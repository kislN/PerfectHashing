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


/// TODO: all links, hash for words and vectors in Quadratic and Double, hash with bytes shift, measures, mersene twister

int main() {
//    srand (time(NULL));
    srand(1760);

    vector<vector<UI>> vecs;

    for (size_t i = 0; i < 10000; ++i){
        UI size = 1 + rand() % 40;
        vector<UI> v;
        for (size_t j = 0; j < size; ++j){
            v.push_back(1 + rand() % 1000);
        }
        vecs.push_back(v);
    }
//
//    Graphic<vector<UI>> g_vecs(vecs, 3);
//    g_vecs.do_hash(50, 100);
//    for (size_t i = 0; i < vecs.size(); ++i) {
//        cout << g_vecs.search(vecs[i]) << endl;
//    }

//    Quadratic<vector<UI>> q_vecs(vecs, 101, 50);
//    q_vecs.do_hash();
//    for (size_t i = 0; i < vecs.size(); ++i) {
//        cout << q_vecs.search(vecs[i]) << endl;
//    }

//    Double<vector<UI>> d_vecs(vecs, 1, 101, 1000, 50);
//    d_vecs.do_hash();
////    d_vecs.print_tables();
//    for (size_t i = 0; i < vecs.size(); ++i) {
//        cout << d_vecs.search(vecs[i]) << endl;
//    }
//
//    return 0;

    vector<string> words{"hellj", "dlfgj", "jrlkjbhlr", "dfkj", "dgf", "dfgdfg", "kjlj", "jghsd", "sjkghk", "ksjhdg"};

//    Graphic<string> g_word(words);
//    g_word.do_hash(50, 1000);
//    for (size_t i = 0; i < words.size(); ++i) {
//        cout << g_word.search(words[i]) << endl;
//    }


//    Quadratic<string> q_words(words, 101, 50);
//    q_words.do_hash();
//    for (size_t i = 0; i < words.size(); ++i) {
//        cout << q_words.search(words[i]) << endl;
//    }
//

    Double<string> d_words(words, 1, 101, 1000, 50);
    d_words.do_hash();
//    d_vecs.print_tables();
    for (size_t i = 0; i < words.size(); ++i) {
        cout << d_words.search(words[i]) << endl;
    }
    return 0;

    vector<int> v;
    for (size_t i = 1000; i > 0; --i){
        int r = 1 + rand() % 1000000;
        if (find(v.begin(), v.end(), r) == v.end()) {
            v.push_back(r);
        }
    }


//    Graphic<int> g_hash(v, 2);
//    g_hash.do_hash(3, 100);
//    for (size_t i = 0; i < v.size(); ++i) {
//        cout << g_hash.search(v[i]) << endl;
//    }
//
//    cout << endl << "Quadr" << endl;

//    Quadratic<int> q_hash(v);
//    q_hash.do_hash();
//    for (size_t i = 0; i < v.size(); ++i) {
//        cout << q_hash.search(v[i]) << endl;
//    }

//    Double<int> d_hash(v, 1, 101, 1000, 4);
//    d_hash.do_hash();
////    d_hash.print_tables();
//    for (size_t i = 0; i < v.size(); ++i) {
//        cout << d_hash.search(v[i]) << endl;
//    }
    return 0;
}