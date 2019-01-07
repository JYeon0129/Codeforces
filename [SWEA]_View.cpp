#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

//좌우 2칸씩 공간이 확보되면 카운트

int main() {
	int T;
	//cin >> T;
	T = 10;
	for (int test_case = 0; test_case < T; test_case++) {
		int result = 0, N;
		int *building;
		cin >> N;
		building = new int[N];
		for (int i = 0; i < N; i++) cin >> building[i];
		
		for (int i = 2; i < N - 2; i++) {
			if ((building[i] > building[i - 1]) && (building[i] > building[i - 2])) {
				if ((building[i] > building[i + 1]) && (building[i] > building[i + 2])) {
					int max1 = max(building[i - 2], building[i - 1]);
					int max2 = max(building[i + 2], building[i + 1]);
					int max3 = max(max1, max2);
					result += building[i] - max3;
				}
			}
		}
		cout << "#" << test_case + 1 << " " << result << endl;

	}

	return 0;
}
