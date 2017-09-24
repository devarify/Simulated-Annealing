/**
*Arif Yulianto | 1301168560
*
*Mencari Minimum Fungsi yang diberikan dengan Simulated Annealing
*/

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "Header.h"

using namespace std;

float fungsi(float x1, float x2){
	return (4 - 2.1*pow(x1, 2) + pow(x1, 4) / 3)*pow(x1, 2) + x1*x2 + (-4 + 4 * pow(x2, 2))*pow(x2, 2);
}

float RandomNumber() {
	float random = ((float)rand()) / (float)RAND_MAX;
	float diff = 20;
	float r = random * diff;
	return -10 + r;
}

float prob(float x1, float x2, float T) {
	return pow(2.71828, (x1 - x2) / T);
}

void SimulatedAnnealing() {
	float new_x1, new_x2, newstate, accept_prob;
	float x1 = RandomNumber();
	float x2 = RandomNumber();
	float currentstate = fungsi(x1, x2);
	float T = 1000.0;
	float Tmin = 0.000000001;
	float alpha = 0.9;
	while (T > Tmin) {
		int i = 1;
		while (i <= 50000) {
			new_x1 = RandomNumber();
			new_x2 = RandomNumber();
			newstate = fungsi(new_x1, new_x2);
			accept_prob = prob(currentstate, newstate, T);
			if (accept_prob> rand()) {
				currentstate = newstate;
				x1 = new_x1;
				x2 = new_x2;
			}
			i++;
		}
		T = T*alpha;
		printf("Nilai x1 : %f\t", x1);
		printf("Nilai x2 : %f\t", x2);
		printf("Nilai Minimum: %f\n", fungsi(x1, x2));

	}

}

int main()
{
	header();
	srand((unsigned)time(NULL));
	SimulatedAnnealing();
	printf("Press Enter To Continue..");
	getchar();
	return 0;
}

