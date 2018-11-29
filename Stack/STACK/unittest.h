#ifndef UNITTEST_H_INCLUDED
#define UNITTEST_H_INCLUDED




long int unit_test_error_count = 0;

//--------------------------------------------------------------------------------------------------------------------------------------
/**
 *	UNITTEST
 *
 *	unit test to check anything.
 *  enter two variables, specify how to compare and types of variables.
 *  If the unit test fails, the error information will be in the unit test file.
 *
 */

#define UNITTEST(var1,oper,var2,type1,type2)											\
	{																					\
                                                                                        \
		if((var1 oper var2) == 0)														\
			{																			\
				fprintf(unit_test, "\n  ERROR %ld:\n\n", ++unit_test_error_count);		\
																						\
				fprintf(unit_test, "  %s %s %s - false\n", #var1, #oper, #var2);		\
				fprintf(unit_test, "  ");												\
				fprintf_##type1(var1_, unit_test);										\
				fprintf(unit_test, "  %s ", #oper);										\
				fprintf_##type2(var2_, unit_test);										\
				fprintf(unit_test, " - false\n\n");										\
																						\
				fprintf(unit_test, "  file: %s\n", __FILE__);							\
				fprintf(unit_test, "  function: %s\n", __FUNCTION__);					\
				fprintf(unit_test, "  line: %d\n\n", __LINE__);							\
				fprintf(unit_test, "  data: %s\n", __DATE__);							\
				fprintf(unit_test, "  time: %s\n\n\n", __TIME__);						\
			}																			\
	}																					\


#endif // UNITTEST_H_INCLUDED
