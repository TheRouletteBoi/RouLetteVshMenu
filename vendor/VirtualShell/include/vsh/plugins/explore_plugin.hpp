#ifndef __EXPLORE_PLUGIN_HPP__
#define __EXPLORE_PLUGIN_HPP__

// Interface 1

class explore_plugin_interface_t
{
public:
    int(*DoUnk0)(int);									// 1 Parameter: int value 0 - 4
    int(*DoUnk1)(void);									// 0 Parameter: returns an interface
    int(*DoUnk2)(void);									// 0 Parameter: returns an interface
    int(*DoUnk3)(void);									// 0 Parameter: returns an uint[0x14 / 0x24]
    int(*DoUnk4)(void);									// 0 Parameter
    int(*DoUnk5)(void *, int);							// 2 Parameter: list[] {(reload_category game/network/..,reload_category_items game/...), command amount}  - send (sequences of)xmb command(s)
    int(*ExecXMBcommand)(const char *, void *, int);	// 3 Parameter: char* (open_list nocheck/...), void * callback(can be 0), 0
    int(*DoUnk7)(int, int);								// 2 Parameter:
    int(*DoUnk8)(void *, int, int);						// 3 Parameter:
    int(*DoUnk9)(void *, int, int);						// 3 Parameter: void *, void *, void *
    int(*DoUnk10)(int*, char *);						// 2 Parameter: char * , int * out
    int(*DoUnk11)(char *, char *, int *);				// 3 Parameter: char * query , char * attribute? , uint8 output[]
    int(*DoUnk12)(void *);								// 1 Parameter: struct
    int(*DoUnk13)(int);									// return 0 / 1 Parameter: int 0-9
    int(*DoUnk14)(int);									// return 0 / 2 Parameter: int 0-9,
    int(*DoUnk15)(int, int, int);						// 3 Parameter: int 0-9, ,
    int(*DoUnk16)(int, int, int);						// nullsub / 3 Parameter: int 0-9, ,
    int(*DoUnk17)(int, int, int*, int*, int*);			// 5 Parameter: int 0-9,
    int(*DoUnk18)(int);									// 1 Parameter:
    int(*DoUnk19)(int);									// 1 Parameter:
    int(*DoUnk20)(int, uint64_t);						// nullsub / PlayIndicate, 2 Parameter: , int value, (0 = show?, 1=update?, -1 = hide) -  (set_playing 0x%x 0x%llx 0x%llx 0x%llx 0x%llx")
    int(*DoUnk21)(void *);								// nullsub / 1 Parameter: uint * list (simply both parameter from 20/2 and 3rd terminating = -1)
    int(*DoUnk22)(void *);								// 0 Parameter / 1 Parameter:
    int(*DoUnk23)(void);								// -
    int(*DoUnk24)(void);								// 0 Parameter:
    int(*DoUnk25)(void);								// 0 Parameter: // get target id check
    int(*DoUnk26)(char *, char *);						// 2 Parameter: char * (TropViewMode/backup/FaustPreview...) , char * (group/fixed/on...)
    int(*DoUnk27)(void *);								// 1 Parameter: char *
    int(*DoUnk28)(char *, void *);						// 2 Parameter: char * (ReloadXil/AvcRoomItem/...), uint8 xml?_parameters[]
    int(*DoUnk29)(char *, void *);						// 2 Parameter: char * ,
};


#endif // __EXPLORE_PLUGIN_HPP__