#include<bits/stdc++.h>
using namespace std;

int quick_sort(int start, int end, vector<int>&arr) {
    int idx = start - 1;
    int pivot = arr[end];
    int iter = start;
    while(iter < end) {
        if (arr[iter] < pivot) {
            swap(arr[++idx], arr[iter]);
        }
        iter++;
    }
    swap(arr[++idx], arr[iter]);
    return idx;
}

void divide(int start, int end, vector<int>&arr) {
    if (start >= end) {
        return;
    }
    int mid = quick_sort(start, end, arr);
    divide(start, mid - 1, arr);
    divide(mid + 1, end, arr);
}

int main(){
    vector<int> arr = {9, 8, 7, 6, 5, 4, 3};
    divide(0, arr.size() - 1, arr);
    for (auto i: arr) {
        std::cout<<i<<" ";
    }
}