// Kahn's Algorithm
// for Topological Sorting
// A directed acyclic graph (DAG) G has at least one vertex with the indegree zero and one vertex with the out-degree zero.
// 解决有向无环图的拓扑排序问题
// 使用队列来装载所有入度为0的节点，
// 每次处理完一个节点后，它的邻接节点入度减一，如果为0则加入队列。
// 重复处理，直到队列为空。

#include <bits/stdc++.h>
using namespace std;

vector<int> Kahn(vector<vector<int>> &graph, vector<int> &indegree)
{
    queue<int> q;
    for(int i = 0; i < indegree.size(); ++i)
        if(indegree[i] == 0)
            q.emplace(i);
    vector<int> res;
    while(!q.empty())
    {
        auto i = q.front();
        q.pop();
        res.emplace_back(i);
        for(auto nxt : graph[i])
            if(--indegree[nxt] == 0)
                q.emplace(nxt);
    }
    // detect cycle
    for(int i = 0; i < indegree.size(); ++i)
        if(indegree[i] > 0) return {};
    
    return res;
}
