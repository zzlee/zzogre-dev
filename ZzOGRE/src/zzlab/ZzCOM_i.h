

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Mon Apr 29 15:50:52 2013
 */
/* Compiler settings for .\ZzCOM.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ZzCOM_i_h__
#define __ZzCOM_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISharedMemory_FWD_DEFINED__
#define __ISharedMemory_FWD_DEFINED__
typedef interface ISharedMemory ISharedMemory;
#endif 	/* __ISharedMemory_FWD_DEFINED__ */


#ifndef __ISharedMemoryFactory_FWD_DEFINED__
#define __ISharedMemoryFactory_FWD_DEFINED__
typedef interface ISharedMemoryFactory ISharedMemoryFactory;
#endif 	/* __ISharedMemoryFactory_FWD_DEFINED__ */


#ifndef __ISharedMemoryQueue_FWD_DEFINED__
#define __ISharedMemoryQueue_FWD_DEFINED__
typedef interface ISharedMemoryQueue ISharedMemoryQueue;
#endif 	/* __ISharedMemoryQueue_FWD_DEFINED__ */


#ifndef __IClock_FWD_DEFINED__
#define __IClock_FWD_DEFINED__
typedef interface IClock IClock;
#endif 	/* __IClock_FWD_DEFINED__ */


#ifndef __IDetours_FWD_DEFINED__
#define __IDetours_FWD_DEFINED__
typedef interface IDetours IDetours;
#endif 	/* __IDetours_FWD_DEFINED__ */


#ifndef __ISharedImage_FWD_DEFINED__
#define __ISharedImage_FWD_DEFINED__
typedef interface ISharedImage ISharedImage;
#endif 	/* __ISharedImage_FWD_DEFINED__ */


#ifndef __ISharedVideo_FWD_DEFINED__
#define __ISharedVideo_FWD_DEFINED__
typedef interface ISharedVideo ISharedVideo;
#endif 	/* __ISharedVideo_FWD_DEFINED__ */


#ifndef __ISharedQueue_FWD_DEFINED__
#define __ISharedQueue_FWD_DEFINED__
typedef interface ISharedQueue ISharedQueue;
#endif 	/* __ISharedQueue_FWD_DEFINED__ */


#ifndef __IEnumSharedMemoryNames_FWD_DEFINED__
#define __IEnumSharedMemoryNames_FWD_DEFINED__
typedef interface IEnumSharedMemoryNames IEnumSharedMemoryNames;
#endif 	/* __IEnumSharedMemoryNames_FWD_DEFINED__ */


#ifndef __ISimpleTimer_FWD_DEFINED__
#define __ISimpleTimer_FWD_DEFINED__
typedef interface ISimpleTimer ISimpleTimer;
#endif 	/* __ISimpleTimer_FWD_DEFINED__ */


#ifndef __ID3D9Surface_FWD_DEFINED__
#define __ID3D9Surface_FWD_DEFINED__
typedef interface ID3D9Surface ID3D9Surface;
#endif 	/* __ID3D9Surface_FWD_DEFINED__ */


#ifndef __ID3D9Texture_FWD_DEFINED__
#define __ID3D9Texture_FWD_DEFINED__
typedef interface ID3D9Texture ID3D9Texture;
#endif 	/* __ID3D9Texture_FWD_DEFINED__ */


#ifndef __IDshowMediaPlayer_FWD_DEFINED__
#define __IDshowMediaPlayer_FWD_DEFINED__
typedef interface IDshowMediaPlayer IDshowMediaPlayer;
#endif 	/* __IDshowMediaPlayer_FWD_DEFINED__ */


#ifndef __ILAVMediaPlayer_FWD_DEFINED__
#define __ILAVMediaPlayer_FWD_DEFINED__
typedef interface ILAVMediaPlayer ILAVMediaPlayer;
#endif 	/* __ILAVMediaPlayer_FWD_DEFINED__ */


#ifndef __IAlphaMediaPlayer_FWD_DEFINED__
#define __IAlphaMediaPlayer_FWD_DEFINED__
typedef interface IAlphaMediaPlayer IAlphaMediaPlayer;
#endif 	/* __IAlphaMediaPlayer_FWD_DEFINED__ */


#ifndef __IMediaPlayer_FWD_DEFINED__
#define __IMediaPlayer_FWD_DEFINED__
typedef interface IMediaPlayer IMediaPlayer;
#endif 	/* __IMediaPlayer_FWD_DEFINED__ */


#ifndef __IDevIL_FWD_DEFINED__
#define __IDevIL_FWD_DEFINED__
typedef interface IDevIL IDevIL;
#endif 	/* __IDevIL_FWD_DEFINED__ */


#ifndef __IPendingImage_FWD_DEFINED__
#define __IPendingImage_FWD_DEFINED__
typedef interface IPendingImage IPendingImage;
#endif 	/* __IPendingImage_FWD_DEFINED__ */


#ifndef __IImageLoader_FWD_DEFINED__
#define __IImageLoader_FWD_DEFINED__
typedef interface IImageLoader IImageLoader;
#endif 	/* __IImageLoader_FWD_DEFINED__ */


#ifndef __IParallelBox_FWD_DEFINED__
#define __IParallelBox_FWD_DEFINED__
typedef interface IParallelBox IParallelBox;
#endif 	/* __IParallelBox_FWD_DEFINED__ */


#ifndef __IEB3FileLoader_FWD_DEFINED__
#define __IEB3FileLoader_FWD_DEFINED__
typedef interface IEB3FileLoader IEB3FileLoader;
#endif 	/* __IEB3FileLoader_FWD_DEFINED__ */


#ifndef __ISyncClock_FWD_DEFINED__
#define __ISyncClock_FWD_DEFINED__
typedef interface ISyncClock ISyncClock;
#endif 	/* __ISyncClock_FWD_DEFINED__ */


#ifndef __IRegularClock_FWD_DEFINED__
#define __IRegularClock_FWD_DEFINED__
typedef interface IRegularClock IRegularClock;
#endif 	/* __IRegularClock_FWD_DEFINED__ */


#ifndef __IDshowVideoCaptureSource_FWD_DEFINED__
#define __IDshowVideoCaptureSource_FWD_DEFINED__
typedef interface IDshowVideoCaptureSource IDshowVideoCaptureSource;
#endif 	/* __IDshowVideoCaptureSource_FWD_DEFINED__ */


#ifndef __IEnumVideoCaptureSources_FWD_DEFINED__
#define __IEnumVideoCaptureSources_FWD_DEFINED__
typedef interface IEnumVideoCaptureSources IEnumVideoCaptureSources;
#endif 	/* __IEnumVideoCaptureSources_FWD_DEFINED__ */


#ifndef __IStaticClock_FWD_DEFINED__
#define __IStaticClock_FWD_DEFINED__
typedef interface IStaticClock IStaticClock;
#endif 	/* __IStaticClock_FWD_DEFINED__ */


#ifndef __IDIMager_FWD_DEFINED__
#define __IDIMager_FWD_DEFINED__
typedef interface IDIMager IDIMager;
#endif 	/* __IDIMager_FWD_DEFINED__ */


#ifndef __IFFmpegVideoPlayer_FWD_DEFINED__
#define __IFFmpegVideoPlayer_FWD_DEFINED__
typedef interface IFFmpegVideoPlayer IFFmpegVideoPlayer;
#endif 	/* __IFFmpegVideoPlayer_FWD_DEFINED__ */


#ifndef __IVideoStreamPlayer_FWD_DEFINED__
#define __IVideoStreamPlayer_FWD_DEFINED__
typedef interface IVideoStreamPlayer IVideoStreamPlayer;
#endif 	/* __IVideoStreamPlayer_FWD_DEFINED__ */


#ifndef __IRoot_FWD_DEFINED__
#define __IRoot_FWD_DEFINED__
typedef interface IRoot IRoot;
#endif 	/* __IRoot_FWD_DEFINED__ */


#ifndef __SharedMemoryFactory_FWD_DEFINED__
#define __SharedMemoryFactory_FWD_DEFINED__

#ifdef __cplusplus
typedef class SharedMemoryFactory SharedMemoryFactory;
#else
typedef struct SharedMemoryFactory SharedMemoryFactory;
#endif /* __cplusplus */

#endif 	/* __SharedMemoryFactory_FWD_DEFINED__ */


#ifndef __SharedMemoryQueue_FWD_DEFINED__
#define __SharedMemoryQueue_FWD_DEFINED__

#ifdef __cplusplus
typedef class SharedMemoryQueue SharedMemoryQueue;
#else
typedef struct SharedMemoryQueue SharedMemoryQueue;
#endif /* __cplusplus */

#endif 	/* __SharedMemoryQueue_FWD_DEFINED__ */


#ifndef __SharedMemory_FWD_DEFINED__
#define __SharedMemory_FWD_DEFINED__

#ifdef __cplusplus
typedef class SharedMemory SharedMemory;
#else
typedef struct SharedMemory SharedMemory;
#endif /* __cplusplus */

#endif 	/* __SharedMemory_FWD_DEFINED__ */


#ifndef __Root_FWD_DEFINED__
#define __Root_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZzRoot ZzRoot;
#else
typedef struct Root Root;
#endif /* __cplusplus */

#endif 	/* __Root_FWD_DEFINED__ */


#ifndef __Detours_FWD_DEFINED__
#define __Detours_FWD_DEFINED__

#ifdef __cplusplus
typedef class Detours Detours;
#else
typedef struct Detours Detours;
#endif /* __cplusplus */

#endif 	/* __Detours_FWD_DEFINED__ */


#ifndef __SharedImage_FWD_DEFINED__
#define __SharedImage_FWD_DEFINED__

#ifdef __cplusplus
typedef class SharedImage SharedImage;
#else
typedef struct SharedImage SharedImage;
#endif /* __cplusplus */

#endif 	/* __SharedImage_FWD_DEFINED__ */


#ifndef __EnumSharedMemoryNames_FWD_DEFINED__
#define __EnumSharedMemoryNames_FWD_DEFINED__

#ifdef __cplusplus
typedef class EnumSharedMemoryNames EnumSharedMemoryNames;
#else
typedef struct EnumSharedMemoryNames EnumSharedMemoryNames;
#endif /* __cplusplus */

#endif 	/* __EnumSharedMemoryNames_FWD_DEFINED__ */


#ifndef __SharedQueue_FWD_DEFINED__
#define __SharedQueue_FWD_DEFINED__

#ifdef __cplusplus
typedef class SharedQueue SharedQueue;
#else
typedef struct SharedQueue SharedQueue;
#endif /* __cplusplus */

#endif 	/* __SharedQueue_FWD_DEFINED__ */


#ifndef __SimpleTimer_FWD_DEFINED__
#define __SimpleTimer_FWD_DEFINED__

#ifdef __cplusplus
typedef class SimpleTimer SimpleTimer;
#else
typedef struct SimpleTimer SimpleTimer;
#endif /* __cplusplus */

#endif 	/* __SimpleTimer_FWD_DEFINED__ */


#ifndef __OneShotTimer_FWD_DEFINED__
#define __OneShotTimer_FWD_DEFINED__

#ifdef __cplusplus
typedef class OneShotTimer OneShotTimer;
#else
typedef struct OneShotTimer OneShotTimer;
#endif /* __cplusplus */

#endif 	/* __OneShotTimer_FWD_DEFINED__ */


#ifndef __DshowMediaPlayer_FWD_DEFINED__
#define __DshowMediaPlayer_FWD_DEFINED__

#ifdef __cplusplus
typedef class DshowMediaPlayer DshowMediaPlayer;
#else
typedef struct DshowMediaPlayer DshowMediaPlayer;
#endif /* __cplusplus */

#endif 	/* __DshowMediaPlayer_FWD_DEFINED__ */


#ifndef __DevIL_FWD_DEFINED__
#define __DevIL_FWD_DEFINED__

#ifdef __cplusplus
typedef class DevIL DevIL;
#else
typedef struct DevIL DevIL;
#endif /* __cplusplus */

#endif 	/* __DevIL_FWD_DEFINED__ */


#ifndef __ImageLoader_FWD_DEFINED__
#define __ImageLoader_FWD_DEFINED__

#ifdef __cplusplus
typedef class ImageLoader ImageLoader;
#else
typedef struct ImageLoader ImageLoader;
#endif /* __cplusplus */

#endif 	/* __ImageLoader_FWD_DEFINED__ */


#ifndef __PendingImage_FWD_DEFINED__
#define __PendingImage_FWD_DEFINED__

#ifdef __cplusplus
typedef class PendingImage PendingImage;
#else
typedef struct PendingImage PendingImage;
#endif /* __cplusplus */

#endif 	/* __PendingImage_FWD_DEFINED__ */


#ifndef __SharedVideo_FWD_DEFINED__
#define __SharedVideo_FWD_DEFINED__

#ifdef __cplusplus
typedef class SharedVideo SharedVideo;
#else
typedef struct SharedVideo SharedVideo;
#endif /* __cplusplus */

#endif 	/* __SharedVideo_FWD_DEFINED__ */


#ifndef __MediaClock_FWD_DEFINED__
#define __MediaClock_FWD_DEFINED__

#ifdef __cplusplus
typedef class MediaClock MediaClock;
#else
typedef struct MediaClock MediaClock;
#endif /* __cplusplus */

#endif 	/* __MediaClock_FWD_DEFINED__ */


#ifndef __HiResClock_FWD_DEFINED__
#define __HiResClock_FWD_DEFINED__

#ifdef __cplusplus
typedef class HiResClock HiResClock;
#else
typedef struct HiResClock HiResClock;
#endif /* __cplusplus */

#endif 	/* __HiResClock_FWD_DEFINED__ */


#ifndef __SyncClock_FWD_DEFINED__
#define __SyncClock_FWD_DEFINED__

#ifdef __cplusplus
typedef class SyncClock SyncClock;
#else
typedef struct SyncClock SyncClock;
#endif /* __cplusplus */

#endif 	/* __SyncClock_FWD_DEFINED__ */


#ifndef __RegularClock_FWD_DEFINED__
#define __RegularClock_FWD_DEFINED__

#ifdef __cplusplus
typedef class RegularClock RegularClock;
#else
typedef struct RegularClock RegularClock;
#endif /* __cplusplus */

#endif 	/* __RegularClock_FWD_DEFINED__ */


#ifndef __ID3D9Texture_FWD_DEFINED__
#define __ID3D9Texture_FWD_DEFINED__
typedef interface ID3D9Texture ID3D9Texture;
#endif 	/* __ID3D9Texture_FWD_DEFINED__ */


#ifndef __ID3D9Surface_FWD_DEFINED__
#define __ID3D9Surface_FWD_DEFINED__
typedef interface ID3D9Surface ID3D9Surface;
#endif 	/* __ID3D9Surface_FWD_DEFINED__ */


#ifndef __IStaticClock_FWD_DEFINED__
#define __IStaticClock_FWD_DEFINED__
typedef interface IStaticClock IStaticClock;
#endif 	/* __IStaticClock_FWD_DEFINED__ */


#ifndef __ParallelBox_FWD_DEFINED__
#define __ParallelBox_FWD_DEFINED__

#ifdef __cplusplus
typedef class ParallelBox ParallelBox;
#else
typedef struct ParallelBox ParallelBox;
#endif /* __cplusplus */

#endif 	/* __ParallelBox_FWD_DEFINED__ */


#ifndef __NativeClock_FWD_DEFINED__
#define __NativeClock_FWD_DEFINED__

#ifdef __cplusplus
typedef class NativeClock NativeClock;
#else
typedef struct NativeClock NativeClock;
#endif /* __cplusplus */

#endif 	/* __NativeClock_FWD_DEFINED__ */


#ifndef __EB3FileLoader_FWD_DEFINED__
#define __EB3FileLoader_FWD_DEFINED__

#ifdef __cplusplus
typedef class EB3FileLoader EB3FileLoader;
#else
typedef struct EB3FileLoader EB3FileLoader;
#endif /* __cplusplus */

#endif 	/* __EB3FileLoader_FWD_DEFINED__ */


#ifndef __DshowVideoCaptureSource_FWD_DEFINED__
#define __DshowVideoCaptureSource_FWD_DEFINED__

#ifdef __cplusplus
typedef class DshowVideoCaptureSource DshowVideoCaptureSource;
#else
typedef struct DshowVideoCaptureSource DshowVideoCaptureSource;
#endif /* __cplusplus */

#endif 	/* __DshowVideoCaptureSource_FWD_DEFINED__ */


#ifndef __EnumVideoCaptureSources_FWD_DEFINED__
#define __EnumVideoCaptureSources_FWD_DEFINED__

#ifdef __cplusplus
typedef class EnumVideoCaptureSources EnumVideoCaptureSources;
#else
typedef struct EnumVideoCaptureSources EnumVideoCaptureSources;
#endif /* __cplusplus */

#endif 	/* __EnumVideoCaptureSources_FWD_DEFINED__ */


#ifndef __StaticClock_FWD_DEFINED__
#define __StaticClock_FWD_DEFINED__

#ifdef __cplusplus
typedef class StaticClock StaticClock;
#else
typedef struct StaticClock StaticClock;
#endif /* __cplusplus */

#endif 	/* __StaticClock_FWD_DEFINED__ */


#ifndef __DIMager_FWD_DEFINED__
#define __DIMager_FWD_DEFINED__

#ifdef __cplusplus
typedef class DIMager DIMager;
#else
typedef struct DIMager DIMager;
#endif /* __cplusplus */

#endif 	/* __DIMager_FWD_DEFINED__ */


#ifndef __FFmpegVideoPlayer_FWD_DEFINED__
#define __FFmpegVideoPlayer_FWD_DEFINED__

#ifdef __cplusplus
typedef class FFmpegVideoPlayer FFmpegVideoPlayer;
#else
typedef struct FFmpegVideoPlayer FFmpegVideoPlayer;
#endif /* __cplusplus */

#endif 	/* __FFmpegVideoPlayer_FWD_DEFINED__ */


#ifndef __VideoStreamPlayer_FWD_DEFINED__
#define __VideoStreamPlayer_FWD_DEFINED__

#ifdef __cplusplus
typedef class VideoStreamPlayer VideoStreamPlayer;
#else
typedef struct VideoStreamPlayer VideoStreamPlayer;
#endif /* __cplusplus */

