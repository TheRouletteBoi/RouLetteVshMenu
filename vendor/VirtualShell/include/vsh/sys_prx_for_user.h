#ifndef __SYS_PRX_FOR_USER_H__
#define __SYS_PRX_FOR_USER_H__
#include "vshtypes.h"
#include <sys/synchronization.h> // for sys_lwmutex_t
#include <sys/mempool.h> // for sys_mempool_t
#include <sys/spu_utility.h> // for sys_spu_image_t

_VSH_BEGIN
CDECL_BEGIN

// sysPrxForUser_02E20EC1  // Returns the address of the null byte terminator of the given string. 	const char* sysPrxForUser_2E20EC1(const char* s) 

sys_prx_id_t sysPrxForUser_0341BB97(void* addr);                   // sys_prx_get_module_id_by_address()
static sys_prx_id_t sys_prx_get_module_id_by_address(void* addr) { return sysPrxForUser_0341BB97(addr); }

int sysPrxForUser_04E83D2C(const char *str1,                       // _sys_strncmp()
                                  const char *str2,
                                  size_t num);
static int _sys_strncmp(const char* str1, const char* str2, size_t num) { return sysPrxForUser_04E83D2C(str1, str2, num); }

char *sysPrxForUser_052D29A6(char *dest,                           // _sys_strcat()
                                    const char *src);
static char* _sys_strcat(char* dest,const char* src) { return sysPrxForUser_052D29A6(dest, src); }

void *sysPrxForUser_05C65656(sys_mempool_t mempool);               // sys_mempool_try_allocate_block()
static void* sys_mempool_try_allocate_block(sys_mempool_t mempool) { return sysPrxForUser_05C65656(mempool); }

int sysPrxForUser_0618936B(char *s,                                // _sys_vsnprintf()
                                  size_t n,
                                  const char *fmt,
                                  va_list arg);
#define sys_vsnprintf sysPrxForUser_0618936B

int sysPrxForUser_06574237(char *str,                              // _sys_snprintf()
                                  size_t size,
                                  const char *fmt, ...);
#define sys_snprintf sysPrxForUser_06574237

// sysPrxForUser_094FF0D1  // ? sys_rsxaudio_... (3 params)
// sysPrxForUser_0FB028AF  // ? sys_memory/mmapper... (6 params)
// sysPrxForUser_121E5DA5  // ?

int sysPrxForUser_1573DC3F(sys_lwmutex_t *lwmutex,                 // sys_lwmutex_lock()
                                  usecond_t timeout);
static int sys_lwmutex_lock(sys_lwmutex_t* lwmutex, usecond_t timeout) { return sysPrxForUser_1573DC3F(lwmutex, timeout); }

char *sysPrxForUser_191F0C4A(const char *s,                        // _sys_strrchr()
                                    int c);

// sysPrxForUser_1AE10B92  // _sys_spu_printf_attach_thread
// int spu_printf_attach_thread(sys_spu_thread_t thread);

int sysPrxForUser_1BC200F4(sys_lwmutex_t *lwmutex);                // sys_lwmutex_unlock()
static int sys_lwmutex_unlock(sys_lwmutex_t* lwmutex) { return sysPrxForUser_1BC200F4(lwmutex); }

int sysPrxForUser_1C9A942C(sys_lwcond_t *lwcond);                  // sys_lwcond_destroy()
static int sys_lwcond_destroy(sys_lwcond_t* lwcond) { return sysPrxForUser_1C9A942C(lwcond); }

int sysPrxForUser_1CA525A2(const char *s1,                         // _sys_strncasecmp()
                                  const char *s2, size_t n);
static int _sys_strncasecmp(const char* s1, const char* s2, size_t n) { return sysPrxForUser_1CA525A2(s1, s2, n); }

// sysPrxForUser_1ED454CE  // sys_spu_elf_get_information

int sysPrxForUser_24A1EA07(sys_ppu_thread_t *thread_id,            // sys_ppu_thread_create()
                                  void (*entry)(uint64_t),
                                  uint64_t arg,
                                  int prio,
                                  size_t stacksize,
                                  uint64_t flags,
                                  const char *threadname);
static int sys_ppu_thread_create(sys_ppu_thread_t* thread_id, void (*entry)(uint64_t), uint64_t arg, int prio, size_t stacksize, uint64_t flags, const char* threadname) { return sysPrxForUser_24A1EA07(thread_id, entry, arg, prio, stacksize, flags, threadname); }

