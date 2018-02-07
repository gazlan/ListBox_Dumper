// LB_DumpDlg.h : header file
//

#if !defined(AFX_LB_DUMPDLG_H__FF524BC4_BABF_47A1_B34D_E62DB3FAAF11__INCLUDED_)
#define AFX_LB_DUMPDLG_H__FF524BC4_BABF_47A1_B34D_E62DB3FAAF11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLB_DumpDlg dialog

class CLB_DumpDlg : public CDialog
{
// Construction
public:
	CLB_DumpDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLB_DumpDlg)
	enum { IDD = IDD_LB_DUMP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLB_DumpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLB_DumpDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnChangeEdtHandle();
	afx_msg void OnChangeEdtFilename();
	afx_msg void OnBtnDump();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LB_DUMPDLG_H__FF524BC4_BABF_47A1_B34D_E62DB3FAAF11__INCLUDED_)
