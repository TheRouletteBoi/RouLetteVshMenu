#pragma once
#include <sys/synchronization.h>
#include <cell/sync2/cond_types.h>
#include <cell/sync2/cond.h>
#include <sys/ppu_thread.h>
#include <functional>
#include <memory>
#include <string>
#include <vsh/stdc.h>

namespace std
{
   typedef decltype(nullptr) nullptr_t;


   // STRUCT TEMPLATE integral_constant
   template <class _Ty, _Ty _Val>
   struct integral_constant {
      static constexpr _Ty value = _Val;

      using value_type = _Ty;
      using type = integral_constant;

      constexpr operator value_type() const noexcept {
         return value;
      }

      constexpr value_type operator()() const noexcept {
         return value;
      }
   };

   // ALIAS TEMPLATE bool_constant
   template <bool _Val>
   using bool_constant = integral_constant<bool, _Val>;

   using true_type = bool_constant<true>;
   using false_type = bool_constant<false>;

   // STRUCT TEMPLATE enable_if
   template <bool _Test, class _Ty = void>
   struct enable_if {}; // no member "type" when !_Test

   template <class _Ty>
   struct enable_if<true, _Ty> { // type is _Ty for _Test
      using type = _Ty;
   };

   template <bool _Test, class _Ty = void>
   using enable_if_t = typename enable_if<_Test, _Ty>::type;

   // STRUCT TEMPLATE conditional
   template <bool _Test, class _Ty1, class _Ty2>
   struct conditional { // Choose _Ty1 if _Test is true, and _Ty2 otherwise
      using type = _Ty1;
   };

   template <class _Ty1, class _Ty2>
   struct conditional<false, _Ty1, _Ty2> {
      using type = _Ty2;
   };

   template <bool _Test, class _Ty1, class _Ty2>
   using conditional_t = typename conditional<_Test, _Ty1, _Ty2>::type;

   template<class _Ty1, class _Ty2>
   struct is_same : false_type
   {
      // determine whether _Ty1 and _Ty2 are the same type
   };

   template<class _Ty1>
   struct is_same<_Ty1, _Ty1> : true_type
   {
      // determine whether _Ty1 and _Ty2 are the same type
   };




   // STRUCT TEMPLATE remove_reference
   template <class _Ty>
   struct remove_reference {
      using type = _Ty;
      using _Const_thru_ref_type = const _Ty;
   };

   template <class _Ty>
   struct remove_reference<_Ty&> {
      using type = _Ty;
      using _Const_thru_ref_type = const _Ty&;
   };

   template <class _Ty>
   struct remove_reference<_Ty&&> {
      using type = _Ty;
      using _Const_thru_ref_type = const _Ty&&;
   };

   template <class _Ty>
   using remove_reference_t = typename remove_reference<_Ty>::type;


   /*template<class T> struct remove_reference { typedef T type; };
   template<class T> struct remove_reference<T&> { typedef T type; };
   template<class T> struct remove_reference<T&&> { typedef T type; };

   template<typename _Tp>
   constexpr typename remove_reference<_Tp>::type&&
      move(_Tp&& __t) noexcept
   {
      return static_cast<typename remove_reference<_Tp>::type&&>(__t);
   }*/


   template <class _Ty>
   struct remove_cv { // remove top-level const and volatile qualifiers
      using type = _Ty;

      template <template <class> class _Fn>
      using _Apply = _Fn<_Ty>; // apply cv-qualifiers from the class template argument to _Fn<_Ty>
   };

   template <class _Ty>
   using remove_cv_t = typename remove_cv<_Ty>::type;

   template <class _Ty>
   using remove_reference_t = typename remove_reference<_Ty>::type;

   /*
   template <class T>
   inline T&& forward(typename std::remove_reference<T>::type& t) noexcept
   {
      return static_cast<T&&>(t);
   }

   template <class T>
   inline T&& forward(typename std::remove_reference<T>::type&& t) noexcept
   {
      return static_cast<T&&>(t);
   }
   */

   // FUNCTION TEMPLATE forward
   template <class _Ty>
   constexpr _Ty&& forward(
      remove_reference_t<_Ty>& _Arg) noexcept { // forward an lvalue as either an lvalue or an rvalue
      return static_cast<_Ty&&>(_Arg);
   }

