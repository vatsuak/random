# #####################################################
# Island problem from amazon
# Given a 2 dimension array matrix of 0s and 1s, 
# count the number of islands of 1s. An island 
# is surrounded by a group of adjacent cells 
# that are all 1s. A cell can only be adjacent 
# to each other horizontally and vertically.
# input:  binaryMatrix = [ [0,    1,    0,    1,    0],
#                          [0,    0,    1,    1,    1],
#                          [1,    0,    0,    1,    0],
#                          [0,    1,    1,    0,    0],
#                          [1,    0,    1,    0,    1] ]
########################################################

def countIsland(arr, row, col, visited):
    ''' function that returns(1)
        if arr[row,col] is an island(1)
        and marks all the surrounding 1's as visited
        if its a zero it just returns 0
    '''
    if not isValid(arr, row, col) or visited[row][col] == 1 or arr[row][col] == 0 :
        return 0
    visited[row][col] = 1
    countIsland(arr, row+1, col, visited)
    countIsland(arr, row-1, col, visited)
    countIsland(arr, row, col+1, visited)
    countIsland(arr, row, col-1, visited)
    return 1

def isValid(arr,r,c):
    '''return if the (r,c) is a valid index'''
    if r<0 or r>len(arr)-1 or c<0 or c>len(arr[0])-1:
        return False
    return True

def main(arr):
    visited = [[0 for cols in range(len(arr[0]))] for rows in range(len(arr))]
    total_islands = 0
    for r in range(len(arr)):
        for c in range(len(arr[0])):
            total_islands += countIsland(arr, r, c, visited)
    return total_islands

if __name__ ==  '__main__':
    arr = [[0, 1, 0, 1, 0], [0, 0, 1, 1, 1], [1, 0, 0, 1, 0], [0, 1, 1, 0, 0], [1, 0, 1, 0, 1]]
    print(main(arr))



    
