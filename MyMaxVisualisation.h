// MyMaxVisualisation.h : main header file for the MyMaxVisualisation application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMyMaxVisualisationApp:
// See MyMaxVisualisation.cpp for the implementation of this class
//

class CMyMaxVisualisationApp : public CWinApp
{
public:
	CMyMaxVisualisationApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMyMaxVisualisationApp theApp;