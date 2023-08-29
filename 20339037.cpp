#include <iostream>
#include<ctime>
using namespace std;
int sudoku[9][9];//存储数独 
int flag[9][9];//存储题目输入的数据位置 
int p;
/***************************************/
//数独输入函数
void cinsudoku(){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			char in;
			cin>>in;
			if(in=='.'){
				sudoku[i][j]=0;
				flag[i][j]=0;
			}
			else{
				sudoku[i][j]=in-48;
				flag[i][j]=1;
			}	
		}
	}
	return;
}
/***************************************/
//数独输出函数 
void printsudoku(){
	if(p==1){//自定模板输出 
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout<<sudoku[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	else if(p==0){//机器模板输出 
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				if(sudoku[i][j]==0)
					cout<<'.';
				else
					cout<<sudoku[i][j];
			}
		}
	}
	else throw"wrong p";
}
/***************************************/
//判断数字是否符合规则函数 

bool judgerowandline(int x,int y){
	int i,j;
	for(i=0;i<9;i++){
		if(i!=y&&sudoku[x][y]==sudoku[x][i]&&sudoku[x][i]!=0)
		    return false;
	}
	for(j=0;j<9;j++){
		if(j!=x&&sudoku[x][y]==sudoku[j][y]&&sudoku[j][y]!=0)
		    return false;
	}
	return true;
}
bool judgeneighbour(int x,int y){
	int neighbour1,neighbour2;
	int i,j;
    neighbour1=x/3*3;
    neighbour2=y/3*3;
	for(i=neighbour1;i<neighbour1+3;i++){//九宫格判断 
		for(j=neighbour2;j<neighbour2+3;j++){
			if(i!=x||j!=y){
				if(sudoku[i][j]!=0&&sudoku[i][j]==sudoku[x][y])
				    return false;
			}
		}
	}
	return true;
}
bool judge(int x,int y){
	return judgerowandline(x,y)&&judgeneighbour(x,y);
}
/**************************************/
//回溯法解数独 
void solve(int t){
	int i,j,x,y;	
	if(t!=81){
		x=t/9;
		y=t%9;
		if(flag[x][y]!=0){//若为题目输入的数字则不改变 
			solve(t+1);
		}
		else if(flag[x][y]==0&&sudoku[x][y]!=0){
			solve(t+1);
		}
		else {
			for(i=1;i<=9;i++){
				sudoku[x][y]=i;
				if(judge(x,y)){//填写正确则进行下一个数字 
					solve(t+1);
				}
				sudoku[x][y]=0;//若后面发现填的数字不对则回归到0 
			}
		}
	}
	else printsudoku();
}
/***************************************/
int main(){
	//long t1,t2;
	cin>>p;
	cinsudoku();
	//t1=clock();
	solve(0);
	//t2=clock();
	//cout<<t2-t1<<"ms";
	return 0;
}
