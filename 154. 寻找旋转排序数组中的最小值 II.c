//��Ȼ����LC153���Ͽ������ظ�Ԫ�أ������ﲻ��ֱ�����ö��ֲ��ң�1.1��ģ��
//�������������
int findMin(int* nums, int numsSize){
    int left = 0, right = numsSize - 1;
    while (left < right) {
        int mid = (left + right) >> 1;
        //���һ��nums[mid] > nums[right]������mid��������Сֵ����ߣ���ô��߿��Բ�������
        if (nums[mid] > nums[right]) {
            left = mid + 1;
          //�������nums[mid] < nums[right]������mid��������Сֵ���ұߣ���ô�ұ߿��Բ�������
        } else if (nums[mid] < nums[right]) {
            right = mid;
          //�������nums[mid] == nums[right]����Ϊ�ظ�Ԫ�أ���֪��mid����������߻������ұߣ���nums[right]������nums[mid]��������ǾͲ������ұߣ�right--
        } else right -= 1;
    }
    return nums[left];
}