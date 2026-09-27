class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total = 0;
        int answer = 0;
        int oldSum =0;
        int gasSum =0;
        int costSum = 0;
        for(int i =0; i<n ;i++){
            total+= gas[i] - cost[i];
            gasSum+=gas[i];
            costSum+=cost[i];
            if(total<0){
                total = 0;
                answer=i+1;
            }
        }
        if(costSum>gasSum) return -1;
        return answer;
    }
};
