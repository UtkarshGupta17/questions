class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty=numBottles;
        int drunk=numBottles;
        while(empty>=numExchange){
            empty=empty-numExchange;
            numExchange=numExchange+1;
            empty+=1;
            drunk+=1;
        }
        return drunk;
        
    }
};
