
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
    vector<element<T>> table_;
    HashFunction<T> hash_fun;

public:
    explicit Quadratic(vector<T> & data_, UI c = 1, UI r_max = 1000, UI s = 4) {
        data = data_;
        n = data.size();
        m = c * n * n;
        table_.resize(m);
        hash_fun = HashFunction<T>(m, r_max, s);
    }

    void do_hash(){
        for (size_t i = 0; i < n; i++) {
            T x = data[i];
            UI hash = 0;
            hash_fun.one_hash(x, hash);

            UI primary_hash = hash;
            size_t count = 1;
            while (table_[hash].used) {
                hash = (primary_hash + count * count) % m;
                count++;
            }
            table_[hash].key = x;
            table_[hash].used = true;
        }

    }

    UI search(T & x){
        UI hash = 0;
        hash_fun.one_hash(x, hash);

        UI primary_hash = hash;
        size_t count = 1;
        while (table_[hash].key != x) {
            hash = (primary_hash + count * count) % m;
            count++;
        }
        return hash;
    }

    void print_table(){
        for (size_t i = 0; i < m; i++){
            cout << endl << i << " - ";
            cout << table_[i].key << " ";
        }
    }

};


#endif //PERFECTHASHING_QUADRATIC_H
