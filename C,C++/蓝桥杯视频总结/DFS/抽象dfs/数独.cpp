#include <iostream>
#include <string>

using namespace std;

char s[10][10];
bool f;
int vx[10][10], vy[10][10], vv[10][10];

void dfs(int x,int y){
	if(f){
		return ;
	}
	if(x == 9){
		f = true;
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				if(j == 8){
					cout << s[i][j] << endl;
				}else{
					cout << s[i][j] << " ";
				}
			}
		}
		return ;
	}
	if(y == 9){
		dfs(x+1, 0);
		return ;
	}
	if(s[x][y] != '*'){
		dfs(x,y+1);
		return ;
	}
	for(int i=1;i<=9;i++){  // 相当于 81 个for循环  哈哈哈 
		if(!vx[x][i] && !vy[y][i] && !vv[x/3*3 + y/3][i]){
			s[x][y] = '0' + i;
			vx[x][i] = 1;
			vy[y][i] = 1;
			vv[x/3*3 + y/3][i] = 1;
			dfs(x,y+1);  // 当前点搜索之后继续搜索下一个点 
			vx[x][i] = 0;
			vy[y][i] = 0;
			vv[x/3*3 + y/3][i] = 0;
			s[x][y] = '*';
		}
	}
} 

int main(){
	
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin >> s[i][j];
		}
	}
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(s[i][j] != '*'){
				vx[i][s[i][j]-'0'] = 1;
				vy[j][s[i][j]-'0'] = 1;
				vv[i/3*3 + j/3][s[i][j]-'0'] = 1;
			}
		}
	}
	
	dfs(0,0); // 对每个位置进行深搜 
	
	return 0;
}
/*
搜索问题只要，什么情况下搜，什么情况下不搜
至于怎么搜，让程序去跑就好 

输入数独，给出一组和法界就行，没有就输出
* 2 6 * * * * * *
* * * 5 * 2 * * 4
* * * 1 * * * * 7
* 3 * * 2 * 1 8 *
* * * 3 * 9 * * *
* 5 4 * 1 * * 7 *
5 * * * * 1 * * *
6 * * 9 * 7 * * *
* * * * * * 7 5 *

1 2 6 7 3 4 5 9 8
3 7 8 5 9 2 6 1 4
4 9 5 1 6 8 2 3 7
7 3 9 4 2 5 1 8 6
8 6 1 3 7 9 4 2 5
2 5 4 8 1 6 3 7 9
5 4 7 2 8 1 9 6 3
6 1 3 9 5 7 8 4 2
9 8 2 6 4 3 7 5 1

*/ 



























