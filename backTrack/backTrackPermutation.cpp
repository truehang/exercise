/**
 * @file backTrackPermutation.cpp
 * @author Hogan Chou (hoganchous@gmail.com)
 * @brief 以下内容都是排列问题，使用交换的思想，用backtrack（回溯）的形式求解
 * @version 0.1
 * @date 2023-05-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>
using namespace std;

//全排列问题
// 时间复杂度O(n!)
void permutationHelper(vector<int> &a, int i, vector<vector<int>> &res) 
{  
    if(i == a.size()) 
    {
        res.emplace_back(a); // 正好在这个条件下我们得到结果
        return; // 返回条件
    }
    // i为首位置，i之后位置的数都可以换到i上
    for(int j = i; j < a.size(); ++j)
    {
        swap(a[i], a[j]); // 交换该位置和首位置，交换n次就意味着i位置可以存放n个数。
        permutationHelper(a, i + 1, res); // 接着计算下一个位置的交换可能性
        swap(a[i], a[j]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    permutationHelper(nums,0,res);
    return res;
}

// 包含重复元素的全排列，全排列的结果需要去重，全排列的剪枝
void permutationHelperUnique(vector<int> &a, int i, vector<vector<int>> &res) 
{  
    if(i == a.size()) 
    {
        res.emplace_back(a); // 正好在这个条件下我们得到结果
        return; // 返回条件
    }
    // i为首位置，i之后位置的数都可以换到i上
    // 如果已经有一个数m和首位置互换了，那么之后的m不需要再和首位置互换，否则首位置的数就重复了，结果也是重复的
    unordered_set<int> memo;
    for(int j = i; j < nums.size(); ++j)
    {
        if(memo.count(nums[j]) == 0)
        {
            // value not swap with nums[i] before
            memo.insert(nums[j]);
            swap(nums[i], nums[j]);// 这里的j已经交换了值了
            helper(nums, i + 1, res);
            swap(nums[i], nums[j]);
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    permutationHelperUnique(nums, 0, res); 
    return res;
}

void dumpSubsets(const vector<vector<int>> &a)
{
    int n = a.size();
    cout << "[";
    for(int i = 0; i < n; ++i)
    {
        int m = a[i].size();
        cout << "[";
        for(int j = 0; j < m; ++j)
        {
            cout << a[i][j];
            if(j < m - 1)
            cout << ",";
        }
        cout << "]";
        if(i < n - 1)
        cout << ",";
    }
    cout << "]\n";
}

int main()
{
    vector<int> nums = {1,2,3};
    dumpSubsets(permute(nums));
    nums = {1,1,2};
    dumpSubsets(permuteUnique(nums));
    return 0;
}