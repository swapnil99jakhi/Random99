#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"inc/customer.h"
#include"inc/supplier.h"
int main()
{   int p;
    printf("Press 1 for Customer Menu\nPress 2 for Supplier Menu\n");
    scanf("%d",&p);
    switch(p){
    case 1:
    customer();
    break;
    case 2:
    supplier();
    break;
    }
    return 0;
}

