; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLB_DumpDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "LB_Dump.h"

ClassCount=4
Class1=CLB_DumpApp
Class2=CLB_DumpDlg

ResourceCount=4
Resource2=IDR_MAINFRAME
Resource3=IDD_LB_DUMP_DIALOG
Resource4=IDD_LB_DUMP_DIALOG (English (U.S.))

[CLS:CLB_DumpApp]
Type=0
HeaderFile=LB_Dump.h
ImplementationFile=LB_Dump.cpp
Filter=N

[CLS:CLB_DumpDlg]
Type=0
HeaderFile=LB_DumpDlg.h
ImplementationFile=LB_DumpDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_LB_DUMP_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CLB_DumpDlg

[DLG:IDD_LB_DUMP_DIALOG (English (U.S.))]
Type=1
Class=?
ControlCount=3
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDT_FILENAME,edit,1350631552
Control3=IDC_BTN_DUMP,button,1342242817

