#ifndef PERFECTHASHING_EXPERIMENTS_H
#define PERFECTHASHING_EXPERIMENTS_H

#include<unistd.h>
unsigned int microsecond = 1000000;

bool quad_num(string file_name, size_t c, size_t average = 3) {

    ofstream file(file_name);
    if (!file.is_open()) {
        return 0;
    }
    cout << "File is open " << endl;
    file << "DataType,DataN,C,BuildTime,SearchTime,Memory" << endl;

    vector<size_t> data_n{100, 500, 1000, 1500, 2500, 4000};

    for (auto n : data_n) {
        cout << "Quadratic, numbers, n = " << n << ", c = " << c << endl;
        auto build_time = steady_clock::duration::zero();
        auto search_time = steady_clock::duration::zero();
        long long total_memory = 0;
        for (size_t i = 0; i < average; ++i) {
            long long memory = getMemoryUsage();
            vector<int> numbers;
            while (numbers.size() < n) {
                int r = 1 + rand() % 100000;
                if (find(numbers.begin(), numbers.end(), r) == numbers.end()) {
                    numbers.push_back(r);
                }
            }
            Quadratic<int> q_nums(numbers, c, 10000, 4);

            auto start_time = high_resolution_clock::now();
            q_nums.do_hash();
            build_time += (high_resolution_clock::now() - start_time);
            total_memory += (getMemoryUsage() - memory) / 1024;

            start_time = high_resolution_clock::now();
            for (int &number : numbers) {
                q_nums.search(number);
            }
            search_time += (high_resolution_clock::now() - start_time) / n;
        }
        build_time = build_time / average;
        search_time = search_time / average;
        total_memory = total_memory / average;

        build_time = duration_cast<microseconds>(build_time);
        search_time = duration_cast<microseconds>(search_time);

        file << "Numbers" << "," << n << "," << c << "," << build_time.count() / 1000000. << ","
             << search_time.count() / 1000000. << "," << total_memory << endl;
    }

    file.close();
    return 1;
}


bool quad_word(string file_name, size_t c, size_t average = 3) {

    ofstream file(file_name);
    if (!file.is_open()) {
        return 0;
    }
    cout << "File is open " << endl;
    file << "DataType,DataN,C,BuildTime,SearchTime,Memory" << endl;

    vector<size_t> data_n{100, 500, 1000, 1500, 2500, 4000};

    for (auto n : data_n) {
        cout << "Quadratic, words, n = " << n << endl;
        auto build_time = steady_clock::duration::zero();
        auto search_time = steady_clock::duration::zero();
        long long total_memory = 0;

        for (size_t i = 0; i < average; ++i) {
            long long memory = getMemoryUsage();
            vector<string> words;
            gen_words(words, n);
            Quadratic<string> q_words(words, c, 10000, 50);

            auto start_time = high_resolution_clock::now();
            q_words.do_hash();
            build_time += (high_resolution_clock::now() - start_time);
            total_memory += (getMemoryUsage() - memory) / 1024;

            start_time = high_resolution_clock::now();
            for (string &word : words) {
                q_words.search(word);
            }
            search_time += (high_resolution_clock::now() - start_time) / n;
        }
        build_time = build_time / average;
        search_time = search_time / average;
        total_memory = total_memory / average;

        build_time = duration_cast<microseconds>(build_time);
        search_time = duration_cast<microseconds>(search_time);
        file << "Words" << "," << n << "," << c << "," << build_time.count() / 1000000. << ","
             << search_time.count() / 1000000. << "," << total_memory << endl;
    }

    file.close();
    return 1;

}


bool quad_vec(string file_name, size_t c, size_t average = 3) {

    ofstream file(file_name);
    if (!file.is_open()) {
        return 0;
    }
    cout << "File is open " << endl;
    file << "DataType,DataN,C,BuildTime,SearchTime,Memory" << endl;

    vector<size_t> data_n{100, 500, 1000, 1500, 2500, 4000};

    for (auto n : data_n){
        cout << "Quadratic, vectors, n = " << n << endl;
        auto build_time = steady_clock::duration::zero();
        auto search_time = steady_clock::duration::zero();
        long long total_memory = 0;

        for (size_t i = 0; i < average; ++i) {
            long long memory = getMemoryUsage();
            vector<vector<UI>> vectors;
            while (vectors.size() < n){
                UI size = 1 + rand() % 40;
                vector<UI> v;
                for (size_t j = 0; j < size; ++j){
                    v.push_back(1 + rand() % 1000);
                }
                vectors.push_back(v);
            }
            Quadratic<vector<UI>> q_vecs(vectors, c, 10000, 50);

            auto start_time = high_resolution_clock::now();
            q_vecs.do_hash();
            build_time += (high_resolution_clock::now() - start_time);
            total_memory += (getMemoryUsage() - memory) / 1024;

            start_time = high_resolution_clock::now();
            for (vector<UI> & vector : vectors) {
                q_vecs.search(vector);
            }
            search_time += (high_resolution_clock::now() - start_time) / n;
        }
        build_time = build_time / average;
        search_time = search_time / average;
        total_memory = total_memory / average;

        build_time = duration_cast<microseconds>(build_time);
        search_time = duration_cast<microseconds>(search_time);
        file << "Vectors" << "," << n << "," << c << "," << build_time.count() / 1000000. << ","
        << search_time.count() / 1000000. << "," << total_memory << endl;
    }

    file.close();
    return 1;

}



