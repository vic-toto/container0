#ifndef VECTOR_HPP
# define VECTOR_HPP
#include "ft_containers.hpp"
#include <vector>
#include <iostream>
using namespace std;

namespace ft
{
    template <typename T>
    class    general_container{
        protected:
            size_t size;
        
        public:
			general_container(int size);
            int     size();
    };

//Dany the cat.. everybody wants to be a cat!

// ToDo
// 1. Create RandomAccessIterator class OK
// 2. Do RandomAccess vector operators OK
//3. Vector constructor and destructor 
// 4. vector operators
// 5.vector iterators
// 6. capacìty methods
// 7. element access
//8 . modifiers
// 9. allocator
//10. non-member functions overloads

    template<typename _Tp, typename _Alloc = std::allocator<_Tp> >
    class   vector  //: public container;
    {
		template<typename IterT>
		class RandomAccessIterator
		{
		private:
			pointer_ptr;
		public:
			RandomAccessIterator() : _ptr(nullptr) {}
			RandomAccessIterator(pointer rhs) : _ptr(rhs) {}
			RandomAccessIterator(const RandomAccessIterator<typename ft::remove_const<value_type>::type > & src) : _ptr(&(*src)) {} //copia: passa come parametro di inizializzazione un altro parametro RandomAccessIterator
			RandomAccessIterator<value_type> & operator=(RandomAccessIterator<typename ft::remove_const<value_type>::type >const & src) {
				_ptr = &(*src);
				return *this;
			}

			inline	RandomAccessIterator& operator+=(difference_type rhs) {_ptr += rhs; return *this;}
			inline	RandomAccessIterator& operator-=(difference_type rhs) {_ptr -= rhs; return *this;}
			inline	reference& operator*() const {return *_ptr;}
			inline	pointer	operator ->() const {return _ptr}
			inline	reference operator[] (difference_type rhs) const {return _ptr[rhs];}
			
			inline	RandomAccessIterator& operator++() {++ptr; return *this}
			inline	RandomAccessIterator& operator--() {--ptr; return *this}
			inline	RandomAccessIterator operator++(int)	{RandomAccessIterator tmp(*this); ++_ptr; return tmp;}
			inline	RandomAccessIterator operator--(int)	{RamdonAccessIterator tmp(*this); --_ptr; return tmp;}
			inline	difference_type operator -(const RandomAccessIterator& rhs) const {return _ptr-rhs._ptr;}
			inline	RandomAccessIterator operator +(difference_type rhs) const {return RandomAccessIterator(_ptr+rhs);}
			inline	RandomAccessIterator operator -(difference_type rhs) const {return RandomAccessIterator(_ptr-rhs);}
		}

			public:
				template<class A, class B>
				friend inline bool operator ==(const vector::template RandomAccessIterator<A>& lhs, const vector::template RandomAccessIterator<B>& rhs) {return &(*lhs) == &(*rhs);} //dereferenzia e poi ritorna true se sono lo stesso indirizzo. 
				template<class A, class B>
				friend inline bool operator != (const vector::template RandomAccessIterator<A>& lhs, const vector::template RandomAccessIterator <B>& rhs) {return &(*lhs) != &(*rhs);}
				template<class A, class B>
				friend inline bool operator >(const vector::template RandomAccessIterator<A>& lhs, const vector::template RandomAccessIterator <B>& rhs) {return &(*lhs) > &(*rhs);}
				template<class A, class B>
				friend inline bool operator <(const vector::template RandomAccessIterator<A>& lhs, const vector::template RandomAccessIterator <B>& rhs) {return &(*lhs) < &(*rhs);}
				template<class A, class B>
				friend inline bool operator >=(const vector::template RandomAccessIterator<A>& lhs, const vector::template RandomAccessIterator <B>& rhs) {return &(*lhs) >= &(*rhs);}
				template<class A, class B>
				friend inline bool operator <= (const vector::template RandomAccessIterator<A>& lhs, const vector::template RandomAccessIterator <B>& rhs) {return &(*lhs) <= &(*rhs);}
				template<class A, class B>
				friend typename vector::template RandomAccessIterator<A>::difference_type operator-(const vector::template RandomAccessIterator<A>& lhs, const vector::template RandomAccessIterator <B>& rhs) {return &(*lhs) - &(*rhs);}
				template<class A, class B>
				friend typename vector::template RandomAccessIterato<A>::difference_type operator+(const vector::template RandomAccessIterator<A>& lhs, const vector::template RandomAccessIterator <B>& rhs) {return &(*lhs) + &(*rhs);}
				template<class A>
				friend vector::template RandomAccessIterator <A> operator+(const vector::template RandomAccessIterator<A>::difference_type & a, const vector::template RandomAccessIterator<A> &iter){return (iter + a)}
				template<class A>
				friend vector::template RandomAccessIterator <A> operator-(const vector::template RandomAccessIterator<A>::difference_type & a, const vector::template RandomAccessIterator<A> &iter){return (iter - a)}


        public:
		typedef typename _Tp								value_type;
        typedef typename _Alloc                             allocator_type;
        typedef typename allocator_type::pointer            pointer;
		typedef	typename allocator_type::const_pointer		const_pointer;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::connt_reference    const_reference;
		typedef	RandomAccessIterator<value_type>			iterator;
		typedef	RandomAccessIterator<const value_type>		const_iterator;
		typedef	reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef	reverse_iterator<iterator>					reverse_iterator;
		typedef	ptrdiff_t									difference_type;
		typedef	size_t										size_type;

        typedef ft::vector_iterator<pointer>                iterator;
		typedef	ft::vector_iterator<

        protected:
        pointer         __vector;
        size_t          _capacity;
        alllocator_type _allocator;
        size_t          _size;

        public:

        //typename is like an alias to whatever i want

        //Constructors

        //Default constructor
        explicit vector(const <allocator_type>& alloc = allocator_type()): 
            __vector(NULL), _size(0), _capacity(0), _allocator(alloc)
        {
            this->__vector = this->_allocator.allocate(0);
        }
        explicit vector(const allocator_type& alloc):
        {
            this->__vector = this->_allocator.allocate(0);
            this->_size = 0;
            this->_capacity = 0;
            this->_allocator = alloc;
        }
        explicit vector(    size_type count,
                            const T& value = T(),
                            const Allocator& alloc = Allocator())
        {
            this->___vector = this->_allocator.allocate(count);
            this
        }
        iterator begin()
        {
            return (this->__vector);
        }
        const_iterator begin() const
        {
            return const_iterator(this->__vector);
        }
        iterator end()
        {
            return (this->begin() + this->_size);
        }
    };
}



#endif