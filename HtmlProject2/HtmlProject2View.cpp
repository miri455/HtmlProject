
// HtmlProject2View.cpp: CHtmlProject2View 클래스의 구현
//

#include <cmath>
#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "HtmlProject2.h"
#endif

#include "HtmlProject2Doc.h"
#include "HtmlProject2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHtmlProject2View

IMPLEMENT_DYNCREATE(CHtmlProject2View, CHtmlView)

BEGIN_MESSAGE_MAP(CHtmlProject2View, CHtmlView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CHtmlProject2View, CHtmlView)
	DISP_FUNCTION_ID(CHtmlProject2View, "CallName", 1, CallName, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CHtmlProject2View, "CallLanguage", 2, CallLanguage, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CHtmlProject2View, "CallSCMTool", 3, CallSCMTool, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CHtmlProject2View, "Calculate", 4, Calculate, VT_EMPTY, VTS_BSTR VTS_BSTR VTS_BSTR)
END_DISPATCH_MAP()

BEGIN_INTERFACE_MAP(CHtmlProject2View, CHtmlView)
	INTERFACE_PART(CHtmlProject2View, IID_IDispatch, Dispatch)
END_INTERFACE_MAP()

// CHtmlProject2View 생성/소멸

CHtmlProject2View::CHtmlProject2View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	EnableAutomation();
}

CHtmlProject2View::~CHtmlProject2View()
{
}

BOOL CHtmlProject2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CHtmlView::PreCreateWindow(cs);
}

void CHtmlProject2View::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	//Navigate2(_T("http://www.msdn.microsoft.com/korea/visualc/"),nullptr, nullptr);
	//Navigate2(_T("https://www.google.com"), NULL, NULL, NULL, NULL);

	TCHAR exePath[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, exePath, MAX_PATH);

	CString path(exePath);
	path = path.Left(path.ReverseFind('\\')); // 실행 파일 디렉토리
	path += _T("\\main.htm");

	CString url;
	url.Format(_T("file:///%s"), path);
	url.Replace(_T('\\'), _T('/'));

	Navigate2(url, NULL, NULL);
}

HRESULT CHtmlProject2View::OnGetExternal(LPDISPATCH* lppDispatch)
{
	*lppDispatch = GetIDispatch(TRUE);
	return S_OK;
}

void CHtmlProject2View::CallName()
{
	AfxMessageBox(_T("안미리"));
}

void CHtmlProject2View::CallLanguage()
{
	AfxMessageBox(_T("MFC,C,JAVA,Python,HTML,CSS,Javascript"));
}

void CHtmlProject2View::CallSCMTool()
{
	AfxMessageBox(_T("GitLab,GitHub,Attlasian,TortoiseSVN"));
}

void CHtmlProject2View::Calculate(BSTR a, BSTR b, BSTR op)
{
	double n1 = _wtof(a);
	double n2 = _wtof(b);
	double result = 0.0;
	CString msg;

	if (CString(op) == _T("+")) result = n1 + n2;
	else if (CString(op) == _T("-")) result = n1 - n2;
	else if (CString(op) == _T("*")) result = n1 * n2;
	else if (CString(op) == _T("/")) result = n1 / n2;

	if (fmod(result, 1.0) == 0.0)
		msg.Format(_T("계산 결과: %d"), int(result));
	else
		msg.Format(_T("계산 결과: %.2f"), result);

	AfxMessageBox(msg);
}


// CHtmlProject2View 인쇄


// CHtmlProject2View 진단

#ifdef _DEBUG
void CHtmlProject2View::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CHtmlProject2View::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CHtmlProject2Doc* CHtmlProject2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHtmlProject2Doc)));
	return (CHtmlProject2Doc*)m_pDocument;
}
#endif //_DEBUG


// CHtmlProject2View 메시지 처리기
// {69A4159A-18BD-41DC-AF81-D990F07C21A0}
IMPLEMENT_OLECREATE(CHtmlProject2View, "HtmlProject2View",
	0x69a4159a, 0x18bd, 0x41dc, 0xaf, 0x81, 0xd9, 0x90, 0xf0, 0x7c, 0x21, 0xa0);