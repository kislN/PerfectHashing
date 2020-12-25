

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
    size_t bound;
    UI r_max, s;
    vector<vector<T>> table_;
    vector<size_t> collision_indexes;
    vector<Quadratic<T>> quad;
    HashFunction<T> hash_fun;
    vector<size_t> quad_indexes;

public:
    explicit Double(vector<T> & data_, UI c = 1, UI r_max_ = 1000, UI s_ = 4, size_t bound_coeff = 4) {
        data = data_;
        n = data.size();
        m = c * n;
        table_.resize(m);
        quad_indexes.resize(m);
        r_max = r_max_;
        s = s_;
        bound = n * bound_coeff;
    }


    void do_hash(){

        while (true)
        {
            vector<size_t> coll_count(m, 0);
            hash_fun = HashFunction<T>(m, r_max, s);
            for (size_t i = 0; i < n; i++) {
                T x = data[i];
                UI hash = 0;
                hash_fun.one_hash(x, hash);

                table_[hash].push_back(x);
                coll_count[hash]++;
            }

            size_t sum = 0;
            for (size_t i = 0; i < m; ++i) {
                sum += coll_count[i] * coll_count[i];
                if (coll_count[i] > 1) {
                    collision_indexes.push_back(i);
                }
            }

            if (sum >= bound){
                table_.clear();
                table_.resize(m);
                collision_indexes.clear();
                continue;
            }
            else {
                for (size_t i = 0; i < collision_indexes.size(); ++i) {
                    UI coll = collision_indexes[i];
                    Quadratic<T> q(table_[coll], 1, r_max, s);
                    quad_indexes[coll] = i;
                    q.do_hash();
                    quad.push_back(q);
                }
                break;
            }
        }

    }

    UI search(T & x){
        UI hash = 0;
        hash_fun.one_hash(x, hash);

        if (table_[hash].size() > 1){
            hash = quad[quad_indexes[hash]].search(x);
        }
        return hash;
    }

    void print_tables(){
        for (size_t i = 0; i < m; ++i){
            if (table_[i].size() < 2){
                cout << endl << i << ":" ;
                for (auto el : table_[i]){
                    cout << el << " ";
                }
            }
            else {
                if (table_[i].size() > 1) {
                    cout << endl << i << ": ";
                    quad[quad_indexes[i]].print_table();
                }

            }

        }
    }
};


#endif //PERFECTHASHING_DOUBLE_H
