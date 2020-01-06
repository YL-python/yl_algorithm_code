#include <iostream>
#include <string>

using namespace std;

int n,m; 
char s[1005][1005];
bool vx[1005] ,vy[1005];

void dfs(iny x,int y){
	s[x][y] = '0';
	if(!vx[x]){
		vx[x] = true;
		for(int i=0;i<m;i++){
			if(s[x][i] == '1'){
				dfs(x,i);
			}
		}
	}
	if(!vy[y]){
		vy[y] = true;
		for(int i=0;i<n;i++){
			if(s[i][y] == '1'){
				dfs(i,y);
			}
		}
	}
}

int main(){
	
	cin >> n>> m;
	for(int i=0;i<n;i++){
		cin >> s[i];
	}
	int cnt = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j] == '1'){
				cnt ++;
				dfs(i,j);
			}
		}
	}
	cout << cnt;
	return 0;
}




























