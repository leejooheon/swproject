#ifndef __USER_H__
#define __USER_H__

typedef struct _user {
	char * name;
	int age_weight;
}User;

extern void getUserDB(void);
extern void InitUserFileDescriptor(void);
extern int FindUserNumber(void);
extern void AllocateUserMemory(int len);
extern void SaveUser(void);
extern void releaseUserMemory(void);
extern int FIndSpecificMember(char * name);
extern void ShowSpecificMember(int n);

extern User * user;
extern int * user_len;

#endif
