// oomp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <omp.h>
#include <stdio.h>
#include <iostream>

using namespace std;
int n = 100000000;
double res = 0.0, res1 = 0.0, res2 = 0.0, res3 = 0.0;
double area = 0.0, area1 = 0.0, area2 = 0.0, area3 = 0.0;
double deltaX = (1.0 / n);

void nothreads()
{
	cout << "No Threads" << endl;
	double time_ini = omp_get_wtime();
		for (int i = 0; i <= n; i++)
		{
			res = (4.0 / (1.0 + ((deltaX*i)*(deltaX*i))));
			area += res * deltaX;
		}
		double time_fin = omp_get_wtime();
		cout.precision(14);
		cout << "Area = " << area << endl;
		cout << "Time = " << time_fin - time_ini << endl;
}

void cuatrothreads()
{
	cout << "4 Threads" << endl;
	double time_ini1 = omp_get_wtime();
	#pragma omp parallel for num_threads(4) reduction (+: area1)
	for (int j = 0; j <= n; j++)
	{
		res1 = (4.0 / (1.0 + ((deltaX*j)*(deltaX*j))));
		area1 += res1 * deltaX;
	}
	double time_fin1 = omp_get_wtime();
	cout.precision(14);
	cout << "Area = " << area1 << endl;
	cout << "Time = " << time_fin1 - time_ini1 << endl;

}

void ochothreads()
{
	cout << "8 Threads" << endl;
	double time_ini1 = omp_get_wtime();
	#pragma omp parallel for num_threads(8) reduction (+: area2)
	for (int j = 0; j <= n; j++)
	{
		res1 = (4.0 / (1.0 + ((deltaX*j)*(deltaX*j))));
		area2 += res1 * deltaX;
	}
	double time_fin1 = omp_get_wtime();
	cout.precision(14);
	cout << "Area = " << area2 << endl;
	cout << "Time = " << time_fin1 - time_ini1 << endl;

}

void docethreads()
{
	cout << "12 Threads" << endl;
	double time_ini1 = omp_get_wtime();
	#pragma omp parallel for num_threads(12) reduction (+: area3)
		for (int j = 0; j <= n; j++)
		{
			res1 = (4.0 / (1.0 + ((deltaX*j)*(deltaX*j))));
			area3 += res1 * deltaX;
		}
		double time_fin1 = omp_get_wtime();
		cout.precision(14);
		cout << "Area = " << area3 << endl;
		cout << "Time = " << time_fin1 - time_ini1 << endl;

}


int main1()
{
	nothreads();
	cuatrothreads();
	ochothreads();
	docethreads();
	
}
