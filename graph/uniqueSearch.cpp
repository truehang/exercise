// 为了防止重复搜索到原来的路径
// 我们可以使用visited数组来对访问过的元素进行标记
// 每次递归时，先标记为已访问过，递归返回后也不清除子树的访问痕迹，这样寻找路径时，首先没有访问过在进行递归
// 模板是
for(int i = 0; i < m; ++i)
for(int j = 0; j < n; ++j)
if(COND(findroute) && !visited[i][j]) // 查找新路线
{
    if(dfs(board,i,j,visited...)) 
    {
    }
}


dfs(board,i,j,visited...)
{   
    // 返回条件
    if(COND(return)) return;
    visited[i][j] = 1;
    for(...)
        dfs(board,ni,nj,visited); // 每个分支都要访问到，完全查找
    // 不清楚子树的访问痕迹

}