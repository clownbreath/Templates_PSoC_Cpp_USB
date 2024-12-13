/******************************************************************************\
|*  Project Name:  HID_generic			           							  *|
|*  Author(s):     Robert Birch (BRW), Cypress Semiconductor                  *|
|*  Date:          2008/June/24                                               *|
|*  Description:   This project implements a INTERRUPT endpoint USB device    *|
|*                                                                            *|
|*  Warning:	                                                     		  *|
|*  Memos:                                                                    *|
|*----------------------------------------------------------------------------*|
|*  Communication: USB                                                        *|
|*----------------------------------------------------------------------------*|
|*  LEGAL NOTICE:                                                             *|
|*  Cypress’ Source Code: Copyright 2007, Cypress Semiconductor Corporation.  *|
|*  This Source Code (software and/or firmware) is owned by Cypress           *|
|*  Semiconductor Corporation (Cypress) and is protected by and subject to    *|
|*  worldwide patent protection (United States and foreign), United States    *|
|*  copyright laws and international treaty provisions. Cypress hereby grants *|
|*  to licensee a personal, non-exclusive, non-transferable license to copy,  *|
|*  use, modify, create derivative works of, and compile the Cypress Source   *|
|*  Code and derivative works for the sole purpose of creating custom         *|
|*  software and or firmware in support of licensee product to be used only   *|
|*  in conjunction with a Cypress integrated circuit as specified in the      *|
|*  applicable agreement. Any reproduction, modification, translation,        *|
|*  compilation, or representation of this Source Code except as specified    *|
|*  above is prohibited without the express written permission of Cypress.    *|
|*                                                                            *|
|*  Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,    *|
|*  WITH REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  *|
|*  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.       *|
|*  Cypress reserves the right to make changes without further notice to the  *|
|*  materials described herein. Cypress does not assume any liability arising *|
|*  out of the application or use of any product or circuit described herein. *|
|*  Cypress does not authorize its products for use as critical components in *|
|*  life-support systems where a malfunction or failure may reasonably be     *|
|*  expected to result in significant injury to the user. The inclusion of    *|
|*  Cypress’ product in a life-support systems application implies that the   *|
|*  manufacturer assumes all risk of such use and in doing so indemnifies     *|
|*  Cypress against all charges.                                              *|
|*                                                                            *|
|*  Use may be limited by and subject to the applicable Cypress software      *|
|*  license agreement.                                                        *|
\******************************************************************************/

#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules


/* LOCAL VARIABLES */
/*******************/
BYTE l_bUSB_Once_Toggle ;			// USB
BYTE l_abUSB_InBuffer[64];			// USB
BYTE l_abUSB_OutBuffer[64];			// USB


void main()
{
	// **************************************************************************************************
	// 1. INITIALIZE
	// 
	M8C_EnableGInt ;	

    // USB	
	USB_Start(0, USB_5V_OPERATION);   	//Start USB Operation using device 0 with 5V operation  
    while(!USB_bGetConfiguration());    //Wait for Device to enumerate  
    USB_INT_REG |= USB_INT_EP1_MASK | USB_INT_EP2_MASK ;
	
	l_bUSB_Once_Toggle = 1 ;
	
	// **************************************************************************************************
	// 2. MAIN LOOP
	//
	while (1) {
	
		// 2a. Gather and Process data ie: capsense, ADC
		// 
		l_abUSB_InBuffer[0]++ ;		
		
		
		// 2b. Block on OUT from host
		//
		USB_EnableOutEP(2);
		while (USB_bGetEPState(2) != OUT_BUFFER_FULL) ;
		USB_bReadOutEP(2, l_abUSB_OutBuffer, 64);
		
		// 2c. Process OUT from host
		// 
		PRT0DR = 0xFF ;
		PRT1DR = 0xFF ;
		//PRT2DR = 0xFF ;
		
//		PRT1DR &= ~((l_abUSB_OutBuffer[0] & 0x10) >> 2) ;
//		PRT0DR &= ~((l_abUSB_OutBuffer[0] & 0x08) >> 0) ;
//		PRT0DR &= ~((l_abUSB_OutBuffer[0] & 0x04) >> 1) ;
//		PRT2DR &= ~((l_abUSB_OutBuffer[0] & 0x02) << 6) ;
//		PRT2DR &= ~((l_abUSB_OutBuffer[0] & 0x01) << 5) ;
		
    		
		// 2c. Setup IN report
		//    		
		if (l_bUSB_Once_Toggle) {
			l_bUSB_Once_Toggle = 0 ;
			l_abUSB_InBuffer[5] = 5 ;
			l_abUSB_InBuffer[6] = 6 ;
			l_abUSB_InBuffer[9] = 99 ;
			USB_LoadInEP(1, l_abUSB_InBuffer, 64, USB_NO_TOGGLE);
			USB_EnableOutEP(2);
		} else {
	    	USB_LoadInEP(1, l_abUSB_InBuffer, 64, USB_TOGGLE);  		
	    }
		
		// 2c. Block on IN tranfer but give a chance on incomming
		//
		while (USB_bGetEPState(1) == IN_BUFFER_FULL) ;

		// 2d. Debug pin toggle
		//
		PRT2DR ^= 0x01;
	}
}
