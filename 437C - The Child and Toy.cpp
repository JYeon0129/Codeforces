#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;
// 장난감의 각 부품을 모두 제거하기 위한 최소 비용
// n개의 부품은 m개의 로프로 구성되어있다.
int **graph_toy; // 장난감 정보
int *cost;
int main() { 
	int n, m, tmp, tmp2, result = 0;
	cin >> n >> m;
	cost = new int[n + 1];
	cost[0] = 0;
	graph_toy = new int*[n + 1];
	for (int i = 0; i < n + 1; i++) { // 인접행렬 초기화
		graph_toy[i] = new int[n + 1];
		for (int j = 0; j < n + 1; j++) {
			graph_toy[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		cost[i + 1] = 0;
		cin >> cost[i+1];
	}
	for (int i = 0; i < m; i++) {
		cin >> tmp >> tmp2;
		if (cost[tmp] >= cost[tmp2]) {
			graph_toy[tmp][tmp2] = cost[tmp2];
			graph_toy[tmp2][tmp] = cost[tmp2];
		}
		else {
			graph_toy[tmp][tmp2] = cost[tmp];
			graph_toy[tmp2][tmp] = cost[tmp];
		}
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (graph_toy[i][j] != 0) {
				result += graph_toy[i][j];
				graph_toy[i][j] = graph_toy[j][i] = 0;
			}
		}
	}
	cout << result;
	return 0;
}
