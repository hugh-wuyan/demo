#include <iostream>
#include <iomanip>
using namespace std;
template<class T>
class node
{
	public:
    T data;
    node* next;
};
template<class T>
class linkedList
{
public:
    linkedList();//���캯��
    virtual ~linkedList();//����������ע��Ҫ���������нڵ����Դ
    void insert( int value );//���棺�����ʼ������ʹ�ã�
    bool initiate();//��ʼ��������ʹ��new��������ͷ��㡣�������ʧ�ܣ��򷵻�false�����򷵻�true
    bool isEmpty();//�жϵ������Ƿ�Ϊ��
    //ɾ���������е�pos��Ԫ�ؽ�㣬����ɾ���Ľڵ��ֵ����value�С�
    //ע�⣺�������Ϊ�ա�ɾ��λ�ô��������ȡ��Լ�ɾ��λ��Ϊ0���������Ҫ��ֹɾ���������Ӧ��Ϣ
    bool remove( int pos, int& value );
    void print();//˳���ӡ����������ǵ�����Ϊ�գ������ Empty
    int Length();//���ص������ȡ�����ǵ�����Ϊ�գ��򷵻�-1
private:
    node<T> *head;
    int len;
};
//���ڴ˴��������г�Ա������ʵ��
//���캯�� 
template<class T>
linkedList<T>::linkedList()
{len=0;}
//�������� 
template<class T>
linkedList<T>::~linkedList()
{
    if(len == 0)
    {
        delete head;
    }
    while(head->next != NULL)
    {
        node<T> *temp = head;
        head = head->next;
        delete temp;
    }
    delete head;
    head = NULL;
}
//insert
template<class T>
void linkedList<T>::insert(int value)
{
	len++;
	int count=0;
	node<T> *p=head;
	while(p!=NULL&&count<len-1)
	{
		p=p->next;
		count++;
	}
	node<T> *q=new node<T>;
	q->data=value;
	q->next=p->next;
	p->next=q;
}
//initiate 
template<class T>
bool linkedList<T>::initiate()
{
	head=new node<T>;
	head->next=NULL;
	if(head!= NULL)
        return true;
    else
        return false;
}
//isempty
template<class T>
bool linkedList<T>::isEmpty()
 {
 if(head->next!= NULL)
        return false;
    else
        return true;
 }
//remove 
template<class T>
bool linkedList<T>::remove(int pos, int &value)
{
	int count=1;
	node<T> *p=head->next;
	node<T> *q=head;
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
//��Ա����print
template<class T>
void linkedList<T>::print()
{
    if( isEmpty() )
    {
        cout << "Empty" << endl;
        return;
    }
    node<T>* tmp = head->next;
    while(tmp)
    {
        cout <<tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
//��Ա����Length 
template<class T>
int linkedList<T>::Length()
{
	return len;
}

int main(int argc, char* argv[])
{
    linkedList<int> L1;
    int n;
    int val;
    //��ʼ������
    if(!L1.initiate())
        return 0;

    cin>>n;//�������������ݸ���
    for(int i=0; i<n; i++) //����n����������������
    {
        cin>>val;
        L1.insert(val);
    }
    cout << "Origin Length��" << L1.Length() << endl;//���������
    cout << "data��" ;
    L1.print();//��ӡ����

    cin>>n;//������Ҫɾ�������ݵ�λ��
    if (L1.remove(n,val))
    {
        //ɾ��λ��n�����ݣ�����ɾ��������ֵ����val��
        cout<<"Delete the data at position("<<n<<"):"<<val<<endl;
        cout<< "New Length��" << L1.Length()<< endl;//���������
        cout<< "data��" ;
        L1.print();//��ӡ����
    }

    return 0;
}
