#ifndef __FOOD_DB_H__
#define __FOOD_DB_H__
#include<stdio.h>
typedef struct _Food {
	int code;
	char * food_name;
	float calorie;
	float protein;
	float fat;
	float sugar;
	float fiber;
	float ash;
	float calcium;
	float phosphorus;
	float iron;
	float natrium;
	float potassium;
	float zinc;
	float vit_A;
	float retinol;
	float carotin;
	float vit_B1;
	float vit_B2;
	float vit_B6;
	float niacin;
	float vit_C;
	float folic_acid;
	float vit_E;
	float cholesterol;
	float supply_food;
	float total_fatty_acid;
	float monounsaturate;
	float polyunsatumted_fatty_acid;
}Food;

void releaseFoodDBMemory(void);
void InitFoodDBFileDescriptor(void);
void testPrint(void);
void InitFoodDateBase(void);
void SavedFoodDataToStruct(char * str, int n);
void getFoodDB(void);



extern Food * food;
FILE * fp;
#endif
