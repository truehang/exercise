#include <bits/stdc++.h>
using namespace std;
// select a pivot and partion
int partition(vector<int> &a, int l, int r)
{
    // choose pivot
    int idx = random() % (r - l + 1) + l;
    // swap pivot to range last part
    swap(a[idx], a[r]);
    // move each element which is less than pivot to the left
    int i = l - 1;
    for(int j = l; j < r; ++j)
    {
        if(a[j] < a[r])
            swap(a[++i], a[j]);
    }
    // move pivot in the middle
    swap(a[++i], a[r]);
    // return pivot index
    return i;
}

void quickSort(vector<int> &a, int l, int r)
{
    if(l >= r)
    return;
    int p = partition(a, l, r);
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
}

void quickSort(vector<int> &a)
{
    srand(time(0));
    quickSort(a, 0, a.size() - 1);
}

int findKthLargest(vector<int>& nums, int k) {
    // quick select
    srand(time(0));
    int n = nums.size();

    int l = 0, r = n - 1;
    int p = partition(nums, l, r);
    while(p != n - k)
    {
        if(p < n - k)
        {
            l = p + 1;               
        }else{
            r = p - 1;
        }
        p = partition(nums, l, r);
    }
    return nums[p];
}

int main()
{
    vector<int> a{1,4,5,7,2,4,5,1};
    quickSort(a);
    for(auto v :  a)
        cout << v << ",";
    cout << endl;

    // test
    vector<int> b1 = {3,2,1,5,6,4};
    int k = 2;
    cout << findKthLargest(b1, k) << endl;
    b1 = {3,2,3,1,2,4,5,5,6};
    k = 4;
    cout << findKthLargest(b1, k) << endl;
    return 0;
}