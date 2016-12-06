int main(void) 
{ 
//	getFoodDB();
	
//	printf("name : %s\n", getName(2));

	getUserDB();
	ShowAllMember();
	ShowSpecificMember(FIndSpecificMember("이주헌"));
	
	releaseUserMemory();
//	releaseFoodDBMemory();

	return 0; 
} 

