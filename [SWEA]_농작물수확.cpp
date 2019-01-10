/*
  2차원 배열의 입력이 들어올 때
  마름모 꼴로 값을 더한 것을 구하라
  단 입력은 띄어쓰기없이 각 행마다 붙어서 입력을 받는다
  */

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		int result = 0;
		int N;
		cin >> N;
		vector<string> farm;
		for (int i = 0; i < N; i++) {
			string temp = "";
			cin >> temp;
			farm.push_back(temp);
		}

		for (int i = 0; i <= N / 2; i++) {
			for (int j = N / 2 - i; j <= N / 2 + i; j++) {
				result += farm.at(i).at(j) - '0';
				if ((2 * i) != (N - 1))
					result += farm.at(N - 1 - i).at(j) - '0';
			}
		}
		cout << "#" << test_case + 1 << " " << result << endl;
	}
	return 0;
}
