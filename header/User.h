#ifndef __USER_H__
#define __USER_H__

typedef struct _user {
	char * name;
	int age_weight;
}User;

void getUserDB(void);
void InitUserFileDescriptor(void);
int FindUserNumber(void);
void AllocateUserMemory(int len);
void SaveUser(void);
void releaseUserMemory(void);
int FIndSpecificMember(char * name);
void ShowSpecificMember(int n);

extern User * user;
extern int * user_len;

#endif
