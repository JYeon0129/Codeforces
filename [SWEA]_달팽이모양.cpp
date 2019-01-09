/*배열에 달팽이모양으로 숫자 채워넣기*/
#include<iostream>
using namespace std;

int** snail(int**arr, int limit, int start_index, int start_num) {
	if (limit < 0) return arr;
	if (limit == 0) arr[start_index][start_index] = start_num;
	int num = start_num;
	for (int i = 0; i < limit; i++) {
		arr[start_index][start_index + i] = num;
		num++;
	}

	for (int i = 0; i < limit; i++) {
		arr[start_index + i][start_index + limit] = num;
		num++;
	}

	for (int i = limit; i > 0; i--) {
		arr[start_index+ limit][start_index + i] = num;
		num++;
	}

	for (int i = limit; i > 0; i--) {
		arr[start_index + i][start_index] = num;
		num++;
	}

	if (limit > 0) arr = snail(arr, limit - 2, start_index + 1, num);
	return arr;
}

int main() {
	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		int result = 0;
		int **arr;
		int N;
		cin >> N;
		arr = new int*[N];
		for (int i = 0; i < N; i++) {
			arr[i] = new int[N];
			for (int j = 0; j < N; j++) arr[i][j] = 0;
		}
		
		arr = snail(arr, N - 1, 0, 1);

		cout << "#" << test_case + 1 << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
