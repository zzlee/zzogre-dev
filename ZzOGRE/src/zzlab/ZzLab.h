/*
 * ZzCOM.h
 *
 *  Created on: 2012/11/29
 *      Author: SUCHEN
 */

#ifndef ZZLAB_H_
#define ZZLAB_H_

#include "dshow_i.h"
#include "uuid_i.h"

#include <vector>

#include <boost/utility.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/intrusive_ptr.hpp>
#include <boost/utility.hpp>
#include <boost/type_traits.hpp>

namespace boost {

template<typename T>
inline typename boost::enable_if<boost::is_base_of<IUnknown, T> >::type intrusive_ptr_add_ref(
		T* p) {
//	std::cout << __PRETTY_FUNCTION__ << std::endl;

	p->AddRef();
}

template<typename T>
inline typename boost::enable_if<boost::is_base_of<IUnknown, T> >::type intrusive_ptr_release(
		T* p) {
//	std::cout << __PRETTY_FUNCTION__ << std::endl;

	p->Release();
}

}

#ifndef WIN
#define WIN(e) zzlab::WIN_(e, __FILE__, __LINE__)
#endif

#ifndef HR
#define HR(e) zzlab::HR_(e, __FILE__, __LINE__)
#endif

#ifndef STRINGIZE_NX
#define STRINGIZE_NX(x) #x
#endif

#ifndef STRINGIZE
#define STRINGIZE(x) STRINGIZE_NX(x)
#endif

#define ZZLAB_TYPEDEF_SHARED_PTR(X) typedef boost::shared_ptr<X> X ## Ptr
#define ZZLAB_TYPEDEF_SHARED_PTR1(X, Y) typedef boost::shared_ptr<X> Y ## Ptr
#define ZZLAB_TYPEDEF_COM_PTR(X) typedef boost::intrusive_ptr<X> X ## Ptr

ZZLAB_TYPEDEF_COM_PTR(IUnknown);
ZZLAB_TYPEDEF_COM_PTR(IClassFactory);

ZZLAB_TYPEDEF_COM_PTR(IPersistPropertyBag);
ZZLAB_TYPEDEF_COM_PTR(IPropertyBag);
ZZLAB_TYPEDEF_COM_PTR(IOleObject);
ZZLAB_TYPEDEF_COM_PTR(IOleClientSite);
ZZLAB_TYPEDEF_COM_PTR(IStorage);
ZZLAB_TYPEDEF_COM_PTR(IOleInPlaceObject);
ZZLAB_TYPEDEF_COM_PTR(IOleInPlaceObjectWindowless);
ZZLAB_TYPEDEF_COM_PTR(IViewObject);
ZZLAB_TYPEDEF_COM_PTR(IShockwaveFlash);
ZZLAB_TYPEDEF_COM_PTR(IConnectionPoint);
ZZLAB_TYPEDEF_COM_PTR(IConnectionPointContainer);
ZZLAB_TYPEDEF_COM_PTR(IBaseFilter);
ZZLAB_TYPEDEF_COM_PTR(IEnumPins);
ZZLAB_TYPEDEF_COM_PTR(IPin);
ZZLAB_TYPEDEF_COM_PTR(IMemInputPin);
ZZLAB_TYPEDEF_COM_PTR(IMemAllocator);
ZZLAB_TYPEDEF_COM_PTR(IVideoWindow);
ZZLAB_TYPEDEF_COM_PTR(IMediaSeeking);
ZZLAB_TYPEDEF_COM_PTR(IDispatch);
ZZLAB_TYPEDEF_COM_PTR(IDataObject);
ZZLAB_TYPEDEF_COM_PTR(IAdviseSink);
ZZLAB_TYPEDEF_COM_PTR(IFilterGraph);

namespace zzlab {

extern void WIN_(DWORD err, const char* file, int line);
extern void HR_(HRESULT err, const char* file, int line);
extern std::string handlePythonError();

extern void initialize();
extern void uninitialize();

class RegisterInitializer {
public:
	typedef void (*Initializer)();
	typedef void (*Deinitializer)();

	RegisterInitializer(Initializer init, Deinitializer deinit);
};

} /* namespace zzlab */

#endif /* ZZLAB_H_ */
