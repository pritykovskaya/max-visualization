#pragma once


// SettingsDialog2 dialog

class SettingsDialog2 : public CDialog
{
	DECLARE_DYNAMIC(SettingsDialog2)

public:
	SettingsDialog2(CWnd* pParent = NULL);   // standard constructor
	virtual ~SettingsDialog2();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

};
