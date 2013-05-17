/*
 * dshow_.h
 *
 *  Created on: 2012/9/3
 *      Author: SUCHEN
 */

#ifndef DSHOW__H_
#define DSHOW__H_

#include <ocidl.h>
#include <oleidl.h>
#include <unknwn.h>

struct IOleInPlaceObjectWindowless: public IOleInPlaceObject {
	virtual HRESULT STDMETHODCALLTYPE OnWindowMessage(
	/* [in] */UINT msg,
	/* [in] */WPARAM wParam,
	/* [in] */LPARAM lParam,
	/* [out] */LRESULT *plResult) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetDropTarget(
	/* [out] */IDropTarget **ppDropTarget) = 0;
};

struct IShockwaveFlash: public IDispatch {
	virtual HRESULT __stdcall get_ReadyState(
	/*[out,retval]*/long * pVal) = 0;
	virtual HRESULT __stdcall get_TotalFrames(
	/*[out,retval]*/long * pVal) = 0;
	virtual HRESULT __stdcall get_Playing(
	/*[out,retval]*/VARIANT_BOOL * pVal) = 0;
	virtual HRESULT __stdcall put_Playing(
	/*[in]*/VARIANT_BOOL pVal) = 0;
	virtual HRESULT __stdcall get_Quality(
	/*[out,retval]*/int * pVal) = 0;
	virtual HRESULT __stdcall put_Quality(
	/*[in]*/int pVal) = 0;
	virtual HRESULT __stdcall get_ScaleMode(
	/*[out,retval]*/int * pVal) = 0;
	virtual HRESULT __stdcall put_ScaleMode(
	/*[in]*/int pVal) = 0;
	virtual HRESULT __stdcall get_AlignMode(
	/*[out,retval]*/int * pVal) = 0;
	virtual HRESULT __stdcall put_AlignMode(
	/*[in]*/int pVal) = 0;
	virtual HRESULT __stdcall get_BackgroundColor(
	/*[out,retval]*/long * pVal) = 0;
	virtual HRESULT __stdcall put_BackgroundColor(
	/*[in]*/long pVal) = 0;
	virtual HRESULT __stdcall get_Loop(
	/*[out,retval]*/VARIANT_BOOL * pVal) = 0;
	virtual HRESULT __stdcall put_Loop(
	/*[in]*/VARIANT_BOOL pVal) = 0;
	virtual HRESULT __stdcall get_Movie(
	/*[out,retval]*/BSTR * pVal) = 0;
	virtual HRESULT __stdcall put_Movie(
	/*[in]*/BSTR pVal) = 0;
	virtual HRESULT __stdcall get_FrameNum(
	/*[out,retval]*/long * pVal) = 0;
	virtual HRESULT __stdcall put_FrameNum(
	/*[in]*/long pVal) = 0;
	virtual HRESULT __stdcall raw_SetZoomRect(
	/*[in]*/long left,
	/*[in]*/long top,
	/*[in]*/long right,
	/*[in]*/long bottom) = 0;
	virtual HRESULT __stdcall raw_Zoom(
	/*[in]*/int factor) = 0;
	virtual HRESULT __stdcall raw_Pan(
	/*[in]*/long x,
	/*[in]*/long y,
	/*[in]*/int mode) = 0;
	virtual HRESULT __stdcall raw_Play() = 0;
	virtual HRESULT __stdcall raw_Stop() = 0;
	virtual HRESULT __stdcall raw_Back() = 0;
	virtual HRESULT __stdcall raw_Forward() = 0;
	virtual HRESULT __stdcall raw_Rewind() = 0;
	virtual HRESULT __stdcall raw_StopPlay() = 0;
	virtual HRESULT __stdcall raw_GotoFrame(
	/*[in]*/long FrameNum) = 0;
	virtual HRESULT __stdcall raw_CurrentFrame(
	/*[out,retval]*/long * FrameNum) = 0;
	virtual HRESULT __stdcall raw_IsPlaying(
	/*[out,retval]*/VARIANT_BOOL * Playing) = 0;
	virtual HRESULT __stdcall raw_PercentLoaded(
	/*[out,retval]*/long * percent) = 0;
	virtual HRESULT __stdcall raw_FrameLoaded(
	/*[in]*/long FrameNum,
	/*[out,retval]*/VARIANT_BOOL * loaded) = 0;
	virtual HRESULT __stdcall raw_FlashVersion(
	/*[out,retval]*/long * version) = 0;
	virtual HRESULT __stdcall get_WMode(
	/*[out,retval]*/BSTR * pVal) = 0;
	virtual HRESULT __stdcall put_WMode(
	/*[in]*/BSTR pVal) = 0;
	virtual HRESULT __stdcall get_SAlign(
	/*[out,retval]*/BSTR * pVal) = 0;
	virtual HRESULT __stdcall put_SAlign(
	/*[in]*/BSTR pVal) = 0;
	virtual HRESULT __stdcall get_Menu(
	/*[out,retval]*/VARIANT_BOOL * pVal) = 0;
	virtual HRESULT __stdcall put_Menu(
	/*[in]*/VARIANT_BOOL pVal) = 0;
	virtual HRESULT __stdcall get_Base(
	/*[out,retval]*/BSTR * pVal) = 0;
	virtual HRESULT __stdcall put_Base(
	/*[in]*/BSTR pVal) = 0;
	virtual HRESULT __stdcall get_Scale(
	/*[out,retval]*/BSTR * pVal) = 0;
	virtual HRESULT __stdcall put_Scale(
	/*[in]*/BSTR pVal) = 0;
	virtual HRESULT __stdcall get_DeviceFont(
	/*[out,retval]*/VARIANT_BOOL * pVal) = 0;
	virtual HRESULT __stdcall put_DeviceFont(
	/*[in]*/VARIANT_BOOL pVal) = 0;
	virtual HRESULT __stdcall get_EmbedMovie(
	/*[out,retval]*/VARIANT_BOOL * pVal) = 0;
	virtual HRESULT __stdcall put_EmbedMovie(
	/*[in]*/VARIANT_BOOL pVal) = 0;
	virtual HRESULT __stdcall get_BGColor(
	/*[out,retval]*/BSTR * pVal) = 0;
	virtual HRESULT __stdcall put_BGColor(
	/*[in]*/BSTR pVal) = 0;
	virtual HRESULT __stdcall get_Quality2(
	/*[out,retval]*/BSTR * pVal) = 0;
	virtual HRESULT __stdcall put_Quality2(
	/*[in]*/BSTR pVal) = 0;
	virtual HRESULT __stdcall raw_LoadMovie(
	/*[in]*/int layer,
	/*[in]*/BSTR url) = 0;
	virtual HRESULT __stdcall raw_TGotoFrame(
	/*[in]*/BSTR target,
	/*[in]*/long FrameNum) = 0;
	virtual HRESULT __stdcall raw_TGotoLabel(
	/*[in]*/BSTR target,
	/*[in]*/BSTR label) = 0;
	virtual HRESULT __stdcall raw_TCurrentFrame(
	/*[in]*/BSTR target,
	/*[out,retval]*/long * FrameNum) = 0;
	virtual HRESULT __stdcall raw_TCurrentLabel(
	/*[in]*/BSTR target,
	/*[out,retval]*/BSTR * pVal) = 0;
	virtual HRESULT __stdcall raw_TPlay(
	/*[in]*/BSTR target) = 0;
	virtual HRESULT __stdcall raw_TStopPlay(
	/*[in]*/BSTR target) = 0;
	virtual HRESULT __stdcall raw_SetVariable(
	/*[in]*/BSTR name,
	/*[in]*/BSTR value) = 0;
	virtual HRESULT __stdcall raw_GetVariable(
	/*[in]*/BSTR name,
	/*[out,retval]*/BSTR * pVal) = 0;
	virtual HRESULT __stdcall raw_TSetProperty(
	/*[in]*/BSTR target,
	/*[in]*/int property,
	/*[in]*/BSTR value) = 0;
	virtual HRESULT __stdcall raw_TGetProperty(
	/*[in]*/BSTR target,
	/*[in]*/int property,
	/*[out,retval]*/BSTR * pVal) = 0;
	virtual HRESULT __stdcall raw_TCallFrame(
	/*[in]*/BSTR target,
	/*[in]*/int FrameNum) = 0;
	virtual HRESULT __stdcall raw_TCallLabel(
	/*[in]*/BSTR target,
	/*[in]*/BSTR label) = 0;
	virtual HRESULT __stdcall raw_TSetPropertyNum(
	/*[in]*/BSTR target,
	/*[in]*/int property,
	/*[in]*/double value) = 0;
	virtual HRESULT __stdcall raw_TGetPropertyNum(
	/*[in]*/BSTR target,
	/*[in]*/int property,
	/*[out,retval]*/double * pVal) = 0;
	virtual HRESULT __stdcall raw_TGetPropertyAsNumber(
	/*[in]*/BSTR target,
	/*[in]*/int property,
	/*[out,retval]*/double * pVal) = 0;
	virtual HRESULT __stdcall get_SWRemote(
	/*[out,retval]*/BSTR * pVal) = 0;
	virtual HRESULT __stdcall put_SWRemote(
	/*[in]*/BSTR pVal) = 0;
	virtual HRESULT __stdcall get_FlashVars(
	/*[out,retval]*/BSTR * pVal) = 0;
	virtual HRESULT __stdcall put_FlashVars(
	/*[in]*/BSTR pVal) = 0;
	virtual HRESULT __stdcall get_AllowScriptAccess(
	/*[out,retval]*/BSTR * pVal) = 0;
	virtual HRESULT __stdcall put_AllowScriptAccess(
	/*[in]*/BSTR pVal) = 0;
	virtual HRESULT __stdcall get_MovieData(
	/*[out,retval]*/BSTR * pVal) = 0;
	virtual HRESULT __stdcall put_MovieData(
	/*[in]*/BSTR pVal) = 0;
	virtual HRESULT __stdcall get_InlineData(
	/*[out,retval]*/IUnknown * * ppIUnknown) = 0;
	virtual HRESULT __stdcall put_InlineData(
	/*[in]*/IUnknown * ppIUnknown) = 0;
	virtual HRESULT __stdcall get_SeamlessTabbing(
	/*[out,retval]*/VARIANT_BOOL * pVal) = 0;
	virtual HRESULT __stdcall put_SeamlessTabbing(
	/*[in]*/VARIANT_BOOL pVal) = 0;
	virtual HRESULT __stdcall raw_EnforceLocalSecurity() = 0;
	virtual HRESULT __stdcall get_Profile(
	/*[out,retval]*/VARIANT_BOOL * pVal) = 0;
	virtual HRESULT __stdcall put_Profile(
	/*[in]*/VARIANT_BOOL pVal) = 0;
	virtual HRESULT __stdcall get_ProfileAddress(
	/*[out,retval]*/BSTR * pVal) = 0;
	virtual HRESULT __stdcall put_ProfileAddress(
	/*[in]*/BSTR pVal) = 0;
	virtual HRESULT __stdcall get_ProfilePort(
	/*[out,retval]*/long * pVal) = 0;
	virtual HRESULT __stdcall put_ProfilePort(
	/*[in]*/long pVal) = 0;
	virtual HRESULT __stdcall raw_CallFunction(
	/*[in]*/BSTR request,
	/*[out,retval]*/BSTR * response) = 0;
	virtual HRESULT __stdcall raw_SetReturnValue(
	/*[in]*/BSTR returnValue) = 0;
	virtual HRESULT __stdcall raw_DisableLocalSecurity() = 0;
	virtual HRESULT __stdcall get_AllowNetworking(
	/*[out,retval]*/BSTR * pVal) = 0;
	virtual HRESULT __stdcall put_AllowNetworking(
	/*[in]*/BSTR pVal) = 0;
	virtual HRESULT __stdcall get_AllowFullScreen(
	/*[out,retval]*/BSTR * pVal) = 0;
	virtual HRESULT __stdcall put_AllowFullScreen(
	/*[in]*/BSTR pVal) = 0;
};

