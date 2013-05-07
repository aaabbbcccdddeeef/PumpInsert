/*----------------------------------------------------------------------------
 * Name:    GLCD.h
 * Purpose: MCB1700 low level Graphic LCD (320x240 pixels) prototypes
 * Version: V1.00
 * Note(s):
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2009 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------
 * History:
 *          V1.00 Initial Version
 *----------------------------------------------------------------------------*/

#ifndef _GLCD_H
#define _GLCD_H

/*------------------------------------------------------------------------------
  color coding.
  GLCD is coded:   15..11 red, 10..5 green, 4..0 blue  (unsigned short)  GLCD_R5, GLCD_G6, GLCD_B5   
  original coding: 17..12 red, 11..6 green, 5..0 blue                    ORG_R6,  ORG_G6,  ORG_B6

  ORG_R1..5 = GLCD_R0..4,  ORG_R0 = GLCD_R4
  ORG_G0..5 = GLCD_G0..5,
  ORG_B1..5 = GLCD_B0..4,  ORG_B0 = GLCD_B4
 *------------------------------------------------------------------------------*/
                            
/* GLCD RGB color definitions */
#define Black           0x0000		/*   0,   0,   0 */
#define Navy            0x000F      /*   0,   0, 128 */
#define DarkGreen       0x03E0      /*   0, 128,   0 */
#define DarkCyan        0x03EF      /*   0, 128, 128 */
#define Maroon          0x7800      /* 128,   0,   0 */
#define Purple          0x780F      /* 128,   0, 128 */
#define Olive           0x7BE0      /* 128, 128,   0 */
#define LightGrey       0xC618      /* 192, 192, 192 */
#define DarkGrey        0x39E7//64,64,64 //0x7BEF      /* 128, 128, 128 */
#define Blue            0x001F      /*   0,   0, 255 */
#define Green           0x07E0      /*   0, 255,   0 */
#define Cyan            0x07FF      /*   0, 255, 255 */
#define Red             0xF800      /* 255,   0,   0 */
#define Magenta         0xF81F      /* 255,   0, 255 */
#define Yellow          0xFFE0      /* 255, 255, 0   */
#define White           0xFFFF      /* 255, 255, 255 */

#define GUI_ICON0           0xf0f0f0
#define GUI_ICON1               0xffa3a3
#define GUI_ICON2               0xe3e3e3
#define GUI_ICON3           0x8080c0
#define GUI_ICON4           0x80f380
#define GUI_ICON5       0xaa8080
#define GUI_ICON6           0xffD3d3
#define GUI_ICON7       0xD3D3D3
#define GUI_ICON8           0xD3D3D3


#define main_icon_x             10
#define main_icon_y             70
#define main_icon_weight   300    
#define main_icon_height    100

#define option_icon_size       50

//==========for panel version == v01===========
#define option_icon_0_x             12
#define option_icon_0_y             55
#define option_icon_1_x             73
#define option_icon_1_y             option_icon_0_y
#define option_icon_2_x             134
#define option_icon_2_y             option_icon_0_y
#define option_icon_3_x             195
#define option_icon_3_y             option_icon_0_y
#define option_icon_4_x             256
#define option_icon_4_y             option_icon_0_y
#define option_icon_5_x             option_icon_0_x
#define option_icon_5_y             135
#define option_icon_6_x             option_icon_1_x
#define option_icon_6_y             option_icon_5_y
#define option_icon_7_x             option_icon_2_x
#define option_icon_7_y             option_icon_5_y
#define option_icon_8_x             option_icon_3_x
#define option_icon_8_y             option_icon_5_y
#define option_icon_9_x             option_icon_4_x
#define option_icon_9_y             option_icon_5_y

//==========for panel version == v02===========
#define option_icon_0_x1             11
#define option_icon_0_y1             45
#define option_icon_0_x2             64
#define option_icon_0_y2             114

#define option_icon_1_x1             72
#define option_icon_1_y1             option_icon_0_y1
#define option_icon_1_x2             125
#define option_icon_1_y2             option_icon_0_y2

#define option_icon_2_x1             133
#define option_icon_2_y1             option_icon_0_y1
#define option_icon_2_x2             186
#define option_icon_2_y2             option_icon_0_y2

#define option_icon_3_x1             194
#define option_icon_3_y1             option_icon_0_y1
#define option_icon_3_x2             247
#define option_icon_3_y2             option_icon_0_y2

#define option_icon_4_x1             255
#define option_icon_4_y1             option_icon_0_y1
#define option_icon_4_x2             308
#define option_icon_4_y2             option_icon_0_y2

