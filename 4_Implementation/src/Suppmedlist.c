#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"../inc/supplier.h"
void Medical_Update(MedList1 MList[],int l,Supplier Supp)
{
	char Med[20][20];
	int w=0,u=0,v=0,c=0;
	while(Supp.Medicines[u])
	{
		if(Supp.Medicines[u]==' ')
		{
			Med[v][w]='\0';
			c++;
			v++;
			w=0;
			u++;
			continue;			
		}
		Med[v][w]=Supp.Medicines[u];
		w++;
		u++;
	}
	Med[v][w]='\0';
	u=0;v=0;w=0;
	char Qty[5][10];
	
	while(Supp.Quantity[u])
	{
		if(Supp.Quantity[u]==' ')
		{
			Qty[v][w]='\0';
			v++;
			w=0;
			u++;
			continue;			
		}
		Qty[v][w]=Supp.Quantity[u];
		w++;
		u++;
	}
	
	Qty[v][w]='\0';
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
			int T=atoi(Qty[Ml])+atoi(MList[i].Quantity);
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
    printf("Medical List Updated");
	fclose(temp);
       	remove("data2.csv");
       	rename("temp.csv","data2.csv");
       		
	
}