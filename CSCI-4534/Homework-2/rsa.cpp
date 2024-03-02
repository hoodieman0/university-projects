//
// Created by hoodi on 10/25/2022.
//

#include "rsa.hpp"

RSA::
RSA() {
    generateKeys();
}

BT RSA::
GCD(BT a, BT b) {
    BT r;
    while ( (a % b) > 0){
        r = a % b;
        a = b;
        b = r;
    }
    return b;
}

bool RSA::isRelativePrime(BT p, BT q) {
    if (GCD(p, q) == 1) return true;
    return false;
}

BT RSA::
fastMod(BT a, BT b, BT n) {
    BT result = 1;
    if (b & 1){ result = a; }
    while (b){
        b >>= 1;
        a = (a * a) % n;
        if (b & 1){
            result = (result * a) % n;
        }
    }
//    if (result < 0) { result = result + n; }
    return result;
}

bool RSA::
millerTest(BT d, BT n){
    srand(time(NULL));
    int a = 2 + rand() % (n-4);
    int x = fastMod(a, d, n);
    if (x == 1 || x == n-1) { return true; }

    while (d != n-1){
        x = (x * x) % n;
        d *= 2;
        if (x == 1) return false;
        if (x == n-1) return true;
    }
    return false;
}

//TODO please check this GoG code over and cross reference book
bool RSA::
isPrime(BT p, int k) {
    if (p <= 1 || p == 4) return false;
    if (p <= 3 ) return true;
    BT d = p - 1;
    while (d % 2 == 0){
        d /=2;
    }
    for (int i = 0; i < k; i++){
        if (!millerTest(d, p)) return false;
    }

    return true;
}

// returns d, d = ax + by = GCD(a,b)
//TODO can be done iteratively
BT RSA::
extendedEuclid(BT a, BT b, BT* x, BT* y){
    if (b == 0){
        *x = 1;
        *y = 0;
        return a;
    }
    else{
        BT result = extendedEuclid(b, a % b, x, y);
        BT temp = *x;
        *x = *y;
        *y = temp - (a / b) * (*y);
        return result;
    }
}

//finds all possible solutions for x in ax = b (mod n)
// for RSA key generation, b = 1 must be true
BT RSA::
modLinear(BT a, BT b, BT n){
    BT d, x, y, z;

    d = extendedEuclid(a, n, &x, &y);

    if (b % d == 0){
        z = (x * (b / d)) % n;
        if (z < 0){ z = z + n; }
        return z;
    }
    throw "Modular Linear Equation Solver has a bad value";
}

void RSA::
generateKeys() {
    random_device r;
    default_random_engine e1(r());
    uniform_int_distribution<BT> dist(10, 1000);

    do{
        primeP = dist(e1);//primes(gen);
    } while (!isPrime(primeP, 10)); //TODO make this a DEFINE

    do{
        primeQ = dist(e1);//primes(gen);
    } while (!isPrime(primeQ, 10));

    number = primeP * primeQ;

    BT totient = eulerTotient(primeP, primeQ);
    uniform_int_distribution<BT> keys(2, totient - 1);


    random_device r2;
    default_random_engine e2(r2());
    uniform_int_distribution<BT> dist2(2, totient - 1);

    while (pubKey == 0 || priKey == 0){
        do {
            pubKey = dist2(e2);//keys(gen);
        } while (!isRelativePrime(pubKey, totient));

        priKey = modLinear(pubKey, 1, totient);

//        for (int k = 2; k < totient; k++){
//            if ((k*totient + 1) % pubKey == 0){
//                int x = k * totient;
//                int y = x + 1;
//                cerr << pubKey << endl;
//                int z = y / pubKey;
//                int a = 100000 % pubKey;
//                int temp = z;
//                cerr << temp << endl;
//                priKey = (k*totient + 1) / pubKey;
//                break;
//            }
//        }
    }
    //TODO remove this
    cerr << "P = " << primeP << " | Q = " << primeQ << " | Number = " << number << endl;
    cerr << "Public : " << pubKey << " | Private : " << priKey << " | T : " << totient<< endl;
}

void RSA::encryptFile(const string& fileName) const {
    ifstream ifs(fileName);
    ofstream oFile("modifiedText.txt");
    string temp;
    while (!ifs.eof()){
        ifs >> temp;
        for (char c : temp){
            oFile << fastMod(c, pubKey, number);
            oFile << '\n';
        }
    }
    cout << "File Successfully Encrypted!" <<endl;

    oFile.close();
    ifs.close();
}

void RSA::decryptFile(const string& fileName) const {
    ifstream ifs("modifiedText.txt");
    ofstream oFile("modifiedText(2).txt");
    string temp;

    BT thing;
    BT thing2;

    while (!ifs.eof()){
        ifs >> temp;
        thing = stoi(temp); //TODO THIS IS WRONG

        thing2 = fastMod(thing, priKey, number);
        oFile << (char) thing2;
        cerr << temp << endl;
        cerr << thing << endl;
        cerr << thing2 << endl;
        cerr << (char) thing2 << "\n" <<endl;

        oFile << '\n';
    }
    cout << "File Successfully Decrypted!" <<endl;

    oFile.close();
    ifs.close();
}

PubKey RSA::getPubKey() const {
    PubKey temp(pubKey, number);
    return temp;
}