typedef enum _FilterState {
	State_Stopped = 0,
	State_Paused = (State_Stopped + 1),
	State_Running = (State_Paused + 1)
} FILTER_STATE;

#define CHARS_IN_GUID     39
typedef struct _AMMediaType {
	GUID majortype;
	GUID subtype;
	BOOL bFixedSizeSamples;
	BOOL bTemporalCompression;
	ULONG lSampleSize;
	GUID formattype;
	IUnknown *pUnk;
	ULONG cbFormat;
	BYTE *pbFormat;
} AM_MEDIA_TYPE;

typedef enum _PinDirection {
	PINDIR_INPUT = 0, PINDIR_OUTPUT = (PINDIR_INPUT + 1)
} PIN_DIRECTION;

#define MAX_PIN_NAME     128
#define MAX_FILTER_NAME  128

typedef LONGLONG REFERENCE_TIME;
typedef DWORD_PTR HSEMAPHORE;
typedef DWORD_PTR HEVENT;
typedef LONG_PTR OAHWND;

struct IBaseFilter;
struct IFilterGraph;

typedef struct _AllocatorProperties {
	long cBuffers;
	long cbBuffer;
	long cbAlign;
	long cbPrefix;
} ALLOCATOR_PROPERTIES;

typedef struct _PinInfo {
	IBaseFilter *pFilter;
	PIN_DIRECTION dir;
	WCHAR achName[128];
} PIN_INFO;

