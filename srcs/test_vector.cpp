#include "../includes/ft_containers.hpp"
//using namespace ft;

void    basic_test()
{
    std::cout << "_______TESTING CONSTRUCTION OF VECTOR_______" << std::endl;

	ft::vector<T> vector; 
	std::vector<int> v;
	ft::vector<int> tmp0(vector);
	ft::vector <int> tmp1(100, 4), tmp2(25890, 5);
	tmp1 = tmp2; 

	
    ft::vector<int> v1(5, 10);
    std::vector <int> v2(5, 10);
	v1.push_back
    std::cout << "initialised ft::vector v1 and std::vector v2" << std::endl << std::endl;
    std::cout << "v1 size " << v1.size() << std::endl;
    std::cout << "v2 size " << v2.size() << std::endl << std::endl; 
    std::cout << "v1 max_size " << v1.max_size() << std::endl;
    std::cout << "v2 maz_size " << v2.max_size() << std::endl << std::endl;

    std::cout << "TESTING VECTOR ITERATORS" << std::endl;
   
    for (ft::vector<int>::iterator it1 = v1.begin(); it1 != v1.end(); ++it1)
        std::cout << "vec1 *it 1 = " << *it1 << std::endl;
    for ( std::vector<int>::iterator it2 = v2.begin(); it2 != v2.end(); ++it2)
        std::cout << "vec2 *it 2 = " << *it2 << std::endl;



	ft::vector<T> vector;
	std::vector<int> v;
	ft::vector<int> tmp0(vector);
	ft::vector<int> tmp(10000000, 4), tmp2(10000000, 5);
	tmp = tmp2;
	ft::vector<int> tmp3(tmp);
	ft::vector<int> tmp4(tmp.begin(), tmp.end());
	v.push_back(tmp4.size());
	v.push_back(tmp4.capacity());
	v.push_back(tmp[2]);
	v.push_back(tmp3[2]);
	v.push_back(tmp4[2]);
	try
	{
		ft::vector<int> tmp5(-1, -1);
	}
	catch (std::exception &e)
	{
		v.push_back(1);
	}
	return v;

}