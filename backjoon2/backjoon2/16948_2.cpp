#include <iostream>
#include <cstring>
#include <queue>

#define MAX 201

using namespace std;
int bfs(int y, int x, int ey, int ex,int size);
int main(void)
{
	int x, y, ex, ey; // 행 y 열 x
	int size;
	cin >> size;
	cin >> y>> x >> ey >> ex;

	cout << bfs(y, x, ey, ex, size) << "\n";
}

int bfs(int y, int x, int ey, int ex, int size)
{
	queue<pair<int, int>> q;
	int ny = 0, nx = 0;
	int dist[MAX][MAX];
	bool visited[MAX][MAX] = {0,}; // 방문 기록
	int dy[] = { -1,1,-2,2,-1,1 };
	int dx[] = { -2,-2,0,0,2,2 };
	
	memset(dist, -1, sizeof(dist));

	q.push(make_pair(y, x)); // 행 렬
	visited[y][x] = true;
	dist[y][x] = 0;

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;

		q.pop();

		if (y == ey && x == ex) {
			break;
		}
		for (int i = 0; i < 6; i++) {
			ny = dy[i] + y;
			nx = dx[i] + x;

			if (ny < 0 || nx < 0 || ny >= size || nx >= size) {
				continue;
			}
			else if (visited[ny][nx] == false) {
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
				dist[ny][nx] = dist[y][x] + 1;
			}
		}
	}
	if (dist[ey][ex] == -1) {
		return -1;
	}
	else return dist[ey][ex];
}