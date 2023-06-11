// 在有向图中寻找所有路径
// BFS
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> res;
    queue<vector<int>> q;
    q.push({0});
    while(!q.empty())
    {
        auto curPath = q.front();
        q.pop();
        int curV = curPath.back();
        if(curV == graph.size() - 1) // destination
        {
            res.emplace_back(curPath); // add current path
        }else{
            for(auto nxt : graph[curV])
            {
                vector<int> tmp = curPath;
                tmp.emplace_back(nxt);
                q.emplace(tmp); // extend current path
            }
        }
    }

    return res;

}
// DFS
vector<vector<int>> res;
vector<vector<int>> dag;
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    dag = graph;
    vector<int> path;
    dfs(0, path);
    return res;
}
void dfs(int src, vector<int> &path)
{
    path.push_back(src);
    if(src == dag.size() - 1)
    {
        res.emplace_back(path);
    }else{
        for(auto nxt : dag[src])
            dfs(nxt, path);
    }
    path.pop_back();
}

    