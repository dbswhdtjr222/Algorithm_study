#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <queue>

using namespace std;

int bfs(int x, int y);
int visited[101][101] = {0,};
int maze[101][101] = { 0, };
int dist[101][101] = { 0, };
int main(void)
{
	printf("%d", bfs(0, 0));
	
}
int bfs(int x, int y)//x, y는 출발 지점
{ // 미로, 방문, 거리기록 배열, 방문한 곳 표시하고,	갈 수 없는지 있는지 체크, 거리 계산
	size_t MAX_X;
	size_t MAX_Y;
	queue<pair<int, int>> q; // 좌표 값이 큐에 들어가므로
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};

	cin >> MAX_X >> MAX_Y;

	assert((MAX_X >= 2) && (MAX_Y >= 2) && (MAX_Y <= 100) && (MAX_X <= 100));
	
	for (int i = 0; i < MAX_X; i++) { // 미로 입력
		for (int j = 0; j < MAX_Y; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}
	
	size_t new_x, new_y; // 인접 노드 인덱스 접근 변수
	q.push(make_pair(x, y)); // 처음 시작 위치를 큐에 넣기
	dist[x][y] = 1; // 시작 부터 거리를 매김
	visited[x][y] = 1;

	while (!q.empty()) { // 큐가 비었을 때 멈춘다
		x = q.front().first;
		y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			new_x = x + dx[i]; // 인접 노드
			new_y = y + dy[i];

			if ((new_y >= 0 && new_y < MAX_Y)
				&& (new_x >= 0 && new_x < MAX_X)
				&& (maze[new_x][new_y] == 1)
				&& (visited[new_x][new_y] == 0)) {
				q.push(make_pair(new_x, new_y));
				dist[new_x][new_y] = dist[x][y] + 1;
				visited[new_x][new_y] = 1;
			}
		}
	}

	return dist[MAX_X - 1][MAX_Y - 1];
}
