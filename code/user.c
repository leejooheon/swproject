#include<stdio.h>
#include "../header/UserInfo.h"
UserInfo userInfo;
char ** info;

void getUserDB(void)
{
	int len = 0, idx = 0, i;
	char * str;
	char buf[32] = {0, };
	char temp[16] = {0, };
	fp2 = fopen("../DB/userDB.txt");

	while(!feof(fp)){
		str = fgets(buf, sizeof(buf), fp);
		len++;
	}

	memset(buf, 0, sizeof(char) * 32);
	info = (char**)malloc(sizeof(char*) * len);
	for(i = 0; i < len; i++)
		info[i] = (char*)malloc(sizeof(char)*32);

	fseek(SEEK_SET);

	while(!feof(fp)){
		str = fgets(buf, sizeof(buf, fp);
		for(i = 0; str[i] != 0; i++){
			if(str[i] != 32){
				temp[idx++] = str[i];
			} else{
				idx = 0;
				//save struct
				//구조체 만들어야함.
			}
		}
	}

}

void initByUserInfo(int n){


}

