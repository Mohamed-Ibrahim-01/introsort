#include "RUNNING.h"
#include "sorting.h"
/**
 * Quick sort algorithm for vector of integers
 * 
 * @param
 *  a --> int array to be sorted
 *  start --> iterator points to the lower index
 *  end --> iterator points to the maximum index
 * 
 * @return
 * void as quicksort is an inplace sorting algorithm
*/
void quicksort(vector<int>& arr, vector<int>::iterator start, vector<int>::iterator end){
    if(std::distance(start, end) > 0){
        auto splitPosition = partition(start, end);
        quicksort(arr, start, splitPosition);
        quicksort(arr, splitPosition+1, end);
    }
}


/**
 * Partitioning a vector using a pivot at the end 
 * 
 * @param
 *  start --> iterator points to the lower index
 *  end --> iterator points to the maximum index
 * 
 * @return
 * pivot --> pivot index after partitioning the vector 
*/
vector<int>::iterator partition(vector<int>::iterator start, vector<int>::iterator end){
    auto pivot = end-1;
    auto last_smaller = start -1; 
    for(auto curr_num = start; curr_num != end-1; curr_num++){
        if(*curr_num < *pivot ){
            auto first_greater = last_smaller+1;
            std::iter_swap(first_greater, curr_num);
            last_smaller++;
        }
    }
    iter_swap(pivot, last_smaller+1);
    pivot = last_smaller+1;
    return pivot;
}

#if DEBUG_QUICK_SORT
int main(){
    std::vector<int> nums{-1,5,7,2,3,4,0,17,0,0,17};
    quicksort(nums, begin(nums), end(nums));
    for(auto num : nums)
        cout << num << std::endl;
}
#endif
