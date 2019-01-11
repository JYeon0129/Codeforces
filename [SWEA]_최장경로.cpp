/* 그래프에서 사이클이 없는 최장 경로를 찾기 */

#include<iostream>
#include<string.h>
using namespace std;
int map[11][11];
int visited[11];
int N, M, max_distance;

void dfs(int start, int distance) {
	visited[start] = 1;
	if (max_distance < distance) max_distance = distance;

	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0 && map[start][i] == 1){
			dfs(i, distance + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		int result = 0;
		cin >> N >> M;

		if (M == 0) {
			cout << "#" << test_case + 1 << " " << 1 << endl;
			continue;
		}

		int x, y;

		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));
		max_distance = 0;

		for (int i = 0; i < M; i++) {
			cin >> x >> y;
			map[x][y] = 1;
			map[y][x] = 1;
		}

		for (int i = 1; i <= N; i++) {
			memset(visited, 0, sizeof(visited));
			dfs(i, 1);
		}

		cout << "#" << test_case + 1 << " " << max_distance << endl;
	}
	return 0;
}
