
#include "SaveResults.h"
using namespace std;

void save_to_file(const vector<double>& values_y, const vector<double>& interpolated,
    const vector<double>& smoothed0, const vector<double>& smoothed4,
    const vector<double>& smoothed8, const vector<double>& smoothed99,
    const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (size_t i = 0; i < values_y.size(); ++i) {
            file << values_y[i] << " " << interpolated[i] << " " << smoothed0[i]
                << " " << smoothed4[i] << " " << smoothed8[i] << " " << smoothed99[i] << "\n";
        }
        file.close();
    }
    else {
        cout << "the file does not open (error): " << filename << endl;
    }
}