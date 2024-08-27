vector<vector<string>>ans;
    void mkstr(vector<vector<char>> v){
        vector<string>vt;

        for(int i=0;i<v.size();i++){
            string s;
            for(int j =0;j<v[0].size();j++){
                s+=v[i][j];
            }
            vt.push_back(s);
        }
        ans.push_back(vt);
    }
    bool feasible(vector<vector<char>>v , int i , int j){

        // check row
        for(int k=0;k<j;k++){
            if(v[i][k]=='Q') return false;
        }
        
        // check col
        for(int k=0;k<i;k++){
            if(v[k][j]=='Q') return false;
        }

        int r = i-1,c=j-1;

        while(r>=0 && c>=0){
            if(v[r][c]=='Q') return false;
            r--;c--;
        }
        r =i-1 , c = j+1;

        while(r>=0 && c<v.size()){
            if(v[r][c]=='Q') return false;
            r--;c++;
        }

        return true;
    }
    void nqueen(vector<vector<char>>v , int i){
        if(i==v.size()){
            mkstr(v);
            return;
        }

        for(int j=0;j<v.size();j++){
            if(feasible(v , i , j)){
                v[i][j]='Q';
                nqueen(v,i+1);
                v[i][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>>v(n,vector<char>(n,'.'));
        nqueen(v,0);
        return ans;
    }
