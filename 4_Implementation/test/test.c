#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"../unity/unity.h"
#include"../unity/unity_internals.h"
#include"../inc/customer.h"
#include"../inc/supplier.h"
Customer Cust;
Supplier Supp;
void setUp(void)
{
}
void tearDown(void)
{
}
void test_should_convert(void){
    FILE *f2=fopen("data2.csv","r");
	if(f2==NULL)
	{	
		perror("Unable to open the file");
	}
	char buff1[1024];//stores the first 1024 lines into buff
    int rc=0,cc=0;
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
   char ID1[5];
    int num=6;
    sprintf(ID1,"%d",num);
    strcpy(Cust.ID,ID1);
    strcpy(Cust.name,"lodi");
    strcpy(Cust.City,"bangalore");
    strcpy(Cust.Mobile_Number,"4444444444");
    strcpy(Cust.email,"@xyz.com");
    strcpy(Cust.Medicines,"Nacxone Kdox"); 
    TEST_ASSERT_EQUAL_INT(70,Bill_Generation(Cust,MList,12));
}
    void test_should_convert1(){
    strcpy(Supp.name,"Aditya");
    strcpy(Supp.City, "Nashik");
    strcpy(Supp.Mobile_Number,"9091347337");
    strcpy(Supp.email,"@playboy.com");
    strcpy(Supp.Medicines,"Pacedon Allegra");
    strcpy(Supp.Quantity,"20 40");
    TEST_ASSERT_EQUAL('y',New_Supplier_ID(Supp));
}
int compare(int id)
{
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
 	Customer cust=Search_Id(id,custList,i);
 	if(!(strcmp(cust.name,custList[1].name)))
			return 1;
	else
		return 0;		
}
int compare1(int id){
    int q=0;
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
Supplier supp=Search_IDS(id,SuppList,q);
 	if(!(strcmp(supp.name,SuppList[1].name)))
			return 1;
	else
		return 0;

}
void Search_Customer_ID(void )
{
	TEST_ASSERT_EQUAL_INT(1,compare(2));

}
void Search_Supplier_ID(void )
{
	TEST_ASSERT_EQUAL_INT(1,compare(2));

}
int main(void)
{
UNITY_BEGIN();
RUN_TEST(test_should_convert);
RUN_TEST(test_should_convert1);
RUN_TEST(Search_Customer_ID);
RUN_TEST(Search_Supplier_ID);
return UNITY_END();
}

/*
gcc Custbill.c Custfinal.c Custlist.c Custmedlist.c Custwrite.c Custsearch.c Custsearch1.c main.c Suppfinal.c Suppmedlist.c Suppsearch.c Suppsearch1.c Suppwrite.c
*/
