#include "../includes/ft_containers.hpp"
//using namespace ft;

void    basic_test()
{
    std::cout << "_______BASIC TESTING OF VECTOR_______" << std::endl;

    ft::vector<int> v1(5, 10);
    std::vector <int> v2(5, 10);
    std::cout << "initialised ft::vector v1 and std::vector v2" << std::endl << std::endl;
    std::cout << "v1 size " << v1.size() << std::endl;
    std::cout << "v2 size " << v2.size() << std::endl << std::endl; 
    std::cout << "v1 max_size " << v1.max_size() << std::endl;
    std::cout << "v2 maz_size " << v2.max_size() << std::endl << std::endl;

    std::cout << "TESTING VECTOR ITERATORS" << std::endl;

    ft::vector<int>::iterator it1;
    std::vector<int>::iterator it2;

   // for (it1 = v1.begin(); it1 != v1.end(); ++it1)
   //     std::cout << "vec1 *it 1 = " << *it1 << std::endl;
   //  for (it2 = v2.begin(); it2 != v2.end(); ++it2)
   //     std::cout << "vec2 *it 2 = " << *it2 << std::endl;




}