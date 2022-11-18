from collections import deque
import sys
input = lambda: sys.stdin.readline().rstrip()

def bfs(x, y):
	q = deque()
	q.append((x, y))
	while q:
		x, y = q.popleft()
		for i in range(4):
			nx = x + dx[i]
			ny = y + dy[i]
			if 0 < nx < h and 0 < ny < w and brd[nx][ny] != '1' and visited[nx][ny] == 0:
				if brd[nx][ny] == 'E':
					print("path exist")
					return
				visited[nx][ny] = 1
				q.append((nx, ny))
	print("no path")

if __name__ == '__main__':
	h = int(input())
	brd = [list(input()) for _ in range(h)]
	w = len(brd[0])
	visited = [[0] * w for _ in range(h)]
	dx = [1, 0, -1, 0]
	dy = [0, 1, 0, -1]
	x, y = 0, 0
	for i in range(h):
		for j in range(w):
			if brd[i][j] == 'P':
				x, y = i, j
				break
		if x != y:
			break
	bfs(x, y)
