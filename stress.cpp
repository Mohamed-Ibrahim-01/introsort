#include "RUNING.h"
#define ARRAY_SIZE 1e3

#include <iostream>
#include <chrono>
#include <cmath>
#include "sorting.h"

using std::cout;
using std::endl;
using std::log;
/**
 * generate 1d vector with size = ARRAY_SIZE
 * 
 * @param
 * 
 * isRandom --> boolean variable to return random or sorted array
 * if isRandom == true, then the array should look like this [0, 1, 2, 3]
 * 
 * @return
 *  a 1d vector with size = ARRAY_SIZE, you have the choice to pass vector by reference or to return a vector
 * make sure to change the code in main to match your change
 * 
 */
vector<int> generate_vector(bool isRandom) {
    constexpr int MIN = -90000;
    constexpr int MAX = 90000;
    constexpr int SIZE = ARRAY_SIZE;

    vector<int> random_vector;

    for(unsigned int i = 0; i < SIZE; i++){
        auto random_num = MIN + ( std::rand() % ( MAX - MIN + 1 ) );
        random_vector.push_back(random_num);
    }
    if(isRandom) std::sort(begin(random_vector), end(random_vector));
    return random_vector;
}

/**
 * driving stress test for both algorithms
 * 
 * generate 1d vector 
 * compare their output and running time
*/
#if BEGIN_STRESS
int main(int argc, char **argv)
{

    while (true)
    {
        
        vector<int> a = generate_vector(true);
        vector<int> b(a); //copy array A into array B
        vector<int> sorted_array(a);
        sort(sorted_array.begin(), sorted_array.end());
        
        auto quick_start = std::chrono::high_resolution_clock::now();
        quicksort(a, a.begin(), a.end());
        auto quick_finish = std::chrono::high_resolution_clock::now();

        auto intro_start = std::chrono::high_resolution_clock::now();


        int max_depth = floor(log(b.size()));
        introsort(b, b.begin(), b.end(), max_depth);
        auto intro_finish = std::chrono::high_resolution_clock::now();

        auto quick_time = (quick_finish - quick_start).count();
        auto intro_time = (intro_finish - intro_start).count();

        if (a == sorted_array && b==sorted_array)
        {
            cout << "equivalent result ";
            cout << "quick_time ==> " << quick_time << " *** ";
            cout << "intro_time ==> " << intro_time << " *** ";
            cout << "performance enhancement ==>" << quick_time / intro_time << endl;
        }
        else
        {
            cout << "error, check your inputs and algorithms " << endl;
            break;
        }
    }
    return 0;
}
#endif
