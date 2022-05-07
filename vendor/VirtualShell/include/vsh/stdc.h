#ifndef __STDC_H__
#define __STDC_H__
#include "vshtypes.h"
//#include "math.h"
#include <stdlib.h> // for ldiv_t
#include <stdio.h> // for FILE
#include <wchar.h> // for mbstate_t
#include <time.h> // for clock_t
#include <dirent.h> // for DIR
#include <sys/stat.h> // for  struct stat

//#undef _STD_USING
//#define  _MEMCHR
//#define _NO_CPP_INLINES
//#define _STD_USING_STRING
//#define  _STD_USING_STDLIB

_VSH_BEGIN
CDECL_BEGIN

extern uint64_t stdc_1ACBEFAC;  // ? dword_747E48
extern uint64_t stdc_26A34F81;  // ? dword_6F7B38
extern uint64_t stdc_57DBCF27;  // _Inf
extern uint64_t stdc_6524499E;  // _FInf
extern uint64_t stdc_7BC88211;  // ? off_707E80
extern uint64_t stdc_985FC057;  // ? dword_6F7B80
extern uint64_t stdc_AAAACE57;  // ? dword_6D5368
extern uint64_t stdc_B5D2F53B;  // ? off_707E84
extern uint64_t stdc_D59C193C;  // _Nan
extern uint64_t stdc_210B2F6E;  // _FNan
extern uint64_t stdc_D97B0687;  // _Ctype
extern uint64_t stdc_67D1406B;  // __ctype_ptr
extern FILE stdc_32E56B1A;  // _Stdin
extern FILE stdc_FB2BD688;  // _Stdout
extern FILE stdc_FEFBE065;  // _Stderr


int stdc_24C9E021(int n);                                                      // abs()
static int abs(int n) { return stdc_24C9E021(n); }

double stdc_58EB9E57(double x);                                                // fabs()
static double fabs(double x) { return stdc_58EB9E57(x); }

int stdc_EE303936(double);                                                     // _Dsign()

double stdc_0F428F0F(double x);                                                // rint()

int stdc_3AD203FA(double x);                                                   // lrint()

long int stdc_9558ED08(float x);                                               // lrintf()

double stdc_21E6D304(double x);                                                // ceil()

float stdc_BAF11866(float x);                                                  // ceilf()

double stdc_475D855B(double x);                                                // trunc()

double stdc_519EBB77(double x);                                                // floor()
static double floor(double x) { return stdc_519EBB77(x); }

float stdc_23B985F7(float x);                                                  // floorf()
static float floorf(float x) { return stdc_23B985F7(x); }

double stdc_F3EC0258(double x);                                                // round()

float stdc_C984BF53(float x);                                                   // roundf()

long int stdc_772F1E4D(double x);                                              // lround()

long int stdc_FBB4047A(float x);                                               // lroundf()

float stdc_7C2EAEB5(float x, float y);                                         // fminf()

float stdc_895CDB49(float x, float y);                                         // fmaxf()

double stdc_A713F8CF(double x, double* intpart);                               // modf()

double stdc_E769E5CF(double numer, double denom);                              // fmod()

float stdc_9A81E583(float numer, float denom);                                 // fmodf()

/*
typedef struct {
	long int quot;
	long int rem;
} ldiv_t;*/

std::ldiv_t stdc_AD62A342(long int numer, long int denom);                          // ldiv()
static std::ldiv_t ldiv(long int numer, long int denom) { return stdc_AD62A342(numer, denom); }

int stdc_15BDCC00(void);                                                       // rand()
static int rand() { return stdc_15BDCC00(); }

void stdc_0D2A593B(unsigned seed);                                             // srand()
static void srand(unsigned seed) { return stdc_0D2A593B(seed); }

double stdc_18668CE3(double x);                                                // exp()
static double exp(double x) { return stdc_18668CE3(x); }

float stdc_FCF08193(float x);                                                  // expf()
#define expf stdc_FCF08193

double stdc_7F381837(double x, int *_exp);                                      // frexp()
#define frexp stdc_7F381837

