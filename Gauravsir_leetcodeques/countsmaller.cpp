void merge(vector<pair<int,int>>&v , vector<int>&ans , int l , int u,int mid){

        int l1 = mid-l+1;
        int l2 = u-mid;

        vector<pair<int,int>>v1(l1);
        vector<pair<int,int>>v2(l2);

        for(int i=0;i<l1;i++){
            v1[i] = v[l+i];
        }

        for(int i=0;i<l2;i++){
            v2[i] = v[mid+1+i];              
        }

        int i=0,j=0,k=l;

        while(i<l1 && j<l2){
            if(v1[i].first > v2[j].first){
               ans[v1[i].second]+=(l2-j);
               v[k++] = v1[i++];
            }
            else{
               v[k++] = v2[j++];
            }
        }

        while(i<l1){
            v[k++] = v1[i++];;
        }

        while(j<l2){
            v[k++] = v2[j++];
        }
    }
    void mergesort(vector<pair<int,int>>&v , vector<int>&ans , int l , int u){
         
         if(l>=u) return;

         int mid = l + (u-l)/2;

         mergesort(v,ans,l,mid);
         mergesort(v,ans,mid+1,u);

         merge(v,ans,l,u,mid);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size(); 
        vector<int>ans(n,0);
        vector<pair<int,int>>v;

        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }

        mergesort(v,ans,0,n-1);

        return ans;
    }

