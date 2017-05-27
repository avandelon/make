#include "merge.h"
#include <assert.h>

void merge(int *xb,int size1,int *yb, int size2,int *zb)
 {
	 int *xb_clone = xb;
	 int *yb_clone = yb;
	 for (int i = 0;i < size1+size2; i++)
	 {
		 if ((xb-xb_clone != size1 && *xb < *yb)  || (yb-yb_clone == size2))
		 {
			 *zb = *xb;
			 zb = zb + 1;
			 xb = xb + 1;			 
		 }
		 else
		 {
			*zb = *yb;
			zb = zb + 1;
			yb = yb + 1;
			 
		 }
	 }
 }