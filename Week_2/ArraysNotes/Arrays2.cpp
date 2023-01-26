#include <iostream>
#include "input.h"

using namespace std;

const long MAX_SIZE = 100;

long Input(double x[]);
void Display(double x[], long maxValues);
double CalcAverage(double x[], long maxValues);

long Input(double x[])
{
	long numberOfValues;
	numberOfValues = ReadValue<int>("# of values? ", 0, MAX_SIZE);
	for (long i = 0; i < numberOfValues; i++) {
		x[i] = ReadValue<double>("Value? ");
	}
	return numberOfValues;
}

void Display(double x[], long maxValues)
{
	for (long i = 0; i < maxValues; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

double CalcAverage(double x[], long maxValues)
{
	double sum = 0.0;
	for (long i = 0; i < maxValues; i++) {
		sum += x[i];
	}
	return sum / maxValues;
}

int main()
{
	long arraySize = 0;
	double values[MAX_SIZE];

	arraySize = Input(values);
	double avg = CalcAverage(values, arraySize);
	Display(values, arraySize);
	cout << "Average Value: " << avg << endl;

	return 0;
}