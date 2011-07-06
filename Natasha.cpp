
/ Natasha.cpp : implementation file
//

#include "stdafx.h"
#include "MyMaxVisualisation.h"
#include "Natasha.h"


// Natasha dialog

IMPLEMENT_DYNAMIC(Natasha, CDialog)

Natasha::Natasha(CWnd* pParent /*=NULL*/)
	: CDialog(Natasha::IDD, pParent)
{

}

Natasha::~Natasha()
{
}

void Natasha::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Natasha, CDialog)
END_MESSAGE_MAP()


// Natasha message handlers
