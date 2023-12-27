//
// Created by rituparn on 26.12.23.
//
//
// Created by rituparn on 26.12.23.
//

#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

std::vector<int64_t > BuildSegmentTree(std::vector<int64_t>& Position, std::vector<int64_t>& SegmentTree, int64_t Node, int64_t start, int64_t end) {
    if (start == end) {
        SegmentTree[Node] = Position[start];
    } else {
        int64_t mid = (start + end) / 2;
        BuildSegmentTree(Position, SegmentTree, 2 * Node + 1, start, mid);
        BuildSegmentTree(Position, SegmentTree, 2 * Node + 2, mid + 1, end);
        SegmentTree[Node] = std::max(SegmentTree[2 * Node + 1], SegmentTree[2 * Node + 2]);
    }
    return SegmentTree;
}



void UpdateSegmentTree(std::vector<int64_t>& Position,std::pair<int64_t, int64_t> startEnd,std::pair<int64_t, int64_t> leftRight,int64_t Value,int64_t Node){
    if(startEnd.first>leftRight.second||startEnd.second<leftRight.first){
        return;
    }
    if (startEnd.first==startEnd.second){
        Position[Node]+=Value;
    }
    int64_t mid = (startEnd.first + startEnd.second) / 2;
    UpdateSegmentTree(Position, std::make_pair(startEnd.first, mid), leftRight,Value,2 * Node + 1);
    UpdateSegmentTree(Position, std::make_pair(mid+1, startEnd.second), leftRight,Value,2 * Node + 2);
}


int64_t MaxValue(std::vector<int64_t>& Position,std::pair<int64_t, int64_t> startEnd, std::pair<int64_t, int64_t> leftRight, int64_t Node){
    if(leftRight.second>startEnd.second||startEnd.first>leftRight.second){
        return std::numeric_limits<int64_t>::min();
    }
    if(startEnd.first>=leftRight.first&&startEnd.second<=leftRight.second){
        return Position[Node];

    }
    int64_t mid = (startEnd.first + startEnd.second) / 2;
    int64_t maxL=MaxValue(Position, std::make_pair(startEnd.first, mid), leftRight,2 * Node + 1);
    int64_t maxR=MaxValue(Position, std::make_pair(mid+1, startEnd.second), leftRight,2 * Node + 2);
    return std::max(maxL,maxR);
}
int main(){
    int64_t NumberofIgloos,Capacity,NumberofAttempts;
    std::vector<int64_t> NumberOfFailedAttemps;
    std::cin>>NumberofIgloos;
    std::vector<int64_t>GunterPositions(NumberofIgloos);
    for (int64_t i=0; i<NumberofIgloos; ++i) {
        std::cin>>GunterPositions[i];
    }
    std::vector<int64_t>SegmentTree (4*NumberofIgloos, 0);
    std::vector<int64_t> ExampleSegmentTree=BuildSegmentTree(GunterPositions, SegmentTree, 0, 0, NumberofIgloos-1);
    std::cin>>Capacity;
    std::cin>>NumberofAttempts;
    for (int64_t i = 0; i < NumberofAttempts; ++i) {
        int64_t TempLeft, TempRight, Value;
        std::cin>>TempLeft>>TempRight>>Value;
        if ((MaxValue(ExampleSegmentTree,std::make_pair(0, NumberofIgloos-1),std::make_pair(TempLeft, TempRight),0))+Value>Capacity){
            NumberOfFailedAttemps.emplace_back(i);
        }else{
            UpdateSegmentTree(ExampleSegmentTree, std::make_pair(0, NumberofIgloos-1),std::make_pair(TempLeft,TempRight), Value,0);
        }
    }
    for (auto i:NumberOfFailedAttemps) {
        std::cout<<i<<" ";
    }

}
