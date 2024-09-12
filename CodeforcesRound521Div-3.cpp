

/*
C. Good Array
time limit per test1 second
memory limit per test256 megabytes
Let's call an array good if there is an element in the array that equals to the sum of all other elements. For example, the array a=[1,3,3,7]
 is good because there is the element a4=7
 which equals to the sum 1+3+3
.

You are given an array a
 consisting of n
 integers. Your task is to print all indices j
 of this array such that after removing the j
-th element from the array it will be good (let's call such indices nice).

For example, if a=[8,3,5,2]
, the nice indices are 1
 and 4
:

if you remove a1
, the array will look like [3,5,2]
 and it is good;
if you remove a4
, the array will look like [8,3,5]
 and it is good.
You have to consider all removals independently, i. e. remove the element, check if the resulting array is good, and return the element into the array.

Input
The first line of the input contains one integer n
 (2≤n≤2⋅105
) — the number of elements in the array a
.

The second line of the input contains n
 integers a1,a2,…,an
 (1≤ai≤106
) — elements of the array a
.

Output
In the first line print one integer k
 — the number of indices j
 of the array a
 such that after removing the j
-th element from the array it will be good (i.e. print the number of the nice indices).

In the second line print k
 distinct integers j1,j2,…,jk
 in any order — nice indices of the array a
.

If there are no such indices in the array a
, just print 0
 in the first line and leave the second line empty or do not print it at all.

Examples
InputCopy
5
2 5 1 2 2
OutputCopy
3
4 1 5
InputCopy
4
8 3 5 2
OutputCopy
2
1 4 
InputCopy
5
2 1 2 4 3
OutputCopy
0

Note
In the first example you can remove any element with the value 2
 so the array will look like [5,1,2,2]
. The sum of this array is 10
 and there is an element equals to the sum of remaining elements (5=1+2+2
).

In the second example you can remove 8
 so the array will look like [3,5,2]
. The sum of this array is 10
 and there is an element equals to the sum of remaining elements (5=3+2
). You can also remove 2
 so the array will look like [8,3,5]
. The sum of this array is 16
 and there is an element equals to the sum of remaining elements (8=3+5
).

In the third example you cannot make the given array good by removing exactly one element.


#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6;

int freq[MAX + 1] = {0};
int main(){
    int n;cin>>n;
    int arr[n];
    long long sum=0;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum=sum+arr[i];
        freq[arr[i]]++;
    }
    vector<int>ans;
    for(int i=0;i<n;i++){
        freq[arr[i]]--;
        sum=sum-arr[i];
        if(sum%2==0 && sum/2<=MAX && freq[sum/2]>0){
         ans.push_back(i);   
        }
        freq[arr[i]]++;
        sum=sum+arr[i];
    }
    cout << ans.size() << endl;
for (auto it : ans) cout << it + 1 << " ";
cout << endl;

}
*/
/*
B. Disturbed People
time limit per test1 second
memory limit per test256 megabytes
There is a house with n
 flats situated on the main street of Berlatov. Vova is watching this house every night. The house can be represented as an array of n
 integer numbers a1,a2,…,an
, where ai=1
 if in the i
-th flat the light is on and ai=0
 otherwise.

Vova thinks that people in the i
-th flats are disturbed and cannot sleep if and only if 1<i<n
 and ai−1=ai+1=1
 and ai=0
.

Vova is concerned by the following question: what is the minimum number k
 such that if people from exactly k
 pairwise distinct flats will turn off the lights then nobody will be disturbed? Your task is to find this number k
.

Input
The first line of the input contains one integer n
 (3≤n≤100
) — the number of flats in the house.

The second line of the input contains n
 integers a1,a2,…,an
 (ai∈{0,1}
), where ai
 is the state of light in the i
-th flat.

Output
Print only one integer — the minimum number k
 such that if people from exactly k
 pairwise distinct flats will turn off the light then nobody will be disturbed.

Examples
InputCopy
10
1 1 0 1 1 0 1 0 1 0
OutputCopy
2
InputCopy
5
1 1 0 0 0
OutputCopy
0
InputCopy
4
1 1 1 1
OutputCopy
0
Note
In the first example people from flats 2
 and 7
 or 4
 and 7
 can turn off the light and nobody will be disturbed. It can be shown that there is no better answer in this example.

There are no disturbed people in second and third examples.


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
	vector<int>arr(n);
    for(auto &i:arr){
        cin>>i;
    }
	int ans = 0;
    for(int i=1;i<n-1;i++){
        if(arr[i]==0 &&arr[i-1]==1 && arr[i+1]==1){
            ans++;
            arr[i+1]=0;
        }
    }
	
	cout<<ans<< endl;
}

*/
