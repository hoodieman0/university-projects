// Written by James Mok

#include "Exceptions.hpp"

ostream& StreamException::
print(ostream& out) const {
    out << "Error Code (" << code << ") " << error << endl;
    return out;
}

ostream& IncorrectUsageException::
print(ostream& out) const {
    out << "Error Code (" << code << ") " << error << endl;
    out << "Incorrect Amount Of Arguments\nUsage: program-name input-file" << endl;
    return out;
}

ostream& BadOpenException::
print(ostream& out) const {
    out << "Error Code (" << code << ") " << error << endl;
    out << "Unable To Open Input-File" << endl;
    return out;
}

ostream& InvalidGameTypeException::
print(ostream& out) const {
    out << "Error Code (" << code << ") " << error << endl;
    out << "Character \'" << input << "\' In Input File Is Not A Valid Game Type" << endl;
    return out;
}

ostream& InvalidCharException::
print(ostream& out) const {
    out << "Error Code (" << code << ") " << error << endl;
    out << "Character \'" << input << "\' In Input File Cannot Be Used In A Sudoku Square" << endl;
    return out;
}


//-------------------------------------------------------------------------------------------------------------------
ostream& GameException::
print(ostream& out) const {
    out << "Error Code (" << code << ") " << error << endl;
    return out;
}

ostream& MarkFixedException::
print(ostream& out) const {
    //out << "Error Code (" << code << ") " << error << endl; //Not needed because it does not exit the game
    out <<"Square [" <<row << ", " <<col << "] Is A Fixed Value!" <<endl;
    return out;
}

ostream& InvalidMarkerException::
print(ostream& out) const {
    //out << "Error Code (" << code << ") " << error << endl; //Not needed because it does not exit the game
    out <<"Character \'" << input << "\' Is An Invalid Character!" << endl;
    return out;
}

ostream& ExistingValueException::
print(ostream& out) const {
    out <<"Character \'" << input << "\' Is Already Used In A Cluster For Square [" << row <<", " <<col <<"]!" <<endl;
    return out;
}

ostream& InvalidPositionException::
print(ostream& out) const {
    out <<"Square [" <<row << ", " <<col << "] Does Not Exist!" <<endl;
    return out;
}