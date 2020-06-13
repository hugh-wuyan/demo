#include<iostream>
 using namespace std;
 int search(int x,int y,int c[8][8])
 {
 	int a,b;
 	for(a=x+1,b=y+1;a<8&&b<8;a++,b++)
 	{
 		if(c[a][b]==1)
 		return 0;
	 }
	for(a=x-1,b=y-1;a>=0&&b>=0;a--,b--)
	{
		if(c[a][b]==1)
		return 0;
	}
	for(a=x-1,b=y+1;a>=0&&b<8;a--,b++)
	{
		if(c[a][b]==1)
		return 0;
	}
	for(a=x+1,b=y-1;a<8&&b>=0;a++,b--)
	{
		if(c[a][b]==1)
		return 0;
	}
	return 1;
 }
int main()
{
	int a[8][8]={0},i,x(36),z(0),j;
	char b[8];
	for(i=0;i<8;i++)
	{
		cin>>b[i];
		if(b[i]!='*')
		x=x-(b[i]-48);
		else 
		z=i;
	}
	b[z]=x+48;//接收数据 
	for(i=0;i<8;i++)
	{
		z=b[i]-49;
		a[i][z]=1;
	}//形成棋盘和皇后 
    for(i=0;i<8;i++)
	{
	z=b[i]-49;
	j=search(i,z,a);
	if(j==0)
	{cout<<"No Answer";break;
		}	
	}
	if(j==1)
	cout<<x; 
}
