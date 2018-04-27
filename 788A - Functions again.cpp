#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;
int n, tmp;
vector<__int64> v;
vector<__int64> diff;
__int64 *result;
int main(){
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
		if (i > 0) {
			diff.push_back(abs(v.at(i) - v.at(i - 1)));
		}
	}
	result = new __int64[n];
	result[0] = 0;
	__int64 maxi = -1, mini = 0;
	for (int i = 1; i < n; i++) {
		if (i % 2 == 1) result[i] = result[i-1]+diff.at(i - 1);
		else result[i] = result[i - 1] - diff.at(i - 1);
		if (maxi < result[i]) maxi = result[i];
		if (mini > result[i]) mini = result[i];
	}
	cout << abs(maxi - mini);
	return 0;
}
