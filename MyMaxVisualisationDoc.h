// MyMaxVisualisationDoc.h : interface of the CMyMaxVisualisationDoc class
//
#include "Area.h"
#include "Function.h"
#include "Method.h"
#include "MethodResult.h"


class CMyMaxVisualisationDoc : public CDocument
{
protected: // create from serialization only
	CMyMaxVisualisationDoc();
	DECLARE_DYNCREATE(CMyMaxVisualisationDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CMyMaxVisualisationDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

public:
	
	GorgeMethod* p_gorge_method;
	RandomMethod* p_random_method;
	GradMethod* p_grad_method;
	Method* p_current_method;
public :
	MethodResult method_result;

public:
	TwoArgumentFunction* p_func;
public:
		Area* p_area;
public:
	
	int method_type;

//	Method* current_method();
public:
	int f_type;
};


