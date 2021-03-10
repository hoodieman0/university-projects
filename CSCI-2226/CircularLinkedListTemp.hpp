#ifndef CircularLinkedList_hpp
#define CircularLinkedList_hpp

using namespace std;

// template <typename T>
struct Reel
{
    char data;
    Reel* next;
};


template <typename T>

//Creates a circular linked list of any type to simulate individual slot machine reels.
class LinkedList
{
    private:
        int length;
        Reel* currentPosition;
        Reel* head;
        Reel* back;

    public:
        void Intitialize();
        ~LinkedList();
        void MakeEmpty();
        void PutItem(T);
        T GetNextItem();
};


template <typename T> void LinkedList<T>::Intitialize()
{
    length = 0;
    currentPosition = nullptr;
    head = nullptr;
    back = nullptr;
}

template <typename T> LinkedList<T>::~LinkedList()
{
    MakeEmpty();
}

template <typename T> void LinkedList<T>::MakeEmpty()
{
    Reel* temp = nullptr;
    while(head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    length = 0;
}

template <typename T> void LinkedList<T>::PutItem(T symbol)
{
    Reel* temp = new Reel;
	temp->data = symbol;
    if(temp->next == nullptr)
    {
        temp->next = temp;
        back = temp;
    } 
	else
    {
        temp->next = head;
    }

	head = temp; 
    back->next = head;
    currentPosition = head;
	length++; 
}

template <typename T> T LinkedList<T>::GetNextItem(){
	T data = currentPosition->data; 
	currentPosition = currentPosition->next; 
	return data; 
}



#endif