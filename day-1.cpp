#include <bits/stdc++.h>
#include "print.h"
using namespace std;

int largest_element(vector<int>& arr){
    int maxi = INT_MIN;
    for(int i = 0;i<arr.size();i++){
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

int second_largest(vector<int>& arr){
    int largest = INT_MIN, second_largest = INT_MIN;

    for(int i = 0;i<arr.size();i++){
        if(arr[i] > largest){
            second_largest = largest;
            largest = arr[i];
        }else if(arr[i] > second_largest && largest != arr[i]){
            second_largest = arr[i];
        }
    }
    return second_largest;
}

bool is_sorted(vector<int>& arr){
    for(int i = 1;i<arr.size();i++){
        if(arr[i] < arr[i-1]) return false;
    }
    return true;
}

int remove_dups(vector<int>& arr){
    int j = 0;

    for(int i = 1;i<arr.size();i++){
        if(arr[i] != arr[j]){
            j++;
            swap(arr[i], arr[j]);
        }
    }
    return j + 1;
}

void left_rotate_by_1(vector<int>& arr){
    int first = arr[0];
    for(int i = 0;i<arr.size() - 1;i++){
        arr[i] = arr[i+1];
    }
    arr[arr.size() - 1] = first;
}


// LeetCode - daily - 13 Jul
// Sequential Digits
// https://leetcode.com/problems/sequential-digits/description/ 

// Brute force - first verdict

bool is_seq(int num){
    int maxi = num % 10;
    num /= 10;
    while(num){
        if((num % 10 + 1) != maxi) return false;
        maxi = num % 10;
        num/=10;
    }
    return true;
}
vector<int> sequentialDigits_brute(int low, int high) {
    vector<int> res;
    for(int i = low;i<=high;i++){
        if(is_seq(i)) res.push_back(i);
    }
    return res;
}

// TLE

vector<int> sequentialDigits_op(int low, int high) {
    vector<int> res;
    vector<int> st  = {12, 123, 1234, 12345, 123456, 1234567, 12345678, 123456789,
                   23, 234, 2345, 23456, 234567, 2345678, 23456789,
                   34, 345, 3456, 34567, 345678, 3456789,
                   45, 456, 4567, 45678, 456789,
                   56, 567, 5678, 56789,
                   67, 678, 6789,
                   78, 789,
                   89
                };

    for(int s: st) if(low <= s && s <= high) res.push_back(s);
    
    return res;
}


// GFG - daily - 13 Jul
// Rearrange the Array
// https://www.geeksforgeeks.org/problems/rearrange-the-array-1639032648/1

// Brute force - first verdict

vector<int> transform(vector<int>& arr, vector<int>& b){
    vector<int> temp(arr.size(),-1);

    for(int i = 0;i<arr.size();i++){
        temp[b[i]-1] = arr[i];
    }
    return temp;
}

int minOperations_brute(vector<int> &b) {
    vector<int> arr = {1,2,3,4,5};
    vector<int> temp = transform(arr, b);
    print(temp);
    return 0;
}

int minOperations(vector<int> &b){
    int mod = 1e9 + 7;
    int n = b.size();
    vector<int> vis(n, 0);
    int lc = 1;

    for(int i = 0;i<n;i++){
        if(vis[i]) continue;
        int curr = i;

        int len = 0;

        while(!vis[curr]){
            vis[curr] = 1;
            len++;
            curr = b[curr] - 1;
        }
        // lc = std::lcm(lc, len) % mod;
    }
    return lc % mod;
}

int main(){
}