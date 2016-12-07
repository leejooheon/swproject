#include "../header/UserInfo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

UserInfo * userInfo;
FILE * fp3;


void getConditionDB(void)
{
	InitConditionFileDescriptor();
	AllocateConditionDB();
	SaverConditionDB();
	ShowConditionDB();
}

void releaseUserInfoMemory(void)
{
	free(userInfo);
}


void ShowConditionDB(void)
{
	int i;
	for (i = 0; i < 7; i++) {
		printf("%d %f %f\n", userInfo[i].age_weight, userInfo[i].calorie, userInfo[i].protein);
	}
}
void SaverConditionDB(void)
{
	int i, j, idx = 0, len = 7;
	char * str;
	char buf[64] = { 0, };
	for (i = 0; i < len; i++) {
		int length, k = 0;
		char temp[16] = { 0, };
		str = fgets(buf, sizeof(buf), fp3);
		length = strlen(buf) + 1;
		for (j = 0; j < length; j++) {
			if (str[j] != 32 && str[j] != 10 && str[j] != 0) {
				temp[idx++] = str[j];
			}
			else {
				idx = 0;
				switch (k) {
				case 0: userInfo[i].age_weight = atoi(temp); memset(temp, 0, strlen(temp)+1); k++; break;
				case 1: userInfo[i].calorie = atof(temp); memset(temp, 0, strlen(temp) + 1); k++; break;
				case 2: userInfo[i].protein = atof(temp); memset(temp, 0, strlen(temp) + 1); k++; break;
				case 3: userInfo[i].vit_A = atof(temp); memset(temp, 0, strlen(temp) + 1); k++; break;
				case 4: userInfo[i].vit_E = atof(temp); memset(temp, 0, strlen(temp) + 1); k++; break;
				case 5: userInfo[i].vit_C = atof(temp); memset(temp, 0, strlen(temp) + 1); k++; break;
				case 6: userInfo[i].vit_B1 = atof(temp); memset(temp, 0, strlen(temp) + 1); k++; break;
				case 7: userInfo[i].vit_B2 = atof(temp); memset(temp, 0, strlen(temp) + 1); k++; break;
				case 8: userInfo[i].niacin = atof(temp); memset(temp, 0, strlen(temp) + 1); k++; break;
				case 9: userInfo[i].vit_B6 = atof(temp); memset(temp, 0, strlen(temp) + 1); k++; break;
				case 10: userInfo[i].folic_acid = atof(temp); memset(temp, 0, strlen(temp) + 1); k++; break;
				case 11: userInfo[i].calcium = atof(temp); memset(temp, 0, strlen(temp) + 1); k++; break;
				case 12: userInfo[i].phosphorus = atof(temp); memset(temp, 0, strlen(temp) + 1); k++; break;
				case 13: userInfo[i].iron = atof(temp); memset(temp, 0, strlen(temp) + 1); k++; break;
				case 14: userInfo[i].zinc = atof(temp); memset(temp, 0, strlen(temp) + 1); k++; break;
				default: break;
				}
			}
		}
	}
	fclose(fp3);
}
void AllocateConditionDB(void)
{
	userInfo = (UserInfo *)malloc(sizeof(UserInfo) * 7);
}
void InitConditionFileDescriptor(void)
{
	//수정해야함
	if ((fp3 = fopen("../DB/conditionDB.txt", "r")) == NULL) {
		printf("conditionDB open error\n");
		exit(1);
	}
}
