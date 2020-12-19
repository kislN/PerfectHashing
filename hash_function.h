

#ifndef PERFECTHASHING_HASH_FUNCTION_H
#define PERFECTHASHING_HASH_FUNCTION_H


template <class T>
class HashFunction {
private:
    vector<vector<UI>> rand_vectors;
    size_t m;
    size_t s;
    UI a;
    UI b;
    UI r_max;

public:
     HashFunction() = default;

     HashFunction(size_t m_, UI r_max_, size_t s_ = 4){
        m = m_;
        s = s_;
//        r_max = r_max_;
//        a = 1 + rand() % r_max;
//        b = 0 + rand() % r_max;
        a = uid_a(gen);
        b = uid_b(gen);
        generate_rand_vec(2);
    }

    void pair_hash(T & x, pair<UI, UI> & nodes_pair){
        UI f1 = 0;
        UI f2 = 0;
        hash_fun2(0, x, f1);
        hash_fun2(1, x, f2);
        nodes_pair = pair<UI, UI>(f1, f2);
    }

    void one_hash(int & x, UI & hash){
        hash = 0;
        hash_fun1(x, hash);
    }

    void one_hash(string & x, UI & hash){
        hash = 0;
        hash_fun2(0, x, hash);
    }

    void one_hash(vector<UI> & x, UI & hash){
        hash = 0;
        hash_fun2(0, x, hash);
    }

    void generate_rand_vec(size_t num_vecs){
        for (size_t i = 0; i < num_vecs; ++i) {
            vector<UI> rand_vec;
            for (size_t j = 0; j < s; ++j) {
//                rand_vec.push_back(1 + rand() % r_max);
                rand_vec.push_back(uid_a(gen));
            }
            rand_vectors.push_back(rand_vec);
        }
    }

    void hash_fun1(int & x, UI & hash){
        hash = ((a * x + b) % PRIME) % m;
    }

    void hash_fun2(size_t rand_vec_ind, int & x, UI & f_hash){
        f_hash = 0;
        for (size_t i = 0; i < rand_vectors[rand_vec_ind].size(); i++){
            f_hash += rand_vectors[rand_vec_ind][i] * pow(x, i);
        }
        f_hash = f_hash % m;
    }

    void hash_fun2(size_t rand_vec_ind, string & x, UI & f_hash){
        f_hash = 0;
        size_t x_len = x.size();
        for (size_t i = 0; i < x_len; i++){
            f_hash += rand_vectors[rand_vec_ind][i] * UI(x[i]);
        }
        f_hash = f_hash % m;
    }

    void hash_fun2(size_t rand_vec_ind, vector<UI> & x, UI & f_hash){
        f_hash = 0;
        size_t x_len = x.size();
        for (size_t i = 0; i < x_len; i++){
            f_hash += rand_vectors[rand_vec_ind][i] * x[i];
        }
        f_hash = f_hash % m;
    }

};



#endif //PERFECTHASHING_HASH_FUNCTION_H
