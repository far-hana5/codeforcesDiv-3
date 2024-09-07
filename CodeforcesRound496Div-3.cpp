
/*
C. Summarize to the Power of Two
time limit per test3 seconds
memory limit per test256 megabytes
A sequence a1,a2,…,an
 is called good if, for each element ai
, there exists an element aj
 (i≠j
) such that ai+aj
 is a power of two (that is, 2d
 for some non-negative integer d
).

For example, the following sequences are good:

[5,3,11]
 (for example, for a1=5
 we can choose a2=3
. Note that their sum is a power of two. Similarly, such an element can be found for a2
 and a3
),
[1,1,1,1023]
,
[7,39,89,25,89]
,
[]
.
Note that, by definition, an empty sequence (with a length of 0
) is good.

For example, the following sequences are not good:

[16]
 (for a1=16
, it is impossible to find another element aj
 such that their sum is a power of two),
[4,16]
 (for a1=4
, it is impossible to find another element aj
 such that their sum is a power of two),
[1,3,2,8,8,8]
 (for a3=2
, it is impossible to find another element aj
 such that their sum is a power of two).
You are given a sequence a1,a2,…,an
. What is the minimum number of elements you need to remove to make it good? You can delete an arbitrary set of elements.

Input
The first line contains the integer n
 (1≤n≤120000
) — the length of the given sequence.

The second line contains the sequence of integers a1,a2,…,an
 (1≤ai≤109
).

Output
Print the minimum number of elements needed to be removed from the given sequence in order to make it good. It is possible that you need to delete all n
 elements, make it empty, and thus get a good sequence.

Examples
InputCopy
6
4 7 1 5 4 9
OutputCopy
1
InputCopy
5
1 2 3 4 5
OutputCopy
2
InputCopy
1
16
OutputCopy
1
InputCopy
4
1 1 1 1023
OutputCopy
0
Note
In the first example, it is enough to delete one element a4=5
. The remaining elements form the sequence [4,7,1,4,9]
, which is good.


*/



#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;  // Input the size of the sequence
    vector<int> arr(n);  // Store the sequence
    map<int, int> frequency;  // Frequency map to count occurrences of each number

    // Step 1: Input the sequence and build the frequency map
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        frequency[arr[i]]++;  // Count how many times each number appears
    }

    int elementsToRemove = 0;  // This will store the count of elements to remove

    // Step 2: Iterate over each element in the sequence
    for (int i = 0; i < n; i++) {
        bool foundPair = false;  // Flag to check if we can find a valid pair

        // Step 3: Check for each power of 2 (up to 2^30, because 2^30 > 10^9)
        for (int j = 0; j < 31; j++) {
            int target = (1 << j) - arr[i];  // Calculate the complement

            // Step 4: Check if the complement exists in the frequency map
            if (frequency.count(target)) {
                // Ensure it's a valid pair (not the same element or has more than 1 occurrence)
                if (target != arr[i] || frequency[target] > 1) {
                    foundPair = true;  // Found a valid pair, no need to remove this element
                    break;
                }
            }
        }

        // Step 5: If no valid pair was found, this element must be removed
        if (!foundPair) {
            elementsToRemove++;
        }
    }

    // Step 6: Output the result (minimum number of elements to remove)
    cout << elementsToRemove << endl;

    return 0;
}

