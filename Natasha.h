
#pragma once


// Natasha dialog

class Natasha : public CDialog
{
	DECLARE_DYNAMIC(Natasha)

public:
	Natasha(CWnd* pParent = NULL);   // standard constructor
	virtual ~Natasha();

// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
