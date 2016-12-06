#ifndef __USER_INFO_H__
#define __USER_INFO_H__

typedef struct _userInfo{
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

extern float calorie_MAX;
extern float calorie_MAX;
extern	float protein_MAX;
extern	float vit_A_MAX;
extern	float vit_E_MAX;
extern	float vit_C_MAX;
extern	float vit_B1_MAX;
extern	float vit_B2_MAX;
extern	float niacin_MAX;
extern	float vit_B6_MAX;
extern	float folic_acid_MAX;
extern	float calcium_MAX;
extern	float phosphorus_MAX;
extern	float iron_MAX;
extern	float zinc_MAX;

extern UserInfo userInfo;
FILE * fp2;

#endif
