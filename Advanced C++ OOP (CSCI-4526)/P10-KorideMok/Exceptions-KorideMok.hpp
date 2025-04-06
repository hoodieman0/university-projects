// Written by James Mok

#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include "tools.hpp"

// Types of Exceptions:
// * Stream Exceptions
// * Game Exceptions

//-----------------------------------------------------------------------------------------------------------------
// Stream Exceptions:
// StreamException() - Generic Stream Exception
//
// IncorrectUsageException() - the amount commandline arguments is incorrect
//      *Used in main
//
// BadOpenException() - the file cannot be opened
//      *Used in main
//
// InvalidGameTypeException() - the char read for Game::gametype is invalid
//      *Used in Game::Game()
//
// InvalidCharException() - The char read in the stream is invalid for the program
//      *Used in Board::getPuzzle()

class StreamException : public exception{
    protected:
        int code = 100;
        string error = "Generic Stream Exception";
    public:
        StreamException(const int code=100, const string s="Generic Stream Exception") : code(code), error(s) {}
        ~StreamException()=default;
        virtual ostream& print(ostream&) const;
};

class IncorrectUsageException : public StreamException {
    public:
        IncorrectUsageException() : StreamException(101, "IncorrectUsageException") {}
        ~IncorrectUsageException()=default;
        ostream& print(ostream&) const override;
};

class BadOpenException : public StreamException {
public:
    BadOpenException() : StreamException(102, "BadOpenException") {}
    ~BadOpenException()=default;
    ostream& print(ostream&) const override;
};

class InvalidGameTypeException : public StreamException{
    private:
        char input;
    public:
        InvalidGameTypeException(const char c) : StreamException(103,"InvalidGameTypeException"), input(c) {}
        ~InvalidGameTypeException()=default;
        ostream& print(ostream&) const override;
};

class InvalidCharException : public StreamException{
    private:
        char input;
        int line;

    public:
        InvalidCharException(const char c, const int line) : StreamException(104,"InvalidCharException"), input(c), line(line) {}
        ~InvalidCharException()=default;
        ostream& print(ostream&) const override;
};



inline ostream& operator<< (ostream& out, StreamException& e){
    return e.print(out);
}


//-----------------------------------------------------------------------------------------------------------------
// Game Exceptions:
// GameException() - Generic Game Exception
//
// MarkFixedException() - State::fixed is true at [row, col]
//      *Used in State::mark() and Square::mark()
//
// InvalidMarkerException() - Inputted char is not accepted by function
//      *Used in Square::mark()
//
// ExistingValueException() - The value inputted is used in an associated cluster
//      *Used in Square::mark()
//
// InvalidPositonException() - The row or column inputted is not in range
//      *Used in Board::mark

class GameException : public exception{
    protected:
        int code = 200;
        string error = "Generic Game Exception";
    public:
        GameException(const int code=200, const string s="Game Logic Exception") : code(code), error(s) {}
        ~GameException()=default;
        virtual ostream& print(ostream&) const;
};

class MarkFixedException : public GameException{
    private:
        int row, col;
    public:
    //unassociated state object is [0, 0]
        MarkFixedException(const int row=0, const int col=0) : GameException(201, "MarkFixedException"),
                row(row), col(col) {}
        ~MarkFixedException()=default;
        ostream& print(ostream&) const override;
};

class InvalidMarkerException : public GameException{
    private:
        char input;
    public:
        InvalidMarkerException(const char c) : GameException(202, "InvalidMarkException"), input(c) {}
        ~InvalidMarkerException()=default;
        ostream& print(ostream&) const override;
};

class ExistingValueException : public GameException{
    private:
        int row, col;
        char input;
    public:
        ExistingValueException(const char c, const int row, const int col) :
            GameException(203, "ExistingValueException"), input(c), row(row), col(col) {}
        ~ExistingValueException()=default;
        ostream& print(ostream&) const override;
};

class InvalidPositionException : public GameException {
    int row, col;
    public:
        InvalidPositionException(const int row, const int col) : GameException(204, "InvalidPositionException"), row(row), col(col) {}
        ~InvalidPositionException()=default;
        ostream& print(ostream&) const override;
};

inline ostream& operator<< (ostream& out, GameException& e){
    return e.print(out);
}

#endif
