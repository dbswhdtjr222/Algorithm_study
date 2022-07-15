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
int bfs(int x, int y)//x, y�� ��� ����
{ // �̷�, �湮, �Ÿ���� �迭, �湮�� �� ǥ���ϰ�,	�� �� ������ �ִ��� üũ, �Ÿ� ���
	size_t MAX_X;
	size_t MAX_Y;
	queue<pair<int, int>> q; // ��ǥ ���� ť�� ���Ƿ�
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};

	cin >> MAX_X >> MAX_Y;

	assert((MAX_X >= 2) && (MAX_Y >= 2) && (MAX_Y <= 100) && (MAX_X <= 100));
	
	for (int i = 0; i < MAX_X; i++) { // �̷� �Է�
		for (int j = 0; j < MAX_Y; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}
	
	size_t new_x, new_y; // ���� ��� �ε��� ���� ����
	q.push(make_pair(x, y)); // ó�� ���� ��ġ�� ť�� �ֱ�
	dist[x][y] = 1; // ���� ���� �Ÿ��� �ű�
	visited[x][y] = 1;

	while (!q.empty()) { // ť�� ����� �� �����
		x = q.front().first;
		y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			new_x = x + dx[i]; // ���� ���
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
