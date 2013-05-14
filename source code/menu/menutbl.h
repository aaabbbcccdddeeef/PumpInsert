/******************************************************************************/
/* menutbl.h:                                      */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2009 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/
#define edit_line                       _BIT0
#define input_num_button                _BIT1
#define input_func_button               _BIT2
#define menu_level_1                    _BIT3
#define menu_level_2                    _BIT4
#define menu_level_4                    _BIT5
#define edit_line_min                       _BIT6

#define CurrentMenu		tblMenus[MenuPageIndex]
#define PrevMenuPage		CurrentMenu.PrevPage
#define CurrentMenuItems	CurrentMenu.MenuItems
#define MenuItemCount		CurrentMenu.ItemCount
#define CurrentMenuLevel        CurrentMenu.PageLevel

#define CurrentMenuItem		CurrentMenu.MenuItems[MenuItemIndex]
#define NextMenuPage		CurrentMenuItem.NextPage

#define TempMenu		tblMenus[TempPageIndex]
#define TempMenuItems	TempMenu.MenuItems
#define TempMenuItem		TempMenu.MenuItems[TempItemIndex]


#ifdef __MENUTBL__
MenuItemType MainMenuItems[];
MenuItemType SampleTestMenuItems[];
MenuItemType PoleCleanMenuItems[];
MenuPageType tblMenus[];
#else
extern MenuItemType MainMenuItems[];
extern MenuItemType SampleTestMenuItems[];
extern MenuItemType PoleCleanMenuItems[];
extern MenuPageType tblMenus[];
#endif





//*******************************END OF LINE***********************************//

