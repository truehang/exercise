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