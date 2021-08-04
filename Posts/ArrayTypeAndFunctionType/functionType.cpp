
#include <stdio.h>
#include <iostream>
#include <boost/core/demangle.hpp>
#include <boost/type_index.hpp>

using boost::typeindex::type_id_with_cvr;

void func() {std::cout<<"hello word\n";}

void my_int_func(int x)
{
	printf( "%d\n", x );
}

void func2(void func())
{
	std::cout<<"func is "<<type_id_with_cvr<decltype(func)>().pretty_name()<<" or "<<
		typeid(func).name()<<std::endl;
}

int main()
{
	// functionName v.s. &functionName
	std::cout<<"\nfunctionName v.s. &functionName"<<std::endl;
	std::cout<<"====================================="<<std::endl;

	std::cout<<"func is "<<type_id_with_cvr<decltype(func)>().pretty_name()<<" or "<<
		typeid(func).name()<<std::endl;
	std::cout<<"*func is "<<type_id_with_cvr<decltype(*func)>().pretty_name()<<" or "<<
		typeid(*func).name()<<std::endl;
	std::cout<<"**func is "<<type_id_with_cvr<decltype(**func)>().pretty_name()<<" or "<<
		typeid(**func).name()<<std::endl;
	std::cout<<"&func is "<<type_id_with_cvr<decltype(&func)>().pretty_name()<<" or "<<
		typeid(&func).name()<<std::endl;
	std::cout<<"*&func is "<<type_id_with_cvr<decltype(*&func)>().pretty_name()<<" or "<<
		typeid(*&func).name()<<std::endl;
	std::cout<<"**&func is "<<type_id_with_cvr<decltype(*&func)>().pretty_name()<<" or "<<
		typeid(**&func).name()<<std::endl;

	printf("The address of func is %p\n", func);
	printf("The address of &func %p\n", &func);
	std::cout<<"Call func(): "; func();
	std::cout<<"Call (*func)(): "; (*func)();
	std::cout<<"Call (**func)(): "; (**func)();
	std::cout<<"Call (&func)(): "; (&func)();
	std::cout<<"Call (*(&func))(): "; (*(&func))();
	std::cout<<"Call (**(&func))(): "; (**(&func))();

	std::cout<<"\nfunctionName is parameter "<<std::endl;
	std::cout<<"====================================="<<std::endl;
	func2(func);

	std::cout<<"\n Miscs "<<std::endl;
	std::cout<<"====================================="<<std::endl;
	void (*foo)(int);
	void (*foo1)(int);
	void foo2(int);

	foo = &my_int_func;
	foo1 = my_int_func;
	//foo2 = &my_int_func;

	/* call my_int_func (note that you do not need to write (*foo)(2) ) */
	std::cout<<"Call foo(2): "; 
	foo(2);
	/* but if you want to, you may */
	std::cout<<"Call (*foo)(2): "; 
	(*foo)( 2 );

	std::cout<<"Call foo1(3): "; 
	foo1(3);
	std::cout<<"Call (*foo1)(3): "; 
	(*foo1)(3);

	return 0;
}