#define option_icon_5_x1             option_icon_0_x1
#define option_icon_5_y1             125
#define option_icon_5_x2             option_icon_0_x2
#define option_icon_5_y2             194

#define option_icon_6_x1             option_icon_1_x1
#define option_icon_6_y1             option_icon_5_y1
#define option_icon_6_x2             option_icon_1_x2
#define option_icon_6_y2             option_icon_5_y2

#define option_icon_7_x1             option_icon_2_x1
#define option_icon_7_y1             option_icon_5_y1
#define option_icon_7_x2             option_icon_2_x2
#define option_icon_7_y2             option_icon_5_y2

#define option_icon_8_x1             option_icon_3_x1
#define option_icon_8_y1             option_icon_5_y1
#define option_icon_8_x2             option_icon_3_x2
#define option_icon_8_y2             option_icon_5_y2

#define option_icon_9_x1            option_icon_4_x1
#define option_icon_9_y1             option_icon_5_y1
#define option_icon_9_x2             option_icon_4_x2
#define option_icon_9_y2             option_icon_5_y2

#define second_interval              34

#define second_1_x1                    20
#define second_1_y1                    42
#define second_1_x2                    39
#define second_1_y2                    61

#define second_2_x1                    second_1_x1
#define second_2_y1                    (second_1_y1+(second_interval*1))
#define second_2_x2                    second_1_x2
#define second_2_y2                    (second_1_y2+(second_interval*1))

#define second_3_x1                    second_1_x1
#define second_3_y1                    (second_1_y1+(second_interval*2))
#define second_3_x2                    second_1_x2
#define second_3_y2                    (second_1_y2+(second_interval*2))

#define second_4_x1                    second_1_x1
#define second_4_y1                    (second_1_y1+(second_interval*3))
#define second_4_x2                    second_1_x2
#define second_4_y2                    (second_1_y2+(second_interval*3))

#define second_5_x1                    second_1_x1
#define second_5_y1                    (second_1_y1+(second_interval*4))
#define second_5_x2                    second_1_x2
#define second_5_y2                    (second_1_y2+(second_interval*4))

#define second_1_sel_x1                    6
#define second_1_sel_y1                     40
#define second_1_sel_x2                     313
#define second_1_sel_y2                     64

#define second_2_sel_x1                    second_1_sel_x1
#define second_2_sel_y1                    (second_1_sel_y1+(second_interval*1))
#define second_2_sel_x2                    second_1_sel_x2
#define second_2_sel_y2                    (second_1_sel_y2+(second_interval*1))

#define second_3_sel_x1                    second_1_sel_x1
#define second_3_sel_y1                    (second_1_sel_y1+(second_interval*2))
#define second_3_sel_x2                    second_1_sel_x2
#define second_3_sel_y2                    (second_1_sel_y2+(second_interval*2))

#define second_4_sel_x1                    second_1_sel_x1
#define second_4_sel_y1                    (second_1_sel_y1+(second_interval*3))
#define second_4_sel_x2                    second_1_sel_x2
#define second_4_sel_y2                    (second_1_sel_y2+(second_interval*3))

#define second_5_sel_x1                    second_1_sel_x1
#define second_5_sel_y1                    (second_1_sel_y1+(second_interval*4))
#define second_5_sel_x2                    second_1_sel_x2
#define second_5_sel_y2                    (second_1_sel_y2+(second_interval*4))


#define second_Line1                43
#define second_Line2               (second_Line1+(second_interval*1))
#define second_Line3               (second_Line1+(second_interval*2))
#define second_Line4               (second_Line1+(second_interval*3))
#define second_Line5               (second_Line1+(second_interval*4))

#define third_interval              29

#define third_1_x1                    20
#define third_1_y1                    38
#define third_1_x2                    39
#define third_1_y2                    57

#define third_2_x1                    second_1_x1
#define third_2_y1                    (second_1_y1+(third_interval*1))
#define third_2_x2                    second_1_x2
#define third_2_y2                    (second_1_y2+(third_interval*1))

#define third_3_x1                    second_1_x1
#define third_3_y1                    (second_1_y1+(third_interval*2))
#define third_3_x2                    second_1_x2
#define third_3_y2                    (second_1_y2+(third_interval*2))

#define third_4_x1                    second_1_x1
#define third_4_y1                    (second_1_y1+(third_interval*3))
#define third_4_x2                    second_1_x2
#define third_4_y2                    (second_1_y2+(third_interval*3))

#define third_5_x1                    second_1_x1
#define third_5_y1                    (second_1_y1+(third_interval*4))
#define third_5_x2                    second_1_x2
#define third_5_y2                    (second_1_y2+(third_interval*4))

