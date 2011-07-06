#pragma once
#include "afxwin.h"


// DialogFinal dialog

class DialogFinal : public CDialog
{
	DECLARE_DYNAMIC(DialogFinal)

public:
	DialogFinal(CWnd* pParent = NULL);   // standard constructor
	virtual ~DialogFinal();

// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double m_min_x;
public:
	afx_msg void OnEnChangeEdit1();
public:
	double m_max_x;
public:
	double m_min_y;
public:
	double m_max_y;
public:
	int m_func;
public:
	afx_msg void OnBnClickedRadio1();
public:
	afx_msg void OnBnClickedRadio2();
public:
	int m_meth;
public:
	afx_msg void OnEnChangeEdit9();
public:
	double m_steps;
public:
	double m_start_x;
public:
	double m_start_y;
	
public:
	double m_rand_eps;
public:
	double m_p;
public:
	int m_fail_steps;
public:
	double m_eps_point_change;
public:
	afx_msg void OnEnChangeEdit10();
public:
	double m_x_second_start_point;
public:
	double m_y_second_start_point;
public:
	CEdit control_rand_eps;
public:
	CEdit control_p;
public:
	CEdit control_fail_steps;
public:
	CEdit control_gorge_eps;
public:
	CEdit control_gorge_x;
public:
	CEdit control_gorge_y;
public:
	afx_msg void OnEnChangeEdit11();
public:
	afx_msg void OnCbnSelchangeCombo1();
};
