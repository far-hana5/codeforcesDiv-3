/*

#include <bits/stdc++.h>
using namespace std;

// function to find the equilibrium index
int equilibriumPoint(vector<long long>& arr)
{
    int n = arr.size();
    long long leftsum, rightsum;

    //Check for indexes one by one until
    //an equilibrium index is found 
    for (int i = 0; i < n; ++i) {

       //get left sum 
        leftsum = 0;
        for (int j = 0; j < i; j++)
            leftsum += arr[j];

         //get right sum 
        rightsum = 0;
        for (int j = i + 1; j < n; j++)
            rightsum += arr[j];

        //if leftsum and rightsum
        //are same, then w/e are done 
        if (leftsum == rightsum)
            return i + 1;
    }
    return -1;
}

// Driver code
int main()
{
    // Sample Input
    vector<long long> arr = { -7, 1, 5, 2, -4, 3, 0 };

    // Function call
    cout << equilibriumPoint(arr);
    return 0;
}

*/

/*
Maximum subarray size, such that all subarrays of that size have sum less than k

Given an array of n positive integers and a positive integer k, the task is to find the maximum subarray size such that all subarrays of that size have the sum of elements less than or equals to k.

Examples : 

Input : arr[] = {1, 2, 3, 4} and k = 8. Output : 2 

*/

