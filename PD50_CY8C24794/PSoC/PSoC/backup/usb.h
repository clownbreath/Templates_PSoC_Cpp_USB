//*****************************************************************************
//*****************************************************************************
//  FILENAME: USB.h
//   Version: 1.5, Updated on 2008/9/10 at 16:20:2
//  Generated by PSoC Designer ???
//
//  DESCRIPTION: USB User Module C Language interface file
//               for the CY8C24090 family of devices
//-----------------------------------------------------------------------------
//  Copyright (c) Cypress Semiconductor 2005. All Rights Reserved.
//*****************************************************************************
//*****************************************************************************

#ifndef USB_H
#define USB_H

#include <m8c.h>

//-------------------------------------------------
// USB Device type support for the USB API.
//-------------------------------------------------

//-------------------------------------------------
// fastcall16 qualifiers for the USB API.
//-------------------------------------------------
#pragma fastcall16 USB_Start
#pragma fastcall16 USB_Stop
#pragma fastcall16 USB_bCheckActivity
#pragma fastcall16 USB_bGetConfiguration
#pragma fastcall16 USB_bGetEPState
#pragma fastcall16 USB_wGetEPCount
#pragma fastcall16 USB_LoadInEP
#pragma fastcall16 USB_LoadInISOCEP
#pragma fastcall16 USB_bReadOutEP
#pragma fastcall16 USB_EnableOutISOCEP
#pragma fastcall16 USB_EnableOutEP
#pragma fastcall16 USB_DisableOutEP
#pragma fastcall16 USB_Force
#pragma fastcall16 USB_bGetEPAckState
#pragma fastcall16 USB_SetPowerStatus

//-------------------------------------------------
// fastcall16 qualifiers for the HID Class API.
//-------------------------------------------------
#pragma fastcall16 USB_UpdateHIDTimer
#pragma fastcall16 USB_bGetProtocol

//-------------------------------------------------
// Prototypes of the USB API.
//-------------------------------------------------
extern void USB_Start(BYTE bDevice, BYTE bMode);
extern void USB_Stop(void);
extern BYTE USB_bCheckActivity(void);
extern BYTE USB_bGetConfiguration(void);
extern BYTE USB_bGetEPState(BYTE bEPNumber);
extern WORD USB_wGetEPCount(BYTE bEPNumber);
extern void USB_LoadInEP(BYTE bEPNumber, BYTE * pData, WORD wLength, BYTE bToggle);
extern void USB_LoadInISOCEP(BYTE bEPNumber, BYTE * pData, WORD wLength, BYTE bToggle);
extern BYTE USB_bReadOutEP(BYTE bEPNumber, BYTE * pData, WORD wLength);
extern void USB_EnableOutEP(BYTE bEPNumber);
extern void USB_EnableOutISOCEP(BYTE bEPNumber);
extern void USB_DisableOutEP(BYTE bEPNumber);
extern void USB_Force(BYTE bState);
extern BYTE USB_bGetEPAckState(BYTE bEPNumber);
extern void USB_SetPowerStatus(BYTE bPowerStaus);

//-------------------------------------------------
// HID Class Prototypes of the USB API.
//-------------------------------------------------
extern BYTE USB_UpdateHIDTimer(BYTE bInterface);
extern BYTE USB_bGetProtocol(BYTE bInterface);

//-------------------------------------------------
// Constants for USB API's.
//-------------------------------------------------
#define NO_EVENT_ALLOWED               2
#define EVENT_PENDING                  1
#define NO_EVENT_PENDING               0

#define IN_BUFFER_FULL                 NO_EVENT_PENDING
#define IN_BUFFER_EMPTY                EVENT_PENDING
#define OUT_BUFFER_FULL                EVENT_PENDING
#define OUT_BUFFER_EMPTY               NO_EVENT_PENDING

#define USB_NO_TOGGLE                  0x00
#define USB_TOGGLE                     0x01

#define USB_FORCE_J                    0xA0
#define USB_FORCE_K                    0x80
#define USB_FORCE_SE0                  0xC0
#define USB_FORCE_NONE                 0x00

#define USB_IDLE_TIMER_RUNNING         0x02
#define USB_IDLE_TIMER_EXPIRED         0x01
#define USB_IDLE_TIMER_INDEFINITE      0x00

