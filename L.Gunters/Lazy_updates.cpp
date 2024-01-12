//
// Created by rituparn on 29.12.23.
//


#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

void BuildSegmentTree(std::vector<int64_t>& Position, std::vector<int64_t>& SegmentTree, int64_t Node, int64_t start, int64_t end) {
    if (start == end) {
        SegmentTree[Node] = Position[start];
    } else {
        int64_t mid = (start + end) / 2;
        BuildSegmentTree(Position, SegmentTree, 2 * Node + 1, start, mid);
        BuildSegmentTree(Position, SegmentTree, 2 * Node + 2, mid + 1, end);
        SegmentTree[Node] = std::max(SegmentTree[2 * Node + 1], SegmentTree[2 * Node + 2]);
    }
}


void UpdateSegmentTree (std::vector<int64_t>&SegmentTree,std::vector<int64_t>&LazyTree,std::pair<int64_t, int64_t> startEnd,std::pair<int64_t, int64_t> leftRight,int64_t Value,int64_t Node) {
    if (startEnd.first > startEnd.second) {
        return;
    }
    if (LazyTree[Node] != 0) {
        SegmentTree[Node] += LazyTree[Node];
        if (startEnd.first != startEnd.second) {
            LazyTree[2 * Node + 1] += LazyTree[Node];
            LazyTree[2 * Node + 2] += LazyTree[Node];
        }
        LazyTree[Node] = 0;
    }
    if (leftRight.first>startEnd.second||leftRight.second<startEnd.first){
        return;
    }
    if (leftRight.first<=startEnd.first&&leftRight.second>=startEnd.second){
        SegmentTree[Node]+=Value;
        if (startEnd.first != startEnd.second){
            LazyTree[2 * Node + 1] += Value;
            LazyTree[2 * Node + 2] += Value;
        }
        return;
    }
    int64_t Middle=(startEnd.first+startEnd.second)/2;
    UpdateSegmentTree(SegmentTree,LazyTree, std::make_pair(startEnd.first, Middle), leftRight, Value, 2*Node+1);
    UpdateSegmentTree(SegmentTree,LazyTree, std::make_pair(Middle+1, startEnd.second), leftRight,Value, 2*Node+2);
    SegmentTree[Node]=std::max(SegmentTree[2*Node+1],SegmentTree[2*Node+2]);


}

int64_t MaxValue(std::vector<int64_t> &SegmentTree, std::vector<int64_t> &LazyTree,std::pair<int64_t, int64_t> startEnd, std::pair<int64_t, int64_t> leftRight, int64_t Node) {
    if (startEnd.first > startEnd.second) {
        return std::numeric_limits<int64_t>::min();
    }
    if (LazyTree[Node] != 0) {
        SegmentTree[Node] += LazyTree[Node];
        if (startEnd.first != startEnd.second) {
            LazyTree[2 * Node + 1] += LazyTree[Node];
            LazyTree[2 * Node + 2] += LazyTree[Node];
        }
        LazyTree[Node] = 0;
    }
    if (leftRight.first > startEnd.second || leftRight.second < startEnd.first) {
        return std::numeric_limits<int64_t>::min();
    }

    if(leftRight.first<=startEnd.first&&leftRight.second>=startEnd.second){
        return SegmentTree[Node];
    }
    int64_t Middle=(startEnd.first+startEnd.second)/2;
    int64_t leftMax=MaxValue(SegmentTree,LazyTree, std::make_pair(startEnd.first, Middle), leftRight, 2*Node+1);
    int64_t rightMax=MaxValue(SegmentTree,LazyTree, std::make_pair(Middle+1, startEnd.second), leftRight, 2*Node+2);
    return std::max(leftMax,rightMax);
}




int main(){
    int64_t NumberofIgloos,Capacity,NumberofAttempts;
    std::vector<int64_t> NumberOfFailedAttemps;
    std::cin>>NumberofIgloos;
    std::vector<int64_t>GunterPositions(NumberofIgloos);
    for (int64_t i=0; i<NumberofIgloos; i++) {
        std::cin>>GunterPositions[i];
    }
    std::vector<int64_t>SegmentTree (4*NumberofIgloos);
    std::vector<int64_t > lazyTree(4 * NumberofIgloos,0);
    BuildSegmentTree(GunterPositions, SegmentTree, 0, 0, NumberofIgloos-1);
    std::cin>>Capacity;
    std::cin>>NumberofAttempts;
    for (int64_t i = 0; i < NumberofAttempts; i++) {
        int64_t TempLeft, TempRight, Value;
        std::cin>>TempLeft>>TempRight>>Value;
        if (MaxValue(SegmentTree,lazyTree,std::make_pair(0, NumberofIgloos-1),std::make_pair(TempLeft, TempRight),0)+Value>Capacity){
            NumberOfFailedAttemps.emplace_back(i);


        }else{
            UpdateSegmentTree(SegmentTree, lazyTree,std::make_pair(0, NumberofIgloos-1),std::make_pair(TempLeft,TempRight), Value,0);
        }
    }
    for (auto i:NumberOfFailedAttemps) {
        std::cout<<i<<" ";
    }

}
