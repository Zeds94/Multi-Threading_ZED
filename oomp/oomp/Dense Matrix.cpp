#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <omp.h>
#include <vector>
using namespace std;




int main()
{
	double _start = omp_get_wtime();
	const int n = 10000;
	std::vector< std::vector<int> >A(n, std::vector<int>(n));
	//vector< vector<int> > A(n, vector<int>(n));
	int x[n];
	int y[n];
	int _sum[n] = { 0 };



	omp_set_num_threads(12);
#pragma omp parallel for schedule(guided)
	for (int i = 0; i < n; i++)
	{
#pragma omp parallel for schedule(guided)
		for (int j = 0; j < n; j++)
		{
			A[i][j] = rand() % 10;
		}
		x[i] = rand() % 10;
		y[i] = rand() % 10;
		//cout << "x[" << i << "]=" << x[i] << " y[" << i << "] = " << y[i] << endl;

	}

#pragma omp parallel for schedule(guided)
	for (int i = 0; i < n; i++)
	{

#pragma omp parallel for schedule(guided)
		for (int j = 0; j < n; j++)
		{
			_sum[i] += A[i][j] * x[j];

		}
		//cout << "Sum = " << _sum[i] << endl;
		y[i] = y[i] + _sum[i];

	}

	for (int i = 0; i < n; i++)
	{
		//cout << "X[" << i << "]=" << x[i] << " y[" << i << "]=" << y[i] << endl;
		//cout << " y[" << i << "]=" << y[i] << endl;
		//cout << "x["<< i <<"] = " << x[i] << endl;
	}

	double _end = omp_get_wtime();
	cout << "\nTime = " << _end - _start << endl;
}