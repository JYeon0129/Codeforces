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
	int n1, n2, k1, k2;
	cin >> n1 >> n2 >> k1 >> k2;
	if (n1 > n2) {
		cout << "First";
	}
	
	else if (n1 <= n2) {
		cout << "Second";
	}
	
	return 0;
}
