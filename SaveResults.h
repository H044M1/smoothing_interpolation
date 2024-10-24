#pragma once
#ifndef SaveResults_h
#define SaveResults_h

#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


void save_to_file(const vector<double>& values_y, const vector<double>& interpolated,
    const vector<double>& smoothed0, const vector<double>& smoothed4, const vector<double>& smoothed8,
    const vector<double>& smoothed99, const string& filename);

#endif