#endif 	/* __VideoStreamPlayer_FWD_DEFINED__ */


#ifndef __LAVMediaPlayer_FWD_DEFINED__
#define __LAVMediaPlayer_FWD_DEFINED__

#ifdef __cplusplus
typedef class LAVMediaPlayer LAVMediaPlayer;
#else
typedef struct LAVMediaPlayer LAVMediaPlayer;
#endif /* __cplusplus */

#endif 	/* __LAVMediaPlayer_FWD_DEFINED__ */


#ifndef __AlphaMediaPlayer_FWD_DEFINED__
#define __AlphaMediaPlayer_FWD_DEFINED__

#ifdef __cplusplus
typedef class AlphaMediaPlayer AlphaMediaPlayer;
#else
typedef struct AlphaMediaPlayer AlphaMediaPlayer;
#endif /* __cplusplus */

#endif 	/* __AlphaMediaPlayer_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_ZzCOM_0000_0000 */
/* [local] */ 

typedef 
enum MemoryType
    {	MemoryType_Unknown	= 0,
	MemoryType_Predefined	= 0x8000,
	MemoryType_Raw	= ( MemoryType_Predefined + 1 ) ,
	MemoryType_ANSIString	= ( MemoryType_Raw + 1 ) ,
	MemoryType_UnicodeString	= ( MemoryType_ANSIString + 1 ) ,
	MemoryType_MemoryQueue	= ( MemoryType_UnicodeString + 1 ) ,
	MemoryType_Image	= ( MemoryType_MemoryQueue + 1 ) ,
	MemoryType_Queue	= ( MemoryType_Image + 1 ) ,
	MemoryType_Video	= ( MemoryType_Queue + 1 ) 
    } 	MemoryType_t;

typedef struct MemoryInfo
    {
    LONG_PTR Pointer;
    LONG Size;
    } 	MemoryInfo_t;

typedef 
enum ImageType
    {	ImageType_Unknown	= 0,
	ImageType_Predefined	= 0x8000,
	ImageType_Gray	= ( ImageType_Predefined + 1 ) ,
	ImageType_BGR	= ( ImageType_Gray + 1 ) ,
	ImageType_BGRA	= ( ImageType_BGR + 1 ) ,
	ImageType_BGRX	= ( ImageType_BGRA + 1 ) ,
	ImageType_RGB	= ( ImageType_BGRX + 1 ) ,
	ImageType_RGBA	= ( ImageType_RGB + 1 ) ,
	ImageType_RGBX	= ( ImageType_RGBA + 1 ) ,
	ImageType_U16	= ( ImageType_RGBX + 1 ) ,
	ImageType_YUY2	= ( ImageType_U16 + 1 ) ,
	ImageType_YV12	= ( ImageType_YUY2 + 1 ) ,
	ImageType_I420	= ( ImageType_YV12 + 1 ) 
    } 	ImageType_t;

typedef 
enum ROP
    {	ROP_SRCCOPY	= 0xcc0020,
	ROP_SRCPAINT	= 0xee0086,
	ROP_SRCAND	= 0x8800c6,
	ROP_SRCINVERT	= 0x660046,
	ROP_SRCERASE	= 0x440328,
	ROP_NOTSRCCOPY	= 0x330008,
	ROP_NOTSRCERASE	= 0x1100a6,
	ROP_MERGECOPY	= 0xc000ca,
	ROP_MERGEPAINT	= 0xbb0226,
	ROP_PATCOPY	= 0xf00021,
	ROP_PATPAINT	= 0xfb0a09,
	ROP_PATINVERT	= 0x5a0049,
	ROP_DSTINVERT	= 0x550009,
	ROP_BLACKNESS	= 0x42,
	ROP_WHITENESS	= 0xff0062
    } 	ROP_t;

typedef struct Size
    {
    LONG Width;
    LONG Height;
    } 	Size_t;

typedef struct Point
    {
    LONG X;
    LONG Y;
    } 	Point_t;

typedef struct ImageInfo
    {
    LONG_PTR Pointer;
    LONG Step;
    } 	ImageInfo_t;

typedef struct BitmapInfo
    {
    LONG BitCount;
    LONG Width;
    LONG Height;
    } 	BitmapInfo_t;

typedef struct Rect
    {
    LONG X;
    LONG Y;
    LONG Width;
    LONG Height;
    } 	Rect_t;

typedef struct VideoType
    {
    Size_t Size;
    ImageType_t Type;
    float FPS;
    } 	VideoType_t;

typedef 
enum D3DFormat
    {	D3DFormat_R8G8B8	= 20,
	D3DFormat_A8R8G8B8	= 21,
	D3DFormat_X8R8G8B8	= 22,
	D3DFormat_A8	= 28,
	D3DFormat_L8	= 50,
	D3DFormat_L16	= 81,
	D3DFormat_G16R16	= 34
    } 	D3DFormat_t;

typedef 
enum D3DResourceType
    {	D3DResourceType_SURFACE	= 1,
	D3DResourceType_VOLUME	= 2,
	D3DResourceType_TEXTURE	= 3,
	D3DResourceType_VOLUMETEXTURE	= 4,
	D3DResourceType_CubeTexture	= 5,
	D3DResourceType_VERTEXBUFFER	= 6,
	D3DResourceType_INDEXBUFFER	= 7,
	D3DResourceType_FORCE_DWORD	= 0x7fffffff
    } 	D3DResourceType_t;

typedef 
enum D3DMultiSampleType
    {	D3DMultiSampleType_NONE	= 0,
	D3DMultiSampleType_NONMASKABLE	= 1,
	D3DMultiSampleType_2_SAMPLES	= 2,
	D3DMultiSampleType_3_SAMPLES	= 3,
	D3DMultiSampleType_4_SAMPLES	= 4,
	D3DMultiSampleType_5_SAMPLES	= 5,
	D3DMultiSampleType_6_SAMPLES	= 6,
	D3DMultiSampleType_7_SAMPLES	= 7,
	D3DMultiSampleType_8_SAMPLES	= 8,
	D3DMultiSampleType_9_SAMPLES	= 9,
	D3DMultiSampleType_10_SAMPLES	= 10,
	D3DMultiSampleType_11_SAMPLES	= 11,
	D3DMultiSampleType_12_SAMPLES	= 12,
	D3DMultiSampleType_13_SAMPLES	= 13,
	D3DMultiSampleType_14_SAMPLES	= 14,
	D3DMultiSampleType_15_SAMPLES	= 15,
	D3DMultiSampleType_16_SAMPLES	= 16,
	D3DMultiSampleType_FORCE_DWORD	= 0xffffffff
    } 	D3DMultiSampleType_t;

typedef 
enum D3DPool
    {	D3DPool_DEFAULT	= 0,
	D3DPool_MANAGED	= 1,
	D3DPool_SYSTEMMEM	= 2,
	D3DPool_SCRATCH	= 3,
	D3DPool_FORCE_DWORD	= 0x7fffffff
    } 	D3DPool_t;

typedef struct D3DSurfaceDesc
    {
    D3DFormat_t Format;
    D3DResourceType_t Type;
    DWORD Usage;
    D3DPool_t Pool;
    D3DMultiSampleType_t MultiSampleType;
    DWORD MultiSampleQuality;
    UINT Width;
    UINT Height;
    } 	D3DSurfaceDesc_t;

typedef 
enum D3DLock
    {	D3DLock_DISCARD	= 0x2000L,
	D3DLock_NO_DIRTY_UPDATE	= 0x8000L,
	D3DLock_NOSYSLOCK	= 0x800L,
	D3DLock_READONLY	= 0x10L
    } 	D3DLock_t;

typedef 
enum ILImageParamters
    {	ILU_Filter	= 0x2600,
	ILU_Nearest	= 0x2601,
	ILU_Linear	= 0x2602,
	ILU_Bilinear	= 0x2603,
	ILU_ScaleBox	= 0x2604,
	ILU_ScaleTriangle	= 0x2605,
	ILU_ScaleBell	= 0x2606,
	ILU_ScaleBspline	= 0x2607,
	ILU_ScaleLanczos3	= 0x2608,
	ILU_ScaleMitchell	= 0x2609
    } 	ILImageParamters_t;

typedef 
enum AV_MediaType
    {	AV_MediaType_Unknown	= -1,
	AV_MediaType_Video	= ( AV_MediaType_Unknown + 1 ) ,
	AV_MediaType_Audio	= ( AV_MediaType_Video + 1 ) 
    } 	AV_MediaType_t;

typedef 
enum AV_PixelFormat
    {	AV_PixelFormat_Unknown	= -1,
	AV_PixelFormat_YUV420P	= ( AV_PixelFormat_Unknown + 1 ) ,
	AV_PixelFormat_YUVA420P	= ( AV_PixelFormat_YUV420P + 1 ) 
    } 	AV_PixelFormat_t;

typedef 
enum AV_PlayerState
    {	AV_Player_Ready	= 0,
	AV_Player_Playing	= ( AV_Player_Ready + 1 ) ,
	AV_Player_Pause	= ( AV_Player_Playing + 1 ) ,
	AV_Player_EndOfStream	= ( AV_Player_Pause + 1 ) ,
	AV_Player_Stop	= ( AV_Player_EndOfStream + 1 ) 
    } 	AV_PlayerState_t;



extern RPC_IF_HANDLE __MIDL_itf_ZzCOM_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ZzCOM_0000_0000_v0_0_s_ifspec;

#ifndef __ISharedMemory_INTERFACE_DEFINED__
#define __ISharedMemory_INTERFACE_DEFINED__

