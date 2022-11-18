from collections import deque
import sys
input = lambda: sys.stdin.readline().rstrip()

def bfs(x, y):
	q = deque()
	q.append((x, y))
	while q:
		x, y = q.popleft()

if __name__ == '__main__':
	n = int(input())
	brd = [list(input()) for _ in range(n)]