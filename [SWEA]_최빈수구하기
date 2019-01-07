//빈도수가 제일 적은 수 구하기

#include<iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		int result = 0, N;
		int student[101];
		for (int i = 0; i < 101; i++) {
			student[i] = 0;
		}
		cin >> N;
		int temp = 0;
		for (int i = 0; i < 1000; i++) {
			cin >> temp;
			student[temp]++;
		}
		int c = 0;
		for (int i = 0; i < 101; i++) {
			if (c <= student[i]) {
				c = student[i];
				result = i;
			}
		}
		cout << "#" << test_case + 1 << " " << result << endl;
	}

	return 0;
}