   template <class _Ty>
   constexpr _Ty&& forward(remove_reference_t<_Ty>&& _Arg) noexcept { // forward an rvalue as an rvalue
      return static_cast<_Ty&&>(_Arg);
   }

   // FUNCTION TEMPLATE move
   template <class _Ty>
   constexpr remove_reference_t<_Ty>&& move(_Ty&& _Arg) noexcept { // forward _Arg as movable
      return static_cast<remove_reference_t<_Ty>&&>(_Arg);
   }












   /// <summary>
   /// Thread.hpp
   /// </summary>
   class mutex
   {
   public:
       mutex()
       {
           sys_mutex_attribute_initialize(attr);
           errCode = sys_mutex_create(&thisMutex, &attr);
       }
       sys_mutex_t& get_native() { return thisMutex; }
       int errCode;
   private:
       sys_mutex_t thisMutex;
       sys_mutex_attribute_t attr;
   };

   template<class T>
   class lock_guard
   {
   public:
       lock_guard(T& in) : mutex(in)
       {
           sys_mutex_lock(mutex.get_native(), 0);
       }
       ~lock_guard()
       {
           sys_mutex_unlock(mutex.get_native());
       }
   private:
       T& mutex;
   };


}

#define JMJ_THREAD_PRIORITY 1000 // thread priority 0=highest, 3071=lowest
#define JMJ_THREAD_STACK_SIZE 2048 // stack size for newly created threads

namespace jmj
{
    template<typename _Threadable>
    class thread
    {
    public:
        thread() : _joinable(false) {}
        thread(void(_Threadable::* func)(), _Threadable* t, const std::string& name = "jmjthread") : _joinable(true), obj(t), f(func)
        {
            sys_ppu_thread_create(&thread_id, myFunc, reinterpret_cast<uint64_t>(this),
                JMJ_THREAD_PRIORITY, JMJ_THREAD_STACK_SIZE, SYS_PPU_THREAD_CREATE_JOINABLE, name.c_str());
        }
        bool joinable() { return _joinable; }
        void join() { uint64_t rslt; sys_ppu_thread_join(thread_id, &rslt); }
        _Threadable* obj;
    protected:
        bool _joinable;
        sys_ppu_thread_t thread_id;
        void(_Threadable::* f)();
        static void myFunc(uint64_t in) {
            thread* thisObj = reinterpret_cast<thread*>((uint32_t)in);
            (*thisObj->obj.*thisObj->f)();
            sys_ppu_thread_exit(in);
        }
    };

    template <typename T>
    class counting_semaphore
    {
    public:
        counting_semaphore(const T& max = 1) : max(max), count(0)
        {
            // set up the conditional variable
            sys_cond_attribute_t cvAttr;
            sys_cond_attribute_initialize(cvAttr);
            sys_cond_create(&cv, mutex.get_native(), &cvAttr);
        }
        ~counting_semaphore()
        {
            sys_cond_destroy(cv);
        }
        /***
        * Wait for a condition
        */
        void acquire()
        {
            std::lock_guard<std::mutex> lock(mutex);
            while (count <= 0)
            {
                sys_cond_wait(cv, 0);
            }
            count--;
        }
        /****
        * Signal a condition
        */
        void release()
        {
            if (count >= max)
                return;
            count++;
            sys_cond_signal(cv);
        }
    private:
        std::mutex mutex;
        sys_cond_t cv;
        T count;
        T max;
    };

    class binary_semaphore : public counting_semaphore<int>
    {
    public:
        binary_semaphore() : counting_semaphore<int>(1) {}
    };

} // namespace jmj



template<class T>
std::string to_string(T value)
{
   char buf[25];
   vsh::memset(buf, 0, 25);
   int len = vsh::snprintf(buf, sizeof(buf), "%d", value);
   return std::string(buf);
}

template<class T>
std::wstring to_wstring(T value)
{
   wchar_t buf[25];
   vsh::memset(buf, 0, 25);
   int len = vsh::swprintf(buf, sizeof(buf), L"%d", value);
   return std::wstring(buf);
}

template<>
std::string to_string(uint64_t value);

std::string to_string(float value, int decimalPlaces = 0);

template<>
std::string to_string(double value);

template<>
std::wstring to_wstring(uint64_t value);

std::wstring to_wstring(float value, int decimalPlaces = 0);

template<>
std::wstring to_wstring(double value);

uint32_t mix_time_seed(std::clock_t a, std::time_t b, sys_pid_t c);