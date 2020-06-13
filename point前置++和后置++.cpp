#include  <iostream> 
using  namespace  std; 
class Point
{
	int m_x,m_y;
	public:
	friend ostream &operator<<(ostream &,const Point &);
	Point(int x=0,int y=0){m_x=x;m_y=y;}
	Point& operator ++();
	Point operator ++(int);
	int real(){return m_x;}
	int imag(){return m_y;}
};
Point& Point::operator ++()
{m_x++;m_y++;return *this;}
Point Point::operator ++(int)
{Point old=*this;
m_x++;
m_y++;
return old; 
}  
ostream& operator<< (ostream&s,const Point& a)
{
	return s<<"("<<a.m_x<<","<<a.m_y<<")"<<endl;
	return s;
}
int  main() 
{ 
        Point  a(1,3); 
        cout<<a; 
        cout<<a++; 
        cout<<++a; 
        return  0; 
}

