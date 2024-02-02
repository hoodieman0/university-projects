#include "SDES.hpp"

SDES::SDES(const unsigned int key, bool output, bool verbose) : output(output), verbose(verbose) {
    keyGen(key);
}