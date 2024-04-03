#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int solveTabulation(int n){
    std::vector<std::vector<int>>dp (n+2, std::vector<int>(n+2,0));
    for (int start = n; start >=1 ; start--) {
        for (int end =start; end <=n; end++) {
            if (start==end){
                continue;
            }else{
                int max_cost=INT_MAX;
                for (int i =start; i <end ; i++) {
                    max_cost=min(max_cost, i+ max(dp[start][i-1],dp[i+1][end]));
                }
                dp[start][end]=max_cost;
            }

        }
    }
    return dp[1][n];
}


int main() {
    int n;
    cin >> n;
    cout <<solveTabulation(n) <<"\n";
    return 0;
}
