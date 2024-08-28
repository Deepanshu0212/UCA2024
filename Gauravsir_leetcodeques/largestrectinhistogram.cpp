#include <bits/stdc++.h>
using namespace std;
void nextsmaller( vector<int>heights , vector<int>&v){
        stack<int>st;
        
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                v[i]=st.top();
            }  
            st.push(i);
        }

    }
    void prevsmaller( vector<int>heights , vector<int>&v){
        stack<int>st;
        
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                v[i]=st.top();
            }  
            st.push(i);
        }

    }


    void next(vector<int>& heights,vector<int>v){
        stack<int>st;

        for(int i= heights.size()-1;i>=0;i--){
            while(!st.empty() &&  heights[i] <= heights[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                v[i]=st.top();
            }
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int area = 0;
        vector<int>next(heights.size(),heights.size());
        vector<int>prev(heights.size(),-1);

        nextsmaller(heights,next);
        prevsmaller(heights,prev);

        for(int i=0;i<heights.size();i++){
            // cout<<heights[i]<<" "<<next[i]<<" "<<prev[i]<<endl;
            int ar = heights[i]*(next[i]-prev[i]-1);

            area = max(area,ar);
        }

        return area;

    }