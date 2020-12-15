//
// Created by Anastasiia Kislitsyna on 12/6/20.
//

#ifndef PERFECTHASHING_DOUBLE_H
#define PERFECTHASHING_DOUBLE_H

#include "iterator"
#include "iostream"
#include "hash_function.h"
#include <random>
#include "Quadratic.h"

#include <vector>

using namespace std;
typedef unsigned int UI;


class Double {
private:
    vector<int> data;
    size_t n;
    size_t m;
    vector<vector<int>> table;
    hash_params h_params;
    vector<size_t> collision_indexes;
    vector<Quadratic> quad;

public:
    Double(vector<int> data_, UI p = 101) {
        data = data_;
        n = data.size();
        m = n; /// ???
        table.resize(m);
        UI a = 1 + rand() % p;
        UI b = 0 + rand() % p;
        h_params = hash_params{a, b, p, m};
    }


    void create_table(){

        for (size_t i = 0; i < n; i++) {
            int x = data[i];
            UI hash = hash_fun(x, h_params.a, h_params.b, h_params.p, h_params.M);

            if (!table[hash].empty()) {
                collision_indexes.push_back(hash);
            }
            table[hash].push_back(x);
        }

        for (UI coll : collision_indexes){
            Quadratic q(table[coll]);
            q.create_table();
            quad.push_back(q);
        }

    }

};


#endif //PERFECTHASHING_DOUBLE_H
