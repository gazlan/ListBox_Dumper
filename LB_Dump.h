// LB_Dump.h : main header file for the LB_DUMP application
//

#if !defined(AFX_LB_DUMP_H__BA34017E_23BD_4C22_9B67_86126D3CB0FB__INCLUDED_)
#define AFX_LB_DUMP_H__BA34017E_23BD_4C22_9B67_86126D3CB0FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLB_DumpApp:
// See LB_Dump.cpp for the implementation of this class
//

class CLB_DumpApp : public CWinApp
{
public:
	CLB_DumpApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLB_DumpApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLB_DumpApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LB_DUMP_H__BA34017E_23BD_4C22_9B67_86126D3CB0FB__INCLUDED_)
