#ifndef PERFECTHASHING_GRAPHIC_H
#define PERFECTHASHING_GRAPHIC_H


template <class T>
class Graphic {
private:
    vector<T> data;
    size_t n;
    size_t m;
    vector<UI> rand_vec1;
    vector<UI> rand_vec2;
    vector<UI> node_marks;

public:
    explicit Graphic(vector<T> & data_, UI c = 3){
        data = data_;
        n = data.size();
        m = c * n;
    }

    void generate_rand_vectors(size_t s = 4, UI r_max = 10){
        rand_vec1.resize(0);
        rand_vec2.resize(0);
        for(size_t i = 0; i < s; i++){
            rand_vec1.push_back(1 + rand() % r_max);
            rand_vec2.push_back(1 + rand() % r_max);
        }
    }

    void hash_fun(int & x, pair<UI, UI> & nodes_pair){
        UI f1 = 0;
        UI f2 = 0;
        for (size_t i = 0; i < rand_vec1.size(); i++){
            f1 += rand_vec1[i] * pow(x, i);
            f2 += rand_vec2[i] * pow(x, i);
        }
        f1 = f1 % m;
        f2 = f2 % m;

        nodes_pair = pair<UI, UI>(f1, f2);
    }

    void hash_fun(string & x, pair<UI, UI> & nodes_pair){
        UI f1 = 0;
        UI f2 = 0;
        size_t x_len = x.size();
        for (size_t i = 0; i < x_len; i++){
            f1 += rand_vec1[i] * UI(x[i]);
            f2 += rand_vec2[i] * UI(x[i]);
        }
        f1 = f1 % m;
        f2 = f2 % m;

        nodes_pair = pair<UI, UI>(f1, f2);
    }

    void hash_fun(vector<UI> & x, pair<UI, UI> & nodes_pair){
        UI f1 = 0;
        UI f2 = 0;
        size_t x_len = x.size();
        for (size_t i = 0; i < x_len; i++){
            f1 += rand_vec1[i] * x[i];
            f2 += rand_vec2[i] * x[i];
        }
        f1 = f1 % m;
        f2 = f2 % m;

        nodes_pair = pair<UI, UI>(f1, f2);
    }

    void do_hash(size_t s = 4, UI r_max = 1000){
        Graph G(m, n);
        bool flag_loop = false;
        size_t count = 0;
        while (!flag_loop) {
            count++;
            generate_rand_vectors(s, r_max);
            vector<pair<UI, UI>> nodes_pairs;
            for (size_t i = 0; i < n; i++) {
                pair<UI, UI> nodes_pair;
                hash_fun(data[i], nodes_pair);
                nodes_pairs.push_back(nodes_pair);
            }
            flag_loop = G.generate_rand(nodes_pairs);
        }
//        G.print_adj_with_weights();
        cout << "COUNT = " << count << endl;
        G.update_marks();
        node_marks = G.get_node_marks();
    }

    UI search(T & x){
        pair<UI, UI> nodes;
        hash_fun(x, nodes);
        UI hash = (node_marks[nodes.first] + node_marks[nodes.second]) % n;
        return hash;
    }

};


#endif //PERFECTHASHING_GRAPHIC_H
