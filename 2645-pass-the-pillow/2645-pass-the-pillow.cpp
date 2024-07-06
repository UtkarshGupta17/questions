class Solution {
public:
    int passThePillow(int n, int time) {
        int c=time/(n-1);
        int r=time%(n-1);
        if(c%2==0){
            return r+1;
        }
        else{
            return n-r;
        }

        
//also working 
        // int ans=-1;
        // if(n>time){
        //     for(int i=1;i<=time;i++){
        //         ans=i;
        //     }
        // }
        // int flag=0;
        // if(n<time){
        //     while(n<time){
        //         time=time-n;
        //         flag=!flag;
        //     }
        // }
        
        // if(flag==0){
        //     for(int i=1;i<=time+1;i++){
                
        //         ans=i;
        //     }
        // }
        // else{
        //     for(int i=time;i>0;i--){
        //         n=n-1;
        //         ans=n-1;
        //     }
        // }
        
        // return ans;
    }
};