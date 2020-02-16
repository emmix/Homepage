---
layout: post
title:  "Conquer the combinations of qualifiers, types and handlers in C++"
date:   2017-01-11 13:17:09 +0800
categories: c++
---

I have been confused about combinations of qualifiers, types and handlers in c++ such as "const int*, int const*, const int&..." since the first sight. Until the [Shijing Lv's Answer] in Stack Overflow, it has inspired me, Let's give a summarization and extension.


Qualifiers(Modifiers): const, volatile, register <br/>
Types: int, char, classes... <br/>
Handlers: *(pinter), &(reference) <br/>

[Qualifiers] Type [Qualifier] [handler] [Qualifiers] variable <br/>

Qualifiers are adjective can modify types and handlers which can be considered noun. Moreover we can put qualifiers in the behind or front of Type, they are the same and exclusive <br/>
    Qualifier Type = Type Qualifier <br/>

Now let's read from right to left: variable is a [Qualifiers] [handler to] [Qualifiers] type.</br>
Please note &(refrence) is constant intrinsic, so we do not need "const" modifer to modify reference.

It is turn to initialize this template, please refer to following code:
<pre><code>
int main() {
   const int ci = 0; // ci is const int
   int const ci_1 = 0; // ci_1 is const int (int const = const int), ci == ci_1

   const int * cip; // cip is pointer to const int
   int const * cip_1; // cip_1 is pointer to const int, (int const = const int), cip == cip_1

   const int * const cpci = &ci;  // cpci is const pointer to const int
   int const * const cpci_1 = &ci; // cpci_1 is const pointer to const int
                                   // (int const = const int), cpci == cpci_1

   const int & rci = ci; // rci is a reference to const int
   int const & rci_1 = ci; // rci_1 is a reference to const int (int const = const int)

   return 0;
}
</code></pre>

Shijing Lv had a good illustration too. For those who don't know about Clockwise/Spiral Rule: Start from the name of the variable, move clockwisely (in this case, move backward) to the next pointer or type. Repeat until expression ends.

<img src="https://i.stack.imgur.com/sT6ng.png" alt="pointer to int">
<img src="https://i.stack.imgur.com/Zt0G2.png" alt="const pointer to int const">
<img src="https://i.stack.imgur.com/kXH8P.png" alt="pointer to int const">
<img src="https://i.stack.imgur.com/UeqZO.png" alt="pointer to const int">
<img src="https://i.stack.imgur.com/f5ftV.png" alt="const pointer to int">



# Involve in array compositing type
<pre>
To declare a reference to an array:
int array[ 10 ];

int (&array_ref)[ 10 ] = array;    // array_ref is now a reference to array
// == int [10] (&arrary_ref) == int [10] & array_ref
// int [10]: array's element is int
// int [10] & array_ref: array_ref is a reference to an array with 10 elements which are int

int & (&array_ref)[ 10 ] = array;
// array_ref is a reference to an array with 10 elements which are references to int

The parentheses are required because otherwise the declaration

int &array_ref[ 10 ];
would attempt to declare an array of 10 references to ints.
</pre>

# Involve in function compositing type
function type is defined by its return type and arguments types, such as "void (int, double)"
<pre>
typedef void (*functiontype)();
void dosomething() { } //
int (*func1)(int); // == int(int) *func1: func1 is a pointer to int(int)
int (&func1)(int); // == int(int) &func2: func2 is a reference to int(int)
int & (&func3)(int); // == int&(int) &func3: func3 is a reference to int&(int)

functiontype func = &dosomething;
func(); // == (*func)();

</pre>



[Shijing Lv's Answer]: http://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const
