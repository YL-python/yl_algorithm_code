#include<iostream>
using namespace std;

int gcd(int a,int b){
	return b?gcd(b,b%a):a;
} 

int main(){

	return 0;
}

