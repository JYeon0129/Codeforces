#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;
vector<vector<int>> v;
int *arr;
vector<string> vresult;
bool isInclude(int a, int b[], int n) {
	for (int i = 0; i < n; i++) {
		if (a == b[i]) return false;
	}
	return true;
}
int* dfs(int index, int water) {
	int d = water;
	int *result;
	result = new int[2];
	result[0] = index;
	result[1] = d;
	if (v[index].size() > 0) {
		if (v[index].at(1) < d) d = v[index].at(1);
		v[index].at(2) = -1;
		result = dfs(v[index].at(0), d);
	}
	return result;
}
int main() {
	int n, p, a, b, d;
	int *result;
	result = new int[2];
	cin >> n >> p;
	v.resize(n + 1);
	arr = new int[p];
	for (int i = 0; i < p; i++) {
		cin >> a >> b >> d;
		v[a].push_back(b);
		v[a].push_back(d);
		v[a].push_back(0);
		arr[i] = b;
	}

	if (n == p || p ==0) {
		cout << "0";
	}
	else {
		a = 0;
		for (int i = 1; i < n + 1; i++) {
			if (v[i].size() > 0 && v[i].at(2) == 0) {
				if (isInclude(i, arr, p)) {
					result = dfs(i, INT32_MAX);
					a++;
					vresult.push_back(to_string(i)+ " " + to_string(result[0]) + " " + to_string(result[1]));
				}
			}
		}
		cout << a << endl;
		for (int i = 0; i < vresult.size(); i++)
			cout << vresult.at(i) << endl;
	}
	//_getch();
	return 0;
}
