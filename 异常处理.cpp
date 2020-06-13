#include<iostream>
#include<string>
#include<exception>
#include<typeinfo>//�벹����ʵ�ͷ�ļ� 
using  namespace  std; 
class MyException1: public exception
{	
public:
	string what()
	{
		return typeid(MyException1).name();
	}
};
//�붨���쳣��MyException1 
class MyException2:virtual public exception
{
	public:
	string what()
	{
		return typeid(MyException2).name();
	}
};
//�붨���쳣��MyException2 
int divide(int a,int b)
{int c;
if(b==0)
c=0;
else
c=a/b;
throw c;	
}
//�붨�庯��divide()���Գ�0���������쳣 
int  main() 
{ 
        int  id,k; 
        cin>>id; 
        char  a; 
        string  s="hello"; 
          try 
        { 
                switch  (id) 
                { 
                case  1: 
                        throw  MyException1(); 
                        break; 
                case  2: 
                        throw  MyException2(); 
                        break; 
                case  3: 
                        k=divide(8,0); 
                        break;                                         
                case  4: 
                        a=s.at(10); 
                        cout<<a<<endl; 
                        break;                                         
                default: 
                        break; 
                } 
        } 
        catch  (MyException1  &e) 
        { 
              cout  <<  "exception:  "<<e.what()<<  endl; 
        } 
        catch  (MyException2  &e) 
        { 
                cout  <<  "exception:  "<<e.what()<<  endl; 
        } 
        catch  (int  &e) 
        { 
                cout  <<  "exception:  "<<e<<  endl; 
        }         
        catch(exception  &e) 
        { 
              cout  <<  "exception:  "<<e.what()<<  endl; 
        } 
        cout<<"Return  to  main()"<<endl; 
        return  0; 
}
