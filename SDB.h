#ifndef SDB_H_INCLUDED
#define SDB_H_INCLUDED
#include "STD.h"


typedef struct SimpleDb
{
 uint32 Student_ID;
 uint32 Student_year;
 uint32 Course1_ID;
 uint32 Course1_grade;
 uint32 Course2_ID;
 uint32 Course2_grade;
 uint32 Course3_ID;
 uint32 Course3_grade;
 struct SimpleDb* link;
} student;

void SDB_APP ();
void SDB_action (uint8 choice);
void Enter_Data(student* in);
void Create_Database();

uint8 SDB_GetUsedSize();
void SDB_DeletEntry (uint32 id);
bool SDB_IsFull ();
bool SDB_AddEntry();
bool SDB_ReadEntry (uint32 id);
void SDB_GetList (uint8 * count, uint32 * list[10]);
bool SDB_IsIdExist (uint32 id);
student* list_1;

#endif
