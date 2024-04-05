//
// Created by rituparn on 05.04.24.
//


#include <iostream>
#include <vector>
#include <limits>


int solveTabulation(int numberRange){
    std::vector<std::vector<int>>dp (numberRange+2, std::vector<int>(numberRange+2,0));
    for (int start = numberRange; start >=1 ; start--) {
        for (int end =start; end <=numberRange; end++) {
            if (start==end){
                continue;
            }else{
                int max_cost=std::numeric_limits<int>::max();
                for (int i =start; i <end ; i++) {
                    max_cost=std::min(max_cost, i+ std::max(dp[start][i-1],dp[i+1][end]));
                }
                dp[start][end]=max_cost;
            }

        }
    }
    return dp[1][numberRange];
}


int main() {
    int numberRange;
    std::cin >> numberRange;
    std::cout <<solveTabulation(numberRange) <<"\n";
    return 0;
}
