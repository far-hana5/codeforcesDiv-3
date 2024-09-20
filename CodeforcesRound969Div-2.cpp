#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T; 
    
    for (int i = 0; i < T; i++) {
        int l, r;
        cin >> l >> r;  
        
        cout << ((r + 1) / 2 - l / 2) / 2 << endl;
    }
    
    return 0;
}
