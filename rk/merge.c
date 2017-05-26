#include "merge.h"

void merge(int *xb,int size1,int *yb, int size2,int *zb)
 {
	 for (int i = 0;i< size1+size2; i++)
	 {
		 if (*xb < *yb)
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