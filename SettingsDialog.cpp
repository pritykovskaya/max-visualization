// SettingsDialog.cpp : implementation file
//

#include "stdafx.h"
#include "MyMaxVisualisation.h"
#include "SettingsDialog.h"


// SettingsDialog dialog

IMPLEMENT_DYNAMIC(SettingsDialog, CDialog)

SettingsDialog::SettingsDialog(CWnd* pParent /*=NULL*/)
	: CDialog(SettingsDialog::IDD, pParent)
{

}

SettingsDialog::~SettingsDialog()
{
}

void SettingsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SettingsDialog, CDialog)
END_MESSAGE_MAP()


// SettingsDialog message handlers
