#pragma warning (disable:4996)
#include <stdio.h>
#include <conio.h>
#include "Complex.h"

struct Complex Read()
{
	struct Complex Num1;
	char c;
	printf("insert Real Number: ");
	scanf("%lf", &Num1.R);
	scanf("%c", &c);
	printf("Enter Imanginary Num2: ");
	scanf("%lf", &Num1.I);
	scanf("%c", &c);

	return Num1;

}

void Display(const struct Complex Num1)
{
	printf("Numbers Entred are (%lf,  %lfi)\n", Num1.R, Num1.I);

}
struct Complex Add(struct Complex Num1, struct Complex Num2)
{
	struct Complex Result;

	Result.R = Num1.R + Num2.R;
	Result.I = Num1.I + Num2.I;
	return Result;
}

struct Complex Sub(struct Complex Num1, struct Complex Num2)
{
	struct Complex Result;

	Result.R = Num1.R - Num2.R;
	Result.I = Num1.I - Num2.I;
	return Result;
}

struct Complex Mul(struct Complex Num1, struct Complex Num2)
{
	struct Complex Result;

	Result.R = ((Num1.R * Num2.R) - (Num1.I * Num2.I));
	Result.I = ((Num1.R * Num2.I) + (Num1.I * Num2.R));
	return Result;
}

struct Complex Div(struct Complex Num1, struct Complex Num2)
{
	struct Complex Result;
	double Squared;

	Squared = ((Num2.R * Num2.R) + (Num2.I * Num2.I));

	Result.R = (((Num1.R * Num2.R) + (Num1.I * Num2.I)) / Squared);
	Result.I = (((Num1.I * Num2.R) - (Num1.R * Num2.I)) / Squared);


	return Result;
}