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