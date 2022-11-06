#include "tools.hpp"
#include "Game-KorideMok.hpp"
#include "Exceptions-KorideMok.hpp"

// argv[1] is the file name used in Board class
int main(int argc, char* const argv[]){
    banner();
    try {
        if(argc != 2) throw IncorrectUsageException();

        ifstream ifs(argv[1]);
        if (!ifs.is_open()) throw BadOpenException();

        cout <<"~Starting Game~" <<endl;
        Game obj(ifs);
        obj.run();
        cout <<"~Quitting Game~" <<endl;
    }
    catch(StreamException& e) {
        cerr <<e <<endl;
        fatal("");
    }
    catch (GameException& e){
        cerr <<e <<endl;
        fatal("");
    }
    catch(...){
        fatal("General Exception");
    }

    bye();
}