#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;
// 리프 노드와 루트가 아닌 노드 중에 고양이가 m개 이상 연속하지 않는 길로만 가서 도착할 수 있는 식당 수

vector<vector<int>> graph; // 그래프 정보 보관
vector<vector<int>> cat;
bool *isCat;
bool *visited;

int dfs_cat(int m, int index) {
	int result = 0;
	visited[index] = false;
	if (index != 1 && graph[index].size() == 1) { // leaf node
		if (cat[index].at(0) <= m) return 1;
		else return 0;
	}
	else if (index ==1 || graph[index].size() > 1) {
		for (int i = 0; i < graph[index].size(); i++) {
			if (visited[graph[index].at(i)] && cat[graph[index].at(i)].at(0) > 0) {
				cat[graph[index].at(i)].at(0) += cat[index].at(0);
			}
			if (visited[graph[index].at(i)] && cat[graph[index].at(i)].at(0) <= m) {
				result += dfs_cat(m, graph[index].at(i));
			}
		}
	}
	return result;
}
int main() { 
	int n, m, tmp, tmp2;
	cin >> n >> m;

	graph.resize(n + 1);
	cat.resize(n + 1);
	isCat = new bool[n + 1];
	visited = new bool[n + 1];
	isCat[0] = false;
	for (int i = 1; i < n+1; i++) {
		isCat[i] = false;
		visited[i] = true;
		cin >> tmp;
		isCat[i] = tmp;
	}
	for (int i = 1; i < n; i++) {
		cin >> tmp >> tmp2;
		graph[tmp].push_back(tmp2);
		graph[tmp2].push_back(tmp);
	}
	for (int i = 1; i < n + 1; i++) {
		cat[i].push_back(0);
		if (isCat[i]) {
			cat[i].at(0) = 1;
		}
	}
	
	cout << dfs_cat(m, 1)<<endl;
	return 0;
}
