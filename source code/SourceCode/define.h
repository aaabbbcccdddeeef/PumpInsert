/*****************************************************************************
 *   define.h:  difine file for NXP LPC17xx Family Microprocessors
 *
 *   Copyright(C) 2009, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2009.05.23  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/
#define _FW_VAERSION                                        "0.1.1.01"
#define _DEBUG_MODE                                         0//TRUE
#define _DEBUG_NO_LCD                                      0
#define _POWER_ON_LOGO                                   TRUE//FALSE
#define _SAMPLE_RELEASE                                   TRUE



#define _MANUAL_GAIN                                                0
#define _AUTO_GAIN                                                     0
#define _BOTTLE_TEST                                                  0
#define _TEMP_TEST                                                      0
//#define _SAMPLE_FREQ                                            500// Hz define in MDK
//--------------------------------------------------
// Definitions of Panel type
//--------------------------------------------------
#define _PANEL_EMBEST                                               0
#define _PANEL_RX                                                       1

#define _PANEL_TYPE                                                   _PANEL_RX

//--------------------------------------------------
// Definitions of Panel type
//--------------------------------------------------
#define _RX_V01                                                            0
#define _RX_V02                                                            1

//#define _PANEL_VERSION                                                   _RX_V01 //defined in MDK project

//--------------------------------------------------
// Definitions of PCB type
//--------------------------------------------------
#define _PCB_EMBEST                                                   0
#define _PCB_SINSCHE                                                  1
#define _PCB_SINSCHE_V02                                          2

#define _PCB_TYPE                                                        _PCB_SINSCHE_V02

//--------------------------------------------------
// Definitions of Memory type
//--------------------------------------------------
#define _MEMORY_SD                                                   0
#define _MEMORY_SPI_FLASH                                     1

#define _MEMORY_TYPE                                              _MEMORY_SPI_FLASH

//--------------------------------------------------
// Definitions of Flash Number
//--------------------------------------------------
#define _FLASH_NUM0                                                 0
#define _FLASH_NUM1                                                 1


#define  countof(Array)     (sizeof(Array)/sizeof(Array[0]))

//--------------------------------------------------
// Definitions of Bits
//--------------------------------------------------
#define _BIT0                           0x00000001
#define _BIT1                           0x00000002
#define _BIT2                           0x00000004
#define _BIT3                           0x00000008
#define _BIT4                           0x00000010
#define _BIT5                           0x00000020
#define _BIT6                           0x00000040
#define _BIT7                           0x00000080
#define _BIT8                           0x00000100
#define _BIT9                           0x00000200
#define _BIT10                          0x00000400
#define _BIT11                          0x00000800
#define _BIT12                          0x00001000
#define _BIT13                          0x00002000
#define _BIT14                          0x00004000
#define _BIT15                          0x00008000
//--------------------------------------------------
// Definitions of DT format
//--------------------------------------------------
#define YEAR_MON_DAY_24                                        0
#define YEAR_MON_DAY_12                                        1
#define DAY_MON_YEAR_24                                        2
#define DAY_MON_YEAR_12                                        3
#define MON_DAY_YEAR_24                                        4
#define MON_DAY_YEAR_12                                        5

//--------------------------------------------------
// Definitions of Date offset
//--------------------------------------------------
#define YEAR1                                                               0
#define YEAR2                                                               1
#define YEAR3                                                               2
#define YEAR4                                                               3
#define MONTH1                                                            4
#define MONTH2                                                            5
#define DAY1                                                                 6
#define DAY2                                                                 7

//--------------------------------------------------
// Definitions of Backlight off seconds
//--------------------------------------------------
#define BACKLIGHT_OFF_VALUE1                                0    
#define BACKLIGHT_OFF_VALUE2                                1
#define BACKLIGHT_OFF_VALUE3                                2
#define BACKLIGHT_OFF_VALUE4                                3
#define BACKLIGHT_OFF_VALUE5                                4
#define BACKLIGHT_OFF_VALUE6                                5

//--------------------------------------------------
// Definitions of Power off seconds
//--------------------------------------------------
#define POWER_OFF_VALUE1                                        0    
#define POWER_OFF_VALUE2                                        1
#define POWER_OFF_VALUE3                                        2
#define POWER_OFF_VALUE4                                        3
#define POWER_OFF_VALUE5                                        4
#define POWER_OFF_VALUE6                                        5

//--------------------------------------------------
// Definitions of Reading option
//--------------------------------------------------
#if(_SAMPLE_RELEASE == TRUE)
#define READING_TIME                                                30    
#define READ_TIMES                                                    60
#else
#define READING_TIME                                                20    
#define READ_TIMES                                                    1
#endif

//--------------------------------------------------
// Definitions of Language type
//--------------------------------------------------
#define LANGUAGE_CHINESE                                        0    
#define LANGUAGE_ENGLISH                                        1

//--------------------------------------------------
// Definitions of evaluation mode
//--------------------------------------------------
#define EVALUATION_MODE_AVERAGE                         0    
#define EVALUATION_MODE_SINGLE                            1
#define EVALUATION_MODE_MEDIAN                           2
//--------------------------------------------------
// Definitions of evaluation mode
//--------------------------------------------------
#define GAIN_MODE_AUTO                         0    
#define GAIN_MODE_MANUAL                            1

//--------------------------------------------------
// Definitions of UI message
//--------------------------------------------------
#define MESSAGE_NONE                                              0
#define MESSAGE_DATE_ERROR                                  1
#define MESSAGE_TIME_ERROR                                   2
#define MESSAGE_PASSWORD_DONE                          3

//--------------------------------------------------
// Definitions of UI color
//--------------------------------------------------
#define HIGHTLIGHT_BAR_BACKCOLOR                              0x80f380//0x868686//0x804040
#define HIGHTLIGHT_BAR_FORECOLOR                              0x804040//0xFFFFFF
#define SELECT_ICON_COLOR                                   0x80f380
#define FONT_COLOR                                                  0x000000
#define FONT_REVERSE_COLOR                                  0xFFFFFF
#define FRAME_SIDE_COLOR                                      0x0000FF
#define TOP_BAR_COLOR                                            0x606060//0x804040
#define BOTTOM_BAR_COLOR_L                                    0x606060//0x804040
#define BOTTOM_BAR_COLOR_M                                    0x606060//0x804040
#define BOTTOM_BAR_COLOR_R                                    0x606060//0x804040
#define MAIN_FRAME_BK                                                0xEBEBEB   
//--------------------------------------------------
// Definitions of Data length
//--------------------------------------------------
#define SAMPLE_ID_LENGTH                                            12+1
#define OPERATOR_ID_LENGTH                                        12+1

//--------------------------------------------------
// Definitions of record number per page
//--------------------------------------------------
#define NUMBER_OF_PAGE1                                            8//4
#define NUMBER_OF_PAGE2                                            10
//--------------------------------------------------
// Definitions of standby value
//--------------------------------------------------
#define PCONP_STANDBY_Val             0x80008600

//--------------------------------------------------
// Definitions of HID bytes
//--------------------------------------------------
#define _HID_COMMAND                                            0x00
#define _HID_REVERSE                                            0x01
#define _HID_REVERSE1                                            0x02
#define _HID_VALUE3                                            0x03
#define _HID_VALUE2                                            0x04
#define _HID_VALUE1                                            0x05
#define _HID_VALUE0                                            0x06
#define _HID_CKS                                                    0x07

//--------------------------------------------------
// Definitions of HID commands
//--------------------------------------------------

#define _USB_READ_RECORD_COUNTER                        0x00
#define _USB_READ_RECORD                                         0x01
#define _USB_SET_CHANNLE_NUMBER                            0x02
#define _USB_SET_SAMPLE_FREQ                                    0x03
#define _USB_DFU_MODE                                               0x04
#define _USB_DFU_TIME                                               0x05

//--------------------------------------------------
// Definitions of picture index
//--------------------------------------------------
#define _PIC_OPTION                                              11
#define _PIC_OPTION_UNSEL                                              12
#define _PIC_OPTION_SEL                                              13
#define _PIC_WHITE                                                  14
#define _PIC_SECOND                                                 16
#define _PIC_SECOND_UNSEL                                      17
#define _PIC_SECOND_SEL                                      18
#define _PIC_THIRD_UNSEL                                                23
#define _PIC_THIRD_SEL                                                24

//--------------------------------------------------
// Definitions of picture index
//--------------------------------------------------
#define _PIC_LOGO_1                                                      1//(1-10)
#define _PIC_L1_UNSEL                                              11
#define _PIC_L1_ODD                                              12
#define _PIC_L1_EVEN                                              13
#define _PIC_L1_BOTTOM_C                                           11
#define _PIC_L1_BOTTOM_E                                            12
#define _PIC_L1_TOP1                                                    14
#define _PIC_L1_TOP2                                                    15
#define _PIC_L2_UNSEL                                             16
#define _PIC_L2_SEL                                                 17
#define _PIC_L2_BOTTOM_C                                           16
#define _PIC_L2_BOTTOM_E                                            17
#define _PIC_L2_OPTION1_UNSEL                                                18
#define _PIC_L2_OPTION2_UNSEL                                                19
#define _PIC_L2_OPTION1_SEL                                                20
#define _PIC_L2_OPTION2_SEL                                               21
#define _PIC_L2_ONOFF_UNSEL                                                    19
#define _PIC_L2_ONOFF_SEL                                                        21
#define _PIC_MAIN_MEASURE                                                22
#define _PIC_MAIN_STD_VERIFY                                                23
#define _PIC_MAIN_DATA                                               24
#define _PIC_MAIN_BOTTOM_C                                           22
#define _PIC_MAIN_BOTTOM_E                                            23
#define _PIC_MAIN_TOP                                                       25
#define _PIC_ENERGY                                                           25
#define _PIC_TIPS                                                                26
#define _PIC_MEASURE                                                        27
#define _PIC_STD_VERIFY                                                   28
#define _PIC_BOTTOM_NONE_C                                               27
#define _PIC_BOTTOM_NONE_E                                               28
#define _PIC_L3_UNSEL                                                           29
#define _PIC_L3_SEL                                                                30
#define _PIC_L3_DT_UNSEL                                                     31
#define _PIC_L3_DT_SEL                                                         32
#define _PIC_L3_BK_UNSEL                                                     33
#define _PIC_L3_BK_SEL                                                          34
#define _PIC_L3_AP_UNSEL                                                     33
#define _PIC_L3_AP_SEL                                                          34
#define _PIC_L2_TOP_SAMPLE_ID                                              35
#define _PIC_L2_TOP_OPERATOR_ID                                              36
#define _PIC_L2_TOP_DT                                                          37
#define _PIC_L2_TOP_READ_OPTION                                       35
#define _PIC_L2_TOP_POWER_MANAGE                                       36
#define _PIC_L2_TOP_PASSWORD                                         37
#define _PIC_L2_TOP_AUDIO                                                 38
#define _PIC_L2_TOP_VERIFY_PASSWORD                                         38
#define _PIC_L2_TOP_WAITING_TIME                                38
#define _PIC_DATA_OPTION_UNSEL                                          39
#define _PIC_DATA_OPTION_SEL                                          40
#define _PIC_ADVANCED_L2_UNSEL                              39
#define _PIC_ADVANCED_L2_SEL                              40
#define _PIC_ARROW                                                              41
#define _PIC_ADVANCED_L3_UNSEL                                       42
#define _PIC_ADVANCED_L3_SEL                                       43
#define _PIC_ADVANCED_TOP1                                              44
//--------------------------------------------------
// Definitions of number of second
//--------------------------------------------------
#define _OPTION0_SECOND_NUM                                              3
#define _OPTION1_SECOND_NUM                                              3
#define _OPTION2_SECOND_NUM                                              3
#define _OPTION3_SECOND_NUM                                              2
#define _OPTION4_SECOND_NUM                                              2
#define _OPTION5_SECOND_NUM                                              3
#define _OPTION6_SECOND_NUM                                              2
#define _OPTION7_SECOND_NUM                                              2
#define _OPTION8_SECOND_NUM                                              0
#define _OPTION9_SECOND_NUM                                              0

//--------------------------------------------------
// Definitions of number of third
//--------------------------------------------------
#define _DT_FORMAT_THIRD_NUM                                              6
#define _BACKLIGHT_THIRD_NUM                                              6
#define _AUTOPOWER_THIRD_NUM                                              6

//--------------------------------------------------
// Definitions of layer 1
//--------------------------------------------------
#define _L1_SAMPLE_ID                                                             0
#define _L1_OPERATOR_ID                                                         1
#define _L1_DT                                                                           2
#define _L1_READ_OPTION                                                         3
#define _L1_POWER_MANAGE                                                     4
#define _L1_AUDIO                                                                     5
#define _L1_SECURITY                                                                6
#define _L1_LANGUAGE                                                               7
#define _L1_INFOMATION                                                            8
#define _L1_RESET                                                                       9

//--------------------------------------------------
// Definitions of length of string index
//--------------------------------------------------
#define _LENGTH_SECOND                                                           0
#define _LENGTH_SECONDs                                                         1
#define _LENGTH_10_SECONDs                                                   2
#define _LENGTH_20__SECONDs                                                 3
#define _LENGTH_30__SECONDs                                                 4
#define _LENGTH_1_MINUTE                                                       5
#define _LENGTH_2_MINUTES                                                     6
#define _LENGTH_5_MINUTES                                                     7
#define _LENGTH_10_MINUTES                                                   8
#define _LENGTH_30_MINUTES                                                   9
#define _LENGTH_1_HOUR                                                           10

//--------------------------------------------------
// Definitions of unit
//--------------------------------------------------
#define _UNIT_SECOND                                                                0
#define _UNIT_TIMES                                                                  1

//--------------------------------------------------
// Definitions of reading time
//--------------------------------------------------
#define _MIN_READING_TIME                                                                0
#define _MAX_READING_TIME                                                                30

//--------------------------------------------------
// Definitions of read times
//--------------------------------------------------
#define _MIN_READ_TIMES                                                                1
#define _MAX_READ_TIMES                                                                  60

//--------------------------------------------------
// Definitions of waitting time
//--------------------------------------------------
#define _MIN_WAITTING_TIME                                                                0
#define _MAX_WAITTING_TIME                                                                  30
//**********************end of file**************************//


