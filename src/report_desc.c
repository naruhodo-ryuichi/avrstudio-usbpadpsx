/*
This file contains the HIS report descriptor. This data is fetched once by the
PC, and the report data (created in report.c) is interpreted according to the
info in this descriptor.
*/
#include <avr/pgmspace.h>
#include "usbconfig.h"
//Generated with usbtool from usb.org, then modified for AVR use

//Change the len of the report defined in usbconfig.h if you
//change the report!
//If you change this and use Windows: plug in the pad, de-install the 
//HID thingy that pops up in the 'devices'-control panel, un- and replug
//the pad. If you don't, Windows will be so 'kind' to use a cached HID 
//descriptor.
const PROGMEM char usbDescriptorHidReport[DESCRIPTOR_SIZE] = { /* USB report descriptor */
		0x05, 0x01, // USAGE_PAGE (Generic Desktop)
				0x09, 0x04, // USAGE (Joystick)
				0xa1, 0x01, // COLLECTION (Application)
				0x09, 0x01, //   USAGE (Pointer)
				0xa1, 0x00, //   COLLECTION (Physical)
				0x85, 0x01, //     REPORT_ID (1)
				0x09, 0x30, //     USAGE (X)
				0x09, 0x31, //     USAGE (Y)
				0x15, 0x00, //     LOGICAL_MINIMUM (0)
				0x25, 0x0f, //     LOGICAL_MAXIMUM (15)
				0x75, 0x04, //     REPORT_SIZE (4)
				0x95, 0x02, //     REPORT_COUNT (2)
				0x81, 0x02, //     INPUT (Data,Var,Abs)
				/*report size 4x2=8 bits*/
				0x09, 0x32, //     USAGE (Z)
				0x09, 0x33, //     USAGE (Rx)
				0x09, 0x34, //     USAGE (Ry)
				0x09, 0x35, //     USAGE (Rz)
				0x15, 0x00, //     LOGICAL_MINIMUM (0)
				0x26, 0xff, 0x00, //LOGICAL_MAXIMUM (255)
				0x75, 0x08, //     REPORT_SIZE (8)
				0x95, 0x04, //     REPORT_COUNT (4)
				0x81, 0x02, //     INPUT (Data,Var,Abs)
				/*report size 8x4=32 bits*/
				0x05, 0x09, //     USAGE_PAGE (Button)
				0x19, 0x01, //     USAGE_MINIMUM (Button 1)
				0x29, 0x10, //     USAGE_MAXIMUM (Button 16)
				0x15, 0x00, //     LOGICAL_MINIMUM (0)
				0x25, 0x01, //     LOGICAL_MAXIMUM (1)
				0x75, 0x01, //     REPORT_SIZE (1)
				0x95, 0x10, //     REPORT_COUNT (16)
				0x81, 0x02, //     INPUT (Data,Var,Abs)
				/*report size 1x16= 16bits*/
				0xc0, //     END_COLLECTION PHYSICAL
				/**********************************************************************/
				// REPORT INPUT 2
				0x05, 0x0F, //    Usage Page Physical Interface
				0x09, 0x92, //    Usage ES Playing
				0xA1, 0x02, //    Collection Datalink
				0x85, 0x02, //    Report ID 2
				0x09, 0x9F, //    Usage DS Device is Reset
				0x09, 0xA0, //    Usage DS Device is Pause
				0x09, 0xA4, //    Usage Actuator Power
				0x09, 0xA5, //    Usage Undefined
				0x09, 0xA6, //    Usage Undefined
				0x15, 0x00, //    Logical Minimum 0
				0x25, 0x01, //    Logical Maximum 1
				0x35, 0x00, //    Physical Minimum 0
				0x45, 0x01, //    Physical Maximum 1
				0x75, 0x01, //    Report Size 1
				0x95, 0x05, //    Report Count 5
				0x81, 0x02, //    Input (Variable)
				0x95, 0x03, //    Report Count 3
				0x81, 0x03, //    Input (Constant, Variable)
				/*report size 5x1+3x1=8 bits*/
				0x09, 0x94, //    Usage PID Device Control
				0x15, 0x00, //    Logical Minimum 0
				0x25, 0x01, //    Logical Maximum 1
				0x35, 0x00, //    Physical Minimum 0
				0x45, 0x01, //    Physical Maximum 1
				0x75, 0x01, //    Report Size 1
				0x95, 0x01, //    Report Count 1
				0x81, 0x02, //    Input (Variable)
				0x09, 0x22, //    Usage Effect Block Index
				0x15, 0x01, //    Logical Minimum 1
				0x25, 0x28, //    Logical Maximum 28h (40d)
				0x35, 0x01, //    Physical Minimum 1
				0x45, 0x28, //    Physical Maximum 28h (40d)
				0x75, 0x07, //    Report Size 7
				0x95, 0x01, //    Report Count 1
				0x81, 0x02, //    Input (Variable)
				/*report size 1x1+7x1=8bits*/
				0xC0, // End Collection Datalink
				/**********************************************************************/
				// REPORT OUTPUT 1
				0x09, 0x21, //    Usage Set Effect Report
				0xA1, 0x02, //    Collection Datalink
				0x85, 0x01, //    Report ID 1
				0x09, 0x22, //    Usage Effect Block Index
				0x15, 0x01, //    Logical Minimum 1
				0x25, 0x28, //    Logical Maximum 28h (40d)
				0x35, 0x01, //    Physical Minimum 1
				0x45, 0x28, //    Physical Maximum 28h (40d)
				0x75, 0x08, //    Report Size 8
				0x95, 0x01, //    Report Count 1
				0x91, 0x02, //    Output (Variable)
				/*report size 1x1+7x1=8bits*/
				0x09, 0x25, //    Usage Effect Type
				0xA1, 0x02, //    Collection Datalink
				0x09, 0x26, //    Usage ET Constant Force
				0x09, 0x27, //    Usage ET Ramp
				0x09, 0x30, //    Usage ET Square
				0x09, 0x31, //    Usage ET Sine
				0x09, 0x32, //    Usage ET Triangle
				0x09, 0x33, //    Usage ET Sawtooth Up
				0x09, 0x34, //    Usage ET Sawtooth Down
				0x09, 0x40, //    Usage ET Spring
				0x09, 0x41, //    Usage ET Damper
				0x09, 0x42, //    Usage ET Inertia
				0x09, 0x43, //    Usage ET Friction
				0x09, 0x28, //    Usage ET Custom Force Data
				0x25, 0x0C, //    Logical Maximum Ch (12d)
				0x15, 0x01, //    Logical Minimum 1
				0x35, 0x01, //    Physical Minimum 1
				0x45, 0x0C, //    Physical Maximum Ch (12d)
				0x75, 0x08, //    Report Size 8
				0x95, 0x01, //    Report Count 1
				0x91, 0x00, //    Output
				/*report size 8x1=8bits*/
				0xC0, //    End Collection
				0x09, 0x50, //    Usage Duration
				0x09, 0x54, //    Usage Trigger Repeat Interval
				0x09, 0x51, //    Usage Sample Period
				0x15, 0x00, //    Logical Minimum 0
				0x26, 0xFF, 0x7F, //    Logical Maximum 7FFFh (32767d)
				0x35, 0x00, //    Physical Minimum 0
				0x46, 0xFF, 0x7F, //    Physical Maximum 7FFFh (32767d)
				0x66, 0x03, 0x10, //    Unit 1003h (4099d)
				0x55, 0xFD, //    Unit Exponent FDh (253d)
				0x75, 0x10, //    Report Size 10h (16d)
				0x95, 0x03, //    Report Count 3
				0x91, 0x02, //    Output (Variable)
				/*report size 16x3=48bits=12bytes*/
				0x55, 0x00, //    Unit Exponent 0
				0x66, 0x00, 0x00, //    Unit 0
				0x09, 0x52, //    Usage Gain
				0x15, 0x00, //    Logical Minimum 0
				0x26, 0xFF, 0x00, //    Logical Maximum FFh (255d)
				0x35, 0x00, //    Physical Minimum 0
				0x46, 0x10, 0x27, //    Physical Maximum 2710h (10000d)
				0x75, 0x08, //    Report Size 8
				0x95, 0x01, //    Report Count 1
				0x91, 0x02, //    Output (Variable)
				/*report size 8x1=8bits*/
				0x09, 0x53, //    Usage Trigger Button
				0x15, 0x01, //    Logical Minimum 1
				0x25, 0x08, //    Logical Maximum 8
				0x35, 0x01, //    Physical Minimum 1
				0x45, 0x08, //    Physical Maximum 8
				0x75, 0x08, //    Report Size 8
				0x95, 0x01, //    Report Count 1
				0x91, 0x02, //    Output (Variable)
				/*report size 8x1=8bits*/
				0x09, 0x55, //    Usage Axes Enable
				0xA1, 0x02, //    Collection Datalink
				0x05, 0x01, //    Usage Page Generic Desktop
				0x09, 0x30, //    Usage X
				0x09, 0x31, //    Usage Y
				0x15, 0x00, //    Logical Minimum 0
				0x25, 0x01, //    Logical Maximum 1
				0x75, 0x01, //    Report Size 1
				0x95, 0x02, //    Report Count 2
				0x91, 0x02, //    Output (Variable)
				/*report size 2x1=2bits*/
				0xC0, // End Collection
				0x05, 0x0F, //    Usage Page Physical Interface
				0x09, 0x56, //    Usage Direction Enable
				0x95, 0x01, //    Report Count 1
				0x91, 0x02, //    Output (Variable)
				/*report size 1x1=1bits*/
				0x95, 0x05, //    Report Count 5
				0x91, 0x03, //    Output (Constant, Variable)
				/*report size 5x1=5bits*/
				/*TOTAL 2+1+5=8bits*/
				0x09, 0x57, //    Usage Direction
				0xA1, 0x02, //    Collection Datalink
				0x0B, 0x01, 0x00, 0x0A, 0x00, //    Usage Ordinals: Instance 1
				0x0B, 0x02, 0x00, 0x0A, 0x00, //    Usage Ordinals: Instance 2
				0x66, 0x14, 0x00, //    Unit 14h (20d)
				0x55, 0xFE, //    Unit Exponent FEh (254d)
				0x15, 0x00, //    Logical Minimum 0
				0x26, 0xFF, 0x00, //    Logical Maximum FFh (255d)
				0x35, 0x00, //    Physical Minimum 0
				0x47, 0xA0, 0x8C, 0x00, 0x00, //    Physical Maximum 8CA0h (36000d)
				0x66, 0x00, 0x00, //    Unit 0
				0x75, 0x08, //    Report Size 8
				0x95, 0x02, //    Report Count 2
				0x91, 0x02, //    Output (Variable)
				/*report size 8x2=16bits*/
				0x55, 0x00, //    Unit Exponent 0
				0x66, 0x00, 0x00, //    Unit 0
				0xC0, //    End Collection
				0x05, 0x0F, //    Usage Page Physical Interface
				0x09, 0xA7, //    Usage Undefined
				0x66, 0x03, 0x10, //    Unit 1003h (4099d)
				0x55, 0xFD, //    Unit Exponent FDh (253d)
				0x15, 0x00, //    Logical Minimum 0
				0x26, 0xFF, 0x7F, //    Logical Maximum 7FFFh (32767d)
				0x35, 0x00, //    Physical Minimum 0
				0x46, 0xFF, 0x7F, //    Physical Maximum 7FFFh (32767d)
				0x75, 0x10, //    Report Size 10h (16d)
				0x95, 0x01, //    Report Count 1
				0x91, 0x02, //    Output (Variable)
				/*report size 16x1=16bits*/
				0x66, 0x00, 0x00, //    Unit 0
				0x55, 0x00, //    Unit Exponent 0
				0xC0, //    End Collection
				/**********************************************************************/
				// REPORT OUTPUT 2
				0x05, 0x0F, //    Usage Page Physical Interface
				0x09, 0x5A, //    Usage Set Envelope Report
				0xA1, 0x02, //    Collection Datalink
				0x85, 0x02, //    Report ID 2
				0x09, 0x22, //    Usage Effect Block Index
				0x15, 0x01, //    Logical Minimum 1
				0x25, 0x28, //    Logical Maximum 28h (40d)
				0x35, 0x01, //    Physical Minimum 1
				0x45, 0x28, //    Physical Maximum 28h (40d)
				0x75, 0x08, //    Report Size 8
				0x95, 0x01, //    Report Count 1
				0x91, 0x02, //    Output (Variable)
				/*report size 8x1=8bits*/
				0x09, 0x5B, //    Usage Attack Level
				0x09, 0x5D, //    Usage Fade Level
				0x15, 0x00, //    Logical Minimum 0
				0x26, 0xFF, 0x00, //    Logical Maximum FFh (255d)
				0x35, 0x00, //    Physical Minimum 0
				0x46, 0x10, 0x27, //    Physical Maximum 2710h (10000d)
				0x95, 0x02, //    Report Count 2
				0x91, 0x02, //    Output (Variable)
				/*report size 8x2=16bits*/
				0x09, 0x5C, //    Usage Attack Time
				0x09, 0x5E, //    Usage Fade Time
				0x66, 0x03, 0x10, //    Unit 1003h (4099d)
				0x55, 0xFD, //    Unit Exponent FDh (253d)
				0x26, 0xFF, 0x7F, //    Logical Maximum 7FFFh (32767d)
				0x46, 0xFF, 0x7F, //    Physical Maximum 7FFFh (32767d)
				0x75, 0x10, //    Report Size 10h (16d)
				0x91, 0x02, //    Output (Variable)
				/*report size 16x2=32bits*/
				0x45, 0x00, //    Physical Maximum 0
				0x66, 0x00, 0x00, //    Unit 0
				0x55, 0x00, //    Unit Exponent 0
				0xC0, //    End Collection
				/**********************************************************************/
				// REPORT OUTPUT 3
				0x09, 0x5F, //    Usage Set Condition Report
				0xA1, 0x02, //    Collection Datalink
				0x85, 0x03, //    Report ID 3
				0x09, 0x22, //    Usage Effect Block Index
				0x15, 0x01, //    Logical Minimum 1
				0x25, 0x28, //    Logical Maximum 28h (40d)
				0x35, 0x01, //    Physical Minimum 1
				0x45, 0x28, //    Physical Maximum 28h (40d)
				0x75, 0x08, //    Report Size 8
				0x95, 0x01, //    Report Count 1
				0x91, 0x02, //    Output (Variable)
				/*report size 8x1=8bits*/
				0x09, 0x23, //    Usage Parameter Block Offset
				0x15, 0x00, //    Logical Minimum 0
				0x25, 0x01, //    Logical Maximum 1
				0x35, 0x00, //    Physical Minimum 0
				0x45, 0x01, //    Physical Maximum 1
				0x75, 0x04, //    Report Size 4
				0x95, 0x01, //    Report Count 1
				0x91, 0x02, //    Output (Variable)
				/*report size 4x1=4bits*/
				0x09, 0x58, //    Usage Type Specific Block Off...
				0xA1, 0x02, //    Collection Datalink
				0x0B, 0x01, 0x00, 0x0A, 0x00, //    Usage Ordinals: Instance 1
				0x0B, 0x02, 0x00, 0x0A, 0x00, //    Usage Ordinals: Instance 2
				0x75, 0x02, //    Report Size 2
				0x95, 0x02, //    Report Count 2
				0x91, 0x02, //    Output (Variable)
				/*report size 2x2=4bits*/
				0xC0, //    End Collection
				0x15, 0x80, //    Logical Minimum 80h (-128d)
				0x25, 0x7F, //    Logical Maximum 7Fh (127d)
				0x36, 0xF0, 0xD8, //    Physical Minimum D8F0h (-10000d)
				0x46, 0x10, 0x27, //    Physical Maximum 2710h (10000d)
				0x09, 0x60, //    Usage CP Offset
				0x75, 0x08, //    Report Size 8
				0x95, 0x01, //    Report Count 1
				0x91, 0x02, //    Output (Variable)
				/*report size 8x1=8bits*/
				0x36, 0xF0, 0xD8, //    Physical Minimum D8F0h (-10000d)
				0x46, 0x10, 0x27, //    Physical Maximum 2710h (10000d)
				0x09, 0x61, //    Usage Positive Coefficient
				0x09, 0x62, //    Usage Negative Coefficient
				0x95, 0x02, //    Report Count 2
				0x91, 0x02, //    Output (Variable)
				/*report size 8x2=16bits*/
				0x15, 0x00, //    Logical Minimum 0
				0x26, 0xFF, 0x00, //    Logical Maximum FFh (255d)
				0x35, 0x00, //    Physical Minimum 0
				0x46, 0x10, 0x27, //    Physical Maximum 2710h (10000d)
				0x09, 0x63, //    Usage Positive Saturation
				0x09, 0x64, //    Usage Negative Saturation
				0x75, 0x08, //    Report Size 8
				0x95, 0x02, //    Report Count 2
				0x91, 0x02, //    Output (Variable)
				/*report size 8x2=16bits*/
				0x09, 0x65, //    Usage Dead Band
				0x46, 0x10, 0x27, //    Physical Maximum 2710h (10000d)
				0x95, 0x01, //    Report Count 1
				0x91, 0x02, //    Output (Variable)
				/*report size 8x2=16bits*/
				0xC0, //    End Collection
				/**********************************************************************/
				// REPORT OUTPUT 4
				0x09, 0x6E, //    Usage Set Periodic Report
				0xA1, 0x02, //    Collection Datalink
				0x85, 0x04, //    Report ID 4
				0x09, 0x22, //    Usage Effect Block Index
				0x15, 0x01, //    Logical Minimum 1
				0x25, 0x28, //    Logical Maximum 28h (40d)
				0x35, 0x01, //    Physical Minimum 1
				0x45, 0x28, //    Physical Maximum 28h (40d)
				0x75, 0x08, //    Report Size 8
				0x95, 0x01, //    Report Count 1
				0x91, 0x02, //    Output (Variable)
				/*report size 8x1=8bits*/
				0x09, 0x70, //    Usage Magnitude
				0x15, 0x00, //    Logical Minimum 0
				0x26, 0xFF, 0x00, //    Logical Maximum FFh (255d)
				0x35, 0x00, //    Physical Minimum 0
				0x46, 0x10, 0x27, //    Physical Maximum 2710h (10000d)
				0x75, 0x08, //    Report Size 8
				0x95, 0x01, //    Report Count 1
				0x91, 0x02, //    Output (Variable)
				/*report size 8x1=8bits*/
				0x09, 0x6F, //    Usage Offset
				0x15, 0x80, //    Logical Minimum 80h (-128d)
				0x25, 0x7F, //    Logical Maximum 7Fh (127d)
				0x36, 0xF0, 0xD8, //    Physical Minimum D8F0h (-10000d)
				0x46, 0x10, 0x27, //    Physical Maximum 2710h (10000d)
				0x95, 0x01, //    Report Count 1
				0x91, 0x02, //    Output (Variable)
				/*report size 8x1=8bits*/
				0x09, 0x71, //    Usage Phase
				0x66, 0x14, 0x00, //    Unit 14h (20d)
				0x55, 0xFE, //    Unit Exponent FEh (254d)
				0x15, 0x00, //    Logical Minimum 0
				0x26, 0xFF, 0x00, //    Logical Maximum FFh (255d)
				0x35, 0x00, //    Physical Minimum 0
				0x47, 0xA0, 0x8C, 0x00, 0x00, //    Physical Maximum 8CA0h (36000d)
				0x91, 0x02, //    Output (Variable)
				/*report size 8x1=8bits*/
				0x09, 0x72, //    Usage Period
				0x26, 0xFF, 0x7F, //    Logical Maximum 7FFFh (32767d)
				0x46, 0xFF, 0x7F, //    Physical Maximum 7FFFh (32767d)
				0x66, 0x03, 0x10, //    Unit 1003h (4099d)
				0x55, 0xFD, //    Unit Exponent FDh (253d)
				0x75, 0x10, //    Report Size 10h (16d)
				0x95, 0x01, //    Report Count 1
				0x91, 0x02, //    Output (Variable)
				/*report size 16x1=16bits*/
				0x66, 0x00, 0x00, //    Unit 0
				0x55, 0x00, //    Unit Exponent 0
				0xC0, // End Collection
				/**********************************************************************/
				// REPORT OUTPUT 5
				0x09, 0x73, //    Usage Set Constant Force Rep...
				0xA1, 0x02, //    Collection Datalink
				0x85, 0x05, //    Report ID 5
				0x09, 0x22, //    Usage Effect Block Index
				0x15, 0x01, //    Logical Minimum 1
				0x25, 0x28, //    Logical Maximum 28h (40d)
				0x35, 0x01, //    Physical Minimum 1
				0x45, 0x28, //    Physical Maximum 28h (40d)
				0x75, 0x08, //    Report Size 8
				0x95, 0x01, //    Report Count 1
				0x91, 0x02, //    Output (Variable)
				/*report size 8x1=8bits*/
				0x09, 0x70, //    Usage Magnitude
				0x16, 0x01, 0xFF, //    Logical Minimum FF01h (-255d)
				0x26, 0xFF, 0x00, //    Logical Maximum FFh (255d)
				0x36, 0xF0, 0xD8, //    Physical Minimum D8F0h (-10000d)
				0x46, 0x10, 0x27, //    Physical Maximum 2710h (10000d)
				0x75, 0x10, //    Report Size 10h (16d)
				0x95, 0x01, //    Report Count 1
				0x91, 0x02, //    Output (Variable)
				/*report size 16x1=16bits*/
				0xC0, //    End Collection
				/**********************************************************************/
				// REPORT OUTPUT 6
				0x09, 0x74, //    Usage Set Ramp Force Report
				0xA1, 0x02, //    Collection Datalink
				0x85, 0x06, //    Report ID 6
				0x09, 0x22, //    Usage Effect Block Index
				0x15, 0x01, //    Logical Minimum 1
				0x25, 0x28, //    Logical Maximum 28h (40d)
				0x35, 0x01, //    Physical Minimum 1
				0x45, 0x28, //    Physical Maximum 28h (40d)
				0x75, 0x08, //    Report Size 8
				0x95, 0x01, //    Report Count 1
				0x91, 0x02, //    Output (Variable)
				0x09, 0x75, //    Usage Ramp Start
				0x09, 0x76, //    Usage Ramp End
				0x15, 0x80, //    Logical Minimum 80h (-128d)
				0x25, 0x7F, //    Logical Maximum 7Fh (127d)
				0x36, 0xF0, 0xD8, //    Physical Minimum D8F0h (-10000d)
				0x46, 0x10, 0x27, //    Physical Maximum 2710h (10000d)
				0x75, 0x08, //    Report Size 8
				0x95, 0x02, //    Report Count 2
				0x91, 0x02, //    Output (Variable)
				/*report size 8x2=16bits*/
				0xC0, //    End Collection
				/**********************************************************************/
				// REPORT OUTPUT 7
				0x09, 0x68, //    Usage Custom Force Data Rep...
				0xA1, 0x02, //    Collection Datalink
				0x85, 0x07, //    Report ID 7
				0x09, 0x22, //    Usage Effect Block Index
				0x15, 0x01, //    Logical Minimum 1
				0x25, 0x28, //    Logical Maximum 28h (40d)
				0x35, 0x01, //    Physical Minimum 1
				0x45, 0x28, //    Physical Maximum 28h (40d)
				0x75, 0x08, //    Report Size 8
				0x95, 0x01, //    Report Count 1
				0x91, 0x02, //    Output (Variable)
				/*report size 8x1=8bits*/
				0x09, 0x6C, //    Usage Custom Force Data Offset
				0x15, 0x00, //    Logical Minimum 0
				0x26, 0x10, 0x27, //    Logical Maximum 2710h (10000d)
				0x35, 0x00, //    Physical Minimum 0
				0x46, 0x10, 0x27, //    Physical Maximum 2710h (10000d)
				0x75, 0x10, //    Report Size 10h (16d)
				0x95, 0x01, //    Report Count 1
				0x91, 0x02, //    Output (Variable)
				/*report size 16x1=16bits*/
				0x09, 0x69, //    Usage Custom Force Data
				0x15, 0x81, //    Logical Minimum 81h (-127d)
				0x25, 0x7F, //    Logical Maximum 7Fh (127d)
				0x35, 0x00, //    Physical Minimum 0
				0x46, 0xFF, 0x00, //    Physical Maximum FFh (255d)
				0x75, 0x08, //    Report Size 8
				0x95, 0x0C, //    Report Count Ch (12d)
				0x92, 0x02, 0x01, //       Output (Variable, Buffered)
				/*report size 8x12=96bits*/
				0xC0, //    End Collection
				/**********************************************************************/
				// REPORT OUTPUT 8
				0x09, 0x66, //    Usage Download Force Sample
				0xA1, 0x02, //    Collection Datalink
				0x85, 0x08, //    Report ID 8
				0x05, 0x01, //    Usage Page Generic Desktop
				0x09, 0x30, //    Usage X
				0x09, 0x31, //    Usage Y
				0x15, 0x81, //    Logical Minimum 81h (-127d)
				0x25, 0x7F, //    Logical Maximum 7Fh (127d)
				0x35, 0x00, //    Physical Minimum 0
				0x46, 0xFF, 0x00, //    Physical Maximum FFh (255d)
				0x75, 0x08, //    Report Size 8
				0x95, 0x02, //    Report Count 2
				0x91, 0x02, //    Output (Variable)
				/*report size 8x2=16bits*/
				0xC0, //    End Collection
				/**********************************************************************/
				// REPORT OUTPUT 10
				0x05, 0x0F, //    Usage Page Physical Interface
				0x09, 0x77, //    Usage Effect Operation Report
				0xA1, 0x02, //    Collection Datalink
				0x85, 0x0A, //    Report ID Ah (10d)
				0x09, 0x22, //    Usage Effect Block Index
				0x15, 0x01, //    Logical Minimum 1
				0x25, 0x28, //    Logical Maximum 28h (40d)
				0x35, 0x01, //    Physical Minimum 1
				0x45, 0x28, //    Physical Maximum 28h (40d)
				0x75, 0x08, //    Report Size 8
				0x95, 0x01, //    Report Count 1
				0x91, 0x02, //    Output (Variable)
				/*report size 8x1=8bits*/
				0x09, 0x78, //    Usage Operation
				0xA1, 0x02, //    Collection Datalink
				0x09, 0x79, //    Usage Op Effect Start
				0x09, 0x7A, //    Usage Op Effect Start Solo
				0x09, 0x7B, //    Usage Op Effect Stop
				0x15, 0x01, //    Logical Minimum 1
				0x25, 0x03, //    Logical Maximum 3
				0x75, 0x08, //    Report Size 8
				0x95, 0x01, //    Report Count 1
				0x91, 0x00, //    Output
				/*report size 8x1=8bits*/
				0xC0, //    End Collection
				0x09, 0x7C, //    Usage Loop Count
				0x15, 0x00, //    Logical Minimum 0
				0x26, 0xFF, 0x00, //    Logical Maximum FFh (255d)
				0x35, 0x00, //    Physical Minimum 0
				0x46, 0xFF, 0x00, //    Physical Maximum FFh (255d)
				0x91, 0x02, //    Output (Variable)
				/*report size 8x1=8bits*/
				0xC0, //    End Collection
				/**********************************************************************/
				// REPORT OUTPUT 11
				0x09, 0x90, //    Usage PID State Report
				0xA1, 0x02, //    Collection Datalink
				0x85, 0x0B, //    Report ID Bh (11d)
				0x09, 0x22, //    Usage Effect Block Index
				0x25, 0x28, //    Logical Maximum 28h (40d)
				0x15, 0x01, //    Logical Minimum 1
				0x35, 0x01, //    Physical Minimum 1
				0x45, 0x28, //    Physical Maximum 28h (40d)
				0x75, 0x08, //    Report Size 8
				0x95, 0x01, //    Report Count 1
				0x91, 0x02, //    Output (Variable)
				/*report size 8x1=8bits*/
				0xC0, //    End Collection
				/**********************************************************************/
				// REPORT OUTPUT 12
				0x09, 0x96, //    Usage DC Disable Actuators
				0xA1, 0x02, //    Collection Datalink
				0x85, 0x0C, //    Report ID Ch (12d)
				0x09, 0x97, //    Usage DC Stop All Effects
				0x09, 0x98, //    Usage DC Device Reset
				0x09, 0x99, //    Usage DC Device Pause
				0x09, 0x9A, //    Usage DC Device Continue
				0x09, 0x9B, //    Usage PID Device State
				0x09, 0x9C, //    Usage DS Actuators Enabled
				0x15, 0x01, //    Logical Minimum 1
				0x25, 0x06, //    Logical Maximum 6
				0x75, 0x08, //    Report Size 8
				0x95, 0x01, //    Report Count 1
				0x91, 0x00, //    Output
				/*report size 8x1=8bits*/
				0xC0, //    End Collection
				/**********************************************************************/
				// REPORT OUTPUT 13
				0x09, 0x7D, //    Usage PID Pool Report
				0xA1, 0x02, //    Collection Datalink
				0x85, 0x0D, //    Report ID Dh (13d)
				0x09, 0x7E, //    Usage RAM Pool Size
				0x15, 0x00, //    Logical Minimum 0
				0x26, 0xFF, 0x00, //    Logical Maximum FFh (255d)
				0x35, 0x00, //    Physical Minimum 0
				0x46, 0x10, 0x27, //    Physical Maximum 2710h (10000d)
				0x75, 0x08, //    Report Size 8
				0x95, 0x01, //    Report Count 1
				0x91, 0x02, //    Output (Variable)
				/*report size 8x1=8bits*/
				0xC0, //    End Collection
				/**********************************************************************/
				// REPORT OUTPUT 14
				0x09, 0x6B, //    Usage Set Custom Force Report
				0xA1, 0x02, //    Collection Datalink
				0x85, 0x0E, //    Report ID Eh (14d)
				0x09, 0x22, //    Usage Effect Block Index
				0x15, 0x01, //    Logical Minimum 1
				0x25, 0x28, //    Logical Maximum 28h (40d)
				0x35, 0x01, //    Physical Minimum 1
				0x45, 0x28, //    Physical Maximum 28h (40d)
				0x75, 0x08, //    Report Size 8
				0x95, 0x01, //    Report Count 1
				0x91, 0x02, //    Output (Variable)
				/*report size 8x1=8bits*/
				0x09, 0x6D, //    Usage Sample Count
				0x15, 0x00, //    Logical Minimum 0
				0x26, 0xFF, 0x00, //    Logical Maximum FFh (255d)
				0x35, 0x00, //    Physical Minimum 0
				0x46, 0xFF, 0x00, //    Physical Maximum FFh (255d)
				0x75, 0x08, //    Report Size 8
				0x95, 0x01, //    Report Count 1
				0x91, 0x02, //    Output (Variable)
				/*report size 8x1=8bits*/
				0x09, 0x51, //    Usage Sample Period
				0x66, 0x03, 0x10, //    Unit 1003h (4099d)
				0x55, 0xFD, //    Unit Exponent FDh (253d)
				0x15, 0x00, //    Logical Minimum 0
				0x26, 0xFF, 0x7F, //    Logical Maximum 7FFFh (32767d)
				0x35, 0x00, //    Physical Minimum 0
				0x46, 0xFF, 0x7F, //    Physical Maximum 7FFFh (32767d)
				0x75, 0x10, //    Report Size 10h (16d)
				0x95, 0x01, //    Report Count 1
				0x91, 0x02, //    Output (Variable)
				/*report size 16x1=16bits*/
				0x55, 0x00, //    Unit Exponent 0
				0x66, 0x00, 0x00, //    Unit 0
				0xC0, //    End Collection
				/**********************************************************************/
				// REPORT EFFECT 1
				0x09, 0xAB, //    Usage Effect
				0xA1, 0x02, //    Collection Datalink
				0x85, 0x01, //    Report ID 1
				0x09, 0x25, //    Usage Effect Type
				0xA1, 0x02, //    Collection Datalink
				0x09, 0x26, //    Usage ET Constant Force
				0x09, 0x27, //    Usage ET Ramp
				0x09, 0x30, //    Usage ET Square
				0x09, 0x31, //    Usage ET Sine
				0x09, 0x32, //    Usage ET Triangle
				0x09, 0x33, //    Usage ET Sawtooth Up
				0x09, 0x34, //    Usage ET Sawtooth Down
				0x09, 0x40, //    Usage ET Spring
				0x09, 0x41, //    Usage ET Damper
				0x09, 0x42, //    Usage ET Inertia
				0x09, 0x43, //    Usage ET Friction
				0x09, 0x28, //    Usage ET Custom Force Data
				0x25, 0x0C, //    Logical Maximum Ch (12d)
				0x15, 0x01, //    Logical Minimum 1
				0x35, 0x01, //    Physical Minimum 1
				0x45, 0x0C, //    Physical Maximum Ch (12d)
				0x75, 0x08, //    Report Size 8
				0x95, 0x01, //    Report Count 1
				0xB1, 0x00, //    Feature
				/*report size 8x1=8bits*/
				0xC0, // End Collection
				0x05, 0x01, //    Usage Page Generic Desktop
				0x09, 0x3B, //    Usage Byte Count
				0x15, 0x00, //    Logical Minimum 0
				0x26, 0xFF, 0x01, //    Logical Maximum 1FFh (511d)
				0x35, 0x00, //    Physical Minimum 0
				0x46, 0xFF, 0x01, //    Physical Maximum 1FFh (511d)
				0x75, 0x0A, //    Report Size Ah (10d)
				0x95, 0x01, //    Report Count 1
				0xB1, 0x02, //    Feature (Variable)
				/*report size 10x1=10bits*/
				0x75, 0x06, //    Report Size 6
				0xB1, 0x01, //    Feature (Constant)
				/*report size 6x1=6bits*/
				/*TOTAL: 16*/
				0xC0, //    End Collection
				/**********************************************************************/
				// REPORT EFFECT 2
				0x05, 0x0F, //    Usage Page Physical Interface
				0x09, 0x89, //    Usage Block Load Status
				0xA1, 0x02, //    Collection Datalink
				0x85, 0x02, //    Report ID 2
				0x09, 0x22, //    Usage Effect Block Index
				0x25, 0x28, //    Logical Maximum 28h (40d)
				0x15, 0x01, //    Logical Minimum 1
				0x35, 0x01, //    Physical Minimum 1
				0x45, 0x28, //    Physical Maximum 28h (40d)
				0x75, 0x08, //    Report Size 8
				0x95, 0x01, //    Report Count 1
				0xB1, 0x02, //    Feature (Variable)
				/*report size 8x1=8bits*/
				0x09, 0x8B, //    Usage Block Load Full
				0xA1, 0x02, //    Collection Datalink
				0x09, 0x8C, //    Usage Block Load Error
				0x09, 0x8D, //    Usage Block Handle
				0x09, 0x8E, //    Usage PID Block Free Report
				0x25, 0x03, //    Logical Maximum 3
				0x15, 0x01, //    Logical Minimum 1
				0x35, 0x01, //    Physical Minimum 1
				0x45, 0x03, //    Physical Maximum 3
				0x75, 0x08, //    Report Size 8
				0x95, 0x01, //    Report Count 1
				0xB1, 0x00, //    Feature
				/*report size 8x1=8bits*/
				0xC0, // End Collection
				0x09, 0xAC, //    Usage Undefined
				0x15, 0x00, //    Logical Minimum 0
				0x27, 0xFF, 0xFF, 0x00, 0x00, //    Logical Maximum FFFFh (65535d)
				0x35, 0x00, //    Physical Minimum 0
				0x47, 0xFF, 0xFF, 0x00, 0x00, //    Physical Maximum FFFFh (65535d)
				0x75, 0x10, //    Report Size 10h (16d)
				0x95, 0x01, //    Report Count 1
				0xB1, 0x00, //    Feature
				/*report size 16x1=16bits*/
				0xC0, //    End Collection
				/**********************************************************************/
				// REPORT EFFECT 3
				0x09, 0x7F, //    Usage ROM Pool Size
				0xA1, 0x02, //    Collection Datalink
				0x85, 0x03, //    Report ID 3
				0x09, 0x80, //    Usage ROM Effect Block Count
				0x75, 0x10, //    Report Size 10h (16d)
				0x95, 0x01, //    Report Count 1
				0x15, 0x00, //    Logical Minimum 0
				0x35, 0x00, //    Physical Minimum 0
				0x27, 0xFF, 0xFF, 0x00, 0x00, //    Logical Maximum FFFFh (65535d)
				0x47, 0xFF, 0xFF, 0x00, 0x00, //    Physical Maximum FFFFh (65535d)
				0xB1, 0x02, //    Feature (Variable)
				/*report size 16x1=16bits*/
				0x09, 0x83, //    Usage PID Pool Move Report
				0x26, 0xFF, 0x00, //    Logical Maximum FFh (255d)
				0x46, 0xFF, 0x00, //    Physical Maximum FFh (255d)
				0x75, 0x08, //    Report Size 8
				0x95, 0x01, //    Report Count 1
				0xB1, 0x02, //    Feature (Variable)
				/*report size 8x1=8bits*/
				0x09, 0xA9, //    Usage Undefined
				0x09, 0xAA, //    Usage Undefined
				0x75, 0x01, //    Report Size 1
				0x95, 0x02, //    Report Count 2
				0x15, 0x00, //    Logical Minimum 0
				0x25, 0x01, //    Logical Maximum 1
				0x35, 0x00, //    Physical Minimum 0
				0x45, 0x01, //    Physical Maximum 1
				0xB1, 0x02, //    Feature (Variable)
				/*report size 2x1=2bits*/
				0x75, 0x06, //    Report Size 6
				0x95, 0x01, //    Report Count 1
				0xB1, 0x03, //    Feature (Constant, Variable)
				/*report size 6x1=6bits*/
				/*TOTAL 6+2=8*/
				0xC0, //    End Collection
				0xc0, //     END_COLLECTION
};
