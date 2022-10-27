#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <memory>

namespace ft
{
	
//template <bool Cond, class T = void>
//	struct enable_if;
//
//	template <typename T>
//	struct enable_if<true, T>
//	{
//		public:
//			typedef T 	type;
//	};
//
//	template <class T>
//	struct is_integral
//	{
//		public:
//			typedef book 	value_type;
//			typedef false_type	type;
//
//			static const bool value = false;
//
//			operator value_type()
//			{
//				return value;
//			}
//	};
	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (*first1 < *first2) return true;
			if (*first2 < *first1) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template<class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2,
								Compare comp)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (comp(*first1, *first2)) return true;
			if (comp(*first2, *first1)) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2>
	bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1!=last1) {
			if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
			return false;
			++first1; ++first2;
		}
		return true;
	}

    template<class T> struct remove_const 
    { typedef T type; }; //se arriva tipo non const, ritorna il tipo;

    template<class T> struct remove_const <const T>
    { typedef T type; };//se arriva const, ritorna il tipo non const;
}



#endif