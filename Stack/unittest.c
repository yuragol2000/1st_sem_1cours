
#include "unittest.h"

//--------------------------------------------------------------------------------------------------------------------------------------
/**
 *   @function test()
 *
 *   @param[in] memory* test stack
 *
 */
void test(struct Stack* memory)
	{
	    FILE* unit_test = fopen("unit_test.txt","w");

		printf("Test 1 without attack\n");

		printf("STACK is pushing\n");

		for(int i = 0; i <= 1000; i++)
			{
				printf("\r");
				Push(memory,i);

			}
			if (Stack_OK(memory) != NO_PROBLEM )
                Dump_(memory);
		printf("STACK push is ok\n");

		printf("STACK is poping\n");

		for(int i = 1000; i >= 0; i--)
			{
				printf("\r");
				Push(memory,i);

			}
			if (Stack_OK(memory) != NO_PROBLEM )
                Dump_(memory);
		printf("STACK pop is ok\n\n");

		printf("Test 2 with attack\n");

		printf("STACK is pushing\n");

		for(int i = 0; i <=2000; i++)
			{
				printf("\r");
				Push(memory,i);

			}
		printf("STACK push is ok\n");
        			if (Stack_OK(memory) != NO_PROBLEM )
                Dump_(memory);
		printf("STACK is poping\n");

		for(int i = 2000; i >= 0; i--)
			{
				printf("\r");
				Pop(memory);
			}
			if (Stack_OK(memory) != NO_PROBLEM )
                Dump_(memory);
		printf("STACK pop is ok\n");

	}
