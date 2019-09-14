class Node():
    def __init__(self, key=None):
        self.val = key
        self.left = None 
        self.right = None

    def add_left(self, child):
        self.left = child
    
    def add_right(self, child):
        self.right = child

def insert(root, node):
    if root == None:
        root = node
    if root.val > node.val:
        if root.left == None:
            root.add_left(node)
        else:
            insert(root.left, node)
    if root.val < node.val:
        if root.right == None:
            root.add_right(node)
        else:
            insert(root.right, node)

def inorder(root):
    if root != None:
        print root.val
        inorder(root.left)
        inorder(root.right)

if __name__ == '__main__':
    r = Node(50) 
    insert(r,Node(30)) 
    insert(r,Node(20)) 
    insert(r,Node(40)) 
    insert(r,Node(70)) 
    insert(r,Node(60)) 
    insert(r,Node(80)) 
    inorder(r)