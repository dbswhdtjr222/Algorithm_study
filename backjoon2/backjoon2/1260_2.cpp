#include <iostream>
#include <assert.h>
#include <queue>
#define MAX 1001

using namespace std;

size_t n, m, v; //n 정점 개수 노드의 개수, 간선의 개수 노드와 연결된 선들의 개수, 탐색을 시작할	노드의 번호
int map[MAX][MAX] = { 0, };
bool visit[MAX];

void dfs(int v);
void bfs(int v);
void reset_visit();

int main(void)
{
	//bfs dfs
	size_t a, b;
	cin >> n >> m >> v;
	assert((n >= 1 && n <= 1000) && (m >= 1 && m < 10000));
	for (int i = 0; i < m; i++) { // 연결된 노드 표시
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	reset_visit();
	dfs(v);
	cout << "\n";
	reset_visit();
	bfs(v);
}
void dfs(int v)
{
	visit[v] = true;
	cout << v << " ";
	for (int i = 1; i <= n; i++) {
		if (map[v][i] == 1 && visit[i] == false) {
			dfs(i); //재귀
		}
	}
}
void bfs(int v)
{
	queue<int> q;
	visit[v] = true;
	q.push(v);
	cout << v << " ";

	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (map[v][i] == 1 && visit[i] == false) {
				q.push(i);
				visit[i] = true;
				cout << i << " ";
			}
		}
	}
}
void reset_visit()
{
	for (int i = 0; i < m; i++) {
		visit[i] = 0;
	}
}