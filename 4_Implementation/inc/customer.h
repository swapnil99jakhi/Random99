/** 
 * @file Customer.h
 * @author Group8
 * @brief Header file
 * @version 0.1
 * @date 2021-07-05
 *
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct cust
{
	char ID[10];
	char name[50];
	char City[50];
	char Mobile_Number[11];
	char email[20];
	char Medicines[100];
	
}Customer;
typedef struct MedL
{
	char ID[10];
	char MedName[25];
	char Quantity[10];
	char Price[5];
}MedList;
/**
 * @brief Creates a new customer record in the customer csv file
 */
int New_Customer_Id();
/**
 * @brief Searches for the existing customer using his/her ID as an input in the customer csv file
 * @param id(Customer id)
 * @param custList(Customer list)
 * @param row(Total number of customers)
 */
Customer Search_Id(int id,Customer custList[],int row);
/**
 * @brief Searches for the existing customer using his/her name as an input in the customer csv file
 * @param id(Customer name)
 * @param custList(Customer list)
 * @param row(Total number of customers)
 */
Customer Search_name(char nam[],Customer custList[],int row);
/**
 * @brief Gives the list of customer records from the customer csv file
 * @param custList(Customer list)
 * @param row(Total number of customers)
 */
void Customer_Records(Customer custList[],int row);
/**
 * @brief Decrementing the specific medicine quantities from medical list csv file demanded by customer  
 * @param MList(Medical List)
 * @param l(Number of medicines of the customer)
 * @param row(Customer file)
 */
void Medical_Update_Customer(MedList MList[],int l,Customer Cust);
/**
 * @brief Generates bill for the customer using his/her order of medicine
 * @param Cust(Customer file)
 * @param MList(Medical list)
 * @param row(Number of medicines of the customer)
 */
int Bill_Generation(Customer Cust,MedList MList[],int l);
/**
 * @brief Main function of customer menu 
 */
int customer();
