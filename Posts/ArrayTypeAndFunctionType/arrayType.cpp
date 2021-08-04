
#include <stdio.h>
#include <iostream>
#include <boost/type_index.hpp>

using boost::typeindex::type_id_with_cvr;

void func(int arr[3])
{
	std::cout<<"func(arr) is "<<type_id_with_cvr<decltype(arr)>().pretty_name()<<" or "<<
		typeid(arr).name()<<std::endl;
}

int main()
{
	int arr[3] = {1,2,3};
	int (*arrPtr)[3];
	arrPtr = & arr;
	std::cout<<"arr is "<<type_id_with_cvr<decltype(arr)>().pretty_name()<<" or "<<
		typeid(arr).name()<<std::endl;
	std::cout<<"*arr is "<<type_id_with_cvr<decltype(*arr)>().pretty_name()<<" or "<<
		typeid(*arr).name()<<std::endl;
	// ***arr does not exist
	//std::cout<<"**arr is "<<type_id_with_cvr<decltype(**arr)>().pretty_name()<<" or "<<
		//typeid(**arr).name()<<std::endl;
	std::cout<<"&arr is "<<type_id_with_cvr<decltype(&arr)>().pretty_name()<<" or "<<
		typeid(&arr).name()<<std::endl;
	std::cout<<"*&arr is "<<type_id_with_cvr<decltype(*&arr)>().pretty_name()<<" or "<<
		typeid(*&arr).name()<<std::endl;
	std::cout<<"**&arr is "<<type_id_with_cvr<decltype(**&arr)>().pretty_name()<<" or "<<
		typeid(**&arr).name()<<std::endl;
	// ***&arr does not exist 
	//std::cout<<"***&arr is "<<type_id_with_cvr<decltype(***&arr)>().pretty_name()<<" or "<<
		//typeid(***&arr).name()<<std::endl;

	printf("value/addr(arr):  %d/%p, value/addr(arr+1): %d/%p\n", *arr, arr, *(arr+1), arr+1);
	printf("value/addr(&arr):  %d/%p, value/addr(&arr+1): %d/%p\n", *&arr, &arr, *(&arr+1), &arr+1);
	printf("value/addr(arrPtr):  %d/%p, value/addr(arrPtr+1): %d/%p\n", *arrPtr, &arrPtr, *(arrPtr+1), arrPtr+1);

   func(arr);
   //funcArray(arrPtr);
	int *intPtr = arr;
	//intPtr = arrPtr;

	return 0;
}
