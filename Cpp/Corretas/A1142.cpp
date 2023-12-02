    #include <bits/stdc++.h>
    #include <vector>
    using namespace std;
    
    int main() {

        int flag;
        cin>>flag;

        for(int i = 1; i <= flag*4; i++) {
            if (i % 4 == 0){
                cout << "PUM" <<endl;
                continue;
            }
            cout << i<<" ";


        };
        return 0;
    }