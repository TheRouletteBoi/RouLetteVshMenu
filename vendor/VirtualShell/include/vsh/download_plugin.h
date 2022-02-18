#ifndef __DOWNLOAD_PLUGIN_H__
#define __DOWNLOAD_PLUGIN_H__
#include "vshtypes.h"


_VSH_BEGIN

typedef struct download_plugin_interface_t
{
	int32_t (*DoUnk0)(int);																// 1 Parameter: int (0-4) - "page_select_destination"
	int32_t (*DoUnk1)(wchar_t * url);													// 1 Parameter: wchar_t * url
	int32_t (*DoUnk2)(wchar_t * device_path);											// 1 Parameter: wchar_t * device_path?
	int32_t (*DoUnk3)(int, wchar_t *url);												// 2 Parameter: int (0-4), wchar_t * url - first value == 5 => does PSN Login / "page_select_dst"
	int32_t (*DoUnk4)(int, wchar_t * url, wchar_t *, int, int, uint64_t, uint64_t);     // 7 Parameter: , wchar_t * url,
	int32_t (*DownloadURL)(int, wchar_t * url, wchar_t * device_path);					// 3 Parameter: int (0-4), wchar_t * url, wchar_t* device_path? - "page_progress"
	int32_t (*DoUnk6)(wchar_t * mimeType, wchar_t *userdata);							// 2 Parameter: wchar_t * mimeType?, void * userdata?
	int32_t (*DoUnk7)(wchar_t * url, wchar_t *mimeType, void * userdata);				// 3 Parameter: wchar_t* url, wchar_t* mimeType, void * userdata
	int32_t (*DoUnk8)(void*);															// 1 Parameter:
	int32_t (*DoUnk9)(void*, int, int);													// 3 Parameter:
	int32_t (*DoUnk10)(uint8_t);														// 1 Parameter: uint8_t -1/0 ?
	int32_t (*DoUnk11)(int);															// 1 Parameter: void * unk?
	int32_t (*DoUnk12)(char *);															// 1 Parameter: void * unk
	int32_t (*DoUnk13)(char *);															// 1 Parameter: void * unk
	int32_t (*DoUnk14)(int, void *);													// 2 Parameter: int (0-4), unk_struct - "page_check_headers"
	int32_t (*DoUnk15)(int, int, int, int, uint64_t, uint64_t, uint64_t);               // 1 Parameter: int (0-4) - "page_select_dst"
	int32_t (*DoUnk16)(int, wchar_t *, wchar_t *, uint64_t, char *, char *, char *);    // 7 Parameter: - "page_progress"
	int32_t (*DoUnk17)(int);															// 1 Parameter: int (0-4) - "page_select_device"
	int32_t (*DoUnk18)(int, void *);													// 2 Parameter: int (0-4), unk_struct - "page_select_instant_play"
} download_plugin_interface;

typedef struct
{
	int32_t (*Action)(const char *);                   // 1 Parameter: char * numbers (Interface 1, func 0)
} download_act0_if;                                    // Interface ACT0


_VSH_END

#endif // __DOWNLOAD_PLUGIN_H__
