#pragma once

#include "MyForm1.h"                                         // Added form from step 3

#include "../../frl_files/frl_shared_header.h"

#include <array>
#include <iostream>
#include <queue>
#include <thread>
bool StartUnmanagedThreading();

bool ResetUSB();
bool is_bUSB_Connected();
void SendCommandUSB(unsigned char* reportData_out, uint8_t size);

struct usb_msg {
	FRL::WireFormat::usb_type type; // 1 USB, 2 UART
	unsigned char data[FRL_ZWF_PACKET_SIZE];
};
extern std::queue <usb_msg> hid_msgs;	// Shared queue from managed and unmanaged

struct cdc_msg {
	FRL::WireFormat::usb_type type; // 1 USB, 2 UART
	unsigned char data[FRL_ZWF_PACKET_SIZE];
};

extern std::queue <cdc_msg> cdc_msgs;	// Shared queue from managed and unmanaged


namespace memo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ CDC_DB;
	protected:

	protected:

	protected:

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::IO::Ports::SerialPort^ serialPort1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
	private: System::Windows::Forms::HScrollBar^ hScrollBar1;
	private: System::Windows::Forms::RichTextBox^ HID_DB;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RichTextBox^ DB;
	private: System::Windows::Forms::Label^ label3;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->CDC_DB = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->hScrollBar1 = (gcnew System::Windows::Forms::HScrollBar());
			this->HID_DB = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->DB = (gcnew System::Windows::Forms::RichTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// CDC_DB
			// 
			this->CDC_DB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CDC_DB->Location = System::Drawing::Point(786, 79);
			this->CDC_DB->Name = L"CDC_DB";
			this->CDC_DB->Size = System::Drawing::Size(423, 76);
			this->CDC_DB->TabIndex = 13;
			this->CDC_DB->Text = L"";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 23);
			this->button1->TabIndex = 11;
			this->button1->Text = L"usb connect";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 50);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 23);
			this->button2->TabIndex = 15;
			this->button2->Text = L"cdc connect";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// serialPort1
			// 
			this->serialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &MyForm::serialPort1_DataReceived);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(119, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(106, 23);
			this->button3->TabIndex = 16;
			this->button3->Text = L"usb send random";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(119, 50);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(106, 23);
			this->button4->TabIndex = 17;
			this->button4->Text = L"cdc send random";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripStatusLabel1 });
			this->statusStrip1->Location = System::Drawing::Point(0, 562);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(1221, 22);
			this->statusStrip1->TabIndex = 18;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(84, 17);
			this->toolStripStatusLabel1->Text = L"no connection";
			// 
			// hScrollBar1
			// 
			this->hScrollBar1->Location = System::Drawing::Point(203, 449);
			this->hScrollBar1->Name = L"hScrollBar1";
			this->hScrollBar1->Size = System::Drawing::Size(278, 46);
			this->hScrollBar1->TabIndex = 19;
			// 
			// HID_DB
			// 
			this->HID_DB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->HID_DB->Location = System::Drawing::Point(786, 6);
			this->HID_DB->Name = L"HID_DB";
			this->HID_DB->Size = System::Drawing::Size(423, 67);
			this->HID_DB->TabIndex = 20;
			this->HID_DB->Text = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1159, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 13);
			this->label1->TabIndex = 21;
			this->label1->Text = L"HID_DB";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1156, 86);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 13);
			this->label2->TabIndex = 22;
			this->label2->Text = L"CDC_DB";
			// 
			// DB
			// 
			this->DB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DB->Location = System::Drawing::Point(786, 161);
			this->DB->Name = L"DB";
			this->DB->Size = System::Drawing::Size(423, 76);
			this->DB->TabIndex = 23;
			this->DB->Text = L"";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1184, 168);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(22, 13);
			this->label3->TabIndex = 24;
			this->label3->Text = L"DB";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1221, 584);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->DB);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->HID_DB);
			this->Controls->Add(this->hScrollBar1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->CDC_DB);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Vigo Lite";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		HID_DB->Clear();
		DB->AppendText("private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {\n");
		std::cout << "private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {\n";

		StartUnmanagedThreading();
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

		DB->AppendText("MyForm_Load Hello world!\r\n"); std::cout << "MyForm_Load Hello world!\r\n" ;
		this->ClientSize = System::Drawing::Size(1237, 330);
		this->Show();
		int c = 0;
		while (1) {

			if (is_bUSB_Connected()) {
				toolStripStatusLabel1->Text = "HID connected";
				toolStripStatusLabel1->BackColor = Color::LightGreen;
			}
			if (serialPort1->IsOpen)
			{
				toolStripStatusLabel1->Text += " CDC connected";
				toolStripStatusLabel1->BackColor = Color::LightGreen;
			}

			if (!hid_msgs.empty()) {
				try {
					HID_DB->AppendText("."); std::cout << ".";
					struct usb_msg m = hid_msgs.front();
					hid_msgs.pop();

					if (++c == 1) {
						c = 0;

						if (m.type == FRL::WireFormat::usb_type::FRL_USB_GEN_HID) {
							switch (((FRL::WireFormat::FRL_Template_t*)(&m.data[0]))->_ReportType) {
							case FRL::WireFormat::ReportType::GENERAL_INFO:
								HID_DB->AppendText("GENERAL_INFO"); std::cout << "GENERAL_INFO";
								HID_DB->AppendText("VERSION: [" + ((FRL::WireFormat::FRL_Template_t*)(&m.data[0]))->_version + "]\r\n"); std::cout << "GENERAL_INFO";
								HID_DB->AppendText("Encoder: [" + ((FRL::WireFormat::FRL_Info*)(&m.data[0]))->_encoder_value + "]\r\n"); std::cout << "GENERAL_INFO";

								hScrollBar1->Value = ((FRL::WireFormat::FRL_Info*)(&m.data[0]))->_encoder_value;
								HID_DB->ScrollToCaret();
								break;
							default:
								break;

							}
						}
						else {
							HID_DB->AppendText("."); std::cout << ".";
						}
					}
				}
				catch (System::Exception^ e) {
					e->Message;
				}

			}
			Application::DoEvents();
			if (!cdc_msgs.empty()) {
				try {

					struct cdc_msg m = cdc_msgs.front();
					cdc_msgs.pop();

					if (++c == 1) {
						c = 0;

						if (m.type == FRL::WireFormat::usb_type::FRL_USB_GEN_HID) {
							CDC_DB->AppendText("."); std::cout << ".";
						}
						else {
							CDC_DB->AppendText("."); std::cout << ".";

							switch (((FRL::WireFormat::FRL_Template_t*)(&m.data[0]))->_ReportType) {
							case FRL::WireFormat::ReportType::GENERAL_INFO:
								CDC_DB->AppendText("GENERAL_INFO"); std::cout << "GENERAL_INFO";
								CDC_DB->AppendText("VERSION: [" + ((FRL::WireFormat::FRL_Template_t*)(&m.data[0]))->_version + "]\r\n"); std::cout << "GENERAL_INFO";
								CDC_DB->ScrollToCaret();
								break;
							default:
								break;

							}


						}
					}
				}
				catch (System::Exception^ e) {
					e->Message;
				}

			}
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {


		memo::MyForm1 form1;

		CDC_DB->Clear();
		for each (String ^ s in System::IO::Ports::SerialPort::GetPortNames())
		{
			Console::WriteLine("   {0}", s);
			form1.comboBox1->Items->Add(s);
		}
		// Instantiate form
		form1.ShowDialog();

		fprintf(stderr, "Serial chosen: [%s]\r\n", frl_g_serial_port);



		try
		{
			if (serialPort1->IsOpen) {
				serialPort1->Close();
				//ConnectBtn->Text = "Open";
				return;
			}
			serialPort1->BaudRate = 115200;
			serialPort1->PortName = gcnew String(frl_g_serial_port);
			serialPort1->ReadTimeout = 1;
			serialPort1->WriteTimeout = 10;

			serialPort1->Open();
			if (serialPort1->IsOpen)
			{
				DB->AppendText("Serial Port open!\r\n");
				Console::WriteLine("   {0}", "Serial Port open!\r\n");
				//serial_only = true;

				//ConnectBtn->Text = "Close";
			}
		}
		catch (System::Exception^ e)
		{
			MessageBox::Show(e->Message, "ConnectBtn_Click", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}
private: System::Void serialPort1_DataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e) {

	static struct cdc_msg mmm;

	//array<unsigned char>^  = gcnew array<unsigned char>(64);

	cli::array<unsigned char>^ result = gcnew cli::array<Byte>(64);

	try
	{

		serialPort1->Read(result, 0, 64);

		if (result->Length == 64) {
			for (int i = 0; i < result->Length; i++) {
				mmm.data[i] = (unsigned char)result[i];
			}

			mmm.type = FRL::WireFormat::usb_type::FRL_USB_CDC;// FRL::WireFormat::usb_type::FRL_USB_CDC;
			cdc_msgs.push(mmm);
		}
	}
	catch (System::TimeoutException^ e) {
		e->Message;
	}
	catch (const std::exception&)
	{

	}
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	//SendCommandUSB(3, 23, 45);
	if (!is_bUSB_Connected()) {
		MessageBox::Show("HID not connected", "HID get info", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	struct cdc_msg m;
	//array<unsigned char>^ auc = gcnew array<unsigned char>(64);
	unsigned char auc[65];

	m.type = FRL::WireFormat::usb_type::FRL_USB_CDC;
	((FRL::WireFormat::HID_Update*)(m.data))->_ReportType = FRL::WireFormat::ReportType::GENERAL_INFO;
	((FRL::WireFormat::HID_Update*)(m.data))->_pre = FRL_ZWF_VERIFY_PRE;
	((FRL::WireFormat::HID_Update*)(m.data))->_post = FRL_ZWF_VERIFY_POST;

	for (int i = 0; i < 64; i++) {
		auc[i+1] = m.data[i];
	}

	SendCommandUSB(auc, 65);


}

	   
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	struct cdc_msg m;
	array<unsigned char>^ auc = gcnew array<unsigned char>(64);

	m.type = FRL::WireFormat::usb_type::FRL_USB_CDC;
	((FRL::WireFormat::HID_Update*)(m.data))->_ReportType = FRL::WireFormat::ReportType::GENERAL_INFO;

	for (int i = 0; i < 64; i++) {
		auc[i] = m.data[i];
	}
	try {
		serialPort1->Write(auc, 0, 64);
	}
	catch (System::Exception^ e)
	{
		MessageBox::Show(e->Message, "CDC get info", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
};
}
