#include <iostream>
#include <random>
#include <vector>
#include <typeinfo>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

typedef unsigned int UI;
const int INF = numeric_limits<UI>::max() / 2;

#include "Quadratic.h"
#include "Double.h"
#include "Graph.h"
#include "Graphic.h"


int main() {
    vector<int> v;
    for (size_t i = 30; i > 0; --i){
        int r = 1 + rand() % 1000;
        if (find(v.begin(), v.end(), r) == v.end()) {
            v.push_back(r);
        }
    }
//    cout << v.size() << endl;
//    for (size_t i = 0; i < v.size(); ++i){
//        cout << v[i] << endl;
//    }


    Graphic g_hash(v, 3);
    g_hash.do_hash();
    for (size_t i = 0; i < v.size(); ++i) {
        cout << g_hash.search(v[i]) << endl;
    }


    return 0;
}