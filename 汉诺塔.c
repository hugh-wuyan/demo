#include <stdio.h>
#include <string.h>
/* 孙发思路：1将 n-1个盘子先放到B座位上    
             2.将A座上地剩下的一个盘移动到C盘上    
             3、将n-1个盘从B座移动到C座上*///函数声明
void move(char x, char y);
void hannuo(int n,char one ,char two,char three)
{  void move(char x,char y); 
   if(n==1)move(one, three);
   else
{  
	hannuo(n-1,one ,three,two);
    move(one,three);
	hannuo(n-1,two,one,three); 
}
}
void move(char x,char y)
{
 printf("%c--->%c",x,y); 
 } 
void main()
{
    int n;
	printf("input your number");
	scanf("%d",&n);
	hannuo(n,'A','B','C');

 }

