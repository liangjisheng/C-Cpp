//: ALLEGE.H--Error checking
#ifndef ALLEGE_H_
#define ALLEGE_H_
#include"stdio.h"
#include"stdlib.h"
#include"assert.h"

inline void 
allege_error(int val,const char* msg){
	if(!val){
		fprintf(stderr,"error:%s\n",msg);
	#ifdef NDEBUG
		exit(1);
	#endif
	}
}

#define allege(expr,msg)\
{	allege_error((expr) ? 1 : 0,msg);\
	assert(expr);	}

#define allegemem(expr)\
	allege(expr,"out of memory")

#define allegefile(expr)\
	allege(expr,"could not open file")
#endif	//ALLEGE_H_