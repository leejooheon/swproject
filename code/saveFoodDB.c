#include "../header/FoodDB.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

Food * food;

void getFoodDB(void)
{
	InitFoodDBFileDescriptor(); 
	InitFoodDateBase(); 
	testPrint(); 
}

void releaseFoodDBMemory(void)
{
	int i;
	for (i = 0; i < 3153; i++) {
		free(food[i].food_name);
	}
	free(food);
}

void InitFoodDBFileDescriptor(void)
{
	if ((fp = fopen("../DB/Food_DB.txt", "r")) == NULL)
	{
		printf("file open error\n");
		exit(1);
	}
}

void testPrint(void)
{
	for (int i = 0; i < 3153; i++) {
		printf("code : %d, name : %s\n", food[i].code, food[i].food_name);
	}
}

void InitFoodDateBase(void)
{
	char buf[1024];
	char *str;
	int n = 0;
	food = (Food *)malloc(sizeof(Food) * 3155);
	while (!feof(fp))
	{
		str = fgets(buf, sizeof(buf), fp);
		SavedFoodDataToStruct(str, n);
		n++;
	}
	fclose(fp);
}

void SavedFoodDataToStruct(char * str, int n)
{
	int i = 0, k = 0, idx = 0, flag = 0, len;
	char temp[128] = { 0, };
	
	if (str == NULL)
		return;

	len = strlen(str);

	for (i = 0; i < len; i++)
	{
		if (flag == 1) {
			if (str[i] == '"') {
				flag = 0;
			} else {
				temp[idx++] = str[i];
			}
		} else if (str[i] == '"'){
			flag = 1;
		} else if (str[i] != 32) {
			if (str[i] == '"' || str[i] == '/')
				continue;
			temp[idx++] = str[i];
		} else {
			idx = 0;
			switch (k) {
				case 0: food[n].code = atoi(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 1: food[n].food_name = (char*)malloc(sizeof(char)*strlen(temp) + 1); strncpy(food[n].food_name, temp, strlen(temp) + 1); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 2: food[n].calorie = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 3: food[n].protein = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 4: food[n].fat = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 5: food[n].sugar = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 6: food[n].ash = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 7: food[n].calcium = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 8: food[n].phosphorus = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 9: food[n].iron = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 10: food[n].natrium = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 11: food[n].potassium = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 12: food[n].zinc = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 13: food[n].vit_A = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 14: food[n].retinol = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 15: food[n].carotin = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 16: food[n].vit_B1 = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 17: food[n].vit_B2 = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 18: food[n].vit_B6 = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 19: food[n].niacin = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 20: food[n].vit_C = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 21: food[n].folic_acid = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 22: food[n].vit_E = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 23: food[n].cholesterol = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 24: food[n].supply_food = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 25: food[n].total_fatty_acid = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 26: food[n].monounsaturate = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				case 27: food[n].polyunsatumted_fatty_acid = atof(temp); k++; memset(temp, 0, sizeof(char) * 128); break;
				default: break;
			}
		}
	}
}
