/*
  N개의 원소를 가진 수열에서 1개 이상의 원소를 선택했을 때 K가 되는
  부분 수열의 개수를 구하라
*/
#include<iostream>

using namespace std;
int dfs(int* arr, int index, int total, int N, int K) {
	total += arr[index];
	int result = 0;
	if (total == K) {
		result++;
	}
	else if (total < K) {
		for(int i = index + 1; i < N; i++)
			result += dfs(arr, i, total, N, K);
	}

	return result;
}
int main() {
	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		int result = 0;
		int N, K;
		cin >> N >> K;
		int* arr;
		arr = new int[N];
		for (int i = 0; i < N; i++) cin >> arr[i];

		for (int i = 0; i < N; i++) {
			result += dfs(arr, i, 0, N, K);
		}

		cout << "#" << test_case + 1 << " " << result << endl;
	}
	return 0;
}
