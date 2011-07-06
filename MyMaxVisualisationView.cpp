// MyMaxVisualisationView.cpp : implementation of the CMyMaxVisualisationView class
//

#include "stdafx.h"
#include "MyMaxVisualisation.h"

#include "MyMaxVisualisationDoc.h"
#include "MyMaxVisualisationView.h"

#include "DialogFinal.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyMaxVisualisationView

IMPLEMENT_DYNCREATE(CMyMaxVisualisationView, CView)

BEGIN_MESSAGE_MAP(CMyMaxVisualisationView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_SETTINGS, &CMyMaxVisualisationView::OnSettings)
END_MESSAGE_MAP()

// CMyMaxVisualisationView construction/destruction

CMyMaxVisualisationView::CMyMaxVisualisationView():
max_value(0),
min_value(0),
draw_traject(false),
draw_point(false)
{
	// TODO: add construction code here
}


CMyMaxVisualisationView::~CMyMaxVisualisationView()
{
}

BOOL CMyMaxVisualisationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMyMaxVisualisationView drawing




// CMyMaxVisualisationView printing

BOOL CMyMaxVisualisationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyMaxVisualisationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyMaxVisualisationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMyMaxVisualisationView diagnostics

#ifdef _DEBUG
void CMyMaxVisualisationView::AssertValid() const
{
	CView::AssertValid();
}

void CMyMaxVisualisationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyMaxVisualisationDoc* CMyMaxVisualisationView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyMaxVisualisationDoc)));
	return (CMyMaxVisualisationDoc*)m_pDocument;
}
#endif //_DEBUG

void CMyMaxVisualisationView::DrawAxis(CDC* pDC){

	CMyMaxVisualisationDoc* pDoc = GetDocument();

	CRect rc;
	GetClientRect(&rc);

	double x_coord = (pDoc-> p_area -> my_area[1] - pDoc-> p_area -> my_area[0]) / 10;
	double y_coord = (pDoc-> p_area -> my_area[3] - pDoc-> p_area -> my_area[2]) / 10;

	CPen pen;
	CPen * pOldPen;
	pen.CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	pOldPen = pDC -> SelectObject(&pen);
	
	int width = rc.Width() - 150;
	int height = rc.Height() - 150;
	
	pDC->MoveTo(75, 50);
	pDC->LineTo(75, height + 50);
	pDC->LineTo(width + 75, height + 50);
	
	char axis_legend[100];
	for (int i = 0; i <= 10; ++i)
	{
		pDC->MoveTo(75 + i*width/10, height + 45);
		pDC->LineTo(75 + i*width/10, height + 55);
		sprintf(axis_legend, "%4.2f", pDoc->p_area->my_area[0] + i*x_coord);
		pDC->TextOut(55 + i*width/10, height + 60, CString(axis_legend));
	}

	for (int i = 0; i <= 10; ++i)
	{
		pDC->MoveTo(70, 50 + i*height/10);
		pDC->LineTo(80, 50 + i*height/10);
		sprintf(axis_legend, "%4.2f", pDoc->p_area->my_area[2] + (10 - i)*y_coord);
		pDC->TextOut(35, 40 + i*height/10, CString(axis_legend));
	}

	pDC->SelectObject(pOldPen);
	pen.DeleteObject();

}



vector<int> CMyMaxVisualisationView::TransformToPix(vector<double> v)
{
	CMyMaxVisualisationDoc* pDoc = GetDocument();
	CRect rc;
	GetClientRect(&rc);

	vector <int> res(2);
	res[0] = (75 + (v[0] - pDoc->p_area->my_area[0])/(pDoc->p_area->my_area[1] - pDoc->p_area->my_area[0])*(rc.Width() - 150));
	res[1] = (rc.Height()-100 - (v[1]-pDoc->p_area->my_area[2])/(pDoc->p_area->my_area[3]-pDoc->p_area->my_area[2])*(rc.Height()-150));
	return res;
}


vector<double> CMyMaxVisualisationView::TransformToPoint(vector<int> v)
{
	CMyMaxVisualisationDoc* pDoc = GetDocument();
	CRect rc;
	GetClientRect(&rc);
	vector <double> res(2);
	res[0] = (pDoc->p_area->my_area[0]+(v[0]-75)/(rc.Width() - 150)*(pDoc->p_area->my_area[1] - pDoc->p_area->my_area[0]));
	res[1] = (pDoc->p_area->my_area[2]+(rc.Height()-100-v[1])/(rc.Height()-150)*(pDoc->p_area->my_area[3] - pDoc->p_area->my_area[2]));
	return res;
}


