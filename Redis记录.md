# 安装<br>
$ redis-server<br>
13166:C 08 May 2022 18:59:59.859 # oO0OoO0OoO0Oo Redis is starting oO0OoO0OoO0Oo<br>
13166:C 08 May 2022 18:59:59.859 # Redis version=5.0.7, bits=64, commit=00000000, modified=0, pid=13166, just started<br>
13166:C 08 May 2022 18:59:59.859 # Warning: no config file specified, using the default config. In order to specify a config file use redis-server /path/to/redis.conf<br>
13166:M 08 May 2022 18:59:59.860 * Increased maximum number of open files to 10032 (it was originally set to 1024).<br>
13166:M 08 May 2022 18:59:59.860 # Could not create server TCP listening socket *:6379: bind: Address already in use<br>

$ redis-cli<br>
127.0.0.1:6379> ping<br>
PONG<br>
127.0.0.1:6379> <br>

【到这， redis成功安装 2022年5月8日】<br>

# 任务<br>
## 1.使用 redis benchmark 工具, 测试 10 20 50 100 200 1k 5k 字节 value 大小，redis get set 性能。<br>

### 测试10字节<br>

$ sudo redis-benchmark -d 10 -t GET,SET<br>
====== SET ======<br>
  100000 requests completed in 1.80 seconds<br>
  50 parallel clients<br>
  10 bytes payload<br>
  keep alive: 1<br>

96.80% <= 1 milliseconds<br>
99.07% <= 2 milliseconds<br>
99.54% <= 3 milliseconds<br>
99.76% <= 4 milliseconds<br>
99.89% <= 5 milliseconds<br>
99.95% <= 6 milliseconds<br>
99.95% <= 8 milliseconds<br>
100.00% <= 9 milliseconds<br>
55432.37 requests per second<br>

====== GET ======<br>
  100000 requests completed in 1.88 seconds<br>
  50 parallel clients<br>
  10 bytes payload<br>
  keep alive: 1<br>

95.29% <= 1 milliseconds<br>
97.80% <= 2 milliseconds<br>
99.37% <= 3 milliseconds<br>
99.73% <= 4 milliseconds<br>
99.93% <= 5 milliseconds<br>
99.95% <= 7 milliseconds<br>
100.00% <= 8 milliseconds<br>
100.00% <= 8 milliseconds<br>
53106.74 requests per second<br>

### 测试20字节<br>

$ sudo redis-benchmark -d 20 -t GET,SET<br>
====== SET ======<br>
  100000 requests completed in 1.81 seconds<br>
  50 parallel clients<br>
  20 bytes payload<br>
  keep alive: 1<br>

97.25% <= 1 milliseconds<br>
99.50% <= 2 milliseconds<br>
99.74% <= 3 milliseconds<br>
99.89% <= 4 milliseconds<br>
99.96% <= 5 milliseconds<br>
100.00% <= 5 milliseconds<br>
55279.16 requests per second<br>

====== GET ======<br>
  100000 requests completed in 1.88 seconds<br>
  50 parallel clients<br>
  20 bytes payload<br>
  keep alive: 1<br>

92.54% <= 1 milliseconds<br>
99.20% <= 2 milliseconds<br>
99.72% <= 3 milliseconds<br>
99.83% <= 4 milliseconds<br>
99.94% <= 5 milliseconds<br>
99.95% <= 6 milliseconds<br>
99.95% <= 7 milliseconds<br>
99.96% <= 12 milliseconds<br>
99.97% <= 13 milliseconds<br>
100.00% <= 13 milliseconds<br>
53304.90 requests per second<br>

### 测试50字节<br>

$ sudo redis-benchmark -d 50 -t GET,SET<br>
====== SET ======<br>
  100000 requests completed in 2.03 seconds<br>
  50 parallel clients<br>
  50 bytes payload<br>
  keep alive: 1<br>

91.77% <= 1 milliseconds<br>
96.94% <= 2 milliseconds<br>
98.70% <= 3 milliseconds<br>
99.31% <= 4 milliseconds<br>
99.57% <= 5 milliseconds<br>
99.66% <= 6 milliseconds<br>
99.82% <= 7 milliseconds<br>
99.90% <= 8 milliseconds<br>
99.92% <= 9 milliseconds<br>
99.95% <= 10 milliseconds<br>
99.95% <= 11 milliseconds<br>
100.00% <= 12 milliseconds<br>
49358.34 requests per second<br>

