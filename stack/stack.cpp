// 后缀表达式不需要使用括号，适合使用栈来进行计算
// (1 + 2) * 2 后缀表达式为1,2,+,2,*

// 使用单调栈能够把O(n2)的时间复杂度变成O(n)
// 具体就是需要比较数组中两个元素的大小，并且只找第一个符合要求的元素
