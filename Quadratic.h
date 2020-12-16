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
        hash_fun = HashFunction<T>(0, m, p);
    }

    void do_hash(){
        for (size_t i = 0; i < n; i++) {
            int x = data[i];
            UI hash;
            hash_fun.hash_int(x, hash);

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
        UI hash;
        hash_fun.hash_int(x, hash);

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