#define USB_3V_OPERATION               0x02
#define USB_5V_OPERATION               0x03

#define USB_DEVICE_STATUS_BUS_POWERED  0x00
#define USB_DEVICE_STATUS_SELF_POWERED 0x01

#define USB_MODE_DISABLE               0x00
#define	USB_MODE_NAK_IN_OUT            0x01
#define	USB_MODE_STATUS_OUT_ONLY       0x02
#define	USB_MODE_STALL_IN_OUT          0x03
#define	USB_MODE_RESERVED_0100         0x04
#define	USB_MODE_ISO_OUT               0x05
#define	USB_MODE_STATUS_IN_ONLY        0x06
#define	USB_MODE_ISO_IN                0x07
#define	USB_MODE_NAK_OUT               0x08
#define	USB_MODE_ACK_OUT               0x09
#define	USB_MODE_RESERVED_1010         0x0A
#define	USB_MODE_ACK_OUT_STATUS_IN     0x0B
#define	USB_MODE_NAK_IN                0x0C
#define	USB_MODE_ACK_IN                0x0D
#define	USB_MODE_RESERVED_1110         0x0E
#define	USB_MODE_ACK_IN_STATUS_OUT     0x0F
#define	USB_MODE_STALL_DATA_EP         0x80

//-----------------------------------------------
// Transfer Completion Notification
//-----------------------------------------------
#define USB_XFER_IDLE                       0x00
#define USB_XFER_STATUS_ACK                 0x01
#define USB_XFER_PREMATURE                  0x02
#define USB_XFER_ERROR                      0x03

typedef struct {
    BYTE bStatus;
    WORD wLength;
} T_USB_XFER_STATUS_BLOCK;


//--------------------------------------------------
// Constants for interrupt regs and masks
//--------------------------------------------------
#pragma ioport USB_INT_REG: 0x0DF
BYTE           USB_INT_REG;
#define USB_INT_RESET_MASK 0x01
#define USB_INT_SOF_MASK   0x02
#define USB_INT_EP0_MASK   0x04
#define USB_INT_EP1_MASK   0x08
#define USB_INT_EP2_MASK   0x10
#define USB_INT_EP3_MASK   0x20
#define USB_INT_EP4_MASK   0x40
#define USB_INT_WAKEUP_MASK 0x80

#pragma ioport USB_ADDR:                     0x04a
BYTE           USB_ADDR;
#pragma ioport USB_USBIO_CR0:                0x04b
BYTE           USB_USBIO_CR0;
#pragma ioport USB_USBIO_CR1:                0x04c
BYTE           USB_USBIO_CR1;
#pragma ioport USB_USB_CR1:                  0x1c1
BYTE           USB_USB_CR1;
#pragma ioport USB_EP0MODE:                  0x056
BYTE           USB_EP0MODE;
#pragma ioport USB_EP0CNT:                   0x057
BYTE           USB_EP0CNT;
#pragma ioport USB_EP0DATA:                  0x058
BYTE           USB_EP0DATA;
#pragma ioport USB_EP1MODE:                  0x1c4
BYTE           USB_EP1MODE;
#pragma ioport USB_EP1CNT1:                  0x04e
BYTE           USB_EP1CNT1;
#pragma ioport USB_EP1CNT0:                  0x04f
BYTE           USB_EP1CNT0;
#pragma ioport USB_EP2MODE:                  0x1c5
BYTE           USB_EP2MODE;
#pragma ioport USB_EP2CNT1:                  0x050
BYTE           USB_EP2CNT1;
#pragma ioport USB_EP2CNT0:                  0x051
BYTE           USB_EP2CNT0;
#pragma ioport USB_EP3MODE:                  0x1c6
BYTE           USB_EP3MODE;
#pragma ioport USB_EP3CNT1:                  0x052
BYTE           USB_EP3CNT1;
#pragma ioport USB_EP3CNT0:                  0x053
BYTE           USB_EP3CNT0;
#pragma ioport USB_EP4MODE:                  0x1c7
BYTE           USB_EP4MODE;
#pragma ioport USB_EP4CNT1:                  0x054
BYTE           USB_EP4CNT1;
#pragma ioport USB_EP4CNT0:                  0x055
BYTE           USB_EP4CNT0;

#endif

// end of file USB.h