int CMyMaxVisualisationView::TransformToPixX(double x)
{
	CMyMaxVisualisationDoc* pDoc = GetDocument();
	CRect rc;
	GetClientRect(&rc);

	return 75 + (x - pDoc->p_area->my_area[0])/(pDoc->p_area->my_area[1] - pDoc->p_area->my_area[0])*(rc.Width() - 150);
}


int CMyMaxVisualisationView::TransformToPixY(double y)
{
	CMyMaxVisualisationDoc* pDoc = GetDocument();
	CRect rc;
	GetClientRect(&rc);

	return rc.Height()- 100 -(y - pDoc->p_area->my_area[2]) / (pDoc->p_area->my_area[3]-pDoc->p_area->my_area[2])*(rc.Height() - 150);
}


double CMyMaxVisualisationView::TransformToPointX(double x)
{
	CMyMaxVisualisationDoc* pDoc = GetDocument();
	CRect rc;
	GetClientRect(&rc);

	return pDoc->p_area->my_area[0]+(double)(x-75)/(rc.Width() - 150)*(pDoc->p_area->my_area[1] - pDoc->p_area->my_area[0]);
	
}

double CMyMaxVisualisationView::TransformToPointY(double y)
{
	CMyMaxVisualisationDoc* pDoc = GetDocument();
	CRect rc;
	GetClientRect(&rc);

	return pDoc->p_area->my_area[2]+(double)(rc.Height()-100-y)/(rc.Height()-150)*(pDoc->p_area->my_area[3] - pDoc->p_area->my_area[2]);
}



void CMyMaxVisualisationView::DrawMap(CDC* pDC)
{

		CMyMaxVisualisationDoc* pDoc = GetDocument(); 
		
		CRect rc;
		GetClientRect(&rc);

		int width = rc.Width() - 150;
		int heigth = rc.Height() - 150;
		double cur_value;
		cur_value = (*(pDoc->p_func))(TransformToPointX(75), TransformToPointY(heigth + 50));
		min_value = cur_value;  
		max_value = cur_value;  
		double x, y, color;
		for (int i = 76; i < width + 75; i = i + 5)
		{
			for(int j = heigth + 50; j > 50; j = j - 5)
			{
				x = TransformToPointX(i);
				y = TransformToPointY(j);
				cur_value = (*(pDoc->p_func))(x,y);
				if (cur_value > max_value) max_value = cur_value;
				if (cur_value < min_value) min_value = cur_value;
			}
		}
		
		CDC map;
		CBitmap bit;  
		bit.CreateCompatibleBitmap(pDC, width, heigth);
		map.CreateCompatibleDC(pDC);
		map.SelectObject(&bit); 


		for (int i = 0; i < width; ++i)
		{
			for(int j = 0; j < heigth; ++j)
			{
				x = TransformToPointX(i + 75);
				y = TransformToPointY(heigth + 50 - j);
				cur_value = (*(pDoc->p_func))(x,y);
				color = (cur_value - min_value)/(max_value - min_value) * 150;
				map.SetPixel(i, heigth - j, RGB(0, color, 100));
			}
		}

		pDC->BitBlt(75, 50, width, heigth, &map, 0, 0, SRCCOPY);	
}

void CMyMaxVisualisationView::DrawTrajectory(CDC* pDC)
{
	CMyMaxVisualisationDoc* pDoc = GetDocument();
	
	if (draw_traject == 1) {
		CRect rc;
		GetClientRect(&rc);
		CPen pen;
		CPen * pOldPen;
		pen.CreatePen(PS_SOLID, 1, RGB(150,150,200));
		pOldPen = pDC->SelectObject(&pen);


		vector <vector<double>> temp = pDoc->method_result.my_trajectory;
		vector <vector <double>>::iterator iter = temp.begin();
		
		int x = TransformToPixX(temp[0][0]);
		int y = TransformToPixY(temp[0][1]);
		pDC->MoveTo(x, y);
		pDC->Rectangle(x - 3, y - 3, x + 3, y + 3);
		++iter;
		for (int i = 0; i < temp.size(); ++i)
		{
			x = TransformToPixX(temp[i][0]);
			y = TransformToPixY(temp[i][1]);
			pDC->LineTo(x, y);
			pDC->Rectangle(x - 2, y - 2, x + 2, y + 2);		
		}

		pDC->SelectObject(pOldPen);
		pen.DeleteObject();

		CBrush brush;
		CBrush * pOldBrush;
		brush.CreateSolidBrush(RGB(255, 255, 0));
		pOldBrush = pDC->SelectObject(&brush);

		pDC->Ellipse(x - 6, y - 6, x + 6, y + 6);
		
		pDC->SelectObject(pOldBrush);
		brush.DeleteObject();
	}
}