typedef struct _FilterInfo {
	WCHAR achName[128];
	IFilterGraph *pGraph;
} FILTER_INFO;

struct IReferenceClock: public IUnknown {
public:
	virtual HRESULT STDMETHODCALLTYPE GetTime(
	/* [annotation][out] */
	REFERENCE_TIME *pTime) = 0;

	virtual HRESULT STDMETHODCALLTYPE AdviseTime(
	/* [in] */REFERENCE_TIME baseTime,
	/* [in] */REFERENCE_TIME streamTime,
	/* [in] */HEVENT hEvent,
	/* [annotation][out] */
	DWORD_PTR *pdwAdviseCookie) = 0;

	virtual HRESULT STDMETHODCALLTYPE AdvisePeriodic(
	/* [in] */REFERENCE_TIME startTime,
	/* [in] */REFERENCE_TIME periodTime,
	/* [in] */HSEMAPHORE hSemaphore,
	/* [annotation][out] */
	DWORD_PTR *pdwAdviseCookie) = 0;

	virtual HRESULT STDMETHODCALLTYPE Unadvise(
	/* [in] */DWORD_PTR dwAdviseCookie) = 0;

};

struct IMediaFilter: public IPersist {
public:
	virtual HRESULT STDMETHODCALLTYPE Stop(void) = 0;

