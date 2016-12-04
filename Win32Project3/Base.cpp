#include <afxwin.h>
#include <string>
#include <sstream>
using namespace std;

class CMyMainWnd : public CFrameWnd{
public:
	CMyMainWnd(){ // конструктор
		Create(NULL, L"MY Window"); // создать рамочное окно класса CFrameWnd 
		this->SetClientFont("Arial", 20, FALSE, FALSE);
		this->UpdateWindow();
	}

	afx_msg void OnLButtonDown(UINT, CPoint); // объ€вление функции, считывающей нажатие левой кнопки мыши
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);// объ€вление функции, считывающей двойное нажатие правой кнопки мыши
	afx_msg void OnPaint(); // первоначальна€ надпись и ее расположение
	afx_msg void OnKeyDown(	UINT nChar,	UINT nRepCnt,UINT nFlags); // объ€вление функции, считывающей нажатие клавиш

	CFont *m_pFont; // тип дл€ шрифта
	COLORREF m_textColor; // тип дл€ цвета текста
	COLORREF m_EllipseColor; // тип дл€ цвета окружности
	DECLARE_MESSAGE_MAP()
	virtual void SetClientFont(CString Typeface,int Size, BOOL Bold, BOOL Italic); // объ€вление функции, задающей стиль

	/*BOOL GetCursorPos(LPPOINT lpPoint); 
	BOOL Ellipse(int x1, int y1, int x2, int y2);
	BOOL Rectangle(int x1, int y1, int x2, int y2);*/

};
BEGIN_MESSAGE_MAP(CMyMainWnd, CFrameWnd)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_PAINT()
END_MESSAGE_MAP()






class CMyApp : public CWinApp{ //ѕереопредел€ем виртуальную функцию InitInstance и создаем внутри нее объект оконного класса
public:
	CMyApp(){}; // конструктор
	virtual BOOL InitInstance(){
		m_pMainWnd = new CMyMainWnd();

		m_pMainWnd->ShowWindow(SW_SHOW);
		return TRUE;
	}

	

};
CMyApp theApp;


void CMyMainWnd::OnLButtonDown(UINT nFlags, CPoint point){

	int rdm = rand() % 200;
	CClientDC dc(this);
	
	CPen NewPen(PS_SOLID, 5, RGB(MulDiv(rand(), 255, RAND_MAX), MulDiv(rand(), 255, RAND_MAX), MulDiv(rand(), 255, RAND_MAX)));
	// multidiv(a,b,c) ”множает a на b и делит pезультат на c, окpугл€€ получаемое значение до длижайшего целого
	dc.SelectObject(&NewPen);
	//‘ункци€ SelectObject выбирает объект в заданный контекст устройства (DC). Ќовый объект замен€ет предыдущий объект того же самого типа.
	dc.Ellipse(point.x - rdm / 2, point.y - rdm / 2, point.x + rdm/2, point.y + rdm/2);
}




void CMyMainWnd::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	CSize sz;
	CRect rect;
	GetClientRect(rect);
	int xx = rect.Width();
	int yy = rect.Height();

	CClientDC dc(this);
	CPen NewPen(PS_SOLID, 0, RGB(255,255,255)); // без рамки и полностью белый
	dc.SelectObject(&NewPen); //  
	dc.Rectangle(0, 0, xx, yy);// пр€моугольник
}

