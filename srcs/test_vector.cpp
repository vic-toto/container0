#include "../includes/ft_containers.hpp"
//using namespace ft;

#pragma region Vector

//test operator ==
bool	vector_operator_equal_test()
{
	start2 = timer();
	end2 = timer();
	start1 = timer();
	end1 = timer();
	std::vector<int> result, result2;
	std::vector<int> v_int1, v_int2, v_int3;
	std::vector<std::string> v_str1, v_str2;
	ft::vector<int> V_int1, V_int2, V_int3;
	ft::vector<std::string> V_str1, V_str2;
	v_int1.push_back(1);
	v_int3.push_back(1);
	v_str1.push_back("a");
	v_str2.push_back("b");
	result.push_back(v_int1 == v_int2);
	v_int2.push_back(2);
	result.push_back(v_int1 == v_int2);
	result.push_back(v_int1 == v_int3);
	result.push_back(v_str1 == v_str2);
	V_int1.push_back(1);
	V_int3.push_back(1);
	V_str1.push_back("a");
	V_str2.push_back("b");
	result2.push_back(V_int1 == V_int2);
	V_int2.push_back(2);
	result2.push_back(V_int1 == V_int2);
	result2.push_back(V_int1 == V_int3);
	result2.push_back(V_str1 == V_str2);
	return result == result2;
}

//test operator !=
bool	vector_operator_not_equal_test()
{
	start2 = timer();
	end2 = timer();
	start1 = timer();
	end1 = timer();
	std::vector<int> result, result2;
	std::vector<int> v_int1, v_int2, v_int3;
	std::vector<std::string> v_str1, v_str2;
	ft::vector<int> V_int1, V_int2, V_int3;
	ft::vector<std::string> V_str1, V_str2;
	v_int1.push_back(1);
	v_int3.push_back(1);
	v_str1.push_back("a");
	v_str2.push_back("b");
	result.push_back(v_int1 != v_int2);
	v_int2.push_back(2);
	result.push_back(v_int1 != v_int2);
	result.push_back(v_int1 != v_int3);
	result.push_back(v_str1 != v_str2);
	V_int1.push_back(1);
	V_int3.push_back(1);
	V_str1.push_back("a");
	V_str2.push_back("b");
	result2.push_back(V_int1 != V_int2);
	V_int2.push_back(2);
	result2.push_back(V_int1 != V_int2);
	result2.push_back(V_int1 != V_int3);
	result2.push_back(V_str1 != V_str2);
	return result == result2;
}

//test operator <
bool	vector_operator_less_test()
{
	start2 = timer();
	end2 = timer();
	start1 = timer();
	end1 = timer();
	std::vector<int> result, result2;
	std::vector<int> v_int1, v_int2, v_int3;
	std::vector<std::string> v_str1, v_str2;
	ft::vector<int> V_int1, V_int2, V_int3;
	ft::vector<std::string> V_str1, V_str2;
	v_int1.push_back(1);
	v_int3.push_back(1);
	v_str1.push_back("a");
	v_str2.push_back("b");
	result.push_back(v_int1 < v_int2);
	v_int2.push_back(2);
	result.push_back(v_int1 < v_int2);
	result.push_back(v_int1 < v_int3);
	result.push_back(v_str1 < v_str2);
	V_int1.push_back(1);
	V_int3.push_back(1);
	V_str1.push_back("a");
	V_str2.push_back("b");
	result2.push_back(V_int1 < V_int2);
	V_int2.push_back(2);
	result2.push_back(V_int1 < V_int2);
	result2.push_back(V_int1 < V_int3);
	result2.push_back(V_str1 < V_str2);
	return result == result2;
}

//test operator <=
bool	vector_operator_less_equal_test()
{
	start2 = timer();
	end2 = timer();
	start1 = timer();
	end1 = timer();
	std::vector<int> result, result2;
	std::vector<int> v_int1, v_int2, v_int3;
	std::vector<std::string> v_str1, v_str2;
	ft::vector<int> V_int1, V_int2, V_int3;
	ft::vector<std::string> V_str1, V_str2;
	v_int1.push_back(1);
	v_int3.push_back(1);
	v_str1.push_back("a");
	v_str2.push_back("b");
	result.push_back(v_int1 <= v_int2);
	v_int2.push_back(2);
	result.push_back(v_int1 <= v_int2);
	result.push_back(v_int1 <= v_int3);
	result.push_back(v_str1 <= v_str2);
	V_int1.push_back(1);
	V_int3.push_back(1);
	V_str1.push_back("a");
	V_str2.push_back("b");
	result2.push_back(V_int1 <= V_int2);
	V_int2.push_back(2);
	result2.push_back(V_int1 <= V_int2);
	result2.push_back(V_int1 <= V_int3);
	result2.push_back(V_str1 <= V_str2);
	return result == result2;
}

// test operator >
bool	vector_operator_more_test()
{
	start2 = timer();
	end2 = timer();
	start1 = timer();
	end1 = timer();
	std::vector<int> result, result2;
	std::vector<int> v_int1, v_int2, v_int3;
	std::vector<std::string> v_str1, v_str2;
	ft::vector<int> V_int1, V_int2, V_int3;
	ft::vector<std::string> V_str1, V_str2;
	v_int1.push_back(1);
	v_int3.push_back(1);
	v_str1.push_back("a");
	v_str2.push_back("b");
	result.push_back(v_int1 > v_int2);
	v_int2.push_back(2);
	result.push_back(v_int1 > v_int2);
	result.push_back(v_int1 > v_int3);
	result.push_back(v_str1 > v_str2);
	V_int1.push_back(1);
	V_int3.push_back(1);
	V_str1.push_back("a");
	V_str2.push_back("b");
	result2.push_back(V_int1 > V_int2);
	V_int2.push_back(2);
	result2.push_back(V_int1 > V_int2);
	result2.push_back(V_int1 > V_int3);
	result2.push_back(V_str1 > V_str2);
	return result == result2;
}

// test operator >=
bool	vector_operator_more_equal_test()
{
	start2 = timer();
	end2 = timer();
	start1 = timer();
	end1 = timer();
	std::vector<int> result, result2;
	std::vector<int> v_int1, v_int2, v_int3;
	std::vector<std::string> v_str1, v_str2;
	ft::vector<int> V_int1, V_int2, V_int3;
	ft::vector<std::string> V_str1, V_str2;
	v_int1.push_back(1);
	v_int3.push_back(1);
	v_str1.push_back("a");
	v_str2.push_back("b");
	result.push_back(v_int1 >= v_int2);
	v_int2.push_back(2);
	result.push_back(v_int1 >= v_int2);
	result.push_back(v_int1 >= v_int3);
	result.push_back(v_str1 >= v_str2);
	V_int1.push_back(1);
	V_int3.push_back(1);
	V_str1.push_back("a");
	V_str2.push_back("b");
	result2.push_back(V_int1 >= V_int2);
	V_int2.push_back(2);
	result2.push_back(V_int1 >= V_int2);
	result2.push_back(V_int1 >= V_int3);
	result2.push_back(V_str1 >= V_str2);
	return result == result2;
}