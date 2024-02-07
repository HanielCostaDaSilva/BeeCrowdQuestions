#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool isPythagoreanTriple(int x, int y, int z) {
    int sides[3] = {x, y, z};
    sort(sides, sides + 3); 

    return sides[0]*sides[0] + sides[1]*sides[1] == sides[2]*sides[2];
}

bool isPrimitive(int x, int y, int z) {
    return gcd(x, gcd(y, z)) == 1;
}

int main() {
    int x, y, z;

    while (cin >> x >> y >> z) {
        if (isPythagoreanTriple(x, y, z)) {
            if (isPrimitive(x, y, z)) {
                cout << "tripla pitagorica primitiva" << endl;
            } else {
                cout << "tripla pitagorica" << endl;
            }
        } else {
            cout << "tripla" << endl;
        }
    }

    return 0;
}
