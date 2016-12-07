extern User * user;
extern int * user_len;
User * cur_user;
void CheckUserExist(void)
{
	int len = *user_len;
	char input_name[10] = {0, };

	printf("이름을 입력해주세요.\n");
	scanf("%s", input_name);

	if(CheckUserDataBase(input_name)){
		
	}else{

	}
}

int CheckUserDataBase(char * input_name)
{
	int i, len = *user_len;

	for(i = 0; i < len; i++){
		if(!strcmp(user[i].name, input_name)){
			return i;
		}
	}
	return 0;
}
