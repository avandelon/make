 #include <stdio.h>
 #include "read_array.h"
 
 #define OK 0
 #define ARRAY_EMPTY -5
 #define INCORRECT_ELEMENT -6
 
 int read_array(FILE *f, int ** const pb, int ** const pe,int n)
 {
	int err = OK;
	while(*pe-*pb<=n && fscanf(f,"%d",*pe) == 1)
	{
		*pe = *pe + 1;
	}
	if (*pe-*pb < n)
		err = INCORRECT_ELEMENT;
	if (*pe-*pb == 0)
		err = ARRAY_EMPTY;
	return err;	
 }