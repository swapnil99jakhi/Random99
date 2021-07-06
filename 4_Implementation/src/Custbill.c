#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"../inc/customer.h"
int Bill_Generation(Customer Cust,MedList MList[],int l)
{
	char Med[20][20];
	int w=0,u=0,v=0,c=0;
	int total=0;
	while(Cust.Medicines[u])
	{
		if(Cust.Medicines[u]==' ')
		{
			Med[v][w]='\0';
			c++;
			v++;
			w=0;
			u++;
			continue;			
		}
		if(Cust.Medicines[u]=='\n'){
		u++;
		continue;
		}
		Med[v][w]=Cust.Medicines[u];
		w++;
		u++;
	}
	Med[v][w]='\0';
	c++;
	int Ml=0;
	for(int i=1;i<l;i++)
	{	
		if(!strcmp(MList[i].MedName,Med[Ml]))
		{
			int p=atoi(MList[i].Price);
			total=total+p;
			Ml++;
		}
		if(Ml==c)
			break;
			
	}
	return total;
}

