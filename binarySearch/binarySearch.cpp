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

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = ((right - left) >> 1) + left;
        if (nums[mid] >= target) {
            if(mid == 0 || nums[mid - 1] < target)
                return mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

// 如果能找到一个问题是如何求解的，以及变量的两个边界值，可以使用二分查找去验证答案，相当于一种高效的穷举法

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