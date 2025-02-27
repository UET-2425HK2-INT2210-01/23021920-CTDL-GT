#include <iostream>
using namespace std;

int main() {
	int a[5];
	for(int i=0; i<5; i++) {
		cin >> a[i];
	}
	int min=99999,max=-99999;
	for(int i = 0; i < 5; i++) {
		if(min > a[i]) min = a[i];
		if(max < a[i]) max = a[i];

	}
	int tong= max + min;
	cout << tong;
	return 0;
}