double stdc_38E69F09(double x, double y);                                      // pow()
#define pow stdc_38E69F09

float stdc_4DDB926B(float x, float y);                                         // powf()
#define powf stdc_4DDB926B

float stdc_00FDE072(float x, float y);                                         // f_powf()
#define f_powf stdc_00FDE072

double stdc_659E011E(double x);                                                // sqrt()
static double sqrt(double x) { return stdc_659E011E(x); }

double stdc_8451EDF0(double x);                                                // sqrtf()
static double sqrtf(double x) { return stdc_8451EDF0(x); }

double stdc_CA463458(double, int);                                              // _Log()
#define _Log stdc_CA463458

float stdc_71293B71(float, int);										         // _FLog()
#define _FLog stdc_71293B71

double stdc_742F12B4(double, unsigned int);                                    // _Sin()
#define _Sin stdc_742F12B4

float stdc_B54CC9A1(float x);                                                  // f_sinf()
static float f_sinf(float x) { return stdc_B54CC9A1(x); }

float stdc_B5E28191(float, unsigned int);                                      // _FSin()
#define _FSin stdc_B5E28191

double stdc_05EFC660(double x);                                                // asin()
#define asin stdc_05EFC660

float stdc_411434BB(float x);                                                  // asinf()
#define asinf stdc_411434BB

float stdc_7AB679DA(float x);                                                  // f_cosf()
static float f_cosf(float x) { return stdc_7AB679DA(x); }

double stdc_1313A420(double x);                                                // acos()
#define acos stdc_1313A420

float stdc_DECE76A6(float x);                                                  // acosf()
#define acosf stdc_DECE76A6

float stdc_705D9E24(float);                                                    // f_acosf()
#define f_acosf stdc_705D9E24

double stdc_D50277AD(double x);                                                // tan()
#define tan stdc_D50277AD

float stdc_9379E36E(float x);                                                  // tanf()
#define tanf stdc_9379E36E

double stdc_7F579E03(double x);                                                // atan()
#define atan stdc_7F579E03

float stdc_3C057FBD(float x);                                                  // atanf()
#define atanf stdc_3C057FBD

double stdc_31DB8C89(double y, double x);                                      // atan2()
#define atan2 stdc_31DB8C89

float stdc_FB932A56(float y, float x);                                         // atan2f()
static float atan2f(float y, float x) { return stdc_FB932A56(x, y); }

float stdc_ABDCCC7A(float, float);                                             // f_atan2f()
#define f_atan2f stdc_ABDCCC7A

float stdc_B7696143(float x, float y);                                                // nextafterf()
#define nextafterf stdc_B7696143

int* stdc_44115DD0();														// _Geterrno()
//static int errno() { return (*stdc_44115DD0()); }

void stdc_8B439438(FILE *stream);                                              // clearerr()
#define clearerr stdc_8B439438

void stdc_692B497F(const char *str);                                           // perror()
#define perror stdc_692B497F

int stdc_33D6AE54(FILE* stream);                                               // ferror()
static int ferror(FILE* stream) { return stdc_33D6AE54(stream); }

char *stdc_44796E5C(int errnum);                                               // strerror()
static char* strerror(int errnum) { return stdc_44796E5C(errnum); }

size_t stdc_2F45D39C(const char *str);                                         // strlen()
static size_t strlen(const char* str) { return stdc_2F45D39C(str); }

size_t stdc_65E8D4D0(const wchar_t *ws);                                       // wcslen()
static size_t wcslen(const wchar_t* ws) { return stdc_65E8D4D0(ws); }

void *stdc_CBAC7AD7(const char *ptr, int value, size_t num);                         // memchr()
static void* memchr(const char* ptr, int value, size_t num) { return stdc_CBAC7AD7(ptr, value, num); }

wchar_t *stdc_4E72F810(const wchar_t *s, wchar_t c, size_t n);                 // wmemchr()
static wchar_t* wmemchr(const wchar_t* s, wchar_t c, size_t n) { return stdc_4E72F810(s, c, n); }

