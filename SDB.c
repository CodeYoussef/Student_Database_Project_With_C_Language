#include <stdio.h>
#include <stdlib.h>
#include "STD.h"
#include "SDB.h"
extern student* list_1;
bool SDB_IsFull (){ //determine if database is full

int Record=0;   //variable to count no. of records
    student*ptr1 = list_1;
while(ptr1!=NULL){
    ptr1=ptr1->link; //see next record
    Record++;
}
if(Record>9)
return true;//database is full if record is 10
else
return false;//there is a place left

}

uint8 SDB_GetUsedSize(){//determine no of records in database

int Record=0;//variable to count no. of records
    student*ptr1 = list_1;
while(ptr1!=NULL){
    ptr1=ptr1->link; //see next record
    Record++;
}
return Record; //return number of records
}


bool SDB_AddEntry(){ //add new record
if (SDB_IsFull()==1){ //check weather database is full
return false; //if data couldn't be added
}
else{
student*temp = (student*)malloc(sizeof(student));  //add new block
Enter_Data(temp); //call function of entering data
student* ptr=list_1; //call database address
    while(ptr->link!=NULL){
    ptr=ptr->link; //call next record till find the null
    }
    ptr->link=temp; // give  database adress of new block
    temp->link=NULL;
return true; //return true if data is recorded
}}

void SDB_DeletEntry (uint32 id){//delete  record
    student * temp;
    student * ptr = list_1;
	while(ptr->link!= NULL){  //search for records
		if(ptr->link->Student_ID == id){ //condition if id exist with user id
			temp = ptr->link; //give temp record the address of current record
			break;
	    }
		ptr = ptr->link; //if not the same id go to next record
	}
	if(ptr->link == NULL){  //if id not found
		printf("ID of the value %d is not in the List\n",id);
	}
	else{
		ptr->link = temp ->link;//give previous record the address of next record
		free(temp);// remoe clock
	}
}



bool SDB_ReadEntry (uint32 id){ //search for id user added and read it's record if found
 student*ptr = list_1;
while(ptr!=NULL){
 if(ptr->Student_ID==id){ //condition to search on records
printf("\n ID is %d \n",ptr->Student_ID);    //show record of this ID
printf("Year is %d \n",ptr->Student_year);
printf("Course_1 ID is %d \n",ptr->Course1_ID);
printf("Course_1 Grade is %d \n",ptr->Course1_grade);
printf("Course_2 ID is %d \n",ptr->Course2_ID);
printf("Course_2 Grade is %d \n",ptr->Course2_grade);
printf("Course_3 ID is %d \n",ptr->Course3_ID);
printf("Course_3 Grade is %d \n",ptr->Course3_grade);

 return true;// id id found
 }
    ptr=ptr->link; //see next record if id not found
}
return false; //if id not found
}


void SDB_GetList (uint8* count, uint32* list[10]){  //get no of id and list them
    uint8 counter=0;                       //count no. of ID'S
    student*ptr = list_1;
while(ptr != NULL){
    list[counter]=ptr->Student_ID;
    ptr=ptr->link;                        //go to next record
    counter++;
}
*count =counter;                          //return number of ID'S
}

bool SDB_IsIdExist (uint32 id){  //check if id user added is found or not
 student*ptr = list_1;
while(ptr != NULL){                // loop of search
 if(ptr->Student_ID==id)  {        //search condition if id exist
  return true;                     //return true
 }
    ptr=ptr->link;                 //see next record address
}
return false;
}