	virtual HRESULT STDMETHODCALLTYPE Pause(void) = 0;

	virtual HRESULT STDMETHODCALLTYPE Run(REFERENCE_TIME tStart) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetState(
	/* [in] */DWORD dwMilliSecsTimeout,
	/* [annotation][out] */
	FILTER_STATE *State) = 0;

	virtual HRESULT STDMETHODCALLTYPE SetSyncSource(
	/* [annotation][in] */
	IReferenceClock *pClock) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetSyncSource(
	/* [annotation][out] */
	IReferenceClock **pClock) = 0;
};

struct IEnumMediaTypes;

struct IPin: public IUnknown {
public:
	virtual HRESULT STDMETHODCALLTYPE Connect(
	/* [in] */IPin *pReceivePin,
	/* [annotation][in] */
	const AM_MEDIA_TYPE *pmt) = 0;

	virtual HRESULT STDMETHODCALLTYPE ReceiveConnection(
	/* [in] */IPin *pConnector,
	/* [in] */const AM_MEDIA_TYPE *pmt) = 0;

	virtual HRESULT STDMETHODCALLTYPE Disconnect(void) = 0;

	virtual HRESULT STDMETHODCALLTYPE ConnectedTo(
	/* [annotation][out] */
	IPin **pPin) = 0;

	virtual HRESULT STDMETHODCALLTYPE ConnectionMediaType(
	/* [annotation][out] */
	AM_MEDIA_TYPE *pmt) = 0;

	virtual HRESULT STDMETHODCALLTYPE QueryPinInfo(
	/* [annotation][out] */
	PIN_INFO *pInfo) = 0;

	virtual HRESULT STDMETHODCALLTYPE QueryDirection(
	/* [annotation][out] */
	PIN_DIRECTION *pPinDir) = 0;

	virtual HRESULT STDMETHODCALLTYPE QueryId(
	/* [annotation][out] */
	LPWSTR *Id) = 0;

