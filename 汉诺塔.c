#include <stdio.h>
#include <string.h>
/* �﷢˼·��1�� n-1�������ȷŵ�B��λ��    
             2.��A���ϵ�ʣ�µ�һ�����ƶ���C����    
             3����n-1���̴�B���ƶ���C����*///��������
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

