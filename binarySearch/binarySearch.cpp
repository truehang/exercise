// lower bound, unique value
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &a, int target)
{
    int l = 0, r = a.size() - 1;
    while(l <= r)
    {
        int m = ((r - l) >> 1) + l;
        if(a[m] == target) return m;
        if(a[m] > target)
            r = m - 1;
        else l = m + 1;
    }
    return -1; 
}

int main(){
    vector<int> a{1, 3, 4, 6, 7, 10};
    std::cout << "search 0 ret " << binarySearch(a, 0) << std::endl;
    std::cout << "search 1 ret " << binarySearch(a, 1) << std::endl;
    std::cout << "search 2 ret " << binarySearch(a, 2) << std::endl;
    std::cout << "search 4 ret " << binarySearch(a, 4) << std::endl;
    std::cout << "search 10 ret " << binarySearch(a, 10) << std::endl;
    std::cout << "search 11 ret " << binarySearch(a, 11) << std::endl;
    return 0;
}