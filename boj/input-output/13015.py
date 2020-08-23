def draw_first_and_last(n, a):
    for i in range(1, n*2+a+1):
        if i <= n or i > n+a:
            print('*', end="")
        else:
            print(' ', end="")
    print("")
    
def draw_star(n):
    print('*'*n, end="")

def draw_space(n):
    print(' '*n, end="")
    
    
n = int(input())
a = n * 2 - 3

draw_first_and_last(n,a)
for i in range(1,n):
    draw_space(i)
    draw_star(1)
    draw_space(n-2)
    draw_star(1)
    
    if i != n-1:
        draw_space(a-(i*2))
        draw_star(1)
        
    draw_space(n-2)
    draw_star(1)
    print("")

    
for i in range(n-2,0,-1):
    draw_space(i)
    draw_star(1)
    draw_space(n-2)
    draw_star(1)
    draw_space(a-(i*2))
    draw_star(1)
    draw_space(n-2)
    draw_star(1)
    print("")
    
draw_first_and_last(n,a)