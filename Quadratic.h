//
// Created by Anastasiia Kislitsyna on 12/5/20.
//

#ifndef PERFECTHASHING_QUADRATIC_H
#define PERFECTHASHING_QUADRATIC_H

#include "iterator"
#include "iostream"
#include "hash_function.h"
#include <random>

#include <vector>

using namespace std;
typedef unsigned int UI;

struct element {
    int key;
    bool used;
};

struct hash_params {
    UI a;
    UI b;
    UI p;
    size_t M;
};


class Quadratic {
private:
    vector<int> data;
    size_t n;
    size_t m;
    vector<element> table;
    hash_params h_params;

public:
    Quadratic(vector<int> data_, UI p = 101) {
        data = data_;
        n = data.size();
        m = n * n;
        table.resize(m);

        UI a = 1 + rand() % p;
        UI b = 0 + rand() % p;
        h_params = hash_params{a, b, p, m};
    }


    void create_table(){

        for (size_t i = 0; i < n; i++) {
            int x = data[i];
            UI hash = hash_fun(x, h_params.a, h_params.b, h_params.p, h_params.M);

            UI primary_hash = hash;
            size_t count = 1;
            while (table[hash].used) {
                hash = primary_hash + count * count;
                count += count;
            }

            table[hash].key = x;
            table[hash].used = true;
        }

    }


    UI search_x(int x){
        UI hash = hash_fun(x, h_params.a, h_params.b, h_params.p, h_params.M);

        UI primary_hash = hash;
        size_t count = 1;
        while (table[hash].key != x) {
            hash = primary_hash + count * count;
            count += count;
        }
        return hash;
    }

    void print_table(){
        for (size_t i = 0; i < m; i++){
            cout << table[i].key << " - " << table[i].used << endl;
        }
    }

};


#endif //PERFECTHASHING_QUADRATIC_H
