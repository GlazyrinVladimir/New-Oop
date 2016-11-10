// task01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "HttpUrl.h"
#include <iostream>

int main()
{

	//CMyArray<int> arr({ 1, 2, 3, 4 });
//	std::cout << arr.begin() << std::cout;

	CMyArray<double> arr;
	std::cout << "1:" << std::endl;
	arr.PushFront(2.28);
	arr.PushFront(2.29);
	arr.PushFront(2.3);
	arr.PushBack(2.27);
	//std::cout << "4 = " << arr.GetSize() << " ";
	std::cout << arr[0] << " ";
	std::cout << arr[1] << " ";
	std::cout << arr[2] << " ";
	std::cout << arr[3] << " ";
	std::cout << std::endl << "2:" << std::endl;
	CMyArray<double> arr2(arr);
	std::cout << arr[0] << " ";
	std::cout << arr[1] << " ";
	std::cout << arr[2] << " ";
	std::cout << arr[3] << " ";
	std::cout << std::endl << "3:" << std::endl;
	CMyArray<int> arr3({ 1, 2, 3, 4 });
	std::cout << arr3[0] << " ";
	std::cout << arr3[1] << " ";
	std::cout << arr3[2] << " ";
	std::cout << arr3[3] << " ";
	CMyArray<int> arr4;
	arr4 = arr3;
	std::cout << arr4[0] << " ";
	std::cout << arr4[1] << " ";
	std::cout << arr4[2] << " ";
	std::cout << arr4[3] << " ";
	/*CArray<std::string> stringArray;
	stringArray.Push("Hello");
	stringArray.Push("World");
	stringArray[0] = ("Goodbye");*/

    return 0;
}

