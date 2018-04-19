#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;
//참가자들을 m개의 팀으로 나눈다 각 팀은 최소 1명 이상의 참가자가 있다.
//같은 팀에 속한 참가자들은 친구가 될수있다. 친구의 최대 최소 숫자를 구하라
vector<string> note;
vector<string> result;
string short_note(string a, int m) {
	string t="",x="",y="";
	for (int i = 0; i < 2 * m; i += 2) {
		if (note.at(i) == a) {
			x = note.at(i);
			y = note.at(i + 1);
			if (x.length() > y.length()) t = y;
			else t = x;
			break;
		}
	}
	return t;
}
int main() { 
	int n, m;
	string a, b;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		note.push_back(a);
		note.push_back(b);
	}
	for (int i = 0; i < n; i++) {
		cin >> a;
		b = short_note(a,m);
		result.push_back(b);
	}
	for (int i = 0; i < result.size(); i++) cout << result.at(i) << " ";

	return 0;
}
