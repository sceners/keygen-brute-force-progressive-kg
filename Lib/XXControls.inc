comment $
//-----------------------------------------------------------------------------------//
//  Source code                                                                      //
//                                                                                   //
//  Written      by  Chib                            			                     //
//                                                                                   //
//  FileName   : XXControls.inc                                                      //
//  Description: prototypes of functions for work with menu, button                  //
//                                                                                   //
//  email      : XXControls@bk.ru                                                    //
//  website    : http://chib.boom.ru                                                 //
//-----------------------------------------------------------------------------------//
$

;-----------------------------------------------
;-----------------------------------------------
; menu function

RedrawWindowMenu    PROTO :HWND
SetMenuItemIcon     PROTO :HMENU,:DWORD, :HICON
SetStyleMenu        PROTO :DWORD
GetStyleMenu        PROTO
SetDisableSelect    PROTO :BYTE
SetMenuIcon         PROTO :HMENU, :HIMAGELIST, :DWORD, :DWORD
AddLeftBorder       PROTO :HMENU, :DWORD, :BOOLEAN
RemoveLeftBorder    PROTO :HMENU
SetTransparentMenu  PROTO :BYTE

STYLE_DEFAULT       equ 0
STYLE_OFFICE_2000   equ 80000000h
STYLE_OFFICE_XP     equ 40000000h
STYLE_XNET          equ 20000000h


MNUBUTTON STRUCT
  idItem            DWORD      ?
  nIcon             DWORD      ?
MNUBUTTON ENDS

;-----------------------------------------------
;-----------------------------------------------
; button function

RedrawButton      PROTO :HWND, :DWORD

XXBUTTON STRUCT
  hIcon_normal      HICON      ?
  hIcon_hover       HICON      ?
  hBitmap_normal    HBITMAP    ?
  hBitmap_hover     HBITMAP    ?
  hBitmap_push      HBITMAP    ?
  hBitmap_gray      HBITMAP    ?
  hover_clr         COLORREF   ?
  push_clr          COLORREF   ?
  normal_clr        COLORREF   ?
  hFont_normal      HFONT      ?
  hFont_hover       HFONT      ?
  hCursor_hover     HCURSOR    ?
  Sound_hover       HGLOBAL    ?
  hMenu             HMENU      ?
  lpToolTip         LPSTR      ?  
  btn_prop          DWORD      ?
XXBUTTON ENDS

DRAW_BORDER         equ 1h
FLAT_BTN            equ 2h
DRAW_FOCUS          equ 4h
TRANSPARENT_BKGND   equ 8h
RGN_BUTTON          equ 10h
BALLOON_TT          equ 20h
ICON_LEFT           equ 40h
ICON_RIGHT          equ 80h
ICON_TOP            equ 100h
; flag for align menu
MNU_BOTTOM          equ 200h
MNU_BOTTOMRIGHT     equ 400h
MNU_RIGHT           equ 800h
WINXP_THEME_SUPPORT equ 1000h 


;-----------------------------------------------
;-----------------------------------------------
; color function

DarkenColor         PROTO   :DWORD, :COLORREF
GrayColor           PROTO   :COLORREF
MixedColor          PROTO   :COLORREF, :COLORREF
LightenColor        PROTO   :DWORD, :COLORREF
MidColor            PROTO   :COLORREF, :COLORREF
GetXpHighlightColor PROTO
NumColorBits        PROTO
Gradient_Fill       PROTO   :HDC, :DWORD, :COLORREF, :COLORREF, :BOOLEAN
DrawIcnRect         PROTO   :DWORD, :DWORD, :DWORD, :BYTE, :BYTE
DrawDDB             PROTO   :HDC, :DWORD, :HBITMAP, :DWORD
Icon_CopyAsBlend    PROTO   :HDC, :HICON, :BYTE
Transparent_Blt     PROTO   :HDC, :DWORD, :DWORD, :DWORD, :DWORD, :HDC, :DWORD, :DWORD, :DWORD, :DWORD, :UINT

CreateRgnFromBitmap PROTO :HBITMAP
CreateFillBmp       PROTO :DWORD, :DWORD, :DWORD, :BYTE, :BYTE, :COLORREF, :DWORD, :DWORD
FILL_NULL         equ 0
FILL_NOISE        equ 1
FILL_SOFTBUMP     equ 2
FILL_VBUMP        equ 3
FILL_HBUMP        equ 4
FILL_HSHADE       equ 5
FILL_VSHADE       equ 6
FILL_DIAGSHADE    equ 7
FILL_HARDBUMP     equ 8
FILL_METAL        equ 9

RECT_H  equ 0
RECT_V  equ 1

;-----------------------------------------------
;-----------------------------------------------
; XXRichEdit control  function (Print, preview ...)

CreatePreView       PROTO :DWORD,:DWORD
CreatePageSetup     PROTO :HWND
PrintREdit          PROTO :HWND,:HWND
SetStyleMenuXXRichEdit PROTO :DWORD
;Needed if static linking is used only XXRichEdit.lib
UnInitPreView       PROTO

;-----------------------------------------------
;-----------------------------------------------
; Other
SetWindowTransparent PROTO :HWND, :DWORD

IsShellType PROTO
; return value for IsShellType
WIN_NT3     equ 1
WIN_NT4     equ 2
WIN_95      equ 3
WIN_98      equ 4 
WIN_ME      equ 5
WIN_2000    equ 6 
WIN_XP      equ 7
WIN_2003    equ 8