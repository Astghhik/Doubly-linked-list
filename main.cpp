#include <iostream>
#include "doubly_linked_list.hpp"

int main()
{
	Doubly_linked_list<int> list;


	list.push_back(2);
	list.push_front(1);
	list.print();
	list.reverse();
	list.print();

	list.insert(1,5);
        list.print();


	return 0;
}

