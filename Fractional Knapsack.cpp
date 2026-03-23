class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<int,int>> perUnitProfit;
        int n=val.size();
        for(int i=0;i<n;i++)
        {
            perUnitProfit.push_back({val[i],wt[i]});
        }
        auto lambda=[](auto &a,auto &b)
        {
            return 1.0 *a.first/a.second > 1.0* b.first/b.second;
        };
        sort(perUnitProfit.begin() ,perUnitProfit.end() , lambda);
        
        double result=0;
        for(int i=0;i<n;i++)
        {
            auto p=perUnitProfit[i];
            
            if(p.second <= capacity)
            {
                result += p.first;
                capacity -=p.second;
            }
            else{
                result +=  (1.0 *p.first/p.second)*capacity;
                break;
            }
        }
        
        return result;
    }
};
