// Written by James Mok and Neelakanta Bharadwaj Koride

#include "tools.hpp"
#include "Square-KorideMok.hpp"


class Board{
    private:
        int n = 9; // Size of the puzzle
        Square bd[81]; //TODO changable array size
        ifstream& file;
        short left;
        void getPuzzle();

    public:
        Board(int, ifstream&);
        inline ~Board(){ cout <<"~Destroying Board~" <<endl; }
        inline Square& sub(int j, int k){ return bd[(j - 1) * 9 + (k + 1)]; }
        ostream& print(ostream&);
};

inline ostream& operator<<(ostream& out,Board& b){
    return b.print(out);
}