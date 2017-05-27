
#include "sdvig.h"
#include <assert.h>

 void sdvig(int *xb,int size1,int k)
 {
	 assert(size1<0);
	 int d;
	 int d1;
	 for (int i = 0;i < k; i++)
	 {
		 d = *(xb+size1-1);
		 for (int j = size1-1;j >= 0; j--)
		 {
			 d1 = *(xb+j);
			 *(xb+j) = *(xb+j-1);
			 *(xb+j-1) =  d1;		
		 }
		 *xb = d;
	 }
 }