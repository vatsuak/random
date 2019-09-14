class Sort():

    def __init__(self, array, order=1):
        self.arr = array   # a list 
        self.ord = order   # 1 for ascending 2 of descending
    
    def insertion(self):
        l = len(self.arr)
        for key in range(1,l):
            value = self.arr[key]
            # pairwise swaps can be replaced with binary search
            for i in range(0,key):
                if value<self.arr[i]:
                    self.arr[i],self.arr[key] = self.arr[key],self.arr[i]
    
    def printer(self):
        for i in range(len(self.arr)):
            print self.arr[i]

def main():
    a = [5,4,3,2,1]
    sorter = Sort(a)
    print 'Before Sort'
    sorter.printer()
    sorter.insertion()
    print 'After sort'
    sorter.printer()

if __name__=='__main__':
    main()
