// 首先初始化父节点
vector<int> parent(n);
for(int i = 0; i < n; ++i)
    parent[i] = i;
vector<int> rank(n, 1); // 和高度的含义类似但是不等于高度
find(int i)
{
    if(parent[i] != i)
    {
        parent[i] = find(parent[i]);// 路径压缩
    }
    return parent[i];
}

union(int i, int j)
{
    int pi = find(i);
    int pj = find(j);
    if(pi != pj)
    {
        // now union
        parent[pi] = pj;
    }
}

// 更高效的unionFind
// find 使用路径压缩
// union时使用秩来合并
union(int i, int j)
{
    int pi = find(i);
    int pj = find(j);
    if(pi != pj)
    {
        // now union with rank
        if(rank[pi] > rank[pj])
            root[pj] = pi;
        else if(rank[pi] < rank[pj])
            root[pi] = pj;
        else{
            root[pj] = pi;
            rank[pi] += 1; // 秩加一
        }

        //联通会导致联通量减少
        joint--;
    }
}

// 判断有几个联通区域
// 是否只有一个联通区域
// 可以通过找父节点来看，也可以通过成功联通的数量来看
int p1 = find(parent, 0);
for(int i = 1; i < n; ++i) // 直接判断parent是错误的
{
    if(find(parent, i) != p1)
        return false;
}
return true;

// 如果是用于查找单词相似，还需要哈希映射，把单词映射成数字，然后再使用联通