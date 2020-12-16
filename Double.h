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


template <class T>
class Double {
private:
    vector<T> data;
    size_t n;
    size_t m;
    vector<vector<UI>> table;
    hash_params h_params;
    vector<size_t> collision_indexes;
    vector<Quadratic<T>> quad;
    HashFunction<T> hash_fun;

public:
    explicit Double(vector<T> & data_, UI p = 101) {
        data = data_;
        n = data.size();
        m = n; /// ???
        table.resize(m);
        hash_fun = HashFunction<T>(0, m, p);
    }


    void do_hash(){
        for (size_t i = 0; i < n; i++) {
            int x = data[i];
            UI hash;
            hash_fun.hash_int(x, hash);

            if (!table[hash].empty()) {
                collision_indexes.push_back(hash);
            }
            table[hash].push_back(x);
        }

        for (UI coll : collision_indexes){
            Quadratic<T> q(table[coll]);
            q.create_table();
            quad.push_back(q);
        }

    }


};


#endif //PERFECTHASHING_DOUBLE_H
