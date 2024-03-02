//
// Created by hoodi on 10/25/2022.
//

#ifndef PUBKEY_HPP
#define PUBKEY_HPP

#include "tools.hpp"

class PubKey {
private:
    unsigned long key;
    unsigned long priKey;
    unsigned long number;

public:
    PubKey() = default;
    PubKey(unsigned long, unsigned long);
    ~PubKey() = default;

    unsigned long getKey() const { return key; }
    unsigned long getNumber() const { return number; }
};

inline ostream& operator<<(ostream& out, PubKey pub){
    out << "{key : " << pub.getKey() << ", N : " << pub.getNumber() << "}" <<endl;
    return out;
}

#endif //PUBKEY_HPP
