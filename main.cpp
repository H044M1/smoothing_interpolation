#include "Point.h"
#include "Cubic_interpolation_spline_1D.h"
#include "Smoothing_Spline_1D.h"
#include <algorithm> 
#include <iostream> 
#include <cmath>
#include <random>
#include <string>
#include "SaveResults.h"
#define M_PI 3.14159265358979323846

using namespace std;

int observations_numbers = 10;


int main() {

    Cubic_Interpolation_Spline_1D interpolation_spline;
    Smoothing_Spline_1D smoothing_spline_0(0);
    Smoothing_Spline_1D smoothing_spline_33(0.33);
    Smoothing_Spline_1D smoothing_spline_66(0.66);
    Smoothing_Spline_1D smoothing_spline_99(0.99);
    double mean = 1.01, stddev = 3.88, num_points = observations_numbers;
    vector<double> values_y, interpolated, smoothed0, smoothed33, smoothed66, smoothed99;
    vector<Point> values_x;
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<> dist(mean, stddev);
    for (int i = 0; i < num_points; ++i) {
        double x = i;
        double y = dist(gen);
        values_y.push_back(y);
        values_x.push_back(Point(x, 0, 0));
    }

    double result_inter[3], result_smooth0[3], result_smooth33[3], result_smooth66[3], result_smooth99[3];
    interpolation_spline.Update_Spline(values_x, values_y);
    smoothing_spline_0.Update_Spline(values_x, values_y);
    smoothing_spline_0.Update_Spline(values_x, values_y);
    smoothing_spline_33.Update_Spline(values_x, values_y);
    smoothing_spline_66.Update_Spline(values_x, values_y);
    smoothing_spline_99.Update_Spline(values_x, values_y);
    for (int i = 0; i < observations_numbers; i++) {
        interpolation_spline.Get_Value(values_x[i], result_inter);
        smoothing_spline_0.Get_Value(values_x[i], result_smooth0);
        smoothing_spline_33.Get_Value(values_x[i], result_smooth33);
        smoothing_spline_66.Get_Value(values_x[i], result_smooth66);
        smoothing_spline_99.Get_Value(values_x[i], result_smooth99);
        interpolated.push_back(result_inter[0]);
        smoothed0.push_back(result_smooth0[0]);
        smoothed33.push_back(result_smooth33[0]);
        smoothed66.push_back(result_smooth66[0]);
        smoothed99.push_back(result_smooth99[0]);
        cout << "Original Y value: " << values_y[i]
            << " | Interpolated result: " << result_inter[0]
            << " | Smoothed (p = 0): " << result_smooth0[0]
            << " | Smoothed (p = 0.33): " << result_smooth33[0]
            << " | Smoothed (p = 0.66): " << result_smooth66[0]
            << " | Smoothed (p = 0.99): " << result_smooth99[0] << endl;

    }

    string filename = "spline_results.txt";
    save_to_file(values_y, interpolated, smoothed0, smoothed33, smoothed66, smoothed99, filename);

    return 0;
}