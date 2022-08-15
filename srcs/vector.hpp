#include <sstream>
#include <iostream>
//Vectors are sequence containers 
//representing arrays that can change in size.

//vectors use contiguous storage locations for their elements, 
// their elements can be accessed using offsets on regular pointers to its elements
//their size can change dynamically, with their storage being handled automatically by the container.

//Internally, vectors use a dynamically allocated array to store their elements.
//This array may need to be reallocated to grow size when new elements are inserted, 
// which implies allocating a new array and moving all elements to it.
// vectors do not reallocate each time an element is added to the container.

//vector containers may allocate some extra storage to accommodate for possible growth, and thus the container 
// may have an actual capacity greater than the storage strictly needed to contain its elements
//reallocations should only happen at logarithmically growing intervals of size so that the insertion of individual 
// elements at the end of the vector can be provided with amortized constant time complexity (see push_back).


//Compared to the other dynamic sequence containers (deques, lists and forward_lists), vectors are very efficient accessing 
// its elements and relatively efficient adding or removing elements from its end. 
//For operations that involve inserting or removing elements at positions other than the end, they perform worse than the others, 
// and have less consistent iterators and references than lists.

//SEQUENCE: Elements in sequence containers are ordered in a strict linear sequence. Individual elements are accessed by their 
//position in this sequence.

// DYNAMIC ARRAY: Allows direct access to any element in the sequence, even through pointer arithmetics, and provides relatively fast
// addition/removal of elements at the end of the sequence.

// ALLOCATOR-AWARE: The container uses an allocator object to dynamically handle its storage needs.

namespace	ft{

	class   Vector{
		private:
				const std::string _name;
				const int	size;
				
		public: 
			Vector();
			~Vector();


			Vector & operator = (Vector &same);
			//iterators
			int	begin(Vector vector);
			int	end(Vector vector);

			//capacity
			int	size();

			//modifiers
			void	push_back(); //adds new element to end of vestor after last element. 
								// increases size of 1 and only if size > capacity 
								//triggers re-allocatin of space.

	};
}