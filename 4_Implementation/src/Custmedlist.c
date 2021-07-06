#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"../inc/customer.h"
void Medical_Update_Customer(MedList MList[],int l,Customer Cust)
{
	char Med[5][10];
	int w=0,u=0,v=0,c=0;
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
		Med[v][w]=Cust.Medicines[u];
		w++;
		u++;
	}
	Med[v][w-1]='\0';
	c++;
	FILE *temp=fopen("temp.csv","a+");
	if(temp==NULL)
	{	
		perror("Unable to open the file");
	}
	int Ml=0;
	for(int i=0;i<l;i++)
	{
		if(!strcmp(MList[i].MedName,Med[Ml]))
		{
			int T=atoi(MList[i].Quantity)-1;
			char num[10];
			sprintf(num,"%d",T);
			fprintf(temp,"%s,%s,%s,%s",MList[i].ID,MList[i].MedName,num,MList[i].Price);
			Ml++;
		}
		else
		{
		if(i==0)
			fprintf(temp,"%s,%s,%s,%s\n",MList[i].ID,MList[i].MedName,MList[i].Quantity,MList[i].Price);
			else
				fprintf(temp,"%s,%s,%s,%s",MList[i].ID,MList[i].MedName,MList[i].Quantity,MList[i].Price);
			
		}
	}
	fclose(temp);
	remove("data2.csv");
	rename("temp.csv","data2.csv");
}