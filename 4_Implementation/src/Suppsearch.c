#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"../inc/supplier.h"
Supplier Search_IDS(int id,Supplier SuppList[],int row)
{
	Supplier Supp;
	char ID2[10];
	sprintf(ID2,"%d",id);
	for(int j=0;j<row;j++)
	{
		if(!(strcmp(SuppList[j].ID,ID2))){
			strcpy(Supp.ID,SuppList[j].ID);
			strcpy(Supp.name,SuppList[j].name);
			strcpy(Supp.City,SuppList[j].City);
			strcpy(Supp.Mobile_Number,SuppList[j].Mobile_Number);
			strcpy(Supp.email,SuppList[j].email);
			strcpy(Supp.Medicines,SuppList[j].Medicines);
			strcpy(Supp.Quantity,SuppList[j].Quantity);
			break;
		}
		
	}
	return Supp;
}