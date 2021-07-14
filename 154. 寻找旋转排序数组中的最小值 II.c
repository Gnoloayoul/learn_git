//虽然这是LC153加上可允许重复元素，但这里不能直接套用二分查找（1.1）模板
//分三种情况讨论
int findMin(int* nums, int numsSize){
    int left = 0, right = numsSize - 1;
    while (left < right) {
        int mid = (left + right) >> 1;
        //情况一：nums[mid] > nums[right]，就是mid落在了最小值的左边，那么左边可以不用讨论
        if (nums[mid] > nums[right]) {
            left = mid + 1;
          //情况二：nums[mid] < nums[right]，就是mid落在了最小值的右边，那么右边可以不用讨论
        } else if (nums[mid] < nums[right]) {
            right = mid;
          //情况三：nums[mid] == nums[right]，因为重复元素，不知道mid是落在了左边还是在右边，但nums[right]总是有nums[mid]这个替身，那就不考虑右边，right--
        } else right -= 1;
    }
    return nums[left];
}