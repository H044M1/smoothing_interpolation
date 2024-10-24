#pragma once
#ifndef Cubic_Interpolation_Spline_1D_h
#define Cubic_Interpolation_Spline_1D_h

#include "Spline.h"
#include <cmath>
#include <stdexcept>

using namespace std;

class Cubic_Interpolation_Spline_1D : public Spline{
	private:
		vector<Point> Points;
		vector<double> a, b, c, d;
	public:
		void Update_Spline(const vector<Point>& Points, const vector<double>& F_Value);
		void Get_Value(const Point& P, double* Res)const;
};


#endif

