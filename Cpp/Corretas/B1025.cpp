#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int c, n, q;
  
  while (cin >> n >> q && n && q) {
    vector<int> marbles(n);
    
    for (int i = 0; i < n; i++) {
      cin >> marbles[i];
    }

    sort(marbles.begin(), marbles.end());

    cout << "CASE# " << c + 1 <<":"<< endl;
    for (int i = 0; i < q; i++) {
      int x;
      cin >> x;

      // Encontrar a posição do número x usando busca binária
      auto it = lower_bound(marbles.begin(), marbles.end(), x);

      if (it != marbles.end() && *it == x) {
        cout << x << " found at " << (it - marbles.begin() + 1) << endl;
      } else {
        cout << x << " not found" << endl;
      }
    }
    //isso foi uma referencia?
    c++;
  }
  return 0;
}
