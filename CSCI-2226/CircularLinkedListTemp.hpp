#ifndef CircularLinkedList_hpp
#define CircularLinkedList_hpp

#include <iostream>
using namespace std;

//Creates a circular linked list of any type to simulate individual slot machine reels.

template <class T> struct Node
{
    T data;
    struct Node* next;
};

template <class T> class LinkedList
{
    private:
        int length;

        struct Node<T>* currentPosition = nullptr;
        struct Node<T>* head = nullptr;
        struct Node<T>* back = nullptr;

        bool isEmpty = true;
        bool isCurrentPosition = true;

    public:
        LinkedList();
        ~LinkedList();
        void MakeEmpty();
        void PutItem(T);
        T GetNextItem();
};


template <class T> LinkedList<T>::LinkedList()
{
    length = 0;
    currentPosition = nullptr;
    head = nullptr;
    back = nullptr;
}

template <class T> LinkedList<T>::~LinkedList()
{
    MakeEmpty();
}

template <class T> void LinkedList<T>::MakeEmpty()
{
    struct Node<T>* temp = nullptr;
    while(head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    length = 0;
}

template <class T> void LinkedList<T>::PutItem(T symbol)
{
    struct Node<T>* temp;
	temp->data = symbol;
    std::cerr << "Assignments Passed" << endl;
    
    if(isEmpty) //this would not trigger with back == nullptr
    {
        std::cerr << "2Passed" << endl;
        back = temp;
        std::cerr << "Passed" << endl;
        back->next = back;
        isEmpty = false;
        std::cerr << "Back Creation Passed" << endl;
    } 
	else
    {
        std::cerr << "3Passed" << endl;
        temp->next = back->next;
        back->next = temp;
        std::cerr << "Insertion Passed" << endl;
    }

    head = temp;
    std::cerr << "Head Creation Passed" << endl;

	length++; 
}

template <class T> T LinkedList<T>::GetNextItem()
{
    if (isCurrentPosition) //does not trigger with currentPosition == nullptr
    {
        currentPosition = head;
        isCurrentPosition = false;
    }
    else
    {
        currentPosition = currentPosition->next;
    }
	std::cerr << head->data << "|" << currentPosition->data << endl;
    T stuff = currentPosition->data;
	return stuff;
}

#endif