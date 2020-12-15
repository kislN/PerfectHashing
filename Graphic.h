#ifndef PERFECTHASHING_GRAPHIC_H
#define PERFECTHASHING_GRAPHIC_H


class Graphic {
private:
    vector<int> data;
    size_t n;
    size_t m;
    vector<UI> rand_vec1;
    vector<UI> rand_vec2;
    bool flag_int;
    vector<UI> node_marks;

public:
    Graphic(vector<int> data_, UI c = 3, bool f_int=true){
        data = data_;
        n = data.size();
        m = c * n;
        if (f_int){
            flag_int = true;
        }
        else {
            flag_int = false;
        }
    }

    void generate_rand_vectors(UI r_max = 10){
        rand_vec1.resize(0);
        rand_vec2.resize(0);
        size_t s;
        if (flag_int){
            s = 4;
        }
        else {
            s = 50;
        }
        for(size_t i = 0; i < s; i++){
            rand_vec1.push_back(1 + rand() % r_max);
            rand_vec2.push_back(1 + rand() % r_max);
        }
    }

    pair<UI, UI> hash_number(int x){
        UI f1 = 0;
        UI f2 = 0;
        for (size_t i = 0; i < rand_vec1.size(); i++){
            f1 += rand_vec1[i] * pow(x, i);
            f2 += rand_vec2[i] * pow(x, i);
        }
        f1 = f1 % m;
        f2 = f2 % m;


        return pair<UI, UI>(f1, f2);
    }

//    pair<UI, UI> hash_word(string x){
//        UI f1 = 0;
//        UI f2 = 0;
//        size_t x_len = x.size();
//        for (size_t i = 0; i < x_len; i++){
//
//            f1 += rand_vec1[i] * int(x[i]);
//            f2 += rand_vec2[i] * int(x[i]);
//        }
//        f1 = f1 % m;
//        f2 = f2 % m;
//        return pair<UI, UI>(f1, f2);
//    }

    void do_hash(){
        Graph G(m, n);
        bool flag_loop = false;
        size_t count = 0;
        while (!flag_loop) {
            cout << "here" << count << endl;
            count++;
            generate_rand_vectors();
            vector<pair<UI, UI>> nodes_pairs;
            if (flag_int){
                for (size_t i = 0; i < n; i++) {
                    nodes_pairs.push_back(hash_number(data[i]));
//                    nodes_pairs.push_back(jenkins(data[i]));
                }
            }
            else {
                cout << "you are asshole" << endl;
            }
            flag_loop = G.generate_rand(nodes_pairs);
        }
//        G.print_adj_with_weights();
        G.update_marks();
        node_marks = G.get_node_marks();
    }

    UI search(int x){
        pair<UI, UI> nodes = hash_number(x);
//        pair<UI, UI> nodes = jenkins(x);
        UI hash = (node_marks[nodes.first] + node_marks[nodes.second]) % n;
        return hash;
    }

};


#endif //PERFECTHASHING_GRAPHIC_H
