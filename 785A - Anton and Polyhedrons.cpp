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
	int n, result = 0;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "Tetrahedron") result += 4;
		else if (s == "Cube") result += 6;
		else if (s == "Octahedron") result += 8;
		else if (s == "Dodecahedron") result += 12;
		else result += 20;
	}
	cout << result;
	return 0;
}