// sysPrxForUser_25062C8E  // ?

uint64_t sysPrxForUser_25596F51(sys_mempool_t mempool);            // sys_mempool_get_count()
#define sys_mempool_get_count sysPrxForUser_25596F51

sys_prx_id_t sysPrxForUser_26090058(const char* path,              // sys_prx_load_module()
                                           sys_prx_flags_t flags,
                                           sys_prx_load_module_option_t *pOpt);
static sys_prx_id_t sys_prx_load_module(const char* path, sys_prx_flags_t flags, sys_prx_load_module_option_t* pOpt) { return sysPrxForUser_26090058(path, flags, pOpt); }

void *sysPrxForUser_27427742(void *str1,                           // _sys_memmove()
                                    const void *str2,
                                    size_t n);
static void* _sys_memmove(void* str1, const void* str2, size_t n) { return sysPrxForUser_27427742(str1, str2, n); }

int sysPrxForUser_2A6D9D51(sys_lwcond_t *lwcond,                   // sys_lwcond_wait()
                                  usecond_t timeout);
#define sys_lwcond_wait sysPrxForUser_2A6D9D51

// sysPrxForUser_2C847572  // _sys_process_atexitspawn

size_t sysPrxForUser_2D36462B(const char *str);                    // _sys_strlen()
static size_t _sys_strlen(const char* str) { return sysPrxForUser_2D36462B(str); }

// sysPrxForUser_2F256B29  // ? sys_rsxaudio_import_shared_memory (2 params)

int sysPrxForUser_2F85C0EF(sys_lwmutex_t *lwmutex,                 // sys_lwmutex_create()
                                  sys_lwmutex_attribute_t *attr);
static int sys_lwmutex_create(sys_lwmutex_t* lwmutex, sys_lwmutex_attribute_t* attr) { return sysPrxForUser_2F85C0EF(lwmutex, attr); }

// sysPrxForUser_3172759D  // sys_game_get_temperature

void *sysPrxForUser_318F17E1(size_t alignment,                     // _sys_memalign()
                                    size_t size);
static void* _sys_memalign(size_t alignment, size_t size) { return sysPrxForUser_318F17E1(alignment, size); }

int sysPrxForUser_350D454E(sys_ppu_thread_t *thread_id);           // sys_ppu_thread_get_id()
static int sys_ppu_thread_get_id(sys_ppu_thread_t* thread_id) { return sysPrxForUser_350D454E(thread_id); }

// sysPrxForUser_35168520  // _sys_heap_malloc
// sysPrxForUser_39E9B068  // sys_rsxaudio_unimport_shared_memory(2 params)

void *sysPrxForUser_3BD53C7B(void *ptr,                            // sys_memchr()
                                    int value,
                                    size_t num);
#define sys_memchr sysPrxForUser_3BD53C7B

// sysPrxForUser_3DD4A957  // sys_ppu_thread_register_atexit
// sysPrxForUser_3EF17F8C  // ?

int sysPrxForUser_409AD939(sys_memory_t mem_id);                   // sys_mmapper_free_memory()
static int sys_mmapper_free_memory(sys_memory_t mem_id) { return sysPrxForUser_409AD939(mem_id); }

// sysPrxForUser_4232B0DB  // ?

int sysPrxForUser_42B23552(void* library);                         // sys_prx_register_library()
static int sys_prx_register_library(void* library) { return sysPrxForUser_42B23552(library); }

// sysPrxForUser_44265C08  // _sys_heap_memalign

int sysPrxForUser_459B4393(const char *str1,                       // sys_strcmp()
                                  const char *str2);
static int _sys_strcmp(const char* str1, const char* str2) { return sysPrxForUser_459B4393(str1, str2); }

// sysPrxForUser_45FE2FCE  // _sys_spu_printf_initialize
// int spu_printf_initialize(int prio, void (func)(const char *));

int sysPrxForUser_4643BA6E(sys_addr_t start_addr,                  // sys_mmapper_unmap_memory()
                                  sys_memory_t *mem_id);
#define sys_mmapper_unmap_memory sysPrxForUser_4643BA6E

int sysPrxForUser_4A071D98(sys_interrupt_thread_handle_t ih);      // sys_interrupt_thread_disestablish()
#define sys_interrupt_thread_disestablish sysPrxForUser_4A071D98

int sysPrxForUser_4B2F301A(int c);                                 // sys_tolower()
static int _sys_tolower(int c) { return sysPrxForUser_4B2F301A(c); }

