#include<stdio.h>

typedef struct country
{
	char name[100];
	int gold;
	int silver;
	int bronze;
	int tatol;
}country;

void print_country(country c)
{
	printf("%s\t%d\t%d\t%d\t%d\n",c.name ,c.gold ,c.silver ,c.bronze ,c.tatol );
}

void bubble_tatol(country a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j].tatol>a[j+1].tatol)
			{
				country t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
}

void bubble_gold(country a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j].gold>a[j+1].gold)
			{
				country t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
}

int main()
{
	country c[8];
	FILE *fp=fopen("D:/程序设计实验/实验6/冬奥会.txt","r");
	if(fp==NULL)
	{
		printf("Error\n");
		return 0;
	}
	for(int i=0;i<8;i++)
	{
		fscanf(fp,"%s %d %d %d %d",c[i].name ,&c[i].gold ,&c[i].silver ,&c[i].bronze ,&c[i].tatol );
	}
	fclose(fp);

	bubble_tatol (c,8);
	printf("奖牌最多的国家是：\n");
	print_country(c[7]);
	printf("奖牌最少的国家是：\n");
	print_country(c[0]);
	
	bubble_gold(c,8);
	FILE*outfp=fopen("D:/程序设计实验/实验6/file_sorted.txt","w");
	for(int i=0;i<8;i++)
	{
		fprintf(outfp,"%s\t%d\t%d\t%d\t%d\n",c[i].name ,c[i].gold ,c[i].silver ,c[i].bronze ,c[i].tatol);
	}
	fclose(outfp);
	
	return 0;
} 
