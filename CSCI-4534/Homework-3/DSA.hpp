#ifndef DSA_HPP
#define DSA_HPP

using namespace std;

struct Signature {
    int hash;
    int r;
    int s;
};

class DSA {
    private:
    int p, q, h, privateKey, k;
    int publicKey, g;

    public:
    DSA(int p, int q, int h, int privateKey, int k);
    Signature signHash(int hash);
    bool verifyHash(Signature sig);

    ~DSA()=default;
};

#endif