#include <iostream>
#include<iomanip>
#include <cmath>
using namespace std;

const double PI=3.1415926;
//璇峰湪姝ゅ瀹屽杽绫荤殑璁捐
class cylinder
{
public:
cylinder(double a,double b)
{r=b;h=a;cout<<"构造函数被调用"<<endl;}
~cylinder()
{cout<<"析构函数被调用"<<endl;}
double getvolumn()
{return PI*r*r*h;}
double getarea()
{return PI*r*r*2+2*PI*r*h;}
private:
double r;
double h;
};


int main()
{
    double d,h;
    cin>>d>>h;
    cylinder can(h,d/2);
    cout<<fixed<<setprecision(6);
    cout<<"油桶的容积是"<<can.getvolumn()<<" "<<endl;
    cout<<"铁皮的面积是"<<can.getarea()<<endl;
}



