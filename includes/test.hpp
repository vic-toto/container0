# ifndef TEST_HPP
#define TEST_HPP


#include <vector>
#include <stack>
#include <map>
#include <set>
#include <iostream>
#include <iomanip>
#include <sys/time.h>
#include <string>
#include "utils.hpp"
#include "vector.hpp"
#include "stack.hpp"

extern time_t	start1, start2, end1, end2;

time_t 		timer();
//print result functions
void	print_green_res(std::string s);
void	print_red_res(std::string s);
//launch unit tests
int		run_unit_test(std::string test_name, std::vector<int>(func1)(), std::vector<int>(func2)());
int		run_bool_unit_test(std::string test_name, bool(func1)());

template <class T>
typename ft::enable_if< std::is_unsigned<T>::value >::type foo(T) {
	start1 = -20;
}

template <class T>
typename ft::enable_if< std::is_signed<T>::value >::type foo(T) {
	start2 = -20;
}

template <class InputIterator1, class InputIterator2>
bool comp_iter(InputIterator1 it1, InputIterator2 it2) { return it1 == it2; }

class B
{
public:
	char *l;
	int i;
	B() : l(nullptr), i(1){};
	B(const int &ex);
	virtual ~B();
};

class A : public B
{
public:
	A() : B(){};
	A(const B *ex);
	~A();
};

class StackBoolTest
{
public:
	std::stack<int> s1, s2, s3, s4;
	std::stack<std::string> s5, s6, s7, s8, s9;
	ft::stack<int> st1, st2, st3, st4;
	ft::stack<std::string> st5, st6, st7, st8, st9;

	StackBoolTest();
};

#endif