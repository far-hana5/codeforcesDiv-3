

/*
A. Diverse Team
time limit per test1 second
memory limit per test256 megabytes
There are n
 students in a school class, the rating of the i
-th student on Codehorses is ai
. You have to form a team consisting of k
 students (1≤k≤n
) such that the ratings of all team members are distinct.

If it is impossible to form a suitable team, print "NO" (without quotes). Otherwise print "YES", and then print k
 distinct numbers which should be the indices of students in the team you form. If there are multiple answers, print any of them.

Input
The first line contains two integers n
 and k
 (1≤k≤n≤100
) — the number of students and the size of the team you have to form.

The second line contains n
 integers a1,a2,…,an
 (1≤ai≤100
), where ai
 is the rating of i
-th student.

Output
If it is impossible to form a suitable team, print "NO" (without quotes). Otherwise print "YES", and then print k
 distinct integers from 1
 to n
 which should be the indices of students in the team you form. All the ratings of the students in the team should be distinct. You may print the indices in any order. If there are multiple answers, print any of them.

Assume that the students are numbered from 1
 to n
.

Examples
InputCopy
5 3
15 13 15 15 12
OutputCopy
YES
1 2 5 
InputCopy
5 4
15 13 15 15 12
OutputCopy
NO
InputCopy
4 4
20 10 40 30
OutputCopy
YES
1 2 3 4 
Note
All possible answers for the first example:

{1 2 5}
{2 3 5}
{2 4 5}
Note that the order does not matter.


#include <bits/stdc++.h>

using namespace std;

int main() {
int n, k;
	cin >> n >> k;
	set<int> el;
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (!el.count(x)) {
			ans.push_back(i);
			el.insert(x);
		}
	}
	
	if (int(ans.size()) < k) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for (int i = 0; i < k; ++i)
			cout << ans[i]+1<< " ";
		cout << endl;
	}
	
	return 0;

	
}

*/

/*
B. Substrings Sort
time limit per test1 second
memory limit per test256 megabytes
You are given n
 strings. Each string consists of lowercase English letters. Rearrange (reorder) the given strings in such a way that for every string, all strings that are placed before it are its substrings.

String a
 is a substring of string b
 if it is possible to choose several consecutive letters in b
 in such a way that they form a
. For example, string "for" is contained as a substring in strings "codeforces", "for" and "therefore", but is not contained as a substring in strings "four", "fofo" and "rof".

Input
The first line contains an integer n
 (1≤n≤100
) — the number of strings.

The next n
 lines contain the given strings. The number of letters in each string is from 1
 to 100
, inclusive. Each string consists of lowercase English letters.

Some strings might be equal.

Output
If it is impossible to reorder n
 given strings in required order, print "NO" (without quotes).

Otherwise print "YES" (without quotes) and n
 given strings in required order.

Examples
InputCopy
5
a
aba
abacaba
ba
aba
OutputCopy
YES
a
ba
aba
aba
abacaba
InputCopy
5
a
abacaba
ba
aba
abab
OutputCopy
NO
InputCopy
3
qwerty
qwerty
qwerty
OutputCopy
YES
qwerty
qwerty
qwerty
Note
In the second example you cannot reorder the strings because the string "abab" is not a substring of the string "abacaba".



#include<bits/stdc++.h>
using namespace std;
bool cmp(string x,string y){
	return x.length()<y.length();
}
int main(){
	int n;
	cin>>n;
    string s[1000];
	for(int i=0;i<n;i++){
		cin>>s[i];
	}

	sort(s,s+n,cmp);

	for(int i=0;i<n-1;i++){
	if(s[i+1].find(s[i])==string::npos){
		cout<<"NO";
		return 0;
	}
	}
	cout<<"YES\n";
	for(int i=0;i<n;i++){
		cout<<s[i]<<endl;
	}


}


*/

