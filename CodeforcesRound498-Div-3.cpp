/*
C. Three Parts of the Array
time limit per test1 second
memory limit per test256 megabytes
You are given an array d1,d2,…,dn
 consisting of n
 integer numbers.

Your task is to split this array into three parts (some of which may be empty) in such a way that each element of the array belongs to exactly one of the three parts, and each of the parts forms a consecutive contiguous subsegment (possibly, empty) of the original array.

Let the sum of elements of the first part be sum1
, the sum of elements of the second part be sum2
 and the sum of elements of the third part be sum3
. Among all possible ways to split the array you have to choose a way such that sum1=sum3
 and sum1
 is maximum possible.

More formally, if the first part of the array contains a
 elements, the second part of the array contains b
 elements and the third part contains c
 elements, then:

sum1=∑1≤i≤adi,
sum2=∑a+1≤i≤a+bdi,
sum3=∑a+b+1≤i≤a+b+cdi.
The sum of an empty array is 0
.

Your task is to find a way to split the array such that sum1=sum3
 and sum1
 is maximum possible.

Input
The first line of the input contains one integer n
 (1≤n≤2⋅105
) — the number of elements in the array d
.

The second line of the input contains n
 integers d1,d2,…,dn
 (1≤di≤109
) — the elements of the array d
.

Output
Print a single integer — the maximum possible value of sum1
, considering that the condition sum1=sum3
 must be met.

Obviously, at least one valid way to split the array exists (use a=c=0
 and b=n
).

Examples
InputCopy
5
1 3 1 1 4
OutputCopy
5
InputCopy
5
1 3 2 1 4
OutputCopy
4
InputCopy
3
4 1 2
OutputCopy
0
Note
In the first example there is only one possible splitting which maximizes sum1
: [1,3,1],[ ],[1,4]
.

In the second example the only way to have sum1=4
 is: [1,3],[2,1],[4]
.

In the third example there is only one way to split the array: [ ],[4,1,2],[ ]
.

*/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005];

int main() {
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	int i = 0, j = n+1;
	ll zi = 0, zj = 0, solidx = 0;
/*
Initially, zi = 0 and zj = 0.
Start the loop:
zi += a[1] = 1 and zj += a[5] = 4. Now zi = 1, zj = 4.
Since zi < zj, add a[2] to zi. Now zi = 4.
Now zi == zj, so update solidx = 2. Move both pointers inward: zi += a[3] = 1, zj += a[4] = 1. Now zi = 5 and zj = 5.
Again, zi == zj, so update solidx = 3. After that, the loop ends.
The maximum sum where sum1 == sum3 is the sum of elements from a[1] to a[3], i.e., 1 + 3 + 1 = 5.
*/
	while (i < j) {
		if (zi < zj)
		//	zi += a[++i];
         zi=zi+a[++i];
		else if (zi > zj)
			//zj += a[--j];
         zj = zj+a[--j];
		else {
			solidx = i;
         zi=zi+a[++i];
			//zi += a[++i];
			//zj += a[--j];
         zj = zj+a[--j];
		}
	}
	
	cout << accumulate(a+1, a+solidx+1, 0ll); 
}