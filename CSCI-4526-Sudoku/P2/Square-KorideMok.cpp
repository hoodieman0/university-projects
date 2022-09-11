// Written by James Mok and Niel Koride

#include "Square-KorideMok.hpp"

ostream& print( ostream& );

// ---------------------------------------------------------------------
// Default Constructor for State objects
// Precondition: None
// Postconiditon: Null value State object is created
State::
State(){
    cout <<"Default State Constructor" << endl;
    value = '\0';
    fixed = false;
    possibilities = 0;
}

// ---------------------------------------------------------------------
// State Constructor
// Precondition: None
// Postcondition: State object is created
State::
State(char startingValue){
    value = startingValue;
    if (startingValue == '-'){
        possibilities = 0x3FE; //binary: 0011 1111 1110
        fixed = false;
    }
    //unit test value
    else if (startingValue == '~'){
        possibilities = 0x0f2;
        fixed = false;
        value = '-';
    }
    else{
        possibilities = 0x000;
        fixed = true;
    }
}

// ---------------------------------------------------------------------
// State Destructor
// Precondition: State object exists
// Postcondition: Deletes State object
State::
~State(){
    cout <<"Default State Destructor" <<endl;
}

// ---------------------------------------------------------------------
// Marks the State object with a valid character
// Precondition: State object exists
// Postcondition: Changes State variable "value" to the given character
// Failure: "Cannot Add Value"
void State::
mark(char ch){
    if (!this->fixed){
        value = ch;
    }
    else{
        cout <<"Cannot Add Value" <<endl;
    }
}

// ---------------------------------------------------------------------
// Prints the variables of the State object in a human-readable format
// Preconditions: State object exists
// Postconditions: Prints the variables to the console
void const State::
print(){
    cout <<"value: " <<value <<endl;
    cout <<"fixed: " <<boolalpha <<fixed <<endl;
    cout <<"possibilities: ";

    short temp = possibilities >> 1;
    short mask = 0x001;
    for (int counter = 1; counter <= 9; counter++){
        if ((temp & mask) == 1){
            cout << counter;
        }
        else{
            cout << '-';
        }

        temp = temp >> 1;
    }
    cout << endl;
}

// ---------------------------------------------------------------------
// Default constructor for Square
// Preconditions: None
// Postconditions: None
Square::
Square(){
    cout <<"Square Default Constructor" << endl;
}

Square::
Square(char startingValue, short r, short c) : info(startingValue)
{
    row = r;
    col = c;
    cerr <<"Constructing Square " <<row <<", " <<col <<endl;
}

Square::
~Square(){
    cerr <<"Destroying Square " <<row <<", " <<col <<endl;
}

void Square::
mark(char marker){
    info.mark(marker);
}

void const Square::
print(){
    cout <<"Square [" <<row <<", " <<col <<"] ";
    info.print();
}