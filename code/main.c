#include "getFunction.c"
int main(void)
{
	InitFileDescriptor();
	InitDateBase();
	testPrint();
	printf("name : %s\n", getName(2));
	releaseMemory();
	return 0;
}