// sysPrxForUser_4BBF59D0  // sys_net_eurus_post_command(u16 cmd, u8 *cmdbuf, u64 cmdbuf_size)

int sysPrxForUser_4F7172C9(const void *p);                         // sys_process_is_stack()
#define sys_process_is_stack sysPrxForUser_4F7172C9

void sysPrxForUser_5267CB35(int *lock);                            // sys_spinlock_unlock()
#define sys_spinlock_unlock sysPrxForUser_5267CB35

int sysPrxForUser_52AADADF(sys_lwcond_t *lwcond,                   // sys_lwcond_signal_to()
                                  sys_ppu_thread_t ppu_thread_id);
#define sys_lwcond_signal_to sysPrxForUser_52AADADF

// sysPrxForUser_5FDFB2FE  // _sys_spu_printf_detach_group
// int spu_printf_detach_group(sys_spu_thread_group_t group);

int sysPrxForUser_608212FC(sys_mempool_t mempool,                  // sys_mempool_free_block()
                                  void *block);
#define sys_mempool_free_block sysPrxForUser_608212FC

// sysPrxForUser_620E35A7  // sys_game_get_system_sw_version
// sysPrxForUser_637BDAAE  // ?
// sysPrxForUser_67F9FEDB  // sys_game_process_exitspawn2

void *sysPrxForUser_68B9B011(void *str,                            // sys_memset()
                                    int c,
                                    size_t n);
static void* _sys_memset(void* str, int c, size_t n) { return sysPrxForUser_68B9B011(str, c, n); }

void *sysPrxForUser_6BF66EA7(void *dest,                           // sys_memcpy()
                                    const void *src,
                                    size_t num); 
static void* _sys_memcpy(void* dest, const void* src, size_t num) { return sysPrxForUser_6BF66EA7(dest, src, num); }

// sysPrxForUser_6E05231D  // sys_game_watchdog_stop

int sysPrxForUser_70258515(size_t size,                            // sys_mmapper_allocate_memory_from_container()
                                  sys_memory_container_t container,
                                  uint64_t flags,
                                  sys_memory_t *mem_id);
#define sys_mmapper_allocate_memory_from_container sysPrxForUser_70258515

int sysPrxForUser_71A8472A(void* addr,                             // sys_get_random_number()
                                  uint64_t size);
static int sys_get_random_number(void* addr, uint64_t size) { return sysPrxForUser_71A8472A(addr, size); }

int sysPrxForUser_722A0254(int *lock);                             // sys_spinlock_trylock()
#define sys_spinlock_trylock sysPrxForUser_722A0254

// sysPrxForUser_728FD7C3  // ?

sys_prx_id_t sysPrxForUser_74311398(void);                         // sys_prx_get_my_module_id()
static sys_prx_id_t sys_prx_get_my_module_id() { return sysPrxForUser_74311398(); }

// sysPrxForUser_744680A2  // sys_initialize_tls

char *sysPrxForUser_7498887B(char *str,                            // sys_strchr()
                                    int c);

// sysPrxForUser_750DD5CD  // ?

int sysPrxForUser_791B9219(char *str,                              // sys_vsprintf() 
                                  const char *format,
                                  va_list arg);

// sysPrxForUser_7B034C78  // sys_rsxaudio_prepare_process(1 param)
// sysPrxForUser_7DAFF8BB  // ?

int sysPrxForUser_80FB0C19(sys_prx_id_t id,                        // sys_prx_stop_module()
                                  size_t args,
                                  void *argp,
                                  int *modres,
                                  sys_prx_flags_t flags,
                                  sys_prx_stop_module_option_t *pOpt);
static int sys_prx_stop_module(sys_prx_id_t id, size_t args, void* argp, int* modres, sys_prx_flags_t flags, sys_prx_stop_module_option_t* pOpt) { return sysPrxForUser_80FB0C19(id, args, argp, modres, flags, pOpt); }

system_time_t sysPrxForUser_8461E528(void);                        // sys_time_get_system_time()
static system_time_t sys_time_get_system_time() { return sysPrxForUser_8461E528(); }

int sysPrxForUser_84BB6774(sys_prx_id_t id,                        // sys_prx_get_module_info()
                                  sys_prx_flags_t flags,
                                  sys_prx_module_info_t *pInfo);
