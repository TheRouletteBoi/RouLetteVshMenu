#pragma once
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

}

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