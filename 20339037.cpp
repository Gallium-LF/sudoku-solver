#include <iostream>
#include<ctime>
using namespace std;
int sudoku[9][9];//�洢���� 
int flag[9][9];//�洢��Ŀ���������λ�� 
int p;
/***************************************/
//�������뺯��
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
//����������� 
void printsudoku(){
	if(p==1){//�Զ�ģ����� 
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout<<sudoku[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	else if(p==0){//����ģ����� 
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
//�ж������Ƿ���Ϲ����� 

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
	for(i=neighbour1;i<neighbour1+3;i++){//�Ź����ж� 
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
//���ݷ������� 
void solve(int t){
	int i,j,x,y;	
	if(t!=81){
		x=t/9;
		y=t%9;
		if(flag[x][y]!=0){//��Ϊ��Ŀ����������򲻸ı� 
			solve(t+1);
		}
		else if(flag[x][y]==0&&sudoku[x][y]!=0){
			solve(t+1);
		}
		else {
			for(i=1;i<=9;i++){
				sudoku[x][y]=i;
				if(judge(x,y)){//��д��ȷ�������һ������ 
					solve(t+1);
				}
				sudoku[x][y]=0;//�����淢��������ֲ�����ع鵽0 
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
