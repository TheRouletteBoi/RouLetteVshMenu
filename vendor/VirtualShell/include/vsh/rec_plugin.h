// Mysis rec_plugin.h v0.1
// 3141card (C style version)
#ifndef __REC_PLUGIN_H__
#define __REC_PLUGIN_H__

typedef struct rec_plugin_interface_t
{
	int32_t (*DoUnk0)(void); 
	int32_t (*start)(void); //RecStart
	int32_t (*stop)(void); //RecStop
	int32_t (*close)(int32_t isdiscard); 
	int32_t (*geti)(int32_t giprm);  // RecGetInfo
	int32_t (*md)(void * mdarg, int32_t); //RecSetInfo
	int32_t (*etis)(int32_t start_time_msec); //RecSetInfo
	int32_t (*etie)(int32_t end_time_msec); //RecSetInfo
} rec_plugin_interface;

rec_plugin_interface *rec_interface;

#endif // __REC_PLUGIN_H__
