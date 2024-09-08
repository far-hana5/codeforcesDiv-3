#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pp;
typedef long long ll;

// Custom comparator to sort pairs based on the absolute difference between their first and second values
bool cmp(pp a, pp b) {
    return abs(a.first - a.second) > abs(b.first - b.second);
}

int main() {
    
    int n, m;
    cin >> n >> m;

    vector<pp> a(n);
    ll totalSum = 0;

    // Read the input pairs and calculate the initial total sum of the first values
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
        totalSum += (ll)x;
    }

    // Sort pairs based on the absolute difference using custom comparator
    sort(a.begin(), a.end(), cmp);

    int ans = 0; // Counter for number of swaps

    // Try to reduce the sum by swapping first and second values of pairs
    for (int i = 0; i < n; i++) {
        if (totalSum <= m) {
            break; // If total sum is already less than or equal to m, stop
        }

        // Adjust the total sum by swapping the first and second values
        totalSum -= (ll)a[i].first;
        totalSum += (ll)a[i].second;
        ans++; // Count the number of swaps made
    }

    // If it's impossible to reduce the sum to be <= m, output -1
    if (totalSum > m) {
        cout << -1 << endl;
    } else {
        cout << ans << endl; // Output the number of swaps
    }

   
}