#define third_6_x1                    second_1_x1
#define third_6_y1                    (second_1_y1+(third_interval*5))
#define third_6_x2                    second_1_x2
#define third_6_y2                    (second_1_y2+(third_interval*5))

#define third_1_sel_x1                    6
#define third_1_sel_y1                     36
#define third_1_sel_x2                     313
#define third_1_sel_y2                     60

#define third_2_sel_x1                    second_1_sel_x1
#define third_2_sel_y1                    (second_1_sel_y1+(third_interval*1))
#define third_2_sel_x2                    second_1_sel_x2
#define third_2_sel_y2                    (second_1_sel_y2+(third_interval*1))

#define third_3_sel_x1                    second_1_sel_x1
#define third_3_sel_y1                    (second_1_sel_y1+(third_interval*2))
#define third_3_sel_x2                    second_1_sel_x2
#define third_3_sel_y2                    (second_1_sel_y2+(third_interval*2))

#define third_4_sel_x1                    second_1_sel_x1
#define third_4_sel_y1                    (second_1_sel_y1+(third_interval*3))
#define third_4_sel_x2                    second_1_sel_x2
#define third_4_sel_y2                    (second_1_sel_y2+(third_interval*3))

#define third_5_sel_x1                    second_1_sel_x1
#define third_5_sel_y1                    (second_1_sel_y1+(third_interval*4))
#define third_5_sel_x2                    second_1_sel_x2
#define third_5_sel_y2                    (second_1_sel_y2+(third_interval*4))

#define third_6_sel_x1                    second_1_sel_x1
#define third_6_sel_y1                    (second_1_sel_y1+(third_interval*5))
#define third_6_sel_x2                    second_1_sel_x2
#define third_6_sel_y2                    (second_1_sel_y2+(third_interval*5))


#define third_Line1                39
#define third_Line2               (third_Line1+(third_interval*1))
#define third_Line3               (third_Line1+(third_interval*2))
#define third_Line4               (third_Line1+(third_interval*3))
#define third_Line5               (third_Line1+(third_interval*4))
#define third_Line6               (third_Line1+(third_interval*5))

#define energy_x1                               276
#define energy_y1                               3
#define energy_x2                               315
#define energy_y2                               21

#define energy_w_0_x1                       4
#define energy_w_0_y1                       153
#define energy_w_0_x2                       42
#define energy_w_0_y2                       171

#define energy_w_1_x1                       (energy_w_0_x1+(50*1))
#define energy_w_1_y1                       energy_w_0_y1
#define energy_w_1_x2                       (energy_w_0_x2+(50*1))
#define energy_w_1_y2                       energy_w_0_y2

#define energy_w_2_x1                       (energy_w_0_x1+(50*2))
#define energy_w_2_y1                       energy_w_0_y1
#define energy_w_2_x2                       (energy_w_0_x2+(50*1))
#define energy_w_2_y2                       energy_w_0_y2

#define energy_w_3_x1                       (energy_w_0_x1+(50*3))
#define energy_w_3_y1                       energy_w_0_y1
#define energy_w_3_x2                       (energy_w_0_x2+(50*1))
#define energy_w_3_y2                       energy_w_0_y2

#define energy_w_4_x1                       (energy_w_0_x1+(50*4))
#define energy_w_4_y1                       energy_w_0_y1
#define energy_w_4_x2                       (energy_w_0_x2+(50*1))
#define energy_w_4_y2                       energy_w_0_y2

#define main_x1                                     8
#define main_y1                                     43
#define main_x2                                     319
#define main_y2                                     151
//=====================TOP BAR POINT=====================
#define _main_background_x1                      0
#define _main_background_y1                      31
#define _main_background_x2                      319
#define _main_background_y2                      239

#define _main_top_bar_interval_x             160
#define _main_top_bar_interval_y             50

#define _main_top_bar_x1                          80
#define _main_top_bar_y1                          0
#define _main_top_bar_x2                          239
#define _main_top_bar_y2                          29

#define _L1_top_bar_interval_x             160
#define _L1_top_bar_interval_y             50
//#define top_option_interval                   50

#define _L1_top_bar_x1                          80
#define _L1_top_bar_y1                          0
#define _L1_top_bar_x2                          239
#define _L1_top_bar_y2                          29

