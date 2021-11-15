// 3141card
#ifndef __SYS_NET_H__
#define __SYS_NET_H__


// sys_net_012F752F // ?

extern "C" int32_t sys_net_051EE3EE(struct pollfd *fds, int32_t nfds, int32_t ms); // socketpoll()
#define socketpoll sys_net_051EE3EE

extern "C" int32_t sys_net_05BD4438(sys_net_udpp2p_test_param_t *param); // sys_net_get_udpp2p_test_param()
#define sys_net_get_udpp2p_test_param sys_net_05BD4438

// sys_net_0B017E2B // ?

extern "C" int32_t sys_net_10B81ED6(sys_net_udpp2p_test_param_t *param); // sys_net_set_udpp2p_test_param()
#define sys_net_set_udpp2p_test_param sys_net_10B81ED6

extern "C" int32_t sys_net_139A9E9B(sys_net_initialize_parameter_t *param); // sys_net_initialize_network_ex()
#define sys_net_initialize_network_ex sys_net_139A9E9B

extern "C" int32_t sys_net_13EFE7F5(int32_t s, struct sockaddr *addr, socklen_t *paddrlen); // getsockname()
#define getsockname sys_net_13EFE7F5

// sys_net_16F1CE55 // ?
// sys_net_1C8FC14B // ?

extern "C" int32_t sys_net_1D14D6E4(struct in_addr *primary, struct in_addr *secondary); // sys_net_get_lib_name_server()
#define sys_net_get_lib_name_server sys_net_1D14D6E4

extern "C" ssize_t sys_net_1F953B9F(int32_t s, void *buf, size_t len, int32_t flags, struct sockaddr *addr, socklen_t *paddrlen); // recvfrom()
#define recvfrom sys_net_1F953B9F

extern "C" int32_t sys_net_27FB339D(int32_t if_id, int32_t code, void *ptr, int32_t len); // sys_net_if_ctl()
#define sys_net_if_ctl sys_net_27FB339D

extern "C" int32_t sys_net_28E208BB(int32_t socket, int32_t backlog); // listen()
#define listen sys_net_28E208BB

// sys_net_2AAE42A8 // ?
// sys_net_3575B141 // ?

extern "C" int32_t sys_net_368823C0(sys_net_test_param_t *param); // sys_net_get_netemu_test_param()
#define sys_net_get_netemu_test_param sys_net_368823C0

extern "C" int32_t sys_net_3B27C780(int32_t s, sys_net_sockinfo_t *p, int32_t n); // sys_net_get_sockinfo()
#define sys_net_get_sockinfo sys_net_3B27C780

// sys_net_3C7189C0 // ?
// sys_net_3C95AA78 // ?
// sys_net_3CA02562 // ?
// sys_net_3CFA784B // ?

extern "C" int32_t sys_net_3F09E20A(int32_t nfds, struct fd_set *readfds, struct fd_set *writefds, struct fd_set *exceptfds, struct timeval *timeout); // socketselect()
#define socketselect sys_net_3F09E20A



extern "C" int32_t sys_net_4323CDA7(uint64_t *arg1, int32_t arg2, int32_t arg3, uint64_t *arg4, int32_t arg5, int32_t arg6, int32_t arg7); // ? (&var_AC, 6, 0, &var_B0, 0, 0, 0)



extern "C" int32_t sys_net_44328AA2(int32_t id, int32_t *pflags); // sys_net_close_dump()
#define sys_net_close_dump sys_net_44328AA2

// sys_net_44F05E73 // ?
// sys_net_46497DA6 // ?
// sys_net_4AB0B9B9 // sys_net_set_test_param

extern "C" in_addr_t sys_net_506AD863(const char *cp); // inet_network()
#define inet_network sys_net_506AD863

extern "C" int32_t sys_net_5420E419(void); // sys_net_show_nameserver()
#define sys_net_show_nameserver sys_net_5420E419

extern "C" in_addr_t sys_net_566893CE(struct in_addr in); // inet_lnaof()
#define inet_lnaof sys_net_566893CE

