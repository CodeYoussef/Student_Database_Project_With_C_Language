#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"


void Enter_Data(student* in){ //Enter Student Data By user
printf("Enter Student Id : ");
scanf("%d",&in->Student_ID);
printf("Enter Student Year : ");
scanf("%d",&in->Student_year);
printf("Enter Course_ID : ");
scanf("%d",&in->Course1_ID);
printf("Enter Course_Grade : ");
scanf("%d",&in->Course1_grade);
printf("Enter Course2_ID : ");
scanf("%d",&in->Course2_ID);
printf("Enter Course2_Grade : ");
scanf("%d",&in->Course2_grade);
printf("Enter Course3_ID : ");
scanf("%d",&in->Course3_ID);
printf("Enter Course3_Grade : ");
scanf("%d",&in->Course3_grade);
printf(" \n");
}

void Create_Database(){  //first default record
int iter;
list_1=NULL;
printf("Enter One Record at first : \n");

student* temp = (student*)malloc(sizeof(student));
Enter_Data(temp);

temp->link=list_1;
    list_1=temp;


//Display Data for testing database
    student*ptr1 = list_1;
while(ptr1!=NULL){
        printf("%d ",ptr1->Student_ID);
    printf("%d \n",ptr1->Student_year);
    ptr1=ptr1->link;
}
}


void SDB_APP (){//main menu display
uint8 user_choise;
printf("(1) - To add entry, enter 1\n");
printf("(2) - To get used size in database, enter 2\n");
printf("(3) - To read student data, enter 3\n");
printf("(4) - To get the list of all student IDs, enter 4\n");
printf("(5) - To check is ID is existed, enter 5\n");
printf("(6) - To delete student data, enter 6\n");
printf("(7) - To check is database is full, enter 7\n");
printf("(0) - To exit enter\n");
scanf("%d",&user_choise);
printf("\n");
SDB_action(user_choise);
}

void SDB_action (uint8 choice){ //chose function from menu to be applied
    uint32 deleteid;
    uint32 IfIdExist;
    uint32 readid;
    Int8 condition;
    Int8 foundcondition;
    Int8 readcondition;
    uint8 countpointer;
    uint32* listpointer[10];
    uint8 i;
while(choice!=0){
switch(choice){
case(1):
 condition=SDB_AddEntry();          //call add function
if(condition==1)                    //if function added
    printf("Done !\n");
else if(condition==0){               //if function not added
    printf("Error !\n");
    }
    break;

case(2):printf(" %d ",SDB_GetUsedSize());
break;
case(3):
    printf("\n Enter The Id Needed To Be Scanned :");
    scanf("%d",&readid);                        //enter id needed to be scanned
    readcondition=SDB_ReadEntry(readid);        //call function of searching
    if(readcondition==1)                        //if function return 1
    printf("\n Found \n");
    else if(readcondition==0)                   // else if function return
        printf("Not Found\n");
    break;

case(4):
    SDB_GetList(&countpointer,&listpointer);
    printf("\n %d \n",countpointer);
for(i=0;i<countpointer;i++){
    printf("%d ",*(listpointer+i));        //could not display array!!!!
}
    break;


case(5):
    printf("\n Enter The Id Needed To Be Scanned :");
    scanf("%d",&IfIdExist);            //enter id needed to be scanned
    foundcondition=SDB_IsIdExist(IfIdExist);
    if(foundcondition==1)    //condition of return value of function
        printf("Found\n");
    else if(foundcondition==0)
        printf("Not Found\n");
    break;

case(6):
    printf("\n Enter The Id Needed To Be Deleted :");
    scanf("%d",&deleteid);                   //enter id needed to be deleted
    SDB_DeletEntry(deleteid);break;          //perform function

case(7):
    if(SDB_IsFull()==1)                      //condition of return value
        printf("DataBase is Full\n");
    else if(SDB_IsFull()==0){
        printf("There Is a place\n");
        }
        break;

default:printf("Wrong Entry ! ");            //if user input not on system
}
printf(" \n");
SDB_APP();                                   // loop the main menu again
}
}


