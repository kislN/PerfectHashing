#include <iostream>
#include <random>
#include <vector>
#include <typeinfo>
#include <string>
#include <cmath>
#include <queue>
#include <time.h>
#include <iostream>
#include <utility>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <map>
#include <string>
#include <chrono>
#include <ios>


#include <random>
#include <stdint.h>

using namespace std;
using namespace std::chrono;


typedef unsigned int UI;
const int INF = numeric_limits<UI>::max() / 2;
const UI PRIME = 2971215073;
UI r_max = 10000;
mt19937 gen(time(0));   // Mersenne twister
uniform_int_distribution<> uid_a(1, r_max-1);
uniform_int_distribution<> uid_b(0, r_max-1);
uniform_int_distribution<> uid_word(4, 39);

#include "Quadratic.h"
#include "Double.h"
#include "Graph.h"
#include "Graphic.h"
#include "utils.h"
#include "experiments.h"
#include "real_life_experiments.h"


int main() {
    srand (time(NULL));

//    all_experiments();
    real_experiments();

    return 0;

}