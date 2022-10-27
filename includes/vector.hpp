#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "ft_containers.hpp"
#include <vector>
#include <iostream>
using namespace std;

//Dany the cat.. everybody wants to be a cat!

// ToDo
// 1. Create RandomAccessIterator class     OK vic
// 2. Do RandomAccess vector operators      OK vic
// 3. Vector constructor and destructor     Ok vic
// 4. vector operators                      Ok sunnycat
// 5. vector iterators                      Ok sunnycat see vector_iterator.hpp
// 6. capacity methods                      Ok sunnycat
// 7. element access                        
// 8. modifiers
// 9. allocator
//10. non-member functions overloads

namespace ft
{
    template <bool Cond, class T = void>
	struct enable_if;

	template <typename T>
	struct enable_if<true, T>
	{
		public:
			typedef T 	type;
	};

	template <class T>
	struct is_integral
	{
		public:
			typedef bool 	value_type;
			typedef false_type	type;

			static const bool value = false;

			operator value_type()
			{
				return value;
			}
	};

	template <class T, class Alloc = std::allocator<T> >
    class   vector  //: public container;
    {
      

		public:
		template<typename IterT>
		class RandomAccessIterator
		{
			public: 
				typedef	typename iterator_traits<IterT*>::value_type		value_type;
				typedef	typename iterator_traits<IterT*>::pointer			pointer;
				typedef	typename iterator_traits<IterT*>::reference			reference;
				typedef	typename iterator_traits<IterT*>::difference_type	difference_type;
				typedef	typename iterator_traits<IterT*>::iterator_category	iterator_category;
				typedef	pointer												iterator_type;
			private:
				pointer _ptr;
			public:
				RandomAccessIterator() : _ptr(nullptr) {}
				RandomAccessIterator(pointer rhs) : _ptr(rhs) {}
				RandomAccessIterator(const RandomAccessIterator<typename remove_const<value_type>::type > & src) : _ptr(&(*src)) {} //copia: passa come parametro di inizializzazione un altro parametro RandomAccessIterator
				RandomAccessIterator<value_type> & operator=(RandomAccessIterator<typename remove_const<value_type>::type >const & src) {
					_ptr = &(*src);
					return *this;
				}

				inline	RandomAccessIterator& operator+=(difference_type rhs) {_ptr += rhs; return *this;}
				inline	RandomAccessIterator& operator-=(difference_type rhs) {_ptr -= rhs; return *this;}
				inline	reference& operator*() const {return *_ptr;}
				inline	pointer	operator ->() const {return _ptr;}
				inline	reference operator[] (difference_type rhs) const {return _ptr[rhs];}

				inline	RandomAccessIterator& operator++() {++_ptr; return *this;}
				inline	RandomAccessIterator& operator--() {--_ptr; return *this;}
				inline	RandomAccessIterator operator++(int)	{RandomAccessIterator tmp(*this); ++_ptr; return tmp;}
				inline	RandomAccessIterator operator--(int)	{RandomAccessIterator tmp(*this); --_ptr; return tmp;}
				inline	difference_type operator -(const RandomAccessIterator& rhs) const {return _ptr-rhs._ptr;}
				inline	RandomAccessIterator operator +(difference_type rhs) const {return RandomAccessIterator(_ptr+rhs);}
				inline	RandomAccessIterator operator -(difference_type rhs) const {return RandomAccessIterator(_ptr-rhs);}
		};

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
			friend typename vector::template RandomAccessIterator<A>::difference_type operator+(const vector::template RandomAccessIterator<A>& lhs, const vector::template RandomAccessIterator <B>& rhs) {return &(*lhs) + &(*rhs);}
			template<class L>
			friend vector::template RandomAccessIterator<L> operator+(const typename vector::template RandomAccessIterator<L>::difference_type & a, const vector::template RandomAccessIterator<L> &iter){return (iter + a);}
			template<class L>
			friend vector::template RandomAccessIterator<L> operator-(const typename vector::template RandomAccessIterator<L>::difference_type & a, const vector::template RandomAccessIterator<L> &iter){return (iter - a);}
			
  public:
		typedef T  							                value_type;
        typedef Alloc                                       allocator_type;
        typedef typename allocator_type::pointer            pointer;
		typedef	typename allocator_type::const_pointer		const_pointer;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
		typedef	RandomAccessIterator<value_type>			iterator;
		typedef	RandomAccessIterator<const value_type>		const_iterator;
		typedef	reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef	reverse_iterator<iterator>					reverse_iterator;
		typedef	ptrdiff_t									difference_type;
		typedef	size_t										size_type;

