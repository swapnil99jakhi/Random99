#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"../inc/supplier.h"
char New_Supplier_ID(Supplier Supp)
{
	char a;
	FILE *f1=fopen("data1.csv","r");
	if(f1==NULL)
	{	
		perror("Unable to open the file");
		
	}
	char buff[1024];//stores the first 1024 lines into buff
	int rc=0,cc=0,q=0;
	while(fgets(buff, 1024, f1))
	{
		cc=0;
		rc++;
		if(rc==1)
			continue;
		char *field = strtok(buff,",");
		while(field)
		{				
			field = strtok(NULL,",");
			cc++;			
		}	
		q++;
	}
    	fclose(f1);	
    	FILE* fp = fopen("data1.csv", "a+");
   	if (!fp) {
        	// Error in file opening
       		printf("Can't open file\n");
        	
    	}
    	sprintf(Supp.ID,"%d",++q);
    	fprintf(fp,"%s,%s,%s,%s,%s,%s,%s\n",Supp.ID,Supp.name,Supp.City,Supp.Mobile_Number,Supp.email,Supp.Medicines,Supp.Quantity );  
		printf("\nNew added to record\n");
		a='y';
        fclose(fp);
		return a;
}