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
        cerr <<"Cannot Add Value" <<endl;
    }
}

// ---------------------------------------------------------------------
// Prints the variables of the State object in a human-readable format
// Preconditions: State object exists
// Postconditions: Prints State's variables to the console
void const State::
print(){
    cout <<"value: " <<value <<" fixed: " <<boolalpha <<fixed;
    cout <<" possibilities: ";

    short temp = possibilities >> 1;
    short mask = 0x001;
    for (int counter = 1; counter <= 9; counter++){
        if ((temp & mask) == 1){
            cout << counter;
        }
        else{
            cout <<'-';
        }

        temp = temp >> 1;
    }
    cout <<endl;
}

// ---------------------------------------------------------------------
// Default constructor for Square
// Preconditions: None
// Postconditions: None
Square::
Square(){
    cout <<"Square Default Constructor" << endl;
}

// ---------------------------------------------------------------------
// Constructor for Square
// Preconditions: None
// Postconditions: A square object with a State, row, and column is created
Square::
Square(char startingValue, short r, short c) : info(startingValue)
{
    row = r;
    col = c;
    cout <<"Constructing Square " <<row <<", " <<col <<endl;
}
// ---------------------------------------------------------------------
// Default destructor for Square
// Preconditions: Square object exists
// Postconditions: Square object is deleted
Square::
~Square(){
    cout <<"Destroying Square " <<row <<", " <<col <<endl;
}

// ---------------------------------------------------------------------
// Marks the specific Square with a given char
// Preconditions: Square object exists
// Postconditions: Square's State's value is changed to 'marker'
void Square::
mark(char marker){
    info.mark(marker);
}

// ---------------------------------------------------------------------
// Prints the values of the Square object in a human-readable format
// Preconditions: Square object exists
// Postconditions: Prints Square's variables to the console
void const Square::
print(){
    cout <<"Square [" <<row <<", " <<col <<"] ";
    info.print();
    //cout << this;
}