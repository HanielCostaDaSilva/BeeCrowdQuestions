#include <bits/stdc++.h>


using namespace std;

double calculateCutArea(const vector<int>& stripLengths, double cutHeight) {
    double area = 0;
    for (int length : stripLengths) {
        area += max(0.0, static_cast<double>(length) - cutHeight);
    }
    return area;
}

int main() {
    int numberOfStrips;
    unsigned long long expectedArea;

    while (cin >> numberOfStrips >> expectedArea && (numberOfStrips || expectedArea)) {
        vector<int> stripLengths(numberOfStrips);
        unsigned long long totalArea = 0;

        for (int& length : stripLengths) {
            cin >> length;
            totalArea += length;
        }

        if (totalArea == expectedArea) {
            cout << ":D" << endl;
        } else if (totalArea < expectedArea) {
            cout << "-.-" << endl;
        } else {
            double lowerBound = 0, upperBound = *max_element(stripLengths.begin(), stripLengths.end());

            while (upperBound - lowerBound > 1e-6) {
                double midHeight = (lowerBound + upperBound) / 2;
                double area = calculateCutArea(stripLengths, midHeight);

                if (area >= expectedArea) {
                    lowerBound = midHeight;
                } else {
                    upperBound = midHeight;
                }
            }

            cout << fixed << setprecision(4) << upperBound << endl;
        }
    }

    return 0;
}
