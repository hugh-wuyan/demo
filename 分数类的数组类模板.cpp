#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Array
{
public:
vector<T> list; 
Array(int n)
{}
void input(int n)
{
	for(int i=0;i<n;i++)
	{T K;
	cin>>K;
	list.push_back(K);}
}

T& operator[](int n)
    {
        return list[n];
    }
};

class Fract
{
public:
	int n,m;
	Fract(int a=0,int b=1):n(a),m(b)
	{
	int c;	
	if(a<0)a=a*-1;
	if(b<0)b=b*-1;
	if(a>b)
	{
		c=a;a=b;b=c;
	}
	while (a%b != 0) {
		int temp = a ;
		a = b;
		b = temp%b;	
	}
	n=n/b;
	m=m/b;
}
	void show()
	{
	if(n==0||m==1)
	cout<<n<<endl;
	else
	cout<<n<<"/"<<m<< endl;	
	}
	Fract &operator +=(Fract &x)
	{
		int a,b,c;
		if(n==0)
		{a=x.n;
		b=x.m;
		}
		else
        {a=n*x.m+m*x.n;
        b=m*x.m;
		}
        n = a;m = b;
		if(a<0)a=a*-1;
	if(b<0)b=b*-1;
	if(a>b)
	{
		c=a;a=b;b=c;
	}
	while (a%b != 0) {
		int temp = a ;
		a = b;
		b = temp%b;	
	}
	n=n/b;
	m=m/b;
        return *this;
    }
friend istream &operator>>(istream &is,Fract &f)
    {
        is>>f.n>>f.m;
        return is;
    }
};


int main()
{
    unsigned int n;
    cin >> n;
    Array<double> db(n);
    db.input(n);
    double dbsum(0.0);
    for (unsigned int i = 0; i < n; i++)
        dbsum += db[i];
    cout << dbsum << endl;

    cin >> n;
    Array<Fract> fr(n);
    fr.input(n);
    Fract frsum(0, 1);
    for (unsigned int i = 0; i < n; i++)
        frsum += fr[i];
    frsum.show();
}
