//主要思路：二分答案，判定+二分查找//二分查找的边界，按照题意，左边界是数组weights里的最大元素，右边界是整个数组weights的元素总和
//虽然大体是用了二分查找的（1.1）模板，但要想清楚判定函数返回的运输天数与船最大载重的关系，运输天数小了，船最大载重大了，那么就不管二分载重的右边区间；运输天数大了，船最大载重小了，那么就不管二分载重的左边区间
int shipWithinDays(int* weights, int weightsSize, int days){
    int left = 0, right = 0;
    for (int i = 0; i < weightsSize; i++) {
        left = fmax(left, weights[i]);
        right += weights[i];
    }
    while (left < right) {
        int mid = (left + right) >> 1;
        if (need(mid, weights, weightsSize) <= days) right = mid;
        else left = mid + 1;
    }
    return left;
}

//辅助函数，返回送完数组weights的货要几天。
//船未满，按顺序装货；满了，送完再装货。
int need (int maxCur, int* weights, int weightsSize) {
    int needDay = 1, cur = 0;
    for (int i = 0; i < weightsSize; i++) {
        if (cur + weights[i] > maxCur) {
            ++needDay;
            cur = 0;
        }
        cur += weights[i];
    }
    return needDay;
}
