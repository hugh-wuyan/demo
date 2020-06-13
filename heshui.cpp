#include<iostream>
using namespace std;

int water(int bottle,int cap)
{
	int all;
    all=bottle/2+cap/3;
    bottle=all+bottle%2;
    cap=all+cap%3;
    if(bottle<2&&cap<3)
    return all;
    else
    return all+water(bottle,cap);
}
int main()
{
    int n,k;
	cin>>n;
	k=water(n,n);
	cout<<k+n;	
}
