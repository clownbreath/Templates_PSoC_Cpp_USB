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
        
        
        
        
        
        
        
        
        
        
        
        
        STM32 Virtual ComPort
        