	virtual HRESULT STDMETHODCALLTYPE QueryAccept(
	/* [in] */const AM_MEDIA_TYPE *pmt) = 0;

	virtual HRESULT STDMETHODCALLTYPE EnumMediaTypes(
	/* [annotation][out] */
	IEnumMediaTypes **ppEnum) = 0;

	virtual HRESULT STDMETHODCALLTYPE QueryInternalConnections(
	/* [annotation][out] */
	IPin **apPin,
	/* [out][in] */ULONG *nPin) = 0;

	virtual HRESULT STDMETHODCALLTYPE EndOfStream(void) = 0;

	virtual HRESULT STDMETHODCALLTYPE BeginFlush(void) = 0;

	virtual HRESULT STDMETHODCALLTYPE EndFlush(void) = 0;

	virtual HRESULT STDMETHODCALLTYPE NewSegment(
	/* [in] */REFERENCE_TIME tStart,
	/* [in] */REFERENCE_TIME tStop,
	/* [in] */double dRate) = 0;
};

struct IEnumPins;

EXTERN_C const IID IID_IBaseFilter;

struct IBaseFilter: public IMediaFilter {
public:
	virtual HRESULT STDMETHODCALLTYPE EnumPins(
	/* [annotation][out] */
	IEnumPins **ppEnum) = 0;

	virtual HRESULT STDMETHODCALLTYPE FindPin(
	/* [string][in] */LPCWSTR Id,
	/* [annotation][out] */
	IPin **ppPin) = 0;

	virtual HRESULT STDMETHODCALLTYPE QueryFilterInfo(
	/* [annotation][out] */
	FILTER_INFO *pInfo) = 0;

	virtual HRESULT STDMETHODCALLTYPE JoinFilterGraph(
	/* [annotation][in] */
	IFilterGraph *pGraph,
	/* [annotation][string][in] */
	LPCWSTR pName) = 0;

	virtual HRESULT STDMETHODCALLTYPE QueryVendorInfo(
	/* [annotation][string][out] */
	LPWSTR *pVendorInfo) = 0;
};

struct IEnumPins: public IUnknown {
public:
	virtual HRESULT STDMETHODCALLTYPE Next(
	/* [in] */ULONG cPins,
	/* [annotation][size_is][out] */
	IPin **ppPins,
	/* [annotation][out] */
	ULONG *pcFetched) = 0;

	virtual HRESULT STDMETHODCALLTYPE Skip(
	/* [in] */ULONG cPins) = 0;

	virtual HRESULT STDMETHODCALLTYPE Reset(void) = 0;

	virtual HRESULT STDMETHODCALLTYPE Clone(
	/* [annotation][out] */
	IEnumPins **ppEnum) = 0;
};

struct IMemAllocator;
struct IMediaSample;

struct IMemInputPin: public IUnknown {
public:
	virtual HRESULT STDMETHODCALLTYPE GetAllocator(
	/* [annotation][out] */
	IMemAllocator **ppAllocator) = 0;

	virtual HRESULT STDMETHODCALLTYPE NotifyAllocator(
	/* [in] */IMemAllocator *pAllocator,
	/* [in] */BOOL bReadOnly) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetAllocatorRequirements(
	/* [annotation][out] */
	ALLOCATOR_PROPERTIES *pProps) = 0;

	virtual HRESULT STDMETHODCALLTYPE Receive(
	/* [in] */IMediaSample *pSample) = 0;

	virtual HRESULT STDMETHODCALLTYPE ReceiveMultiple(
	/* [annotation][size_is][in] */
	IMediaSample **pSamples,
	/* [in] */long nSamples,
	/* [annotation][out] */
	long *nSamplesProcessed) = 0;

	virtual HRESULT STDMETHODCALLTYPE ReceiveCanBlock(void) = 0;
};

struct IMemAllocator: public IUnknown {
public:
	virtual HRESULT STDMETHODCALLTYPE SetProperties(
	/* [annotation][in] */
	ALLOCATOR_PROPERTIES *pRequest,
	/* [annotation][out] */
	ALLOCATOR_PROPERTIES *pActual) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetProperties(
	/* [annotation][out] */
	ALLOCATOR_PROPERTIES *pProps) = 0;