        //typedef ft::vector_iterator<pointer>                iterator;
		//typedef	ft::vector_iterator<

        private:
        pointer         __vector;
        size_t          _capacity;
        allocator_type _allocator;
        size_t          _size;
      

        public:

        // constructors
        explicit vector(const allocator_type& alloc = allocator_type()): __vector(0), _size(0), _capacity(0), _allocator(alloc) {return ;}
        explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& allocator = allocator_type()) : _allocator(_allocator), _capacity(n), _size(n)
		{
			__vector = _allocator.allocate(n);
			for (size_type i = 0; i < n; i++)
				_allocator.construct(__vector + i, val);
		}
       template <class InputIterator>
	   vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
	   			typename enable_if<!is_integral<InputIterator>::value>::type* = 0) : _allocator(alloc)
			{
				difference_type n = (first - last);
				_size = static_cast<size_type>(n);
				_capacity = _size;
				__vector = _allocator.allocate(n);

				for (difference_type i = 0; i < n; ++i, ++__vector)
					_allocator.construct(__vector + i, *first);
			}
		vector (const vector& x) : _capacity(0), _size(0) {*this = x;}
	   // Destructor
	   ~vector()
	   {
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(__vector + i);
			if (_capacity)
				_allocator.deallocate(__vector, _capacity);
	   }
		// Operator
		vector &operator = (const vector &copy)
		{
			if (this == &copy)
				return *this;

			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(__vector + i);
			if (_capacity < copy._size)
			{
				if (_capacity)
					_allocator.deallocate(__vector, _capacity);
				this->__vector = this->_allocator.allocate(copy._size);
			}
			this->_size = copy._size;
			this->_capacity = copy._capacity;
			for (size_type i = 0; i < _size; i++)
				this->_allocator.construct(this->__vector + i, copy[i]);
			return *this;
		}
		// Iterators
		iterator begin() { return iterator(__vector); }
		const_iterator begin() const {return const_iterator(__vector); }
		iterator end() {return iterator(__vector + _size) ;}
		const_iterator end() const {return const_iterator(__vector + _size); }
		reverse_iterator rbegin() {return reverse_iterator(end()); }
		const_reverse_iterator rbegin() const {return const_reverse_iterator(end()); }
		reverse_iterator rend() {return reverse_iterator(begin()); }
		const_reverse_iterator rend() const {return const_reverse_iterator(begin()); }


        //Member functions


        size_type				size() const { return this->_size; };

        size_type				max_size() const { return std::numeric_limits<size_type>::max() / sizeof(value_type); };

        void					resize (size_type n, value_type val = value_type())
        {
            while (n < this->size())
                this->pop_back();
            while (n > this->size())
                this->push_back(val);
        }

        // Capacity methods
        size_type				capacity() const { return this->_capacity; };

        bool					empty() const { return (this->_size == 0); };

        void					reserve(size_type n)
        {
            if (n > this->max_size())
                throw (std::length_error("vector max_size"));
            if (n <= this->capacity())
                return;
            pointer tmp = this->_allocator.allocate(n);
            for (size_type i = 0; i < this->size(); i++)
                tmp[i] = this->__vector[i];
            this->deallocate();
            this->_capacity = n;
            this->__vector = tmp;
        };

        reference				operator[] (size_type n) { return (this->__vector[n]); }
        const_reference			operator[] (size_type n) const { return (this->__vector[n]); }

        reference				at (size_type n)
        {
            if (n < 0 || n >= this->size())
                throw std::out_of_range("out of bounds");
            return (this->__vector[n]);
        }
        const_reference			at (size_type n) const
        {
            if (n < 0 || n >= this->size())
                throw std::out_of_range("out of bounds");
            return (this->__vector[n]);
        }

        reference				front() { return (this->__vector[0]); };
        const_reference			front() const { return (this->__vector[0]); };

        reference				back() { return (this->__vector[this->size() - 1]); };
        const_reference			back() const { return (this->__vector[this->size() - 1]); };

        template <class InputIterator>
        void					assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
        {
            this->clear();
            this->insert(begin(), first, last);
        };
        void					assign(size_type n, const value_type& val)
        {
            this->clear();
            this->insert(begin(), n, val);
        };

        void push_back(const value_type& x)
        {
            size_type i = 0;
            if (this->_capacity == 0)
            {
                this->reserve(1);
                this->_size++;
                this->_allocator.construct(this->__vector, x);
                return ;
            }
            if (this->_size == this->_capacity)
            {
                if (this->_capacity == 0)
                    this->_capacity = 1;
                T* temp = this->_allocator.allocate(2 * this->_capacity);
                this->_capacity *= 2;
                while(i < this->_size)
                {
                    this->_allocator.construct(temp + i, this->__vector[i]);
                    i++;
                }
                this->_allocator.deallocate(this->__vector, this->_size);
                this->__vector = temp;
            }
            this->_allocator.construct(this->__vector + this->_size, x);
            this->_size++;
        };

        void					pop_back()
        {
            if (this->size() > 0)
                this->_size--;
        };

        iterator					insert(iterator pos, const value_type &v)
        {
            size_type n = pos - this->begin();
            this->insert(pos, 1, v);
            return (iterator(this->__vector + n));
        }

        void insert (iterator position, size_type n, const value_type& val)
        {
            pointer		tmp;
            size_type	cap = this->_capacity;
            size_type	shift = -1;
            size_type	pos = position - this->begin();
            size_type	newSize = ((pos + n) >= (this->_size + n)) ? (pos + n): (this->_size + n);

            if (newSize > this->_capacity)
            {
                tmp = this->__vector;
                this->_capacity = ((this->_capacity * 2) >= (this->_size + n)) ? (this->_capacity * 2) : (this->_size + n) ;
                this->__vector = this->_allocator.allocate(this->_capacity);
                while(++shift < this->_size)
                    this->__vector[shift] = tmp[shift];
                this->_allocator.deallocate(tmp, cap);
            }
            shift = this->_size - pos;
            this->_size = newSize;
            while ((int)shift-- > 0 && newSize--)
                this->__vector[newSize] = this->__vector[newSize - n];
            while (n--)
                this->__vector[pos++] = val;
        }

        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last,
                    typename ft::enable_if<!ft::is_integral <InputIterator>::value, InputIterator>::type * = NULL)
        {
            InputIterator tmp2 = first;
            pointer		tmp;
            size_type	count = 0;
            while (tmp2++ != last)
                count++;
            size_type	cap = this->_capacity;
            size_type	shift = -1;
            size_type	n = count;
            size_type	pos = position - this->begin();
            size_type	newSize = ((pos + n - 1) >= (this->_size + n - 1)) ? (pos + n - 1): (this->_size + n - 1);

            newSize++;
            if (newSize > this->_capacity)
            {
                tmp = this->__vector;
                this->_capacity = ((this->_capacity * 2) >= (this->_size + n)) ? (this->_capacity * 2) : (this->_size + n);
                this->__vector = this->_allocator.allocate(this->_capacity);
                while(++shift < this->_size)
                    this->__vector[shift] = tmp[shift];
            this->_allocator.deallocate(tmp, cap);
            }
                shift = this->_size - pos;
                this->_size = newSize;
                while ((int)shift-- > 0 && newSize--)
                    __vector[newSize] = __vector[newSize - n];
            try
            {
                while (n--)
                    __vector[pos++] = *(first++);
            }
            catch (...)
            {
                this->_size = 0;
                this->_capacity = 0;
                throw std::exception();
            }
        }

        iterator				erase (iterator position)
        {
            size_type i = position - begin();

            --_size;
            for (; i < _size; i++)
                __vector[i] = __vector[i + 1];
            _allocator.destroy(__vector + i);
            return (position);
        };

        iterator				erase (iterator first, iterator last)
        {
            size_type size = last - first;
            size_type _first = first - begin();
            size_type  i = _first + size - 1;

            while (i >= _first && i != 0){
                _allocator.destroy(__vector + i--);
            }
            if (_first == 0)
                _allocator.destroy(__vector + i--);
            _size -= size;
            for (i = i + 1; i < _size; i++){
                __vector[i] = __vector[i + size];
            }
            _size = i;
            return (first);
        }

        void					swap (vector& x)
        {
            std::swap(this->_size, x._size);
            std::swap(this->_capacity, x._capacity);
            std::swap(this->_allocator, x._allocator);
            std::swap(this->__vector, x.__vector);
        }

        void					clear()
        {
            for (size_type i = 0; i < _size; i++)
                _allocator.destroy(__vector + i);
            this->_size = 0;
        };

        allocator_type			get_allocator() const { return (this->_allocator); };

    };
}



#endif