#include <sys/prx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct sys_prx_dbg_get_module_list_t {
	uint64_t size;				
	uint32_t unk0;
	uint32_t max;
	sys_prx_user_p_prx_id_t idlist;
	uint32_t count;				// ?
	sys_prx_user_p_stop_level_t levellist;	
	uint32_t unk1;
} sys_prx_dbg_get_module_list_t;


typedef struct sys_prx_dbg_module_info_t {
	uint64_t size;				
	char name[30];				
	char version[2];			
	uint32_t modattribute;		
	uint32_t start_entry;		
	uint32_t stop_entry;		
	uint32_t all_segments_num;	
	sys_prx_user_pchar_t filename;	
	uint32_t filename_size;		
	uint32_t segments_num;		
	sys_prx_user_segment_vector_t segments;	
} sys_prx_dbg_module_info_t;

typedef struct sys_process_info_t {
	sys_pid_t pid;
	uint32_t status;
	uint32_t ppu_thread_count;
	uint32_t spu_thread_count;
	uint32_t raw_spu_count;
	sys_pid_t parent_pid;
	char * image_file_name;
	uint32_t memory_size;
	uint8_t osabi_type;
	uint8_t pad[3];
	uint64_t param_0x28;
	uint32_t param_0x30;
} sys_process_info_t;

// DEX Lv2Kernel Only
int sys_prx_dbg_get_module_id_list(sys_pid_t pid, sys_prx_dbg_get_module_list_t *pInfo)
{
	system_call_2(460,(uint32_t) pid, (uint32_t) pInfo );
	return_to_user_prog(int);
}

int sys_prx_dbg_get_module_info(sys_pid_t pid, sys_prx_id_t id, void * p)
{
	system_call_3(493,(uint32_t) pid,(uint32_t) id, (uint32_t) p);
	return_to_user_prog(int);
}

int sys_dbg_get_process_info(sys_pid_t pid, sys_process_info_t* info)
{
	system_call_2(914,(uint32_t) pid, (uint32_t) info);
	return_to_user_prog(int);
}
// DEX Lv2Kernel Only
int sys_dbg_get_process_list(sys_pid_t* pids, uint64_t* max, uint64_t* count)
{
	system_call_3(908,(uint32_t) pids,(uint64_t) max, (uint64_t) count);
	return_to_user_prog(int);
}
	//pokeq(0x8000000000084378ULL,0x4800002CE8010100ULL); // allow syscall_460
	//pokeq(0x80000000000845DCULL,0x48000038E80100F0ULL); // allow syscall_493

	//sys_prx_get_module_list_t prx_list;