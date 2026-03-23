//approach-1  recursion and memoization
class Solution {
  public:
    int n;
    int t[1001][1001];
    int solve(vector<int> &val,vector<int> &wt , int i, int remWeight)
    {
        if(i ==n || remWeight==0)
        {
            return 0;
        }
        
        if(t[i][remWeight] !=-1) return t[i][remWeight];
        
        int take=0;
        if(wt[i]<=remWeight) take=val[i]+solve(val ,wt,i+1, remWeight-wt[i]);
        
        int skip=solve(val ,wt,i+1, remWeight);
        
        return t[i][remWeight]=max(take,skip);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        n=val.size();
        memset(t,-1,sizeof(t));
        return solve(val,wt,0,W);
    }
};

//Approach (Bottom Up)
//T.C : O(n*W)
//S.C : O(n*W)
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        
        vector<vector<int>> t(n+1, vector<int>(W+1, 0));
        //t[i][j] = max profit with i items and j knapsack weight
        //return t[n][W];
        
        //Base case : if(n == 0 ) return 0; //no item
        for(int j = 0; j < W+1; j++) {
            t[0][j] = 0;
        }
        
        //Base case : if(W == 0) return 0; //knapsack full
        for(int i = 0; i < n+1; i++) {
            t[i][0] = 0;
        }
        
        
        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < W+1; j++) {
                
                int take = 0;
                int skip = 0;
                
                //take
                if(wt[i-1] <= j) {
                    take = val[i-1] + t[i-1][j - wt[i-1]];//val[i-1] + solve(i-1, j - wt[i-1], val, wt);
                }
                
                skip    = t[i-1][j]; //solve(i-1, j, val, wt);
                
                t[i][j] = max(take, skip); //return t[n][W] = max(take, skip);
                
            }
        }
        
        return t[n][W];
    }
};
