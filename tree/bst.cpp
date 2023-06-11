// 二叉搜索树
// 通常采用中序遍历来解决问题

// 普通树查找一个点的时间复杂度为O(n)
// 二叉搜索树查找一个点的时间复杂度为O(h)，h是树高，如
TreeNode *searchBST(TreeNode *root, int val)
{
    TreeNode *cur = root;
    while(cur != nullptr)
    {
        if(cur -> val == val)
        {
            break;
        }
        if(cur->val > val)
            cur = cur->left;
        else
            cur = cur->left;
    }
    return cur;
}

// map 和 set 就是利用二叉搜索树的数据结构
// 适用于需要根据数据的大小查找
// 比如说日历表
// 我们要插入一个时间段，我们要寻找可能产生冲突的一个时间段，
// 比较这两个时间段是否与当前时间段重合
set<pair<int,int>> booked;
bool book(int start, int end) {
    // 寻找第一个在后面的区间
    //      [  ]
    // [s,e]
    auto it = booked.lower_bound({end, 0});
    // 比较可能产生交集的区间，即上一次查找的前一个区间
    //1. [==]
    //        [s, e]
    //2. [==]
    //     [s, e]
    //3.  [==]
    // [s,e]
    // 不相交的话满足
    if(it == booked.begin() || (--it)->second <= start)
    {
        booked.emplace(start, end);
        return true;
    }
    return false;
}

    