from collections import deque

def bfs(graph, root):
    visited, queue = set(), deque([root])
    visited.add(root)
    while queue:
        vertex = queue.popleft()
        print(str(vertex) + " ", end="")
        for neighbour in graph[vertex]:
            if neighbour not in visited:
                visited.add(neighbour)
                queue.append(neighbour)

def dfs(graph, root, visited=None):
    if visited is None:
        visited = set()
    visited.add(root)
    print(str(root) + " ", end="")
    for neighbour in graph[root]:
        if neighbour not in visited:
            dfs(graph, neighbour, visited)
    return visited

# Exemple d'utilisation
graph = {1: [2, 3, 4], 2: [5, 6], 3: [], 4: [7, 8], 5: [], 6: [], 7: [], 8: []}

print("BFS: ", end="")
bfs(graph, 1)

print("\nDFS: ", end="")
dfs(graph, 1)