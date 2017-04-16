// bitmapob.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CBitmapObject command target

class CBitmapObject : public CCmdTarget
{
	DECLARE_DYNCREATE(CBitmapObject)
protected:
	CBitmapObject();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitmapObject)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CBitmapObject();

	// Generated message map functions
	//{{AFX_MSG(CBitmapObject)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CBitmapObject)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CBitmapObject)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

    // Declare the interface map for this object
    DECLARE_INTERFACE_MAP()

    // IBitmap interface
    BEGIN_INTERFACE_PART(Bitmap, IBitmap)
        STDMETHOD(LoadResource)(WORD wResID);
    END_INTERFACE_PART(Bitmap)

    // IDrawing interface
    BEGIN_INTERFACE_PART(Drawing, IDrawing)
        STDMETHOD(Draw)(CDC* pDC,int x, int y);
        STDMETHOD(SetPalette)(CPalette* pPal);
        STDMETHOD(GetRect)(CRect* pRect);
    END_INTERFACE_PART(Drawing)

    // member variables
    CDIB m_dibImage;
    WORD m_wResID;
    CPalette* m_pPal;
};

/////////////////////////////////////////////////////////////////////////////
