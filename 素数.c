#include<stdio.h>
int main()
{
int i, n;
scanf("%d", &n);
for (i = 2; i < n ; i++)
{
if (n%i == 0)
break;
}
if (i < n) printf("This is not a prime.");
else printf("This is a prime.");
return 0;
}
