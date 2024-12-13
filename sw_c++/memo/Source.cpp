#include "pch.h"
#include "MyForm.h"

#include <windows.h>
#include <iostream>
#include <vector>
#include <Hidsdi.h>
#include <SetupAPI.h>
#include <string.h>

#include <ctime>
#include <chrono>
#include <queue>
#include <mutex>

#pragma comment(lib, "hid")
#pragma comment(lib, "SetupAPI")


OVERLAPPED over = {};
OVERLAPPED over_w = {};

HANDLE m_hDeviceHandle[2] = { 0, 0 };

uint8_t reportData_out[FRL_ZWF_PACKET_SIZE +1];		// From computer 
uint8_t reportData_in[FRL_ZWF_PACKET_SIZE +1];		// To computer

uint32_t WorkingIndex = 0;			// 0 = none, 1 = 0 and 2 = 1

HANDLE  hThread;

DWORD WINAPI MyThreadFunction(LPVOID lpParam);


std::queue <usb_msg> hid_msgs;
std::queue <cdc_msg> cdc_msgs;


static bool bUSB_Connected = false;
bool is_bUSB_Connected() {
	return bUSB_Connected;
}

void SendCommandUSB(unsigned char * reportData_out, uint8_t size) {

	DWORD nbWrittenBytes = 0;

	over_w = { 0 };
	over_w.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	WriteFile(m_hDeviceHandle[WorkingIndex - 1], reportData_out, FRL_ZWF_PACKET_SIZE + 1, &nbWrittenBytes, &over_w);
	HANDLE hEvents[1];
	hEvents[0] = over_w.hEvent;
	DWORD dwWaitRes = WaitForMultipleObjects(_countof(hEvents), hEvents, TRUE, INFINITE);
	if (dwWaitRes == WAIT_FAILED)
	{
		CancelIo(m_hDeviceHandle[WorkingIndex - 1]);
	}
	else {
		nbWrittenBytes = 9;
	}
}




bool ResetUSB() {
	WorkingIndex = 0;
	return true;
}

bool StartUnmanagedThreading() {

	m_hDeviceHandle[0] = INVALID_HANDLE_VALUE;
	m_hDeviceHandle[1] = INVALID_HANDLE_VALUE;


	for (int i = 0; i < 64; i++) {
		reportData_in[i] = 255 - i;
	}

		hThread = CreateThread(
			NULL,                   // default security attributes
			0,                      // use default stack size  
			MyThreadFunction,       // thread function name
			NULL,                   // argument to thread function 
			0,                      // use default creation flags 
			NULL);                  // returns the thread identifier 

	return true;
}


DWORD WINAPI MyThreadFunction(LPVOID lpParam2) 
{
	uint32_t Count = 0;
	WCHAR Paths[2][256];

	GUID HID_GUID;
	HidD_GetHidGuid(&HID_GUID);

	HDEVINFO DeviceInfoSet = SetupDiGetClassDevs(&HID_GUID, nullptr, nullptr, DIGCF_DEVICEINTERFACE | DIGCF_PRESENT);

	SP_DEVINFO_DATA DeviceInfoData;
	ZeroMemory(&DeviceInfoData, sizeof(SP_DEVINFO_DATA));
	DeviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);

	SP_DEVICE_INTERFACE_DATA DeviceInterfaceData;
	ZeroMemory(&DeviceInterfaceData, sizeof(SP_DEVICE_INTERFACE_DATA));
	DeviceInterfaceData.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);

	struct {
		SP_DEVICE_INTERFACE_DETAIL_DATA Data;
		TCHAR Buffer[256];
	} DeviceInterfaceDetail;

	ZeroMemory(&DeviceInterfaceDetail.Data, sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA));
	DeviceInterfaceDetail.Data.cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);

	uint32_t DeviceIndex = 0;
	while (SetupDiEnumDeviceInterfaces(DeviceInfoSet, nullptr, &HID_GUID, DeviceIndex, &DeviceInterfaceData)) {
		if (SetupDiGetDeviceInterfaceDetail(
			DeviceInfoSet,
			&DeviceInterfaceData,
			&DeviceInterfaceDetail.Data,
			sizeof(DeviceInterfaceDetail),
			nullptr,
			&DeviceInfoData)) {
			wchar_t* pVID = wcsstr(DeviceInterfaceDetail.Data.DevicePath, L"vid_04b4"); //vid_0483 vid_04b4
			wchar_t* pPID = wcsstr(DeviceInterfaceDetail.Data.DevicePath, L"pid_fae0"); //pid_5750 pid_fae0
			if (pVID && pPID) {
				wcscpy_s(Paths[Count++], DeviceInterfaceDetail.Data.DevicePath);
				std::cout << Paths[Count -1] << "\n";
			}
		}

		DeviceIndex++;
	}

	DWORD Error = GetLastError();
	if (Error != ERROR_NO_MORE_ITEMS) {
		std::cout << "Error!\r\n";
	}

	if (DeviceInfoSet) {
		SetupDiDestroyDeviceInfoList(DeviceInfoSet);
	}

	for (uint32_t Index = 0; Index < Count; Index++) {
		m_hDeviceHandle[Index] = CreateFile(
			Paths[Index],
			GENERIC_WRITE | GENERIC_READ,
			FILE_SHARE_READ | FILE_SHARE_WRITE,
			nullptr,
			OPEN_EXISTING,
			FILE_FLAG_OVERLAPPED,
			nullptr);
	}

	for (uint32_t Index = 0; Index < Count; Index++) {
		if (m_hDeviceHandle[Index] != INVALID_HANDLE_VALUE) {
			WorkingIndex = Index + 1;
			break;
		}
	}

	SetupDiDestroyDeviceInfoList(DeviceInfoSet);

	uint8_t count =0;
	usb_msg m;

	//while (1) {
		// do nothing
	//}
	while (WorkingIndex) {
		
		bUSB_Connected = true;

		DWORD nbWrittenBytes = 0;

		over = { 0 };
		over.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
		if (ReadFile(m_hDeviceHandle[WorkingIndex-1], reportData_in, FRL_ZWF_PACKET_SIZE + 1, &nbWrittenBytes, &over))
		{
			
			
		}
		else {
			if (count > 0) {
				bUSB_Connected = false;
			}
		}

		HANDLE hEvents[1];
		hEvents[0] = over.hEvent;
		DWORD dwWaitRes = WaitForMultipleObjects(_countof(hEvents), hEvents, TRUE, INFINITE);
		if (dwWaitRes == WAIT_FAILED)
		{
			CancelIo(m_hDeviceHandle[WorkingIndex - 1]);
		}
		else {
			bUSB_Connected = true;

			//if (nbWrittenBytes != FRL_ZWF_PACKET_SIZE + 1) {
			//	continue;
			//}

			m.type = FRL::WireFormat::usb_type::FRL_USB_GEN_HID;

			for (int i = 0; i < FRL_ZWF_PACKET_SIZE; i++) {
				m.data[i] = reportData_in[i + 1];
			}

			hid_msgs.push(m);
		}

	}

	return m_hDeviceHandle[0] != INVALID_HANDLE_VALUE ||
		m_hDeviceHandle[1] != INVALID_HANDLE_VALUE;
}