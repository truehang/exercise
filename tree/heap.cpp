// 堆是完全二叉树
// 插入和删除都是O(logn)，寻找最值O(1)
// 在cpp中为priority_queue
// 最大的特点是最大值或者最小值都在堆的顶部

// 求动态集合中的最大值或者最小值
// 通常
// 最小堆来求，前k个最大值
// 最大堆来求，前k个最小值
// 模板为
if(heap.size() < k)
    heap.emplace(xxx);
else if(cond(val, heap.top()))
{
    heap.pop();
    heap.emplace(xxx);
}

// 默认排序是从小到大排序->需要最大堆实现，默认是最大堆

// 第 k 大使用最小堆,对于简单的元素，直接使用greater即可
priority_queue<int, vector<int>, greater<int>> minHeap;

//如果使用最小堆的话，加入元素结构比较复杂可以自定义一个struct node，并且重载>运算符， 然后在构造堆时传入greater<node>
// 比如
struct node{
    int sum;
    int i;
    int j;
    node(int a, int b, int c):sum(a), i(b), j(c){}
    bool operator>(const node &other) const
    {
        return sum > other.sum;
    }
};
priority_queue<node, vector<node>, greater<node>> minHeap;
// 或者重载<运算符来定义最大堆
struct node{
    int sum;
    int i;
    int j;
    node(int a, int b, int c):sum(a), i(b), j(c){}
    bool operator<(const node &other) const
    {
        return sum < other.sum;
    }
};
priority_queue<node, vector<node>, less<node>> maxHeap;

// 如果从若干排序好的静态的数组中找前k个最小的组合，也可以使用最小堆
// 我们只需要框定好数据范围，然后添加即可，直到添加到k个
for(int i = 0; i < min(k, m); ++i)
    minHeap.emplace(nums2[0] + nums1[i],i, 0);
// 时间复杂度O(klogk)
vector<vector<int>> res;
do{
    auto [_,i,j] = minHeap.top();
    minHeap.pop();
    res.push_back({nums1[i], nums2[j]});
    if(res.size() == k ) break;
    if(j + 1 < min(k,n))
    minHeap.emplace(nums2[j + 1] + nums1[i], i, j + 1);
    
}while(!minHeap.empty());