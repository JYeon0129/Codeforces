#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;

int main() {
	int n, c, tmp1, tmp2 = 0, cnt = 1;
	cin >> n >> c >> tmp1;
	for(int i = 1; i < n; i++) {
		tmp2 = tmp1;
		cin >> tmp1;
		if (tmp1 - tmp2 > c) cnt = 1;
		else if (tmp1 - tmp2 <= c) cnt++;
	}
	cout << cnt << endl;
	return 0;
}
