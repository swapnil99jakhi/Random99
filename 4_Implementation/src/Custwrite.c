#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"../inc/customer.h"
int New_Customer_Id(Customer Cust)
{
    FILE* fp = fopen("data.csv", "a+");
    if (!fp) {
        // Error in file opening
        printf("Can't open file\n");
        return 0;
    } 
    // Saving data in file
    fprintf(fp,"%s,%s,%s,%s,%s,%s\n",Cust.ID,Cust.name,Cust.City,Cust.Mobile_Number,Cust.email,Cust.Medicines );
    fclose(fp);
    return 1;
}

