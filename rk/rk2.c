#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "read_array.h"
#include "merge.h"
#include "sdvig.h"

#define OK 0
#define NOT_ALL_ARGUMENTS -1
#define NO_FILE_X -2
#define NO_FILE_Y -3
#define INCORRECT_SIZE -4
#define ARRAY_EMPTY -5
#define INCORRECT_ELEMENT -6

 int main(int argc, char** argv)
 {
	int size1;
	int size2;
	int err;
	FILE *fx;
	FILE *fy;
	int *xb;
	int *xe;
	int *yb;
	int *ye;
	
	 
	if (argc != 3)
	{
		fprintf(stderr,"main.exe <filename> <filename>\n");
		err = NOT_ALL_ARGUMENTS;		 
	}
	else
	{
		fx = fopen(argv[1],"r");
		if (fx == NULL)
		{
			fprintf(stderr,"%s\n",strerror(errno));
			err = NO_FILE_X;
		}
		else
		{
			fy = fopen(argv[2],"r");
			if (fy == NULL)
			{
				fprintf(stderr,"%s\n",strerror(errno));
				err = NO_FILE_Y;
			}
			else
			{
				if (fscanf(fx,"%d",&size1) != 1)
				{
					printf("Incorrect size of array\n");
					err = INCORRECT_SIZE;
				}

				else
				{
					int a[size1];
					xb = a;
					xe = a;
					err = read_array(fx, &xb,&xe,size1);
					switch(err)
					{
						case INCORRECT_ELEMENT:
						{
							printf("Incorrect element in array\n");
							err = INCORRECT_ELEMENT;
							break;
						}
						case ARRAY_EMPTY:
						{
							printf("Array is empy\n");
							err = ARRAY_EMPTY;
							break;
						}
						case OK:
						{
							if (fscanf(fy,"%d",&size2) != 1)
							{
								printf("Incorrect size of array\n");
								err = INCORRECT_SIZE;
							}
							
							else
							{
								int b[size2];
								yb = b;
								ye = b;
								err = read_array(fy, &yb,&ye,size2);
								switch(err)
								{
									case INCORRECT_ELEMENT:
									{
										printf("Incorrect element in array\n");
										err = INCORRECT_ELEMENT;
										break;
									}
									case ARRAY_EMPTY:
									{
										printf("Array is empy\n");
										err = ARRAY_EMPTY;
										break;
									}
									case OK:
									{
										int c[size1+size2];
										int *zb = c;
										merge(xb,size1,yb,size2,zb);
										for (int i = 0;i< size1+size2; i++)
										{
											printf("%d ",*(zb+i));
										}
										sdvig(zb,size1+size2,4);
										for (int i = 0;i< size1+size2; i++)
										{
											printf("%d ",*(zb+i));
										}

									}
								}
							}
						}
					}
				}
			}	 
		}
	}
	return err;
 }