// CMyMaxVisualisationView message handlers

void CMyMaxVisualisationView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMyMaxVisualisationDoc* pDoc = GetDocument();
	CRect rc;
	GetClientRect(&rc);

	int width = rc.Width() - 150;
	int height = rc.Height() - 150;
	
	if (point.x >= 75 && point.x <= 75 + width && point.y >= 50 && point.y <= height + 50)
	{
		
		double x = TransformToPointX(point.x);
		double y = TransformToPointY(point.y);
		
		vector<double> current_point;
		current_point.push_back(x);
		current_point.push_back(y);

		clicks.push_back(current_point);

		if (clicks.size() == pDoc -> p_current_method ->numb_of_start_points()) {
			MethodResult result = pDoc -> p_current_method -> search_process(pDoc->p_func, pDoc->p_area, clicks);
			pDoc -> method_result = result;
			draw_traject = 1;
			draw_point = 0;

			clicks.clear();
		} else {
			draw_point = 1;
			draw_traject = 0;
		}
	}
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}

void CMyMaxVisualisationView::DrawPoint(CDC* pDC ) {
	CPen pen;
	CPen * pOldPen;
	pen.CreatePen(PS_SOLID, 1, RGB(150,150,200));
	pOldPen = pDC->SelectObject(&pen);

	vector<int> point = TransformToPix(clicks[0]);
	pDC->Rectangle(point[0] - 3, point[1] - 3, point[0] + 3, point[1] + 3);
			
	pDC->SelectObject(pOldPen);
	pen.DeleteObject();
}


void CMyMaxVisualisationView::WriteFuncAndMethodNames(CDC* pDC)
{
	CMyMaxVisualisationDoc* pDoc = GetDocument();
	
	CRect rc;
	GetClientRect(&rc);
	CPen pen;
	CPen * pOldPen;
	pen.CreatePen(PS_SOLID, 1, RGB(0,0,0));
	pOldPen = pDC->SelectObject(&pen);

	int width = rc.Width() - 150;
	int height = rc.Height() - 150;
	
	char inscr[100];
	double start_value;
	sprintf(inscr, "Function:  %s", pDoc->p_func->get_formula().c_str());
	pDC->TextOut(400, 25, CString(inscr));
	int t = height + 80;
	sprintf(inscr, "Search Metod: %s", pDoc->p_current_method->get_method_name().c_str());
	pDC->TextOut(80, t, CString(inscr));

	pDC->SelectObject(pOldPen);
	pen.DeleteObject();

};

//выводим результат

void CMyMaxVisualisationView::WriteResult(CDC* pDC) {
	if (draw_traject == 1) {
	
		CMyMaxVisualisationDoc* pDoc = GetDocument();
		CRect rc;
		GetClientRect(&rc);
		CPen pen;
		CPen * pOldPen;
		pen.CreatePen(PS_SOLID, 1, RGB(0,0,0));
		pOldPen = pDC->SelectObject(&pen);
		
		int height = rc.Height() - 150;
		int t = height + 80;
		char inscr[255];
	
		for (int i = 0; i < pDoc->p_current_method->numb_of_start_points(); ++i) {
			double start_value = (*(pDoc->p_func))(pDoc->method_result.my_trajectory[i][0], pDoc->method_result.my_trajectory[i][1]);
			sprintf(inscr, "Start Point %d:  (%f, %f)       Start Value %d:  %f", i+1, pDoc->method_result.my_trajectory[i][0], pDoc->method_result.my_trajectory[i][1], i+1, start_value);
			pDC->TextOut(80, t + 15 + 15*i,CString(inscr));
		}
		
		vector <vector<double>> temp = pDoc->method_result.my_trajectory;

		double final_x = temp[temp.size()-1][0];
		double final_y = temp[temp.size()-1][1];

		double cur_value = (*(pDoc->p_func))(final_x, final_y);
		sprintf(inscr, "Final Point:  (%f, %f)       Final Value:  %f", final_x, final_y, cur_value);
		t = rc.Height() - 25;

		pDC->TextOut(80, t, CString(inscr));
		

		sprintf(inscr, "Reason of stop:  %s", pDoc->method_result.reason_of_stop.c_str());
		pDC->TextOut(550, t, CString(inscr));

		
		sprintf(inscr, "Steps made:  %d", pDoc->method_result.my_trajectory.size());
		pDC->TextOut(550, t - 30, CString(inscr));

		pDC->SelectObject(pOldPen);
		pen.DeleteObject();
	}
}

