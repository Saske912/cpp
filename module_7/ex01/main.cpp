//
// Created by Pamula File on 3/9/21.
//
#include "iter.hpp"
#include <iostream>
#include <string>
#define LEN 3

void 	out(std::string& str) {
	std::cout << str << std::endl;
}

void 	func(int& a)
{
	std::cout << a*2 << std::endl;
}

int 	main(void)
{
	std::string *arr = new std::string[LEN];
	
	arr[0] = "hello";
	arr[1] = "world";
	arr[2] = "!";
	iter<std::string >(arr, LEN, out);
	int *k = new int[3];
	k[0] = 5;
	k[1] = 6;
	k[2] = 11;
	iter<int>(k, LEN,func);
	delete [] arr;
	iter<int>(k, LEN, def<int>);
    delete [] k;
}