/*
C. Equal Sums
time limit per test2 seconds
memory limit per test256 megabytes
You are given k
 sequences of integers. The length of the i
-th sequence equals to ni
.

You have to choose exactly two sequences i
 and j
 (i≠j
) such that you can remove exactly one element in each of them in such a way that the sum of the changed sequence i
 (its length will be equal to ni−1
) equals to the sum of the changed sequence j
 (its length will be equal to nj−1
).

Note that it's required to remove exactly one element in each of the two chosen sequences.

Assume that the sum of the empty (of the length equals 0
) sequence is 0
.

Input
The first line contains an integer k
 (2≤k≤2⋅105
) — the number of sequences.

Then k
 pairs of lines follow, each pair containing a sequence.

The first line in the i
-th pair contains one integer ni
 (1≤ni<2⋅105
) — the length of the i
-th sequence. The second line of the i
-th pair contains a sequence of ni
 integers ai,1,ai,2,…,ai,ni
.

The elements of sequences are integer numbers from −104
 to 104
.

The sum of lengths of all given sequences don't exceed 2⋅105
, i.e. n1+n2+⋯+nk≤2⋅105
.

Output
If it is impossible to choose two sequences such that they satisfy given conditions, print "NO" (without quotes). Otherwise in the first line print "YES" (without quotes), in the second line — two integers i
, x
 (1≤i≤k,1≤x≤ni
), in the third line — two integers j
, y
 (1≤j≤k,1≤y≤nj
). It means that the sum of the elements of the i
-th sequence without the element with index x
 equals to the sum of the elements of the j
-th sequence without the element with index y
.

Two chosen sequences must be distinct, i.e. i≠j
. You can print them in any order.

If there are multiple possible answers, print any of them.

Examples
InputCopy
2
5
2 3 1 3 2
6
1 1 2 2 2 1
OutputCopy
YES
2 6
1 2
InputCopy
3
1
5
5
1 1 1 1 1
2
2 3
OutputCopy
NO
InputCopy
4
6
2 2 2 2 2 2
5
2 2 2 2 2
3
2 2 2
5
2 2 2 2 2
OutputCopy
YES
2 2
4 1
Note
In the first example there are two sequences [2,3,1,3,2]
 and [1,1,2,2,2,1]
. You can remove the second element from the first sequence to get [2,1,3,2]
 and you can remove the sixth element from the second sequence to get [1,1,2,2,2]
. The sums of the both resulting sequences equal to 8
, i.e. the sums are equal.


*/
//Key Concepts:
//Calculate the sum of each sequence.
//Iterate over each element in the sequence, compute the new sum when one element is removed, and store this information.
//Check if any two sequences (after removing one element) can have the same sum.

#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    cin >> k;
    vector<pair<int, pair<int, int>>> a;
/*
2
5
2 3 1 3 2
6
1 1 2 2 2 1

For the first sequence [2, 3, 1, 3, 2], the sum is 11.

Remove 2: sum = 9.
Remove 3: sum = 8.
Remove 1: sum = 10.
Remove 3: sum = 8.
Remove 2: sum = 9.
Resulting pairs: (9, (0, 0)), (8, (0, 1)), (10, (0, 2)), (8, (0, 3)), (9, (0, 4)).

For the second sequence [1, 1, 2, 2, 2, 1], the sum is 9.

Remove 1: sum = 8.
Remove 1: sum = 8.
Remove 2: sum = 7.
Remove 2: sum = 7.
Remove 2: sum = 7.
Remove 1: sum = 8.
Resulting pairs: (8, (1, 0)), (8, (1, 1)), (7, (1, 2)), (7, (1, 3)), (7, (1, 4)), (8, (1, 5)).

*/

    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        vector<int> x(n);

        for (int j = 0; j < n; ++j) {
            cin >> x[j];
        }

        int sum = accumulate(x.begin(), x.end(), 0);

        for (int j = 0; j < n; ++j) {
            a.push_back(make_pair(sum - x[j], make_pair(i, j)));
        }
    }

    stable_sort(a.begin(), a.end());
//(7, (1, 2)), (7, (1, 3)), (7, (1, 4)), (8, (0, 1)), (8, (0, 3)), (8, (1, 0)), (8, (1, 1)), (8, (1, 5)), (9, (0, 0)), (9, (0, 4)), (10, (0, 2))

    for (int i = 0; i < int(a.size()) - 1; ++i) {
        if (a[i].first == a[i + 1].first) {
            if (a[i].second.first != a[i + 1].second.first) {
                cout << "YES" << endl;
                cout << a[i + 1].second.first + 1 << " " << a[i + 1].second.second + 1 << endl;
                cout << a[i].second.first + 1 << " " << a[i].second.second + 1 << endl;
                return 0;
            }
        }
    }
//For sum = 8, we find that a[3] = (8, (0, 1)) and a[5] = (8, (1, 0)) are from different sequences.
    cout << "NO" << endl;

    return 0;
}
