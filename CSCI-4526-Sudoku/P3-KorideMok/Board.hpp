#include "tools.hpp";
#include "Square-KorideMok.hpp";

class Board{
private:
    int N; // Size of the puzzle
    int NSquares[10];
    ifstream& file;
    short int left;
    void getPuzzle();


public:
    ~Board(){cout<<"Trace Comment"<<endl;}
    Board(int n, ifstream& puzfile);
    Square& sub(int j, int k);
    void static print();




};
inline ostream& operator<<(ostream& out,Board& b){
    Board::print();
}