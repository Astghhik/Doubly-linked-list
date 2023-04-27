#include <iostream> 
#include <cassert>

template <typename T>
class Node
{
	public:
		T data;
		Node<T> *next;
		Node<T> *prev;

		//constructor
		Node(T data)
		{
			this->data = data;
			prev = NULL;
			next = NULL;
		}

};

template <typename T>
class Doubly_linked_list
{	
	private:
		Node<T> *head;
		Node<T> *tail;
		int size;

	public:
		//constructor
		Doubly_linked_list()
		{
			head = NULL;
			tail = NULL;
		}

		//Destructor
		~Doubly_linked_list()
		{
			while (head != NULL) {
                        pop_front();
			}

		}

                
	        //Function  adds new node to the front of the list	
		void push_front(T data)
		{
			Node<T> *node = new Node<T>(data);
			if(head == NULL)
			{
				head = node;
				tail = node;
			}
			else
			{
				node->next = head;
				head->prev = node;
				head = node;
			}
		          size++;
            }
                
		//adds a new node with the given value to the back of the list
		void push_back(T data)
		{
			Node<T> *node = new Node<T>(data);
			if(tail == NULL)
			{
				head = node;
				tail = node;
			}
			else
			{
				node->prev = tail;
				tail->next = node;
				tail =  node;
			}
			size++;
		}
                
		//returns the value stored in the first node of the list
		T front()
		{
			assert(head != NULL);
			return head->data;
		}
		
		//returns the value stored in the last node of the list
		T back()
		{
			assert(tail != NULL);
			return tail->data;
		}
                
		//print list elements
		void print()
		{
			Node<T> *current = head;
			while(current != NULL)
			{
				std::cout<<current->data<<" ";
				current = current->next;
			}
			std::cout<<std::endl;
		}
                
		 T get_size()
                {
                        return size;
                }
		 void pop_front()
		{
			assert(head != NULL);
			Node<T>* temp = head;
			head = head->next;
			if(head != NULL)
			{
				head->prev = NULL;
			}
			else
			{
				tail = NULL;
			}
			delete temp;
			size--;
		}
};



