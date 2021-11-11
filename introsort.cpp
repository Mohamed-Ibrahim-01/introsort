#include <bits/stdc++.h>
using namespace std;


// Function to perform heapsort on the given range of elements
void heapsort(vector<int>::iterator begin, vector<int>::iterator end)
{
    make_heap(begin, end);
    sort_heap(begin, end);
}

/**
 * implement introsort algorithm
 * 
 * @param
 *  a --> int array to be sorted
 *  begin --> iterator points to the lower index
 *  end --> iterator points to the maximum index
 *  max_depth --> number of maximum recursion depth before changing to heapsort
 * 
 * @return
 * 
*/
void introsort(vector<int> a, vector<int>::iterator begin, vector<int>::iterator end, int max_depth){
    
}

#if DEBUG_INTRO_SORT
int main(){
    std::vector<int> nums{-1,5,7,2,3,4,0,17,0,0,17};
    introsort(nums, begin(nums), end(nums));
    for(auto num : nums)
        cout << num << std::endl;
}
#endif
