#ifndef PERFECTHASHING_UTILS_H
#define PERFECTHASHING_UTILS_H


#include <sys/time.h>
#include <sys/resource.h>


long getMemoryUsage()
{
    struct rusage usage{};
    if(0 == getrusage(RUSAGE_SELF, &usage))
        return usage.ru_maxrss; // bytes
    else
        return 1;
}

void gen_words(vector <string> & vec, size_t len_vec)
{
    string str;
    char c;
    for(size_t i = 0; i < len_vec; i++)
    {
        size_t len_w = uid_word(gen);
        for (size_t j = 0; j < len_w; j++)
        {
            c = rand() % 26 + 'A';
            str += c;
        }
        vec.push_back(str);
        str.clear();
    }
}

#endif //PERFECTHASHING_UTILS_H
