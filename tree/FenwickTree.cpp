// Fenwick Tree or binary indexed tree (BIT) 
// 中文里通常说 树状数组 或者二叉索引数
// 用于高效计算数列的前缀和， 区间和。
// Algorithm	Average	Worst case
// Space	O(n)	O(n)
// Search	O(logn)	O(logn)
// Insert	O(logn)	O(logn)
// Delete	O(n)	O(n)

// Least Significant Bit of i having a value of 1
#define LSB(i) ((i) & -(i))
// 一维度的BIT
struct FenwickTree{
    vector<int> A;
    // 前i个和
    int prefixSum(int i) const{
        int sum = 0;
        for(; i != 0; i -= LSB(i)) // get parent
            sum += A[i];
        return sum;
    }

    // Returns the sum of elements from i + 1 to j
    // Equivalent to prefixSum(j) - prefixSum(i), but slightly faster
    // get [i + 1, j]
    int rangeSum(int i, int j)
    {
        int sum = 0;
        for(; j > i; j -= LSB(j)) //get parent;
            sum += A[j];
        for(; i > j; i -= LSB(i))
            sum -= A[i];
        return sum;
    }
    // Return a single element's value
    int get(int i)
    {
        return rangeSum(i - 1, i); // get [i,i]
    }

    // Add delta to element with index i
    void add(int i, int delta)
    {
        for(; i < A.size(); i += LSB(i)) // get next
            A[i] += delta;
    }

    // Set (as opposed to adjust) a single element's value
    void set(int i, int value)
    {
        add(i, value - get(i));
    }

    FenwickTree(int n):A(n+1){}
    
    FenwickTree(vector<int> &data): A(data){
        A.insert(A.begin(), 0);
        init();
    }
    // Convert A[] in place to Fenwick tree form
    void init(void)
    {
        for(int i = 1; i < A.size(); ++i)
        {
            int j = i + LSB(i); // next
            if(j < A.size())
                A[j] += A[i];
        }
    }

    // Convert back to array of per-element counts
    void fini(void) 
    {
        for(int i = A.size() - 1; i > 0; --i)
        {
            int j = i + LSB(i);
            if(j < A.size())
                A[j] -= A[i];
        }
    }

};

// 应用 注意 index 在FenwickTree中始终加一
/*
class NumArray {
public:
    NumArray(vector<int>& nums):fentree(nums){
    }
    
    void update(int index, int val) {
        fentree.set(index + 1, val);
    }
    // [left, right]
    int sumRange(int left, int right) {
        // in Fenwick Tree index + 1 : l + 1 -> r + 1
       return fentree.rangeSum(left, right + 1);
    }
    struct FenwickTree fentree;
};
*/
// 应用2：逆序对的计算
// 树状数组中每个元素表示的含义是当前管理范围中k∈[i, j], A[k] <= j 的个数
// 先离散化
/*
 vector<int> tmp(nums);
sort(tmp.begin(), tmp.end());
for(int &num : nums)
    num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() + 1;
*/
// 离散化后的数位于[1, n]区间范围内，树状数组的大小为n+1，可以管理这些数。
// 离散化后的数同时也是树状数组的下标index，所以在所有管理了该index的地方计数加一
// 如果我们要找有多少个数比该数小，那么就是在(0, index - 1]的范围中统计<= index - 1 有多少计数,
// 也就是对index -1求前缀和
// 从后往前更新树状数组。
// 逆序对的计算也可以使用归并排序来算

// 二维的树状数组
struct BIT{
    int m, n;
    vector<vector<int>> A;
    int presum(int i, int j){
        int sum = 0;
        for(; i != 0; i -= LSB(i))
        {
            int c = j;
            for(; c != 0; c -= LSB(c))
            {
                sum += A[i][c];
            }
        }
        return sum;
    }

    void add(int i, int j, int diff)
    {
        for(; i < m; i += LSB(i))
        {
            int c = j;
            for(; c < n; c += LSB(c))
            {
                A[i][c] += diff;
            }
        }
    }

    void init(vector<vector<int>>& matrix)
    {
        A = vector<vector<int>>(m, vector<int>(n));
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                A[i][j] += matrix[i - 1][j - 1]; // 因为j-1位置的数也会加到这里
                int jj = j + LSB(j);
                if(jj < n)
                    A[i][jj] += A[i][j];
            }
        }
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1;j < n; ++j)
            {
                int ii = i + LSB(i);
                if(ii < m)
                    A[ii][j] += A[i][j];
            }
        }
    }

    BIT(vector<vector<int>>& matrix):m(matrix.size() + 1), n(matrix[0].size() + 1){
        init(matrix);
    }
};

//应用：高效求矩形区域的和
/*
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix):ftree(matrix) {
    }
    
    void update(int row, int col, int val) {
        ftree.add(row + 1, col + 1, val - sumRegion(row, col, row, col)); // 减去range不是数
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return ftree.presum(row2 + 1, col2 + 1) - ftree.presum(row2 + 1, col1) - ftree.presum(row1, col2 + 1) + ftree.presum(row1, col1);
    }
private:
    BIT ftree;
};
*/

// 应用：求LIS最长递增子序列的个数
#define LSB(i) ((i) & -(i))
int n;
vector<vector<int>> A;// 自己管辖范围内的LIS的最长长度以及计数 <len, cnt>
vector<int> query(int i)
{
    int len = 0, cnt = 0;
    for(; i != 0; i -= LSB(i))
    {
        if(A[i][0] > len)
        {
            len = A[i][0];
            cnt = A[i][1];
        }else if( A[i][0] == len)
        {
            cnt += A[i][1];
        }
    }
    return {len,cnt};
}
void update(int i, const vector<int> &q)
{
    for(; i < n; i += LSB(i))
    {
        if(A[i][0] < q[0])
        {
            A[i][0] = q[0]; // 如果增加一个全新长度的，则传递全新长度，并更新数组
            A[i][1] = q[1];
        }else if( A[i][0] == q[0])
            A[i][1] += q[1]; // 如果只是增加一个相同长度的，那也把增加的计数传递出去
    }
}

int findNumberOfLIS(vector<int>& nums) {
    // 离散化并去重（因为数列要严格递增）
    set<int> tmp{nums.begin(), nums.end()};
    unordered_map<int,int> allNum;
    int idx = 1;
    for(auto nu : tmp)
        allNum[nu] = idx++;
    
    n = idx + 1;
    A = vector<vector<int>>(n,vector<int>(2));

    for(auto nu : nums)
    {
        auto q = query(allNum[nu] - 1);
        update(allNum[nu], {q[0] + 1, max(q[1], 1)});
    }
    return query(idx)[1];
}