bool double_num(string file_name, size_t c, size_t average = 3){

    ofstream file(file_name);
    if (!file.is_open()) {
        return 0;
    }
    cout << "File is open " << endl;
    file << "DataType,DataN,C,BuildTime,SearchTime,Memory" << endl;

    vector<size_t> data_n{100, 500, 1000, 1500, 2500, 4000};

    for (auto n : data_n){
        cout << "Double, numbers, n = " << n << endl;
        auto build_time = steady_clock::duration::zero();
        auto search_time = steady_clock::duration::zero();
        long long total_memory = 0;

        for (size_t i = 0; i < average; ++i) {
            long long memory = getMemoryUsage();
            vector<int> numbers;
            while (numbers.size() < n) {
                int r = 1 + rand() % 100000;
                if (find(numbers.begin(), numbers.end(), r) == numbers.end()) {
                    numbers.push_back(r);
                }
            }
            Double<int> d_nums(numbers, c, 10000, 4);

            auto start_time = high_resolution_clock::now();
            d_nums.do_hash();
            build_time += (high_resolution_clock::now() - start_time);
            total_memory += (getMemoryUsage() - memory) / 1024;

            start_time = high_resolution_clock::now();
            for (int & number : numbers) {
                d_nums.search(number);
            }
            search_time += (high_resolution_clock::now() - start_time) / n;
        }
        build_time = build_time / average;
        search_time = search_time / average;
        total_memory = total_memory / average;

        build_time = duration_cast<microseconds>(build_time);
        search_time = duration_cast<microseconds>(search_time);

        file << "Numbers" << "," << n << "," << c << "," << build_time.count() / 1000000. << ","
             << search_time.count() / 1000000. << "," << total_memory << endl;
    }

    file.close();
    return 1;
}


bool double_word(string file_name, size_t c, size_t average = 3){

    ofstream file(file_name);
    if (!file.is_open()) {
        return 0;
    }
    cout << "File is open " << endl;
    file << "DataType,DataN,C,BuildTime,SearchTime,Memory" << endl;

    vector<size_t> data_n{100, 500, 1000, 1500, 2500, 4000};

    for (auto n : data_n){
        cout << "Double, words, n = " << n << endl;
        auto build_time = steady_clock::duration::zero();
        auto search_time = steady_clock::duration::zero();
        long long total_memory = 0;

        for (size_t i = 0; i < average; ++i) {
            long long memory = getMemoryUsage();
            vector<string> words;
            gen_words(words, n);
            Double<string> d_words(words, c, 10000, 50);

            auto start_time = high_resolution_clock::now();
            d_words.do_hash();
            build_time += (high_resolution_clock::now() - start_time);
            total_memory += (getMemoryUsage() - memory) / 1024;

            start_time = high_resolution_clock::now();
            for (string & word : words) {
                d_words.search(word);
            }
            search_time += (high_resolution_clock::now() - start_time) / n;
        }
        build_time = build_time / average;
        search_time = search_time / average;
        total_memory = total_memory / average;

        build_time = duration_cast<microseconds>(build_time);
        search_time = duration_cast<microseconds>(search_time);
        file << "Words" << "," << n << "," << c << "," << build_time.count() / 1000000. << ","
             << search_time.count() / 1000000. << "," << total_memory << endl;
    }
    file.close();
    return 1;
}


