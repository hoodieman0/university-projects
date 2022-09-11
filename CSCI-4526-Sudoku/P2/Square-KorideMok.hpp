// Written by James Mok and Niel Koride

#ifndef P1_MOK_SQUARE_KORIDEMOK_H
#define P1_MOK_SQUARE_KORIDEMOK_H

class State {
    private:
        short possibilities;
        char value;
        bool fixed; //is part of the original puzzle
        //why is the order important?

    public:
        State();
        State(char);
        ~State();
        void Mark(char);
        void Print();
};

class Square{

};

#endif P1_MOK_SQUARE_KORIDEMOK_H