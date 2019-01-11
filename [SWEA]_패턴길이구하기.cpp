/*
  문자열에서 반복되는 마디의 길이를 구한다
  (아마 같은 문자가 연속해서 입력되진않는듯)
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		int result = 0;
		string p = "";
		vector<char> buf;
		cin >> p;

		buf.push_back(p.at(0));
		for (int i = 1; i < p.length(); i++) {
			if (buf.at(0) == p.at(i)) { // check word
				int check = 0;
				for (int j = 0; j < buf.size(); j++) {
					if (buf.at(j) == p.at(i + j)) check++;
				}
				if (check == buf.size()) break;
				else buf.push_back(p.at(i));
			}
			else {
				buf.push_back(p.at(i));
			}
		}
		result = buf.size();
		cout << "#" << test_case << " " << result << endl;
	}
	return 0;
}
