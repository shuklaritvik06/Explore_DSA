//
// Created by rituparn on 21.10.23.
//

#include <iostream>
#include <array>
#include <tuple> //for get method

int main (){

    std::array<int, 6> ar= {2,3,4,5,6,7};
    std::cout<<"The array is: \n";
    for (int i = 0; i < 6; ++i) {
        std::cout<<ar.at(i)<<std::endl;  //at method return the value at an index
    }

    return 0;
}

/*
 Operations on array :-
1. at() :- This function is used to access the elements of array.
2. get() :- This function is also used to access the elements of array. This function is not the member of array class but overloaded function from class tuple.
3. operator[] :- This is similar to C-style arrays. This method is also used to access array elements.
4. front() :- This returns reference to  the first element of array.
5. back() :- This returns reference to the last element of array.
6. size() :- It returns the number of elements in array. This is a property that C-style arrays lack.
7. max_size() :- It returns the maximum number of elements array can hold i.e, the size with which array is declared. The size() and max_size() return the same value.
8. swap() :- The swap() swaps all elements of one array with other.
9. empty() :- This function returns true when the array size is zero else returns false.
10. fill() :- This function is used to fill the entire array with a particular value.
 */