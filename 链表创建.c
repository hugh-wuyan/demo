struct link* create(int *p,int n)
{
	struct link *head,*a,*b;
	int i;

	for(i=0;i<n;i++)
	{	
	    a=(struct link*)malloc(sizeof(struct link))
		a->data=*(p+i);
		a->next=NULL;
		if(i=0)
		b=head=a;
		else
		b->next=a;
	    b=a;
	}
}		