void CMyMaxVisualisationView::OnDraw(CDC* pDC)
{
	CMyMaxVisualisationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	DrawAxis(pDC);
	WriteFuncAndMethodNames(pDC);
	DrawMap(pDC);
	if (draw_point) {
		DrawPoint(pDC);
	}
	DrawTrajectory(pDC);
	WriteResult(pDC);
}

void CMyMaxVisualisationView::OnSettings()
{
	vector<double> second_point;

	DialogFinal dial;
	CMyMaxVisualisationDoc* pDoc = GetDocument();
	
	dial.m_min_x = pDoc -> p_area->my_area[0];
	dial.m_max_x = pDoc -> p_area->my_area[1];
	dial.m_min_y = pDoc -> p_area->my_area[2];
	dial.m_max_y = pDoc -> p_area->my_area[3];

	dial.m_func = pDoc-> f_type;
	dial.m_meth = pDoc -> method_type;

	dial.m_steps = pDoc -> p_random_method -> get_steps();

	// random
	dial.m_rand_eps = pDoc -> p_random_method -> get_epsilon();
	dial.m_p = pDoc-> p_random_method -> get_p();
	dial.m_fail_steps = pDoc -> p_random_method -> get_fail_steps();

	// gorge
	dial.m_eps_point_change = pDoc -> p_gorge_method -> get_eps_point_change();

	dial.m_start_x = 0;
	dial.m_start_y = 0;
	dial.m_x_second_start_point = 0.1;
	dial.m_y_second_start_point = 0.1;

	if (draw_traject) {
		dial.m_start_x = pDoc->method_result.my_trajectory[0][0];
		dial.m_start_y = pDoc->method_result.my_trajectory[0][1];

		if (pDoc->method_type == 1) {
			dial.m_x_second_start_point = pDoc->method_result.my_trajectory[1][0];
			dial.m_y_second_start_point = pDoc->method_result.my_trajectory[1][1];
		}
	} else {
		if (clicks.size() == 1) {
			dial.m_start_x = clicks[0][0];
			dial.m_start_y = clicks[0][1];
		}
	}
	
	if (dial.DoModal() == IDOK)
	{
		pDoc -> p_area->my_area.clear();
		pDoc -> p_area->my_area.push_back(dial.m_min_x);
		pDoc -> p_area->my_area.push_back(dial.m_max_x);
		pDoc -> p_area->my_area.push_back(dial.m_min_y);
		pDoc -> p_area->my_area.push_back(dial.m_max_y);
		
		pDoc -> f_type = dial.m_func;
		pDoc -> method_type = dial.m_meth;

		// Полиморфизм
		if (pDoc->method_type == 0) {
			pDoc->p_current_method = pDoc->p_random_method;	
		} else {
			pDoc->p_current_method = pDoc->p_gorge_method;
		}

		// random
		pDoc -> p_random_method -> set_steps(dial.m_steps);
		pDoc -> p_random_method -> set_epsilon(dial.m_rand_eps);
		pDoc -> p_random_method -> set_p(dial.m_p);
		pDoc -> p_random_method -> set_fail_steps(dial.m_fail_steps);

		// gorge
		pDoc -> p_gorge_method -> set_numb_of_steps(dial.m_steps);
		pDoc -> p_gorge_method -> set_eps_point_change(dial.m_eps_point_change);
		
		switch (pDoc -> f_type)
		{
		case 0: 
			{
				delete pDoc -> p_func;
				pDoc -> p_func = new Function_1(); 
				break;
			}
		case 1: 
			{
				delete pDoc -> p_func;
				pDoc -> p_func = new Function_2(); 
				break;
			}
		case 2: 
			{
				delete pDoc -> p_func;
				pDoc -> p_func = new Function_3(); 
				break;
			}
		case 3: 
			{
				delete pDoc -> p_func;
				pDoc -> p_func = new Function_4(); 
				break;
			}
		}

		vector<double> first_start_point;
		first_start_point.push_back(dial.m_start_x);
		first_start_point.push_back(dial.m_start_y);

		vector<double> second_start_point;
		second_start_point.push_back(dial.m_x_second_start_point);
		second_start_point.push_back(dial.m_y_second_start_point);
		
		vector<vector<double>> start_points;
		start_points.push_back(first_start_point);
		start_points.push_back(second_start_point);
		
		pDoc->method_result = pDoc->p_current_method->search_process(pDoc->p_func, pDoc->p_area, start_points);

		draw_traject = 1;
		draw_point = 0;

		clicks.clear();
		
		Invalidate();
	} 	
}
