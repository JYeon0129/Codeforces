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
	char tmp; 
	int result = 0;
	for (int i = 0; i < 64; i++) {
		cin >> tmp;
		if (tmp == 'Q') result += 9;
		if (tmp == 'R') result += 5;
		if (tmp == 'B') result += 3;
		if (tmp == 'N') result += 3;
		if (tmp == 'P') result += 1;
		if (tmp == 'q') result -= 9;
		if (tmp == 'r') result -= 5;
		if (tmp == 'b') result -= 3;
		if (tmp == 'n') result -= 3;
		if (tmp == 'p') result -= 1;
	}
	if (result > 0)cout << "White";
	else if (result == 0)cout << "Draw";
	else cout << "Black";
	
	//_getch();
	return 0;
}