---
layout: post
title:  "C++ Function Template Type Deduction"
date:   2017-01-15 11:06:00 +0800
categories: c++
---

# Overview
We have function template and class template. Note that class template parameters are never deduced. The reason is that the flexibility provided by several constructors for a class would make such deduction impossible in many cases and obscure in many more. So we consider function template type deduction bellow.

    template<typename T>
    void f(ParamType param);

A call can look like this:

    f(expr); // call f with some expression

# Case 1: ParamType is a Reference or Pointer, but not a Universal Reference
Type deduction work like this: ***T is deduced to the one which is missed in ParamType compared with expr's type.***

#### Example 1: T&

    template<typename T>
    void f(T& param);

    int x = 27;
    const int = cx =x;
    cont int& rx =x;

    const char name[] = "J. P. Briggs";
    const char * ptrToName = name;

    void someFunc(int, double);

    f(x);
    f(cx);
    f(rx);
    f(name);
    f(someFunc);

|expr      |expr's type      |ParamType   |T deduced    | ParamType deduced |explanation        |
| ---|
| x        | int             |  T&        | int         |  |missing int       |
| cx       | const int       |  T&        | const int   | |missing const int |
| rx       | const int&      |  T&        | const int   | |missing const int |
| name | const char [13] | T& | const char [13] | const char (&) [13] | |
| someFunc | void (int, double) | T& | void (int, double) | void (&)(int, double) | missing void (int, double)|


#### Example 2: T const &



    template<typename T>
    void f(const T& param);

    int x = 27;
    const int = cx =x;
    cont int& rx =x;

    f(x);
    f(cx);
    f(rx);

|expr      |expr's type      |ParamType   |T deduced    |explanation        |
| -------- |-------------    | ---      --|-----   ---  |                   |
| x        | int             |  const T&        | int         | missing int       |
| cx       | const int       |  const T&        | int   | missing int |
| rx       | const int&      |  const T&        | int   | missing int |



#### Example 3: T*

    template<typename T>
    void f(T& param);

    int x = 27;
    const int *px = &x;

    f(&x);
    f(px);

|expr      |expr's type      |ParamType   |T deduced    |explanation        |
| -------- |-------------    | ---      --|-----   ---  |                   |
| x        | int *            |  T*        | int         | missing int       |
| px       | const int *      |  T*        | const int   | missing const int |


# Case 2: ParamType is a Universal Reference(forwarding reference)

    template<typename T>
    void f(T&& param);

Please note T&& is a universal declaration, it has nothing to do with rvalue
references.
Type deduction work like this:
1. ***If expr is lvalue, append "&" to expr's type, no need for rvalue, we call it expr's extended type***
2. ***T is deduced to the one which is missed in ParamType compared with expr's extended type.***
   Note: & is different from &&

For example:
    template<typename T>
    void f(T&& param)

    int x = 27;
    const int cx = x;
    const int& rx = x;

    f(x);
    f(cx);
    f(rx);
    f(27);



| expr | expr's type | expr's extended type | ParamType | T deduced | ParamType deduced |
|---|
|x | int | int & |T && | int & | int & && = int & |
|cx |const int |const int & |T && |const int & |const int & && = const int &|
|rx | const int & | const int & & = const int &|T && |const int & |const int & && = const int &|


# Case 3: ParamType is Neither a Pointer nor a Reference

    template<typename T>
    void f(T param);

That means that param will be a copy of whatever is passed in - a completely new object. We ignore top level reference, modifiers(const/volatile) of expr's type, just because expr can't be modified doesn't mean that a copy of it can't be.

Example 1:
    int x = 27;
    const int cx = x;
    const int& rx = x;
    const char* const ptr = "Fun with pointers";
    void someFunc(int, double);

    f(x);
    f(cx);
    f(rx);
    f(ptr);
    f(someFunc);

| expr |expr's type | ref&modfies ignored | ParamType | T deduced |
|---|
| x | int | int | T | int |
| cx | const int | int | T | int |
| rx | const int & | int | T | int |
| ptr | const char * const | const char * | T | const char * |
| someFunc | void (*)(int, double) | void (*)(int, double) | T | void (*)(int, double) |






# References
Effective Modern C++, Chapter 1, Item 1

The C++ Programming Language, Forth Edition, Chapter 23



























Modern
