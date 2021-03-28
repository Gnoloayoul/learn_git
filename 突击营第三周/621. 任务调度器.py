from collections import Counter
import heapq
class Solution(object):
    def leastInterval(self,tasks,n):
        data = Counter(tasks)
        hq = [-c for c in data.values()]
        heapq.heapify(hq)
        maxValues = -heapq.heappop(hq)-1
        idleSlotes = maxValues*n
        while hq:
            value = -heapq.heappop(hq)
            idleSlotes -= min(maxValues,value)

        return idleSlotes+len(tasks) if idleSlotes > 0 else len(tasks)