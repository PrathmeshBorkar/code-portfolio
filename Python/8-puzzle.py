import heapq
import copy

class PuzzleNode:
    def __init__(self, state, parent, move, depth, cost):
        self.state = state
        self.parent = parent
        self.move = move
        self.depth = depth
        self.cost = cost

    def __lt__(self, other):
        return self.cost < other.cost

def get_blank_pos(state):
    for i in range(3):
        for j in range(3):
            if state[i][j] == 0:
                return i, j

def manhattan_distance(state, goal):
    dist = 0
    for i in range(3):
        for j in range(3):
            val = state[i][j]
            if val != 0:
                for x in range(3):
                    for y in range(3):
                        if goal[x][y] == val:
                            dist += abs(i - x) + abs(j - y)
    return dist

def get_neighbors(node, goal):
    neighbors = []
    x, y = get_blank_pos(node.state)
    moves = {'Up': (x-1, y), 'Down': (x+1, y), 'Left': (x, y-1), 'Right': (x, y+1)}
    
    for move, (nx, ny) in moves.items():
        if 0 <= nx < 3 and 0 <= ny < 3:
            new_state = copy.deepcopy(node.state)
            new_state[x][y], new_state[nx][ny] = new_state[nx][ny], new_state[x][y]
            new_depth = node.depth + 1
            new_cost = new_depth + manhattan_distance(new_state, goal)
            neighbors.append(PuzzleNode(new_state, node, move, new_depth, new_cost))
            
    return neighbors

def solve_a_star(start, goal):
    open_list = []
    closed_set = set()
    
    start_node = PuzzleNode(start, None, None, 0, manhattan_distance(start, goal))
    heapq.heappush(open_list, start_node)
    
    while open_list:
        current = heapq.heappop(open_list)
        state_tuple = tuple(map(tuple, current.state))
        
        if current.state == goal:
            path = []
            while current.parent:
                path.append((current.move, current.state))
                current = current.parent
            return path[::-1] 
            
        closed_set.add(state_tuple)
        
        for neighbor in get_neighbors(current, goal):
            neighbor_tuple = tuple(map(tuple, neighbor.state))
            if neighbor_tuple not in closed_set:
                heapq.heappush(open_list, neighbor)
                
    return None

if __name__ == "__main__":
    start_state = [[1, 2, 3], [4, 0, 5], [7, 8, 6]]
    goal_state = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]
    
    solution = solve_a_star(start_state, goal_state)
    
    print("Start State:")
    for row in start_state: print(row)
    print("\n--- Sequence of Moves ---")
    
    if solution:
        for step, (move, state) in enumerate(solution, 1):
            print(f"\nStep {step}: Move Blank {move}")
            for row in state: print(row)
        print(f"\nTotal steps to reach goal: {len(solution)}")
    else:
        print("No solution found.")
        