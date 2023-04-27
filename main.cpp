#include <iostream>
#include "doubly_linked_list.hpp"

int main()
{
	Doubly_linked_list<int> list;
	//add some elements to the list
	list.push_back(2);
	list.push_front(1);

	//print list
	list.print();

	return 0;
}

