// MyMaxVisualisationDoc.cpp : implementation of the CMyMaxVisualisationDoc class
//

#include "stdafx.h"
#include "MyMaxVisualisation.h"

#include "MyMaxVisualisationDoc.h"
#include "R32M.H"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyMaxVisualisationDoc

IMPLEMENT_DYNCREATE(CMyMaxVisualisationDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyMaxVisualisationDoc, CDocument)
END_MESSAGE_MAP()


// CMyMaxVisualisationDoc construction/destruction

CMyMaxVisualisationDoc::CMyMaxVisualisationDoc():
p_func(new Function_4),
p_area(new Area),
method_type(1),
f_type(0)
{
	// TODO: add one-time construction code here
	rninit(time(0));

	p_grad_method = new GradMethod(10000, 0.0001, 0.001, 0.1, true);
	p_gorge_method = new GorgeMethod(*p_grad_method, 1000, 0.001, 0.001);
	p_random_method = new RandomMethod(10000, 0.1, 0.9, 1000);
	p_current_method = p_gorge_method;
}

//Method* CMyMaxVisualisationDoc::current_method() {
//	if (method_type == 0) {
//		return p_random_method;
//	} else {
//		if (method_type == 1) {
//			return p_gorge_method;
//		} else {
//			return p_grad_method;
//		}
//	}
//}

CMyMaxVisualisationDoc::~CMyMaxVisualisationDoc()
{
	delete p_func;
	delete p_area;
	delete p_random_method;
	delete p_gorge_method;
	delete p_grad_method;
}

BOOL CMyMaxVisualisationDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	
	//i = 100;
	
	return TRUE;
}




// CMyMaxVisualisationDoc serialization

void CMyMaxVisualisationDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CMyMaxVisualisationDoc diagnostics

#ifdef _DEBUG
void CMyMaxVisualisationDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyMaxVisualisationDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMyMaxVisualisationDoc commands

//int CMyMaxVisualisationDoc::GetI(void)
//{
//	return i;
//}
