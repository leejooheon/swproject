#ifndef __USER_INFO_H__
#define __USER_INFO_H__

typedef struct _userInfo{
	int age_weight;
	float calorie;
	float protein;
	float vit_A;
	float vit_E;
	float vit_C;
	float vit_B1;
	float vit_B2;
	float niacin;
	float vit_B6;
	float folic_acid;
	float calcium;
	float phosphorus;
	float iron;
	float zinc;
}UserInfo;


extern void SaverConditionDB(void);
extern void AllocateConditionDB(void);
extern void InitConditionFileDescriptor(void);
extern void getConditionDB(void);
extern void ShowConditionDB(void);
extern void releaseUserInfoMemory(void);

extern UserInfo * userInfo;

#endif
