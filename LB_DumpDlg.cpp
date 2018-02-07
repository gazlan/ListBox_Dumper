#include "stdafx.h"

#include "LB_Dump.h"
#include "LB_DumpDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

static HWND    hForm = NULL;
static HWND    hLB   = NULL;

CLB_DumpDlg::CLB_DumpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLB_DumpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLB_DumpDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLB_DumpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLB_DumpDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLB_DumpDlg, CDialog)
	//{{AFX_MSG_MAP(CLB_DumpDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDT_HANDLE, OnChangeEdtHandle)
	ON_EN_CHANGE(IDC_EDT_FILENAME, OnChangeEdtFilename)
	ON_BN_CLICKED(IDC_BTN_DUMP, OnBtnDump)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CLB_DumpDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLB_DumpDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLB_DumpDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

/* ******************************************************************** **
** @@ MainEnum()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

BOOL CALLBACK MainEnum
(
   HWND     hWnd,       // handle to child window
   LPARAM   lDummy      // application-defined value
)
{
   char     pszBuf[MAX_PATH + 1];

   if (!GetClassName
   (
      hWnd,                // handle of window
      pszBuf,              // address of buffer for class name
      sizeof(pszBuf)       // size of buffer, in characters
   ))
   return TRUE;

   if (!strcmp(pszBuf,"TLB"))
   {
      hLB = hWnd;
   }

   return TRUE;
}

/* ******************************************************************** **
** @@ DesktopEnum()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

BOOL CALLBACK DesktopEnum
(
   HWND     hWnd,       // handle to parent window
   LPARAM   lDummy      // application-defined value
)
{
   char     pszBuf[MAX_PATH + 1];

   if (!GetClassName
   (
      hWnd,                // handle of window
      pszBuf,              // address of buffer for class name
      sizeof(pszBuf)       // size of buffer, in characters
   ))
   return TRUE;

   if (!strcmp(pszBuf,"TForm1"))
   {
         hForm = hWnd;
   }      

   return TRUE;
}

void CLB_DumpDlg::OnChangeEdtHandle() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
}

void CLB_DumpDlg::OnChangeEdtFilename() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
}

void CLB_DumpDlg::OnBtnDump() 
{
   CString     sFileName = _T("");

   GetDlgItemText(IDC_EDT_FILENAME,sFileName);

   if (!EnumDesktopWindows(NULL,(WNDENUMPROC)DesktopEnum,NULL))
   {
      return;
   }

   if (!hForm)
   {
      return;
   }

   if (!EnumChildWindows(hForm,(WNDENUMPROC)MainEnum,NULL))
   {
      return;
   }

   if (!hLB)
   {
      return;
   }

   int   iCnt = ::SendMessage(hLB,LB_GETCOUNT,(WPARAM)0,(LPARAM)0); 

   if (iCnt == LB_ERR)
   {
      return;
   }

   char     pszBuf[USHRT_MAX];

   FILE*    pFile = fopen((LPCTSTR)sFileName,"at+");

   for (int ii = 0; ii < iCnt; ++ii)
   {
      ::SendMessage(hLB,LB_GETTEXT,(WPARAM)ii,(LPARAM)pszBuf);  
      fprintf(pFile,"%s\n",pszBuf);
   }

   fclose(pFile);
}
