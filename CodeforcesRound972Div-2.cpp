/*
A. Simple Palindrome
time limit per test1 second
memory limit per test256 megabytes
Narek has to spend 2 hours with some 2-year-old kids at the kindergarten. He wants to teach them competitive programming, and their first lesson is about palindromes.

Narek found out that the kids only know the vowels of the English alphabet (the letters a
, e
, i
, o
, and u
), so Narek needs to make a string that consists of vowels only. After making the string, he'll ask the kids to count the number of subsequences that are palindromes. Narek wants to keep it simple, so he's looking for a string such that the amount of palindrome subsequences is minimal.

Help Narek find a string of length n
, consisting of lowercase English vowels only (letters a
, e
, i
, o
, and u
), which minimizes the amount of palindrome†
 subsequences‡
 in it.

†
 A string is called a palindrome if it reads the same from left to right and from right to left.

‡
 String t
 is a subsequence of string s
 if t
 can be obtained from s
 by removing several (possibly, zero or all) characters from s
 and concatenating the remaining ones, without changing their order. For example, odocs
 is a subsequence of codeforces
.

Input
The first line of the input contains a single integer t
 (1≤t≤100
) — the number of test cases. Subsequently, the description of each test case follows.

The only line of each test case contains a single integer n
 (1≤n≤100
) — the size of the string.

Output
For each test case, output any string of length n
 that satisfies the above conditions.

Example
InputCopy
3
2
3
6
OutputCopy
uo
iae
oeiiua
Note
In the first example, uo
 has only three palindrome subsequences: u
, o
, and the empty string. It can be shown that there is no better answer.

In the third example, oeiiua
 has only eight palindrome subsequences: o
, e
, i
, i
, u
, a
, ii
, and the empty string. It can be shown that there is no better answer.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin>>t;

    while(t--){
        string s="aeiou";
        ll n;
        cin>>n;
        ll num=n/5;
        vector<char>v;
        for(int i=1;i<=num;i++){
            for(int j=0;j<5;j++){
                v.push_back(s[j]);
            }
        }
        ll left=n%5;
        if(left!=0){
            for(int i=0;i<left;i++){
                v.push_back(s[i]);
            }
        }
        sort(v.begin(),v.end());
        for(auto it:v){
            cout<<it;
        }
        cout<<endl;
    }
}



*/

/*4. Binary Search for Closest Teacher
cpp
Copy code
        int right = lower_bound(thr.begin(), thr.end(), x) - thr.begin();
        int left = right - 1;
The function lower_bound(thr.begin(), thr.end(), x) is a binary search function that finds the first teacher position that is not less than David's position x.
It returns an iterator to that position, and subtracting thr.begin() gives the index of that teacher (right).
left is the index of the teacher just to the left of x (i.e., right - 1).
5. Handling Three Cases for David's Position
The code then handles three distinct cases based on the values of right and left:

Case 1: No Teacher to the Right of David
cpp
Copy code
        if (right == m) {
            cout << (n - x) + (x - thr[left]) << endl;
        }
If right == m, it means there is no teacher to the right of David (i.e., David is farther right than all the teachers).
The distance is calculated by considering that David could potentially move all the way to the rightmost cell (n) and then move left toward the closest teacher, which is at thr[left].
The formula (n - x) + (x - thr[left]) sums the distance from David to the rightmost cell and back to the teacher.
Case 2: No Teacher to the Left of David
cpp
Copy code
        else if (left == -1) {
            cout << x - 1 + (thr[right] - x) << endl;
        }
If left == -1, it means there is no teacher to the left of David (i.e., David is farther left than all the teachers).
The distance is calculated by considering that David could potentially move all the way to the leftmost cell (1) and then move right toward the closest teacher at thr[right].
The formula x - 1 + (thr[right] - x) sums the distance from David to the leftmost cell and back to the teacher.
Case 3: Teachers on Both Sides of David
cpp
Copy code
        else {
            int distL = x - thr[left];
            int distR = thr[right] - x;
            cout << abs(distL - distR) / 2 + min(distR, distL);
        }
If there are teachers on both sides of David (left >= 0 and right < m):
distL is the distance to the closest teacher on the left (x - thr[left]).
distR is the distance to the closest teacher on the right (thr[right] - x).
The formula used here is trying to calculate how far David could optimally move before the closest teacher catches him:
abs(distL - distR) / 2: If the distances to the left and right teachers differ, this is the number of "extra" steps David could take before being caught.
min(distR, distL): This is the distance to the closer teacher, as they will be the one who catches David first.
This calculates the minimum number of moves required for a teacher to catch David.
6. Example Walkthrough:
For a test case where:

n = 8, m = 1, and q = 1

Teacher is at position 6 and David is at position 3

The lower_bound would give right = 0 (since 6 > 3).

left = -1 (since no teacher is to the left of David).

Therefore, it uses the second condition, and the result would be x - 1 + (thr[right] - x) = 3 - 1 + (6 - 3) = 5.

Summary:
The code efficiently finds the closest teacher using binary search for each query.
Depending on whether there are teachers on the left or right of David, it calculates the minimum number of moves to catch him using a combination of distances.









*/

#include<bits/stdc++.h>
using namespace std;

int main(){
int t;
cin>>t;

while(t--){
    int n,m,q;
    cin>>n>>m>>q;

    vector<int>thr(m);
    for(auto &it:thr){
        cin>>it;
    }
    sort(thr.begin(),thr.end());
    for(int i=0;i<q;i++){
        int x;cin>>x;
        int right=lower_bound(thr.begin(),thr.end(),x)-thr.begin();
        int left=right-1;
        if(right==m){
            cout<<(n-x)+(x-thr[left])<<endl;
        }else if(left==-1){
            cout<<x-1+(thr[right]-x)<<endl;
        }else{
          int distL=x-thr[left];int distR=thr[right]-x;
          cout<<abs(distL-distR)/2 + min(distR,distL)<<endl;
        }
    }
}

}