static int sys_prx_get_module_info(sys_prx_id_t id, sys_prx_flags_t flags, sys_prx_module_info_t* pInfo) { return sysPrxForUser_84BB6774(id, flags, pInfo); }

// sysPrxForUser_87C87495  // sys_rsxaudio_finalize(1 param)

int sysPrxForUser_893305FA(sys_raw_spu_t id,                       // sys_raw_spu_load()
                                  const char *path,
                                  uint32_t *entry);

// sysPrxForUser_8985B5B6  // _sys_heap_stats
// sysPrxForUser_8A2F159B  // console_getc
// sysPrxForUser_8A561D92  // _sys_heap_free
// sysPrxForUser_8BB03AB8  // sys_game_board_storage_write

void sysPrxForUser_8C2BB498(int *lock);                // sys_spinlock_initialize()

// sysPrxForUser_8CFEF376  // ?
// sysPrxForUser_92A7EB40  // ?
// sysPrxForUser_96328741  // _sys_process_at_Exitspawn

char *sysPrxForUser_996F7CF8(char *dest,                           // sys_strncat()
                                    const char *src,
                                    size_t n);

char *sysPrxForUser_99C88692(char *dest,                           // sys_strcpy()
                                    const char *src);

// sysPrxForUser_9C9605EE  // sys_rsxaudio_start_process(1 param)
// sysPrxForUser_9D2EC4FF  // ?

void sysPrxForUser_9D3C0F81(sys_mempool_t mempool);                // sys_mempool_destroy()

// sysPrxForUser_9E0623B5  // sys_game_watchdog_start

int sysPrxForUser_9F04F7AF(const char *fmt, ...);                  // sys_printf()

int sysPrxForUser_9F18429D(sys_prx_id_t id,                        // sys_prx_start_module()
                                  size_t args,
                                  void *argp,
                                  int *modres,
                                  sys_prx_flags_t flags,
                                  sys_prx_start_module_option_t *pOpt);
static int sys_prx_start_module(sys_prx_id_t id, size_t args, void* argp, int* modres, sys_prx_flags_t flags, sys_prx_start_module_option_t* pOpt) { return sysPrxForUser_9F18429D(id, args, argp, modres, flags, pOpt); }

// sysPrxForUser_9F950780  // sys_game_get_rtc_status
// sysPrxForUser_9FB6228E  // ?

void *sysPrxForUser_A146A143(sys_mempool_t mempool);               // sys_mempool_allocate_block()

int sysPrxForUser_A1F9EAFE(char *str,                              // sys_sprintf()
                                  const char *fmt, ...);

void sysPrxForUser_A285139D(int *lock);                            // sys_spinlock_lock()

// sysPrxForUser_A2C7BA64  // sys_prx_exitspawn_with_level

sys_prx_id_t sysPrxForUser_A330AD84(int fd,                        // sys_prx_load_module_on_memcontainer_by_fd()
                                           off64_t offset,
                                           sys_memory_container_t mem_container,
                                           sys_prx_flags_t flags,
                                           sys_prx_load_module_option_t *pOpt);
static sys_prx_id_t sys_prx_load_module_on_memcontainer_by_fd(int fd, off64_t offset, sys_memory_container_t mem_container, sys_prx_flags_t flags, sys_prx_load_module_option_t* pOpt) { return sysPrxForUser_A330AD84(fd, offset, mem_container, flags, pOpt); }

void sysPrxForUser_A3E3BE68(int *once_ctrl,                        // sys_ppu_thread_once()
                                   void (*init)(void));

int sysPrxForUser_A5D06BF0(sys_prx_flags_t flags,                  // sys_prx_get_module_list()
                                  sys_prx_get_module_list_t *pInfo);
static int sys_prx_get_module_list(sys_prx_flags_t flags, sys_prx_get_module_list_t* pInfo) { return sysPrxForUser_A5D06BF0(flags, pInfo); }

// sysPrxForUser_A9879A33  // sys_rsxaudio_create_connection(1 param)

sys_prx_id_t sysPrxForUser_AA6D9BFF(const char* path,              // sys_prx_load_module_on_memcontainer()
                                           sys_memory_container_t mem_container,
                                           sys_prx_flags_t flags,
                                           sys_prx_load_module_option_t *pOpt);
static sys_prx_id_t sys_prx_load_module_on_memcontainer(const char* path, sys_memory_container_t mem_container, sys_prx_flags_t flags, sys_prx_load_module_option_t* pOpt) { return sysPrxForUser_AA6D9BFF(path, mem_container, flags, pOpt); }

