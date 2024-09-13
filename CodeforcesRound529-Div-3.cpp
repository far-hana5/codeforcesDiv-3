/*
B. Array Stabilization
time limit per test1 second
memory limit per test256 megabytes
You are given an array a
 consisting of n
 integer numbers.

Let instability of the array be the following value: maxi=1nai−mini=1nai
.

You have to remove exactly one element from this array to minimize instability of the resulting (n−1)
-elements array. Your task is to calculate the minimum possible instability.

Input
The first line of the input contains one integer n
 (2≤n≤105
) — the number of elements in the array a
.

The second line of the input contains n
 integers a1,a2,…,an
 (1≤ai≤105
) — elements of the array a
.

Output
Print one integer — the minimum possible instability of the array if you have to remove exactly one element from the array a
.

Examples
InputCopy
4
1 3 3 7
OutputCopy
2
InputCopy
2
1 100000
OutputCopy
0
Note
In the first example you can remove 7
 then instability of the remaining array will be 3−1=2
.

In the second example you can remove either 1
 or 100000
 then instability of the remaining array will be 100000−100000=0
 and 1−1=0
 correspondingly.



#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
        cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());

    long long diffForLargest=v[n-2]-v[0];
    long long diffForSmallest=v[n-1]-v[1];//1 3 3 7 7

    cout<<min(diffForLargest,diffForSmallest)<<endl;
}

*/

/*
A positive integer x
 is called a power of two if it can be represented as x=2y
, where y
 is a non-negative integer. So, the powers of two are 1,2,4,8,16,…
.

You are given two positive integers n
 and k
. Your task is to represent n
 as the sum of exactly k
 powers of two.

Input
The only line of the input contains two integers n
 and k
 (1≤n≤109
, 1≤k≤2⋅105
).

Output
If it is impossible to represent n
 as the sum of k
 powers of two, print NO.

Otherwise, print YES, and then print k
 positive integers b1,b2,…,bk
 such that each of bi
 is a power of two, and ∑i=1kbi=n
. If there are multiple answers, you may print any of them.

Examples
InputCopy
9 4
OutputCopy
YES
1 2 2 4 
InputCopy
8 1
OutputCopy
YES
8 
InputCopy
5 1
OutputCopy
NO
InputCopy
3 7
OutputCopy
NO

#include<bits/stdc++.h>
using namespace std;

int main(){

    long long n, k;
    cin >> n >> k;
    
    // A priority queue to store the powers of two (max heap)
    priority_queue<long long> pq;
    long long sum = 0;
    
    // Break down 'n' into powers of two and push them into the priority queue
    for(int i = 0; i < 31; i++){
        if(n & (1LL << i)) {
            pq.push(1LL << i); // Push each power of two that is a part of 'n'
            sum++;
        }
    }
    
    // If the number of powers of two is greater than 'k', it's impossible
    if(sum > k) {
        cout << "NO" << endl;
        return 0;
    }
    
    // Try to split larger powers of two into smaller ones to meet exactly 'k' terms
    while(sum < k) {
        long long top = pq.top();
        pq.pop();
        
        if(top == 1) break; // Can't split 1 any further

        pq.push(top / 2);   // Split the top element into two parts
        pq.push(top / 2);
        sum++;              // We increase the number of terms by 1
    }
    
    // If we can't make exactly 'k' parts, print "NO"
    if(sum != k) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        vector<long long> result;
        while(!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        
        // Output the result
        for(long long x : result) {
            cout << x << " ";
        }
        cout << endl;
    }
    
    return 0;
}

*/

/*
A. Repeating Cipher
time limit per test1 second
memory limit per test256 megabytes
Polycarp loves ciphers. He has invented his own cipher called repeating.

Repeating cipher is used for strings. To encrypt the string s=s1s2…sm
 (1≤m≤10
), Polycarp uses the following algorithm:

he writes down s1
 ones,
he writes down s2
 twice,
he writes down s3
 three times,
...
he writes down sm
 m
 times.
For example, if s
="bab" the process is: "b" →
 "baa" →
 "baabbb". So the encrypted s
="bab" is "baabbb".

Given string t
 — the result of encryption of some string s
. Your task is to decrypt it, i. e. find the string s
.

Input
The first line contains integer n
 (1≤n≤55
) — the length of the encrypted string. The second line of the input contains t
 — the result of encryption of some string s
. It contains only lowercase Latin letters. The length of t
 is exactly n
.

It is guaranteed that the answer to the test exists.

Output
Print such string s
 that after encryption it equals t
.

Examples
InputCopy
6
baabbb
OutputCopy
bab
InputCopy
10
ooopppssss
OutputCopy
oops
InputCopy
1
z
OutputCopy
z


#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int index = 0;
    int gap = 1;
    while (index < n)
        cout << s[index], index += gap, gap++;
}
*/
