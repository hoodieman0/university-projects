#ifndef CircularLinkedList_hpp
#define CircularLinkedList_hpp

#include <iostream>
using namespace std;

//Creates a circular linked list of any type to simulate individual slot machine reels.

template <class T> struct Node
{
    T data;
     Node* next;
};

template <class T> class LinkedList
{
    private:
        int length;

        Node<T>* currentPosition;
        Node<T>* back;

    public:
        LinkedList()
        {
            length = 0;
            currentPosition = nullptr;
            back = nullptr;
        }

        ~LinkedList()
        {
            MakeEmpty();
        }

        void MakeEmpty()
        {
            struct Node<T>* temp = nullptr;
            while(back != nullptr)
            {
                temp = back;
                back = back->next;
                delete temp;
            }
            length = 0;
        }

        void PutItem(T symbol)
        {
            Node<T>* temp = new Node<T>;
	        temp->data = symbol;
            if(back == nullptr)
            {
                back = temp;
                temp->next = back;
            } 
	        else
            {
                temp->next = back->next;
                back->next = temp;
            }

	        length++; 
        }

        T GetNextItem()
        {
            Node<T>* temp = new Node<T>;
            temp = back;
    
            if (currentPosition == nullptr)
            {
                currentPosition = temp;
            }
            else
            {
                currentPosition = currentPosition->next;
            }
            T stuff = currentPosition->data;
	        return stuff; 
        }
};

#endif