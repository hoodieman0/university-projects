#include "tools.hpp"
#include "rsa.hpp"



int
fastMod(int a, int b, int n) {
    int result = 1;
    if (b & 1){ result = a; }
    while (b){
        b >>= 1;
        a = (a * a) % n;
        if (b & 1){
            result = (result * a) % n;
        }
    }
    return result;
}

#define BT int

// returns d, d = ax + by = GCD(a,b)
//TODO can be done iteratively
BT extendedEuclid(BT a, BT b, BT* x, BT* y){
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
BT* modLinear(BT a, BT b, BT n){
    BT d, x, y, z;
    BT* arr;

    d = extendedEuclid(a, n, &x, &y);

    if (b % d == 0){
        arr = new BT[d];
        z = (x * (b / d)) % n;
        if (z < 0){ z = z + n; }
        for (int i = 0; i < d; i++){
            cerr << (z + i * (n/d)) % n << endl;
            arr[i] = (z + i * (n/d)) % n;
        }
        return arr;
    }
    throw "Bad input";
}


bool millerTest(BT d, BT n){
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

bool isPrime(BT n, BT k){
    if (n <= 1 || n == 4) return false;
    if (n <= 3 ) return true;
    BT d = n - 1;
    while (d % 2 == 0){
        d /=2;
    }
    for (int i = 0; i < k; i++){
        if (!millerTest(d, n)) return false;
    }

    return true;
}

// 7 * 23, N = 187, M = 88

//argv[1] is filename
int main(int argc, char* argv[]) {
    if (argc != 2) { cout << "Wrong Number of Inputs!" << endl; exit(1); }

//    BT a = 14, b = 30, n = 100;
//    BT* res = modLinear(a, b, n);
//    for (int i = 0; i < *(&res + 1) - res; i++){
//        cerr << res[i] << endl;
//    }
//    cerr << "------------------------"<< endl;
//
//    BT x = fastMod(7, 560, 561);
//    cerr << x << endl;
//    cerr << "------------------------"<< endl;
//
//    try{
//        BT* result1 = modLinear(7, 1, 160);
//        for (int i = 0; i < *(&result1 + 1) - result1; i++){
//            cerr << result1[i] << endl;
//        }
//        cerr << "------------------------"<< endl;
//    }
//    catch (const char* e) { cerr << e << endl; }

//    for (int i = 1; i < 100; i++){
//        if (isPrime(i, 10)){
//            cerr << i << " ";
//        }
//    }
//    cerr << flush;


    char input;
    RSA alg;
    for(;;){
        cout << "\nWhat would you like to do with the file?" << endl;
        cout << "1. Encrypt = e\n2. Decrypt = d\n3. Regenerate Keys = r\n4. Get Public Key = p\n5. Quit = q\n>> ";
        cin >> input;
        switch (tolower(input)) {
            case 'e': alg.encryptFile(argv[1]); continue;
            case 'd': alg.decryptFile(argv[1]); continue;
            case 'r': alg.generateKeys(); cout<< "Regenerated Keys!" <<endl;
                        cout << alg.getPubKey(); continue;
            case 'p': cout << alg.getPubKey(); continue;
            default: cout << "Quitting..." << endl; return 0;
        }
    }
}

//make sure the primes are actually prime and the keys are relatively prime to totient
//dont forget to add the variable name in decryption for the fileName
//for bigger inputs, you need strings for numbers and arrays

//before you do anything redo this code, make it neat and commented