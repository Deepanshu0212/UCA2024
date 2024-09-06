#include <bits/stdc++.h>
using namespace std;
int min(vector<int>& nums){
        int s=0;
        int e=nums.size()-1;
        while(s<e){
            int mid = s+(e-s)/2;
            if(nums[mid]>nums[e]){
                s=mid+1;
            }
            else{
                e=mid;
            }
        }
        return e;
    }

    int min(vector<int>& nums){
       
       int s =0;
       int e = nums.size()-1;

       while(s<e){
         int mid = s + (e-s)/2;
         if(nums[e]< nums[mid]){
            s = mid+1;
         }
         else{
            e = mid-1;
         }
       }

       return e;
    }
    int search(vector<int>& nums, int target) {
        int pi = min(nums);
        int s;
        int e=nums.size()-1;
        if(target==nums[pi]){
            return pi;
        }
        else if(target<=nums[e]){
          s=pi;
          e=nums.size()-1;
        }
        else{
            s=0;
            e=pi-1;
        }
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return -1;
    }