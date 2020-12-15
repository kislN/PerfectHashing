

#ifndef PERFECTHASHING_HASH_FUNCTION_H
#define PERFECTHASHING_HASH_FUNCTION_H

#include <random>

typedef unsigned int UI;

using namespace std;


UI hash_fun(int x, UI a, UI b, UI p, size_t m){
    return ((a * x + b) % p) % m;
}



#endif //PERFECTHASHING_HASH_FUNCTION_H
