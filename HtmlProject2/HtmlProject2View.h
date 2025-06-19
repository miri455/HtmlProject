
// HtmlProject2View.h: CHtmlProject2View 클래스의 인터페이스
//

#pragma once


class CHtmlProject2View : public CHtmlView
{
protected: // serialization에서만 만들어집니다.
	CHtmlProject2View() noexcept;
	DECLARE_DYNCREATE(CHtmlProject2View)
	// COM 등록 관련 매크로들 추가
	DECLARE_OLECREATE(CHtmlProject2View)
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

// 특성입니다.
public:
	CHtmlProject2Doc* GetDocument() const;

// 작업입니다.
public:
	virtual HRESULT OnGetExternal(LPDISPATCH* lppDispatch);

	void CallName();

	void CallLanguage();

	void CallSCMTool();

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

	void Calculate(BSTR a, BSTR b, BSTR op);

// 구현입니다.
public:
	virtual ~CHtmlProject2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // HtmlProject2View.cpp의 디버그 버전
inline CHtmlProject2Doc* CHtmlProject2View::GetDocument() const
   { return reinterpret_cast<CHtmlProject2Doc*>(m_pDocument); }
#endif

