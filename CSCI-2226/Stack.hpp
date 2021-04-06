#pragma once

template <class T> struct Node
{
    T data;
    Node<T>* next;
};

template <class T>
class Stack
{
    private:
        Node<T>* top; 

    public:
        Stack()
        {
            top = nullptr; 
        }
 
        void Push(T item)
        {
            Node<T>* temp = new Node<T>; 
            temp->data = item; 
            temp->next = top; 
            top = temp; 
        } 

        T Top()
        {
            if(IsEmpty())
                throw StackEmptyException("Stack Is Empty"); 
            return top->data; 
        }
        
        void Pop()
        {
            if (IsEmpty())
                throw StackEmptyException("Stack Is Empty");
            Node<T>* temp = top;
            top = top->next; 
            delete temp;  
        } 

        bool IsFull() const
        {
            try
            {
            Node<T>* temp = new Node<T>; 
            delete temp;
            }
            catch(std::bad_alloc)
            {
                return true; 
            }
            return false; 
        } 

    bool IsEmpty() const
    {
        return(top == nullptr); 
        
    } 
    ~StackLi()
    {
        Node<T>* temp;
        while(top != nullptr)
        {
            temp = top; 
            top = top->next;
            delete temp;  
        }
    }
    std::ostream& operator<<(std::ostream& out, Stack& s)
    {
        out << "Stack: ["; 
        if (s.IsEmpty()) 
            out << "(Empty)"; 
        else
        {
            out << "(Not-Empty)"; 
        }
        out << "]";
        return out; 
    }
};

