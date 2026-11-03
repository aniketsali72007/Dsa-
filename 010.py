maze = [
    "S..#",
    ".#..",
    "...#",
    "##.G"
]

def solve(r, c, path):
    # Boundary check
    if r < 0 or c < 0 or r >= 4 or c >= 4:
        return False
    
    # Wall check or visited check
    if maze[r][c] == '#' or (r, c) in path:
        return False
        
    # Goal check
    if maze[r][c] == 'G':
        print("Path found:", path + [(r, c)])
        return True
        
    # Backtracking steps
    path.append((r, c))
    
    # Move in 4 directions: Right, Down, Left, Up
    for dr, dc in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
        if solve(r + dr, c + dc, path):
            return True
            
    path.pop() # Backtrack
    return False

# Start from the 'S' position at (0, 0)
solve(0, 0, [])