bool double_vec(string file_name, size_t c, size_t average = 3){

    ofstream file(file_name);
    if (!file.is_open()) {
        return 0;
    }
    cout << "File is open " << endl;
    file << "DataType,DataN,C,BuildTime,SearchTime,Memory" << endl;

    vector<size_t> data_n{100, 500, 1000, 1500, 2500, 4000};

    for (auto n : data_n){
        cout << "Double, vectors, n = " << n << endl;
        auto build_time = steady_clock::duration::zero();
        auto search_time = steady_clock::duration::zero();
        long long total_memory = 0;

        for (size_t i = 0; i < average; ++i) {
            long long memory = getMemoryUsage();
            vector<vector<UI>> vectors;
            while (vectors.size() < n){
                UI size = 1 + rand() % 40;
                vector<UI> v;
                for (size_t j = 0; j < size; ++j){
                    v.push_back(1 + rand() % 1000);
                }
                vectors.push_back(v);
            }
            Double<vector<UI>> d_vecs(vectors, c, 10000, 50);

            auto start_time = high_resolution_clock::now();
            d_vecs.do_hash();
            build_time += (high_resolution_clock::now() - start_time);
            total_memory += (getMemoryUsage() - memory) / 1024;

            start_time = high_resolution_clock::now();
            for (vector<UI> & vector : vectors) {
                d_vecs.search(vector);
            }
            search_time += (high_resolution_clock::now() - start_time) / n;
        }
        build_time = build_time / average;
        search_time = search_time / average;
        total_memory = total_memory / average;

        build_time = duration_cast<microseconds>(build_time);
        search_time = duration_cast<microseconds>(search_time);
        file << "Vectors" << "," << n << "," << c << "," << build_time.count() / 1000000. << ","
             << search_time.count() / 1000000. << "," << total_memory << endl;
    }

    file.close();
    return 1;
}





bool graph_num(string file_name, size_t c, size_t average = 3){

    ofstream file(file_name);
    if (!file.is_open()) {
        return 0;
    }
    cout << "File is open " << endl;
    file << "DataType,DataN,C,BuildTime,SearchTime,Memory" << endl;

    vector<size_t> data_n{100, 500, 1000, 1500, 2500, 4000};

    for (auto n : data_n){
        cout << "Quadratic, numbers, n = " << n << endl;
        auto build_time = steady_clock::duration::zero();
        auto search_time = steady_clock::duration::zero();
        long long total_memory = 0;

        for (size_t i = 0; i < average; ++i) {
            long long memory = getMemoryUsage();
            vector<int> numbers;
            while (numbers.size() < n) {
                int r = 1 + rand() % 100000;
                if (find(numbers.begin(), numbers.end(), r) == numbers.end()) {
                    numbers.push_back(r);
                }
            }
            Graphic<int> g_nums(numbers, c);

            auto start_time = high_resolution_clock::now();
            g_nums.do_hash(3, 1000);
            build_time += (high_resolution_clock::now() - start_time);
            total_memory += (getMemoryUsage() - memory) / 1024;

            start_time = high_resolution_clock::now();
            for (int & number : numbers) {
                g_nums.search(number);
            }
            search_time += (high_resolution_clock::now() - start_time) / n;
        }
        build_time = build_time / average;
        search_time = search_time / average;
        total_memory = total_memory / average;

        build_time = duration_cast<microseconds>(build_time);
        search_time = duration_cast<microseconds>(search_time);

        file << "Numbers" << "," << n << "," << c << "," << build_time.count() / 1000000. << ","
             << search_time.count() / 1000000. << "," << total_memory << endl;
    }
    file.close();
    return 1;
}

bool graph_word(string file_name, size_t c, size_t average = 3){

    ofstream file(file_name);
    if (!file.is_open()) {
        return 0;
    }
    cout << "File is open " << endl;
    file << "DataType,DataN,C,BuildTime,SearchTime,Memory" << endl;

    vector<size_t> data_n{100, 500, 1000, 1500, 2500, 4000};

    for (auto n : data_n){
        cout << "Quadratic, words, n = " << n << endl;
        auto build_time = steady_clock::duration::zero();
        auto search_time = steady_clock::duration::zero();
        long long total_memory = 0;

        for (size_t i = 0; i < average; ++i) {
            long long memory = getMemoryUsage();
            vector<string> words;
            gen_words(words, n);
            Graphic<string> g_words(words, c);

            auto start_time = high_resolution_clock::now();
            g_words.do_hash(50, 10000);
            build_time += (high_resolution_clock::now() - start_time);
            total_memory += (getMemoryUsage() - memory) / 1024;

            start_time = high_resolution_clock::now();
            for (string & word : words) {
                g_words.search(word);
            }
            search_time += (high_resolution_clock::now() - start_time) / n;
        }
        build_time = build_time / average;
        search_time = search_time / average;
        total_memory = total_memory / average;

        build_time = duration_cast<microseconds>(build_time);
        search_time = duration_cast<microseconds>(search_time);
        file << "Words" << "," << n << "," << c << "," << build_time.count() / 1000000. << ","
             << search_time.count() / 1000000. << "," << total_memory << endl;
    }

    file.close();
    return 1;
}


