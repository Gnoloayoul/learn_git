public class CounterRateLimiter extends MyRateLimiter {
    /**
     * ÿ������������
     */
    private final long permitsPerSecond;
    /**
     * ��һ�����ڵĿ�ʼʱ��
     */
    public long timestamp = System.currentTimeMillis();
    /**
     * ������
     */
    private int counter;
 
    public CounterRateLimiter(long permitsPerSecond) {
        this.permitsPerSecond = permitsPerSecond;
    }
 
    @Override
    public synchronized boolean tryAcquire() {
        long now = System.currentTimeMillis();
        // ��������������С����ֵ�����¼������У�����ܾ�����
        if (now - timestamp < 1000) {
            if (counter < permitsPerSecond) {
                counter++;
                return true;
            } else {
                return false;
            }
        }
        // ʱ�䴰�ڹ��ڣ����ü�������ʱ���
        counter = 0;
        timestamp = now;
        return true;
    }
}