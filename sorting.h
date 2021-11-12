#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using std::vector;
using std::cout;

void quicksort(vector<int>& arr, vector<int>::iterator start, vector<int>::iterator end);
vector<int>::iterator partition(vector<int>::iterator start, vector<int>::iterator end);
void heapsort(vector<int>::iterator begin, vector<int>::iterator end);
void introsort(vector<int>& arr, vector<int>::iterator start, vector<int>::iterator end, int max_depth);