void CMyMainWnd::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	//UINT ONE = 49;
	LOGFONT lf;
	m_pFont->GetLogFont(&lf);
	if (nChar == 49) // кнопка == 1
	{
		this->SetClientFont("Arial", 10, TRUE, FALSE); // ставим шрифт и размер
		m_textColor = RGB(MulDiv(rand(), 255, RAND_MAX),MulDiv(rand(), 255, RAND_MAX), MulDiv(rand(), 255, RAND_MAX)); 
		// multidiv(a,b,c) ”множает a на b и делит pезультат на c, окpугл€€ получаемое значение до длижайшего целого
		this->InvalidateRect(0); // перерисовываем 
	}
	if (nChar == 50)
	{
		this->SetClientFont("Times New Roman", 11, FALSE, FALSE);
		m_textColor = RGB(MulDiv(rand(), 255, RAND_MAX), MulDiv(rand(), 255, RAND_MAX), MulDiv(rand(), 255, RAND_MAX));
		this->InvalidateRect(0);
	}
	if (nChar == 51)
	{
		this->SetClientFont("Comic Sans MS", 12, TRUE, FALSE);
		m_textColor = RGB(MulDiv(rand(), 255, RAND_MAX), MulDiv(rand(), 255, RAND_MAX), MulDiv(rand(), 255, RAND_MAX));
		this->InvalidateRect(0);
	}
	if (nChar == 52)
	{
		this->SetClientFont("Courier New", 13, FALSE, TRUE);
		m_textColor = RGB(MulDiv(rand(), 255, RAND_MAX), MulDiv(rand(), 255, RAND_MAX), MulDiv(rand(), 255, RAND_MAX));
		this->InvalidateRect(0);
	}
	if (nChar == 53)
	{
		this->SetClientFont("Tahoma", 14, TRUE, FALSE);
		m_textColor = RGB(MulDiv(rand(), 255, RAND_MAX), MulDiv(rand(), 255, RAND_MAX), MulDiv(rand(), 255, RAND_MAX));
		this->InvalidateRect(0);
	}
	if (nChar == 54)
	{
		this->SetClientFont("Lucida Console", 15, FALSE, FALSE);
		m_textColor = RGB(MulDiv(rand(), 255, RAND_MAX), MulDiv(rand(), 255, RAND_MAX), MulDiv(rand(), 255, RAND_MAX));
		this->InvalidateRect(0);
	}
	if (nChar == 55)
	{
		this->SetClientFont("Verdana", 16, TRUE, TRUE);
		m_textColor = RGB(MulDiv(rand(), 255, RAND_MAX), MulDiv(rand(), 255, RAND_MAX), MulDiv(rand(), 255, RAND_MAX));
		this->InvalidateRect(0);
	}
	if (nChar == 56)
	{
		this->SetClientFont("Trebuchet MS", 17, FALSE, FALSE);
		m_textColor = RGB(MulDiv(rand(), 255, RAND_MAX), MulDiv(rand(), 255, RAND_MAX), MulDiv(rand(), 255, RAND_MAX));
		this->InvalidateRect(0);
	}
	if (nChar == 57)// кнопка == 9
	{
		this->SetClientFont("Arial", 18, TRUE, TRUE);
		m_textColor = RGB(MulDiv(rand(), 255, RAND_MAX), MulDiv(rand(), 255, RAND_MAX), MulDiv(rand(), 255, RAND_MAX));
		this->InvalidateRect(0);
	}
	



}




void CMyMainWnd::SetClientFont(CString Typeface,
	int Size, BOOL Bold, BOOL Italic)
{
	// ѕолучим контекст окна
	CWindowDC winDC(this);
	// ”знаем, сколько пикселей в одном логическом дюйме
	int pixelsPerInch = winDC.GetDeviceCaps(LOGPIXELSY);
	// ”знаем высоту в пиксел€х шрифта размером Size пунктов
	int fontHeight = -MulDiv(Size, pixelsPerInch, 72);
	int Weight = FW_NORMAL;
	if (Bold)
		Weight = FW_BOLD;
	// ”дал€ем предыдущий экземпл€р шрифта -- нельз€ дважды 
	// инициализировать шрифт вызовом CreateFont().
	delete m_pFont;
	m_pFont = new CFont;
	m_pFont->CreateFont(fontHeight, 0, 0, 0, Weight, Italic, 0, 0,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, PROOF_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, Typeface);

}
void CMyMainWnd::OnPaint(){

	CSize sz;
	CRect rect;
	GetClientRect(rect);
	int x = rect.Width();
	int y = rect.Width();
	
	
	CPaintDC paintDC(this);
	COLORREF oldColor = paintDC.SetTextColor(m_textColor);
	LOGFONT lf;
	m_pFont->GetLogFont(&lf);
	paintDC.SelectObject(m_pFont);
	TEXTMETRIC tm;
	paintDC.GetTextMetrics(&tm);

	sz = paintDC.GetTextExtent(L"Some text");

	paintDC.TextOut(x/2-sz.cx/2,y/4-sz.cy, L"Some text");
	paintDC.SetTextColor(oldColor);
}