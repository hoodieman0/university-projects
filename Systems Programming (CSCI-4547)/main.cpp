#include "params.hpp"

using namespace std;

int main(int argc, char* argv[]){
	Params p(argc, argv);
	p.print(cout);
}