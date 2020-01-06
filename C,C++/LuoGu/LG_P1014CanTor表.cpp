#include <iostream>
#include <string>

using namespace std;

int n; 

int* fun(int x){
	int a[2];
	return a;
}

int main(){
	cin >> n;
	int* ans = fun(n);
	cout << ans[0] << "/" << ans[1];
	
	return 0;
}




























