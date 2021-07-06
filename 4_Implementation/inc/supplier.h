#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Supp
{
	char ID[10];
	char name[50];
	char City[50];
	char Mobile_Number[11];
	char email[20];
	char Medicines[100];
	char Quantity[100];
}Supplier;
typedef struct MedL1
{
	char ID[10];
	char MedName[25];
	char Quantity[10];
	char Price[5];
}MedList1;
char New_Supplier_ID(Supplier Supp);
Supplier Search_IDS(int id,Supplier SuppList[],int row);
Supplier Search_NameS(char nam[],Supplier SuppList[],int row);
void Medical_Update(MedList1 MList[],int l,Supplier Supp);
void supplier();

