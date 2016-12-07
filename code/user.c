#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../header/User.h"


FILE * fp2;

User * user;
int * user_len;

void getUserDB(void)
{
	InitUserFileDescriptor();
	AllocateUserMemory(FindUserNumber());
	SaveUser();
}

int FIndSpecificMember(char * name)
{
	int i, len = *user_len;
	for (i = 0; i < len; i++) {
		if (!strcmp(user[i].name, name))
			return i;
	}
	return -1;
}

void ShowSpecificMember(int n)
{
	printf("name : %s, age_or_weight : %d\n", user[n].name, user[n].age_weight);
}

void ShowAllMember(void)
{
	int i, len = *user_len;
	printf("User_length : %d\n", len);
	for (i = 0; i < len; i++) {
		printf("name : %s, sex : %s, age_or_weight : %d\n", user[i].name, user[i].sex, user[i].age_weight);
	}
	printf("\n");
}

void releaseUserMemory(void)
{
	int i, len = *user_len;
	for (i = 0; i < len; i++) {
		free(user[i].name);
	}
	free(user);
	free(user_len);
}

void SaveUser(void)
{
	char * str;
	char buf[32] = { 0, };
	int i, n = 0, idx = 0;

	while (!feof(fp2)) {
		int k = 0, len;
		char temp[32] = { 0, };
		str = fgets(buf, sizeof(buf), fp2);
		if(str == NULL)
			break;
		len = strlen(str)+1;
		for (i = 0; i < len; i++) {
			if (str[i] != 32 && str[i] != 10 && str[i] != 0) {
				temp[idx++] = str[i];
			}
			else {
				idx = 0;
				switch (k) {
				case 0: strncpy(user[n].name, temp, strlen(temp) + 1); k++; memset(temp, 0, sizeof(char) * 32); break;
				case 1: strncpy(user[n].sex, temp, strlen(temp) + 1); k++; memset(temp, 0, sizeof(char) * 32); break;
				case 2: user[n].age_weight = atoi(temp); memset(buf, 0, sizeof(char) * 32); break;
				default: break;
				}
			}
		}
		n++;
	}
	free(fp2);
}

void AllocateUserMemory(int len)
{
	int i;

	user = (User*)malloc(sizeof(User) * len);

	for (i = 0; i < len; i++) {
		user[i].name = (char*)malloc(sizeof(char) * 16);
	}
}

void InitUserFileDescriptor(void)
{
	if ((fp2 = fopen("../DB/userDB.txt", "r")) == NULL) {
		printf("userDB open error\n");
		exit(1);
	}
}
int FindUserNumber(void)
{
	char * str;
	char buf[32] = { 0, };
	int len = 0;
	while (!feof(fp2)) {
		str = fgets(buf, sizeof(buf), fp2);
		if(str == NULL)
			break;		
		len++;
	}

	fseek(fp2, 0, SEEK_SET);
	memset(buf, 0, sizeof(char) * 32);

	user_len = (int*)malloc(sizeof(int));
	*user_len = len;

	return len;
}