====== GET ======<br>
  100000 requests completed in 1.99 seconds<br>
  50 parallel clients<br>
  50 bytes payload<br>
  keep alive: 1<br>

90.65% <= 1 milliseconds<br>
96.82% <= 2 milliseconds<br>
99.06% <= 3 milliseconds<br>
99.57% <= 4 milliseconds<br>
99.78% <= 5 milliseconds<br>
99.87% <= 6 milliseconds<br>
100.00% <= 7 milliseconds<br>
50251.26 requests per second<br>

### 测试100字节<br>

$ sudo redis-benchmark -d 100 -t GET,SET<br>
====== SET ======<br>
  100000 requests completed in 1.78 seconds<br>
  50 parallel clients<br>
  100 bytes payload<br>
  keep alive: 1<br>

97.02% <= 1 milliseconds<br>
99.63% <= 2 milliseconds<br>
99.81% <= 3 milliseconds<br>
99.93% <= 4 milliseconds<br>
99.95% <= 5 milliseconds<br>
99.98% <= 6 milliseconds<br>
100.00% <= 6 milliseconds<br>
56306.30 requests per second<br>

====== GET ======<br>
  100000 requests completed in 1.81 seconds<br>
  50 parallel clients<br>
  100 bytes payload<br>
  keep alive: 1<br>

96.48% <= 1 milliseconds<br>
98.84% <= 2 milliseconds<br>
99.33% <= 3 milliseconds<br>
99.68% <= 4 milliseconds<br>
99.95% <= 5 milliseconds<br>
99.97% <= 6 milliseconds<br>
100.00% <= 6 milliseconds<br>
55157.20 requests per second<br>

### 测试200字节<br>

$ sudo redis-benchmark -d 200 -t GET,SET<br>
====== SET ======<br>
  100000 requests completed in 1.90 seconds<br>
  50 parallel clients<br>
  200 bytes payload<br>
  keep alive: 1<br>

95.03% <= 1 milliseconds<br>
98.47% <= 2 milliseconds<br>
99.33% <= 3 milliseconds<br>
99.74% <= 4 milliseconds<br>
99.87% <= 5 milliseconds<br>
99.94% <= 6 milliseconds<br>
99.95% <= 7 milliseconds<br>
99.97% <= 8 milliseconds<br>
100.00% <= 8 milliseconds<br>
52687.04 requests per second<br>

====== GET ======<br>
  100000 requests completed in 1.87 seconds<br>
  50 parallel clients<br>
  200 bytes payload<br>
  keep alive: 1<br>

97.29% <= 1 milliseconds<br>
99.14% <= 2 milliseconds<br>
99.54% <= 3 milliseconds<br>
99.72% <= 4 milliseconds<br>
99.86% <= 5 milliseconds<br>
99.99% <= 6 milliseconds<br>
99.99% <= 7 milliseconds<br>
100.00% <= 7 milliseconds<br>
53590.57 requests per second<br>

### 测试1k字节<br>

$ sudo redis-benchmark -d 1000 -t GET,SET<br>
====== SET ======<br>
  100000 requests completed in 1.84 seconds<br>
  50 parallel clients<br>
  1000 bytes payload<br>
  keep alive: 1<br>

95.22% <= 1 milliseconds<br>
99.25% <= 2 milliseconds<br>
99.65% <= 3 milliseconds<br>
99.89% <= 4 milliseconds<br>
99.99% <= 5 milliseconds<br>
100.00% <= 5 milliseconds<br>
54406.96 requests per second<br>

====== GET ======<br>
  100000 requests completed in 2.01 seconds<br>
  50 parallel clients<br>
  1000 bytes payload<br>
  keep alive: 1<br>

95.55% <= 1 milliseconds<br>
97.66% <= 2 milliseconds<br>
98.77% <= 3 milliseconds<br>
99.47% <= 4 milliseconds<br>
99.74% <= 5 milliseconds<br>
99.92% <= 6 milliseconds<br>
99.99% <= 7 milliseconds<br>
100.00% <= 7 milliseconds<br>
49701.79 requests per second<br>

### 测试5k字节<br>

$ sudo redis-benchmark -d 5000 -t GET,SET<br>
====== SET ======<br>
  100000 requests completed in 2.17 seconds<br>
  50 parallel clients<br>
  5000 bytes payload<br>
  keep alive: 1<br>