	virtual HRESULT STDMETHODCALLTYPE Commit(void) = 0;

	virtual HRESULT STDMETHODCALLTYPE Decommit(void) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetBuffer(
	/* [annotation][out] */
	IMediaSample **ppBuffer,
	/* [annotation][unique][in] */
	REFERENCE_TIME *pStartTime,
	/* [annotation][unique][in] */
	REFERENCE_TIME *pEndTime,
	/* [in] */DWORD dwFlags) = 0;

	virtual HRESULT STDMETHODCALLTYPE ReleaseBuffer(
	/* [in] */IMediaSample *pBuffer) = 0;
};

struct IVideoWindow: public IDispatch {
public:
	virtual/* [propput] */HRESULT STDMETHODCALLTYPE put_Caption(
	/* [in] */BSTR strCaption) = 0;

	virtual/* [propget] */HRESULT STDMETHODCALLTYPE get_Caption(
	/* [retval][out] */BSTR *strCaption) = 0;

	virtual/* [propput] */HRESULT STDMETHODCALLTYPE put_WindowStyle(
	/* [in] */long WindowStyle) = 0;

	virtual/* [propget] */HRESULT STDMETHODCALLTYPE get_WindowStyle(
	/* [retval][out] */long *WindowStyle) = 0;

	virtual/* [propput] */HRESULT STDMETHODCALLTYPE put_WindowStyleEx(
	/* [in] */long WindowStyleEx) = 0;

	virtual/* [propget] */HRESULT STDMETHODCALLTYPE get_WindowStyleEx(
	/* [retval][out] */long *WindowStyleEx) = 0;

	virtual/* [propput] */HRESULT STDMETHODCALLTYPE put_AutoShow(
	/* [in] */long AutoShow) = 0;

	virtual/* [propget] */HRESULT STDMETHODCALLTYPE get_AutoShow(
	/* [retval][out] */long *AutoShow) = 0;

	virtual/* [propput] */HRESULT STDMETHODCALLTYPE put_WindowState(
	/* [in] */long WindowState) = 0;

	virtual/* [propget] */HRESULT STDMETHODCALLTYPE get_WindowState(
	/* [retval][out] */long *WindowState) = 0;

	virtual/* [propput] */HRESULT STDMETHODCALLTYPE put_BackgroundPalette(
	/* [in] */long BackgroundPalette) = 0;

	virtual/* [propget] */HRESULT STDMETHODCALLTYPE get_BackgroundPalette(
	/* [retval][out] */long *pBackgroundPalette) = 0;

	virtual/* [propput] */HRESULT STDMETHODCALLTYPE put_Visible(
	/* [in] */long Visible) = 0;

	virtual/* [propget] */HRESULT STDMETHODCALLTYPE get_Visible(
	/* [retval][out] */long *pVisible) = 0;

	virtual/* [propput] */HRESULT STDMETHODCALLTYPE put_Left(
	/* [in] */long Left) = 0;

	virtual/* [propget] */HRESULT STDMETHODCALLTYPE get_Left(
	/* [retval][out] */long *pLeft) = 0;

	virtual/* [propput] */HRESULT STDMETHODCALLTYPE put_Width(
	/* [in] */long Width) = 0;

	virtual/* [propget] */HRESULT STDMETHODCALLTYPE get_Width(
	/* [retval][out] */long *pWidth) = 0;

	virtual/* [propput] */HRESULT STDMETHODCALLTYPE put_Top(
	/* [in] */long Top) = 0;

	virtual/* [propget] */HRESULT STDMETHODCALLTYPE get_Top(
	/* [retval][out] */long *pTop) = 0;

	virtual/* [propput] */HRESULT STDMETHODCALLTYPE put_Height(
	/* [in] */long Height) = 0;

	virtual/* [propget] */HRESULT STDMETHODCALLTYPE get_Height(
	/* [retval][out] */long *pHeight) = 0;

	virtual/* [propput] */HRESULT STDMETHODCALLTYPE put_Owner(
	/* [in] */OAHWND Owner) = 0;

	virtual/* [propget] */HRESULT STDMETHODCALLTYPE get_Owner(
	/* [retval][out] */OAHWND *Owner) = 0;

