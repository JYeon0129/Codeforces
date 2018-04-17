#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;
//좌표 2개가 주어졌을때 정사각형을 이루는 영역을 만들수있는지 없는지를 판단
int main() {
	int x1, y1, x2, y2, x3 = 0, y3 = 0, x4 = 0, y4 = 0;
	cin >> x1 >> y1 >> x2 >> y2;
	if (x1 == x2 && y1 != y2) {
		x3 = x1 + abs(y2-y1);
		x4 = x1 + abs(y2-y1);
		y3 = y1;
		y4 = y2;
	}
	else if (x1 != x2 && y1 == y2) {
		x3 = x1;
		x4 = x2;
		y3 = y1 + abs(x2-x1);
		y4 = y1 + abs(x2-x1);
	}
	else{
		if(abs(x1-x2) == abs(y1-y2)){
			x3 = x1;
			x4 = x2;
			y3 = y2;
			y4 = y1;
		}
		else {
			cout << -1;
			return 0;
		}
	}
	cout << x3 << " " << y3 << " " << x4 << " " << y4;
	return 0;
}