84.20% <= 1 milliseconds<br>
94.37% <= 2 milliseconds<br>
98.59% <= 3 milliseconds<br>
99.29% <= 4 milliseconds<br>
99.76% <= 5 milliseconds<br>
99.86% <= 6 milliseconds<br>
99.97% <= 7 milliseconds<br>
100.00% <= 7 milliseconds<br>
46146.75 requests per second<br>

====== GET ======<br>
  100000 requests completed in 2.17 seconds<br>
  50 parallel clients<br>
  5000 bytes payload<br>
  keep alive: 1<br>

93.88% <= 1 milliseconds<br>
98.84% <= 2 milliseconds<br>
99.42% <= 3 milliseconds<br>
99.77% <= 4 milliseconds<br>
99.94% <= 5 milliseconds<br>
99.99% <= 6 milliseconds<br>
100.00% <= 6 milliseconds<br>
46125.46 requests per second<br>



## 2.写入一定量的 kv 数据, 根据数据大小 1w-50w 自己评估, 结合写入前后的 info memory 信息 , 分析上述不同 value 大小下，平均每个 key 的占用内存空间。<br>

$ sudo redis-benchmark -d 3000 -n 5000000 -t GET,SET<br>
====== SET ======<br>
  5000000 requests completed in 95.02 seconds<br>
  50 parallel clients<br>
  3000 bytes payload<br>
  keep alive: 1<br>

91.86% <= 1 milliseconds<br>
97.93% <= 2 milliseconds<br>
99.33% <= 3 milliseconds<br>
99.69% <= 4 milliseconds<br>
99.89% <= 5 milliseconds<br>
99.95% <= 6 milliseconds<br>
99.97% <= 7 milliseconds<br>
99.98% <= 8 milliseconds<br>
99.99% <= 9 milliseconds<br>
100.00% <= 10 milliseconds<br>
100.00% <= 11 milliseconds<br>
100.00% <= 12 milliseconds<br>
100.00% <= 13 milliseconds<br>
100.00% <= 13 milliseconds<br>
52619.95 requests per second<br>

====== GET ======<br>
  5000000 requests completed in 103.61 seconds<br>
  50 parallel clients<br>
  3000 bytes payload<br>
  keep alive: 1<br>

94.32% <= 1 milliseconds<br>
97.87% <= 2 milliseconds<br>
99.30% <= 3 milliseconds<br>
99.65% <= 4 milliseconds<br>
99.85% <= 5 milliseconds<br>
99.93% <= 6 milliseconds<br>
99.96% <= 7 milliseconds<br>
99.97% <= 8 milliseconds<br>
99.99% <= 9 milliseconds<br>
99.99% <= 10 milliseconds<br>
100.00% <= 11 milliseconds<br>
100.00% <= 11 milliseconds<br>
48255.56 requests per second<br>


$ sudo redis-benchmark -d 3000 -r 10000  -n 5000000 -t GET,SET<br>
====== SET ======<br>
  5000000 requests completed in 97.80 seconds<br>
  50 parallel clients<br>
  3000 bytes payload<br>
  keep alive: 1<br>

88.18% <= 1 milliseconds<br>
97.56% <= 2 milliseconds<br>
99.30% <= 3 milliseconds<br>
99.67% <= 4 milliseconds<br>
99.86% <= 5 milliseconds<br>
99.93% <= 6 milliseconds<br>
99.96% <= 7 milliseconds<br>
99.97% <= 8 milliseconds<br>
99.99% <= 9 milliseconds<br>
99.99% <= 10 milliseconds<br>
100.00% <= 11 milliseconds<br>
100.00% <= 12 milliseconds<br>
100.00% <= 12 milliseconds<br>
51123.18 requests per second<br>

====== GET ======<br>
  5000000 requests completed in 104.59 seconds<br>
  50 parallel clients<br>
  3000 bytes payload<br>
  keep alive: 1<br>

93.12% <= 1 milliseconds<br>
97.77% <= 2 milliseconds<br>
99.32% <= 3 milliseconds<br>
99.66% <= 4 milliseconds<br>
99.84% <= 5 milliseconds<br>
99.91% <= 6 milliseconds<br>
99.95% <= 7 milliseconds<br>
99.97% <= 8 milliseconds<br>
99.98% <= 9 milliseconds<br>
99.99% <= 10 milliseconds<br>
100.00% <= 11 milliseconds<br>
100.00% <= 12 milliseconds<br>
100.00% <= 13 milliseconds<br>
100.00% <= 13 milliseconds<br>
47805.72 requests per second<br>
