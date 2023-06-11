// 来源于：https://leetcode.cn/problems/range-sum-query-mutable/solutions/1389182/qu-yu-he-jian-suo-shu-zu-ke-xiu-gai-by-l-76xj/
// 线段树是一种二叉搜索树
// 叶子节点代表一个点对应一个数组元素
// 非叶子节点代表一个区间[a, b]
// 左儿子表示的区间为[a,(a+b)/2]，右儿子表示的区间为[(a+b)/2+1,b]
// 时间复杂度 O(logn) 建树为O(n)
// 线段树中元素的index可以从0开始

int n;
vector<int> segmentTree;
void init(vector<int> &nums){
    n = nums.size();
    segmentTree.resize(n * 4);
}
void build(int v, int s, int e, vector<int> &nums)
{
    if(s == e)
    {
        segmentTree[v] = nums[s];
        return;
    }
    int m = s + (e - s) / 2;
    build(v * 2 + 1, s, m, nums);
    build(v * 2 + 2, m + 1, e, nums);
    segmentTree[v] = segmentTree[v * 2 + 1] + segmentTree[v * 2 + 2];
}

void change(int index, int val, int v, int s, int e)
{
    if( s == e) // 找到叶子节点更新
    {
        segmentTree[v] = val;
        return;
    }
    int m = s + (e - s) / 2;
    if(index <= m)
    {
        change(index, val, v * 2 + 1, s, m);
    }else change(index, val, v * 2 + 2, m + 1, e);

    //汇总更新前缀和
    segmentTree[v] = segmentTree[v * 2 + 1] + segmentTree[v * 2 + 2];
}

int query(int l, int r, int v, int s, int e)
{
    if(l == s && r == e) //找到了特定的区间
    {
        return segmentTree[v];
    }
    int m = s + (e - s) / 2;
    if(r <= m)
        return query(l, r, v * 2 + 1, s, m); // 在左子树继续找
    else if(l > m)
        return query(l, r, v *2 + 2, m+1,e); // 在右子树继续找
    else
        return query(l, m, v * 2 + 1, s, m) + query(m + 1, r, v * 2 + 2, m + 1, e); 
}

/*
app:

init(nums);
build(0,0,n -1, nums);
change(index, val, 0, 0, n -1);
query(left, right, 0, 0, n - 1);
*/