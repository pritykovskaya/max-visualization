// MyMaxVisualisationView.h : interface of the CMyMaxVisualisationView class
//


#pragma once


class CMyMaxVisualisationView : public CView
{
protected: // create from serialization only
	CMyMaxVisualisationView();
	DECLARE_DYNCREATE(CMyMaxVisualisationView)

// Attributes
public:
	CMyMaxVisualisationDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMyMaxVisualisationView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

public:
	vector <vector <double> > clicks;
public:
	double max_value;
public:
	double min_value;
public:
	void DrawMap(CDC* pDC);
public:
	bool draw_traject;
public:
	bool draw_point;

	
//My functions
public:
	vector<int> TransformToPix(vector <double>);
public:
	vector<double> TransformToPoint(vector<int> v);
public:
	int TransformToPixX(double x);
public:
	int TransformToPixY(double y);
public:
	double TransformToPointX(double x);
public:

	double TransformToPointY(double y);




void DrawAxis(CDC* pDC);


void DrawPoint(CDC* pDC);


void WriteFuncAndMethodNames(CDC* pDC);


void WriteResult(CDC* pDC);

public:
void DrawTrajectory(CDC* pDC);

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
public:
	afx_msg void OnSettings();
};

#ifndef _DEBUG  // debug version in MyMaxVisualisationView.cpp
inline CMyMaxVisualisationDoc* CMyMaxVisualisationView::GetDocument() const
   { return reinterpret_cast<CMyMaxVisualisationDoc*>(m_pDocument); }
#endif

