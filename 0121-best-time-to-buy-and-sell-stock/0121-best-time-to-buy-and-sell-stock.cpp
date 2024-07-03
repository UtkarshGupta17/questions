class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
       /* int n=prices.size();
        int flag;
        if(n==1){
            return 0;
        }
        
        for(int i=1;i<n;i++){
            //flag=0;
            if(prices[i-1]>prices[i]){
                flag=1;

            }
            else{
                flag=0;
                break;
            }
        }
        int maxi=0;
        int mini=prices[0];
        int k;
        for(int i=0;i<n;i++)
            {
                
                mini=min(mini,prices[i]);
                

            }
        for(int p=0;p<n;p++)
        {
            if(prices[p]==mini)
            {
                k=p;

            }
        }
        for(int j=k;j<n;j++)
        {
            maxi=max(maxi,prices[j]);
                

        }

        if(flag==1){
            
            return 0;
        }
        else{
            


        }
        int l=maxi-mini;
        return l;
        */

        int n=prices.size();
        int maxi=0;
        int mini=prices[0];
        for(int i=0;i<n;i++){
            if(prices[i]<mini){
                mini=prices[i];

            }
            if((prices[i]-mini)>maxi){
                maxi=prices[i]-mini;

            }

        }
        return maxi;
        
    }
};