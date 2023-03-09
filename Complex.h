#ifndef COMPLEX_H
#define COMPLEX_H

struct Complex
{
	double	R;
	double	I;
};

struct Complex Read();
void Display(const struct Complex);

struct Complex Add(struct Complex, struct Complex);
struct Complex Sub(struct Complex, struct Complex);
struct Complex Mul(struct Complex, struct Complex);
struct Complex Div(struct Complex, struct Complex);

#endif
