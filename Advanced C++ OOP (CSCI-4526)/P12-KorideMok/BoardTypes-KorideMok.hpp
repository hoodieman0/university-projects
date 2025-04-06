// Written by James Mok

#ifndef DIAG_HPP
#define DIAG_HPP

#include "Board-KorideMok.hpp"

class TradBoard: public Board{
    private:
        void createBox(const short row, const short col);
    public:
        TradBoard()=default;
        TradBoard(short n, short clstr, ifstream& input);
        ~TradBoard()=default;
        
};

class DiagBoard : public TradBoard {
    private:
        void createDiagonal();
    public:
        DiagBoard()=default;
        DiagBoard(short n, short clstr, ifstream& input);
        ~DiagBoard()=default;
        
};

class SixyBoard : public Board{
    private:
        void createVertBox(int row, int col);
        void createHorBox(int row, int col);
    public:
        SixyBoard()=default;
        SixyBoard(short size, short clstr, ifstream& file);
        ~SixyBoard()=default;
};

#endif
