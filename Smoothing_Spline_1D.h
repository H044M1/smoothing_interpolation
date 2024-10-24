#ifndef Smoothing_Spline_1D_h
#define Smoothing_Spline_1D_h

#include "Spline.h"
#include <cmath>
#include <stdexcept>

class Smoothing_Spline_1D : public Spline{
	private:
		double SMOOTH;
		vector<Point> Points;
		vector<double> alpha;
		void Transition_To_Master_Element(int Seg_Num, const double& X, double& Ksi) const;
		double Basis_Function(int Number, const double& Ksi) const;
		double Der_Basis_Function(int Number, const double& Ksi) const;
	public:
		Smoothing_Spline_1D(const double& SMOOTH);
		void Update_Spline(const vector<Point>& Points, const vector<double>& F_Value);
		void Get_Value(const Point& P, double* Res)const;
};

#endif