int stdc_C3E14CBE(const void *ptr1, const void *ptr2, size_t num);             // memcmp()
static int memcmp(const void* ptr1, const void* ptr2, size_t num) { return stdc_C3E14CBE(ptr1, ptr2, num); }

int stdc_AC758D20(const wchar_t *ptr1, const wchar_t *ptr2, size_t num);       // wmemcmp()
static int wmemcmp(const wchar_t* ptr1, const wchar_t* ptr2, size_t num) { return stdc_AC758D20(ptr1, ptr2, num); }

void *stdc_5909E3C4(void *str, int c, size_t n);                               // memset()
static void* memset(void* str, int c, size_t n) { return stdc_5909E3C4(str, c, n); }

wchar_t *stdc_F06EED36(wchar_t *ptr, wchar_t wc, size_t num);                  // wmemset()
static wchar_t* wmemset(wchar_t* ptr, wchar_t wc, size_t num) { return stdc_F06EED36(ptr, wc, num); }

void *stdc_5B162B7F(void *str1, const void *str2, size_t n);                   // memmove()
static void* memmove(void* str1, const void* str2, size_t n) { return stdc_5B162B7F(str1, str2, n); }

wchar_t *stdc_99B38CE7(wchar_t *dest, const wchar_t *src, size_t num);         // wmemmove()
static wchar_t* wmemmove(wchar_t* dest, const wchar_t* src, size_t num) { return stdc_99B38CE7(dest, src, num); }

void *stdc_831D70A5(void *dest, const void *src, size_t num);                  // memcpy()
static void* memcpy(void* dest, const void* src, size_t num) { return stdc_831D70A5(dest, src, num); }

wchar_t *stdc_A8B07F1B(wchar_t *dest, const wchar_t *src, size_t num);         // wmemcpy()
static wchar_t* wmemcpy(wchar_t* dest, const wchar_t* src, size_t num) { return stdc_A8B07F1B(dest, src, num); }

wchar_t *stdc_84378DDC(wchar_t *dest, const wchar_t *src, size_t num);         // wcsncpy()
static wchar_t* wcsncpy(wchar_t* dest, const wchar_t* src, size_t num) { return stdc_84378DDC(dest, src, num); }

int stdc_3D85D6F8(const char *str1, const char *str2);                         // strcmp()
static int strcmp(const char* str1, const char* str2) { return stdc_3D85D6F8(str1, str2); }

int stdc_F0776A44(const wchar_t *wcs1, const wchar_t *wcs2);                   // wcscmp()
static int wcscmp(const wchar_t* wcs1, const wchar_t* wcs2) { return stdc_F0776A44(wcs1, wcs2); }

int stdc_E1E83C65(const char *str1, const char *str2, size_t num);             // strncmp()
static int strncmp(const char* str1, const char* str2, size_t num) { return stdc_E1E83C65(str1, str2, num); }

int stdc_6D5115B0(const wchar_t *ws1, const wchar_t *ws2, size_t n);           // wcsncmp()
static int wcsncmp(const wchar_t* ws1, const wchar_t* ws2, size_t n) { return stdc_6D5115B0(ws1, ws2, n); }

int stdc_B6D92AC3(const char *s1, const char *s2);                             // strcasecmp()
static int strcasecmp(const char* s1, const char* s2) { return stdc_B6D92AC3(s1, s2); }

int stdc_B6257E3D(const char *s1, const char *s2, size_t n);                   // strncasecmp()
static int strncasecmp(const char* s1, const char* s2, size_t n) { return stdc_B6257E3D(s1, s2, n); }

char *stdc_04A183FC(char *dest, const char *src);                              // strcpy()
static char* strcpy(char* dest, const char* src) { return stdc_04A183FC(dest, src); }

wchar_t *stdc_F41355F9(wchar_t *dest, const wchar_t *src);                     // wcscpy()
static wchar_t* wcscpy(wchar_t* dest, const wchar_t* src) { return stdc_F41355F9(dest, src); }

