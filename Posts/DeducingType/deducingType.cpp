

#include <iostream>
#include <typeinfo>
#include <string>
#include <boost/core/demangle.hpp>
#include <boost/type_index.hpp>

using boost::typeindex::type_id_with_cvr;

void func() { std::cout<<"call func\n"; }

template <typename T>
void valueFunc(T param, std::string expr)
{
   std::cout << __func__ << ": " << expr
      << " ---> "<< type_id_with_cvr<decltype(param)>().pretty_name()
      << " ---> "<< type_id_with_cvr<T>().pretty_name()
      << std::endl;
}
void valueFuncTest()
{
   std::cout<<std::endl<<"void valueFunc(T param) :"<<std::endl;
   // literal
   valueFunc(1, "1");
   // plain variable 
   int x = 1;
   valueFunc(x, "x");
   // lvalue reference;
   int &rx = x;
   valueFunc(rx, "int &rx = x");
   // rvalue reference;
   valueFunc(std::move(rx), "std::move(rx)");
   // pointer
   int *px = &x;
   valueFunc(px, "int *px = &x");
   valueFunc(&x, "f(&x)");
   // array
   int a[1];
   valueFunc(a, "int a[1]");
   // function
   valueFunc(func, "void func()");
}
									
template <typename T>
void refFunc(T & param, std::string expr)
{
   std::cout << __func__ << ": " << expr
      << " ---> "<< type_id_with_cvr<decltype(param)>().pretty_name()
      << " ---> "<< type_id_with_cvr<T>().pretty_name()
      << std::endl;
}
void refFuncTest()
{
   std::cout<<std::endl<<"void refFunc(T& param) :"<<std::endl;
   // literal
   //refFunc(1, "1");
   // plain variable 
   int x = 1;
   refFunc(x, "x");
   // lref reference;
   int &rx = x;
   refFunc(rx, "int &rx = x");
   // rref reference;
   //refFunc(std::move(rx), "std::move(rx)");
   // pointer
   int *px = &x;
   refFunc(px, "int *px = &x");
   // array
   int a[1];
   refFunc(a, "int a[1]");
   // function
   refFunc(func, "void func()");
}

template <typename T>
void refRefFunc(T&& param, std::string expr)
{
   std::cout << __func__ << ": " << expr
      << " ---> "<< type_id_with_cvr<decltype(param)>().pretty_name()
      << " ---> "<< type_id_with_cvr<T>().pretty_name()
      << std::endl;
}
void refRefFuncTest()
{
   std::cout<<std::endl<<"void refRefFunc(T&& param) :"<<std::endl;
   // literal
   refRefFunc(1, "1");
   // plain variable 
   int x = 1;
   refRefFunc(x, "x");
   // lref reference;
   int &rx = x;
   refRefFunc(rx, "int &rx = x");
   // rref reference;
   refRefFunc(std::move(rx), "std::move(rx)");
   // pointer
   int *px = &x;
   refRefFunc(px, "int *px = &x");
   // array
   int a[1];
   refRefFunc(a, "int a[1]");
   // function
   refRefFunc(func, "void func()");
}

template <typename T>
//void ptrFunc(T * const param, std::string expr)
void ptrFunc(T * param, std::string expr)
{
   std::cout << __func__ << ": " << expr
      << " ---> "<< type_id_with_cvr<decltype(param)>().pretty_name()
      << " ---> "<< type_id_with_cvr<T>().pretty_name()
      << std::endl;
}
void ptrFuncTest()
{
   std::cout<<std::endl<<"void ptrFunc(T* param) :"<<std::endl;
   // literal
   ptrFunc((int*)1, "(int*)1");
   //ptrFunc(1, "1");
   // plain variable 
   int x = 1;
   //ptrFunc(x, "x");
   // lref reference;
   //int &rx = x;
   //ptrFunc(rx, "int &rx = x");
   // rref reference;
   //ptrFunc(std::move(rx), "std::move(rx)");
   // pointer
   int *px = &x;
   ptrFunc(px, "int *px = &x");
   // array
   int a[1];
   ptrFunc(a, "int a[1]");
   // function
   ptrFunc(func, "void func()");
}

void (f)();
void (f)();
int main()
{
	valueFuncTest();
	refFuncTest();
	refRefFuncTest();
	ptrFuncTest();

   return 0;
}
