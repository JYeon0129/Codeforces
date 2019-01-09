/*
주어진 N번 동안 평탄화 작업을 수행한다
1번 작업동안 가장 큰 수는 -1을 가장 작은 수는 +1을 하고
만약 더이상 평탄화 할 수 없는 상황(모두 같거나 모두 1밖에 차이 안날경우)엔 그냥 리턴
횟수가 다하면 
*/

#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int T = 10;
	//cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		int result = 0;
		int arr[100] = {0};
		int N = 0;
		cin >> N;
		for (int i = 0; i < 100; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + 100);

		for (int i = 0; i < N; i++) {
			arr[99]--;
			arr[0]++;
			if (arr[99] < arr[98]) {
				int t1 = arr[99];
				for (int j = 98; j > 1; j--) {
					if (arr[j] <= t1) {
						arr[99] = arr[j + 1];
						arr[j + 1] = t1;
						break;
					}
				}
			}
			if (arr[0] > arr[1]) {
				int t2 = arr[0];
				for (int j = 1; j < 98; j++) {
					if (arr[j] >= t2) {
						arr[0] = arr[j - 1];
						arr[j - 1] = t2;
						break;
					}
				}
			}

			if (arr[99] - arr[0] <= 1) break;
		}
		result = arr[99] - arr[0];
		cout << "#" << test_case + 1 << " " << result << endl;
	}

	return 0;
}
