class Queue():

    def __init__(self,n):
        self.q = []
        self.head = 0
        self.nodes = n
    
    def push(self, val):
        self.q.append(val)
    
    def pop(self):
        self.head += 1
        return self.q[self.head-1]
    
    def is_dis(self, val):
        for x in self.q:
            if x == val:
                return True
            return False
    
    def disp(self):
        for i in range(self.head,len(self.q)):
            print self.q[i],

def bfs(start,adj):
    # start is a key in the dict adj
    que = Queue(len(adj))
    que.push(start)

    while not que.head==que.nodes:
        v = que.pop()
        for neigh in adj[v]:
            if not neigh in que.q:
                que.push(neigh)
        print v
    # que.disp()

if __name__ == '__main__':
    adj={'A':['B', 'C', 'E'],'B': ['A', 'E'], 'C':['A', 'D'], 'D': ['C', 'E'], 'E': ['A', 'B', 'D']}
    bfs('A',adj)