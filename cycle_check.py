lvl=4
def dfs(adj,s,visited,level,lvl):
    for child in adj[s]:
        if not visited[child]:
            dfs(adj,child,visited,level,lvl)
    visited[s]=1
    level[s]=lvl
    lvl -= 1

def canFinish(numCourses, prerequisites):
        # define the adjacency matrix
        adj = {i:[] for i in range(numCourses)}
        for x,y in prerequisites:
            adj[y].append(x)
        visited = {i:0 for i in range(numCourses)}
        level = {i:0 for i in range(numCourses)}
        for i in range(numCourses):
            if not visited[i]:
                dfs(adj,i,visited,level,lvl)
        return visited, adj, level

if __name__ == '__main__':
    print(canFinish(4, [[1,0],[2,0],[3,1],[3,2]]))
