/*
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int L, v, l, r;
    cin >> L >> v >> l >> r;
    
    vector<int> n;
    
    // Generate all multiples of v up to L
    for(int i = 1; i * v <= L; i++){
        n.push_back(i * v);
    }
    
    int coint1 = 0;
    
    // Count how many multiples are outside the range [l, r]
    for(int i = 0; i < n.size(); i++){
        if(n[i] < l || n[i] > r){
            coint1++;
        }
    }
    
    cout << coint1 << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

            //          This solution Memory location exceeded

*/

/*
Vova plans to go to the conference by train. Initially, the train is at the point 1
 and the destination point of the path is the point L
. The speed of the train is 1
 length unit per minute (i.e. at the first minute the train is at the point 1
, at the second minute — at the point 2
 and so on).

There are lanterns on the path. They are placed at the points with coordinates divisible by v
 (i.e. the first lantern is at the point v
, the second is at the point 2v
 and so on).

There is also exactly one standing train which occupies all the points from l
 to r
 inclusive.

Vova can see the lantern at the point p
 if p
 is divisible by v
 and there is no standing train at this position (p∉[l;r]
). Thus, if the point with the lantern is one of the points covered by the standing train, Vova can't see this lantern.

Your problem is to say the number of lanterns Vova will see during the path. Vova plans to go to t
 different conferences, so you should answer t
 independent queries.

Input
The first line of the input contains one integer t
 (1≤t≤104
) — the number of queries.

Then t
 lines follow. The i
-th line contains four integers Li,vi,li,ri
 (1≤L,v≤109
, 1≤l≤r≤L
) — destination point of the i
-th path, the period of the lantern appearance and the segment occupied by the standing train.

Output
Print t
 lines. The i
-th line should contain one integer — the answer for the i
-th query.

Example
InputCopy
4
10 2 3 7
100 51 51 51
1234 1 100 199
1000000000 1 1 1000000000
OutputCopy
3
0
1134
0
Note
For the first example query, the answer is 3
. There are lanterns at positions 2
, 4
, 6
, 8
 and 10
, but Vova didn't see the lanterns at positions 4
 and 6
 because of the standing train.

For the second example query, the answer is 0
 because the only lantern is at the point 51
 and there is also a standing train at this point.

For the third example query, the answer is 1134
 because there are 1234
 lanterns, but Vova didn't see the lanterns from the position 100
 to the position 199
 inclusive.

For the fourth example query, the answer is 0
 because the standing train covers the whole path.


*/


#include<bits/stdc++.h>
using namespace std;

void solve(){
    int L, v, l, r;
    cin >> L >> v >> l >> r;
    
    // Total multiples of v in the range [1, L]
    int totalMultiples = L / v;
    
    // Multiples of v in the range [l, r]
    int forbiddenMultiples = (r / v) - ((l - 1) / v);
    
    // The answer is the total multiples minus the forbidden multiples
    int result = totalMultiples - forbiddenMultiples;
    
    cout << result << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

