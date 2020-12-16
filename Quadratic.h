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


template <typename T>
struct element {
    T key;
    bool used;
};

template <class T>
class Quadratic {
private:
    vector<T> data;
    size_t n;
    size_t m;
    vector<element<T>> table;
    HashFunction<T> hash_fun;

public:
    explicit Quadratic(vector<T> & data_, UI p = 101) {
        data = data_;
        n = data.size();
        m = n * n;
        table.resize(m);
        hash_fun = HashFunction<T>(1, m, p);
    }

    void do_hash(){
        for (size_t i = 0; i < n; i++) {
            int x = data[i];
            UI hash = 0;
            hash_fun.one_hash(x, hash, m);

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

    UI search(T & x){
        UI hash = 0;
        hash_fun.one_hash(x, hash, m);

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
            cout << endl << i << " - ";
            cout << table[i].key << " ";
        }
    }

};


#endif //PERFECTHASHING_QUADRATIC_H
