#ifndef __COMMON_DEFINE_H__
#define __COMMON_DEFINE_H__

#ifndef PROCESS_ERROR
#define PROCESS_ERROR(Condition)\
	do\
	{\
		if (!Condition) \
		{\
			goto Exit0;\
		}\
	}while (false)
#endif

#ifndef PROCESS_SUCESS
#define PROCESS_SUCESS(Condition)\
	do \
	{\
		if (Condition)\
		{\
			goto Exit1;\
		}\
	} while (false);
#endif

#endif