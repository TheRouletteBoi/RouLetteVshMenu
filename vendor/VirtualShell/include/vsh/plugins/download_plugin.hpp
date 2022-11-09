#ifndef __DOWNLOAD_PLUGIN_HPP__
#define __DOWNLOAD_PLUGIN_HPP__

// Interface 1

class download_plugin_interface_t
{
public:
    int(*DoUnk0)(int);															// 1 Parameter: int (0-4) - "page_select_destination"
    int(*DoUnk1)(wchar_t * url);												// 1 Parameter: wchar_t * url
    int(*DoUnk2)(wchar_t * device_path);										// 1 Parameter: wchar_t * device_path?
    int(*DoUnk3)(int, wchar_t * url);											// 2 Parameter: int (0-4), wchar_t * url - first value == 5 => does PSN Login / "page_select_dst"
    int(*DoUnk4)(int, wchar_t * url, wchar_t *, int, int, uint64_t, uint64_t);	// 7 Parameter: , wchar_t * url,
    int(*DownloadURL)(int, wchar_t * url, wchar_t * device_path);				// 3 Parameter: int (0-4), wchar_t * url, wchar_t* device_path? - "page_progress"
    int(*DoUnk6)(wchar_t * mimeType, wchar_t *userdata);						// 2 Parameter: wchar_t * mimeType?, void * userdata?
    int(*DoUnk7)(wchar_t * url, wchar_t *mimeType, void * userdata);			// 3 Parameter: wchar_t* url, wchar_t* mimeType, void * userdata
    int(*DoUnk8)(void);															// 1 Parameter:
    int(*DoUnk9)(void *, int, int);												// 3 Parameter:
    int(*DoUnk10)(uint8_t);														// 1 Parameter: uint8_t -1/0 ?
    int(*DoUnk11)(int);															// 1 Parameter:
    int(*DoUnk12)(char *);														// 1 Parameter:
    int(*DoUnk13)(char *);														// 1 Parameter:
    int(*DoUnk14)(int, void *);													// 2 Parameter: int (0-4), unk_struct - "page_check_headers"
    int(*DoUnk15)(int);															// 1 Parameter: int (0-4) - "page_select_dst"
    int(*DoUnk16)(int, wchar_t *, wchar_t *, uint64_t, char *, char *, char *);	// 7 Parameter: - "page_progress"
    int(*DoUnk17)(int);															// 1 Parameter: int (0-4) - "page_select_device"
    int(*DoUnk18)(int, void *);													// 2 Parameter: int (0-4), unk_struct - "page_select_instant_play"
};


// Interface ACT0 (0x41435430)

class download_plufin_act0_t
{
public:
    int(*Action)(const char *);						// 1 Parameter: char * numbers (Interface 1, func 0)
};

#endif // __DOWNLOAD_PLUGIN_HPP__