char *stdc_8AB0ABC6(char *dest, const char *src, size_t num);                  // strncpy()
static char* strncpy(char* dest, const char* src, size_t num) { return stdc_8AB0ABC6(dest, src, num); }

char *stdc_FC0428A6(const char *s);                                            // strdup()
static char* strdup(const char* s) { return stdc_FC0428A6(s); }

char *stdc_AA9635D7(char *dest, const char *src);                              // strcat()
static char* strcat(char* dest, const char* src) { return stdc_AA9635D7(dest, src); }

wchar_t *stdc_7FDCF73E(wchar_t *dest, const wchar_t *src);                     // wcscat()
static wchar_t* wcscat(wchar_t* dest, const wchar_t* src) { return stdc_7FDCF73E(dest, src); }

char *stdc_589B5314(char *dest, const char *src, size_t n);                    // strncat()
static char* strncat(char* dest, const char* src, size_t n) { return stdc_589B5314(dest, src, n); }

wchar_t *stdc_9439E4CD(wchar_t* dest, const wchar_t* source, size_t num);      // wcsncat()
static wchar_t* wcsncat(wchar_t* dest, const wchar_t* source, size_t num) { return stdc_9439E4CD(dest, source, num); }

char *stdc_DEBEE2AF(const char *str, int c);                                         // strchr()
static char* strchr(const char* str, int c) { return stdc_DEBEE2AF(str, c); }

wchar_t *stdc_82A3CC30(wchar_t* ws, wchar_t wc);                               // wcschr()
static wchar_t* wcschr(wchar_t* ws, wchar_t wc) { return stdc_82A3CC30(ws, wc); }

char *stdc_73EAE03D(const char *s, int c);                                     // strrchr()
static char* strrchr(const char* s, int c) { return stdc_73EAE03D(s, c); }

wchar_t *stdc_B7AB5127(const wchar_t *ws, wchar_t wc);                         // wcsrchr()
static wchar_t* wcsrchr(const wchar_t* ws, wchar_t wc) { return stdc_B7AB5127(ws, wc); }

char *stdc_C5C09834(const char *str1, const char *str2);                             // strstr()
static char* strstr(const char* str1, const char* str2) { return stdc_C5C09834(str1, str2); }

wchar_t *stdc_A797790F(wchar_t* wcs1, const wchar_t* wcs2);                    // wcsstr()
static wchar_t* wcsstr(wchar_t* wcs1, const wchar_t* wcs2) { return stdc_A797790F(wcs1, wcs2); }

size_t stdc_F3EF3678(const wchar_t *wcs1, const wchar_t *wcs2);                // wcscspn()
static size_t wcscspn(const wchar_t* wcs1, const wchar_t* wcs2) { return stdc_F3EF3678(wcs1, wcs2); }

char *stdc_E40BA755(char *str, const char *delimiters);                        // strtok()
static char* strtok(char* str, const char* delimiters) { return stdc_E40BA755(str, delimiters); }

char *stdc_B738027A(char *str, const char *delim, char **saveptr);             // strtok_r()
static char* strtok_r(char* str, const char* delim, char** saveptr) { return stdc_B738027A(str, delim, saveptr); }

long int stdc_D14ECE90(const char *str, char **endptr, int base);              // strtol()
static long int strtol(const char* str, char** endptr, int base) { return stdc_D14ECE90(str, endptr, base); }

double stdc_D1D69CB8(const char *a, char **b, long x);                         // _Stod()
static double _Stod(const char* a, char** b, long x) { return stdc_D1D69CB8(a, b, x); }
static double strtod(const char* str, char** endptr) { return _Stod(str, endptr, 0); }
static double atof(const char* str) { return _Stod(str, 0, 0); }

uint64_t stdc_36C067C1(const char *a, char **b, int x);                        // _Stoll
#define _Stoll stdc_36C067C1
#define strtoll(str, endptr, base)	_Stoll(str, endptr, base)

