//method -1 brute force O(n^2)  TLE
class Solution {
  public:
 
    vector<int> search(string &pat, string &txt) {
        int n=txt.size();
        int m=pat.size();
        
        vector<int>ans;
        int i=0;
        while(i<=n-m)
        {
            int j=0;
            int k=i;
            bool flag=true;
            for(int j=0;j<m;j++)
            {
                if(txt[k]==pat[j]) k++;
                else{
                    flag=false;
                    break;
                }
            }
            
            if(flag) ans.push_back(i);
            i++;
        }
            
        return ans;
    }
};



//method -2  O(n+m)  KMP (LPS longest prefix suffix )
 class Solution {
  public:
  void makeLPS(string &pattern,vector<int>& lps)
    {
        int m=pattern.size();
        int i=1;
        int length=0;
        lps[0]=0;
        while(i<m)
        {
            if(pattern[i]==pattern[length])
            {
                length++;
                lps[i]=length;
                i++;
            }
            else{
                if(length==0) {
                    lps[i]=0;
                    i++;
                }
                else {
                    length =lps[length-1];
                }
            }
        }
        
        
    }
    vector<int> search(string &pat, string &txt) {
        int n=txt.size();
        int m=pat.size();
        vector<int>lps(m);
        makeLPS(pat,lps);
        
        vector<int>ans;
        int i=0;
        int j=0;
        while(i<n)
        {
            if(txt[i]==pat[j]){
                j++;
                i++;
            }
            
            if(j==m ) {
                ans.push_back(i-j);
                j=lps[j-1];
            }
            else if(i<n && txt[i]!=pat[j]){
               if(j!=0 ) j=lps[j-1];
               else i++;
            }
        }
            
        return ans;
    }
};