// sysPrxForUser_AC6FC404  // sys_ppu_thread_unregister_atexit
// sysPrxForUser_ACAD8FB6  // sys_game_watchdog_clear

int sysPrxForUser_AEB78725(sys_lwmutex_t *lwmutex);                // sys_lwmutex_trylock()
#define sys_lwmutex_trylock sysPrxForUser_AEB78725

// sysPrxForUser_AEDE4B03  // _sys_heap_delete_heap

void sysPrxForUser_AFF080A4(uint64_t val);                         // sys_ppu_thread_exit()
static void sys_ppu_thread_exit(uint64_t val) { sysPrxForUser_AFF080A4(val); }

// sysPrxForUser_B1BD7A61  // sys_rsxaudio_close_connection(1 param)

int sysPrxForUser_B257540B(uint64_t size,                          // sys_mmapper_allocate_memory()
                                  uint64_t flags,
                                  sys_memory_t *mem_id);
static int sys_mmapper_allocate_memory(uint64_t size, uint64_t flags, sys_memory_t* mem_id) { return sysPrxForUser_B257540B(size, flags, mem_id); }

// sysPrxForUser_B27C8AE7  // sys_prx_load_module_list
// sysPrxForUser_B2FCF2C8  // _sys_heap_create_heap

// sysPrxForUser_B3BBCF2A  // _sys_spu_printf_detach_thread
// int spu_printf_detach_thread(sys_spu_thread_t thread);

// sysPrxForUser_B5D5F64E  // ?
// sysPrxForUser_B6369393  // _sys_heap_get_total_free_size

int sysPrxForUser_B995662E(sys_raw_spu_t id,                       // sys_raw_spu_image_load()
                                  sys_spu_image_t *img);
#define sys_raw_spu_image_load sysPrxForUser_B995662E

// sysPrxForUser_B9BF1078  // _sys_heap_alloc_heap_memory
// sysPrxForUser_BAB62B99  // ret 0x80010003

void *sysPrxForUser_BDB18F83(size_t size);                         // sys_malloc()
static void* _sys_malloc(size_t size) { return sysPrxForUser_BDB18F83(size); }

// sysPrxForUser_BF8EE5BB  // ret 0x80010003

int sysPrxForUser_C3476D0C(sys_lwmutex_t *lwmutex);                // sys_lwmutex_destroy()
static int sys_lwmutex_destroy(sys_lwmutex_t* lwmutex) { return sysPrxForUser_C3476D0C(lwmutex); }

void sysPrxForUser_C4FD6121(void *base,                            // sys_qsort()
                                   size_t num,
                                   size_t size,
                                   int (*compar)(const void*, const void*));
#define sys_qsort sysPrxForUser_C4FD6121

// sysPrxForUser_C839BB4C  // sys_rsxaudio_initialize(out:u8[4])

int sysPrxForUser_CA9A60BF(sys_mempool_t *mempool,                 // sys_mempool_create()
                                  void *chunk, 
                                  const uint64_t chunk_size,
                                  const uint64_t block_size,
                                  const uint64_t ralignment);
#define sys_mempool_create sysPrxForUser_CA9A60BF

int sysPrxForUser_D0EA47A7(void* library);                         // sys_prx_unregister_library()
#define sys_prx_unregister_library sysPrxForUser_D0EA47A7

// sysPrxForUser_D19688BC  // ?
// sysPrxForUser_D1AD4570  // _sys_heap_get_mallinfo

char *sysPrxForUser_D3039D4D(char *dest,                           // sys_strncpy()  
                                    const char *src,
                                    size_t num);

// sysPrxForUser_D66C2D52  // sys_memory_ (5 Params)
// sysPrxForUser_D8A6F882  // sys_memory_ (2 Params)

int sysPrxForUser_DA0EB71A(sys_lwcond_t *lwcond,                   // sys_lwcond_create()
                                  sys_lwmutex_t *lwmutex,
                                  sys_lwcond_attribute_t *attr);
#define sys_lwcond_create sysPrxForUser_DA0EB71A

// sysPrxForUser_DB6B3250  // sys_spu_elf_get_segments

int sysPrxForUser_DC578057(sys_addr_t start_addr,                  // sys_mmapper_map_memory()
                                  sys_memory_t mem_id,
                                  uint64_t flags);
static int sys_mmapper_map_memory(sys_addr_t start_addr, sys_memory_t mem_id, uint64_t flags) { return sysPrxForUser_DC578057(start_addr, mem_id, flags); }

