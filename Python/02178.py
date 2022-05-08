from collections import deque

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

n, m = map(int, input().split())

maze = []
for i in range(n):
    row = input()
    rowl = []
    for j in range(m):
        rowl.append(int(row[j]))
    maze.append(rowl)
    
dist = [[0 for i in range(m)] for j in range(n)]
queue = deque([])

dist[0][0] = 1
queue.appendleft((0,0))
while(queue):
    x, y = queue.pop()
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if(nx<0 or nx>=n or ny<0 or ny>=m):
            continue
        if(maze[nx][ny] == 0):
            continue
        elif(dist[nx][ny] == 0):
            dist[nx][ny] = dist[x][y] + 1
            queue.appendleft((nx, ny))

print(dist[n-1][m-1])