/*
#define _top_option1_x1                          0
#define _top_option1_y1                          0
#define _top_option1_x2                          319
#define _top_option1_y2                          29

#define top_option2_x1                          _top_option1_x1
#define top_option2_y1                          (_top_option1_y1+(_L1_top_bar_interval_y*1))
#define top_option2_x2                          _top_option1_x2
#define top_option2_y2                          (_top_option1_y2+(_L1_top_bar_interval_y*1))

#define top_option3_x1                          _top_option1_x1
#define top_option3_y1                          (_top_option1_y1+(_L1_top_bar_interval_y*2))
#define top_option3_x2                          _top_option1_x2
#define top_option3_y2                          (_top_option1_y2+(_L1_top_bar_interval_y*2))

#define top_option4_x1                          _top_option1_x1
#define top_option4_y1                          (_top_option1_y1+(_L1_top_bar_interval_y*3))
#define top_option4_x2                          _top_option1_x2
#define top_option4_y2                          (_top_option1_y2+(_L1_top_bar_interval_y*3))

#define top_option5_x1                          _top_option1_x1
#define top_option5_y1                          (_top_option1_y1+(_L1_top_bar_interval_y*4))
#define top_option5_x2                          _top_option1_x2
#define top_option5_y2                          (_top_option1_y2+(_L1_top_bar_interval_y*4))

#define top_option6_x1                          _top_option1_x1
#define top_option6_y1                          _top_option1_y1
#define top_option6_x2                          _top_option1_x2
#define top_option6_y2                          _top_option1_y2

#define top_option7_x1                          top_option2_x1
#define top_option7_y1                          top_option2_y1
#define top_option7_x2                          top_option2_x2
#define top_option7_y2                          top_option2_y2

#define top_option8_x1                          top_option3_x1
#define top_option8_y1                          top_option3_y1
#define top_option8_x2                          top_option3_x2
#define top_option8_y2                          top_option3_y2

#define top_option9_x1                          top_option4_x1
#define top_option9_y1                          top_option4_y1
#define top_option9_x2                          top_option4_x2
#define top_option9_y2                          top_option4_y2

#define top_option10_x1                          top_option5_x1
#define top_option10_y1                          top_option5_y1
#define top_option10_x2                          top_option5_x2
#define top_option10_y2                          top_option5_y2
*/
//=====================BOTTOM BAR POINT=====================
#define _bottom_bar_x1                           0
#define _bottom_bar_y1                           207
#define _bottom_bar_x2                           319
#define _bottom_bar_y2                           239

#define _top_bar_x1                           0
#define _top_bar_y1                           0
#define _top_bar_x2                           319
#define _top_bar_y2                           31
//=====================L1 OPTION POINT=====================
#define _L1_background_x1                      0
#define _L1_background_y1                      31
#define _L1_background_x2                      319
#define _L1_background_y2                      206//239

#define _L1_icon_1_x1                            6
#define _L1_icon_1_y1                            50
#define _L1_icon_1_x2                            71
#define _L1_icon_1_y2                            115

#define _L1_icon_interval_hori               61
#define _L1_icon_interval_verti              76

//=====================L2 OPTION POINT=====================
#define _L2_background_x1                      0
#define _L2_background_y1                      31
#define _L2_background_x2                      319
#define _L2_background_y2                      206//239

#define _L2_list_interval_x                        160
#define _L2_list_interval_y                        20

#define _L2_list_x1                                  0
#define _L2_list_y1                                  0
#define _L2_list_x2                                  159
#define _L2_list_y2                                  19

#define _L2_list_sel_x1                                  0
#define _L2_list_sel_y1                                  0
#define _L2_list_sel_x2                                  159
#define _L2_list_sel_y2                                  18

#define _L2_option_interval                  32

#define _L2_option_1_x1                           20
#define _L2_option_1_y1                           41
#define _L2_option_1_x2                           179
#define _L2_option_1_y2                           60

#define _L2_option_2_x1                           _L2_option_1_x1
#define _L2_option_2_y1                           (_L2_option_1_y1+(_L2_option_interval*1))
#define _L2_option_2_x2                           _L2_option_1_x2
#define _L2_option_2_y2                           (_L2_option_1_y2+(_L2_option_interval*1))

#define _L2_option_3_x1                           _L2_option_1_x1
#define _L2_option_3_y1                           (_L2_option_1_y1+(_L2_option_interval*2))
#define _L2_option_3_x2                           _L2_option_1_x2
#define _L2_option_3_y2                           (_L2_option_1_y2+(_L2_option_interval*2))

#define _L2_option_1_sel_x1                           20
#define _L2_option_1_sel_y1                           42
#define _L2_option_1_sel_x2                           179
#define _L2_option_1_sel_y2                           61