// sysPrxForUser_DD0C1E09  // _sys_spu_printf_attach_group
// int spu_printf_attach_group(sys_spu_thread_group_t group);

// sysPrxForUser_DD3B27AC  // _sys_spu_printf_finalize
// int spu_printf_finalize();

// sysPrxForUser_DE0C682C  // sys_memory_ 
// sysPrxForUser_DE2F9C85  // ?

sys_prx_id_t sysPrxForUser_E0998DBF(const char* name,              // sys_prx_get_module_id_by_name()
                                           sys_prx_flags_t flags,
                                           sys_prx_get_module_id_by_name_option_t *pOpt);
static sys_prx_id_t sys_prx_get_module_id_by_name(const char* name, sys_prx_flags_t flags, sys_prx_get_module_id_by_name_option_t* pOpt) { return sysPrxForUser_E0998DBF(name, flags, pOpt); }

int sysPrxForUser_E0DA8EFD(sys_spu_image_t *img);                  // sys_spu_image_close()
#define sys_spu_image_close sysPrxForUser_E0DA8EFD

// sysPrxForUser_E66BAC36  // console_putc

void sysPrxForUser_E6F2C1E7(int status);                           // sys_process_exit()
static void sys_process_exit(int status) { return sysPrxForUser_E6F2C1E7(status); }

int32_t sysPrxForUser_E75C40F2(void *x);  // ?

// sysPrxForUser_E76964F5  // sys_game_board_storage_read
// sysPrxForUser_E7EF3A80  // sys_prx_load_module_list_on_memcontainer
// sysPrxForUser_E95FFA0A  // ret 0x80010003

int sysPrxForUser_E9A1BD84(sys_lwcond_t *lwcond);                  // sys_lwcond_signal_all()
#define sys_lwcond_signal_all sysPrxForUser_E9A1BD84

int sysPrxForUser_EBE5F72F(sys_spu_image_t *img,                   // sys_spu_image_import()
                                  const void *src,
                                  uint32_t type);
#define sys_spu_image_import sysPrxForUser_EBE5F72F

// sysPrxForUser_EDEA5F4A  // ?

int sysPrxForUser_EEF75113(int c);                                 // sys_toupper()

sys_prx_id_t sysPrxForUser_EF68C17C(int fd,                        // sys_prx_load_module_by_fd()
                                           off64_t offset,
                                           sys_prx_flags_t flags,
                                           sys_prx_load_module_option_t *pOpt);
static sys_prx_id_t sys_prx_load_module_by_fd(int fd, off64_t offset, sys_prx_flags_t flags, sys_prx_load_module_option_t* pOpt) { return sysPrxForUser_EF68C17C(fd, offset, flags, pOpt); }

int sysPrxForUser_EF87A695(sys_lwcond_t *lwcond);                  // sys_lwcond_signal()
#define sys_lwcond_signal sysPrxForUser_EF87A695

int sysPrxForUser_F0AECE0D(sys_prx_id_t id,                        // sys_prx_unload_module()
                                  sys_prx_flags_t flags,
                                  sys_prx_unload_module_option_t *pOpt);
static int sys_prx_unload_module(sys_prx_id_t id, sys_prx_flags_t flags, sys_prx_unload_module_option_t* pOpt) { return sysPrxForUser_F0AECE0D(id, flags, pOpt); }

// sysPrxForUser_F57E1D6F  // console_write

void sysPrxForUser_F7F7FB20(void *ptr);                            // sys_free()
static void _sys_free(void* ptr) { sysPrxForUser_F7F7FB20(ptr); }

// sysPrxForUser_F82CF400  // ?
// sysPrxForUser_F923DADA  // ?

int sysPrxForUser_FA7F693D(const char *format,                     // sys_vprintf()
                                  va_list arg);

int sysPrxForUser_FB5DB080(const void *ptr1,                       // sys_memcmp()
                                  const void *ptr2,
                                  size_t num);

// sysPrxForUser_FC52A7A9  // sys_game_process_exitspawn

//void sysPrxForUser_FECC05B6(uint64_t);  // SYS_TIMEBASE_GET
//#define SYS_TIMEBASE_GET sysPrxForUser_FECC05B6

// sysPrxForUser_FF34C76C  // sys_rsxaudio_ (1 param)


CDECL_END
_VSH_END

#endif // __SYS_PRX_FOR_USER_H__ 
