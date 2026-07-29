# Graph representation
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
}

# BFS with target node
def bfs(graph, start, target):
    visited = []
    queue = [start]

    while queue:
        node = queue.pop(0)
        
        if node not in visited:
            visited.append(node)
            
            if node == target:
                break
                
            for neighbor in graph[node]:
                queue.append(neighbor)
                
    return visited

# DFS with target node
def dfs(graph, start, target, visited=None):
    if visited is None:
        visited = []

    visited.append(start)

    if start == target:
        return visited

    for neighbor in graph[start]:
        if neighbor not in visited:
            if target in visited:
                break
            dfs(graph, neighbor, target, visited)

    return visited

start_node = input("Enter start node: ").strip().upper()
target_node = input("Enter target node: ").strip().upper()

print("BFS Path:", bfs(graph, start_node, target_node))
print("DFS Path:", dfs(graph, start_node, target_node))