#ifndef PERFECTHASHING_GRAPHIC_H
#define PERFECTHASHING_GRAPHIC_H


template <class T>
class Graphic {
private:
    vector<T> data;
    size_t n;
    size_t m;
    vector<UI> node_marks;
    HashFunction<T> hash_fun;

public:
    explicit Graphic(vector<T> & data_, UI c = 3){
        data = data_;
        n = data.size();
        m = c * n;
    }

    void do_hash(size_t s = 4, UI r_max = 1000){
        Graph G(m, n);
        bool flag_loop = false;
        size_t count = 0;
        while (!flag_loop) {
            count++;
            hash_fun = HashFunction<T>(2, s, r_max);
            vector<pair<UI, UI>> nodes_pairs;
            for (size_t i = 0; i < n; i++) {
                pair<UI, UI> nodes_pair;
                hash_fun.nodes_hash(data[i], nodes_pair, m);
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
        hash_fun.nodes_hash(x, nodes, m);
        UI hash = (node_marks[nodes.first] + node_marks[nodes.second]) % n;
        return hash;
    }

};


#endif //PERFECTHASHING_GRAPHIC_H
