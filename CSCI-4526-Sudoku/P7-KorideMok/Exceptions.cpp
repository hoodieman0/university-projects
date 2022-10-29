// Written by James Mok

#include "Exceptions.hpp"



ostream& Exception::
print(ostream& out) {
    out << "Error Code (" << code << ") " << error << endl;
    return out;
}

ostream& StreamException::
print(ostream& out) {
    out << "Error Code (" << code << ") " << error << endl;
    return out;
}

ostream& InvalidChar::
print(ostream& out) {
    out << "Error Code (" << code << ") " << error << endl;
    out << "Character \'" << input << "\' Is Invalid" << endl;
    return out;
}

ostream& GameException::
print(ostream& out) {
    out << "Error Code (" << code << ") " << error << endl;
    return out;
}

ostream& InvalidMark::
print(ostream& out) {
    out << "Error Code (" << code << ") " << error << endl;
    out << "Character \'" << input << "\' Cannot Be Used To Mark" << endl;
    return out;
}