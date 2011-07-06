// SettingsDialog2.cpp : implementation file
//

#include "stdafx.h"
#include "MyMaxVisualisation.h"
#include "SettingsDialog2.h"


// SettingsDialog2 dialog

IMPLEMENT_DYNAMIC(SettingsDialog2, CDialog)

SettingsDialog2::SettingsDialog2(CWnd* pParent /*=NULL*/)
	: CDialog(SettingsDialog2::IDD, pParent)
{

}

SettingsDialog2::~SettingsDialog2()
{
}

void SettingsDialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1);
}


BEGIN_MESSAGE_MAP(SettingsDialog2, CDialog)
	ON_EN_CHANGE(IDC_EDIT1, &SettingsDialog2::OnEnChangeEdit1)
END_MESSAGE_MAP()


// SettingsDialog2 message handlers

void SettingsDialog2::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