#define _L2_option_2_sel_x1                           _L2_option_1_sel_x1
#define _L2_option_2_sel_y1                           (_L2_option_1_sel_y1+(_L2_option_interval*1))
#define _L2_option_2_sel_x2                           _L2_option_1_sel_x2
#define _L2_option_2_sel_y2                           (_L2_option_1_sel_y2+(_L2_option_interval*1))

#define _L2_option_3_sel_x1                           _L2_option_1_sel_x1
#define _L2_option_3_sel_y1                           (_L2_option_1_sel_y1+(_L2_option_interval*2))
#define _L2_option_3_sel_x2                           _L2_option_1_sel_x2
#define _L2_option_3_sel_y2                           (_L2_option_1_sel_y2+(_L2_option_interval*2))

#define _L2_highlight_1_x1                           15
#define _L2_highlight_1_y1                           37
#define _L2_highlight_1_x2                           305
#define _L2_highlight_1_y2                           64

#define _L2_highlight_2_x1                           _L2_highlight_1_x1
#define _L2_highlight_2_y1                           (_L2_highlight_1_y1+(_L2_option_interval*1))
#define _L2_highlight_2_x2                           _L2_highlight_1_x2
#define _L2_highlight_2_y2                           (_L2_highlight_1_y2+(_L2_option_interval*1))

#define _L2_highlight_3_x1                           _L2_highlight_1_x1
#define _L2_highlight_3_y1                           (_L2_highlight_1_y1+(_L2_option_interval*2))
#define _L2_highlight_3_x2                           _L2_highlight_1_x2
#define _L2_highlight_3_y2                           (_L2_highlight_1_y2+(_L2_option_interval*2))

#define _L2_highlight_4_x1                           _L2_highlight_1_x1
#define _L2_highlight_4_y1                           (_L2_highlight_1_y1+(_L2_option_interval*3))
#define _L2_highlight_4_x2                           _L2_highlight_1_x2
#define _L2_highlight_4_y2                           (_L2_highlight_1_y2+(_L2_option_interval*3))

#define _L2_highlight_5_x1                           _L2_highlight_1_x1
#define _L2_highlight_5_y1                           (_L2_highlight_1_y1+(_L2_option_interval*4))
#define _L2_highlight_5_x2                           _L2_highlight_1_x2
#define _L2_highlight_5_y2                           (_L2_highlight_1_y2+(_L2_option_interval*4))

#define _L2_highlight_bar_x1                           15
#define _L2_highlight_bar_y1                           37
#define _L2_highlight_bar_x2                           305
#define _L2_highlight_bar_y2                           64

#define _L2_highlight_bar_off_x1                           _L2_highlight_bar_x1
#define _L2_highlight_bar_off_y1                           (_L2_highlight_bar_y1+(_L2_option_interval*1))
#define _L2_highlight_bar_off_x2                           _L2_highlight_bar_x2
#define _L2_highlight_bar_off_y2                           (_L2_highlight_bar_y2+(_L2_option_interval*1))

#define _L2_highlight_bar_on_x1                           _L2_highlight_bar_x1
#define _L2_highlight_bar_on_y1                           (_L2_highlight_bar_y1+(_L2_option_interval*2))
#define _L2_highlight_bar_on_x2                           _L2_highlight_bar_x2
#define _L2_highlight_bar_on_y2                           (_L2_highlight_bar_y2+(_L2_option_interval*2))

//=====================L3 OPTION POINT=====================
#define _L3_background_x1                      0
#define _L3_background_y1                      31
#define _L3_background_x2                      319
#define _L3_background_y2                      206//239

#define _L3_list_interval_x                        160
#define _L3_list_interval_y                        20

#define _L3_list_unsel_x1                                  0
#define _L3_list_unsel_y1                                  2
#define _L3_list_unsel_x2                                  159
#define _L3_list_unsel_y2                                  16

#define _L3_list_sel_x1                                  0
#define _L3_list_sel_y1                                  1
#define _L3_list_sel_x2                                  159
#define _L3_list_sel_y2                                  16

#define _L3_icon_off_x1                           271
#define _L3_icon_off_y1                           123//153
//#define _L3_icon_off_x2                           290
//#define _L3_icon_off_y2                           55//171

#define _L3_icon_on_x1                           271
#define _L3_icon_on_y1                           153
//#define _L3_icon_off_x2                           290
//#define _L3_icon_off_y2                           55//171


#define _L3_option_interval                  29

#define _L3_option_1_x1                           20
#define _L3_option_1_y1                           39
#define _L3_option_1_x2                           179
#define _L3_option_1_y2                           54

