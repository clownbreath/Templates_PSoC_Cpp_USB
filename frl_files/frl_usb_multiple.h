/*
 * frl_usb_multiple.h    pdev->pClassData
 * #include "frl_usb_multiple.h"
 *
 *  Created on: Feb 24, 2020
 *      Author: robertbirch             0x80
 */

#ifndef SRC_FRL_USB_MULTIPLE_H_
#define SRC_FRL_USB_MULTIPLE_H_

  //***************************************************************************
 //*** INTERFACES
//***************************************************************************
#define FRL_CDC_INTERFACE

#ifdef FRL_CDC_INTERFACE
  #define FRL_USB_NUM_INTERFACES 					    3
  #define FRL_USB_CUSTOM_HID_PLUS_CDC_CONFIG_DESC_SIZ 	107U
#else
  #define FRL_USB_NUM_INTERFACES 					    1
  #define FRL_USB_CUSTOM_HID_PLUS_CDC_CONFIG_DESC_SIZ 	41U
#endif

  //***************************************************************************
 //*** DEVICE
//***************************************************************************
#define FRL_USB_CUSTOM_HID_INTERFACE 					0

#ifdef FRL_CDC_INTERFACE
  #define FRL_USB_CDC_CMD_INTERFACE 						1
  #define FRL_USB_CDC_DATA_INTERFACE 						2
  #define FRL_USB_CDC_INTERFACE 						    FRL_USB_CDC_CMD_INTERFACE
#endif

  //***************************************************************************
 //*** HID
//***************************************************************************
#define FRL_CUSTOM_HID_EPIN_ADDR                 		0x81U
#define FRL_CUSTOM_HID_EPIN_SIZE                 		0x40U
#define FRL_CUSTOM_HID_EPOUT_ADDR                		0x01U
#define FRL_CUSTOM_HID_EPOUT_SIZE                 		0x40U

  //***************************************************************************
 //*** CDC
//***************************************************************************
#ifdef FRL_CDC_INTERFACE
  #define FRL_CDC_DATA_IN_EP                              0x82U  /* EP2 for data IN */
  #define FRL_CDC_DATA_OUT_EP                             0x02U  /* EP2 for data OUT */
  #define FRL_CDC_CMD_EP                                  0x83U  /* EP3 for CDC commands */

  #define FRL_CDC_DATA_HS_MAX_PACKET_SIZE			       512U  /* Endpoint IN & OUT Packet size */
  #define FRL_CDC_CMD_PACKET_SIZE                            8U  /* Control Endpoint Packet size */
#endif

  //***************************************************************************
 //*** FW
//***************************************************************************
enum frl_usb_classes
{
  FRL_CUSTOM_HID_CLASS = 0,
#ifdef FRL_CDC_INTERFACE
  FRL_CDC_CLASS = 1,
  FRL_NUMBER_OF_USB_CLASSES=2,
#else
  FRL_CDC_CLASS = 1,
  FRL_NUMBER_OF_USB_CLASSES=1,
#endif
};

#endif /* SRC_FRL_USB_MULTIPLE_H_ */






/* NOTES



FRL_TODO_BUG <- Find bugs



#include "frl_usb_multiple.h"


usb_device.c 
usbd_def.h
usbd_customhid.c  @@@@


#ifdef FRL_CDC_INTERFACE

[FRL_CUSTOM_HID_CLASS]



 switch(LOBYTE(req->wIndex)) {
	  		case FRL_USB_CUSTOM_HID_INTERFACE:
	  			ret = (USBD_StatusTypeDef)pdev->pClass[FRL_CUSTOM_HID_CLASS]->Setup(pdev, req);
	  			break ;

#ifdef FRL_CDC_INTERFACE
	  		case FRL_USB_CDC_INTERFACE:
	  			ret = (USBD_StatusTypeDef)pdev->pClass[FRL_CDC_CLASS]->Setup(pdev, req);
	  			break ;
	  		}
#endif
      }



4 total interfaces


HID
  Interface 1/4
    Open Pipes: 2
      bEndpointAddress:     0x81              IN       ENDPOINT 1      usbd_customhid.h   CUSTOM_HID_EPIN_ADDR
        Transfer Type:        Interrupt
        wMaxPacketSize:       0x0002 (2)                                                  CUSTOM_HID_EPIN_SIZE
        bInterval:            0x01
      bEndpointAddress:     0x01              OUT      ENDPOINT 1                                   CUSTOM_HID_EPOUT_ADDR
        Transfer Type:        Interrupt
        wMaxPacketSize:       0x0002 (2)                                                  CUSTOM_HID_EPOUT_SIZE
        bInterval:            0x01                                                        CUSTOM_HID_HS_BINTERVAL


CDC
  Interface 2/4
    Open Pipes: 3
      bEndpointAddress:     0x83              IN       ENDPOINT 3      usbd_cdc.h         CDC_CMD_EP
        Transfer Type:        Interrupt
        wMaxPacketSize:       0x0008 (8)
        bInterval:            0x10

  Interface 3/4
      bEndpointAddress:     0x02              OUT      ENDPOINT 2                         CDC_OUT_EP
        Transfer Type:        Bulk
        wMaxPacketSize:       0x0200 (512)
        bInterval:            0x00

      bEndpointAddress:     0x82              IN       ENDPOINT 2                         CDC_IN_EP
        Transfer Type:        Bulk
        wMaxPacketSize:       0x0200 (512)
        bInterval:            0x00


 ISOC
   Interface 4/4
    Open Pipes: 2
      bEndpointAddress:     0x04              OUT      ENDPOINT 4                         ISOC_OUT_EP
        Transfer Type:        Isoc
        wMaxPacketSize:       0x0040 (64)
        bInterval:            0x00

      bEndpointAddress:     0x84              IN       ENDPOINT 4                         ISOC_IN_EP
        Transfer Type:        Isoc
        wMaxPacketSize:       0x0040 (64)
        bInterval:            0x00


*/
