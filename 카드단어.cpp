/*
N장의 카드가 놓여져 있는데, 이를 순서대로 선택하여 단어를 만들려고 한다. 단어를 만들 때는 선택한 카드를 이미 선택된 카드들의 제일 왼쪽 또는 오른쪽에만 위치시킬 수 있다.

예를 들어 3장의 카드가 E, O, T 순으로 놓여져 있다고 하자. 순서대로 선택하므로 E를 먼저 선택하고 두번째 O를 E의 왼쪽에 붙일 경우 OE, E의 오른쪽에 붙일 경우 EO가 된다. 세번째 T를 OE의 왼쪽에 붙일 경우 TOE, OE의 오른쪽에 붙일 경우 OET, EO의 왼쪽에 붙일 경우 TEO, EO의 오른쪽에 붙일 경우 EOT라는 단어를 만들 수 있다. 3장의 카드로 만들어진 단어 TOE, OET, TEO, EOT 중에서 사전순으로 가장 느린 단어는 TOE가 된다.

대문자 알파벳이 적힌 N장의 카드가 순서대로 주어질 때, 만들 수 있는 단어 중 가장 사전순으로 느린 단어를 출력하는 프로그램을 작성하시오.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		//if (test_case > 24) return 0;
		int N;
		string result = "";
		vector<int> vec;
		// Input
		cin >> N;
		char ch;
		for (int i = 0; i < N; i++) {
			cin >> ch;
			int temp = ch - 'A';
			vec.push_back(temp);
		}

		// search
		for (int i = 0; i < N; i++) {
			char c = (char)(vec.at(i) + 'A');
			
			if (i == 0) result += c;
			else if (result.at(0) - 'A' > vec.at(i)) result += c;
			else result = c + result;
		}
		//output

		cout << "#" << test_case + 1 << " " << result << endl;

	}

	return 0;
}
