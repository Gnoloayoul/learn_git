/**
 * Note: The returned array must be malloced, assume caller calls free().
**/

int *solution1 (int *a, int sz, int k, int *rsz){
    int tmp[sz], pos = 0, posr = 0;
    for (int i = 0; i < sz; i++){
        tmp[i] = i;
    }
    for (int i = 0; i < sz; i++){
        if (pos < sz && pos <= i - k){
            pos = tmp[pos + 1];
        }
        for (int b = i - 1; b >= pos && a[b] <= a[i]; b--){
            tmp[b] = i;
        }
        if (i >= k - 1){
            tmp[posr++] = a[tmp[pos]];
        }
    }
        int *res = malloc(sizeof(int) * posr);
        for (int i = 0; i < posr; i++){
            res[i] = tmp[i];
        }
        (*rsz) = posr;
        return res;
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    return solution1(nums, numsSize, k, returnSize);
}