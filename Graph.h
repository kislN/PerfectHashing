#ifndef PERFECTHASHING_GRAPH_H
#define PERFECTHASHING_GRAPH_H


UI tolerance = 100000000;
mt19937 gen(time(0));   // Mersenne twister
uniform_int_distribution<> uid(0, tolerance-1);

UI mod(int a, int b) {
    return (a % b + b) % b;
}

struct ADJ_VERTEX {
    UI vertex;
    UI weight;
};


class Graph {
private:
    UI graph_size;
    UI edges_num;
    vector<vector<ADJ_VERTEX>> adj_list;
    vector<UI> node_marks;  /// Vector with values of the function g()

public:
    Graph(size_t V, size_t E) {
        graph_size = V;
        edges_num = E;
        adj_list.resize(V, vector<ADJ_VERTEX>{});
        node_marks.resize(V, INF);

    }

    bool generate_rand(vector<pair<UI, UI>> nodes_pairs) {
        vector<bool> used(graph_size, false);
        for (UI i = 0; i < edges_num; ++i){
            UI node_1 = nodes_pairs[i].first;
            UI node_2 = nodes_pairs[i].second;
            if (((!used[node_1]) or (!used[node_2])) and (node_1 != node_2)) {
                adj_list[node_1].push_back(ADJ_VERTEX{node_2, i});
                adj_list[node_2].push_back(ADJ_VERTEX{node_1, i});
                used[node_1] = true;
                used[node_2] = true;
            }
            else {
                adj_list.clear();
                adj_list.resize(graph_size, vector<ADJ_VERTEX>{});
                return false;
            }
        }
        return true;

    }

    void update_marks() {
        vector<bool> used(graph_size, false);
        queue<UI> q;

        for (size_t i = 0; i < graph_size; i++) {

            if ((!adj_list[i].empty()) and (!used[i])) {
                node_marks[i] = 0;
                used[i] = true;
                q.push(i);
            }
            else {
                continue;
            }

            while (!q.empty()) {
                UI v1 = q.front();
                q.pop();
                for (size_t j = 0; j < adj_list[v1].size(); ++j) {
                    UI v2 = adj_list[v1][j].vertex;
                    UI weight = adj_list[v1][j].weight;
                    if (!used[v2]) {
                        node_marks[v2] = mod(int(weight - node_marks[v1]), edges_num);
                        used[v2] = true;
                        q.push(v2);
                    }
                }
            }
        }

    }

    vector<UI>& get_node_marks(){
        return node_marks;
    }

//    vector<vector<ADJ_VERTEX>> &get_adj_list() {
//        return adj_list;
//    }
//
//    vector<EDGE<T>> &get_edges_list() {
//        return edges_list;
//    }
//
    bool is_empty() {
        for (UI i = 0; i < graph_size; ++i) {
            if (!adj_list[i].empty())
                return 0;
        }
        return 1;
    }

    void print_adj_list() {
        if (this->is_empty())
            cout << "List is empty" << endl;
        else {
            for (UI i = 0; i < graph_size; ++i) {
                cout << "vert " << i << ": ";
                for (UI j = 0; j < adj_list[i].size(); ++j) {
                    cout << adj_list[i][j].vertex << " ";
                }
                cout << endl;
            }
        }
    }

    void print_adj_with_weights() {      // Print adjacency with the weights of edges in edges_list.
        if (this->is_empty())
            cout << "List is empty" << endl;
        else {
            for (UI i = 0; i < graph_size; ++i) {
                cout << "vert " << i << ": ";
                for (UI j = 0; j < adj_list[i].size(); ++j) {
                    cout << adj_list[i][j].vertex << "(" << adj_list[i][j].weight << ") ";
                }
                cout << endl;
            }
        }
    }
//
//    void print_edges_list() {
//        if (this->is_empty())
//            cout << "List is empty" << endl;
//        else {
//            for (UI i = 0; i < edges_num; ++i) {
//                cout << edges_list[i].vertex_a << " - " << edges_list[i].vertex_b << ": " <<
//                     edges_list[i].weight << " " << edges_list[i].weight_flag << endl;
//            }
//        }
//    }
};

#endif //PERFECTHASHING_GRAPH_H
