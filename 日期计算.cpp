#include<iostream>
#include<cmath>
using namespace std;
class CTime
{private:
int year,month,day,hour,minute,second;
public:
CTime(int a,int b,int c,int d=0,int e=0,int f=0)
{
int x[12]={31,28,31,30,31,30,31,31,30,31,30,31};
if((a/4==0&&a/100!=0)||(a/400==0))x[1]=29;
if(b>12){cout<<"date error!"<<endl;year=0;month=0;day=0;hour=0;minute=0;second=0;}
else if(c>x[b-1]){cout<<"date error!"<<endl;year=0;month=0;day=0;hour=0;minute=0;second=0;}
else if((b>12||(c>x[b-1]))&&(d>23||e>59||f>59)){cout<<"data and time error!"<<endl;year=0;month=0;day=0;hour=0;minute=0;second=0;}
else if(d>23||e>59||f>59){cout<<"time error!"<<endl;year=0;month=0;day=0;hour=0;minute=0;second=0;}
else {year=a;month=b;day=c;hour=d;minute=e;second=f;}
cout<<"���캯��������"<<endl;
}//���캯�� 

int isvalid()
{int n;
 if(year==0) n=0;
else  n=1;
return n;
}//�ж� 

void showTime()
{cout<<year<<"/"<<month<<"/"<<day<<" "<<hour<<":"<<minute<<":"<<second<<endl;}//��ʾ 

CTime(CTime &g)
{year=g.year;month=g.month;day=g.day;hour=g.hour;minute=g.minute;second=g.second;cout<<"�������캯��������"<<endl;}//���� 

~CTime()
{cout<<"��������������"<<endl;}//���� 

int dayDiff(CTime h)
{int days=0,n=0,month2=0,month1=0,year1=0,year2=0,day1=0,day2=0,i=0;//���� 
if(h.month>month)month2=h.month;
else month2=month;
if(h.month<month)month1=h.month;
else month1=month;
if(month2-month1!=0)for(i=month1;i<month2;i++)
{	switch(i)
	{case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:days=days+31;break;
	case 2:days=days+28;break;
	default:days=days+30;
	}	
}//�����²� 
if(h.year>year){year2=h.year;day2=h.day;month2=h.month;}
else {year2=year;day2=day;month2=month;}
if(h.year<year){year1=h.year;day1=h.day;month1=h.month;}
else {year1=year;day1=day;month1=month;}
if(year==h.year)
{
	if(month>h.month){month2=month;day2=day;}
	else{month2=h.month;day2=h.day;}
	if(month<h.month){month1=month;day1=day;}
	else{month1=h.month;day1=h.day;}
}

for(i=year1+1;i<year2;i++)
{if((i%4==0&&i%100!=0)||(i%400==0)) 
  n++;}//�������� 
days=days+(year2-year1)*365+n+day2-day1;
if(year2!=year1)
	{
	if(((year2%4==0&&year2%100!=0)||(year2%400==0))&&month2>2)
	days=days+1;
	if(((year1%4==0&&year1%100!=0)||(year1%400==0))&&month1<=2)
	days=days+1;
	}
else  if(((year2%4==0&&year2%100!=0)||(year2%400==0))&&month2>2)days=days+1;
return days;
}
};
int  main() 
{ 
        int  year,  month,  day,  hour,  minute,  second; 
        cin  >>  year  >>  month  >>  day  >>  hour  >>  minute  >>  second; 
        CTime  t1(year,  month,  day,  hour,  minute,  second); 
        t1.showTime(); 
        CTime  t2(2000,  1,  1);  //����Ĭ���βν�ʱ���ʼ��Ϊ00:00:00 
        if  (t1.isvalid())          //������ں�ʱ��Ϸ������������ 
        { 
                int  days=0; 
                days=t1.dayDiff(t2); 
                cout<<"������֮�������"<<days<<"��"<<endl; 
                days=t2.dayDiff(t1); 
                cout<<"������֮�������"<<days<<"��"<<endl; 
        } 
}
