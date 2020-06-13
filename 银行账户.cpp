#include <iostream>
#include <iomanip>
using namespace std;
//请在此处补充Account类的定义
class Account
{public:
void init(string a,string b,string c,int d,double e)
{int f;
f=e*1000;
if(f%10>=1&&f%10<=9)
{cout<<"您输入的金额不合法 "<<endl;}
else money=e;
zhanghao=a;
name=b;
age=d;}
void printmoney()
{cout<<name<<"的存款为";
cout<<fixed<<setprecision(2);cout<<money<<endl;}
void  deposit(double a)
{int c;
c=a*1000;
if(c%10>=1&&c%10<=9)
cout<<"您输入的金额不合法 "<<endl;
else money=a+money;}
void withdraw(double a)
{int c;
c=a*1000;
if(c%10>=1&&c%10<=9)
cout<<"您输入的金额不合法 "<<endl;
else if(a>money)cout<<"您的存款金额不足"<<endl;
else money=money-a;}
private:
string zhanghao;
string name;
string sex;
int age;
double money=0;
};


int main()
{
    Account tom;
    tom.init("32020320011001876X", "Tom Black", "男", 19, 2000.89);
    tom.printmoney();//输出：Tom Black的存款为2000.89
    tom.deposit(89.471);//输出：您输入的金额不合法
    tom.printmoney();//输出：Tom Black的存款为2000.89
    tom.deposit(10000);
    tom.printmoney();//输出：Tom Black的存款为12000.89
    tom.withdraw(10001);
    tom.printmoney();//输出：Tom Black的存款为1999.89
    tom.withdraw(10000.123);//输出：您输入的金额不合法
    tom.printmoney();//输出：Tom Black的存款为1999.89
    tom.withdraw(10000.9);//输出：您的存款金额不足
    tom.printmoney();//输出：Tom Black的存款为1999.89
    Account jerry;
    jerry.init("320203200910116569", "Jerry Black", "女", 11, 100.956);//输出：您输入的金额不合法
    jerry.printmoney();//输出：Jerry Black的存款为0.00
}

