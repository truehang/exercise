// Dijkstra's Algorithm
// Time Complexity: O(V2)
// Auxiliary Space: O(V)
// 时间复杂度是O(V2)，空间复杂度O(V)
// 限制条件：边的权重不能为负数
// 应用在：解决没有「负权图」的「单源最短路径」问题
// 基本思路是用已有的最短路径去更新原有的路径。贪心算法
// 维护一个距离数组dist[V]，存放从源节点到当前节点的最短路径值，其中源节点的值为0，其余节点初始值为INF
// 维护一个已访问节点集合vSet[V]，记录当前节点是否已经访问过
// 从dist[]中找到最小值的节点u，更新其未访问过（不在vSet中）的邻居v的距离值dist[v]
// 从dist[]取下一个节点，重复操作，直到访问完所有节点

#include <bits/stdc++.h>
using namespace std;

// 时间复杂度V = dist.size()
int getNext(vector<int> &dist, vector<bool> &vSet)
{
    int minval = INT_MAX, min_index = -1;
    for(int i = 0; i < vSet.size(); ++i)
    {
        if(!vSet[i] && dist[i] <= minval)
            minval = dist[i], min_index = i;
    }

    return min_index;
}

// 时间复杂度V^2
vector<int> Dijkstra(vector<vector<int>> &graph, int src)
{
    vector<int> dist(graph.size(), INT_MAX);
    vector<bool> vSet(graph.size());

    dist[src] = 0;

    int u = getNext(dist, vSet);
    while(u != -1)
    {
        vSet[u] = true;

        // 更新邻居v的距离
        for(int v = 0; v < graph.size(); ++v)
        {
            if(!vSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
        u = getNext(dist, vSet);
    }

    return dist;
}

void printResult(const vector<int> &dist)
{
    cout << "Vertex" << " " << "Distance from Source" << endl;
    for(int i = 0; i < dist.size(); ++i)
        cout << i << "     " << dist[i] << endl;
}

int main()
{
    vector<vector<int>> graph = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    printResult(Dijkstra(graph, 0));
    return 0;
}