#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;
// 두개의 문자열이 들어오고
// 두번째 문자열에서 ?가 들어오면 0.5확률로 +나 -로 결정된다.
// 두번째 문자열이 첫번째 문자열이 될 확률을 구하라
int combi(int a, int b) {
	int t1 = 1, t2 = 1;

	for (int i = a-b+1; i <= a; i++) {
		t1 *= i;
	}
	for (int i = 1; i <= b; i++) {
		t2 *= i;
	}
	return t1 / t2;
}
int main() {
	string s1, s2;
	double s1_p = 0, s1_m = 0, s2_p = 0, s2_m = 0;
	double a1 = 0.0, a2 = 0.0, q = 0.0, result = 0.0, tmp = 0.0;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); i++) {
		if (s1.at(i) == '+') s1_p++;
		else s1_m--;

		if (s2.at(i) == '+') s2_p++;
		else if(s2.at(i) == '-') s2_m--;
		else if (s2.at(i) == '?') q++;
	}
	a1 = s1_p + s1_m;
	a2 = s2_p + s2_m;
	if (q == 0 && s1_p == s2_p) result = 1.0;
	else if (q > 0) {
		tmp = abs(a1 - a2);
		if (tmp <= q) {
			result = combi(q,s1_p-s2_p) / pow(2, q);
		}
	}
	cout.setf(ios::fixed);
	cout.precision(12);
	cout << result;
	return 0;
}
