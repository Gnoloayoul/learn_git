//��Ҫ˼·�����ִ𰸣��ж�+���ֲ���//���ֲ��ҵı߽磬�������⣬��߽�������weights������Ԫ�أ��ұ߽�����������weights��Ԫ���ܺ�
//��Ȼ���������˶��ֲ��ҵģ�1.1��ģ�壬��Ҫ������ж��������ص����������봬������صĹ�ϵ����������С�ˣ���������ش��ˣ���ô�Ͳ��ܶ������ص��ұ����䣻�����������ˣ����������С�ˣ���ô�Ͳ��ܶ������ص��������
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

//����������������������weights�Ļ�Ҫ���졣
//��δ������˳��װ�������ˣ�������װ����
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