unsigned long stdc_867275D7(const char *a, char **b, int x);                   // _Stoul()
#define _Stoul stdc_867275D7
#define strtoul(str, endptr, base)	_Stoul(str, endptr, base)
#define atoi(str)	(int)_Stoul(str, 0, 10)
#define atol(str)	(long)_Stoul(str, 0, 10)

uint64_t stdc_D417EEB5(const char *a, char **b, int x);                        // _Stoull()
#define _Stoull stdc_D417EEB5

long stdc_116CDA13(const wchar_t *restrict_nptr, wchar_t **restrict_endptr, int base);  // wcstol
#define wcstol stdc_116CDA13

long long int stdc_A30D4797(const wchar_t* str, wchar_t** endptr, int base);   // wcstoll()
#define wcstoll stdc_A30D4797

size_t stdc_B2702E15(char *pmb, wchar_t wc, std::mbstate_t *ps);                    // wcrtomb()
static size_t wcrtomb(char* pmb, wchar_t wc, std::mbstate_t* ps) { return stdc_B2702E15(pmb, wc, ps); }

size_t stdc_12A55FB7(wchar_t *pwc, const char *s, size_t n, std::mbstate_t *ps);  // mbrtowc
static size_t mbrtowc(wchar_t* pwc, const char* s, size_t n, std::mbstate_t* ps) { return stdc_12A55FB7(pwc, s, n, ps); }


/*static int mbtowc(wchar_t* pwc, const char* s, size_t n)
{
   static mbstate_t mbs;
   size_t rval;

   if (s == NULL) {
      memset(&mbs, 0, sizeof(mbs));
      return (0);
   }
   rval = mbrtowc(pwc, s, n, &mbs);
   if (rval == (size_t)-1 || rval == (size_t)-2)
      return (-1);
   return ((int)rval);
}

static int wctomb(char* s, wchar_t wchar)
{
   static mbstate_t mbs;
   size_t rval;

   if (s == NULL) {
      memset(&mbs, 0, sizeof(mbs));
      return (0);
   }
   if ((rval = wcrtomb(s, wchar, &mbs)) == (size_t)-1)
      return (-1);
   return ((int)rval);
}*/


size_t stdc_FCAC2E8E(wchar_t *dest, const char *src, size_t max);              // mbstowcs()
static size_t mbstowcs(wchar_t* dest, const char* src, size_t max) { return stdc_FCAC2E8E(dest, src, max); }

size_t stdc_B680E240(char *dest, const wchar_t *src, size_t max);              // wcstombs()
static size_t wcstombs(char* dest, const wchar_t* src, size_t max) { return stdc_B680E240(dest, src, max); }

int stdc_C01D9F97(const char *fmt, ...);                                       // printf()

int stdc_E48348E9(const char * fmt, va_list arg);                            // vprintf()
static int vprintf(const char* fmt, va_list arg) { return stdc_E48348E9(fmt, arg); }

static int printf(const char* fmt, ...)
{
   int r;
   va_list args;
   va_start(args, fmt);
   r = vprintf(fmt, args);
   va_end(args);
   return r;
}

int stdc_273B9711(char *str, const char *fmt, ...);                            // sprintf()

int stdc_3A840AE3(char *str, size_t size, const char *fmt, ...);               // snprintf()

int stdc_7AE82E0F(char *str, const char *format, va_list arg);                 // vsprintf()
static int vsprintf(char* str, const char* format, va_list arg) { return stdc_7AE82E0F(str, format, arg); }

int stdc_FAEC8C60(FILE *stream, const char *fmt, ...);                         // fprintf()

int stdc_FB2081FD(FILE *stream, const char *fmt, va_list arg);                 // vfprintf()
static int vfprintf(FILE* stream, const char* fmt, va_list arg) { return stdc_FB2081FD(stream, fmt, arg); }

static int fprintf(FILE* stream, const char* fmt, ...)
{
    int r;
    va_list args;
    va_start(args, fmt);
    r = vsh::vfprintf(stream, fmt, args);
    va_end(args);
    return r;
}

