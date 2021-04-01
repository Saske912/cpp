//
// Created by Pamula File on 3/11/21.
//

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>

template<typename T>
int     pair_acept(typename std::map<T, int>::iterator it, typename std::map<T, int>::iterator ite, int val)
{
    for (; it != ite; it++)
    {
        if (it->second == val)
            return it->second;
    }
    throw std::exception();
    return (0);
}
template<typename T, typename U>
int     easyfind(std::map<T, U> arr, int val)
{
    (void )arr;
    (void )val;
    throw std::exception();
}

template<typename T>
int     easyfind(std::map<T, int> arr, int val)
{
    typename std::map<T, int>::iterator it = arr.begin();
    typename std::map<T, int>::iterator ite = arr.end();
    return pair_acept<T>(it, ite, val);
}

template<typename T>
int     easyfind(T & arr, int val)
{
    int a;

    typename T::iterator it = arr.begin();
    typename T::iterator ite = arr.end();
    if ( typeid(*it).name() != typeid(int ).name())
        throw std::exception();
    a = *std::find(it, ite, val);
    if (a != val && a == *arr.end())
        throw std::exception();
    return a;
}

#endif //EASYFIND_HPP
