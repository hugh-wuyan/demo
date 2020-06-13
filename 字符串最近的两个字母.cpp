#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	char a[10]={0},b[10]={0};
	int i=0,j=0,k=26,c;
	cin.get(a,10);
	for(i=0;i<10;i++)
	{
	if(a[i]>='A'&&a[i]<='Z')
	a[i]=a[i]+32;
	if(a[i]==0)
	break; 
	}
	cin.get();
	cin.get(b,10);	
	for(j=0;j<10;j++)
	{
	if(b[j]>='A'&&b[j]<='Z')
	b[j]=b[j]+32;
	if(b[j]==0)
	break;
	}
	c=j;
    for(i=i-1;i>=0;i--)
    for(j=c-1;j>=0;j--)
    {
    	if(abs(a[i]-b[j])<=k)
    	k=abs(a[i]-b[j]);
	}
	cout<<k;
	return 0;
}  

