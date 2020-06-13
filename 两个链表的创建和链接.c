#include<malloc.h>
#include<stdio.h>
struct link
{
	int data;
	struct link *next;
};

struct link *fun(int *k,int n)
{
	struct link *head=NULL,*a,*b;
	int i;
	for(i=0;i<n;i++)
	{
		a=(struct link*)malloc(sizeof(struct link));
		a->data=k[i];
		if(i==0)
		b=head=a;
		else b->next=a;
		a->next=NULL;
		b=a; 
	}
	return head;
}

int main()
{
	int a[]={5,10,15},b[]={1,4,6,8,30,45};
	struct link *p,*q,*z,*head=NULL,*pf=NULL;
	int i;
	q=p=(struct link*)malloc(sizeof(struct link));
	p=fun(a,3);
	q=fun(b,6);
	for(i=0;i<6;i++)
	{
		z=(struct link*)malloc(sizeof(struct link));
		if((i+1)%2!=0)
		{
			if(p==NULL)
			break;
			z->data=p->data; 
			p=p->next;
		}
		else
		{
			z->data=q->data;
			q=q->next;
		}
		if(i==0)
		pf=head=z;
		else pf->next=z;
		z->next=NULL;
		pf=z;
	}
 	for(i=0;i<3;i++)
 	{
 		z=(struct link*)malloc(sizeof(struct link));
 		z->data=q->data;
 		z->next=NULL;
 		q=q->next;
 		pf->next=z;
 		pf=z;
	 }
	struct link*t=head;
	while(t)
	{
		printf("%5d",t->data);
		t=t->next;
	}
	printf("\n");
	return 0; 
}



