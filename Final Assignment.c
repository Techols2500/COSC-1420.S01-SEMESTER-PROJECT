/*
DESCRIPTION: Programming Excerise Final
CLASS: COSC 1420.SO1
AUTHOR: TYLER ECHOLS
DATE: May 2019
*/ 

#pragma warning (disable:4996)

#include <conio.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include "Complex.h"


int main()
{
	FILE *	pFile;
	int		RetCode = 0;
	char	Text[121];
	
	int		i;
	int		j;
	int		k;

	int		NumColsInA;
	int		NumColsInB;
	int		NumRowsInA;



	struct Complex		Answer; 
	struct Complex **	A;
	struct Complex **	B;
	struct Complex **	C;
	struct Complex		Alpha; 


	printf("Enter Name of File: \n");
	
	scanf("%s", Text); 
	
	pFile = fopen(Text, "r");
	if (pFile == NULL)
		printf("Could not open the file\n");
	else
	{
		printf("FIle was opened\n");
		if (RetCode == EOF)
		{
			printf("Got to end of file\n");

			fclose(pFile);
		}
		else
		{
			fscanf(pFile, "%d %d %d", &NumRowsInA, &NumColsInA, &NumColsInB);
			printf(" %d %d %d\n", NumRowsInA, NumColsInA, NumColsInB);
			A = (struct Complex **)malloc(NumRowsInA * sizeof(struct Complex *));
			for (i = 0; i < NumRowsInA; i++)
				A[i] = (struct Complex *)malloc(NumColsInA * sizeof(struct Complex));

			B = (struct Complex **)malloc(NumColsInA * sizeof(struct Complex *));
			for (i = 0; i < NumColsInA; i++)
				B[i] = (struct Complex *)malloc(NumColsInB * sizeof(struct Complex));
			
			
			C = (struct Complex **)malloc(NumRowsInA * sizeof(struct Complex *));
			for (i = 0; i < NumRowsInA; i++)
				C[i] = (struct Complex *)malloc(NumColsInB * sizeof(struct Complex));
				
			for (i = 0; i < NumRowsInA; i++)
			{
				for (j = 0; j < NumColsInA; j++)
					fscanf(pFile, " (%lf %lf)", &A[i][j].R, &A[i][j].I);
			}


		

			for (i = 0; i < NumColsInA; i++)
			{
				for (j = 0; j < NumColsInB; j++)
					fscanf(pFile, " (%lf %lf)", &B[i][j].R, &B[i][j].I);

			}

			Alpha.R = 0.0;
			Alpha.I = 0.0;
			for (i = 0; i < NumRowsInA; i++)
			{
				
				for (j = 0; j < NumColsInB; j++)
				{
					for (k = 0; k < NumColsInA; k++)
					{
						Answer = Mul(A[i][k], B[k][j]);
						Alpha = Add(Alpha, Answer);
						
					}
					C[i][j] = Alpha;
					Alpha.R = 0.0;
					Alpha.I = 0.0;
				}
			}
			for (i = 0; i < NumRowsInA; i++)
			{
				for (j = 0; j < NumColsInB; j++)
					printf("(%lf %lf)", C[i][j].R, C[i][j].I);
				printf("\n");
			}

			fclose(pFile);
			
			
			
		}

		

			for (i = 0; i < NumRowsInA; i++)
			{
				free(A[i]);
			}
			free(A);

			for (i = 0; i< NumColsInA; i++)
			{
				free(B[i]);
			}
			free(B);
			 
			for (i = 0; i < NumRowsInA; i++)
			{
				free(C[i]);
			}
			free(C);
	}

	 
	printf("End of Program, hit any key to continue");
	_getch();

	return 0;
}
