#include<stdio.h>
#include<math.h>
#include<string.h>

const int MAX=33333;
int prime[MAX],num;
bool is[MAX];

int getpri()
{
	int i,j,k=0;
	memset(is,true,sizeof(is));
	for(i=2;i<=MAX;i++)
	{
		if(is[i])
		{
			prime[k++]=i;
           for(j=i+i;j<MAX;j+=i)
			   is[j]=false;
		}
	}
	return k;
}
void fun(int x)
{
   int i,cnt=0;
   bool first=true;
   for(i=num-1;i>=0;--i)
   {
	   cnt=0;
       while(x%prime[i]==0)
	   {
		   cnt++;
		   x/=prime[i];
	   }
	   if(cnt)
	   {
		   if(first)
		   {
			   printf("%d %d",prime[i],cnt);
			   first=false;
		   }
		   else
			   printf(" %d %d",prime[i],cnt);
	   }
   }
   printf("\n");
}
int main()
{
	int p,e;
	num=getpri();
	while(true)
	{
		int sum=1;
		while(true)
		{
			scanf("%d",&p);
			if(p==0)
				return 0;
			scanf("%d",&e);
             sum*=(int)pow((double)p,e);
			 if(getchar()=='\n')
				 break;
		}
		fun(sum-1);
	}
	return 0;
}
