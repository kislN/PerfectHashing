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
    vector<vector<T>> table;
    vector<size_t> collision_indexes;
    vector<Quadratic<T>> quad;
    HashFunction<T> hash_fun;
    vector<size_t> quad_indexes;


public:
    explicit Double(vector<T> & data_, UI p = 101, UI c = 1) {
        data = data_;
        n = data.size();
        m = c * n;
        table.resize(m);
        quad_indexes.resize(m);
        hash_fun = HashFunction<T>(0, m, p);
    }


    void do_hash(){
        for (size_t i = 0; i < n; i++) {
            T x = data[i];
            UI hash = 0;
            hash_fun.one_hash(x, hash, m);
            vector<bool> used_coll(m, false);

            if ((!table[hash].empty()) and (!used_coll[hash])) {
                collision_indexes.push_back(hash);
                used_coll[hash] = true;
            }
            table[hash].push_back(x);
        }

        for (size_t i = 0; i < collision_indexes.size(); ++i){
            UI coll = collision_indexes[i];
            Quadratic<T> q(table[coll]);
            quad_indexes[coll] = i;
            q.do_hash();
            quad.push_back(q);
        }

//        for (UI coll : collision_indexes){
//            Quadratic<int> q(table[coll]);
//            q.do_hash();
//            quad.push_back(q);
//        }
    }

    UI search(T & x){
        UI hash = 0;
        hash_fun.one_hash(x, hash, m);

        if (table[hash].size() > 1){
            hash = quad[quad_indexes[hash]].search(x);
        }
        return hash;
    }

    void print_tables(){
        for (size_t i = 0; i < m; ++i){
            if (table[i].size() < 2){
                cout << endl << i << ":" ;
                for (auto el : table[i]){
                    cout << el << " ";
                }
            }
            else {
                if (table[i].size() > 1) {
                    cout << endl << i << ": ";
                    quad[quad_indexes[i]].print_table();
                }

            }

        }
    }
};


#endif //PERFECTHASHING_DOUBLE_H
