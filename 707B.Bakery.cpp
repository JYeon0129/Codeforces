#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;
int graph[100001][3];
int arr[100001];
int main() {
	int n, m, k, t1;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
	}
	for (int i = 0; i < k; i++) {
		cin >> t1;
		arr[t1] = 1;
	}
	int s = -1;
	for (int i = 0; i < m; i++) {
		if (arr[graph[i][0]] + arr[graph[i][1]] == 1) {
			if (s < 0) s = graph[i][2];
			else if (s > 0 && graph[i][2] < s) s = graph[i][2];
		}
	}
	cout << s;
	//_getch();
	return 0;
}
