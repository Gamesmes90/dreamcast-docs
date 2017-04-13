/* This header file machine-generated by mktyplib.exe */
/* Interface to type library: CardObjects */

#ifndef _CardObjects_H_
#define _CardObjects_H_

DEFINE_GUID(LIBID_CardObjects,0x55707B20L,0xFF82,0x11CF,0xBB,0x32,0x14,0x2A,0x04,0xC1,0x00,0x00);
#ifndef BEGIN_INTERFACE
#define BEGIN_INTERFACE
#endif

typedef enum {
    CardTopLeft = 0,
    CardTopCenter = 1,
    CardTopRight = 2,
    CardCenterLeft = 3,
    CardCenter = 4,
    CardCenterRight = 5,
    CardBottomLeft = 6,
    CardBottomCenter = 7,
    CardBottomRight = 8,
    CardStretch = 9
} enumCardAlignment;

typedef enum {
    CardAce = 1,
    Card2 = 2,
    Card3 = 3,
    Card4 = 4,
    Card5 = 5,
    Card6 = 6,
    Card7 = 7,
    Card8 = 8,
    Card9 = 9,
    Card10 = 10,
    CardJack = 11,
    CardQueen = 12,
    CardKing = 13,
    CardJoker = 14
} enumCardNumber;

typedef enum {
    CardBlank = 0,
    CardClub = 1,
    CardSpade = 2,
    CardHeart = 3,
    CardDiamond = 4,
    CardBack1 = -1,
    CardBack2 = -2,
    CardBack3 = -3,
    CardBack4 = -4,
    CardBack5 = -5,
    CardBack6 = -6,
    CardBack7 = -7,
    CardBack8 = -8,
    CardBack9 = -9,
    CardBack10 = -10,
    CardBack11 = -11,
    CardBack12 = -12,
    CardBack13 = -13
} enumCardSuite;

DEFINE_GUID(IID_ICard,0x55707B21L,0xFF82,0x11CF,0xBB,0x32,0x14,0x2A,0x04,0xC1,0x00,0x00);

/* Definition of interface: ICard */
#undef INTERFACE
#define INTERFACE ICard

DECLARE_INTERFACE_(ICard, IDispatch)
{
BEGIN_INTERFACE
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

    /* ICard methods */
    STDMETHOD(get_Number)(THIS_ enumCardNumber FAR* number) PURE;
    STDMETHOD(put_Number)(THIS_ enumCardNumber number) PURE;
    STDMETHOD(get_Suite)(THIS_ enumCardSuite FAR* suite) PURE;
    STDMETHOD(put_Suite)(THIS_ enumCardSuite suite) PURE;
    STDMETHOD(get_Invert)(THIS_ VARIANT_BOOL FAR* invert) PURE;
    STDMETHOD(put_Invert)(THIS_ VARIANT_BOOL invert) PURE;
    STDMETHOD(get_CardAlignment)(THIS_ enumCardAlignment FAR* cardalignment) PURE;
    STDMETHOD(put_CardAlignment)(THIS_ enumCardAlignment cardalignment) PURE;
    STDMETHOD_(void, AboutBox)(THIS) PURE;
};

DEFINE_GUID(DIID_DCardEvents,0x55707B22L,0xFF82,0x11CF,0xBB,0x32,0x14,0x2A,0x04,0xC1,0x00,0x00);

/* Definition of dispatch interface: DCardEvents */
#undef INTERFACE
#define INTERFACE DCardEvents

DECLARE_INTERFACE_(DCardEvents, IDispatch)
{
BEGIN_INTERFACE
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

    /* DCardEvents methods:
    void MouseMove(short Button, short Shift, OLE_XPOS_PIXELS x, OLE_YPOS_PIXELS y);
    void Click(void);
    void DblClick(void);
    void MouseDown(short Button, short Shift, OLE_XPOS_PIXELS x, OLE_YPOS_PIXELS y);
    void MouseUp(short Button, short Shift, OLE_XPOS_PIXELS x, OLE_YPOS_PIXELS y);
    */
};

DEFINE_GUID(CLSID_Card,0x55707B23L,0xFF82,0x11CF,0xBB,0x32,0x14,0x2A,0x04,0xC1,0x00,0x00);

#ifdef __cplusplus
class Card;
#endif

#endif