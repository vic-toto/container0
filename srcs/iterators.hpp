namespace ft
{
	template <class Category, class T, class Distance = ptrdiff_t, 
					class Pointer = T*, class Reference = T&>
	struct	iterator {
		typedef	T		value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef	Reference	reference;
		typedef	Category	iterator_category;
	};

	template <class Iterator>
	struct iterator_traits
	{
		typedef	typename Iterator::iterator_category	iterator_category;
		typedef	typename	Iterator::value_type		value_type;
		typedef	typename	Iterator::difference_type	difference_type;
		typedef	typename	Iterator::pointer			pointerM
		typedef	typename	Iterator::reference			reference;
	};

	template <class T>
	struct iterator_traints<T> {
		typedef	random_access_iterator_tag	iterator_category;
		typedef	T							value_type;
		typedef	ptrdiff_t					difference_type;
		typedef	T							*pointer;
		typedefT							&reference;
	};
	
	template <class Iterator>
	class reverse_iterator
		: public	iterator<typename iterator_traits<Iterator>::iterator_category,
							typename iterator_traits<Iterator>::value_type,
							typename iterator_traits<Iterator>::difference_type,
							typename iterator_traits<Iterator>::pointer,
							typename iterator_traits<Iterator>::reference>
		{
			public:
				typedef Iterator														iterator_type;
				typedef typename iterator_traits<Iterator>::difference_type				difference_type;
							typename iterator_traits<Iterator>::iterator_category		iterator_category;
							typename iterator_traits<Iterator>::reference				reference;
							typename iterator_traits<Iterator>::pointer					pointer:
							typename iterator_traits<Iterator>::value_type				value_type;
		}
}