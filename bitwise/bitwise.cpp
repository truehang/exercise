#include <bits/stdc++.h>
using namespace std;

// 只有6种位运算：非(!)，与(&)，或(|)，异或(^)，左移(<<)，右移(>>)。左移相当于*2,右移相当于尾部1变0再/2。
// 计算整数中1的个数
// i & (i - 1) 将i最右边的1变成0
int countBits(int num)
{
    int cnt = 0;
    while(num > 0)
    {
        num &= (num - 1);
        cnt++;
    }
    return cnt;
}

// "i >> 1" 计算 "i/2"，"i & 1"计算"i%2"，因为位运算更高效
// 任何一个数异或它自己都是0，0与一个数异或等于它自己
// 如何判断两个单词是否含有相同字符，我们可以根据每个单词的字母对整数进行左移操作，把两个单词对应的整数与操作，
// 为0则不含有相同字母，不为0则含有相同字母
// 负数在计算机中是补码表示，取反加一
// -1 的二进制表示是1111111111111111111111111111111111111111111111111111111111111111，
// 所以在对负数进行右移动操作时，一定要移动到最后，比如32位。而非负数只需要右移移动到零即可。
// 比如在数组中找m次数唯一一个n次数的数（m>n）。也是把这些数表示成32位，比较每个位上的累进值。

/*
• __builtin_clz(x): the number of zeros at the beginning of the bit representation
• __builtin_ctz(x): the number of zeros at the end of the bit representation
• __builtin_popcount(x): the number of ones in the bit representation
• __builtin_parity(x): the parity (even or odd) of the number of ones in the
bit representation.

g++ does not automatically use it and we need to use the -march=native flag to enable it.
The -march=native flag is not often set in contest systems, but we can specify
the architecture in our code using a #pragma directive. However, in this context, the
value native is not supported but we have to name the architecture. For example,
the following directive (assuming the Sandy Bridge architecture) can work:
#pragma GCC target ("arch=sandybridge")

x | (1 << k) sets the kth bit of x to one
x & ~(1 << k) sets the kth bit of x to zero
x ˆ (1 << k) inverts the kth bit of x
x & (x − 1) sets the last one bit of x to zero
x & −x sets all the one bits to zero, except for the last one bit.
x | (x − 1) inverts all the bits after the last one bit
x & (x − 1) = 0 a positive number x is a power of two
*/

int main()
{
    int x = 5328;
    cout << 
}