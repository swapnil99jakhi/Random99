#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"../inc/customer.h"
int customer(){
int n;
	printf("Customer Menu\nChoose a Number\n1.New Customer ID Generation\n2.Search By Customer ID \n3.Search By Name\n4.Display Customer Records\n");
	scanf("%d",&n);
		FILE *f1=fopen("data.csv","r");
        if(f1==NULL)
			{	
				perror("Unable to open the file");
			}
			char buffm[1024];//stores the first 1024 lines into buff
			int rc=0,cc=0;
			Customer custList[100];
			int i=0;
			while(fgets(buffm, 1024, f1))
			{
				cc=0;
				rc++;
				if(rc==1)
					continue;
				char *field = strtok(buffm,",");
				while(field)
				{
					if(cc==0)
						strcpy(custList[i].ID,field);
					if(cc==1)
						strcpy(custList[i].name,field);
					if(cc==2)
						strcpy(custList[i].City,field);	
					if(cc==3)
						strcpy(custList[i].Mobile_Number,field);
					if(cc==4)
						strcpy(custList[i].email,field);
					if(cc==5)
				strcpy(custList[i].Medicines,field);				
					field = strtok(NULL,",");
					cc++;					
				}	
				i++;
			}
			fclose(f1);
    FILE *f2=fopen("data2.csv","r");
	if(f2==NULL)
	{	
		perror("Unable to open the file");
	}
	char buff1[1024];//stores the first 1024 lines into buff
	rc=0,cc=0;
	MedList MList[20];
	int q=0;
	while(fgets(buff1, 1024, f2))
	{
		cc=0;
		rc++;
		char *field = strtok(buff1,",");
		while(field)
		{
			if(cc==0)
				strcpy(MList[q].ID,field);
			if(cc==1)
				strcpy(MList[q].MedName,field);
			if(cc==2)
				strcpy(MList[q].Quantity,field);	
			if(cc==3)
				strcpy(MList[q].Price,field);
						
			field = strtok(NULL,",");
			cc++;								
		}	
		q++;
	}
	fclose(f2);	
	
	int id1,j=0;
	Customer Cust;	
	char name1[25];
	switch(n)
	{
		case 1: sprintf(Cust.ID,"%d",++i);
    			printf("\nEnter Name:\n");
    			scanf("%s",Cust.name);
    			printf("\nEnter City:\n");
    			scanf("%s",Cust.City);
    			printf("\nEnter Mobile_Number:\n");
    			scanf("%s",Cust.Mobile_Number);
    			printf("\nEnter Email:\n");
    			scanf("%s",Cust.email);
    			printf("\nEnter Medicines\n");
    			scanf("%s",Cust.Medicines);
    			while(Cust.Medicines[j])
    			{
    				if(Cust.Medicines[j]==',')
    					Cust.Medicines[j]=' ';
    				j++;	
                }
                New_Customer_Id(Cust);
				printf("New Record Added");
			break;
		case 2: 
			printf("Enter ID\n");
			scanf("%d",&id1);
			Cust=Search_Id(id1,custList,i);
			break;
		case 3: 
			printf("Enter Name\n");
			scanf("%s",name1);
            Cust=Search_name(name1,custList,i);
			break;
		case 4: Customer_Records(custList,i);
		return 0;
		break;	
		default: printf("error\n");
			break;				
	}
    Medical_Update_Customer(MList,q,Cust);
	int Bill=Bill_Generation(Cust,MList,q);
	printf("Total Price: %d\n",Bill);
}