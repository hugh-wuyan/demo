#include <iostream>
using namespace std;
const float pi=3.14159;
class Shape
{
	private:
		int m_ID=0;
	public:
		int GetID(){return m_ID;}
		void SetID(int n){m_ID=n;}
		virtual float getArea(){return 0;}
		Shape(){cout<<"Shape constructor called:"<<m_ID<<endl;}
		Shape(int n){m_ID=n;cout<<"Shape constructor called:"<<m_ID<<endl;}
		~Shape(){cout<<"Shape destructor called:"<<m_ID<<endl;}
};
class Circle:public Shape
{
	private:
		int r;
	public:
	        int Getr(){return r;}
		void Setr(int n){r=n;}	
		float getArea(){return pi*r*r;}
		Circle(int n,int k);
		~Circle(){cout<<"Circle destructor called:"<<GetID()<<endl;}
};
Circle::Circle(int n,int k):Shape(k)
{r=n;cout<<"Circle constructor called:"<<GetID()<<endl;}
class Rectangle:public Shape
{
private:
		int h,w;
	public:
	        int Geth(){return h;}
		void Seth(int n){h=n;}
		int Getw(){return w;}
		void Setw(int n){w=n;}
		float getArea(){return h*w;}
		Rectangle(int n,int k,int z);
		~Rectangle(){cout<<"Rectangle destructor called:"<<GetID()<<endl;}
};
Rectangle::Rectangle(int n,int k,int z):Shape(z)
{h=n;w=k;cout<<"Rectangle constructor called:"<<GetID()<<endl;}

int main()
{
    Shape s(1);//1表示ID
    Circle c(4,2);//4表示半径，2表示ID
    Rectangle r(4, 5,3);//4和5表示长和宽，3表示ID
    cout<<"Shape的面积"<<s.getArea()<<endl;
    cout<<"Circle的面积"<<c.getArea()<<endl;
    cout<<"Rectangle的面积"<<r.getArea()<<endl;
}

