#include<iostream>
using namespace std;

/*  µÝÍÆ¹«Ê½ 
	f[1]=1
	f[2]=2=f[1]+1
	f[3]=2=f[1]+1
	f[4]=4=f[1]+f[2]+1
	f[5]=4=f[1]+f[2]+1
*/

int f[1005];

int main(){
	int n;
	cin >>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i/2;j++){
			f[i] += f[j];
		}
		f[i]++;
	}
	cout << f[n];
	return 0;
}

