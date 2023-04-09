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
            std::fstream file;
            file.open(MYFILE);
            file << "\n\n\n~~~~~~~~~~~~~~" << std::endl;
            NodeLL<T>* temp = head;
            std::cerr << "Length : " << length << std::endl;
            while(temp != nullptr)
            {
                file << "Searching " << temp->data << std::endl;
                if (temp->data == data)
                {
                    file << "!!!Found " << data << "!!!" << std::endl;
                    file.close();
                    return temp;
                }
                temp = temp->next;
            }
            file << "\n~Item Not Found~\n" << std::endl;
            file.close();
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
