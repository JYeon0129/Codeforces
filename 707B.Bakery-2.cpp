#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;

int *arr;
vector<vector<int>> v;
vector<vector<int>> v2;
int main() {
	int n, m, k, t1,t2,t3;
	cin >> n >> m >> k;
	arr = new int[k];
	g = new int[n + 1];
	g2 = new int[n + 1];
	v.resize(n + 1);
	v2.resize(n + 1);

	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2 >> t3;
		v[t1].push_back(t3);
		v[t2].push_back(t3);
		v2[t1].push_back(t2);
		v2[t2].push_back(t1);
	}
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < v2[arr[i]].size(); j++) {
			for (int l = 0; l < k; l++) {
				if (v2[arr[i]].at(j) == arr[l]) v[arr[i]].at(j) = 0;
			}
		}
	}

	int gmin = -1;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < v[arr[i]].size(); j++) {
			if (gmin > 0 && v[arr[i]].at(j) < gmin && v[arr[i]].at(j) > 0) {
				gmin = v[arr[i]].at(j);
			}
			else if (gmin < 0 && v[arr[i]].at(j) > 0) gmin = v[arr[i]].at(j);
		}
	}
	cout << gmin;
	//_getch();
	return 0;
}
