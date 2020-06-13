#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	float a[2],b[2],c[2];
	cin>>a[0]>>a[1]>>b[0]>>b[1];
	c[0]=a[0]-b[0];
	c[1]=a[1]-b[1];
	cout<<fixed<<setprecision(2)<<c[0];
	cout<<' '<<c[1]<<fixed<<setprecision(2);
 } 
