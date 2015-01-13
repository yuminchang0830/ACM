/* @JUDGE_ID:50418EN 750 C */
#include <stdio.h>
#include <stdlib.h>

int table[8][8];		/* 0 no use   1 used */
int use[10];
int xx,yy,number;

int write(int x,int y)
{
	int i,j;

	i=x;
	for (j=0;j<8;j++)		/* - */
		table[i][j]=1;
	j=y;
	for (i=0;i<8;i++)
		table[i][j]=1;		/* | */
	i=x;
	while ((i>=0)&&(j>=0))
	{
		i--;
		j--;
	}
	for (i++,j++;(i<8)&&(j<8);i++,j++)
		table[i][j]=1;		/* \ */
	i=x;
	j=y;
	while ((i<8)&&(j>=0))
	{
		i++;
		j--;
	}
	for (i--,j++;(i>=0)&&(j<8);i--,j++)
		table[i][j]=1;		/* / */
	return 0;
}

int force(int x)
{
	int i,j,k,temp[8][8];
	
	if (x>=8)
	{
		printf("%2d      ",number);
		number++;
		for (i=0;i<8;i++)
			if (i)
				printf(" %d",use[i]);
			else
				printf("%d",use[i]);
		printf("\n");
		return 0;
	}

	if (x==yy-1)
		force(x+1);

	for (i=0;i<8;i++)
		for (j=0;j<8;j++)
			temp[i][j]=table[i][j];
	
	for (i=0;i<8;i++)
		if (temp[i][x]==0)
		{
			use[x]=i+1;
			for (j=0;j<8;j++)
				for (k=0;k<8;k++)
					table[j][k]=temp[j][k];
			write(i,x);
			force(x+1);
		}
	return 0;
}

int main()
{
	int i,j,n;

	freopen("p750in.txt","r",stdin);  
	freopen("p750out.txt", "w", stdout);

	scanf("%d",&n);
	while (n--)
	{
		scanf("%d %d",&xx,&yy);

		for (i=0;i<8;i++)
			for (j=0;j<8;j++)
				table[i][j]=0;
		
		for (i=0;i<=10;i++)
			use[i]=0;
		
		use[yy-1]=xx;
		write(xx-1,yy-1);
				
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		number=1;
		
		force(0);
		if (n)
			printf("\n");
	}
	return 0;
}
