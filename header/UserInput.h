#ifndef __USER_INPUT_H__
#define __USER_INPUT_H__
void CheckUserExist(void);
void getUserInfoReference(void);
void getInputFoodInfo(void);
void SearchContext(char * input, int * idx_buf);
void UserSelectFood(int * idx_buf);
void PushUserSelectFoodData(int n, int * idx_buf);
void ShowMyAteInfo(void);

extern User * cur_user;
extern UserInfo my_info;
extern int ref_idx = 0;
#endif
