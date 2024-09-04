/*
Mishka started participating in a programming contest. There are n
 problems in the contest. Mishka's problem-solving skill is equal to k
.

Mishka arranges all problems from the contest into a list. Because of his weird principles, Mishka only solves problems from one of the ends of the list. Every time, he chooses which end (left or right) he will solve the next problem from. Thus, each problem Mishka solves is either the leftmost or the rightmost problem in the list.

Mishka cannot solve a problem with difficulty greater than k
. When Mishka solves the problem, it disappears from the list, so the length of the list decreases by 1
. Mishka stops when he is unable to solve any problem from any end of the list.

How many problems can Mishka solve?

Input
The first line of input contains two integers n
 and k
 (1≤n,k≤100
) — the number of problems in the contest and Mishka's problem-solving skill.

The second line of input contains n
 integers a1,a2,…,an
 (1≤ai≤100
), where ai
 is the difficulty of the i
-th problem. The problems are given in order from the leftmost to the rightmost in the list.

Output
Print one integer — the maximum number of problems Mishka can solve.

Examples
InputCopy
8 4
4 2 3 1 5 1 6 4
OutputCopy
5
InputCopy
5 2
3 1 2 1 3
OutputCopy
0
InputCopy
5 100
12 34 55 43 21
OutputCopy
5
Note
In the first example, Mishka can solve problems in the following order: [4,2,3,1,5,1,6,4]→[2,3,1,5,1,6,4]→[2,3,1,5,1,6]→[3,1,5,1,6]→[1,5,1,6]→[5,1,6]
, so the number of solved problems will be equal to 5
.

In the second example, Mishka can't solve any problem because the difficulties of problems from both ends are greater than k
.

In the third example, Mishka's solving skill is so amazing that he can solve all the problems.


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        
    }
  int s=0;int e=0;
    for(int j=0;j<n;j++){
      if(v[j]<=k){
       s++;
    }else if(v[j]>k){
      break;
    }
}
if(s==n){
    cout<<s<<endl;return 0;
}
for(int g=n-1;0<=g;g--){
     if(v[g]<=k){
       e++;
    }else if(v[g]>k){
        break;
    }
}
cout<<s+e<<endl;
}
*/


//              Problem-B      //

/*
A string s
 of length n
 can be encrypted by the following algorithm:

iterate over all divisors of n
 in decreasing order (i.e. from n
 to 1
),
for each divisor d
, reverse the substring s[1…d]
 (i.e. the substring which starts at position 1
 and ends at position d
).
For example, the above algorithm applied to the string s
="codeforces" leads to the following changes: "codeforces" →
 "secrofedoc" →
 "orcesfedoc" →
 "rocesfedoc" →
 "rocesfedoc" (obviously, the last reverse operation doesn't change the string because d=1
).

You are given the encrypted string t
. Your task is to decrypt this string, i.e., to find a string s
 such that the above algorithm results in string t
. It can be proven that this string s
 always exists and is unique.

Input
The first line of input consists of a single integer n
 (1≤n≤100
) — the length of the string t
. The second line of input consists of the string t
. The length of t
 is n
, and it consists only of lowercase Latin letters.

Output
Print a string s
 such that the above algorithm results in t
.

Examples
InputCopy
10
rocesfedoc
OutputCopy
codeforces
InputCopy
16
plmaetwoxesisiht
OutputCopy
thisisexampletwo
InputCopy
1
z
OutputCopy
z
Note
The first example is described in the problem statement.




#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> divisors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }

    // Sort the divisors in increasing order
    sort(divisors.begin(), divisors.end());

    string s;
    cin >> s;

    // Reverse substrings according to the divisors
    for (int d : divisors) {
        reverse(s.begin(), s.begin() + d);
    }

    cout << s << endl;

    return 0;
}

*/

//                      Problem-C                

/*
C. Alphabetic Removals
time limit per test2 seconds
memory limit per test256 megabytes
You are given a string s
 consisting of n
 lowercase Latin letters. Polycarp wants to remove exactly k
 characters (k≤n
) from the string s
. Polycarp uses the following algorithm k
 times:

if there is at least one letter 'a', remove the leftmost occurrence and stop the algorithm, otherwise go to next item;
if there is at least one letter 'b', remove the leftmost occurrence and stop the algorithm, otherwise go to next item;
...
remove the leftmost occurrence of the letter 'z' and stop the algorithm.
This algorithm removes a single letter from the string. Polycarp performs this algorithm exactly k
 times, thus removing exactly k
 characters.

Help Polycarp find the resulting string.

Input
The first line of input contains two integers n
 and k
 (1≤k≤n≤4⋅105
) — the length of the string and the number of letters Polycarp will remove.

The second line contains the string s
 consisting of n
 lowercase Latin letters.

Output
Print the string that will be obtained from s
 after Polycarp removes exactly k
 letters using the above algorithm k
 times.

If the resulting string is empty, print nothing. It is allowed to print nothing or an empty line (line break).

Examples
InputCopy
15 3
cccaabababaccbc
OutputCopy
cccbbabaccbc
InputCopy
15 9
cccaabababaccbc
OutputCopy
cccccc
InputCopy
1 1
u
OutputCopy


#include<bits/stdc++.h>
using namespace std;

int main(){
    //15 3
 //cccaabababaccbc

    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    multiset<char>ms;
    for(char c:s){
        ms.insert(c);
    }
   // ms:a a a a a b b b c c c c c c 
    
    multiset<char>f;
    for(char c:ms){
        if(k){
            f.insert(c);
            --k;
        }
        else{
            break;
        }
        
    }
    //f: a a a
 
    string ans="";
    for(char c:s){
        auto itr=f.find(c);
        if(itr!=f.end()){
            f.erase(itr);
        }else{
            ans+=c;
        }
    }
 cout<<ans;

}
*/
