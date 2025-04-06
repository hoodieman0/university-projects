#pragma once
#include <iostream>
#include <fstream>

#define MYFILE "myfile.txt"

template <class T> struct NodeLL
{
    T data;
    NodeLL<T>* next;
};

template <class T> class LinkedList
{
    private:
        int length;

        NodeLL<T>* currentPosition;
        NodeLL<T>* head;

    public:
        LinkedList()
        {
            length = 0;
            currentPosition = nullptr;
            head = nullptr;
        }

        ~LinkedList()
        {
            MakeEmpty();
        }

        void MakeEmpty()
        {
            struct NodeLL<T>* temp = nullptr;
            while(head != nullptr)
            {
                temp = head;
                head = head->next;
                delete temp;
            }
            length = 0;
        }

        void Insert(T data)
        {
            NodeLL<T>* temp = new NodeLL<T>; 
	        temp->data = data;
            temp->next = head;
            head = temp;
	        length++; 
        }

        NodeLL<T>* Find(T data)
        {
            NodeLL<T>* temp = head;
            while(temp != nullptr)
            {
                if (temp->data == data)
                {
                    return temp;
                }
                temp = temp->next;
            }
            throw "\n~Item Not Found~\n";
        }

        void ResetList()
        {
            currentPosition = head;
        }

        int GetLength()
        {
            return length;
        }
};
