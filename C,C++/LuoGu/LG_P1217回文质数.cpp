#include <iostream>
#include <string>

using namespace std;

int a, b; 
bool ss_book[10000001];

bool make_ss(){
	ss_book[0]=ss_book[1] = 1;
	for(int i=0;i<=10000000;i++){
		if(ss_book[i]==0){
			for(int j=i+i;j<=10000000;j+=i){
				ss_book[j] = 1;
			}
		}
	}
}


bool huiwen(int x){
	int temp=x,num=0;
	while(temp){
		num = num*10 + temp %10;
		temp /= 10;
	}
	if(num == x){
		return true;
	}else{
		return false;
	}
}

void fun(int x){
	if(huiwen(x) && !ss_book[x]){
		cout << x <<endl;
	}
}

int main(){
	
	cin >>a >> b;
	if(b > 10000000){  // 玄学说  没有偶数位的回文数 
		b=9999999;
	}
	make_ss();
	for(int i=a;i<=b;i++){
		fun(i);
	}
	
	return 0;
}




























