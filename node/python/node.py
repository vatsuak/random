class Node():

    def __init__(self, value=0, child=None):
        self.value = value
        self.child = child
    
    def get_child(self):
        return self.child.value
    
    
    def __str__(self):
        return (str)(self.value)

def print_till_end(start):
    if start.child == None:
        print(start.value)
        return 
    else:
        print(start.value)
        print_till_end(start.child)


if __name__ == "__main__":
    end = Node()
    mid = Node(5,end)
    start = Node(0,mid)
    print("end ",end)
    print("mid ",mid)
    print("start ",start)
    print("child of start ie mid ", start.get_child())
    print_till_end(start)
    print("end of test")
