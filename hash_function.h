

#ifndef PERFECTHASHING_HASH_FUNCTION_H
#define PERFECTHASHING_HASH_FUNCTION_H

#include <random>

typedef unsigned int UI;
using namespace std;


//UI hash_fun(int & x, UI a, UI b, UI p, size_t M){
//    return ((a * x + b) % p) % M;
//}

struct hash_params {
    UI a;
    UI b;
    UI p;
    size_t M;
};

template <class T>
class HashFunction {
private:
    vector<vector<UI>> rand_vectors;
    hash_params h_params;

public:
    HashFunction(size_t vec_num = 1, size_t size_num = 4, UI max_rand = 101){
        if (vec_num > 0) {
            rand_vectors.resize(vec_num, vector<UI>());

            for (size_t i = 0; i < vec_num; ++i) {
                generate_rand_vec(rand_vectors[i], size_num, max_rand);
            }
        }
        else {
            UI a = 1 + rand() % max_rand;
            UI b = 0 + rand() % max_rand;
            h_params = hash_params{a, b, max_rand, size_num};
        }
    }

    void hash_int(int & x, UI & hash){
        hash = ((h_params.a * x + h_params.b) % h_params.p) % h_params.M;
    }

    void generate_rand_vec(vector<UI> & rand_vec, size_t s = 4, UI r_max = 10){
        rand_vec.resize(0);
        for(size_t i = 0; i < s; i++){
            rand_vec.push_back(1 + rand() % r_max);
        }
    }

    void hash_fun(vector<UI> & rand_vec, int & x, size_t & m, UI & f_hash){
        f_hash = 0;
        for (size_t i = 0; i < rand_vec.size(); i++){
            f_hash += rand_vec[i] * pow(x, i);
        }
        f_hash = f_hash % m;
    }

    void hash_fun(vector<UI> & rand_vec, string & x, size_t & m, UI & f_hash){
        f_hash = 0;
        size_t x_len = x.size();
        for (size_t i = 0; i < x_len; i++){
            f_hash += rand_vec[i] * UI(x[i]);
        }
        f_hash = f_hash % m;
    }

    void hash_fun(vector<UI> & rand_vec, vector<UI> & x, size_t & m, UI & f_hash){
        f_hash = 0;
        size_t x_len = x.size();
        for (size_t i = 0; i < x_len; i++){
            f_hash += rand_vec[i] * x[i];
        }
        f_hash = f_hash % m;
    }

    void nodes_hash(T & x, pair<UI, UI> & nodes_pair, size_t & m){
        UI f1 = 0;
        UI f2 = 0;
        hash_fun(rand_vectors[0], x, m, f1);
        hash_fun(rand_vectors[1], x, m, f2);
        nodes_pair = pair<UI, UI>(f1, f2);
    }

};



#endif //PERFECTHASHING_HASH_FUNCTION_H
