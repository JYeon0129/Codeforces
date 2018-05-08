#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
using namespace std;
int arr[500001];

int cnt(int num) {
	int r = 0;
	for (int i = 1; i < num; i++) {
		r += i;
	}
	return r;
}
int main() {
	int n, tmp, result = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		arr[tmp]++;
	}

	for (int i = 1; i < 500001; i++) {
		if (arr[i] >= 2) {
			result += cnt(arr[i]);
		}
	}
	cout << result;
	return 0;
}
