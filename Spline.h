#pragma once
#ifndef spline_h
#define spline_h

#include <vector>
#include "Point.h"

using namespace std;


class Spline{
	public:
		void Update_Spline(const vector<Point>& Points, const vector<double>& F_Value);
		void Get_Value(const Point& P, double* Res)const;
};

#endif