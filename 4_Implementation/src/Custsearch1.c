#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"../inc/customer.h"
Customer Search_name(char nam[],Customer custList[],int row)
{
	Customer Cust;
	for(int j=0;j<row;j++)
	{
		if(!(strcmp(custList[j].name,nam))){
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