	virtual/* [propput] */HRESULT STDMETHODCALLTYPE put_MessageDrain(
	/* [in] */OAHWND Drain) = 0;

	virtual/* [propget] */HRESULT STDMETHODCALLTYPE get_MessageDrain(
	/* [retval][out] */OAHWND *Drain) = 0;

	virtual/* [propget] */HRESULT STDMETHODCALLTYPE get_BorderColor(
	/* [retval][out] */long *Color) = 0;

	virtual/* [propput] */HRESULT STDMETHODCALLTYPE put_BorderColor(
	/* [in] */long Color) = 0;

	virtual/* [propget] */HRESULT STDMETHODCALLTYPE get_FullScreenMode(
	/* [retval][out] */long *FullScreenMode) = 0;

	virtual/* [propput] */HRESULT STDMETHODCALLTYPE put_FullScreenMode(
	/* [in] */long FullScreenMode) = 0;

	virtual HRESULT STDMETHODCALLTYPE SetWindowForeground(
	/* [in] */long Focus) = 0;

	virtual HRESULT STDMETHODCALLTYPE NotifyOwnerMessage(
	/* [in] */OAHWND hwnd,
	/* [in] */long uMsg,
	/* [in] */LONG_PTR wParam,
	/* [in] */LONG_PTR lParam) = 0;

	virtual HRESULT STDMETHODCALLTYPE SetWindowPosition(
	/* [in] */long Left,
	/* [in] */long Top,
	/* [in] */long Width,
	/* [in] */long Height) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetWindowPosition(
	/* [out] */long *pLeft,
	/* [out] */long *pTop,
	/* [out] */long *pWidth,
	/* [out] */long *pHeight) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetMinIdealImageSize(
	/* [out] */long *pWidth,
	/* [out] */long *pHeight) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetMaxIdealImageSize(
	/* [out] */long *pWidth,
	/* [out] */long *pHeight) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetRestorePosition(
	/* [out] */long *pLeft,
	/* [out] */long *pTop,
	/* [out] */long *pWidth,
	/* [out] */long *pHeight) = 0;

	virtual HRESULT STDMETHODCALLTYPE HideCursor(
	/* [in] */long HideCursor) = 0;

	virtual HRESULT STDMETHODCALLTYPE IsCursorHidden(
	/* [out] */long *CursorHidden) = 0;
};

typedef enum AM_SEEKING_SeekingFlags {
	AM_SEEKING_NoPositioning = 0,
	AM_SEEKING_AbsolutePositioning = 0x1,
	AM_SEEKING_RelativePositioning = 0x2,
	AM_SEEKING_IncrementalPositioning = 0x3,
	AM_SEEKING_PositioningBitsMask = 0x3,
	AM_SEEKING_SeekToKeyFrame = 0x4,
	AM_SEEKING_ReturnTime = 0x8,
	AM_SEEKING_Segment = 0x10,
	AM_SEEKING_NoFlush = 0x20
} AM_SEEKING_SEEKING_FLAGS;

typedef enum AM_SEEKING_SeekingCapabilities {
	AM_SEEKING_CanSeekAbsolute = 0x1,
	AM_SEEKING_CanSeekForwards = 0x2,
	AM_SEEKING_CanSeekBackwards = 0x4,
	AM_SEEKING_CanGetCurrentPos = 0x8,
	AM_SEEKING_CanGetStopPos = 0x10,
	AM_SEEKING_CanGetDuration = 0x20,
	AM_SEEKING_CanPlayBackwards = 0x40,
	AM_SEEKING_CanDoSegments = 0x80,
	AM_SEEKING_Source = 0x100
} AM_SEEKING_SEEKING_CAPABILITIES;

EXTERN_C const IID IID_IMediaSeeking;

struct IMediaSeeking: public IUnknown {
public:
	virtual HRESULT STDMETHODCALLTYPE GetCapabilities(
	/* [annotation][out] */
	DWORD *pCapabilities) = 0;

	virtual HRESULT STDMETHODCALLTYPE CheckCapabilities(
	/* [out][in] */DWORD *pCapabilities) = 0;

	virtual HRESULT STDMETHODCALLTYPE IsFormatSupported(
	/* [in] */const GUID *pFormat) = 0;

