#include<stdio.h>
#include<string.h>
#include<stdlib.h>

extern Food * food;
extern UserInfo * userInfo;
extern User * user;
extern int * user_len;

extern int FIndSpecificMember(char * name);

User * cur_user;
UserInfo my_info;
int ref_idx = 0;

void CheckUserExist(void)
{
	int n, len = *user_len;
	char input_name[10] = { 0, };

	printf("이름을 입력해주세요.\n");
	scanf("%s", input_name);

	if ((n = FIndSpecificMember(input_name)) != -1) {
		cur_user = &user[n];
		ClearUserInfo(&my_info);
	}
	else {
		printf("유저 정보를 추가하여 주십시오.\n");
		exit(1);
	}
}
void getUserInfoReference(void)
{
	if (cur_user->age_weight == 1) { // baby
		ref_idx = 0;
	}
	else if (cur_user->age_weight == 2) {
		ref_idx = 1;
	}
	else if (!strcmp(cur_user->sex, "남")) {
		if (cur_user->age_weight > 70) {
			ref_idx = 6;
		}
		else if (cur_user->age_weight > 60) {
			ref_idx = 5;
		}
		else {
			ref_idx = 4;
		}
	}
	else { // girl
		if (cur_user->age_weight > 50) {
			ref_idx = 3;
		}
		else {
			ref_idx = 2;
		}
	}
}
void getInputFoodInfo(void) 
{
	char buf[32] = { 0, };
	int idx_buf[1024];
	printf("****************************************\n");
	printf("- 오늘 하루 먹은 음식들을 입력해주세요.\n");
	printf("- 그만 입력하고 싶다면 x 를 입력해주세요.\n");
	printf("****************************************\n\n");
	while (strcmp(buf, "x")) {
		memset(buf, 0, 32);
		memset(idx_buf, -1, 1024);
		printf("입력 창 : ");
		scanf("%s", buf);
		SearchContext(buf, idx_buf); // 데이터 뽑아내기.
		if (idx_buf[1] != -1) { // 음식이 있다면
			UserSelectFood(idx_buf);// 유저가 이 중에서 선택해야함.
		} else { 
			printf("해당 음식이 DB에 존재하지 않습니다.\n");
			continue;
		}
	}
	ShowMyAteInfo();
	//먹은 데이터 분석
}
void UserSelectFood(int * idx_buf)
{
	int n;
	printf("선택하여 주십시오 : ");
	scanf("%d", &n);

	PushUserSelectFoodData(n, idx_buf);
}
void PushUserSelectFoodData(int n, int * idx_buf)
{
	my_info.calorie += food[idx_buf[n]].calorie;
	my_info.protein += food[idx_buf[n]].protein;
	my_info.vit_A += food[idx_buf[n]].vit_A;
	my_info.vit_E += food[idx_buf[n]].vit_E;
	my_info.vit_C += food[idx_buf[n]].vit_C;
	my_info.vit_B1 += food[idx_buf[n]].vit_B1;
	my_info.vit_B2 += food[idx_buf[n]].vit_B2;
	my_info.vit_B6 += food[idx_buf[n]].vit_B6;
	my_info.niacin += food[idx_buf[n]].niacin;
	my_info.folic_acid += food[idx_buf[n]].folic_acid;
	my_info.calcium += food[idx_buf[n]].calcium;
	my_info.phosphorus += food[idx_buf[n]].phosphorus;
	my_info.iron += food[idx_buf[n]].iron;
	my_info.zinc += food[idx_buf[n]].zinc;
}
void SearchContext(char * input, int * idx_buf)
{
	int i, idx = 0;
	char * str;
	for (i = 0; i < 3153; i++){
		if (str = strstr(food[i].food_name, input) != NULL) {
			idx++;
			idx_buf[idx] = i;
			printf("%d번 : %s\n", idx, food[i].food_name);
		}
	}
}
void ShowMyAteInfo(void)
{

	printf("************************************************************\n");
	printf("		기준 및 내가 먹은 음식들의 영양 성분\n");
	printf("************************************************************\n");

	printf("기준 칼로리     : %f	|", userInfo[ref_idx].calorie);
	printf("	칼로리	 : %f\n", my_info.calorie);

	printf("기준 단백질     : %f	|", userInfo[ref_idx].protein);
	printf("	단백질 	 : %f\n", my_info.protein);

	printf("기준 비타민A    : %f	|", userInfo[ref_idx].vit_A);
	printf("	비타민A	 : %f\n", my_info.vit_A);

	printf("기준 비타민E    : %f	|", userInfo[ref_idx].vit_E);
	printf("	비타민E	 : %f\n", my_info.vit_E);
	
	printf("기준 비타민C    : %f	|", userInfo[ref_idx].vit_C);
	printf("	비타민C	 : %f\n", my_info.vit_C);
	
	printf("기준 비타민B1   : %f	|", userInfo[ref_idx].vit_B1);
	printf("	비타민B1 : %f\n", my_info.vit_B1);
	
	printf("기준 비타민B2   : %f	|", userInfo[ref_idx].vit_B2);
	printf("	비타민B2 : %f\n", my_info.vit_B2);
	
	printf("기준 비타민B6   : %f	|", userInfo[ref_idx].vit_B6);
	printf("	비타민B6 : %f\n", my_info.vit_B6);
	
	printf("기준 나이아신   : %f	|", userInfo[ref_idx].niacin);
	printf("	나이아신 : %f\n", my_info.niacin);
	
	printf("기준 엽산	: %f	|", userInfo[ref_idx].folic_acid);
	printf("	엽산	 : %f\n", my_info.folic_acid);
	
	printf("기준 칼슘	: %f	|", userInfo[ref_idx].calcium);
	printf("	칼슘	 : %f\n", my_info.calcium);
	
	printf("기준 인		: %f	|", userInfo[ref_idx].phosphorus);
	printf("	인	 : %f\n", my_info.phosphorus);
	
	printf("기준 철		: %f	|", userInfo[ref_idx].iron);
	printf("	철 	 : %f\n", my_info.iron);
	
	printf("기준 아연	: %f	|", userInfo[ref_idx].zinc);
	printf("	아연 	 : %f\n\n", my_info.zinc);
}
