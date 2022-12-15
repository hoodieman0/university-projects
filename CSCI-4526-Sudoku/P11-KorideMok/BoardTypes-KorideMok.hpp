// Written by James Mok

#ifndef DIAG_HPP
#define DIAG_HPP

#include "Board-KorideMok.hpp"

class TradBoard: public Board{
    private:
        void createBox(const short row, const short col);
    public:
        TradBoard()=default;
        TradBoard(short, short, ifstream&);
        ~TradBoard()=default;
        
};

class DiagBoard : public TradBoard {
    private:
        void createDiagonal();
    public:
        DiagBoard()=default;
        DiagBoard(short, short, ifstream&);
        ~DiagBoard()=default;
        
};

class SixyBoard : public Board {

};

class SixyBoard : public Board{
    private:
        void createVertBox(int row, int col);
        void createHorBox(int row, int col);
    public:
        SixyBoard()=default;
        SixyBoard(short, short, ifstream&);
        ~SixyBoard();

};

#endif
