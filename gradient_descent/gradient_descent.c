/*************************************************************************
    > File Name: gradient_descent.c
    > Author: wuyilun
    > Mail: wuyilun526@163.com 
    > Created Time: Fri 13 May 2016 05:09:49 AM CST
 ************************************************************************/

#include<stdio.h>

int main(void)
{
	float matrix[4][2] = {
		{1,4},{2,5},{5,1},{4,2}
	};
	float result[4] = {
		19,26,19,20
	};
	float theta[2] = {0,0};
	float learning_rate = 0.01;
	float loss = 1000.0;

	for(int i = 0; i<1000 && loss>0.0001; ++i){
		
		float error_sum = 0.0;
		for(int j = 0; j<4; ++j){

			float h = 0.0;

			for(int k = 0; k<2; ++k){

				h += matrix[j][k] * theta[k];

			}

			error_sum = result[j] - h;

			for(int k = 0; k < 2; ++k){

				theta[k] += learning_rate * error_sum * matrix[j][k];

			}

		}
		
		printf("*****************************************************\n");
		printf("theta now: %f, %f\n", theta[0], theta[1]);

		loss = 0.0;

		for(int j = 0; j<4; ++j){

			float sum = 0.0;

			for(int k = 0; k<2; ++k){

				sum += matrix[j][k] * theta[k];

			}

			loss += (sum - result[j]) * (sum - result[j]);

		}

		printf("loss now: %f\n", loss);

	}

	return 0;

}