int stdc_99A72146(char *s, size_t n, const char *fmt, va_list arg);            // vsnprintf()
static int vsnprintf(char* s, size_t n, const char* fmt, va_list arg) { return stdc_99A72146(s, n, fmt, arg); }

static int snprintf(char* str, size_t size, const char* format, ...)
{
   int r;
   va_list args;
   va_start(args, format);
   r = vsnprintf(str, size, format, args);
   va_end(args);
   return r;
}


int stdc_E9137453(FILE *stream, const wchar_t *fmt, ...);                      // fwprintf()

int stdc_62BF1D6C(wchar_t *wcs, size_t maxlen, const wchar_t *format, ...);    // swprintf()

int stdc_4B6A4010(wchar_t * ws, size_t len, const wchar_t * fmt, va_list arg); // vswprintf()
static int vswprintf(wchar_t* ws, size_t len, const wchar_t* fmt, va_list arg) { return stdc_4B6A4010(ws, len, fmt, arg); }

static int swprintf(wchar_t* s, size_t n, const wchar_t* fmt, ...)
{
   int ret;
   va_list ap;

   va_start(ap, fmt);
   ret = vswprintf(s, n, fmt, ap);
   va_end(ap);

   return (ret);
}

int stdc_B1F4779D(sys_spu_thread_t id, uint32_t arg_addr);                     // spu_thread_printf()
#define spu_thread_printf stdc_B1F4779D

int stdc_F0E022C6(FILE *stream);                                               // getc()
static int getc(FILE* stream) { return stdc_F0E022C6(stream); }

int stdc_A5BC0E19(void);                                                       // getchar()
static int getchar(void) { return stdc_A5BC0E19(); }

char *stdc_90010029(char *str);                                                // gets()
static char* gets(char* str) { return stdc_90010029(str); }

char *stdc_AF44A615(char *str, int num, FILE * stream);                        // fgets()
static char* fgets(char* str, int num, FILE* stream) { return stdc_AF44A615(str, num, stream); }

int stdc_AC893127(FILE *stream);                                               // fgetc()
static int fgetc(FILE* stream) { return stdc_AC893127(stream); }

wchar_t *stdc_55D4866E(wchar_t *ws, int n, FILE *stream);                      // fgetws()
static wchar_t* fgetws(wchar_t* ws, int n, FILE* stream) { return stdc_55D4866E(ws, n, stream); }

// stdc_82A4561A  // _put_fd()

int stdc_2677568C(int c);                                                      // putchar()
#define putchar stdc_2677568C

int stdc_79819DBF(int c, FILE *stream);                                        // fputc()
#define fputc stdc_79819DBF

int stdc_E3CC73F3(const char *str);                                            // puts()
static int puts(const char* str) { return stdc_E3CC73F3(str); }

int stdc_4D348427(const char *str, FILE *stream);                              // fputs()
static int fputs(const char* str, FILE* stream) { return stdc_4D348427(str, stream); }

int stdc_FE88E97E(FILE *stream, const char *fmt, ...);                         // fscanf()
#define fscanf stdc_FE88E97E

int stdc_E9B560A5(const char *s, const char *fmt, ...);                        // sscanf()
#define sscanf stdc_E9B560A5

int stdc_3A210C93(const wchar_t* ws, const wchar_t* fmt, ...);                 // swscanf
#define swscanf stdc_3A210C93

int stdc_3BD9CE0A(int fd);                                                     // fsync()
#define fsync stdc_3BD9CE0A

int stdc_F356418C(const char *, int, ...);                                     // open()
#define stdc_open stdc_F356418C

FILE *stdc_69C27C12(const char *filename, const char *mode);                   // fopen()
static FILE* fopen(const char* filename, const char* mode) { return stdc_69C27C12(filename, mode); }

FILE *stdc_E3812672(int fd, const char *mode);                                 // fdopen()
static FILE* fdopen(int fd, const char* mode) { return stdc_E3812672(fd, mode); }

int stdc_4FFBA189(FILE *stream);                                               // feof()
static int feof(FILE* stream) { return stdc_4FFBA189(stream); }