	virtual HRESULT STDMETHODCALLTYPE QueryPreferredFormat(
	/* [annotation][out] */
	GUID *pFormat) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetTimeFormat(
	/* [annotation][out] */
	GUID *pFormat) = 0;

	virtual HRESULT STDMETHODCALLTYPE IsUsingTimeFormat(
	/* [in] */const GUID *pFormat) = 0;

	virtual HRESULT STDMETHODCALLTYPE SetTimeFormat(
	/* [in] */const GUID *pFormat) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetDuration(
	/* [annotation][out] */
	LONGLONG *pDuration) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetStopPosition(
	/* [annotation][out] */
	LONGLONG *pStop) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetCurrentPosition(
	/* [annotation][out] */
	LONGLONG *pCurrent) = 0;

	virtual HRESULT STDMETHODCALLTYPE ConvertTimeFormat(
	/* [annotation][out] */
	LONGLONG *pTarget,
	/* [annotation][in] */
	const GUID *pTargetFormat,
	/* [in] */LONGLONG Source,
	/* [annotation][in] */
	const GUID *pSourceFormat) = 0;

	virtual HRESULT STDMETHODCALLTYPE SetPositions(
	/* [annotation][out][in] */
	LONGLONG *pCurrent,
	/* [in] */DWORD dwCurrentFlags,
	/* [annotation][out][in] */
	LONGLONG *pStop,
	/* [in] */DWORD dwStopFlags) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetPositions(
	/* [annotation][out] */
	LONGLONG *pCurrent,
	/* [annotation][out] */
	LONGLONG *pStop) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetAvailable(
	/* [annotation][out] */
	LONGLONG *pEarliest,
	/* [annotation][out] */
	LONGLONG *pLatest) = 0;

	virtual HRESULT STDMETHODCALLTYPE SetRate(
	/* [in] */double dRate) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetRate(
	/* [annotation][out] */
	double *pdRate) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetPreroll(
	/* [annotation][out] */
	LONGLONG *pllPreroll) = 0;

};

EXTERN_C const IID IID_IEnumFilters;

struct IEnumFilters: public IUnknown {
public:
	virtual HRESULT STDMETHODCALLTYPE Next(
	/* [in] */ULONG cFilters,
	/* [annotation][out] */
	IBaseFilter **ppFilter,
	/* [annotation][out] */
	ULONG *pcFetched) = 0;

	virtual HRESULT STDMETHODCALLTYPE Skip(
	/* [in] */ULONG cFilters) = 0;

	virtual HRESULT STDMETHODCALLTYPE Reset(void) = 0;

	virtual HRESULT STDMETHODCALLTYPE Clone(
	/* [annotation][out] */
	IEnumFilters **ppEnum) = 0;

};

EXTERN_C const IID IID_IFilterGraph;

struct IFilterGraph: public IUnknown {
public:
	virtual HRESULT STDMETHODCALLTYPE AddFilter(
	/* [in] */IBaseFilter *pFilter,
	/* [string][in] */LPCWSTR pName) = 0;

	virtual HRESULT STDMETHODCALLTYPE RemoveFilter(
	/* [in] */IBaseFilter *pFilter) = 0;

	virtual HRESULT STDMETHODCALLTYPE EnumFilters(
	/* [annotation][out] */
	IEnumFilters **ppEnum) = 0;

	virtual HRESULT STDMETHODCALLTYPE FindFilterByName(
	/* [string][in] */LPCWSTR pName,
	/* [annotation][out] */
	IBaseFilter **ppFilter) = 0;

	virtual HRESULT STDMETHODCALLTYPE ConnectDirect(
	/* [in] */IPin *ppinOut,
	/* [in] */IPin *ppinIn,
	/* [annotation][unique][in] */
	const AM_MEDIA_TYPE *pmt) = 0;

	virtual HRESULT STDMETHODCALLTYPE Reconnect(
	/* [in] */IPin *ppin) = 0;

	virtual HRESULT STDMETHODCALLTYPE Disconnect(
	/* [in] */IPin *ppin) = 0;

	virtual HRESULT STDMETHODCALLTYPE SetDefaultSyncSource(void) = 0;

};


#endif /* DSHOW__H_ */
