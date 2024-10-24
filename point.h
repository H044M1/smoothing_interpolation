#pragma once
#ifndef point_h
#define point_h

class Point{
	private:

		double X, Y, Z;
	public:

		Point(double x, double y, double z);
		double x()const;
		double y()const;
		double z()const;
};

#endif


