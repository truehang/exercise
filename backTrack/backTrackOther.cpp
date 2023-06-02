/**
 * @file backTrackOther.cpp
 * @author Hogan Chou (hoganchous@gmail.com)
 * @brief 如果一个问题需要若干步骤，每个步骤都有若干选项，并且要求出问题的所有解，尝试用回溯法解决。
 * @version 0.1
 * @date 2023-05-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>
using namespace std;

// 通用的非记忆回溯模板
Ret_t dfs( unordered_map<T, int> &visited, T &start, T &end, unordered_map<T,set<T>> &graph)
{
    if(start == end){ // 递归终止条件
        return base_val;
    }
    visited[start] = 1; // 防止访问父亲节点
    Ret_t res;
    for(auto subseq : graph[start])
    {
        if(!visited[subseq])
        {
            auto tmp = dfs(visited, subseq, end, graph);
            res = Operation(res, tmp);
            // if found one, break; or find all
        }
    }
    visited[start] = 0; // 防止递归的子树干扰父节点
    return res;
}

// 记忆递归模板， 在加上一个memo，计算前先查找，找到了就返回，没找到就递归查找更新并返回
Ret_t dfs( unordered_map<T, int> &visited, T &start, T &end, unordered_map<T,set<T>> &graph, unordered_map<T,Ret_t> &memo)
{
    //先查找结果
    if(memo.count(key) > 0)
    {
        return memo[key]; // key = Operation(start,end);
    }
    if(start == end){ // 递归终止条件
        return base_val;
    }
    visited[start] = 1; // 防止访问父亲节点
    Ret_t res;
    for(auto subseq : graph[start])
    {
        if(!visited[subseq])
        {
            auto tmp = dfs(visited, subseq, end, graph);
            res = Operation(res, tmp);
            // 达到退出条件
            if(exit_cond)
            {
                memo[key] = res;
                break;
            }
            // if found one, break; or find all
        }
    }
    visited[start] = 0; // 防止递归的子树干扰父节点
    return memo[key];
}

