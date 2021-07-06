#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"../inc/supplier.h"
void supplier(){
FILE *f2=fopen("data2.csv","r");
	if(f2==NULL)
	{	
		perror("Unable to open the file");
	}
	char buff[1024];//stores the first 1024 lines into buff
	int rc=0,cc=0;
	MedList1 MList[30];
	int i=0;
	while(fgets(buff, 1024, f2))
	{
		cc=0;
		rc++;
		char *field = strtok(buff,",");
		while(field)
		{
			if(cc==0)
				strcpy(MList[i].ID,field);
			if(cc==1)
				strcpy(MList[i].MedName,field);
			if(cc==2)
				strcpy(MList[i].Quantity,field);	
			if(cc==3)
				strcpy(MList[i].Price,field);
						
			field = strtok(NULL,",");
			cc++;								
		}	
		i++;
	}
	fclose(f2);
	printf("If New Supplier\n Press 1 else 0\n");
	int n;
	int q=0;
	Supplier Supp;
	scanf("%d",&n);
	if(n)
	{
		 	
    		printf("\nEnter Name:\n");
    		scanf("%s",Supp.name);
    		printf("\nEnter City:\n");
    		scanf("%s",Supp.City);
    		printf("\nEnter Mobile_Number:\n");
    		scanf("%s",Supp.Mobile_Number);
    		printf("\nEnter Email:\n");
    		scanf("%s",Supp.email);
   		printf("\nEnter Medicines\n");
    		scanf("%s",Supp.Medicines);
    		int j=0;
    		while(Supp.Medicines[j])
    		{
    			if(Supp.Medicines[j]==',')
    				Supp.Medicines[j]=' ';
    			j++;	
    		}
    		printf("\nEnter Each Medicine's Quantity Respectively\n");
    		scanf("%s",Supp.Quantity);
    		j=0;
    		while(Supp.Quantity[j])
    		{
    			if(Supp.Quantity[j]==',')
    				Supp.Quantity[j]=' ';
    			j++;	
    		}
    		New_Supplier_ID(Supp);
	}
	else
	{
		FILE *f3=fopen("data1.csv","r");
		if(f3==NULL)
		{	
			perror("Unable to open the file");
		}
		char buff[1024];//stores the first 1024 lines into buff
		int rc=0,cc=0;
		Supplier SuppList[100];
		while(fgets(buff, 1024, f3))
		{
			cc=0;
			rc++;
			if(rc==1)
				continue;
			char *field = strtok(buff,",");
			while(field)
			{
				if(cc==0)
					strcpy(SuppList[q].ID,field);
				if(cc==1)
					strcpy(SuppList[q].name,field);
				if(cc==2)
					strcpy(SuppList[q].City,field);	
				if(cc==3)
					strcpy(SuppList[q].Mobile_Number,field);
				if(cc==4)
					strcpy(SuppList[q].email,field);
				if(cc==5)
					strcpy(SuppList[q].Medicines,field);
				if(cc==6)
				  strcpy(SuppList[q].Quantity,field);					
			field = strtok(NULL,",");
			cc++;		
			}	
			q++;
		}
		fclose(f3);
		printf("Press 0--> Want to Search By Id\nPress 1-->Want Search By Name\n");
		int m;
		scanf("%d",&m);
		if(!m)
		{
			int ID1;
			printf("Enter ID\n");
			scanf("%d",&ID1);
			Supp=Search_IDS(ID1,SuppList,q);
			
		}
		else
		{
			char nam[25];
			printf("Enter Name\n");
			scanf("%s",nam);
			Supp=Search_NameS(nam,SuppList,q);
			
		}
	}
	printf("%s %s",Supp.Medicines,Supp.Quantity);
	Medical_Update(MList,i,Supp); 
}
