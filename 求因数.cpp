#include  <iostream> 
#include  <cmath> 
using  namespace  std; 

//判断是否为素数 
int  isPrime(long  num) 
{ 
 int i;
	for (i = 2; i < num ; i++)
	{
	 if (num%i == 0)
	 {return 1;break;}
	}
	if(i==num)
	return 0;
} 

//计算质因素分解， 
void  factorization(long n,long factor[100],int &numofFactor) 
{ 
 int i;
if(isPrime(n)==0)
{factor[numofFactor]=n;
numofFactor++;}
else
{
for(i=2;i<n;i++)
{
if(n%i==0)
{
n=n/i;
factor[numofFactor]=i;
numofFactor++;
factorization(n,factor,numofFactor);break;
}
}
}
    return; 
} 

int  main() 
{ 
        long  n; 
        long  factor[100]; 
        int  numofFactor=0; 
        cin>>n; 
        factorization(n,factor,numofFactor); 
        for  (int i=0;i<numofFactor;i++) 
        { 
            cout<<factor[i]<<"  "; 
        } 
        cout<<endl; 
        return  0; 
}
