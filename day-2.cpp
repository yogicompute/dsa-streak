#include <bits/stdc++.h>
#include "print.h"
using namespace std;

void rotate_by_k_places(vector<int>& arr, int k, string dir){

    //right
    if(dir == "right"){

    reverse(arr.begin(), arr.end());

    reverse(arr.begin(), arr.begin() + k - 1);

    reverse(arr.begin() + k, arr.end());
    }
    //left 
    else{

    reverse(arr.begin(), arr.begin() + k - 1);

    reverse(arr.begin() + k, arr.end());

    reverse(arr.begin(), arr.end());

    }
}

void move_zeroes_to_end(vector<int>&arr){
    int j = 0;

    for(int i = 1;i<arr.size();i++){
        if(arr[i] != 0){
            j++;
            swap(arr[i], arr[j]);
        }
    }
}

int ls(vector<int>& arr, int target){
    for(int i = 0;i<arr.size();i++){
        if(arr[i] == target) return i;
    }
    return -1;
}

vector<int> union_of_two_sorted_arr(vector<int>& arr1, vector<int>& arr2){
    vector<int> Union;
    int i = 0, j = 0;

    while(i < arr1.size() && j < arr2.size()){
        if(arr1[i] <= arr2[j]){
            if(Union.size() == 0 || Union.back() != arr1[i]){
                Union.push_back(arr1[i]);
            }
            i++;
        }else{
            if(Union.size() == 0 || Union.back() != arr2[j]){
                Union.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i < arr1.size()){
        if(Union.back() != arr1[i]){
            Union.push_back(arr1[i]);
        }
        i++;
    }

    while(j < arr2.size()){
        if(Union.back() != arr2[j]){
            Union.push_back(arr2[j]);
        }
        j++;
    }
    return Union;
}

int find_missing_number(vector<int>& arr){
    int x1 = 0, x2 = 0;

    for(int i = 0;i<arr.size();i++){
        x1 ^= arr[i];
        x2 ^= (i+1);
    }
    return x1 ^ x2 ^ arr.size();
}

// GFG - daily - 14 Jul - Hard
// Find the Number of Subsequences With Equal GCD
// https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/description

// Brute force - first verdict

int gcd(int a, int b){
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b){
    return (a / gcd(a, b)) * b;
}

long long solve(vector<int>& nums, int left_gcd, int right_gcd, int ind, vector<vector<vector<long long>>>& dp){
    if(ind == nums.size()){
        if((left_gcd == right_gcd) && left_gcd == 0) return 0;
        return dp[ind][left_gcd][right_gcd] = left_gcd == right_gcd;
    }

    if(dp[ind][left_gcd][right_gcd] != -1) return dp[ind][left_gcd][right_gcd];

    return dp[ind][left_gcd][right_gcd] = solve(nums, gcd(left_gcd, nums[ind]), right_gcd,ind + 1, dp)
    + solve(nums, left_gcd, gcd(right_gcd, nums[ind]), ind + 1, dp)
    + solve(nums, left_gcd, right_gcd, ind + 1, dp);
}

int subsequencePairCount(vector<int>& nums) {
    vector<vector<vector<long long>>> dp(nums.size() + 1, vector<vector<long long>>(201, vector<long long> (201, -1)));
    return solve(nums, 0, 0, 0, dp);
}


// GFG - daily - 14 Jul - Medium
// Smallest Non-Zero Number
// https://www.geeksforgeeks.org/problems/find-smallest-non-zero-number4510/1

// Brute force - first verdict

int find(vector<int>& arr) {
    for(int x = 1;;x++){
        int currElement = x;

        for(int y: arr){
            if(currElement > y) currElement += currElement - y;
            else{
                currElement -= y - currElement;
            }
        }
        if(currElement >= 0) return x;
    }       
    return -1;
}

int main(){
    vector<int> arr = {4, 4};
    cout<<find(arr);
}