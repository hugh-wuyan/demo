#include<iostream>
using namespace std;
class CPoint
{		
	public:
		int t1,t2;
		
		CPoint(int p1=0,int p2=0)
		{t1=p1;t2=p2;cout<<"CPoint contstructor with default value(0,0) is called."<<endl;}  
		
		CPoint(CPoint &p)
		{t1=p.t1;t2=p.t2;cout<<"CPoint copy contstructor is called."<<endl;	} 
}; 
class CRectangle
{
	private:
		CPoint r1,r2;
	public:
	    CRectangle(CPoint ct1,CPoint ct2);
		CRectangle(CRectangle& g);
		CRectangle(int a,int b,int c,int d);
		CRectangle();
		int GetArea()
		{return (r2.t1-r1.t1)*(r2.t2-r1.t2);}			
};
CRectangle::CRectangle(CPoint ct1,CPoint ct2):r1(ct1),r2(ct2)
{cout<<"CRectangle contstructor with (CPoint,CPoint) is called."<<endl;}

CRectangle::CRectangle(int a,int b,int c,int d):r1(a,b),r2(c,d)
{cout<<"CRectangle contstructor with (int,int,int,int) is called."<<endl;}

CRectangle::CRectangle(CRectangle& a):r1(a.r1),r2(a.r2)
{cout<<"CRectangle copy contstructor is called."<<endl;}

CRectangle::CRectangle():r1(0,0),r2(0,0) 
{cout<<"CRectangle default contstructor is called."<<endl;}
int  main() 
{ 
        int  a=1,  b=1,  c=6,  d=11; 
        cout<<"#  Define  p1  ######"<<endl; 
        CPoint  p1; 
        cout<<"#  Define  p2  ######"<<endl; 
        CPoint  p2(10,20); 
        cout<<"#  Define  rect1  ######"<<endl; 
        CRectangle  rect1; 
        cout<<"#  Define  rect2  ######"<<endl; 
        CRectangle  rect2(p1,  p2); 
        cout<<"#  Define  rect3  ######"<<endl; 
        CRectangle  rect3(a,  b,  c,  d); 
        cout<<"#  Define  rect4  ######"<<endl; 
        CRectangle  rect4(rect2); 
        cout<<"#  Calculate  area  ######"<<endl; 
        cout  <<  "rect1面积为"  <<  rect1.GetArea()  <<  endl; 
        cout  <<  "rect2面积为"  <<  rect2.GetArea()  <<  endl; 
        cout  <<  "rect3面积为"  <<  rect3.GetArea()  <<  endl; 
        cout  <<  "rect4面积为"  <<  rect4.GetArea()  <<  endl; 
        system("pause"); 
        return  0; 
} 