// sys_net_5853BE79 // ?

extern "C" int32_t sys_net_5A045BD1(int32_t s, int32_t level, int32_t optname, void *optval, socklen_t *optlen); // getsockopt()
#define getsockopt sys_net_5A045BD1

// sys_net_5D0CA0E8 // ?
// sys_net_6005CDE1 // _sys_net_errno_loc

extern "C" int32_t sys_net_64F66D35(int32_t s, const struct sockaddr *addr, socklen_t addrlen); // connect()
#define connect sys_net_64F66D35

// sys_net_6B6CAF26 // ?

extern "C" int32_t sys_net_6DB6E8CD(int32_t s); // socketclose()
#define socketclose sys_net_6DB6E8CD

extern "C" struct hostent *sys_net_71F4C717(const char *name); // gethostbyname()
#define gethostbyname sys_net_71F4C717

// sys_net_73D364D5 // ?
// sys_net_7608719D // ?

extern "C" int32_t sys_net_7687D48C(int32_t retrans, int32_t retry, int32_t flags); // sys_net_set_resolver_configurations()
#define sys_net_set_resolver_configurations sys_net_7687D48C

// sys_net_78EAE3FB // ?

extern "C" int32_t sys_net_79B61646(void); // sys_net_show_route()
#define sys_net_show_route sys_net_79B61646

// sys_net_7E6FB08D // ?
// sys_net_827CA646 // ?
// sys_net_853BE146 // ?

extern "C" char *sys_net_858A930B(struct in_addr in); // inet_ntoa()
#define inet_ntoa sys_net_858A930B

// sys_net_878472F0 // ? (arg1, arg2, 1) 

extern "C" int32_t sys_net_88F03575(int32_t s, int32_t level, int32_t optname, const void *optval, socklen_t optlen); // setsockopt()
#define setsockopt sys_net_88F03575

extern "C" int32_t sys_net_89C9917C(int32_t id, void *buf, int32_t len, int32_t *pflags); // sys_net_read_dump()
#define sys_net_read_dump sys_net_89C9917C

extern "C" int32_t sys_net_8AF3825E(int32_t af, const char *src, void *dst); // inet_pton()
#define inet_pton sys_net_8AF3825E

extern "C" int32_t sys_net_8CCF05ED(sys_net_thread_id_t tid, int32_t flags); // sys_net_abort_resolver()
#define sys_net_abort_resolver sys_net_8CCF05ED

extern "C" int32_t sys_net_8D1B77FB(int32_t s, int32_t flags); // sys_net_abort_socket()
#define sys_net_abort_socket sys_net_8D1B77FB

// sys_net_8F3E1687 // ?

extern "C" int32_t sys_net_92852B93(int32_t socket, uint32_t packet_id, const char *interface); // ? e.g. (s, 0xC020698C, "eth0");

// sys_net_943231D1 // ?
// sys_net_959C4441 // ? blr

extern "C" ssize_t sys_net_9647570B(int32_t s, const void *buf, size_t len, int32_t flags, const struct sockaddr *addr, socklen_t addrlen); // sendto()
#define sendto sys_net_9647570B

extern "C" int32_t sys_net_9A318259(struct in_addr *primary, struct in_addr *secondary); // sys_net_set_lib_name_server()
#define sys_net_set_lib_name_server sys_net_9A318259

// sys_net_9A62982A // ?

extern "C" int32_t sys_net_9C056962(int32_t family, int32_t type, int32_t protocol); // socket()
#define socket sys_net_9C056962

// sys_net_A2B22757 // ?

extern "C" int32_t sys_net_A50777C6(int32_t s, int32_t how); // shutdown()
#define shutdown sys_net_A50777C6

// sys_net_A5A86557 // sys_net_get_test_param

extern "C" int32_t sys_net_A765D029(int32_t s, sys_net_sockinfo_ex_t *p, int32_t n, int32_t flags); // sys_net_get_sockinfo_ex()
#define sys_net_get_sockinfo_ex sys_net_A765D029

