#include <stdio.h>
#include <stdlib.h>
#include "./Include/add.h"
#include "./Include/sub.h"
#include "./Include/mod.h"
#include "./Include/mul.h"
#include "./Include/div.h"
int main()
{
	float num1 =3.5 , num2 =7.5 , result =0.0;
	int num3 = 5, num4 = 2;
	
	result = add_fn (num1 , num2);
	printf("The Addition of %f and %f equal %f \n",num1,num2,result);
	
	
	result = sub_fn (num1 , num2);
	printf("The subtraction of %f and %f equal %f \n",num1,num2,result);
	
	
	result = mul_fn (num1 , num2);
	printf("The multiplication of %f and %f equal %f \n",num1,num2,result);
	
	
	result = div_fn (num1 , num2);
	printf("The division of %f and %f equal %f \n",num1,num2,result);
	
	
	result = mod_fn(num3 , num4);
	printf("The modulus of %d and %d equal %d \n",num3,num4,(int)result);
	

	return 0;
}
