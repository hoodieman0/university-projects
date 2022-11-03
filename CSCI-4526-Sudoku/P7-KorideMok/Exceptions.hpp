// Written by James Mok

#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include "tools.hpp"

/*
 * Main:
 *     -Incorrect number of arguments -> stream fatal()
 *
 * Game:
 *     -Cannot open file -> stream fatal()
 *     -Invalid game type char -> stream fatal()
 *
 * Board:
 *     -Invalid char in file -> stream fatal()
 *
 * Square:
 *     -Invalid char to mark -> game return
 *     -Mark is in cluster -> game return
 *
 * State:
 *     -State is fixed -> game return
 *
 * Cluster:
 *     -None
 *
 * DiagBoard:
 *     -None
 */



class Exception {
    public:
        int code = 100;
        string error = "Generic Exception";

    public:
        Exception(int code, string s) : code(code), error(s) {}
        ~Exception() = default;
        virtual ostream& print(ostream&);
};

class StreamException : public Exception{
    public:
        StreamException(int code=200, string s="Invalid Stream Exception") : Exception(code, s) {};
        ~StreamException() = default;
        virtual ostream& print(ostream&);
};

class InvalidChar : public StreamException{
    private:
        char input = '0';

    public:
        InvalidChar(char c) : StreamException(201,"Char From Stream Is Invalid"),
                                input(c) {}
        ~InvalidChar() = default;
        ostream& print(ostream&) override;
};

class GameException : public Exception{
    private:
    public:
        GameException(int code=300, string s="Game Logic Exception") : Exception(code, s) {}
        ~GameException() = default;
        virtual ostream& print(ostream&);
};

class InvalidMark : public GameException{
    private:
        char input = '0';
    public:
        InvalidMark(char c) : GameException(301, "Cannot Mark This Square"),
                                input(c) {}
        ~InvalidMark() = default;
        ostream& print(ostream&) override;
};

inline ostream& operator<< (ostream& out, Exception& e){
    return e.print(out);
}

#endif
