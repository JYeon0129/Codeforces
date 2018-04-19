#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;
//강의를 필기할때 언어 a와 언어 b중 짧은것을 선택하여 필기를 하였을때 결과(a,b의 결과가 같으면 a를 선호)
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
