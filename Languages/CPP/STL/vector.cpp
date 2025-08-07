#include <iostream>
#include <vector>

int main() {

	/****************************************ITERATORS******************************************/

	/* //1. Modifying the content of a vector at runtime
	std::vector<int> v{1}; 
	std::vector<int>::iterator it = v.begin();
	for(it; it!=v.end(); ++it) {
		*it = 5; //begin(), end(), rbegin(), rend() can modify the content of container at runtime
	}

	for(it=v.begin(); it!=v.end(); ++it) {
		std::cout<<*it<<" ";
	}

	//cbegin() and cend() does not allow to modify content at runtime
	for(auto it=v.cbegin(); it!=v.cend(); ++it) {
		*it = 5; //error here
	} 
	*/

	/***************************************CAPACITY*******************************************/

	/* 2. size(): returns the number of elements in the vector */

	/* 3. max_size(): returns the max number of elem the vector can hold */
	
	/*// 4. capacity(): returns the number of elements that can be held in the current allocated space.
	// Adding an element beyond the capacity, increases its capacity by a factor of 2, generally,
	// provided it does not violate the max_size of the vector
	std::vector<int> vec{};
	std::cout<<"Capacity of vector is: "<<vec.capacity()
			 <<" and the num of elems in it is is: "<<vec.size()<<std::endl;

	vec.resize(5);
	std::cout<<"Size of the vector after resize: "<<vec.capacity()<<" and its size is: "<<vec.size()<<std::endl;

	vec.assign({1,2,3,4,5});
	vec.push_back(6);	
	std::cout<<"New Capacity of the vector after adding an elem beyond its current capacity: "
			 <<vec.capacity()<<" but the num of elems in it is: "<<vec.size()<<std::endl; */

	/* 5. empty(): returns true if the vector is empty, else false */
	

	/* //6. shrink_to_fit(): requests the removal of unused capacity. This should be used after the resize method
	std::vector<int> v{1,2,3,4,5};
	std::cout<<"Capacity of the vector is: "<<v.capacity()<<std::endl;

	v.resize(2);
	std::cout<<"vector resized to contain 2 elems\n";
	v.shrink_to_fit();

	std::cout<<"After shrinking its capacity is: "<<v.capacity()<<std::endl; */


	/****************************************MODIFIERS*******************************************/

	/*
		1. clear(): a. erases all the elems of the container, and the size() becomes 0
					b. This also invalidates any refs, pointers or iterators referring to any 
					   contained elem.
					c. It also invalidate any past-the-end iterators
	*/

	/*
		2. erase(pos): erases the elem at the pos, pos must be provided as an iterator
		   erase([start, end)): removes the range of elems from start to end-1, 
		   						start and end are iterators
	*/

	/* 3. push_back(): adds an elem to the end */
	/* 4. pop_back(): removes an elem from the end */
	
	/* 
		5. resize(n, [value]): a. changes the capacity of the container to contain n elems. 
					 		   b. if n==size(), does nothing
					 		   c. if n>size(), increases the capacity to contain n elems and initializes the 
					 			  space with elem 'value', if provided, else garbage
	*/

	/*
		6. a1.swap(a2): a. Exchanges the content and capacity of vector a1 and a2. 
						b. It does not perform any move, copy or swap operation on elems
						c. All iterators and refs remain valid, only the end() iterator is invalidated
	*/

	return 0;
}