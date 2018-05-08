#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
using namespace std;
int *arr;
int *arr2;
int main() {
	int n, m = 0, now = 0;
	cin >> n;
	arr = new int[n];
	arr2 = new int[n];
	arr2[0] = 0;
	cin >> arr[0];
	for (int i = 1; i < n; i++) {
		cin >> arr[i];
		arr2[i] = 0;

	}
	for (int i = 0; i < n; i++) {
		now = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] > now && arr[i] > arr[j]) {
				arr2[i]++;
				now = arr[j];
			}
		}
		for (int j = i; j < n; j++) {
			if (arr[j] > now) {
				arr2[i]++;
				now = arr[j];
			}
		}
		if (arr2[i] > m) m = arr2[i];
	}
	cout << m;
	return 0;
}
