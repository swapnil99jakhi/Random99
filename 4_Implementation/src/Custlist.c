#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"../inc/customer.h"
void Customer_Records(Customer custList[],int row)
{
	for(int j=0;j<row;j++)
		printf("ID->%s name->%s City->%s Mobile_Number->%s email->%s Medicines->%s\n",custList[j].ID,custList[j].name,custList[j].City,custList[j].Mobile_Number,custList[j].email,custList[j].Medicines);
	
}