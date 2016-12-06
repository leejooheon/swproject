int main(void) 
{ 
	InitFoodDBFileDescriptor(); 
	InitFoodDateBase(); 
	testPrint(); 
	printf("name : %s\n", getName(2)); 
	releaseFoodDBMemory(); 
	return 0; 
} 

