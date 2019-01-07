/*  1. 철수는 연속된 N일 동안의 물건의 매매가를 예측하여 알고 있다.
    2. 당국의 감시망에 걸리지 않기 위해 하루에 최대 1만큼 구입할 수 있다.
    3. 판매는 얼마든지 할 수 있다.

예를 들어 3일 동안의 매매가가 1, 2, 3 이라면 처음 두 날에 원료를 구매하여 마지막 날에 팔면 3의 이익을 얻을 수 있다.
*/
#include<iostream>

using namespace std;
int find_max(int *arr, int start, int end) {
	int result = 0;
	for (int i = start; i < end; i++) {
		if (result < arr[i]) result = arr[i];
	}
	return result;
}
int main() {
	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		long long result = 0;
        int N;
		int *arr;
		cin >> N;

		arr = new int[N];
		int max = 0;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			if (max < arr[i]) {
				max = arr[i];
			}
		}

		for (int i = 0; i < N; i++) {
			if (arr[i] == max && i < N-1) {
				max = find_max(arr, i + 1, N);
			}
			else if (arr[i] < max) result += max - arr[i];
		}

		cout << "#" << test_case + 1 << " " << result << endl;
	}

	return 0;
}
