#include <iostream>
#include <assert.h>
#include <queue>
#define MAX 1001

using namespace std;

size_t n, m, v; //n ���� ���� ����� ����, ������ ���� ���� ����� ������ ����, Ž���� ������	����� ��ȣ
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
	for (int i = 0; i < m; i++) { // ����� ��� ǥ��
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
			dfs(i); //���
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