#define _L3_option_2_x1                           _L3_option_1_x1
#define _L3_option_2_y1                           (_L3_option_1_y1+(_L3_option_interval*1))
#define _L3_option_2_x2                           _L3_option_1_x2
#define _L3_option_2_y2                           (_L3_option_1_y2+(_L3_option_interval*1))

#define _L3_option_3_x1                           _L3_option_1_x1
#define _L3_option_3_y1                           (_L3_option_1_y1+(_L3_option_interval*2))
#define _L3_option_3_x2                           _L3_option_1_x2
#define _L3_option_3_y2                           (_L3_option_1_y2+(_L3_option_interval*2))

#define _L3_option_4_x1                           _L3_option_1_x1
#define _L3_option_4_y1                           (_L3_option_1_y1+(_L3_option_interval*3))
#define _L3_option_4_x2                           _L3_option_1_x2
#define _L3_option_4_y2                           (_L3_option_1_y2+(_L3_option_interval*3))

#define _L3_option_5_x1                           _L3_option_1_x1
#define _L3_option_5_y1                           (_L3_option_1_y1+(_L3_option_interval*4))
#define _L3_option_5_x2                           _L3_option_1_x2
#define _L3_option_5_y2                           (_L3_option_1_y2+(_L3_option_interval*4))

#define _L3_option_6_x1                           _L3_option_1_x1
#define _L3_option_6_y1                           (_L3_option_1_y1+(_L3_option_interval*5))
#define _L3_option_6_x2                           _L3_option_1_x2
#define _L3_option_6_y2                           (_L3_option_1_y2+(_L3_option_interval*5))

#define _L3_option_1_sel_x1                           20
#define _L3_option_1_sel_y1                           42
#define _L3_option_1_sel_x2                           179
#define _L3_option_1_sel_y2                           61

#define _L3_option_2_sel_x1                           _L3_option_1_sel_x1
#define _L3_option_2_sel_y1                           (_L3_option_1_sel_y1+(_L3_option_interval*1))
#define _L3_option_2_sel_x2                           _L3_option_1_sel_x2
#define _L3_option_2_sel_y2                           (_L3_option_1_sel_y2+(_L3_option_interval*1))

#define _L3_option_3_sel_x1                           _L3_option_1_sel_x1
#define _L3_option_3_sel_y1                           (_L3_option_1_sel_y1+(_L3_option_interval*2))
#define _L3_option_3_sel_x2                           _L3_option_1_sel_x2
#define _L3_option_3_sel_y2                           (_L3_option_1_sel_y2+(_L3_option_interval*2))

#define _L3_highlight_x1                           15
#define _L3_highlight_y1                           33
#define _L3_highlight_x2                           306
#define _L3_highlight_y2                           58

#define _L3_highlight_off_x1                           _L3_highlight_x1
#define _L3_highlight_off_y1                           (_L3_highlight_y1+(_L3_option_interval*1))
#define _L3_highlight_off_x2                           _L3_highlight_x2
#define _L3_highlight_off_y2                           (_L3_highlight_y2+(_L3_option_interval*1))

#define _L3_highlight_on_x1                           _L3_highlight_x1
#define _L3_highlight_on_y1                           (_L3_highlight_y1+(_L3_option_interval*2))
#define _L3_highlight_on_x2                           _L3_highlight_x2
#define _L3_highlight_on_y2                           (_L3_highlight_y2+(_L3_option_interval*2))

#define _L3_onoff_x1                           271
#define _L3_onoff_y1                           38//153
#define _L3_onoff_x2                           290
#define _L3_onoff_y2                           56//171

//=====================TIPS POINT====================
#define _tips_interval                                      100

#define _Done_tip_x1                                    110
#define _Done_tip_y1                                    40
#define _Done_tip_x2                                    209
#define _Done_tip_y2                                    139

#define _Error_tip_x1                                    110
#define _Error_tip_y1                                    40
#define _Error_tip_x2                                    209
#define _Error_tip_y2                                    139

#define _Warning_tip_x1                                    110
#define _Warning_tip_y1                                    40
#define _Warning_tip_x2                                    209
#define _Warning_tip_y2                                    139

#define _Reset_tip_x1                                    10
#define _Reset_tip_y1                                    70
#define _Reset_tip_x2                                    109
#define _Reset_tip_y2                                    169

#define _Connect_tip_x1                                    0
#define _Connect_tip_y1                                    40
#define _Connect_tip_x2                                    319
#define _Connect_tip_y2                                    146

//==================VALUE LENGTH====================
#define _Value_x2                                           292
#define _L3_list_on_L2_offset                           1

