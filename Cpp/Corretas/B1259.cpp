#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

void showNumbers(vector<int>& numbers){
    for(int i : numbers){
        cout << i <<endl;
    }
}

int main() {
    vector<int>  pairs, odds;
    int quantyNumbers, number;

    cin >> quantyNumbers;

    //preechendo os vetores
    while(quantyNumbers > 0) {
        cin >> number;
        //adiciona aos pares;
        if(number %2 == 0){
            pairs.push_back(number);
        }
        //adiciona aos ímpares;
        else{
            odds.push_back(number);
        }
        quantyNumbers --;
    }
    //arrumando os pares;
    sort(pairs.begin(),pairs.end());
    //arrumando os ímpares;
    sort(odds.begin(),odds.end(), greater<int>());

    //Mostrando os números;
    showNumbers(pairs);
    showNumbers(odds);

    return 0;
}