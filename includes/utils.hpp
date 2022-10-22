#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <memory>
#include <iterator>
namespace ft{


template<class T> struct remove_const { typedef T type; }; //se arriva tipo non const, ritorna il tipo;

template<class T> struct remove_const <const T> { typedef T type; };//se arriva const, ritorna il tipo non const;
}

#endif