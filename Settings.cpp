// Settings.cpp : implementation file
//

#include "stdafx.h"
#include "MyMaxVisualisation.h"
#include "Settings.h"


// Settings dialog

IMPLEMENT_DYNAMIC(Settings, CDialog)

Settings::Settings(CWnd* pParent /*=NULL*/)
	: CDialog(Settings::IDD, pParent)
{

}

Settings::~Settings()
{
}

void Settings::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Settings, CDialog)
END_MESSAGE_MAP()


// Settings message handlers
