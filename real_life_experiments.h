
#ifndef PERFECTHASHING_REAL_LIFE_EXPERIMENTS_H
#define PERFECTHASHING_REAL_LIFE_EXPERIMENTS_H

void readFile(vector<string> & words)
{
    ifstream file;
    file.open ("../data/iliada_processed.txt");
    if (!file.is_open()) return;

    string word;
    while (file >> word)
    {
        words.push_back(word);
    }
}

bool real_quad(string file_name){
    vector<string> words;
    readFile(words);
    size_t n = words.size();
    size_t c = 3;

    ofstream file(file_name);
    if (!file.is_open()) {
        return 0;
    }
    cout << "File is open " << endl;
    file << "Method,DataN,C,BuildTime,Memory" << endl;


    auto build_time_ = high_resolution_clock::now();
    long total_memory =  getMemoryUsage();
    Quadratic<string> g_words(words, c, 10000, 50);
    g_words.do_hash();
    auto build_time = high_resolution_clock::now() - build_time_;
    total_memory += (getMemoryUsage() - total_memory) / 1024;

    build_time = duration_cast<microseconds>(build_time);
    file << "Quadratic" << "," << n << "," << c << "," << build_time.count() / 1000000. << ","
          << total_memory << endl;


}

bool real_double(string file_name){
    vector<string> words;
    readFile(words);
    size_t n = words.size();
    size_t c = 4;

    ofstream file(file_name);
    if (!file.is_open()) {
        return 0;
    }
    cout << "File is open " << endl;
    file << "Method,DataN,C,BuildTime,Memory" << endl;


    auto build_time_ = high_resolution_clock::now();
    long total_memory =  getMemoryUsage();
    Double<string> g_words(words, c, 10000, 50, 3);
    g_words.do_hash();
    auto build_time = high_resolution_clock::now() - build_time_;
    total_memory += (getMemoryUsage() - total_memory) / 1024;

    build_time = duration_cast<microseconds>(build_time);
    file << "Double" << "," << n << "," << c << "," << build_time.count() / 1000000. << ","
          << total_memory << endl;


}

bool real_graph(string file_name){
    vector<string> words;
    readFile(words);
    size_t n = words.size();
    size_t c = 3;

    ofstream file(file_name);
    if (!file.is_open()) {
        return 0;
    }
    cout << "File is open " << endl;
    file << "Method,DataN,C,BuildTime,Memory" << endl;


    auto build_time_ = high_resolution_clock::now();
    long total_memory =  getMemoryUsage();
    Graphic<string> g_words(words, c);
    g_words.do_hash(50, 10000);
    auto build_time = high_resolution_clock::now() - build_time_;
    total_memory += (getMemoryUsage() - total_memory) / 1024;

    build_time = duration_cast<microseconds>(build_time);
    file << "Graphic" << "," << n << "," << c << "," << build_time.count() / 1000000. << ","
          << total_memory << endl;

}


void real_experiments(){
    real_quad("../data/iliada_quad.csv");
    real_double("../data/iliada_double.csv");
    real_graph("../data/iliada_graph.csv");

}

#endif //PERFECTHASHING_REAL_LIFE_EXPERIMENTS_H
