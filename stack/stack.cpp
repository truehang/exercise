// 后缀表达式不需要使用括号，适合使用栈来进行计算
// (1 + 2) * 2 后缀表达式为1,2,+,2,*

// 使用单调栈能够把O(n2)的时间复杂度变成O(n)
// 具体就是需要比较数组中两个元素的大小，并且只找第一个符合要求的元素

//单调栈+数组保存寻找结果的方式，可以找到每个元素的左右边界，即第一个大于它们或者小于它们的数
// 能大大减小时间复杂度

// 找左边第一个大于的数
// 大于当前的数，所以当前数入栈时要小
for(int i = 0; i < n; i++)
{
    while(!stk.empty() && nums[i] >= stk.top())
        stk.pop();
    // now num < top
    // top 就是第一个大于自己的数
    // 保存top结果到数组中
    stk.push(nums[i]);

}

// 找右边第一个大于的数
// 大于当前的数，所以当前数入栈时小
// 既然找右边的，所以i = n - 1找起
for(int i = n - 1; i >=  0; i--)
{
    while(!stk.empty() && nums[i] >= stk.top())
        stk.pop();
    // now num < top
    // top 就是第一个大于自己的数
    // 保存top结果到数组中
    stk.push(nums[i]);
}

// 找左边第一个小于自己的数
// 小于自己的数，那么自己入栈要大
for(int i = 0; i < n; i++)
{
    while(!stk.empty() && nums[i] <= stk.top())
        stk.pop();
    // now num > top
    // 保存top结果到数组中
    stk.push(nums[i]);
}

// 找右边第一个小于自己的数
// 小于自己的数，那么自己入栈要大
for(int i = n - 1; i >= 0; i--)
{
    while(!stk.empty() && nums[i] <= stk.top())
        stk.pop();
    // now num > top
    // 保存top到数组中
    stk.push(nums[i]);
}