#define _Length_c_second                                15
#define _Length_c_seconds                               15
#define _Length_c_10seconds                           32    
#define _Length_c_20seconds                           33 
#define _Length_c_30seconds                           33 
#define _Length_c_1minute                               40    
#define _Length_c_2minutes                             41       
#define _Length_c_5minutes                             41     
#define _Length_c_10minutes                           50         
#define _Length_c_30minutes                           50         
#define _Length_c_1hour                                   42

#define _Length_e_second                                42
#define _Length_e_seconds                                49
#define _Length_e_10seconds                            69    
#define _Length_e_20seconds                            70    
#define _Length_e_30seconds                            70    
#define _Length_e_1minute                                 53      
#define _Length_e_2minutes                                60       
#define _Length_e_5minutes                                60       
#define _Length_e_10minutes                              67         
#define _Length_e_30minutes                               67        
#define _Length_e_1hour                                     41



#define Top_offset       30

#define Line0                0+Top_offset
#define Line1               24+Top_offset
#define Line2               48+Top_offset
#define Line3               72+Top_offset
#define Line4               96+Top_offset
#define Line5               120+Top_offset
#define Line6               144+Top_offset
#define Line7               168+Top_offset
#define Line8               192+Top_offset
#define Line9               216+Top_offset

#define Record_Line0                5+Top_offset
#define Record_Line1               27+Top_offset
#define Record_Line2               49+Top_offset
#define Record_Line3               71+Top_offset
#define Record_Line4               93+Top_offset
#define Record_Line5               115+Top_offset
#define Record_Line6               137+Top_offset
#define Record_Line7               159+Top_offset
#if(NUMBER_OF_PAGE1 == 4)
#define Record_height               44
#elif(NUMBER_OF_PAGE1 == 8)
#define Record_height               22//44
#endif

/* 
#define Line0                0+Top_offset
#define Line1               16+Top_offset
#define Line2               32+Top_offset
#define Line3               48+Top_offset
#define Line4               64+Top_offset
#define Line5               80+Top_offset
#define Line6               96+Top_offset
#define Line7               112+Top_offset
#define Line8               128+Top_offset
#define Line9               144+Top_offset
#define Line10             160+Top_offset
#define Line11             176+Top_offset
#define Line12             192+Top_offset
//#define Line13             208+Top_offset
*/ 

//===right down===
#define time_rd_y               168
#define time_rd_x          254
#define date_rd_y               168+20
#define date_rd_x          238
//===left up===
#define time_lu_y               6
#define time_lu_x          130
#define date_lu_y               6
#define date_lu_x          10

#define icon_sampleID_x             10
#define icon_sampleID_y             168
#define icon_operatorID_x           12
#define icon_operatorID_y           188

#define icon_option_x                  12
#define icon_option_y                  4
#define icon_power_x                  290
#define icon_power_y                  4
#define icon_verify_x                  4
#define icon_verify_y                  5
#define icon_locked_x                  4
#define icon_locked_y                  24
#define icon_unit_current_x                         270
#define icon_unit_current_y                         140
#define icon_unit_last_x                         274
#define icon_unit_last_y                         130
#define result_current_x                         260
#define result_current_y                         94
#define result_last_x                         268
#define result_last_y                         133
#define caption_parameter_x         160
#define caption_parameter_y         0
#define main_title_x         160
#define main_title_y         2
#define icon_read_mode1_x                286
#define icon_read_mode1_y                84
#define icon_read_mode2_x                282
#define icon_read_mode2_y                84
#define icon_selected_x                     286
#define icon_interval_x                     222

#if(_SAMPLE_RELEASE == TRUE)
#define slider_vertical_x                   45                   
#define slider_vertical_y                   52
#define slider_vertical_width            70
#define slider_vertical_height          138
#define slider_vertical_interval          4//7:value = 20
#else
#define slider_vertical_x                   45                   
#define slider_vertical_y                   40
#define slider_vertical_width            70
#define slider_vertical_height          153
#define slider_vertical_interval          7
#endif
#define read_process_bar_x              90
#define read_process_bar_y              55


#define date_adjust_x                           75
#define date_adjust_y                           106
#define date_lenth_4                            60
#define date_lenth_2                            38
#define date_ymd_year_active_x                              (date_adjust_x-6)
#define date_ymd_year_active_y                              (date_adjust_y-2)
#define date_ymd_month_active_x                           (date_adjust_x+75)
#define date_ymd_month_active_y                           (date_adjust_y-2)
#define date_ymd_day_active_x                               (date_adjust_x+133)
#define date_ymd_day_active_y                               (date_adjust_y-2)
#define date_dmy_year_active_x                              (date_adjust_x+109)
#define date_dmy_year_active_y                              (date_adjust_y-2)
#define date_dmy_month_active_x                           (date_adjust_x+51)
#define date_dmy_month_active_y                           (date_adjust_y-2)
#define date_dmy_day_active_x                               (date_adjust_x-6)
#define date_dmy_day_active_y                               (date_adjust_y-2)
#define date_mdy_year_active_x                              (date_adjust_x+109)
#define date_mdy_year_active_y                             (date_adjust_y-2)
#define date_mdy_month_active_x                           (date_adjust_x-6)
#define date_mdy_month_active_y                           (date_adjust_y-2)
#define date_mdy_day_active_x                               (date_adjust_x+51)
#define date_mdy_day_active_y                              (date_adjust_y-2)

