#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"../inc/customer.h"
Customer Search_Id(int id,Customer custList[],int row)
{
	char ID2[10];
	Customer Cust;
	sprintf(ID2,"%d",id);
	for(int j=0;j<row;j++)
	{
		if(!(strcmp(custList[j].ID,ID2))){
			strcpy(Cust.ID,custList[j].ID);
			strcpy(Cust.name,custList[j].name);
			strcpy(Cust.City,custList[j].City);
			strcpy(Cust.Mobile_Number,custList[j].Mobile_Number);
			strcpy(Cust.email,custList[j].email);
			strcpy(Cust.Medicines,custList[j].Medicines);
			break;
			
			}
	}
	return Cust;
}