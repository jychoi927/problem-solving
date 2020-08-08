def draw_stars(depth, idx):
    if depth == 1:
        Map[idx][idx] = '*'
        return
    l = 4 * (depth - 1) + 1
    
    for i in range(idx, l+idx):
        Map[idx][i] = '*'
        Map[idx+l-1][i] = '*'
    for i in range(idx, l+idx):
        Map[i][idx] = '*'
        Map[i][idx+l-1] = '*'
        
    draw_stars(depth-1, idx+2)
    return
    
    
n = int(input())
length = 4 * (n - 1) + 1

Map = [[' '] * length for _ in range(length)]

draw_stars(n,0)

for i in range(length):
    for j in range(length):
        print(Map[i][j], end="")
    print()