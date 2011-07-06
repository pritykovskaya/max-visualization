// DialogFinal.cpp : implementation file
//

#include "stdafx.h"
#include "MyMaxVisualisation.h"
#include "DialogFinal.h"


// DialogFinal dialog

IMPLEMENT_DYNAMIC(DialogFinal, CDialog)

DialogFinal::DialogFinal(CWnd* pParent /*=NULL*/)
	: CDialog(DialogFinal::IDD, pParent)
	, m_min_x(0)
	, m_max_x(0)
	, m_min_y(0)
	, m_max_y(0)
	, m_func(0)
	, m_meth(0)
	, m_steps(0)
	, m_start_x(0)
	, m_start_y(0)
	, m_rand_eps(0)
	, m_p(0)
	, m_fail_steps(0)
	, m_eps_point_change(0)
	, m_x_second_start_point(0)
	, m_y_second_start_point(0)
{

}

DialogFinal::~DialogFinal()
{
}

void DialogFinal::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_min_x);
	DDX_Text(pDX, IDC_EDIT2, m_max_x);
	DDX_Text(pDX, IDC_EDIT3, m_min_y);
	DDX_Text(pDX, IDC_EDIT4, m_max_y);
	DDX_CBIndex(pDX, IDC_COMBO1, m_func);
	DDV_MinMaxInt(pDX, m_func, 0, 3);
	DDX_Radio(pDX, IDC_RADIO1, m_meth);
	DDV_MinMaxInt(pDX, m_meth, 0, 1);
	DDX_Text(pDX, IDC_EDIT6, m_steps);
	DDV_MinMaxDouble(pDX, m_steps, 0, 100000);
	DDX_Text(pDX, IDC_EDIT8, m_start_x);
	DDX_Text(pDX, IDC_EDIT9, m_start_y);
	DDX_Text(pDX, IDC_EDIT11, m_rand_eps);
	DDV_MinMaxDouble(pDX, m_rand_eps, 0, 1);
	DDX_Text(pDX, IDC_EDIT12, m_p);
	DDV_MinMaxDouble(pDX, m_p, 0, 1);
	DDX_Text(pDX, IDC_EDIT13, m_fail_steps);
	DDV_MinMaxInt(pDX, m_fail_steps, 0, 1000);
	DDX_Text(pDX, IDC_EDIT14, m_eps_point_change);
	DDV_MinMaxDouble(pDX, m_eps_point_change, 0, 1);
	DDX_Text(pDX, IDC_EDIT5, m_x_second_start_point);
	DDX_Text(pDX, IDC_EDIT10, m_y_second_start_point);
	DDX_Control(pDX, IDC_EDIT11, control_rand_eps);
	DDX_Control(pDX, IDC_EDIT12, control_p);
	DDX_Control(pDX, IDC_EDIT13, control_fail_steps);
	DDX_Control(pDX, IDC_EDIT14, control_gorge_eps);
	DDX_Control(pDX, IDC_EDIT5, control_gorge_x);
	DDX_Control(pDX, IDC_EDIT10, control_gorge_y);
}


BEGIN_MESSAGE_MAP(DialogFinal, CDialog)
	ON_EN_CHANGE(IDC_EDIT1, &DialogFinal::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_RADIO1, &DialogFinal::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &DialogFinal::OnBnClickedRadio2)
	ON_EN_CHANGE(IDC_EDIT9, &DialogFinal::OnEnChangeEdit9)
	ON_EN_CHANGE(IDC_EDIT10, &DialogFinal::OnEnChangeEdit10)
	ON_EN_CHANGE(IDC_EDIT11, &DialogFinal::OnEnChangeEdit11)
	ON_CBN_SELCHANGE(IDC_COMBO1, &DialogFinal::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// DialogFinal message handlers

void DialogFinal::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void DialogFinal::OnBnClickedRadio1()
{
	
	m_meth = 0;// TODO: Add your control notification handler code here
	control_gorge_eps.EnableWindow(0);
	control_gorge_x.EnableWindow(0);
	control_gorge_y.EnableWindow(0);
	control_fail_steps.EnableWindow(1);
	control_p.EnableWindow(1);
	control_rand_eps.EnableWindow(1);
}

void DialogFinal::OnBnClickedRadio2()
{
	m_meth = 1;	// TODO: Add your control notification handler code here
	control_gorge_eps.EnableWindow(1);
	control_gorge_x.EnableWindow(1);
	control_gorge_y.EnableWindow(1);
	control_fail_steps.EnableWindow(0);
	control_p.EnableWindow(0);
	control_rand_eps.EnableWindow(0);
}

void DialogFinal::OnEnChangeEdit9()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void DialogFinal::OnEnChangeEdit10()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void DialogFinal::OnEnChangeEdit11()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void DialogFinal::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
}