int stdc_26F023D5(FILE *stream);                                               // ftell()
static int ftell(FILE* stream) { return stdc_26F023D5(stream); }

int stdc_D360DCB4(FILE *stream);                                               // fileno()
#define fileno stdc_D360DCB4

void stdc_54F57626(FILE *stream);                                              // rewind()
static void rewind(FILE* stream) { stdc_54F57626(stream); }

int stdc_69FF1B9B(FILE *stream, long int offset, int whence);                  // fseek()
static int fseek(FILE* stream, long int offset, int whence) { return stdc_69FF1B9B(stream, offset, whence); }

off_t stdc_AEC7C970(int fd, off_t offset, int whence);                         // lseek()
#define lseek stdc_AEC7C970

size_t stdc_FA00D211(int fd, void *buf, size_t nbytes);                        // read()
static size_t read(int fd, void* buf, size_t nbytes) { return stdc_FA00D211(fd, buf, nbytes); }

size_t stdc_D40723D6(void *ptr, size_t size, size_t count, FILE *stream);      // fread()
static size_t fread(void* ptr, size_t size, size_t count, FILE* stream) { return stdc_D40723D6(ptr, size, count, stream); }

size_t stdc_526A496A(int fildes, const void *buf, size_t nbytes);              // write()
static size_t write(int fildes, const void* buf, size_t nbytes) { return stdc_526A496A(fildes, buf, nbytes); }

size_t stdc_F88F26C4(const void *ptr, size_t size, size_t count, FILE *stream);  // fwrite()
static size_t fwrite(const void* ptr, size_t size, size_t count, FILE* stream) { return stdc_F88F26C4(ptr, size, count, stream); }

int stdc_814D8CB0(FILE * stream);                                              // fflush()
static int fflush(FILE* stream) { return stdc_814D8CB0(stream); }

int stdc_B120F6CA(int fd);                                                     // close()
static int close(int fd) { return stdc_B120F6CA(fd); }

int stdc_E1BD3587(FILE *stream);                                               // fclose()
static int fclose(FILE* stream) { return stdc_E1BD3587(stream); }

int stdc_153B364A(const char *path, mode_t mode);                              // mkdir()
static int mkdir(const char* path, mode_t mode) { return stdc_153B364A(path, mode); }

int stdc_7E7017B1(const char *path);                                           // rmdir()
static int rmdir(const char* path) { return stdc_7E7017B1(path); }

int stdc_75D4485C(const char *old_filename, const char *new_filename);         // rename()
static int rename(const char* old_filename, const char* new_filename) { return stdc_75D4485C(old_filename, new_filename); }

int stdc_EF110B6B(const char *path);                                           // unlink()
static int unlink(const char* path) { return stdc_EF110B6B(path); }

int stdc_717B2502(const char *path, struct stat *buf);       // stat()
static int stat(const char* path, struct stat* buf) { return stdc_717B2502(path, buf); }

// stdc_AB77019F  // fstat()

void stdc_8A6830E7(void);                                                      // abort()
static void abort() { stdc_8A6830E7(); }

void stdc_C291E698(int status);                                                // exit()
static void exit(int status) { stdc_C291E698(status); }

// stdc_1A00F889  // _ZNSt9exceptionD2Ev

clock_t stdc_24F6CBDD(void);                                                   // clock()
static clock_t clock() { return stdc_24F6CBDD(); }

time_t stdc_89F6F026(time_t *timer);                                           // time()
static time_t time(time_t* timer) { return stdc_89F6F026(timer); }

char *stdc_BC7B4B8E(const time_t *timer);                                      // ctime()
static char* ctime(const time_t* timer) { return stdc_BC7B4B8E(timer); }

struct tm *stdc_EB26298C(const time_t *timer);                                 // gmtime()
static struct tm* gmtime(const time_t* timer) { return stdc_EB26298C(timer); }

time_t stdc_19CCBB81(struct tm *timeptr);                                      // mktime()
static time_t mktime(struct tm* timeptr) { return stdc_19CCBB81(timeptr); }

