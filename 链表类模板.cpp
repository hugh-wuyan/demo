#include <iostream>
#include <iomanip>
using namespace std;

template<class T> 
class node
{
    T data;
    node* next;
};
class linkedList
{
public:
    linkedList();//构造函数
    virtual ~linkedList();//析构函数，注意要链表中所有节点的资源
    void insert( int value );//警告：必须初始化才能使用！
    bool initiate();//初始化单链表，使用new操作创建头结点。如果创建失败，则返回false，否则返回true
    bool isEmpty();//判断单链表是否为空
    //删除单链表中第pos个元素结点，并将删除的节点的值存在value中。
    //注意：如果链表为空、删除位置大于链表长度、以及删除位置为0的情况，需要终止删除并输出相应信息
    bool remove( int pos, int& value );
    void print();//顺序打印单链表，如果是单链表为空，则输出 Empty
    int Length();//返回单链表长度。如果是单链表为空，则返回-1
private:
    LList *head;
    int len;
};
//请在此处补充所有成员函数的实现
//构造函数 
linkedList::linkedList()
{len=0;}
//析构函数 
linkedList::~linkedList()
{
    if(len == 0)
    {
        delete head;
    }
    while(head->next != NULL)
    {
        PList temp = head;
        head = head->next;
        delete temp;
    }
    delete head;
    head = NULL;
}
//insert
void linkedList::insert(int value)
{
	len++;
	int count=0;
	PList p=head;
	while(p!=NULL&&count<len-1)
	{
		p=p->next;
		count++;
	}
	PList q=new node();
	q->data=value;
	q->next=p->next;
	p->next=q;
}
//initiate 
bool linkedList::initiate()
{
	head=new node();
	head->next=NULL;
	if(head!= NULL)
        return true;
    else
        return false;
}
//isempty
bool linkedList::isEmpty()
 {
 if(head->next!= NULL)
        return false;
    else
        return true;
 }
//remove 
bool linkedList::remove(int pos, int &value)
{
	int count=1;
	PList p=head->next;
	PList q=head;
	if(pos<=0)
	{cout<<"pos<=0,failed"<<endl;return false;}
	if(isEmpty()||pos>len)
	{	cout<<"pos>len,failed"<<endl;return false;}	
	while(p!=NULL)
	{
		if(count==pos)
		{
			 q->next=p->next;
			 value=p->data;
			 delete p;
			 len--;
			 return true;
		}
		else
		{
			count++;
			q=p;
			p=p->next;
		}
	}
}
//成员函数print
void linkedList::print()
{
    if( isEmpty() )
    {
        cout << "Empty" << endl;
        return;
    }
    LList* tmp = head->next;
    while(tmp)
    {
        cout <<tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
//成员函数Length 
int linkedList::Length()
{
	return len;
}

int main(int argc, char* argv[])
{
    linkedList L1;
    int n;
    int val;
    //初始化链表
    if(!L1.initiate())
        return 0;

    cin>>n;//输入链表中数据个数
    for(int i=0; i<n; i++) //输入n个数，并插入链表
    {
        cin>>val;
        L1.insert(val);
    }
    cout << "Origin Length：" << L1.Length() << endl;//输出链表长度
    cout << "data：" ;
    L1.print();//打印链表

    cin>>n;//输入需要删除的数据的位置
    if (L1.remove(n,val))
    {
        //删除位置n的数据，并将删除的数据值放在val中
        cout<<"Delete the data at position("<<n<<"):"<<val<<endl;
        cout<< "New Length：" << L1.Length()<< endl;//输出链表长度
        cout<< "data：" ;
        L1.print();//打印链表
    }

    return 0;
}
