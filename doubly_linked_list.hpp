#include <iostream> 
#include <cassert>

template <typename T>
class Node
{
	public:
		T data;
		Node<T> *next;
		Node<T> *prev;

		//Constructor
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
		//Constructor
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
                
		//Function adds new node to the back of the list
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
                
		T front()
		{
			assert(head != NULL);
			return head->data;
		}
		
		T back()
		{
			assert(tail != NULL);
			return tail->data;
		}
                
		//Print
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
                //Function gets size
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
		
		void pop_back()
		{	
			assert(head != NULL);
			Node<T>* temp = tail;
			tail = tail->prev;
			if(tail != NULL)
			{
				tail->next = NULL;
			}
			else
			{
				head = NULL;
			}
			delete temp;
			size--;
		}

		void insert(int index,T val)
		{
			assert(index >= 0 && index <= size);
			Node<T>* node = new Node<T>(val);
			if (index == 0)
			{
				push_front(val);
			}
			else if (index == size)
			{
				push_back(val);
			}
			else
			{
				Node<T>* current = head;
				for(int i=0; i < index; i++)
				{
					current = current->next;
				}
				node->next = current;
                                node->prev = current->prev;
				current->prev->next = node;
				current->prev = node;
				size++;
			}
		}	

		T& operator[](int index)
		{
			assert(index >= 0 && index < size);
			Node<T>* current = head;
			for(int i=0; i < index; i++)
			{
				current = current->next;
			}
			return current->data;
		}
                
		void reverse()
		{
			Node<T>* current = head;
			Node<T>* temp = NULL;
			while(current != NULL)
			{
				temp = current->prev;
				current->prev = current->next;
				current->next = temp;
				current = current->prev;
			}

			temp = head;
			head = tail;
			tail = temp;
      		}

};