struct tm *stdc_266311A0(const time_t *timer);                                 // localtime()
static struct tm* localtime(const time_t* timer) { return stdc_266311A0(timer); }

double stdc_4217B4CF(time_t time1, time_t time2);                              // difftime()
static double difftime(time_t time1, time_t time2) { return stdc_4217B4CF(time1, time2); }

size_t stdc_CB9C535B(char *ptr, size_t maxsize, const char *fmt, const struct tm *timeptr);  // strftime()
static size_t strftime(char* ptr, size_t maxsize, const char* fmt, const struct tm* timeptr) { return stdc_CB9C535B(ptr, maxsize, fmt, timeptr); }

void stdc_A9F68EFF(void *base, size_t num, size_t size, int(*compar)(const void*, const void*));  // qsort()
#define qsort stdc_A9F68EFF

void *stdc_5E7888F0(const void *key, const void *base, size_t nitems, size_t size, int(*compar)(const void *, const void *));  // bsearch()
#define bsearch stdc_5E7888F0

DIR *stdc_3DBC3BEE(const char *name);                                          // opendir()
static DIR* opendir(const char* name) { return stdc_3DBC3BEE(name); }

struct dirent *stdc_2B81FB7F(DIR *dirp);                                       // readdir()
static struct dirent* readdir(DIR* dirp) { return stdc_2B81FB7F(dirp); }

int stdc_A3440924(DIR *dirp);                                                  // closedir()
static int closedir(DIR* dirp) { return stdc_A3440924(dirp); }


// stdc_2D8BE7E8  // _ZNKSt9exception6_RaiseEv

// stdc_3B5489A9  // ?

// stdc_3CA81C76  // _Iswctype

// stdc_3EEEDB0E  // _Dclass()

// stdc_418BDFE1  // _get_fd()

double stdc_45034943(const char* tagp);                                        // nan()
static double nan(const char* tagp) { return stdc_45034943(tagp); }

// stdc_683CA70A  // _ZNKSt12_String_base5_XlenEv

int stdc_703EC767(FILE *restrict_stream, char *restrict_buf, int type, size_t size);  // setvbuf()
#define setvbuf stdc_703EC767

// stdc_7670FF88  // ?

double stdc_8ECAE294(double x, double y);                                      // nextafter()
#define nextafter stdc_8ECAE294

short stdc_9232BAEA(float *);                                                  // _FDtes()
#define _FDtest stdc_9232BAEA

// stdc_9CB73EE0  // _ZSt6_ThrowRKSt9exception

void stdc_AF89FDBD(const char *, const char *);                                // _Assert()

void stdc_DDC71A75(const char *, const char *);                                // _SCE_Assert()

#undef assert	/* remove existing definition */
#ifdef NDEBUG
#define assert(test)	((void)0)
#else /* NDEBUG */
#define _STRIZE(x)	_VAL(x)
#define _VAL(x)	#x
#if 199901L <= __STDC_VERSION__
#ifdef __cplusplus
#define _FUNNAME	0

#else /* __cplusplus */
#define _FUNNAME	__func__
#endif /* __cplusplus */

#else /* 199901L <= __STDC_VERSION__ */
#define _FUNNAME	0
#endif /* 199901L <= __STDC_VERSION__ */

#ifdef __CELL_ASSERT__
#define vsh_assert(test)	((test) ? (void)0 \
    : vsh::stdc_DDC71A75(__FILE__ ":" _STRIZE(__LINE__) " " #test, _FUNNAME))
#else /* __CELL_ASSERT__ */
#define vsh_assert(test)	((test) ? (void)0 \
    : vsh::stdc_AF89FDBD(__FILE__ ":" _STRIZE(__LINE__) " " #test, _FUNNAME))
#endif /* __CELL_ASSERT__ */
#endif /* NDEBUG */


short stdc_B94B9D13(double *);                                                 // _Dtest()

// stdc_C7931798  // _ZNKSt12_String_base5_XranEv

CDECL_END
_VSH_END

#endif // __STDC_H__
