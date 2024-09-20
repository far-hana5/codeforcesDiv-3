
/*
C. Doors Breaking and Repairing
time limit per test1 second
memory limit per test256 megabytes
You are policeman and you are playing a game with Slavik. The game is turn-based and each turn consists of two phases. During the first phase you make your move and during the second phase Slavik makes his move.

There are n
 doors, the i
-th door initially has durability equal to ai
.

During your move you can try to break one of the doors. If you choose door i
 and its current durability is bi
 then you reduce its durability to max(0,bi−x)
 (the value x
 is given).

During Slavik's move he tries to repair one of the doors. If he chooses door i
 and its current durability is bi
 then he increases its durability to bi+y
 (the value y
 is given). Slavik cannot repair doors with current durability equal to 0
.

The game lasts 10100
 turns. If some player cannot make his move then he has to skip it.

Your goal is to maximize the number of doors with durability equal to 0
 at the end of the game. You can assume that Slavik wants to minimize the number of such doors. What is the number of such doors in the end if you both play optimally?

Input
The first line of the input contains three integers n
, x
 and y
 (1≤n≤100
, 1≤x,y≤105
) — the number of doors, value x
 and value y
, respectively.

The second line of the input contains n
 integers a1,a2,…,an
 (1≤ai≤105
), where ai
 is the initial durability of the i
-th door.

Output
Print one integer — the number of doors with durability equal to 0
 at the end of the game, if you and Slavik both play optimally.

Examples
InputCopy
6 3 2
2 3 1 3 4 2
OutputCopy
6
InputCopy
5 3 3
1 2 4 2 3
OutputCopy
2
InputCopy
5 5 6
1 2 6 10 3
OutputCopy
2
Note
Clarifications about the optimal strategy will be ignored.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x,y;
    cin>>n>>x>>y;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];

    }
    if(x>y){
        cout<<n<<endl;
        return 0;
    }
    long long count=0;
    for(int i=0;i<n;i++){
        if(v[i]<=x){
            count++;
        }

    }
    if(count%2==0){
        cout<<count/2<<endl;
    }else{
cout<<(count/2)+1<<endl;
    }

}
*/