#define time_adjust_24_x                                               95
#define time_adjust_24_y                                               106
#define time_adjust_12_x                                               70
#define time_adjust_12_y                                               106
#define time_24_hour_active_x                                      (time_adjust_24_x-7)
#define time_24_hour_active_y                                       (time_adjust_24_y-2)
#define time_24_min_active_x                                        (time_adjust_24_x+47)
#define time_24_min_active_y                                        (time_adjust_24_y-2)    
#define time_24_sec_active_x                                        (time_adjust_24_x+105)
#define time_24_sec_active_y                                        (time_adjust_24_y-2)
#define time_12_hour_active_x                                       (time_adjust_12_x-8)
#define time_12_hour_active_y                                       (time_adjust_12_y-2)
#define time_12_min_active_x                                        (time_adjust_12_x+47)
#define time_12_min_active_y                                        (time_adjust_12_y-2)
#define time_12_sec_active_x                                        (time_adjust_12_x+105)    
#define time_12_sec_active_y                                        (time_adjust_12_y-2)
    
#define button_confirm_date_x                                                108
#define button_confirm_date_y                                                145

#define scroll_x                                                                    305
#define scroll_y                                                                    30
#define scroll_height                                                            156
#if(_SAMPLE_RELEASE == TRUE)
#define long_scroll_x                                                                    305
#define long_scroll_y                                                                    4
#define long_scroll_height                                                            207
#endif
#define record_date_x                                                           20
#define record_time_x                                                           140
#define record_result_x                                                         220
#define record_unit_x                                                            260
#define record_sid_x                                                             20
#define record_oid_x                                                            165
#define record_select_x0                                                       10
#define record_select_y0                                                       35
#define record_select_x1                                                       300
#if(NUMBER_OF_PAGE1 == 4)
#define record_select_y1                                                       73
#elif(NUMBER_OF_PAGE1 == 8)
#define record_select_y1                                                       51
#endif
#define password_x                                                              64
#define password_y                                                              112

#define sid_x                                                                           10
#define sid_y                                                                       112
//====================16B=====================
#define icon_option           0x7f
#define icon_sampleID      0x80
#define icon_operatorID      0x81
#define icon_datetime      0x82
#define icon_contrast     0x83
#define icon_powermanage     0x84
#define icon_audio     0x85
#define icon_password     0x86
#define icon_information     0x87
#define icon_delete     0x88

#define icon_battery            0x89
#define icon_verify              0x8a

#define icon_selected           0x8b
#define icon_check_off          0x8c
#define icon_check_on           0x8d
//====================24B=====================
#define icon_locked              0x7f
//====================32B=====================
#define icon_readmode1      0x7F
#define icon_readmode2      0x81

extern void GLCD_init           (void);
extern void GLCD_SetPixelIndex(int x, int y, int PixelIndex) ;
extern unsigned int GLCD_GetPixelIndex(int x, int y) ;
extern void GLCD_XorPixel(int x, int y);
extern void GLCD_DrawHLine(int x0, int y,  int x1, int color);
extern void GLCD_DrawXorHLine(int x0, int y,  int x1, int color);
extern void GLCD_DrawVLine(int x, int y0,  int y1, int color);
extern void GLCD_FillRect(int x0, int y0, int x1, int y1 ,int color);
extern void GLCD_clear          (unsigned short color);
extern void GLCD_setTextColor   (unsigned short color);
extern void GLCD_setBackColor   (unsigned short color);
extern void GLCD_displayChar    (unsigned int ln, unsigned int col, unsigned char  c);
extern void GLCD_displayStringLn(unsigned int ln, unsigned char *s);
extern void GLCD_displayStringAt(const char *s,unsigned int x, unsigned int y );
extern void GLCD_bitmap         (unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned char *bitmap);
extern void GLCD_clearLn        (unsigned int ln);
extern void GLCD_putPixel       (unsigned int x, unsigned int y);

#endif /* _GLCD_H */
