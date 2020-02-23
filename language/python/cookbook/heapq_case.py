# 1.5 实现一个优先级队列
import heapq

class Item:
    def __init__(self, name):
        self.name = name
    def __str__(self):
        return self.name

class PriorityQueue:
    def __init__(self):
        self.data = []
        self.index = 0
    def push(self, item, priority):
        heapq.heappush(self.data, (priority, self.index, item))
        self.index += 1
    def pop(self):
        return heapq.heappop(self.data)[-1]
    
def useQueue():
    q = PriorityQueue()
    q.push(Item("first"), 1)
    q.push(Item("second"), 2)
    q.push(Item("third"), 3)
    q.push(Item("forth3"), 4)
    q.push(Item("forth2"), 4)
    print(q.pop())
    print(q.pop())
    print(q.pop())
    print(q.pop())
    print(q.pop())

if __name__ == "__main__":
    useQueue()