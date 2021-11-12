#include "RUNING.h"
#include "sorting.h"
// Function to perform heapsort on the given range of elements
void heapsort(vector<int>::iterator begin, vector<int>::iterator end) {
    std::make_heap(begin, end);
    std::sort_heap(begin, end);
}

void introsort(vector<int>& arr, vector<int>::iterator start, vector<int>::iterator end, int max_depth){
    if(arr.size() <= 1) return;
    else if (max_depth == 0) heapsort(start, end);
    else if(std::distance(start, end) > 0){
        auto splitPosition = partition(start, end);
        introsort(arr, start, splitPosition, max_depth-1);
        introsort(arr, splitPosition+1, end, max_depth-1);
    }
    
}

#if DEBUG_INTRO_SORT
int main(){
    std::vector<int> nums{-1,5,7,2,3,4,0,17,0,0,17};
    int max_depth = floor(std::log(nums.size()));
    introsort(nums, begin(nums), end(nums), max_depth);
    for(auto num : nums)
        cout << num << std::endl;
}
#endif
