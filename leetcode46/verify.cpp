#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> vis;

public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int idx, vector<int>& perm) {
        if (idx == nums.size()) {
            ans.emplace_back(perm);
            return;
        }
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
                continue;
            }
            perm.emplace_back(nums[i]);
            vis[i] = 1;
            backtrack(nums, ans, idx + 1, perm);
            vis[i] = 0;
            perm.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        vis.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, ans, 0, perm);
        return ans;
    }
};

class mySolution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //先排序
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        dfs(nums, 0, res);
        return res;
    }
    void dfs(vector<int>& nums, int i, vector<vector<int>> &res)
    {
        // 边界条件
        if(i == nums.size())
        {
            res.emplace_back(nums);
            return;
        }
        for(int k = i; k < nums.size();) // 当前交换的是第i个元素
        {
            swap(nums[k], nums[i]);
            dfs(nums, i + 1, res);
            swap(nums[k], nums[i]);
            // 为了防止重复，不要和交换的数相同 以及跳过连续相同的数
            k++;
            while(k < nums.size() && (nums[k] == nums[i] || nums[k] == nums[k - 1])) k++;
        }
        

    }
};

int main()
{
    Solution s1;
    mySolution s2;
    // test case #32
    vector<int> testcase32 = {-1,2,0,-1,1,0,1};
    auto res1 = s1.permuteUnique(testcase32);
    testcase32 = {-1,2,0,-1,1,0,1};
    auto res2 = s2.permuteUnique(testcase32);
    if(res1.size() != res2.size())
    {
        cout << "size wrong "  << res1.size() << "," << res2.size() << endl;
        return -1;
    }
    sort(res1.begin(), res1.end());
    sort(res2.begin(), res2.end());
    int n = res1.size();
    for(int i = 0; i < n; ++i)
    {
        if(res1[i] != res2[i])
        {
            for(auto n1 : res1[i])
                cout << n1 << ",";
            cout << endl;
            for(auto n2 : res2[i])
                cout << n2 << ",";
            cout << endl;
            cout << "wrong" << endl;
            return -1;
        }
    }
    cout << "success" << endl;
    return 0;
}