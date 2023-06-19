/**
 * @file backTrackCombination.cpp
 * @author Hogan Chou (hoganchous@gmail.com)
 * @brief 以下内容都是组合问题，思想是枚举每个元素是否选取，使用backtrack（回溯）的形式求解
 * @version 0.1
 * @date 2023-05-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>
using namespace std;

// 枚举是否选择当前这个，并且有选择的先后顺序
// 时间复杂度O(2^n)
void backTrackSelect(vector<int> &a, int i, vector<int> &subset, vector<vector<int>> &res)
{
    if(i == a.size()) // 终止条件
    {
        res.emplace_back(subset);
        return; // 一定记得返回
    }
    
    // 选择下一个
    backTrackSelect(a, i + 1, subset, res);
    
    //选择当前这个值
    subset.push_back(a[i]);
    backTrackSelect(a, i + 1, subset, res);
    // 恢复选择
    subset.pop_back(); 

}

// 子集 或者 组合问题
vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> subset;
    vector<vector<int>> res;
    backTrackSelect(nums, 0, subset, res);
    return res;
}

// 含有k个数的组合，子集的剪枝
void backTrackSelectK(vector<int> &a, int i, int k, vector<int> &subset, vector<vector<int>> &res)
{
    // 添加结果
    if(subset.size() == k) {
        res.emplace_back(subset);
        return;
    }
    if(i == a.size()) // 终止条件
    {
        return; // 一定记得返回
    }
 
    
    //选择当前这个值
    subset.push_back(a[i]);
    backTrackSelectK(a, i + 1, k, subset, res);
    // 恢复选择
    subset.pop_back(); 
   
    // 选择下一个
    backTrackSelectK(a, i + 1, k, subset, res);
}

vector<vector<int>> combine(int n, int k) {
    // vector<int> visited(n + 1);
    vector<int> comb;
    vector<vector<int>> res;
    vector<int> a;
    for(int i = 1; i <= n; ++i)
        a.push_back(i);
    backTrackSelectK(a, 0, k, comb, res);
    return res;
}


// 允许重复选择，和为target
void backTrackSelectSum(vector<int> &a, int i, int sum, int target, vector<int> &subset, vector<vector<int>> &res)
{
    // 添加结果
    if(sum == target) {
        res.emplace_back(subset);
        return;
    }
    if(i == a.size() || sum > target) // 终止条件
    {
        return; // 一定记得返回
    }
 
    //选择当前这个值
    subset.push_back(a[i]);
    sum += a[i];
    backTrackSelectSum(a, i, sum, target, subset, res); // 重复选择，直到返回
    // 恢复选择
    sum -= a[i];
    subset.pop_back(); 
   
    // 选择下一个
    backTrackSelectSum(a, i + 1, sum, target, subset, res);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> candidate;
    vector<vector<int>> res;
    backTrackSelectSum(candidates, 0, 0, target, candidate, res);
    return res;

}

// 有重复的元素，结果需要去重， 和为target
void backTrackSelectSum2(vector<int> &a, int i, int sum, int target, vector<int> &subset, vector<vector<int>> &res)
{
    // 添加结果
    if(sum == target) {
        res.emplace_back(subset);
        return;
    }
    if(i == a.size() || sum > target) // 终止条件
    {
        return; // 一定记得返回
    }
 
    //选择当前这个值
    subset.push_back(a[i]);
    sum += a[i];
    backTrackSelectSum2(a, i + 1, sum, target, subset, res);
    // 恢复选择
    sum -= a[i];
    subset.pop_back(); 
   
    // 选择下一个时，需要跳到下一个不重复的位置, 这个只能在排序后，找子集时使用
    int j = i + 1;
    while(j < a.size() && a[j] == a[i]) ++j;
    backTrackSelectSum2(a, j, sum, target, subset, res);
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> subset; vector<vector<int>> res;
    backTrackSelectSum2(candidates, 0, 0, target, subset, res);
    return res;
}

// 子序列问题
// 找递增序列， 不能排序
void dfs(vector<int>& nums, int i, int last, vector<int> &seq, vector<vector<int>> &res)
{
    if(i == nums.size())
    {
        if(seq.size() > 1)
            res.emplace_back(seq);
        return;
    }
    // 选择当前元素
    if(nums[i] >= last)
    {
        seq.push_back(nums[i]);
        dfs(nums, i + 1, nums[i], seq, res);
        seq.pop_back();
    }

    // 不选择当前元素,假如当前元素等于上一个元素，那么往后递归的数一定会产生重复
    // 所以当前元素不等于前面元素才能递归下去
    if(nums[i] != last)
        dfs(nums, i + 1, last,seq, res);
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<int> seq;
    vector<vector<int>> res;
    dfs(nums, 0, INT_MIN, seq, res);
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
    dumpSubsets(subsets(nums));
    dumpSubsets(combine(4, 2));
    nums = {2,3,6,7};
    dumpSubsets(combinationSum(nums, 7));
    nums = {2,3,5};
    dumpSubsets(combinationSum(nums, 8));
    nums = {10,1,2,7,6,1,5};
    dumpSubsets(combinationSum2(nums, 8));
    nums = {2,5,2,1,2};
    dumpSubsets(combinationSum2(nums, 5));
    
    return 0;
}