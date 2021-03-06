#include  <iostream> 
#include  <vector>
using  namespace  std; 
class  Book 
{
	private:
	unsigned int m_ID;//编号
    string m_Name;//书名
    string m_Introduction;//简介
    string m_Author;//作者
    string m_Date;//日期
    unsigned int m_Page;//页数
    public:
    void SetID(int n);
    void SetName(string n); 
    void SetAuthor(string n); 
    void SetIntroduction(string n); 
    void SetDate(string n); 
    void SetPage(int n); 
    int GetID();
    string GetName();
    string GetAuthor();
    string GetIntroduction();
    string GetDate(); 
    int GetPage();
    Book();//将m_ID初始化为0，表示这个一个未赋值对象
    ~Book();//无具体的工作
    Book(const Book& other);//实现所有成员变量的拷贝
};
void Book::SetPage(int n)
{m_Page = n;}
void Book::SetID(int n)
{m_ID = n;}
void Book::SetName(string n)
{m_Name = n;}                                                     //请在此处补充Book类的成员函数实现
void Book::SetAuthor(string n)
{m_Author = n;}
void Book::SetIntroduction(string n)
{m_Introduction = n;}
void Book::SetDate(string n)
{m_Date = n;}
int Book::GetID()
{return m_ID;}
string Book::GetName()
{return m_Name;}
string Book::GetAuthor()
{return m_Author;}
string Book::GetIntroduction()
{return m_Introduction;}
string Book::GetDate()
{return m_Date;}
int Book::GetPage()
{return m_Page;}
Book::Book()
{m_ID = 0;m_Page = 0;}
Book::Book(const Book& other)
{
    m_ID = other.m_ID;//编号
    m_Name = other.m_Name;//书名
    m_Introduction = other.m_Introduction;//简介
    m_Author = other.m_Author;//作者
    m_Date = other.m_Date;//日期
    m_Page = other.m_Page;
}
Book::~Book()
{}
class Store
{
	private:
	vector<Book> m_Books;//指向利用new操作动态创建的Book数组
    public:
    unsigned int GetCount(); 
    Store();
    Store(int n);
    virtual ~Store();
    Store(const Store& other);
    void in(Book &b);
    void out(string name);
    Book findbyID(int ID);
    Book findbyName(string name);
    void printList();
};
unsigned int Store::GetCount()
{return m_Books.size();} 

Store::Store()
{cout<<"Store default constructor called!"<<endl;}
Store::Store(int n)
{vector<Book> m_Books(n);cout<<"Store constructor with (int n) called!"<<endl;}

Store::~Store()
{cout<<"Store destructor called!"<<endl;}

Store::Store(const Store& other)
{m_Books=other.m_Books;cout<<"Store copy constructor called!"<<endl;}

void Store::in(Book &b)
{
m_Books.insert(m_Books.end(),b);
}

void Store::out(string name)
{int i;
for(i=0;i<m_Books.size();i++)
{if(m_Books[i].GetName()==name)
m_Books.erase(m_Books.begin()+i);
}
}

Book Store::findbyID(int ID)
{
	int i;
	Book fanhui;
	for(i=0;i<m_Books.size();i++)
	{if(m_Books[i].GetID()==ID)
	{return m_Books[i];break;}
	}
	return fanhui;
}

Book Store::findbyName(string name)
{
	int i;
	Book fanhui;
	for(i=0;i<m_Books.size();i++)
	{if(m_Books[i].GetName()==name)
	{return m_Books[i];break;}
	}
	return fanhui;
}

void Store::printList()
{cout<<"There are totally "<<m_Books.size()<<" Books:"<<endl;
int i;
for(i=0;i<m_Books.size();i++)
{  if (m_Books[i].GetID() != 0)
            cout << "ID=" << m_Books[i].GetID() << ";  " << "Name:" << m_Books[i].GetName() << ";  " << "Author:" << m_Books[i].GetAuthor() << ";  " << "Date:" << m_Books[i].GetDate() << ";" << endl;
    }
}

int main()
{ 
        Store  s; 
        Book  b1,b2,b3; 
        b1.SetID(1); 
        b1.SetName("C++  语言程序设计(第4版)"); 
        b1.SetAuthor("郑莉"); 
        b1.SetIntroduction("介绍C++及面向对象的知识"); 
        b1.SetDate("201007"); 
        b1.SetPage(529); 
        b2.SetID(2); 
        b2.SetName("离散数学"); 
        b2.SetAuthor("左孝凌"); 
        b2.SetIntroduction("介绍命题逻辑、谓词逻辑、集合论、代数系统和图论"); 
        b2.SetDate("198209"); 
        b2.SetPage(305); 
        b3.SetID(3); 
        b3.SetName("c程序设计"); 
        b3.SetAuthor("谭浩强"); 
        b3.SetIntroduction("介绍C程序设计中的基本知识，如语句格式、语法等"); 
        b3.SetDate("201006"); 
        b3.SetPage(355); 

        cout<<"第一本书入库"<<endl; 
        s.in(b1); 
        cout<<"第二本书入库"<<endl; 
        s.in(b2); 
        cout<<"第三本书入库"<<endl; 
        s.in(b3); 
        cout  <<"现有库存书籍数量："<<s.GetCount()  <<  endl; 
        cout  <<"查找并出库图书：离散数学"  <<  endl; 
        Book  tmpbook=s.findbyName("离散数学"); 
        if(tmpbook.GetID()!=0) 
        { 
                s.out("离散数学"); 
                cout  <<"离散数学  已成功出库"  <<  endl; 
        } 
        else 
                cout<<"没有找到name为离散数学的书"<<endl; 
        cout  <<"现有库存书籍数量："<<s.GetCount()  <<  endl; 

        cout  <<"查找图书  ID：3"  <<  endl; 
        tmpbook=s.findbyID(3); 
        if(tmpbook.GetID()!=0) 
                cout<<"找到ID为"<<3<<"的书，书名："<<tmpbook.GetName()<<endl; 
        else 
                cout<<"没有找到ID为"<<3<<"的书"<<endl; 

        cout  <<"查找图书  name：离散数学"  <<  endl; 
        tmpbook=s.findbyName("离散数学"); 
        if(tmpbook.GetID()!=0) 
                cout<<"找到name为离散数学的书，ID："<<tmpbook.GetID()<<endl; 
        else 
                cout<<"没有找到name为离散数学的书"<<endl; 

        cout<<"输出所有库存图书的信息"<<endl; 
        s.printList(); 
        cout<<"程序运行结束"<<endl; 
        return  0; 
} 
