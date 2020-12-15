#include <iostream>
#include <random>
#include <vector>
#include <typeinfo>
#include <string>
#include <cmath>
#include <queue>
#include <time.h>



using namespace std;

typedef unsigned int UI;
const int INF = numeric_limits<UI>::max() / 2;

#include "Quadratic.h"
#include "Double.h"
#include "Graph.h"
#include "Graphic.h"




int main() {
    srand (time(NULL));

    vector<int> v;
    for (size_t i = 10000; i > 0; --i){
        int r = 1 + rand() % 100000;
        if (find(v.begin(), v.end(), r) == v.end()) {
            v.push_back(r);
        }
    }
//    for (size_t i = 0; i < v.size(); ++i){
//        cout << v[i] << endl;
//    }


    Graphic g_hash(v, 2);
    g_hash.do_hash();
//    for (size_t i = 0; i < v.size(); ++i) {
//        cout << g_hash.search(v[i]) << endl;
//    }
//    cout << g_hash.search(6) << endl;


    return 0;
}