bool graph_vec(string file_name, size_t c, size_t average = 3){

    ofstream file(file_name);
    if (!file.is_open()) {
        return 0;
    }
    cout << "File is open " << endl;
    file << "DataType,DataN,C,BuildTime,SearchTime,Memory" << endl;

    vector<size_t> data_n{100, 500, 1000, 1500, 2500, 4000};

    for (auto n : data_n){
        cout << "Quadratic, vectors, n = " << n << endl;
        auto build_time = steady_clock::duration::zero();
        auto search_time = steady_clock::duration::zero();
        long long total_memory = 0;

        for (size_t i = 0; i < average; ++i) {
            long long memory = getMemoryUsage();
            vector<vector<UI>> vectors;
            while (vectors.size() < n){
                UI size = 1 + rand() % 40;
                vector<UI> v;
                for (size_t j = 0; j < size; ++j){
                    v.push_back(1 + rand() % 1000);
                }
                vectors.push_back(v);
            }
            Graphic<vector<UI>> g_vecs(vectors, c);

            auto start_time = high_resolution_clock::now();
            g_vecs.do_hash(50, 10000);
            build_time += (high_resolution_clock::now() - start_time);
            total_memory += (getMemoryUsage() - memory) / 1024;

            start_time = high_resolution_clock::now();
            for (vector<UI> & vector : vectors) {
                g_vecs.search(vector);
            }
            search_time += (high_resolution_clock::now() - start_time) / n;
        }
        build_time = build_time / average;
        search_time = search_time / average;
        total_memory = total_memory / average;

        build_time = duration_cast<microseconds>(build_time);
        search_time = duration_cast<microseconds>(search_time);
        file << "Vectors" << "," << n << "," << c << "," << build_time.count() / 1000000. << ","
             << search_time.count() / 1000000. << "," << total_memory << endl;
    }

    file.close();
    return 1;
}


void all_experiments() {

//    quad_num("../data/quad_num_1.csv", 1, 1);
//    quad_num("../data/quad_num_2.csv", 2, 1);
//    quad_num("../data/quad_num_3.csv", 3, 1);
//    quad_num("../data/quad_num_4.csv", 4, 1);

//    quad_word("../data/quad_word_1.csv", 1, 1);
//    quad_word("../data/quad_word_2.csv", 2, 1);
//    quad_word("../data/quad_word_3.csv", 3, 1);
//    quad_word("../data/quad_word_4.csv", 4, 1);

//    quad_vec("../data/quad_vec_1.csv", 1, 1);
//    quad_vec("../data/quad_vec_2.csv", 2, 1);
//    quad_vec("../data/quad_vec_3.csv", 3, 1);
//    quad_vec("../data/quad_vec_4.csv", 4, 1);


//    double_num("../data/double_num_1.csv", 1, 1);
//    double_num("../data/double_num_2.csv", 2, 1);
//    double_num("../data/double_num_3.csv", 3, 1);
//    double_num("../data/double_num_4.csv", 4, 1);

//    double_word("../data/double_word_1.csv", 1, 1);
//    double_word("../data/double_word_2.csv", 2, 1);
//    double_word("../data/double_word_3.csv", 3, 1);
//    double_word("../data/double_word_4.csv", 4, 1);

//    double_vec("../data/double_vec_1.csv", 1, 1);
//    double_vec("../data/double_vec_2.csv", 2, 1);
//    double_vec("../data/double_vec_3.csv", 3, 1);
//    double_vec("../data/double_vec_4.csv", 4, 1);


//    graph_num("../data/graph_num_2.csv", 2, 1);
//    graph_num("../data/graph_num_3.csv", 3, 1);
//    graph_num("../data/graph_num_4.csv", 4, 1);
//
//    graph_word("../data/graph_word_2.csv", 2, 1);
//    graph_word("../data/graph_word_3.csv", 3, 1);
//    graph_word("../data/graph_word_4.csv", 4, 1);

//    graph_vec("../data/graph_vec_2.csv", 2, 1);
//    graph_vec("../data/graph_vec_3.csv", 3, 1);
//    graph_vec("../data/graph_vec_4.csv", 4, 1);




}

#endif //PERFECTHASHING_EXPERIMENTS_H
