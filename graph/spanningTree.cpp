// minimum spanning tree，MST
// 如果连通图G的一个子图是一棵包含G的所有顶点的树，则该子图称为G的生成树(SpanningTree)
// MST拥有连接这些顶点权重之和最小的边，并且边条数最少。

#include <bits/stdc++.h>
using namespace std;


// Kruskal 算法
// 先把边排序
// 取出最小的边，假如加入边不会和原来的MST产生环，则把边添加到MST中，否则丢弃
// 重复步骤，直到成功取了N-1条结束。
// 需要使用到unionFind来判断环
// edges的元素排列为：length,(u,v)
int KruskalMST(vector<pair<int, pair<int,int>>> &edges, int n)
{
    sort(edges.begin(), edges.end());
    vector<int> parent(n);
    for(int i = 0; i < n; ++i)
        parent[i] = i;
    
    auto findP = [&parent](auto &&findP,int i)->int
    {
        return parent[i] == i ? i : findP(findP, parent[i]);
    };
    auto unionE = [&findP, &parent](int i, int j)->bool
    {
        int pi = findP(findP, i);
        int pj = findP(findP, j);
        if(pi == pj)
        {
            return false;
        }
        parent[pi] = pj;
        return true;
    };
    
    int weightsum = 0;
    int i = 0; 
    int cnt = 0;
    while(cnt < n - 1)
    {
        auto [u, v] = edges[i].second;
        if(unionE(u,v))
        {
            weightsum += edges[i].first;
            ++cnt;
        }
        ++i;   
    }
    return weightsum;
}