extern "C" int32_t sys_net_A9A079E0(const char *cp, struct in_addr *addr); // inet_aton()
#define inet_aton sys_net_A9A079E0

extern "C" int32_t sys_net_AB447704(int32_t len, int32_t flags); // sys_net_open_dump()
#define sys_net_open_dump sys_net_AB447704

// sys_net_ABCB26A1 // ?

extern "C" ssize_t sys_net_AD09481B(int32_t s, const struct msghdr *msg, int32_t flags); // sendmsg()
#define sendmsg sys_net_AD09481B

// sys_net_AEB2EC57 // ? sys_timer_usleep
// sys_net_AFC21C3E // ?

extern "C" int32_t sys_net_B0A59804(int32_t s, const struct sockaddr *addr, socklen_t addrlen); // bind()
#define bind sys_net_B0A59804

// sys_net_B15E9321 // ?

extern "C" struct in_addr sys_net_B4152C74(in_addr_t net, in_addr_t host); // inet_makeaddr()
#define inet_makeaddr sys_net_B4152C74

extern "C" int32_t sys_net_B48636C4(void); // sys_net_show_ifconfig()
#define sys_net_show_ifconfig sys_net_B48636C4

extern "C" int32_t sys_net_B68D5625(void); // sys_net_finalize_network()
#define sys_net_finalize_network sys_net_B68D5625

// sys_net_C2F38FF1 // ?
// sys_net_C82191E3 // ? (void)
// sys_net_C9157D30 // _sys_net_h_errno_loc

extern "C" int32_t sys_net_C94F6939(int32_t s, struct sockaddr *addr, socklen_t *paddrlen); // accept()
#define accept sys_net_C94F6939

extern "C" const char *sys_net_C98A3146(int32_t af, const void *src, char *dst, socklen_t size); // inet_ntop()
#define inet_ntop sys_net_C98A3146

extern "C" ssize_t sys_net_C9D09C34(int32_t s, struct msghdr *msg, int32_t flags); // recvmsg()
#define recvmsg sys_net_C9D09C34

// sys_net_D1A13957 // ? gethostbyname, (?, const char *name)
// sys_net_D4C6B098 // ? 

extern "C" in_addr_t sys_net_DABBC2C0(const char *cp); // inet_addr()
#define inet_addr sys_net_DABBC2C0

extern "C" ssize_t sys_net_DC751B40(int32_t s, const void *buffer, size_t size, int32_t flags); // send()
#define send sys_net_DC751B40

// sys_net_DEA29EF4 // ?

extern "C" int32_t sys_net_E2434507(sys_net_test_param_t *param); // sys_net_set_netemu_test_param()
#define sys_net_set_netemu_test_param sys_net_E2434507

extern "C" in_addr_t sys_net_E39A62A7(struct in_addr in); // inet_netof()
#define inet_netof sys_net_E39A62A7

// sys_net_E61CB17A // ?
// sys_net_F0645452 // ?
// sys_net_F5F39114 // sys_ppu_thread_join, (sys_ppu_thread_t thread_id, uint64_t *vptr)

extern "C" struct hostent *sys_net_F7AC8941(const char *addr, socklen_t len, int32_t type); // gethostbyaddr()
#define gethostbyaddr sys_net_F7AC8941

// sys_net_F7ACD655 // ?

extern "C" int32_t sys_net_F9EC2DB6(int32_t s, struct sockaddr *addr, socklen_t *paddrlen); // getpeername()
#define getpeername sys_net_F9EC2DB6

// sys_net_FAFD69A4 // ?

// sys_net_FB03C635 // ? (?, const char *addr, socklen_t len, int32_t type)

extern "C" ssize_t sys_net_FBA04F37(int32_t s, void *buf, size_t len, int32_t flags); // recv()
#define recv sys_net_FBA04F37

// sys_net_FD58F18A // ? -> sys_net_878472F0()

extern "C" int32_t sys_net_FDB8F926(sys_net_thread_id_t tid, int32_t flags); // sys_net_free_thread_context()
#define sys_net_free_thread_context sys_net_FDB8F926

#endif // __SYS_NET_H__
