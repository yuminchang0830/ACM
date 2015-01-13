#define MAX 210

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char buf[20000];
int x[MAX];
int y[MAX];
int num;
double speed[2]={6.0,1.5};
char *p;
int flag;
double edge[MAX][MAX];
double shorts[MAX];
int used[MAX];
double small;

double time(int a,int b,int c)
{
	double t;
	
	t=sqrt((double)(abs(x[a]-x[b]))*(double)(abs(a[x]-x[b]))+(double)(abs(y[a]-y[b]))*(double)(abs(y[a]-y[b])));
	t=t*speed[c]/1000;
	return t;
}

int main()
{
	int n,i,j,idx,temp;
	
	used[0]=1;
	/*freopen("10389.txt","r",stdin);*/
	scanf("%d",&n);

	
	while(n--)
	{
		for (i=0;i<MAX;i++)
			for (j=0;j<MAX;j++)
				edge[i][j]=-1;
		
		scanf("%d %d %d %d",&x[0],&y[0],&x[1],&y[1]);
		gets(buf);
		num=2;
		while (gets(buf)!=NULL)
		{
			p=strtok(buf," ");
			if (p!=NULL)
			{
				/*printf("%s ",p);*/
				x[num]=atoi(p);
				idx=num;
				flag=1;
				p=strtok(NULL," ");
				while(p!=NULL)
				{
					if (*p=='-')
						break;
					
					if (flag==1)
						y[num++]=atoi(p);
					else
						x[num]=atoi(p);
					p=strtok(NULL," ");
					flag=flag^1;
				}
				for (i=idx+1;i<num;i++)
					edge[i][i-1]=edge[i-1][i]=time(i-1,i,1);
			}
			else
			{
				break;
			}
		}
		for (i=0;i<num;i++)
		{
			edge[i][i]=0;
			for (j=i+1;j<num;j++)
				if (edge[i][j]<0)
					edge[j][i]=edge[i][j]=time(i,j,0);
		}
					
		for (i=1;i<num;i++)
			shorts[i]=edge[0][i];
		
		for (i=1;i<num;i++)
			used[i]=0;
		
		temp=num;
		while(--temp)
		{
			small=10000000;
			for (i=1;i<num;i++)
				if (used[i]==0)
					if (shorts[i]<small)
					{
						idx=i;
						small=shorts[i];
					}
			used[idx]=1;
			for (i=1;i<num;i++)
				if (shorts[idx]+edge[idx][i]<shorts[i])
					shorts[i]=shorts[idx]+edge[idx][i];
		}
				
		printf("%d\n",(int)floor(shorts[1]+0.5));
		
		if (n)
			printf("\n");
	}
	
	return 0;
}
