//
// Created by rituparn on 22.10.23.
//


//single list is the double linked list

// C++ program to demonstrate the implementation of List

#include<iostream>
#include <iterator>
#include <list>

using namespace std;

void showList (list<int> g){
    list<int>::iterator it;   //declaring the iterator of the type list
    for(it=g.begin();it!=g.end(); ++it){
        std::cout<<"\t"<<*it;  //dereferencing the iterator using the aesterisk

    std::cout<<"\n";
    }

}

int main  (){
    std::list<int> list1;
    std::list<int> list2;

    for (int i = 0; i < 10; ++i) {
        list1.push_back(i*2);
        list2.push_back(i*3);
    }

    std::cout<<"The list 1 is: \n";
    showList(list1);

    std::cout<<"The list 2 is: \n";
    showList(list2);

    std::cout<<"The list1 reversed is: \n";
    list1.reverse();
    showList(list1);

    std::cout<<"The list2 back is: \n";
    list2.back();

    std::cout<<"The list2 front is: \n";
    list2.front();

    std::cout<<"The list2 popped from back is: \n";
    list2.pop_back();

    std::cout<<"The list2 sorted is: \n";
    list2.sort();
    showList(list2);


    return 0;

}