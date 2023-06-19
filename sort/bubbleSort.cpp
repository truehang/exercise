// O(n2)
for(int i = 0; i < n; i++)
for(int j = i; j < n - 1; j++)
{
    if(nums[j] > nums[j + 1])
    swap(nums[j], nums[j + 1]);
}