/* interface ISharedMemory */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISharedMemory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EAF19CC9-62E1-4B64-A2EA-9A69D6C93860")
    ISharedMemory : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ MemoryType_t *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LockBuffer( 
            /* [retval][out] */ MemoryInfo_t *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnlockBuffer( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISharedMemoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISharedMemory * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISharedMemory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISharedMemory * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISharedMemory * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISharedMemory * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISharedMemory * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISharedMemory * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            ISharedMemory * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            ISharedMemory * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            ISharedMemory * This,
            /* [retval][out] */ MemoryType_t *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LockBuffer )( 
            ISharedMemory * This,
            /* [retval][out] */ MemoryInfo_t *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnlockBuffer )( 
            ISharedMemory * This);
        
        END_INTERFACE
    } ISharedMemoryVtbl;

    interface ISharedMemory
    {
        CONST_VTBL struct ISharedMemoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISharedMemory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISharedMemory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISharedMemory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISharedMemory_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISharedMemory_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISharedMemory_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISharedMemory_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISharedMemory_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define ISharedMemory_get_Size(This,pVal)	\
    ( (This)->lpVtbl -> get_Size(This,pVal) ) 

#define ISharedMemory_get_Type(This,pVal)	\
    ( (This)->lpVtbl -> get_Type(This,pVal) ) 

#define ISharedMemory_LockBuffer(This,pVal)	\
    ( (This)->lpVtbl -> LockBuffer(This,pVal) ) 

#define ISharedMemory_UnlockBuffer(This)	\
    ( (This)->lpVtbl -> UnlockBuffer(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISharedMemory_INTERFACE_DEFINED__ */


#ifndef __ISharedMemoryFactory_INTERFACE_DEFINED__
#define __ISharedMemoryFactory_INTERFACE_DEFINED__

/* interface ISharedMemoryFactory */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISharedMemoryFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("549BE534-6ECC-45B9-BE7F-3C6481A5EA58")
    ISharedMemoryFactory : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ MemoryType_t *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Use( 
            /* [in] */ BSTR name,
            /* [retval][out] */ ISharedMemory **ret) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISharedMemoryFactoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISharedMemoryFactory * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISharedMemoryFactory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISharedMemoryFactory * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISharedMemoryFactory * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISharedMemoryFactory * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISharedMemoryFactory * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISharedMemoryFactory * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            ISharedMemoryFactory * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            ISharedMemoryFactory * This,
            /* [retval][out] */ MemoryType_t *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Use )( 
            ISharedMemoryFactory * This,
            /* [in] */ BSTR name,
            /* [retval][out] */ ISharedMemory **ret);
        
        END_INTERFACE
    } ISharedMemoryFactoryVtbl;

    interface ISharedMemoryFactory
    {
        CONST_VTBL struct ISharedMemoryFactoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISharedMemoryFactory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISharedMemoryFactory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISharedMemoryFactory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISharedMemoryFactory_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISharedMemoryFactory_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISharedMemoryFactory_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISharedMemoryFactory_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISharedMemoryFactory_get_Size(This,pVal)	\
    ( (This)->lpVtbl -> get_Size(This,pVal) ) 

#define ISharedMemoryFactory_get_Type(This,pVal)	\
    ( (This)->lpVtbl -> get_Type(This,pVal) ) 

#define ISharedMemoryFactory_Use(This,name,ret)	\
    ( (This)->lpVtbl -> Use(This,name,ret) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISharedMemoryFactory_INTERFACE_DEFINED__ */


#ifndef __ISharedMemoryQueue_INTERFACE_DEFINED__
#define __ISharedMemoryQueue_INTERFACE_DEFINED__

/* interface ISharedMemoryQueue */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISharedMemoryQueue;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("91348C1D-5DC4-4752-99EE-8B7BCC434932")
    ISharedMemoryQueue : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Capacity( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BeginPush( 
            /* [retval][out] */ ISharedMemory **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EndPush( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BeginPop( 
            /* [retval][out] */ ISharedMemory **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EndPop( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Cancel( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Cancel( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ LONG *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISharedMemoryQueueVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISharedMemoryQueue * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISharedMemoryQueue * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISharedMemoryQueue * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISharedMemoryQueue * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISharedMemoryQueue * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISharedMemoryQueue * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISharedMemoryQueue * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Capacity )( 
            ISharedMemoryQueue * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BeginPush )( 
            ISharedMemoryQueue * This,
            /* [retval][out] */ ISharedMemory **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EndPush )( 
            ISharedMemoryQueue * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BeginPop )( 
            ISharedMemoryQueue * This,
            /* [retval][out] */ ISharedMemory **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EndPop )( 
            ISharedMemoryQueue * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Cancel )( 
            ISharedMemoryQueue * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Cancel )( 
            ISharedMemoryQueue * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            ISharedMemoryQueue * This,
            /* [retval][out] */ LONG *pVal);
        
        END_INTERFACE
    } ISharedMemoryQueueVtbl;

    interface ISharedMemoryQueue
    {
        CONST_VTBL struct ISharedMemoryQueueVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISharedMemoryQueue_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISharedMemoryQueue_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISharedMemoryQueue_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISharedMemoryQueue_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISharedMemoryQueue_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISharedMemoryQueue_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISharedMemoryQueue_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISharedMemoryQueue_get_Capacity(This,pVal)	\
    ( (This)->lpVtbl -> get_Capacity(This,pVal) ) 

#define ISharedMemoryQueue_BeginPush(This,ret)	\
    ( (This)->lpVtbl -> BeginPush(This,ret) ) 

#define ISharedMemoryQueue_EndPush(This)	\
    ( (This)->lpVtbl -> EndPush(This) ) 

#define ISharedMemoryQueue_BeginPop(This,ret)	\
    ( (This)->lpVtbl -> BeginPop(This,ret) ) 

#define ISharedMemoryQueue_EndPop(This)	\
    ( (This)->lpVtbl -> EndPop(This) ) 

#define ISharedMemoryQueue_get_Cancel(This,pVal)	\
    ( (This)->lpVtbl -> get_Cancel(This,pVal) ) 

#define ISharedMemoryQueue_put_Cancel(This,newVal)	\
    ( (This)->lpVtbl -> put_Cancel(This,newVal) ) 

#define ISharedMemoryQueue_get_Size(This,pVal)	\
    ( (This)->lpVtbl -> get_Size(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISharedMemoryQueue_INTERFACE_DEFINED__ */


#ifndef __IClock_INTERFACE_DEFINED__
#define __IClock_INTERFACE_DEFINED__

/* interface IClock */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IClock;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CB6389AA-502C-46e6-ACBF-BAE87B7A360C")
    IClock : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Now( 
            /* [retval][out] */ LONGLONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Milliseconds( 
            /* [retval][out] */ DWORD *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClockVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClock * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClock * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClock * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IClock * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IClock * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IClock * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IClock * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Now )( 
            IClock * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Milliseconds )( 
            IClock * This,
            /* [retval][out] */ DWORD *pVal);
        
        END_INTERFACE
    } IClockVtbl;

    interface IClock
    {
        CONST_VTBL struct IClockVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClock_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IClock_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IClock_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IClock_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IClock_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IClock_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IClock_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IClock_get_Now(This,pVal)	\
    ( (This)->lpVtbl -> get_Now(This,pVal) ) 

#define IClock_get_Milliseconds(This,pVal)	\
    ( (This)->lpVtbl -> get_Milliseconds(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IClock_INTERFACE_DEFINED__ */


#ifndef __IDetours_INTERFACE_DEFINED__
#define __IDetours_INTERFACE_DEFINED__

/* interface IDetours */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDetours;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DBFB4A19-2AD6-4E0E-B5CC-AE040A5B91B2")
    IDetours : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Begin( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Commit( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Attach( 
            /* [in] */ LONG_PTR real,
            /* [in] */ LONG_PTR hook,
            /* [retval][out] */ LONG_PTR *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Detach( 
            /* [in] */ LONG_PTR real,
            /* [in] */ LONG_PTR hook) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDetoursVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDetours * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDetours * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDetours * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDetours * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDetours * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDetours * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDetours * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Begin )( 
            IDetours * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Commit )( 
            IDetours * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Attach )( 
            IDetours * This,
            /* [in] */ LONG_PTR real,
            /* [in] */ LONG_PTR hook,
            /* [retval][out] */ LONG_PTR *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Detach )( 
            IDetours * This,
            /* [in] */ LONG_PTR real,
            /* [in] */ LONG_PTR hook);
        
        END_INTERFACE
    } IDetoursVtbl;

    interface IDetours
    {
        CONST_VTBL struct IDetoursVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDetours_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDetours_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDetours_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDetours_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDetours_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDetours_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDetours_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDetours_Begin(This)	\
    ( (This)->lpVtbl -> Begin(This) ) 

#define IDetours_Commit(This)	\
    ( (This)->lpVtbl -> Commit(This) ) 

#define IDetours_Attach(This,real,hook,ret)	\
    ( (This)->lpVtbl -> Attach(This,real,hook,ret) ) 

#define IDetours_Detach(This,real,hook)	\
    ( (This)->lpVtbl -> Detach(This,real,hook) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDetours_INTERFACE_DEFINED__ */


#ifndef __ISharedImage_INTERFACE_DEFINED__
#define __ISharedImage_INTERFACE_DEFINED__

/* interface ISharedImage */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISharedImage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("37A00AAC-7F13-4E7C-8603-AF7359140B4E")
    ISharedImage : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ ImageType_t *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ Size_t *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LockImage( 
            /* [retval][out] */ ImageInfo_t *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnlockImage( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISharedImageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISharedImage * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISharedImage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISharedImage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISharedImage * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISharedImage * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISharedImage * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISharedImage * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            ISharedImage * This,
            /* [retval][out] */ ImageType_t *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            ISharedImage * This,
            /* [retval][out] */ Size_t *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LockImage )( 
            ISharedImage * This,
            /* [retval][out] */ ImageInfo_t *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnlockImage )( 
            ISharedImage * This);
        
        END_INTERFACE
    } ISharedImageVtbl;

    interface ISharedImage
    {
        CONST_VTBL struct ISharedImageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISharedImage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISharedImage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISharedImage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISharedImage_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISharedImage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISharedImage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISharedImage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISharedImage_get_Type(This,pVal)	\
    ( (This)->lpVtbl -> get_Type(This,pVal) ) 

#define ISharedImage_get_Size(This,pVal)	\
    ( (This)->lpVtbl -> get_Size(This,pVal) ) 

#define ISharedImage_LockImage(This,ret)	\
    ( (This)->lpVtbl -> LockImage(This,ret) ) 

#define ISharedImage_UnlockImage(This)	\
    ( (This)->lpVtbl -> UnlockImage(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISharedImage_INTERFACE_DEFINED__ */


#ifndef __ISharedVideo_INTERFACE_DEFINED__
#define __ISharedVideo_INTERFACE_DEFINED__

/* interface ISharedVideo */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISharedVideo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F0D10F10-6A62-47D3-9A83-B0C580B8915E")
    ISharedVideo : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ ImageType_t *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ Size_t *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LockImage( 
            /* [retval][out] */ ImageInfo_t *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnlockImage( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Writer( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISharedVideoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISharedVideo * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISharedVideo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISharedVideo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISharedVideo * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISharedVideo * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISharedVideo * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISharedVideo * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            ISharedVideo * This,
            /* [retval][out] */ ImageType_t *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            ISharedVideo * This,
            /* [retval][out] */ Size_t *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LockImage )( 
            ISharedVideo * This,
            /* [retval][out] */ ImageInfo_t *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnlockImage )( 
            ISharedVideo * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Writer )( 
            ISharedVideo * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        END_INTERFACE
    } ISharedVideoVtbl;

    interface ISharedVideo
    {
        CONST_VTBL struct ISharedVideoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISharedVideo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISharedVideo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISharedVideo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISharedVideo_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISharedVideo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISharedVideo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISharedVideo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISharedVideo_get_Type(This,pVal)	\
    ( (This)->lpVtbl -> get_Type(This,pVal) ) 

#define ISharedVideo_get_Size(This,pVal)	\
    ( (This)->lpVtbl -> get_Size(This,pVal) ) 

#define ISharedVideo_LockImage(This,ret)	\
    ( (This)->lpVtbl -> LockImage(This,ret) ) 

#define ISharedVideo_UnlockImage(This)	\
    ( (This)->lpVtbl -> UnlockImage(This) ) 

#define ISharedVideo_get_Writer(This,pVal)	\
    ( (This)->lpVtbl -> get_Writer(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISharedVideo_INTERFACE_DEFINED__ */


#ifndef __ISharedQueue_INTERFACE_DEFINED__
#define __ISharedQueue_INTERFACE_DEFINED__

/* interface ISharedQueue */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISharedQueue;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7044D0AC-55DC-4E6F-A58A-F2FB676A9339")
    ISharedQueue : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Push( 
            /* [in] */ LONG_PTR data,
            /* [in] */ LONG size,
            /* [retval][out] */ LONG *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Pop( 
            LONG_PTR data,
            /* [in] */ LONG size,
            /* [retval][out] */ LONG *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TryPush( 
            /* [in] */ LONG_PTR data,
            /* [in] */ LONG size,
            /* [retval][out] */ LONG *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TryPop( 
            /* [in] */ LONG_PTR data,
            /* [in] */ LONG size,
            /* [retval][out] */ LONG *ret) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Cancel( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Cancel( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Capacity( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxMsgSize( 
            /* [retval][out] */ LONG *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISharedQueueVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISharedQueue * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISharedQueue * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISharedQueue * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISharedQueue * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISharedQueue * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISharedQueue * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISharedQueue * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Push )( 
            ISharedQueue * This,
            /* [in] */ LONG_PTR data,
            /* [in] */ LONG size,
            /* [retval][out] */ LONG *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Pop )( 
            ISharedQueue * This,
            LONG_PTR data,
            /* [in] */ LONG size,
            /* [retval][out] */ LONG *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TryPush )( 
            ISharedQueue * This,
            /* [in] */ LONG_PTR data,
            /* [in] */ LONG size,
            /* [retval][out] */ LONG *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TryPop )( 
            ISharedQueue * This,
            /* [in] */ LONG_PTR data,
            /* [in] */ LONG size,
            /* [retval][out] */ LONG *ret);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            ISharedQueue * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Cancel )( 
            ISharedQueue * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Cancel )( 
            ISharedQueue * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Capacity )( 
            ISharedQueue * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxMsgSize )( 
            ISharedQueue * This,
            /* [retval][out] */ LONG *pVal);
        
        END_INTERFACE
    } ISharedQueueVtbl;

    interface ISharedQueue
    {
        CONST_VTBL struct ISharedQueueVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISharedQueue_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISharedQueue_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISharedQueue_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISharedQueue_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISharedQueue_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISharedQueue_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISharedQueue_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISharedQueue_Push(This,data,size,ret)	\
    ( (This)->lpVtbl -> Push(This,data,size,ret) ) 

#define ISharedQueue_Pop(This,data,size,ret)	\
    ( (This)->lpVtbl -> Pop(This,data,size,ret) ) 

#define ISharedQueue_TryPush(This,data,size,ret)	\
    ( (This)->lpVtbl -> TryPush(This,data,size,ret) ) 

#define ISharedQueue_TryPop(This,data,size,ret)	\
    ( (This)->lpVtbl -> TryPop(This,data,size,ret) ) 

#define ISharedQueue_get_Size(This,pVal)	\
    ( (This)->lpVtbl -> get_Size(This,pVal) ) 

#define ISharedQueue_get_Cancel(This,pVal)	\
    ( (This)->lpVtbl -> get_Cancel(This,pVal) ) 

#define ISharedQueue_put_Cancel(This,newVal)	\
    ( (This)->lpVtbl -> put_Cancel(This,newVal) ) 

#define ISharedQueue_get_Capacity(This,pVal)	\
    ( (This)->lpVtbl -> get_Capacity(This,pVal) ) 

#define ISharedQueue_get_MaxMsgSize(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxMsgSize(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISharedQueue_INTERFACE_DEFINED__ */


#ifndef __IEnumSharedMemoryNames_INTERFACE_DEFINED__
#define __IEnumSharedMemoryNames_INTERFACE_DEFINED__

/* interface IEnumSharedMemoryNames */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IEnumSharedMemoryNames;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4A94DF83-23D6-4539-9B79-D138B003B1D7")
    IEnumSharedMemoryNames : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppUnk) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumSharedMemoryNamesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumSharedMemoryNames * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumSharedMemoryNames * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumSharedMemoryNames * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEnumSharedMemoryNames * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEnumSharedMemoryNames * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEnumSharedMemoryNames * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEnumSharedMemoryNames * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IEnumSharedMemoryNames * This,
            /* [retval][out] */ IUnknown **ppUnk);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IEnumSharedMemoryNames * This,
            /* [in] */ long Index,
            /* [retval][out] */ BSTR *pVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IEnumSharedMemoryNames * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } IEnumSharedMemoryNamesVtbl;

    interface IEnumSharedMemoryNames
    {
        CONST_VTBL struct IEnumSharedMemoryNamesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumSharedMemoryNames_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumSharedMemoryNames_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumSharedMemoryNames_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumSharedMemoryNames_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IEnumSharedMemoryNames_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IEnumSharedMemoryNames_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IEnumSharedMemoryNames_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IEnumSharedMemoryNames_get__NewEnum(This,ppUnk)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppUnk) ) 

#define IEnumSharedMemoryNames_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IEnumSharedMemoryNames_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumSharedMemoryNames_INTERFACE_DEFINED__ */


#ifndef __ISimpleTimer_INTERFACE_DEFINED__
#define __ISimpleTimer_INTERFACE_DEFINED__

/* interface ISimpleTimer */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISimpleTimer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4468244E-21DC-4D4F-8569-6106617079DD")
    ISimpleTimer : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TimedOut( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Update( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISimpleTimerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISimpleTimer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISimpleTimer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISimpleTimer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISimpleTimer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISimpleTimer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISimpleTimer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISimpleTimer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TimedOut )( 
            ISimpleTimer * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            ISimpleTimer * This);
        
        END_INTERFACE
    } ISimpleTimerVtbl;

    interface ISimpleTimer
    {
        CONST_VTBL struct ISimpleTimerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISimpleTimer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISimpleTimer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISimpleTimer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISimpleTimer_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISimpleTimer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISimpleTimer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISimpleTimer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISimpleTimer_get_TimedOut(This,pVal)	\
    ( (This)->lpVtbl -> get_TimedOut(This,pVal) ) 

#define ISimpleTimer_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISimpleTimer_INTERFACE_DEFINED__ */


#ifndef __ID3D9Surface_INTERFACE_DEFINED__
#define __ID3D9Surface_INTERFACE_DEFINED__

/* interface ID3D9Surface */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ID3D9Surface;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CFC496D8-A0FD-4d8d-944C-2DC50E863E79")
    ID3D9Surface : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDC( 
            /* [retval][out] */ LONG_PTR *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReleaseDC( 
            /* [in] */ LONG_PTR hdc) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDesc( 
            /* [retval][out] */ D3DSurfaceDesc_t *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LockRect( 
            /* [in] */ Rect_t rect,
            /* [in] */ D3DLock_t Flags,
            /* [retval][out] */ ImageInfo_t *info) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnlockRect( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ID3D9SurfaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ID3D9Surface * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ID3D9Surface * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ID3D9Surface * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ID3D9Surface * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ID3D9Surface * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ID3D9Surface * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ID3D9Surface * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDC )( 
            ID3D9Surface * This,
            /* [retval][out] */ LONG_PTR *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseDC )( 
            ID3D9Surface * This,
            /* [in] */ LONG_PTR hdc);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDesc )( 
            ID3D9Surface * This,
            /* [retval][out] */ D3DSurfaceDesc_t *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LockRect )( 
            ID3D9Surface * This,
            /* [in] */ Rect_t rect,
            /* [in] */ D3DLock_t Flags,
            /* [retval][out] */ ImageInfo_t *info);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnlockRect )( 
            ID3D9Surface * This);
        
        END_INTERFACE
    } ID3D9SurfaceVtbl;

    interface ID3D9Surface
    {
        CONST_VTBL struct ID3D9SurfaceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ID3D9Surface_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ID3D9Surface_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ID3D9Surface_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ID3D9Surface_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ID3D9Surface_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ID3D9Surface_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ID3D9Surface_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ID3D9Surface_GetDC(This,ret)	\
    ( (This)->lpVtbl -> GetDC(This,ret) ) 

#define ID3D9Surface_ReleaseDC(This,hdc)	\
    ( (This)->lpVtbl -> ReleaseDC(This,hdc) ) 

#define ID3D9Surface_GetDesc(This,ret)	\
    ( (This)->lpVtbl -> GetDesc(This,ret) ) 

#define ID3D9Surface_LockRect(This,rect,Flags,info)	\
    ( (This)->lpVtbl -> LockRect(This,rect,Flags,info) ) 

#define ID3D9Surface_UnlockRect(This)	\
    ( (This)->lpVtbl -> UnlockRect(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ID3D9Surface_INTERFACE_DEFINED__ */


#ifndef __ID3D9Texture_INTERFACE_DEFINED__
#define __ID3D9Texture_INTERFACE_DEFINED__

/* interface ID3D9Texture */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ID3D9Texture;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8A18DA32-7838-4454-97F5-20A77508B45F")
    ID3D9Texture : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLevelDesc( 
            /* [in] */ UINT Level,
            /* [retval][out] */ D3DSurfaceDesc_t *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSurfaceLevel( 
            /* [in] */ UINT Level,
            /* [retval][out] */ ID3D9Surface **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LockRect( 
            /* [in] */ UINT Level,
            /* [in] */ Rect_t rect,
            /* [in] */ D3DLock_t Flags,
            /* [retval][out] */ ImageInfo_t *info) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnlockRect( 
            /* [in] */ UINT Level) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ID3D9TextureVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ID3D9Texture * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ID3D9Texture * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ID3D9Texture * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ID3D9Texture * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ID3D9Texture * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ID3D9Texture * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ID3D9Texture * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLevelDesc )( 
            ID3D9Texture * This,
            /* [in] */ UINT Level,
            /* [retval][out] */ D3DSurfaceDesc_t *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSurfaceLevel )( 
            ID3D9Texture * This,
            /* [in] */ UINT Level,
            /* [retval][out] */ ID3D9Surface **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LockRect )( 
            ID3D9Texture * This,
            /* [in] */ UINT Level,
            /* [in] */ Rect_t rect,
            /* [in] */ D3DLock_t Flags,
            /* [retval][out] */ ImageInfo_t *info);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnlockRect )( 
            ID3D9Texture * This,
            /* [in] */ UINT Level);
        
        END_INTERFACE
    } ID3D9TextureVtbl;

    interface ID3D9Texture
    {
        CONST_VTBL struct ID3D9TextureVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ID3D9Texture_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ID3D9Texture_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ID3D9Texture_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ID3D9Texture_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ID3D9Texture_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ID3D9Texture_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ID3D9Texture_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ID3D9Texture_GetLevelDesc(This,Level,ret)	\
    ( (This)->lpVtbl -> GetLevelDesc(This,Level,ret) ) 

#define ID3D9Texture_GetSurfaceLevel(This,Level,ret)	\
    ( (This)->lpVtbl -> GetSurfaceLevel(This,Level,ret) ) 

#define ID3D9Texture_LockRect(This,Level,rect,Flags,info)	\
    ( (This)->lpVtbl -> LockRect(This,Level,rect,Flags,info) ) 

#define ID3D9Texture_UnlockRect(This,Level)	\
    ( (This)->lpVtbl -> UnlockRect(This,Level) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ID3D9Texture_INTERFACE_DEFINED__ */


#ifndef __IDshowMediaPlayer_INTERFACE_DEFINED__
#define __IDshowMediaPlayer_INTERFACE_DEFINED__

/* interface IDshowMediaPlayer */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDshowMediaPlayer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1247F15A-9E2B-462B-9030-3FBEB72D472B")
    IDshowMediaPlayer : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Movie( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Movie( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HasVideo( 
            /* [retval][out] */ VARIANT_BOOL *ret) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HasAudio( 
            /* [retval][out] */ VARIANT_BOOL *ret) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ Size_t *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UVSize( 
            /* [retval][out] */ Size_t *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LockImage( 
            /* [retval][out] */ ImageInfo_t yuv[ 3 ]) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnlockImage( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ThreadAffinityMask( 
            /* [retval][out] */ DWORD_PTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ThreadAffinityMask( 
            /* [in] */ DWORD_PTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SharedVideo( 
            /* [retval][out] */ ISharedVideo **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SharedVideoName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SharedVideoName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SyncSource( 
            /* [retval][out] */ IClock **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SyncSource( 
            /* [in] */ IClock *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SourceFilterName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SourceFilterName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VideoDecoderName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_VideoDecoderName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VideoRendererName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_VideoRendererName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LockImage1( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE YUV( 
            /* [in] */ LONG index,
            /* [retval][out] */ ImageInfo_t *ret) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDshowMediaPlayerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDshowMediaPlayer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDshowMediaPlayer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDshowMediaPlayer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDshowMediaPlayer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDshowMediaPlayer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDshowMediaPlayer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDshowMediaPlayer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Movie )( 
            IDshowMediaPlayer * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Movie )( 
            IDshowMediaPlayer * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasVideo )( 
            IDshowMediaPlayer * This,
            /* [retval][out] */ VARIANT_BOOL *ret);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasAudio )( 
            IDshowMediaPlayer * This,
            /* [retval][out] */ VARIANT_BOOL *ret);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            IDshowMediaPlayer * This,
            /* [retval][out] */ Size_t *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UVSize )( 
            IDshowMediaPlayer * This,
            /* [retval][out] */ Size_t *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LockImage )( 
            IDshowMediaPlayer * This,
            /* [retval][out] */ ImageInfo_t yuv[ 3 ]);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnlockImage )( 
            IDshowMediaPlayer * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ThreadAffinityMask )( 
            IDshowMediaPlayer * This,
            /* [retval][out] */ DWORD_PTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ThreadAffinityMask )( 
            IDshowMediaPlayer * This,
            /* [in] */ DWORD_PTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SharedVideo )( 
            IDshowMediaPlayer * This,
            /* [retval][out] */ ISharedVideo **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SharedVideoName )( 
            IDshowMediaPlayer * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SharedVideoName )( 
            IDshowMediaPlayer * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SyncSource )( 
            IDshowMediaPlayer * This,
            /* [retval][out] */ IClock **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SyncSource )( 
            IDshowMediaPlayer * This,
            /* [in] */ IClock *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SourceFilterName )( 
            IDshowMediaPlayer * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SourceFilterName )( 
            IDshowMediaPlayer * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoDecoderName )( 
            IDshowMediaPlayer * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VideoDecoderName )( 
            IDshowMediaPlayer * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoRendererName )( 
            IDshowMediaPlayer * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VideoRendererName )( 
            IDshowMediaPlayer * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LockImage1 )( 
            IDshowMediaPlayer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *YUV )( 
            IDshowMediaPlayer * This,
            /* [in] */ LONG index,
            /* [retval][out] */ ImageInfo_t *ret);
        
        END_INTERFACE
    } IDshowMediaPlayerVtbl;

    interface IDshowMediaPlayer
    {
        CONST_VTBL struct IDshowMediaPlayerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDshowMediaPlayer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDshowMediaPlayer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDshowMediaPlayer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDshowMediaPlayer_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDshowMediaPlayer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDshowMediaPlayer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDshowMediaPlayer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDshowMediaPlayer_get_Movie(This,pVal)	\
    ( (This)->lpVtbl -> get_Movie(This,pVal) ) 

#define IDshowMediaPlayer_put_Movie(This,newVal)	\
    ( (This)->lpVtbl -> put_Movie(This,newVal) ) 

#define IDshowMediaPlayer_get_HasVideo(This,ret)	\
    ( (This)->lpVtbl -> get_HasVideo(This,ret) ) 

#define IDshowMediaPlayer_get_HasAudio(This,ret)	\
    ( (This)->lpVtbl -> get_HasAudio(This,ret) ) 

#define IDshowMediaPlayer_get_Size(This,pVal)	\
    ( (This)->lpVtbl -> get_Size(This,pVal) ) 

#define IDshowMediaPlayer_get_UVSize(This,pVal)	\
    ( (This)->lpVtbl -> get_UVSize(This,pVal) ) 

#define IDshowMediaPlayer_LockImage(This,yuv)	\
    ( (This)->lpVtbl -> LockImage(This,yuv) ) 

#define IDshowMediaPlayer_UnlockImage(This)	\
    ( (This)->lpVtbl -> UnlockImage(This) ) 

#define IDshowMediaPlayer_get_ThreadAffinityMask(This,pVal)	\
    ( (This)->lpVtbl -> get_ThreadAffinityMask(This,pVal) ) 

#define IDshowMediaPlayer_put_ThreadAffinityMask(This,newVal)	\
    ( (This)->lpVtbl -> put_ThreadAffinityMask(This,newVal) ) 

#define IDshowMediaPlayer_get_SharedVideo(This,pVal)	\
    ( (This)->lpVtbl -> get_SharedVideo(This,pVal) ) 

#define IDshowMediaPlayer_get_SharedVideoName(This,pVal)	\
    ( (This)->lpVtbl -> get_SharedVideoName(This,pVal) ) 

#define IDshowMediaPlayer_put_SharedVideoName(This,newVal)	\
    ( (This)->lpVtbl -> put_SharedVideoName(This,newVal) ) 

#define IDshowMediaPlayer_get_SyncSource(This,pVal)	\
    ( (This)->lpVtbl -> get_SyncSource(This,pVal) ) 

#define IDshowMediaPlayer_put_SyncSource(This,newVal)	\
    ( (This)->lpVtbl -> put_SyncSource(This,newVal) ) 

#define IDshowMediaPlayer_get_SourceFilterName(This,pVal)	\
    ( (This)->lpVtbl -> get_SourceFilterName(This,pVal) ) 

#define IDshowMediaPlayer_put_SourceFilterName(This,newVal)	\
    ( (This)->lpVtbl -> put_SourceFilterName(This,newVal) ) 

#define IDshowMediaPlayer_get_VideoDecoderName(This,pVal)	\
    ( (This)->lpVtbl -> get_VideoDecoderName(This,pVal) ) 

#define IDshowMediaPlayer_put_VideoDecoderName(This,newVal)	\
    ( (This)->lpVtbl -> put_VideoDecoderName(This,newVal) ) 

#define IDshowMediaPlayer_get_VideoRendererName(This,pVal)	\
    ( (This)->lpVtbl -> get_VideoRendererName(This,pVal) ) 

#define IDshowMediaPlayer_put_VideoRendererName(This,newVal)	\
    ( (This)->lpVtbl -> put_VideoRendererName(This,newVal) ) 

#define IDshowMediaPlayer_LockImage1(This)	\
    ( (This)->lpVtbl -> LockImage1(This) ) 

#define IDshowMediaPlayer_YUV(This,index,ret)	\
    ( (This)->lpVtbl -> YUV(This,index,ret) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDshowMediaPlayer_INTERFACE_DEFINED__ */


#ifndef __ILAVMediaPlayer_INTERFACE_DEFINED__
#define __ILAVMediaPlayer_INTERFACE_DEFINED__

/* interface ILAVMediaPlayer */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ILAVMediaPlayer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FF0EB9FB-7E34-4528-9A4A-069896FFF047")
    ILAVMediaPlayer : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Movie( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Movie( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ Size_t *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SyncSource( 
            /* [retval][out] */ IClock **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SyncSource( 
            /* [in] */ IClock *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HasVideo( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HasAudio( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImageType( 
            /* [retval][out] */ ImageType_t *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ImageType( 
            /* [in] */ ImageType_t newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LockImage( 
            /* [retval][out] */ ImageInfo_t *image) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnlockImage( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILAVMediaPlayerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILAVMediaPlayer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILAVMediaPlayer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILAVMediaPlayer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILAVMediaPlayer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILAVMediaPlayer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILAVMediaPlayer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILAVMediaPlayer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Movie )( 
            ILAVMediaPlayer * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Movie )( 
            ILAVMediaPlayer * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            ILAVMediaPlayer * This,
            /* [retval][out] */ Size_t *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SyncSource )( 
            ILAVMediaPlayer * This,
            /* [retval][out] */ IClock **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SyncSource )( 
            ILAVMediaPlayer * This,
            /* [in] */ IClock *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasVideo )( 
            ILAVMediaPlayer * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasAudio )( 
            ILAVMediaPlayer * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImageType )( 
            ILAVMediaPlayer * This,
            /* [retval][out] */ ImageType_t *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ImageType )( 
            ILAVMediaPlayer * This,
            /* [in] */ ImageType_t newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LockImage )( 
            ILAVMediaPlayer * This,
            /* [retval][out] */ ImageInfo_t *image);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnlockImage )( 
            ILAVMediaPlayer * This);
        
        END_INTERFACE
    } ILAVMediaPlayerVtbl;

    interface ILAVMediaPlayer
    {
        CONST_VTBL struct ILAVMediaPlayerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILAVMediaPlayer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILAVMediaPlayer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILAVMediaPlayer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILAVMediaPlayer_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILAVMediaPlayer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILAVMediaPlayer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILAVMediaPlayer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILAVMediaPlayer_get_Movie(This,pVal)	\
    ( (This)->lpVtbl -> get_Movie(This,pVal) ) 

#define ILAVMediaPlayer_put_Movie(This,newVal)	\
    ( (This)->lpVtbl -> put_Movie(This,newVal) ) 

#define ILAVMediaPlayer_get_Size(This,pVal)	\
    ( (This)->lpVtbl -> get_Size(This,pVal) ) 

#define ILAVMediaPlayer_get_SyncSource(This,pVal)	\
    ( (This)->lpVtbl -> get_SyncSource(This,pVal) ) 

#define ILAVMediaPlayer_put_SyncSource(This,newVal)	\
    ( (This)->lpVtbl -> put_SyncSource(This,newVal) ) 

#define ILAVMediaPlayer_get_HasVideo(This,pVal)	\
    ( (This)->lpVtbl -> get_HasVideo(This,pVal) ) 

#define ILAVMediaPlayer_get_HasAudio(This,pVal)	\
    ( (This)->lpVtbl -> get_HasAudio(This,pVal) ) 

#define ILAVMediaPlayer_get_ImageType(This,pVal)	\
    ( (This)->lpVtbl -> get_ImageType(This,pVal) ) 

#define ILAVMediaPlayer_put_ImageType(This,newVal)	\
    ( (This)->lpVtbl -> put_ImageType(This,newVal) ) 

#define ILAVMediaPlayer_LockImage(This,image)	\
    ( (This)->lpVtbl -> LockImage(This,image) ) 

#define ILAVMediaPlayer_UnlockImage(This)	\
    ( (This)->lpVtbl -> UnlockImage(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILAVMediaPlayer_INTERFACE_DEFINED__ */


#ifndef __IAlphaMediaPlayer_INTERFACE_DEFINED__
#define __IAlphaMediaPlayer_INTERFACE_DEFINED__

/* interface IAlphaMediaPlayer */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAlphaMediaPlayer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6B54D6AB-7FCB-466F-9860-252C9FCB1881")
    IAlphaMediaPlayer : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Movie( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Movie( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ Size_t *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SyncSource( 
            /* [retval][out] */ IClock **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SyncSource( 
            /* [in] */ IClock *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HasVideo( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HasAlpha( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HasAudio( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImageType( 
            /* [retval][out] */ ImageType_t *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ImageType( 
            /* [in] */ ImageType_t newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LockImage( 
            /* [retval][out] */ ImageInfo_t *image) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnlockImage( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAlphaMediaPlayerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAlphaMediaPlayer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAlphaMediaPlayer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAlphaMediaPlayer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAlphaMediaPlayer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAlphaMediaPlayer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAlphaMediaPlayer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAlphaMediaPlayer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Movie )( 
            IAlphaMediaPlayer * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Movie )( 
            IAlphaMediaPlayer * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            IAlphaMediaPlayer * This,
            /* [retval][out] */ Size_t *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SyncSource )( 
            IAlphaMediaPlayer * This,
            /* [retval][out] */ IClock **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SyncSource )( 
            IAlphaMediaPlayer * This,
            /* [in] */ IClock *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasVideo )( 
            IAlphaMediaPlayer * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasAlpha )( 
            IAlphaMediaPlayer * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasAudio )( 
            IAlphaMediaPlayer * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImageType )( 
            IAlphaMediaPlayer * This,
            /* [retval][out] */ ImageType_t *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ImageType )( 
            IAlphaMediaPlayer * This,
            /* [in] */ ImageType_t newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LockImage )( 
            IAlphaMediaPlayer * This,
            /* [retval][out] */ ImageInfo_t *image);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnlockImage )( 
            IAlphaMediaPlayer * This);
        
        END_INTERFACE
    } IAlphaMediaPlayerVtbl;

    interface IAlphaMediaPlayer
    {
        CONST_VTBL struct IAlphaMediaPlayerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAlphaMediaPlayer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAlphaMediaPlayer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAlphaMediaPlayer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAlphaMediaPlayer_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAlphaMediaPlayer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAlphaMediaPlayer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAlphaMediaPlayer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAlphaMediaPlayer_get_Movie(This,pVal)	\
    ( (This)->lpVtbl -> get_Movie(This,pVal) ) 

#define IAlphaMediaPlayer_put_Movie(This,newVal)	\
    ( (This)->lpVtbl -> put_Movie(This,newVal) ) 

#define IAlphaMediaPlayer_get_Size(This,pVal)	\
    ( (This)->lpVtbl -> get_Size(This,pVal) ) 

#define IAlphaMediaPlayer_get_SyncSource(This,pVal)	\
    ( (This)->lpVtbl -> get_SyncSource(This,pVal) ) 

#define IAlphaMediaPlayer_put_SyncSource(This,newVal)	\
    ( (This)->lpVtbl -> put_SyncSource(This,newVal) ) 

#define IAlphaMediaPlayer_get_HasVideo(This,pVal)	\
    ( (This)->lpVtbl -> get_HasVideo(This,pVal) ) 

#define IAlphaMediaPlayer_get_HasAlpha(This,pVal)	\
    ( (This)->lpVtbl -> get_HasAlpha(This,pVal) ) 

#define IAlphaMediaPlayer_get_HasAudio(This,pVal)	\
    ( (This)->lpVtbl -> get_HasAudio(This,pVal) ) 

#define IAlphaMediaPlayer_get_ImageType(This,pVal)	\
    ( (This)->lpVtbl -> get_ImageType(This,pVal) ) 

#define IAlphaMediaPlayer_put_ImageType(This,newVal)	\
    ( (This)->lpVtbl -> put_ImageType(This,newVal) ) 

#define IAlphaMediaPlayer_LockImage(This,image)	\
    ( (This)->lpVtbl -> LockImage(This,image) ) 

#define IAlphaMediaPlayer_UnlockImage(This)	\
    ( (This)->lpVtbl -> UnlockImage(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAlphaMediaPlayer_INTERFACE_DEFINED__ */


#ifndef __IMediaPlayer_INTERFACE_DEFINED__
#define __IMediaPlayer_INTERFACE_DEFINED__

/* interface IMediaPlayer */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMediaPlayer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("35FABDFF-5114-4113-89EB-DF7111FDC9FF")
    IMediaPlayer : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Play( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Run( 
            /* [in] */ LONGLONG t) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Pause( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Rate( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Rate( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Duration( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentPosition( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CurrentPosition( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StopTime( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Volume( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Volume( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Balance( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Balance( 
            /* [in] */ DOUBLE newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMediaPlayerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMediaPlayer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMediaPlayer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMediaPlayer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMediaPlayer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMediaPlayer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMediaPlayer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMediaPlayer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Play )( 
            IMediaPlayer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Run )( 
            IMediaPlayer * This,
            /* [in] */ LONGLONG t);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IMediaPlayer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Pause )( 
            IMediaPlayer * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Rate )( 
            IMediaPlayer * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Rate )( 
            IMediaPlayer * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Duration )( 
            IMediaPlayer * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentPosition )( 
            IMediaPlayer * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CurrentPosition )( 
            IMediaPlayer * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StopTime )( 
            IMediaPlayer * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Volume )( 
            IMediaPlayer * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Volume )( 
            IMediaPlayer * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Balance )( 
            IMediaPlayer * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Balance )( 
            IMediaPlayer * This,
            /* [in] */ DOUBLE newVal);
        
        END_INTERFACE
    } IMediaPlayerVtbl;

    interface IMediaPlayer
    {
        CONST_VTBL struct IMediaPlayerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMediaPlayer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMediaPlayer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMediaPlayer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMediaPlayer_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMediaPlayer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMediaPlayer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMediaPlayer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMediaPlayer_Play(This)	\
    ( (This)->lpVtbl -> Play(This) ) 

#define IMediaPlayer_Run(This,t)	\
    ( (This)->lpVtbl -> Run(This,t) ) 

#define IMediaPlayer_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#define IMediaPlayer_Pause(This)	\
    ( (This)->lpVtbl -> Pause(This) ) 

#define IMediaPlayer_get_Rate(This,pVal)	\
    ( (This)->lpVtbl -> get_Rate(This,pVal) ) 

#define IMediaPlayer_put_Rate(This,newVal)	\
    ( (This)->lpVtbl -> put_Rate(This,newVal) ) 

#define IMediaPlayer_get_Duration(This,pVal)	\
    ( (This)->lpVtbl -> get_Duration(This,pVal) ) 

#define IMediaPlayer_get_CurrentPosition(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentPosition(This,pVal) ) 

#define IMediaPlayer_put_CurrentPosition(This,newVal)	\
    ( (This)->lpVtbl -> put_CurrentPosition(This,newVal) ) 

#define IMediaPlayer_get_StopTime(This,pVal)	\
    ( (This)->lpVtbl -> get_StopTime(This,pVal) ) 

#define IMediaPlayer_get_Volume(This,pVal)	\
    ( (This)->lpVtbl -> get_Volume(This,pVal) ) 

#define IMediaPlayer_put_Volume(This,newVal)	\
    ( (This)->lpVtbl -> put_Volume(This,newVal) ) 

#define IMediaPlayer_get_Balance(This,pVal)	\
    ( (This)->lpVtbl -> get_Balance(This,pVal) ) 

#define IMediaPlayer_put_Balance(This,newVal)	\
    ( (This)->lpVtbl -> put_Balance(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMediaPlayer_INTERFACE_DEFINED__ */


#ifndef __IDevIL_INTERFACE_DEFINED__
#define __IDevIL_INTERFACE_DEFINED__

/* interface IDevIL */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDevIL;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0D67C42A-D8AF-497A-8217-281915198975")
    IDevIL : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GenImage( 
            /* [retval][out] */ DWORD *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BindImage( 
            /* [in] */ DWORD image) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteImage( 
            /* [in] */ DWORD image) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ErrorCode( 
            /* [retval][out] */ DWORD *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ErrorString( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadFromFile( 
            /* [in] */ BSTR file,
            /* [retval][out] */ VARIANT_BOOL *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveToFile( 
            /* [in] */ BSTR file,
            /* [retval][out] */ VARIANT_BOOL *ret) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ Size_t *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImageInfo( 
            /* [retval][out] */ ImageInfo_t *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BytesPerPixel( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CopyPixels( 
            /* [in] */ Point_t pt,
            /* [in] */ Size_t size,
            /* [in] */ ImageType_t type,
            /* [in] */ LONG_PTR data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TexImage( 
            /* [in] */ Size_t size,
            /* [in] */ ImageType_t type,
            /* [in] */ LONG_PTR data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPixels( 
            /* [in] */ Point_t pt,
            /* [in] */ Size_t size,
            /* [in] */ ImageType_t type,
            /* [in] */ LONG_PTR data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CopyImage( 
            /* [in] */ DWORD src,
            /* [retval][out] */ VARIANT_BOOL *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Scale( 
            /* [in] */ Size_t size,
            /* [retval][out] */ VARIANT_BOOL *ret) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ ImageType_t *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ImageParameter( 
            /* [in] */ ILImageParamters_t name,
            /* [in] */ ILImageParamters_t param) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConvertImage( 
            /* [in] */ ImageType_t type,
            /* [retval][out] */ VARIANT_BOOL *ret) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDevILVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDevIL * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDevIL * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDevIL * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDevIL * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDevIL * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDevIL * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDevIL * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GenImage )( 
            IDevIL * This,
            /* [retval][out] */ DWORD *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BindImage )( 
            IDevIL * This,
            /* [in] */ DWORD image);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteImage )( 
            IDevIL * This,
            /* [in] */ DWORD image);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ErrorCode )( 
            IDevIL * This,
            /* [retval][out] */ DWORD *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ErrorString )( 
            IDevIL * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadFromFile )( 
            IDevIL * This,
            /* [in] */ BSTR file,
            /* [retval][out] */ VARIANT_BOOL *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveToFile )( 
            IDevIL * This,
            /* [in] */ BSTR file,
            /* [retval][out] */ VARIANT_BOOL *ret);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            IDevIL * This,
            /* [retval][out] */ Size_t *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImageInfo )( 
            IDevIL * This,
            /* [retval][out] */ ImageInfo_t *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BytesPerPixel )( 
            IDevIL * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CopyPixels )( 
            IDevIL * This,
            /* [in] */ Point_t pt,
            /* [in] */ Size_t size,
            /* [in] */ ImageType_t type,
            /* [in] */ LONG_PTR data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TexImage )( 
            IDevIL * This,
            /* [in] */ Size_t size,
            /* [in] */ ImageType_t type,
            /* [in] */ LONG_PTR data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPixels )( 
            IDevIL * This,
            /* [in] */ Point_t pt,
            /* [in] */ Size_t size,
            /* [in] */ ImageType_t type,
            /* [in] */ LONG_PTR data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CopyImage )( 
            IDevIL * This,
            /* [in] */ DWORD src,
            /* [retval][out] */ VARIANT_BOOL *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Scale )( 
            IDevIL * This,
            /* [in] */ Size_t size,
            /* [retval][out] */ VARIANT_BOOL *ret);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IDevIL * This,
            /* [retval][out] */ ImageType_t *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImageParameter )( 
            IDevIL * This,
            /* [in] */ ILImageParamters_t name,
            /* [in] */ ILImageParamters_t param);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConvertImage )( 
            IDevIL * This,
            /* [in] */ ImageType_t type,
            /* [retval][out] */ VARIANT_BOOL *ret);
        
        END_INTERFACE
    } IDevILVtbl;

    interface IDevIL
    {
        CONST_VTBL struct IDevILVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDevIL_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDevIL_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDevIL_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDevIL_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDevIL_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDevIL_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDevIL_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDevIL_GenImage(This,ret)	\
    ( (This)->lpVtbl -> GenImage(This,ret) ) 

#define IDevIL_BindImage(This,image)	\
    ( (This)->lpVtbl -> BindImage(This,image) ) 

#define IDevIL_DeleteImage(This,image)	\
    ( (This)->lpVtbl -> DeleteImage(This,image) ) 

#define IDevIL_get_ErrorCode(This,pVal)	\
    ( (This)->lpVtbl -> get_ErrorCode(This,pVal) ) 

#define IDevIL_get_ErrorString(This,pVal)	\
    ( (This)->lpVtbl -> get_ErrorString(This,pVal) ) 

#define IDevIL_LoadFromFile(This,file,ret)	\
    ( (This)->lpVtbl -> LoadFromFile(This,file,ret) ) 

#define IDevIL_SaveToFile(This,file,ret)	\
    ( (This)->lpVtbl -> SaveToFile(This,file,ret) ) 

#define IDevIL_get_Size(This,pVal)	\
    ( (This)->lpVtbl -> get_Size(This,pVal) ) 

#define IDevIL_get_ImageInfo(This,pVal)	\
    ( (This)->lpVtbl -> get_ImageInfo(This,pVal) ) 

#define IDevIL_get_BytesPerPixel(This,pVal)	\
    ( (This)->lpVtbl -> get_BytesPerPixel(This,pVal) ) 

#define IDevIL_CopyPixels(This,pt,size,type,data)	\
    ( (This)->lpVtbl -> CopyPixels(This,pt,size,type,data) ) 

#define IDevIL_TexImage(This,size,type,data)	\
    ( (This)->lpVtbl -> TexImage(This,size,type,data) ) 

#define IDevIL_SetPixels(This,pt,size,type,data)	\
    ( (This)->lpVtbl -> SetPixels(This,pt,size,type,data) ) 

#define IDevIL_CopyImage(This,src,ret)	\
    ( (This)->lpVtbl -> CopyImage(This,src,ret) ) 

#define IDevIL_Scale(This,size,ret)	\
    ( (This)->lpVtbl -> Scale(This,size,ret) ) 

#define IDevIL_get_Type(This,pVal)	\
    ( (This)->lpVtbl -> get_Type(This,pVal) ) 

#define IDevIL_ImageParameter(This,name,param)	\
    ( (This)->lpVtbl -> ImageParameter(This,name,param) ) 

#define IDevIL_ConvertImage(This,type,ret)	\
    ( (This)->lpVtbl -> ConvertImage(This,type,ret) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDevIL_INTERFACE_DEFINED__ */


#ifndef __IPendingImage_INTERFACE_DEFINED__
#define __IPendingImage_INTERFACE_DEFINED__

/* interface IPendingImage */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IPendingImage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FBC8A744-C748-429F-830B-4BCB450BB63E")
    IPendingImage : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ Size_t *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ ImageType_t *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImageInfo( 
            /* [retval][out] */ ImageInfo_t *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Result( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Done( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImageSize( 
            /* [retval][out] */ Size_t *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPendingImageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPendingImage * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPendingImage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPendingImage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPendingImage * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPendingImage * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPendingImage * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPendingImage * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            IPendingImage * This,
            /* [retval][out] */ Size_t *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IPendingImage * This,
            /* [retval][out] */ ImageType_t *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImageInfo )( 
            IPendingImage * This,
            /* [retval][out] */ ImageInfo_t *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Result )( 
            IPendingImage * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Done )( 
            IPendingImage * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImageSize )( 
            IPendingImage * This,
            /* [retval][out] */ Size_t *pVal);
        
        END_INTERFACE
    } IPendingImageVtbl;

    interface IPendingImage
    {
        CONST_VTBL struct IPendingImageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPendingImage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPendingImage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPendingImage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPendingImage_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPendingImage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPendingImage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPendingImage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IPendingImage_get_Size(This,pVal)	\
    ( (This)->lpVtbl -> get_Size(This,pVal) ) 

#define IPendingImage_get_Type(This,pVal)	\
    ( (This)->lpVtbl -> get_Type(This,pVal) ) 

#define IPendingImage_get_ImageInfo(This,pVal)	\
    ( (This)->lpVtbl -> get_ImageInfo(This,pVal) ) 

#define IPendingImage_get_Result(This,pVal)	\
    ( (This)->lpVtbl -> get_Result(This,pVal) ) 

#define IPendingImage_get_Done(This,pVal)	\
    ( (This)->lpVtbl -> get_Done(This,pVal) ) 

#define IPendingImage_get_ImageSize(This,pVal)	\
    ( (This)->lpVtbl -> get_ImageSize(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPendingImage_INTERFACE_DEFINED__ */


#ifndef __IImageLoader_INTERFACE_DEFINED__
#define __IImageLoader_INTERFACE_DEFINED__

/* interface IImageLoader */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IImageLoader;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F1763D08-DFED-48F5-A905-BDE21EAE7EE1")
    IImageLoader : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ BSTR path,
            /* [in] */ Size_t size,
            /* [in] */ ImageType_t type,
            /* [retval][out] */ IPendingImage **ret) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Pendings( 
            /* [retval][out] */ LONG *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IImageLoaderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IImageLoader * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IImageLoader * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IImageLoader * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IImageLoader * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IImageLoader * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IImageLoader * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IImageLoader * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            IImageLoader * This,
            /* [in] */ BSTR path,
            /* [in] */ Size_t size,
            /* [in] */ ImageType_t type,
            /* [retval][out] */ IPendingImage **ret);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Pendings )( 
            IImageLoader * This,
            /* [retval][out] */ LONG *pVal);
        
        END_INTERFACE
    } IImageLoaderVtbl;

    interface IImageLoader
    {
        CONST_VTBL struct IImageLoaderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IImageLoader_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IImageLoader_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IImageLoader_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IImageLoader_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IImageLoader_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IImageLoader_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IImageLoader_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IImageLoader_Load(This,path,size,type,ret)	\
    ( (This)->lpVtbl -> Load(This,path,size,type,ret) ) 

#define IImageLoader_get_Pendings(This,pVal)	\
    ( (This)->lpVtbl -> get_Pendings(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IImageLoader_INTERFACE_DEFINED__ */


#ifndef __IParallelBox_INTERFACE_DEFINED__
#define __IParallelBox_INTERFACE_DEFINED__

/* interface IParallelBox */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IParallelBox;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A1C472FF-37AB-45BD-BF70-C0CFA010A471")
    IParallelBox : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Copy_8u_C1R( 
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Execute( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IParallelBoxVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IParallelBox * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IParallelBox * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IParallelBox * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IParallelBox * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IParallelBox * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IParallelBox * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IParallelBox * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy_8u_C1R )( 
            IParallelBox * This,
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Execute )( 
            IParallelBox * This);
        
        END_INTERFACE
    } IParallelBoxVtbl;

    interface IParallelBox
    {
        CONST_VTBL struct IParallelBoxVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IParallelBox_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IParallelBox_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IParallelBox_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IParallelBox_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IParallelBox_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IParallelBox_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IParallelBox_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IParallelBox_Copy_8u_C1R(This,src,dst,size)	\
    ( (This)->lpVtbl -> Copy_8u_C1R(This,src,dst,size) ) 

#define IParallelBox_Execute(This)	\
    ( (This)->lpVtbl -> Execute(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IParallelBox_INTERFACE_DEFINED__ */


#ifndef __IEB3FileLoader_INTERFACE_DEFINED__
#define __IEB3FileLoader_INTERFACE_DEFINED__

/* interface IEB3FileLoader */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IEB3FileLoader;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0D6402BE-75C3-4788-B511-CDB14F7D9986")
    IEB3FileLoader : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Generate( 
            /* [in] */ ImageInfo_t displacement,
            /* [in] */ ImageInfo_t profile,
            /* [in] */ ImageInfo_t blend,
            /* [in] */ Size_t size) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEB3FileLoaderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEB3FileLoader * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEB3FileLoader * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEB3FileLoader * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEB3FileLoader * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEB3FileLoader * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEB3FileLoader * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEB3FileLoader * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Generate )( 
            IEB3FileLoader * This,
            /* [in] */ ImageInfo_t displacement,
            /* [in] */ ImageInfo_t profile,
            /* [in] */ ImageInfo_t blend,
            /* [in] */ Size_t size);
        
        END_INTERFACE
    } IEB3FileLoaderVtbl;

    interface IEB3FileLoader
    {
        CONST_VTBL struct IEB3FileLoaderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEB3FileLoader_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEB3FileLoader_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEB3FileLoader_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEB3FileLoader_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IEB3FileLoader_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IEB3FileLoader_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IEB3FileLoader_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IEB3FileLoader_Generate(This,displacement,profile,blend,size)	\
    ( (This)->lpVtbl -> Generate(This,displacement,profile,blend,size) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEB3FileLoader_INTERFACE_DEFINED__ */


#ifndef __ISyncClock_INTERFACE_DEFINED__
#define __ISyncClock_INTERFACE_DEFINED__

/* interface ISyncClock */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISyncClock;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7F7BC0FE-746D-4cac-AE0D-3E7F4FA5C266")
    ISyncClock : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Ready( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISyncClockVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISyncClock * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISyncClock * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISyncClock * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISyncClock * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISyncClock * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISyncClock * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISyncClock * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Ready )( 
            ISyncClock * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        END_INTERFACE
    } ISyncClockVtbl;

    interface ISyncClock
    {
        CONST_VTBL struct ISyncClockVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncClock_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncClock_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncClock_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncClock_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISyncClock_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISyncClock_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISyncClock_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISyncClock_get_Ready(This,pVal)	\
    ( (This)->lpVtbl -> get_Ready(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncClock_INTERFACE_DEFINED__ */


#ifndef __IRegularClock_INTERFACE_DEFINED__
#define __IRegularClock_INTERFACE_DEFINED__

/* interface IRegularClock */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IRegularClock;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DCDBAF39-382E-4ebc-818A-84ED1543CE68")
    IRegularClock : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Tick( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRegularClockVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRegularClock * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRegularClock * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRegularClock * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRegularClock * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRegularClock * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRegularClock * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRegularClock * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Tick )( 
            IRegularClock * This);
        
        END_INTERFACE
    } IRegularClockVtbl;

    interface IRegularClock
    {
        CONST_VTBL struct IRegularClockVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRegularClock_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRegularClock_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRegularClock_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRegularClock_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRegularClock_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRegularClock_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRegularClock_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRegularClock_Tick(This)	\
    ( (This)->lpVtbl -> Tick(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRegularClock_INTERFACE_DEFINED__ */


#ifndef __IDshowVideoCaptureSource_INTERFACE_DEFINED__
#define __IDshowVideoCaptureSource_INTERFACE_DEFINED__

/* interface IDshowVideoCaptureSource */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDshowVideoCaptureSource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2DF7A76D-2094-4052-B8EC-95D056F37B00")
    IDshowVideoCaptureSource : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DisplayName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FriendlyName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SourceVideoType( 
            /* [retval][out] */ VideoType_t *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SourceVideoType( 
            /* [in] */ VideoType_t newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [retval][out] */ VARIANT_BOOL *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Disconnect( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Run( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ConnectedVideoType( 
            /* [retval][out] */ VideoType_t *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LockImage( 
            /* [retval][out] */ ImageInfo_t *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnlockImage( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDshowVideoCaptureSourceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDshowVideoCaptureSource * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDshowVideoCaptureSource * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDshowVideoCaptureSource * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDshowVideoCaptureSource * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDshowVideoCaptureSource * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDshowVideoCaptureSource * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDshowVideoCaptureSource * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayName )( 
            IDshowVideoCaptureSource * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FriendlyName )( 
            IDshowVideoCaptureSource * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SourceVideoType )( 
            IDshowVideoCaptureSource * This,
            /* [retval][out] */ VideoType_t *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SourceVideoType )( 
            IDshowVideoCaptureSource * This,
            /* [in] */ VideoType_t newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Connect )( 
            IDshowVideoCaptureSource * This,
            /* [retval][out] */ VARIANT_BOOL *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            IDshowVideoCaptureSource * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Run )( 
            IDshowVideoCaptureSource * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IDshowVideoCaptureSource * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ConnectedVideoType )( 
            IDshowVideoCaptureSource * This,
            /* [retval][out] */ VideoType_t *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LockImage )( 
            IDshowVideoCaptureSource * This,
            /* [retval][out] */ ImageInfo_t *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnlockImage )( 
            IDshowVideoCaptureSource * This);
        
        END_INTERFACE
    } IDshowVideoCaptureSourceVtbl;

    interface IDshowVideoCaptureSource
    {
        CONST_VTBL struct IDshowVideoCaptureSourceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDshowVideoCaptureSource_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDshowVideoCaptureSource_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDshowVideoCaptureSource_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDshowVideoCaptureSource_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDshowVideoCaptureSource_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDshowVideoCaptureSource_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDshowVideoCaptureSource_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDshowVideoCaptureSource_get_DisplayName(This,pVal)	\
    ( (This)->lpVtbl -> get_DisplayName(This,pVal) ) 

#define IDshowVideoCaptureSource_get_FriendlyName(This,pVal)	\
    ( (This)->lpVtbl -> get_FriendlyName(This,pVal) ) 

#define IDshowVideoCaptureSource_get_SourceVideoType(This,pVal)	\
    ( (This)->lpVtbl -> get_SourceVideoType(This,pVal) ) 

#define IDshowVideoCaptureSource_put_SourceVideoType(This,newVal)	\
    ( (This)->lpVtbl -> put_SourceVideoType(This,newVal) ) 

#define IDshowVideoCaptureSource_Connect(This,ret)	\
    ( (This)->lpVtbl -> Connect(This,ret) ) 

#define IDshowVideoCaptureSource_Disconnect(This)	\
    ( (This)->lpVtbl -> Disconnect(This) ) 

#define IDshowVideoCaptureSource_Run(This)	\
    ( (This)->lpVtbl -> Run(This) ) 

#define IDshowVideoCaptureSource_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#define IDshowVideoCaptureSource_get_ConnectedVideoType(This,pVal)	\
    ( (This)->lpVtbl -> get_ConnectedVideoType(This,pVal) ) 

#define IDshowVideoCaptureSource_LockImage(This,ret)	\
    ( (This)->lpVtbl -> LockImage(This,ret) ) 

#define IDshowVideoCaptureSource_UnlockImage(This)	\
    ( (This)->lpVtbl -> UnlockImage(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDshowVideoCaptureSource_INTERFACE_DEFINED__ */


#ifndef __IEnumVideoCaptureSources_INTERFACE_DEFINED__
#define __IEnumVideoCaptureSources_INTERFACE_DEFINED__

/* interface IEnumVideoCaptureSources */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IEnumVideoCaptureSources;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9B0219FC-C2E6-4B38-B86A-98E03C1BEBA8")
    IEnumVideoCaptureSources : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppUnk) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IDshowVideoCaptureSource **pVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumVideoCaptureSourcesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumVideoCaptureSources * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumVideoCaptureSources * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumVideoCaptureSources * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEnumVideoCaptureSources * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEnumVideoCaptureSources * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEnumVideoCaptureSources * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEnumVideoCaptureSources * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IEnumVideoCaptureSources * This,
            /* [retval][out] */ IUnknown **ppUnk);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IEnumVideoCaptureSources * This,
            /* [in] */ long Index,
            /* [retval][out] */ IDshowVideoCaptureSource **pVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IEnumVideoCaptureSources * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } IEnumVideoCaptureSourcesVtbl;

    interface IEnumVideoCaptureSources
    {
        CONST_VTBL struct IEnumVideoCaptureSourcesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumVideoCaptureSources_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumVideoCaptureSources_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumVideoCaptureSources_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumVideoCaptureSources_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IEnumVideoCaptureSources_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IEnumVideoCaptureSources_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IEnumVideoCaptureSources_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IEnumVideoCaptureSources_get__NewEnum(This,ppUnk)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppUnk) ) 

#define IEnumVideoCaptureSources_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IEnumVideoCaptureSources_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumVideoCaptureSources_INTERFACE_DEFINED__ */


#ifndef __IStaticClock_INTERFACE_DEFINED__
#define __IStaticClock_INTERFACE_DEFINED__

/* interface IStaticClock */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IStaticClock;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("866ECE9B-A45F-42CF-8CAF-DC8B31B78177")
    IStaticClock : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Now( 
            /* [in] */ LONGLONG newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IStaticClockVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IStaticClock * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IStaticClock * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IStaticClock * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IStaticClock * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IStaticClock * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IStaticClock * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IStaticClock * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Now )( 
            IStaticClock * This,
            /* [in] */ LONGLONG newVal);
        
        END_INTERFACE
    } IStaticClockVtbl;

    interface IStaticClock
    {
        CONST_VTBL struct IStaticClockVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStaticClock_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IStaticClock_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IStaticClock_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IStaticClock_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IStaticClock_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IStaticClock_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IStaticClock_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IStaticClock_put_Now(This,newVal)	\
    ( (This)->lpVtbl -> put_Now(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IStaticClock_INTERFACE_DEFINED__ */


#ifndef __IDIMager_INTERFACE_DEFINED__
#define __IDIMager_INTERFACE_DEFINED__

/* interface IDIMager */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDIMager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CC0FCAFE-7C5A-4F04-A8A4-D8C26A991155")
    IDIMager : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetImageKN( 
            /* [in] */ LONG_PTR kdat,
            /* [in] */ LONG_PTR ndat) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DLLVersion( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FreqMode( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FreqMode( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SleepMode( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SleepMode( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SpeedMode( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SpeedMode( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitPara( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDIMagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDIMager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDIMager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDIMager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDIMager * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDIMager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDIMager * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDIMager * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetImageKN )( 
            IDIMager * This,
            /* [in] */ LONG_PTR kdat,
            /* [in] */ LONG_PTR ndat);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DLLVersion )( 
            IDIMager * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FreqMode )( 
            IDIMager * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FreqMode )( 
            IDIMager * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SleepMode )( 
            IDIMager * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SleepMode )( 
            IDIMager * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SpeedMode )( 
            IDIMager * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SpeedMode )( 
            IDIMager * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitPara )( 
            IDIMager * This);
        
        END_INTERFACE
    } IDIMagerVtbl;

    interface IDIMager
    {
        CONST_VTBL struct IDIMagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDIMager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDIMager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDIMager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDIMager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDIMager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDIMager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDIMager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDIMager_GetImageKN(This,kdat,ndat)	\
    ( (This)->lpVtbl -> GetImageKN(This,kdat,ndat) ) 

#define IDIMager_get_DLLVersion(This,pVal)	\
    ( (This)->lpVtbl -> get_DLLVersion(This,pVal) ) 

#define IDIMager_get_FreqMode(This,pVal)	\
    ( (This)->lpVtbl -> get_FreqMode(This,pVal) ) 

#define IDIMager_put_FreqMode(This,newVal)	\
    ( (This)->lpVtbl -> put_FreqMode(This,newVal) ) 

#define IDIMager_get_SleepMode(This,pVal)	\
    ( (This)->lpVtbl -> get_SleepMode(This,pVal) ) 

#define IDIMager_put_SleepMode(This,newVal)	\
    ( (This)->lpVtbl -> put_SleepMode(This,newVal) ) 

#define IDIMager_get_SpeedMode(This,pVal)	\
    ( (This)->lpVtbl -> get_SpeedMode(This,pVal) ) 

#define IDIMager_put_SpeedMode(This,newVal)	\
    ( (This)->lpVtbl -> put_SpeedMode(This,newVal) ) 

#define IDIMager_InitPara(This)	\
    ( (This)->lpVtbl -> InitPara(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDIMager_INTERFACE_DEFINED__ */


#ifndef __IFFmpegVideoPlayer_INTERFACE_DEFINED__
#define __IFFmpegVideoPlayer_INTERFACE_DEFINED__

/* interface IFFmpegVideoPlayer */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IFFmpegVideoPlayer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2A34DEC3-20A5-4E4D-9E05-97910CD9E7EA")
    IFFmpegVideoPlayer : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ BSTR videoFile,
            /* [retval][out] */ VARIANT_BOOL *ret) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SyncSource( 
            /* [retval][out] */ IClock **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SyncSource( 
            /* [in] */ IClock *newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LockImage( 
            /* [retval][out] */ ImageInfo_t info[ 4 ]) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnlockImage( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Run( 
            /* [in] */ LONGLONG timeBase) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PlayerState( 
            /* [retval][out] */ AV_PlayerState_t *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PacketQueueSize( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PacketQueueSize( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FrameQueueSize( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FrameQueueSize( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentPTS( 
            /* [retval][out] */ LONGLONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentFrame( 
            /* [retval][out] */ LONGLONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetQueueStats( 
            /* [retval][out] */ LONG ret[ 4 ]) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Seek( 
            /* [in] */ LONGLONG t) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Pause( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Resume( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFFmpegVideoPlayerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFFmpegVideoPlayer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFFmpegVideoPlayer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFFmpegVideoPlayer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFFmpegVideoPlayer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFFmpegVideoPlayer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFFmpegVideoPlayer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFFmpegVideoPlayer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IFFmpegVideoPlayer * This,
            /* [in] */ BSTR videoFile,
            /* [retval][out] */ VARIANT_BOOL *ret);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SyncSource )( 
            IFFmpegVideoPlayer * This,
            /* [retval][out] */ IClock **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SyncSource )( 
            IFFmpegVideoPlayer * This,
            /* [in] */ IClock *newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LockImage )( 
            IFFmpegVideoPlayer * This,
            /* [retval][out] */ ImageInfo_t info[ 4 ]);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnlockImage )( 
            IFFmpegVideoPlayer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Run )( 
            IFFmpegVideoPlayer * This,
            /* [in] */ LONGLONG timeBase);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PlayerState )( 
            IFFmpegVideoPlayer * This,
            /* [retval][out] */ AV_PlayerState_t *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PacketQueueSize )( 
            IFFmpegVideoPlayer * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PacketQueueSize )( 
            IFFmpegVideoPlayer * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FrameQueueSize )( 
            IFFmpegVideoPlayer * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FrameQueueSize )( 
            IFFmpegVideoPlayer * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentPTS )( 
            IFFmpegVideoPlayer * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentFrame )( 
            IFFmpegVideoPlayer * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetQueueStats )( 
            IFFmpegVideoPlayer * This,
            /* [retval][out] */ LONG ret[ 4 ]);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IFFmpegVideoPlayer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Seek )( 
            IFFmpegVideoPlayer * This,
            /* [in] */ LONGLONG t);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Pause )( 
            IFFmpegVideoPlayer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Resume )( 
            IFFmpegVideoPlayer * This);
        
        END_INTERFACE
    } IFFmpegVideoPlayerVtbl;

    interface IFFmpegVideoPlayer
    {
        CONST_VTBL struct IFFmpegVideoPlayerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFFmpegVideoPlayer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFFmpegVideoPlayer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFFmpegVideoPlayer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFFmpegVideoPlayer_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFFmpegVideoPlayer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFFmpegVideoPlayer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFFmpegVideoPlayer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFFmpegVideoPlayer_Open(This,videoFile,ret)	\
    ( (This)->lpVtbl -> Open(This,videoFile,ret) ) 

#define IFFmpegVideoPlayer_get_SyncSource(This,pVal)	\
    ( (This)->lpVtbl -> get_SyncSource(This,pVal) ) 

#define IFFmpegVideoPlayer_put_SyncSource(This,newVal)	\
    ( (This)->lpVtbl -> put_SyncSource(This,newVal) ) 

#define IFFmpegVideoPlayer_LockImage(This,info)	\
    ( (This)->lpVtbl -> LockImage(This,info) ) 

#define IFFmpegVideoPlayer_UnlockImage(This)	\
    ( (This)->lpVtbl -> UnlockImage(This) ) 

#define IFFmpegVideoPlayer_Run(This,timeBase)	\
    ( (This)->lpVtbl -> Run(This,timeBase) ) 

#define IFFmpegVideoPlayer_get_PlayerState(This,pVal)	\
    ( (This)->lpVtbl -> get_PlayerState(This,pVal) ) 

#define IFFmpegVideoPlayer_get_PacketQueueSize(This,pVal)	\
    ( (This)->lpVtbl -> get_PacketQueueSize(This,pVal) ) 

#define IFFmpegVideoPlayer_put_PacketQueueSize(This,newVal)	\
    ( (This)->lpVtbl -> put_PacketQueueSize(This,newVal) ) 

#define IFFmpegVideoPlayer_get_FrameQueueSize(This,pVal)	\
    ( (This)->lpVtbl -> get_FrameQueueSize(This,pVal) ) 

#define IFFmpegVideoPlayer_put_FrameQueueSize(This,newVal)	\
    ( (This)->lpVtbl -> put_FrameQueueSize(This,newVal) ) 

#define IFFmpegVideoPlayer_get_CurrentPTS(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentPTS(This,pVal) ) 

#define IFFmpegVideoPlayer_get_CurrentFrame(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentFrame(This,pVal) ) 

#define IFFmpegVideoPlayer_GetQueueStats(This,ret)	\
    ( (This)->lpVtbl -> GetQueueStats(This,ret) ) 

#define IFFmpegVideoPlayer_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IFFmpegVideoPlayer_Seek(This,t)	\
    ( (This)->lpVtbl -> Seek(This,t) ) 

#define IFFmpegVideoPlayer_Pause(This)	\
    ( (This)->lpVtbl -> Pause(This) ) 

#define IFFmpegVideoPlayer_Resume(This)	\
    ( (This)->lpVtbl -> Resume(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFFmpegVideoPlayer_INTERFACE_DEFINED__ */


#ifndef __IVideoStreamPlayer_INTERFACE_DEFINED__
#define __IVideoStreamPlayer_INTERFACE_DEFINED__

/* interface IVideoStreamPlayer */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IVideoStreamPlayer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CFBFBAE1-E64E-4E6C-B174-71AAF82BE9DF")
    IVideoStreamPlayer : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ BSTR streamName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Run( 
            /* [in] */ LONGLONG timeBase) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LockImage( 
            /* [retval][out] */ ImageInfo_t info[ 4 ]) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnlockImage( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetQueueStats( 
            /* [retval][out] */ LONG ret[ 4 ]) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PlayerState( 
            /* [retval][out] */ AV_PlayerState_t *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PacketQueueSize( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PacketQueueSize( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FrameQueueSize( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FrameQueueSize( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentPTS( 
            /* [retval][out] */ LONGLONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentFrame( 
            /* [retval][out] */ LONGLONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FrameSize( 
            /* [retval][out] */ Size_t *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SyncSource( 
            /* [retval][out] */ IClock **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SyncSource( 
            /* [in] */ IClock *newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVideoStreamPlayerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVideoStreamPlayer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVideoStreamPlayer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVideoStreamPlayer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IVideoStreamPlayer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IVideoStreamPlayer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IVideoStreamPlayer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IVideoStreamPlayer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IVideoStreamPlayer * This,
            /* [in] */ BSTR streamName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IVideoStreamPlayer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Run )( 
            IVideoStreamPlayer * This,
            /* [in] */ LONGLONG timeBase);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LockImage )( 
            IVideoStreamPlayer * This,
            /* [retval][out] */ ImageInfo_t info[ 4 ]);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnlockImage )( 
            IVideoStreamPlayer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetQueueStats )( 
            IVideoStreamPlayer * This,
            /* [retval][out] */ LONG ret[ 4 ]);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PlayerState )( 
            IVideoStreamPlayer * This,
            /* [retval][out] */ AV_PlayerState_t *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PacketQueueSize )( 
            IVideoStreamPlayer * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PacketQueueSize )( 
            IVideoStreamPlayer * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FrameQueueSize )( 
            IVideoStreamPlayer * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FrameQueueSize )( 
            IVideoStreamPlayer * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentPTS )( 
            IVideoStreamPlayer * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentFrame )( 
            IVideoStreamPlayer * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FrameSize )( 
            IVideoStreamPlayer * This,
            /* [retval][out] */ Size_t *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SyncSource )( 
            IVideoStreamPlayer * This,
            /* [retval][out] */ IClock **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SyncSource )( 
            IVideoStreamPlayer * This,
            /* [in] */ IClock *newVal);
        
        END_INTERFACE
    } IVideoStreamPlayerVtbl;

    interface IVideoStreamPlayer
    {
        CONST_VTBL struct IVideoStreamPlayerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVideoStreamPlayer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVideoStreamPlayer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVideoStreamPlayer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVideoStreamPlayer_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IVideoStreamPlayer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IVideoStreamPlayer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IVideoStreamPlayer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IVideoStreamPlayer_Open(This,streamName)	\
    ( (This)->lpVtbl -> Open(This,streamName) ) 

#define IVideoStreamPlayer_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IVideoStreamPlayer_Run(This,timeBase)	\
    ( (This)->lpVtbl -> Run(This,timeBase) ) 

#define IVideoStreamPlayer_LockImage(This,info)	\
    ( (This)->lpVtbl -> LockImage(This,info) ) 

#define IVideoStreamPlayer_UnlockImage(This)	\
    ( (This)->lpVtbl -> UnlockImage(This) ) 

#define IVideoStreamPlayer_GetQueueStats(This,ret)	\
    ( (This)->lpVtbl -> GetQueueStats(This,ret) ) 

#define IVideoStreamPlayer_get_PlayerState(This,pVal)	\
    ( (This)->lpVtbl -> get_PlayerState(This,pVal) ) 

#define IVideoStreamPlayer_get_PacketQueueSize(This,pVal)	\
    ( (This)->lpVtbl -> get_PacketQueueSize(This,pVal) ) 

#define IVideoStreamPlayer_put_PacketQueueSize(This,newVal)	\
    ( (This)->lpVtbl -> put_PacketQueueSize(This,newVal) ) 

#define IVideoStreamPlayer_get_FrameQueueSize(This,pVal)	\
    ( (This)->lpVtbl -> get_FrameQueueSize(This,pVal) ) 

#define IVideoStreamPlayer_put_FrameQueueSize(This,newVal)	\
    ( (This)->lpVtbl -> put_FrameQueueSize(This,newVal) ) 

#define IVideoStreamPlayer_get_CurrentPTS(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentPTS(This,pVal) ) 

#define IVideoStreamPlayer_get_CurrentFrame(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentFrame(This,pVal) ) 

#define IVideoStreamPlayer_get_FrameSize(This,pVal)	\
    ( (This)->lpVtbl -> get_FrameSize(This,pVal) ) 

#define IVideoStreamPlayer_get_SyncSource(This,pVal)	\
    ( (This)->lpVtbl -> get_SyncSource(This,pVal) ) 

#define IVideoStreamPlayer_put_SyncSource(This,newVal)	\
    ( (This)->lpVtbl -> put_SyncSource(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVideoStreamPlayer_INTERFACE_DEFINED__ */


#ifndef __IRoot_INTERFACE_DEFINED__
#define __IRoot_INTERFACE_DEFINED__

/* interface IRoot */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IRoot;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A4DB1DEC-5245-4F12-ABFC-AFE3D3F35D63")
    IRoot : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DebugTrace( 
            /* [in] */ BSTR msg) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UseSharedMemory( 
            /* [in] */ BSTR name,
            /* [in] */ MemoryType_t type,
            /* [in] */ LONG size,
            /* [retval][out] */ ISharedMemory **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateSharedMemoryFactory( 
            /* [in] */ MemoryType_t type,
            /* [in] */ LONG size,
            /* [retval][out] */ ISharedMemoryFactory **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UseSharedMemoryQueue( 
            /* [in] */ BSTR name,
            /* [in] */ LONG capacity,
            /* [in] */ ISharedMemoryFactory *factory,
            /* [retval][out] */ ISharedMemoryQueue **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UseSharedQueue( 
            /* [in] */ BSTR name,
            /* [in] */ LONG capacity,
            /* [in] */ LONG maxMsgSize,
            /* [retval][out] */ ISharedQueue **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UseSharedImage( 
            /* [in] */ BSTR name,
            /* [in] */ ImageType_t type,
            /* [in] */ Size_t size,
            /* [retval][out] */ ISharedImage **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumSharedMemoryNames( 
            /* [retval][out] */ IEnumSharedMemoryNames **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RefreshSharedMemoryNames( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CastAsSharedImage( 
            /* [in] */ ISharedMemory *in,
            /* [retval][out] */ ISharedImage **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CastAsSharedMemoryQueue( 
            /* [in] */ ISharedMemory *in,
            /* [retval][out] */ ISharedMemoryQueue **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CastAsSharedQueue( 
            /* [in] */ ISharedMemory *in,
            /* [retval][out] */ ISharedQueue **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDIBitsToDevice( 
            /* [in] */ LONG_PTR hdc,
            /* [in] */ Rect_t dstROI,
            /* [in] */ Point_t srcPos,
            /* [in] */ BitmapInfo_t srcBitmapInfo,
            /* [in] */ LONG_PTR src) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StretchDIBits( 
            /* [in] */ LONG_PTR hdc,
            /* [in] */ Rect_t dstROI,
            /* [in] */ Rect_t srcROI,
            /* [in] */ BitmapInfo_t srcBitmapInfo,
            /* [in] */ LONG_PTR src,
            /* [in] */ ROP_t rop) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDC( 
            /* [in] */ LONG_PTR hwnd,
            /* [retval][out] */ LONG_PTR *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReleaseDC( 
            /* [in] */ LONG_PTR hwnd,
            /* [in] */ LONG_PTR hdc) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SwapChannels_8u_C3C4R( 
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t roiSize,
            /* [in] */ int dstOrder[ 4 ],
            /* [in] */ BYTE val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateSimpleTimer( 
            /* [in] */ float fps,
            /* [retval][out] */ ISimpleTimer **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateOneShotTimer( 
            /* [in] */ DWORD delay,
            /* [retval][out] */ ISimpleTimer **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadGraphFile( 
            /* [in] */ BSTR path,
            /* [retval][out] */ IUnknown **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Copy_8u_C1R( 
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateImageLoader( 
            /* [in] */ IDevIL *devil,
            /* [retval][out] */ IImageLoader **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Copy_8u_C3R( 
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Copy_8u_C4R( 
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Copy_8u_AC4C3R( 
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Copy_8u_C3AC4R( 
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateDevIL( 
            /* [retval][out] */ IDevIL **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateDshowMediaPlayer( 
            /* [retval][out] */ IDshowMediaPlayer **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UseSharedVideo( 
            /* [in] */ BSTR name,
            /* [in] */ ImageType_t type,
            /* [in] */ Size_t size,
            /* [in] */ VARIANT_BOOL writer,
            /* [retval][out] */ ISharedVideo **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CastAsSharedVideo( 
            /* [in] */ ISharedMemory *in,
            /* [retval][out] */ ISharedVideo **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateMediaClock( 
            /* [retval][out] */ IClock **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateHiResClock( 
            /* [retval][out] */ IClock **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateSyncClock( 
            /* [in] */ BSTR timeServer,
            /* [in] */ int port,
            /* [in] */ IClock *source,
            /* [retval][out] */ IClock **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateParallelBox( 
            /* [retval][out] */ IParallelBox **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateNativeClock( 
            /* [retval][out] */ IClock **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenEB3File( 
            /* [in] */ BSTR file,
            /* [retval][out] */ IEB3FileLoader **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Set_8u_C1R( 
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size,
            /* [in] */ LONG val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateRegularClock( 
            /* [in] */ LONG numerator,
            /* [in] */ LONG denominator,
            /* [retval][out] */ IClock **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumVideoCaptureSources( 
            /* [retval][out] */ IEnumVideoCaptureSources **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE YCbCr422ToBGR_C2C3R( 
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateStaticClock( 
            /* [retval][out] */ IClock **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenDIMager( 
            /* [retval][out] */ IDIMager **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateFFmpegVideoPlayer( 
            /* [retval][out] */ IFFmpegVideoPlayer **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateVideoStreamPlayer( 
            /* [retval][out] */ IVideoStreamPlayer **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE YCbCr422ToBGR_C2AC4R( 
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size,
            /* [in] */ BYTE val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SubdivisionLevel( 
            /* [in] */ int size,
            /* [in] */ int level,
            /* [retval][out] */ int *newSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Subdivision2D( 
            /* [in] */ LONG_PTR src,
            /* [in] */ Size_t srcSize,
            /* [in] */ int level,
            /* [in] */ LONG_PTR dst,
            /* [in] */ Size_t dstSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Set_8u_C4CR( 
            /* [in] */ LONG value,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Set_8u_C4R( 
            /* [in] */ BYTE value[ 4 ],
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE YUV420ToRGB_8u_P3AC4R( 
            /* [in] */ ImageInfo_t srcY,
            /* [in] */ ImageInfo_t srcU,
            /* [in] */ ImageInfo_t srcV,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE YCbCr420ToBGR_8u_P3C4R( 
            /* [in] */ ImageInfo_t srcY,
            /* [in] */ ImageInfo_t srcU,
            /* [in] */ ImageInfo_t srcV,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size,
            /* [in] */ BYTE val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Threshold_LTValGTVal_16u_C1R( 
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size,
            /* [in] */ long thresholdLT,
            /* [in] */ long valueLT,
            /* [in] */ long thresholdGT,
            /* [in] */ long valueGT) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Scale_16u8u_C1R( 
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Copy_8u_C1C4R( 
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RangeScale_16u8u_C1R( 
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size,
            /* [in] */ int thresholdLT,
            /* [in] */ int thresholdGT) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE YCbCr422ToBGR_8u_C2C3R( 
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateLAVMediaPlayer( 
            /* [retval][out] */ ILAVMediaPlayer **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SwapChannels_8u_C4IR( 
            /* [in] */ ImageInfo_t srcDst,
            /* [in] */ Size_t size,
            /* [in] */ int dstOrder[ 4 ]) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateImage_8u_C1( 
            /* [in] */ Size_t size,
            /* [retval][out] */ ImageInfo_t *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateImage_8u_C2( 
            /* [in] */ Size_t size,
            /* [retval][out] */ ImageInfo_t *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateImage_8u_C3( 
            /* [in] */ Size_t size,
            /* [retval][out] */ ImageInfo_t *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateImage_8u_C4( 
            /* [in] */ Size_t size,
            /* [retval][out] */ ImageInfo_t *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FreeImage( 
            /* [in] */ ImageInfo_t img) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE YCbCr420ToBGR_8u_P3C3R( 
            /* [in] */ ImageInfo_t srcY,
            /* [in] */ ImageInfo_t srcU,
            /* [in] */ ImageInfo_t srcV,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE YCbCr422ToBGR_8u_C2C4R( 
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size,
            /* [in] */ BYTE val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateAlphaMediaPlayer( 
            /* [retval][out] */ IAlphaMediaPlayer **ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeinterlaceFilterTriangle_8u_C1R( 
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size,
            /* [in] */ long centerWeight,
            /* [in] */ long layout) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeinterlaceFilterCAVT_8u_C1R( 
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size,
            /* [in] */ long threshold) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE YCbCr422_8u_C2P3R( 
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dstY,
            /* [in] */ ImageInfo_t dstU,
            /* [in] */ ImageInfo_t dstV,
            /* [in] */ Size_t size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE YCbCr422ToBGR_8u_P3C3R( 
            /* [in] */ ImageInfo_t srcY,
            /* [in] */ ImageInfo_t srcU,
            /* [in] */ ImageInfo_t srcV,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BGRToY_JPEG_8u_C3C1R( 
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Dup_8u_C1C3R( 
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Dup_8u_C1C4R( 
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRootVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRoot * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRoot * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRoot * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRoot * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRoot * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRoot * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRoot * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DebugTrace )( 
            IRoot * This,
            /* [in] */ BSTR msg);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UseSharedMemory )( 
            IRoot * This,
            /* [in] */ BSTR name,
            /* [in] */ MemoryType_t type,
            /* [in] */ LONG size,
            /* [retval][out] */ ISharedMemory **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateSharedMemoryFactory )( 
            IRoot * This,
            /* [in] */ MemoryType_t type,
            /* [in] */ LONG size,
            /* [retval][out] */ ISharedMemoryFactory **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UseSharedMemoryQueue )( 
            IRoot * This,
            /* [in] */ BSTR name,
            /* [in] */ LONG capacity,
            /* [in] */ ISharedMemoryFactory *factory,
            /* [retval][out] */ ISharedMemoryQueue **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UseSharedQueue )( 
            IRoot * This,
            /* [in] */ BSTR name,
            /* [in] */ LONG capacity,
            /* [in] */ LONG maxMsgSize,
            /* [retval][out] */ ISharedQueue **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UseSharedImage )( 
            IRoot * This,
            /* [in] */ BSTR name,
            /* [in] */ ImageType_t type,
            /* [in] */ Size_t size,
            /* [retval][out] */ ISharedImage **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumSharedMemoryNames )( 
            IRoot * This,
            /* [retval][out] */ IEnumSharedMemoryNames **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RefreshSharedMemoryNames )( 
            IRoot * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CastAsSharedImage )( 
            IRoot * This,
            /* [in] */ ISharedMemory *in,
            /* [retval][out] */ ISharedImage **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CastAsSharedMemoryQueue )( 
            IRoot * This,
            /* [in] */ ISharedMemory *in,
            /* [retval][out] */ ISharedMemoryQueue **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CastAsSharedQueue )( 
            IRoot * This,
            /* [in] */ ISharedMemory *in,
            /* [retval][out] */ ISharedQueue **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDIBitsToDevice )( 
            IRoot * This,
            /* [in] */ LONG_PTR hdc,
            /* [in] */ Rect_t dstROI,
            /* [in] */ Point_t srcPos,
            /* [in] */ BitmapInfo_t srcBitmapInfo,
            /* [in] */ LONG_PTR src);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StretchDIBits )( 
            IRoot * This,
            /* [in] */ LONG_PTR hdc,
            /* [in] */ Rect_t dstROI,
            /* [in] */ Rect_t srcROI,
            /* [in] */ BitmapInfo_t srcBitmapInfo,
            /* [in] */ LONG_PTR src,
            /* [in] */ ROP_t rop);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDC )( 
            IRoot * This,
            /* [in] */ LONG_PTR hwnd,
            /* [retval][out] */ LONG_PTR *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseDC )( 
            IRoot * This,
            /* [in] */ LONG_PTR hwnd,
            /* [in] */ LONG_PTR hdc);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SwapChannels_8u_C3C4R )( 
            IRoot * This,
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t roiSize,
            /* [in] */ int dstOrder[ 4 ],
            /* [in] */ BYTE val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateSimpleTimer )( 
            IRoot * This,
            /* [in] */ float fps,
            /* [retval][out] */ ISimpleTimer **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateOneShotTimer )( 
            IRoot * This,
            /* [in] */ DWORD delay,
            /* [retval][out] */ ISimpleTimer **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadGraphFile )( 
            IRoot * This,
            /* [in] */ BSTR path,
            /* [retval][out] */ IUnknown **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy_8u_C1R )( 
            IRoot * This,
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateImageLoader )( 
            IRoot * This,
            /* [in] */ IDevIL *devil,
            /* [retval][out] */ IImageLoader **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy_8u_C3R )( 
            IRoot * This,
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy_8u_C4R )( 
            IRoot * This,
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy_8u_AC4C3R )( 
            IRoot * This,
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy_8u_C3AC4R )( 
            IRoot * This,
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateDevIL )( 
            IRoot * This,
            /* [retval][out] */ IDevIL **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateDshowMediaPlayer )( 
            IRoot * This,
            /* [retval][out] */ IDshowMediaPlayer **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UseSharedVideo )( 
            IRoot * This,
            /* [in] */ BSTR name,
            /* [in] */ ImageType_t type,
            /* [in] */ Size_t size,
            /* [in] */ VARIANT_BOOL writer,
            /* [retval][out] */ ISharedVideo **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CastAsSharedVideo )( 
            IRoot * This,
            /* [in] */ ISharedMemory *in,
            /* [retval][out] */ ISharedVideo **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateMediaClock )( 
            IRoot * This,
            /* [retval][out] */ IClock **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateHiResClock )( 
            IRoot * This,
            /* [retval][out] */ IClock **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateSyncClock )( 
            IRoot * This,
            /* [in] */ BSTR timeServer,
            /* [in] */ int port,
            /* [in] */ IClock *source,
            /* [retval][out] */ IClock **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateParallelBox )( 
            IRoot * This,
            /* [retval][out] */ IParallelBox **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateNativeClock )( 
            IRoot * This,
            /* [retval][out] */ IClock **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenEB3File )( 
            IRoot * This,
            /* [in] */ BSTR file,
            /* [retval][out] */ IEB3FileLoader **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Set_8u_C1R )( 
            IRoot * This,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size,
            /* [in] */ LONG val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateRegularClock )( 
            IRoot * This,
            /* [in] */ LONG numerator,
            /* [in] */ LONG denominator,
            /* [retval][out] */ IClock **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumVideoCaptureSources )( 
            IRoot * This,
            /* [retval][out] */ IEnumVideoCaptureSources **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *YCbCr422ToBGR_C2C3R )( 
            IRoot * This,
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateStaticClock )( 
            IRoot * This,
            /* [retval][out] */ IClock **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenDIMager )( 
            IRoot * This,
            /* [retval][out] */ IDIMager **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateFFmpegVideoPlayer )( 
            IRoot * This,
            /* [retval][out] */ IFFmpegVideoPlayer **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateVideoStreamPlayer )( 
            IRoot * This,
            /* [retval][out] */ IVideoStreamPlayer **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *YCbCr422ToBGR_C2AC4R )( 
            IRoot * This,
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size,
            /* [in] */ BYTE val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SubdivisionLevel )( 
            IRoot * This,
            /* [in] */ int size,
            /* [in] */ int level,
            /* [retval][out] */ int *newSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Subdivision2D )( 
            IRoot * This,
            /* [in] */ LONG_PTR src,
            /* [in] */ Size_t srcSize,
            /* [in] */ int level,
            /* [in] */ LONG_PTR dst,
            /* [in] */ Size_t dstSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Set_8u_C4CR )( 
            IRoot * This,
            /* [in] */ LONG value,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Set_8u_C4R )( 
            IRoot * This,
            /* [in] */ BYTE value[ 4 ],
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *YUV420ToRGB_8u_P3AC4R )( 
            IRoot * This,
            /* [in] */ ImageInfo_t srcY,
            /* [in] */ ImageInfo_t srcU,
            /* [in] */ ImageInfo_t srcV,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *YCbCr420ToBGR_8u_P3C4R )( 
            IRoot * This,
            /* [in] */ ImageInfo_t srcY,
            /* [in] */ ImageInfo_t srcU,
            /* [in] */ ImageInfo_t srcV,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size,
            /* [in] */ BYTE val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Threshold_LTValGTVal_16u_C1R )( 
            IRoot * This,
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size,
            /* [in] */ long thresholdLT,
            /* [in] */ long valueLT,
            /* [in] */ long thresholdGT,
            /* [in] */ long valueGT);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Scale_16u8u_C1R )( 
            IRoot * This,
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy_8u_C1C4R )( 
            IRoot * This,
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RangeScale_16u8u_C1R )( 
            IRoot * This,
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size,
            /* [in] */ int thresholdLT,
            /* [in] */ int thresholdGT);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *YCbCr422ToBGR_8u_C2C3R )( 
            IRoot * This,
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateLAVMediaPlayer )( 
            IRoot * This,
            /* [retval][out] */ ILAVMediaPlayer **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SwapChannels_8u_C4IR )( 
            IRoot * This,
            /* [in] */ ImageInfo_t srcDst,
            /* [in] */ Size_t size,
            /* [in] */ int dstOrder[ 4 ]);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateImage_8u_C1 )( 
            IRoot * This,
            /* [in] */ Size_t size,
            /* [retval][out] */ ImageInfo_t *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateImage_8u_C2 )( 
            IRoot * This,
            /* [in] */ Size_t size,
            /* [retval][out] */ ImageInfo_t *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateImage_8u_C3 )( 
            IRoot * This,
            /* [in] */ Size_t size,
            /* [retval][out] */ ImageInfo_t *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateImage_8u_C4 )( 
            IRoot * This,
            /* [in] */ Size_t size,
            /* [retval][out] */ ImageInfo_t *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FreeImage )( 
            IRoot * This,
            /* [in] */ ImageInfo_t img);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *YCbCr420ToBGR_8u_P3C3R )( 
            IRoot * This,
            /* [in] */ ImageInfo_t srcY,
            /* [in] */ ImageInfo_t srcU,
            /* [in] */ ImageInfo_t srcV,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *YCbCr422ToBGR_8u_C2C4R )( 
            IRoot * This,
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size,
            /* [in] */ BYTE val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateAlphaMediaPlayer )( 
            IRoot * This,
            /* [retval][out] */ IAlphaMediaPlayer **ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeinterlaceFilterTriangle_8u_C1R )( 
            IRoot * This,
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size,
            /* [in] */ long centerWeight,
            /* [in] */ long layout);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeinterlaceFilterCAVT_8u_C1R )( 
            IRoot * This,
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size,
            /* [in] */ long threshold);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *YCbCr422_8u_C2P3R )( 
            IRoot * This,
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dstY,
            /* [in] */ ImageInfo_t dstU,
            /* [in] */ ImageInfo_t dstV,
            /* [in] */ Size_t size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *YCbCr422ToBGR_8u_P3C3R )( 
            IRoot * This,
            /* [in] */ ImageInfo_t srcY,
            /* [in] */ ImageInfo_t srcU,
            /* [in] */ ImageInfo_t srcV,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BGRToY_JPEG_8u_C3C1R )( 
            IRoot * This,
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Dup_8u_C1C3R )( 
            IRoot * This,
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Dup_8u_C1C4R )( 
            IRoot * This,
            /* [in] */ ImageInfo_t src,
            /* [in] */ ImageInfo_t dst,
            /* [in] */ Size_t size);
        
        END_INTERFACE
    } IRootVtbl;

    interface IRoot
    {
        CONST_VTBL struct IRootVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRoot_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRoot_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRoot_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRoot_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRoot_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRoot_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRoot_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRoot_DebugTrace(This,msg)	\
    ( (This)->lpVtbl -> DebugTrace(This,msg) ) 

#define IRoot_UseSharedMemory(This,name,type,size,ret)	\
    ( (This)->lpVtbl -> UseSharedMemory(This,name,type,size,ret) ) 

#define IRoot_CreateSharedMemoryFactory(This,type,size,ret)	\
    ( (This)->lpVtbl -> CreateSharedMemoryFactory(This,type,size,ret) ) 

#define IRoot_UseSharedMemoryQueue(This,name,capacity,factory,ret)	\
    ( (This)->lpVtbl -> UseSharedMemoryQueue(This,name,capacity,factory,ret) ) 

#define IRoot_UseSharedQueue(This,name,capacity,maxMsgSize,ret)	\
    ( (This)->lpVtbl -> UseSharedQueue(This,name,capacity,maxMsgSize,ret) ) 

#define IRoot_UseSharedImage(This,name,type,size,ret)	\
    ( (This)->lpVtbl -> UseSharedImage(This,name,type,size,ret) ) 

#define IRoot_EnumSharedMemoryNames(This,ret)	\
    ( (This)->lpVtbl -> EnumSharedMemoryNames(This,ret) ) 

#define IRoot_RefreshSharedMemoryNames(This)	\
    ( (This)->lpVtbl -> RefreshSharedMemoryNames(This) ) 

#define IRoot_CastAsSharedImage(This,in,ret)	\
    ( (This)->lpVtbl -> CastAsSharedImage(This,in,ret) ) 

#define IRoot_CastAsSharedMemoryQueue(This,in,ret)	\
    ( (This)->lpVtbl -> CastAsSharedMemoryQueue(This,in,ret) ) 

#define IRoot_CastAsSharedQueue(This,in,ret)	\
    ( (This)->lpVtbl -> CastAsSharedQueue(This,in,ret) ) 

#define IRoot_SetDIBitsToDevice(This,hdc,dstROI,srcPos,srcBitmapInfo,src)	\
    ( (This)->lpVtbl -> SetDIBitsToDevice(This,hdc,dstROI,srcPos,srcBitmapInfo,src) ) 

#define IRoot_StretchDIBits(This,hdc,dstROI,srcROI,srcBitmapInfo,src,rop)	\
    ( (This)->lpVtbl -> StretchDIBits(This,hdc,dstROI,srcROI,srcBitmapInfo,src,rop) ) 

#define IRoot_GetDC(This,hwnd,ret)	\
    ( (This)->lpVtbl -> GetDC(This,hwnd,ret) ) 

#define IRoot_ReleaseDC(This,hwnd,hdc)	\
    ( (This)->lpVtbl -> ReleaseDC(This,hwnd,hdc) ) 

#define IRoot_SwapChannels_8u_C3C4R(This,src,dst,roiSize,dstOrder,val)	\
    ( (This)->lpVtbl -> SwapChannels_8u_C3C4R(This,src,dst,roiSize,dstOrder,val) ) 

#define IRoot_CreateSimpleTimer(This,fps,ret)	\
    ( (This)->lpVtbl -> CreateSimpleTimer(This,fps,ret) ) 

#define IRoot_CreateOneShotTimer(This,delay,ret)	\
    ( (This)->lpVtbl -> CreateOneShotTimer(This,delay,ret) ) 

#define IRoot_LoadGraphFile(This,path,ret)	\
    ( (This)->lpVtbl -> LoadGraphFile(This,path,ret) ) 

#define IRoot_Copy_8u_C1R(This,src,dst,size)	\
    ( (This)->lpVtbl -> Copy_8u_C1R(This,src,dst,size) ) 

#define IRoot_CreateImageLoader(This,devil,ret)	\
    ( (This)->lpVtbl -> CreateImageLoader(This,devil,ret) ) 

#define IRoot_Copy_8u_C3R(This,src,dst,size)	\
    ( (This)->lpVtbl -> Copy_8u_C3R(This,src,dst,size) ) 

#define IRoot_Copy_8u_C4R(This,src,dst,size)	\
    ( (This)->lpVtbl -> Copy_8u_C4R(This,src,dst,size) ) 

#define IRoot_Copy_8u_AC4C3R(This,src,dst,size)	\
    ( (This)->lpVtbl -> Copy_8u_AC4C3R(This,src,dst,size) ) 

#define IRoot_Copy_8u_C3AC4R(This,src,dst,size)	\
    ( (This)->lpVtbl -> Copy_8u_C3AC4R(This,src,dst,size) ) 

#define IRoot_CreateDevIL(This,ret)	\
    ( (This)->lpVtbl -> CreateDevIL(This,ret) ) 

#define IRoot_CreateDshowMediaPlayer(This,ret)	\
    ( (This)->lpVtbl -> CreateDshowMediaPlayer(This,ret) ) 

#define IRoot_UseSharedVideo(This,name,type,size,writer,ret)	\
    ( (This)->lpVtbl -> UseSharedVideo(This,name,type,size,writer,ret) ) 

#define IRoot_CastAsSharedVideo(This,in,ret)	\
    ( (This)->lpVtbl -> CastAsSharedVideo(This,in,ret) ) 

#define IRoot_CreateMediaClock(This,ret)	\
    ( (This)->lpVtbl -> CreateMediaClock(This,ret) ) 

#define IRoot_CreateHiResClock(This,ret)	\
    ( (This)->lpVtbl -> CreateHiResClock(This,ret) ) 

#define IRoot_CreateSyncClock(This,timeServer,port,source,ret)	\
    ( (This)->lpVtbl -> CreateSyncClock(This,timeServer,port,source,ret) ) 

#define IRoot_CreateParallelBox(This,ret)	\
    ( (This)->lpVtbl -> CreateParallelBox(This,ret) ) 

#define IRoot_CreateNativeClock(This,ret)	\
    ( (This)->lpVtbl -> CreateNativeClock(This,ret) ) 

#define IRoot_OpenEB3File(This,file,ret)	\
    ( (This)->lpVtbl -> OpenEB3File(This,file,ret) ) 

#define IRoot_Set_8u_C1R(This,dst,size,val)	\
    ( (This)->lpVtbl -> Set_8u_C1R(This,dst,size,val) ) 

#define IRoot_CreateRegularClock(This,numerator,denominator,ret)	\
    ( (This)->lpVtbl -> CreateRegularClock(This,numerator,denominator,ret) ) 

#define IRoot_EnumVideoCaptureSources(This,ret)	\
    ( (This)->lpVtbl -> EnumVideoCaptureSources(This,ret) ) 

#define IRoot_YCbCr422ToBGR_C2C3R(This,src,dst,size)	\
    ( (This)->lpVtbl -> YCbCr422ToBGR_C2C3R(This,src,dst,size) ) 

#define IRoot_CreateStaticClock(This,ret)	\
    ( (This)->lpVtbl -> CreateStaticClock(This,ret) ) 

#define IRoot_OpenDIMager(This,ret)	\
    ( (This)->lpVtbl -> OpenDIMager(This,ret) ) 

#define IRoot_CreateFFmpegVideoPlayer(This,ret)	\
    ( (This)->lpVtbl -> CreateFFmpegVideoPlayer(This,ret) ) 

#define IRoot_CreateVideoStreamPlayer(This,ret)	\
    ( (This)->lpVtbl -> CreateVideoStreamPlayer(This,ret) ) 

#define IRoot_YCbCr422ToBGR_C2AC4R(This,src,dst,size,val)	\
    ( (This)->lpVtbl -> YCbCr422ToBGR_C2AC4R(This,src,dst,size,val) ) 

#define IRoot_SubdivisionLevel(This,size,level,newSize)	\
    ( (This)->lpVtbl -> SubdivisionLevel(This,size,level,newSize) ) 

#define IRoot_Subdivision2D(This,src,srcSize,level,dst,dstSize)	\
    ( (This)->lpVtbl -> Subdivision2D(This,src,srcSize,level,dst,dstSize) ) 

#define IRoot_Set_8u_C4CR(This,value,dst,size)	\
    ( (This)->lpVtbl -> Set_8u_C4CR(This,value,dst,size) ) 

#define IRoot_Set_8u_C4R(This,value,dst,size)	\
    ( (This)->lpVtbl -> Set_8u_C4R(This,value,dst,size) ) 

#define IRoot_YUV420ToRGB_8u_P3AC4R(This,srcY,srcU,srcV,dst,size)	\
    ( (This)->lpVtbl -> YUV420ToRGB_8u_P3AC4R(This,srcY,srcU,srcV,dst,size) ) 

#define IRoot_YCbCr420ToBGR_8u_P3C4R(This,srcY,srcU,srcV,dst,size,val)	\
    ( (This)->lpVtbl -> YCbCr420ToBGR_8u_P3C4R(This,srcY,srcU,srcV,dst,size,val) ) 

#define IRoot_Threshold_LTValGTVal_16u_C1R(This,src,dst,size,thresholdLT,valueLT,thresholdGT,valueGT)	\
    ( (This)->lpVtbl -> Threshold_LTValGTVal_16u_C1R(This,src,dst,size,thresholdLT,valueLT,thresholdGT,valueGT) ) 

#define IRoot_Scale_16u8u_C1R(This,src,dst,size)	\
    ( (This)->lpVtbl -> Scale_16u8u_C1R(This,src,dst,size) ) 

#define IRoot_Copy_8u_C1C4R(This,src,dst,size)	\
    ( (This)->lpVtbl -> Copy_8u_C1C4R(This,src,dst,size) ) 

#define IRoot_RangeScale_16u8u_C1R(This,src,dst,size,thresholdLT,thresholdGT)	\
    ( (This)->lpVtbl -> RangeScale_16u8u_C1R(This,src,dst,size,thresholdLT,thresholdGT) ) 

#define IRoot_YCbCr422ToBGR_8u_C2C3R(This,src,dst,size)	\
    ( (This)->lpVtbl -> YCbCr422ToBGR_8u_C2C3R(This,src,dst,size) ) 

#define IRoot_CreateLAVMediaPlayer(This,ret)	\
    ( (This)->lpVtbl -> CreateLAVMediaPlayer(This,ret) ) 

#define IRoot_SwapChannels_8u_C4IR(This,srcDst,size,dstOrder)	\
    ( (This)->lpVtbl -> SwapChannels_8u_C4IR(This,srcDst,size,dstOrder) ) 

#define IRoot_CreateImage_8u_C1(This,size,ret)	\
    ( (This)->lpVtbl -> CreateImage_8u_C1(This,size,ret) ) 

#define IRoot_CreateImage_8u_C2(This,size,ret)	\
    ( (This)->lpVtbl -> CreateImage_8u_C2(This,size,ret) ) 

#define IRoot_CreateImage_8u_C3(This,size,ret)	\
    ( (This)->lpVtbl -> CreateImage_8u_C3(This,size,ret) ) 

#define IRoot_CreateImage_8u_C4(This,size,ret)	\
    ( (This)->lpVtbl -> CreateImage_8u_C4(This,size,ret) ) 

#define IRoot_FreeImage(This,img)	\
    ( (This)->lpVtbl -> FreeImage(This,img) ) 

#define IRoot_YCbCr420ToBGR_8u_P3C3R(This,srcY,srcU,srcV,dst,size)	\
    ( (This)->lpVtbl -> YCbCr420ToBGR_8u_P3C3R(This,srcY,srcU,srcV,dst,size) ) 

#define IRoot_YCbCr422ToBGR_8u_C2C4R(This,src,dst,size,val)	\
    ( (This)->lpVtbl -> YCbCr422ToBGR_8u_C2C4R(This,src,dst,size,val) ) 

#define IRoot_CreateAlphaMediaPlayer(This,ret)	\
    ( (This)->lpVtbl -> CreateAlphaMediaPlayer(This,ret) ) 

#define IRoot_DeinterlaceFilterTriangle_8u_C1R(This,src,dst,size,centerWeight,layout)	\
    ( (This)->lpVtbl -> DeinterlaceFilterTriangle_8u_C1R(This,src,dst,size,centerWeight,layout) ) 

#define IRoot_DeinterlaceFilterCAVT_8u_C1R(This,src,dst,size,threshold)	\
    ( (This)->lpVtbl -> DeinterlaceFilterCAVT_8u_C1R(This,src,dst,size,threshold) ) 

#define IRoot_YCbCr422_8u_C2P3R(This,src,dstY,dstU,dstV,size)	\
    ( (This)->lpVtbl -> YCbCr422_8u_C2P3R(This,src,dstY,dstU,dstV,size) ) 

#define IRoot_YCbCr422ToBGR_8u_P3C3R(This,srcY,srcU,srcV,dst,size)	\
    ( (This)->lpVtbl -> YCbCr422ToBGR_8u_P3C3R(This,srcY,srcU,srcV,dst,size) ) 

#define IRoot_BGRToY_JPEG_8u_C3C1R(This,src,dst,size)	\
    ( (This)->lpVtbl -> BGRToY_JPEG_8u_C3C1R(This,src,dst,size) ) 

#define IRoot_Dup_8u_C1C3R(This,src,dst,size)	\
    ( (This)->lpVtbl -> Dup_8u_C1C3R(This,src,dst,size) ) 

#define IRoot_Dup_8u_C1C4R(This,src,dst,size)	\
    ( (This)->lpVtbl -> Dup_8u_C1C4R(This,src,dst,size) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRoot_INTERFACE_DEFINED__ */



#ifndef __ZzCOMLib_LIBRARY_DEFINED__
#define __ZzCOMLib_LIBRARY_DEFINED__

/* library ZzCOMLib */
/* [helpstring][version][uuid] */ 





EXTERN_C const IID LIBID_ZzCOMLib;

EXTERN_C const CLSID CLSID_SharedMemoryFactory;

#ifdef __cplusplus

class DECLSPEC_UUID("66FDA126-D60D-4EDA-A9B5-BDEA3034F940")
SharedMemoryFactory;
#endif

EXTERN_C const CLSID CLSID_SharedMemoryQueue;

#ifdef __cplusplus

class DECLSPEC_UUID("F2AC1889-DF86-4DE8-8558-A9C634EF7E57")
SharedMemoryQueue;
#endif

EXTERN_C const CLSID CLSID_SharedMemory;

#ifdef __cplusplus

class DECLSPEC_UUID("444AA9DD-B439-4A1C-8AA6-6C73B629373A")
SharedMemory;
#endif

EXTERN_C const CLSID CLSID_Root;

#ifdef __cplusplus

class DECLSPEC_UUID("114A1E18-4107-4296-B650-C314B5BB030E")
ZzRoot;
#endif

EXTERN_C const CLSID CLSID_Detours;

#ifdef __cplusplus

class DECLSPEC_UUID("E378E8B6-4167-47FB-BE54-866A060C492C")
Detours;
#endif

EXTERN_C const CLSID CLSID_SharedImage;

#ifdef __cplusplus

class DECLSPEC_UUID("EF6511D0-24A1-4AB0-8624-8A107FC5CF84")
SharedImage;
#endif

EXTERN_C const CLSID CLSID_EnumSharedMemoryNames;

#ifdef __cplusplus

class DECLSPEC_UUID("6684722B-3D3D-48A0-86FF-27AB5450F491")
EnumSharedMemoryNames;
#endif

EXTERN_C const CLSID CLSID_SharedQueue;

#ifdef __cplusplus

class DECLSPEC_UUID("DBD622AD-5D03-4204-9B76-8A8F161EED53")
SharedQueue;
#endif

EXTERN_C const CLSID CLSID_SimpleTimer;

#ifdef __cplusplus

class DECLSPEC_UUID("F8DF9B0F-3742-45CF-8205-DFA63CCADAC2")
SimpleTimer;
#endif

EXTERN_C const CLSID CLSID_OneShotTimer;

#ifdef __cplusplus

class DECLSPEC_UUID("9355051F-4DAE-4F1A-910E-DD6AC5EE4ADC")
OneShotTimer;
#endif

EXTERN_C const CLSID CLSID_DshowMediaPlayer;

#ifdef __cplusplus

class DECLSPEC_UUID("D09B53DD-3913-48F1-92A1-1ECBEDB3EF72")
DshowMediaPlayer;
#endif

EXTERN_C const CLSID CLSID_DevIL;

#ifdef __cplusplus

class DECLSPEC_UUID("5400B79B-C796-42A8-AEAF-3AB5A8F8B491")
DevIL;
#endif

EXTERN_C const CLSID CLSID_ImageLoader;

#ifdef __cplusplus

class DECLSPEC_UUID("35420A04-5593-4920-8346-8E12B801190D")
ImageLoader;
#endif

EXTERN_C const CLSID CLSID_PendingImage;

#ifdef __cplusplus

class DECLSPEC_UUID("E25DDAB7-84DA-47BC-ACE1-B06D978337B3")
PendingImage;
#endif

EXTERN_C const CLSID CLSID_SharedVideo;

#ifdef __cplusplus

class DECLSPEC_UUID("118B04EA-89E4-4115-8751-379B3B577182")
SharedVideo;
#endif

EXTERN_C const CLSID CLSID_MediaClock;

#ifdef __cplusplus

class DECLSPEC_UUID("DB5EE62C-31AF-40A2-8F3B-64499397B167")
MediaClock;
#endif

EXTERN_C const CLSID CLSID_HiResClock;

#ifdef __cplusplus

class DECLSPEC_UUID("1F70FBA3-D6EC-4849-A6A5-2FCA64510493")
HiResClock;
#endif

EXTERN_C const CLSID CLSID_SyncClock;

#ifdef __cplusplus

class DECLSPEC_UUID("C8E21697-F130-428F-8F17-3254BCD93B77")
SyncClock;
#endif

EXTERN_C const CLSID CLSID_RegularClock;

#ifdef __cplusplus

class DECLSPEC_UUID("B4982DBF-4ACA-49BD-BF91-F98EA5545998")
RegularClock;
#endif

EXTERN_C const CLSID CLSID_ParallelBox;

#ifdef __cplusplus

class DECLSPEC_UUID("467C6300-3DE3-4551-8480-085981D10938")
ParallelBox;
#endif

EXTERN_C const CLSID CLSID_NativeClock;

#ifdef __cplusplus

class DECLSPEC_UUID("88C7A888-BF15-4BC6-AF30-F6D7CA4EAE80")
NativeClock;
#endif

EXTERN_C const CLSID CLSID_EB3FileLoader;

#ifdef __cplusplus

class DECLSPEC_UUID("A3BAC155-AB88-4661-BE08-E362E7B6683F")
EB3FileLoader;
#endif

EXTERN_C const CLSID CLSID_DshowVideoCaptureSource;

#ifdef __cplusplus

class DECLSPEC_UUID("95C5FE3C-9EE7-4682-A3E7-61241B032448")
DshowVideoCaptureSource;
#endif

EXTERN_C const CLSID CLSID_EnumVideoCaptureSources;

#ifdef __cplusplus

class DECLSPEC_UUID("2664D38D-14E8-499D-A459-3D0A8DB9CF65")
EnumVideoCaptureSources;
#endif

EXTERN_C const CLSID CLSID_StaticClock;

#ifdef __cplusplus

class DECLSPEC_UUID("9C6CCAFF-09BE-47E3-A87A-02E3E0CDAD4A")
StaticClock;
#endif

EXTERN_C const CLSID CLSID_DIMager;

#ifdef __cplusplus

class DECLSPEC_UUID("38473ED7-38CF-458A-B316-9A477FB07692")
DIMager;
#endif

EXTERN_C const CLSID CLSID_FFmpegVideoPlayer;

#ifdef __cplusplus

class DECLSPEC_UUID("F213808A-90CD-4DD3-A46A-56022B71F08C")
FFmpegVideoPlayer;
#endif

EXTERN_C const CLSID CLSID_VideoStreamPlayer;

#ifdef __cplusplus

class DECLSPEC_UUID("35EDCCD6-2190-4A62-A28A-10C8F0847F37")
VideoStreamPlayer;
#endif

EXTERN_C const CLSID CLSID_LAVMediaPlayer;

#ifdef __cplusplus

class DECLSPEC_UUID("7957423F-1FA1-4C04-9FD5-6325D3F732C9")
LAVMediaPlayer;
#endif

EXTERN_C const CLSID CLSID_AlphaMediaPlayer;

#ifdef __cplusplus

class DECLSPEC_UUID("823DA983-C585-41C2-ADB5-79F0F5FEAEF5")
AlphaMediaPlayer;
#endif
#endif /* __ZzCOMLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


