#include "Interface.h"

#include <iostream>
#include <string>
using namespace std;

int main() {
    Interface<int>();

    return 0;

    /*
    int n;
    cin >> n;
    Sequence<int>* vec = new ArraySequence<int>(n);
    for (int i = 0; i < n; i++){
        int a = rand()%n + 1;
        vec->Set(i, a);
    }
//    vector<string> vecs = {"aaab", "aaba", "abaa", "bbaa", "aabb", "baab"};
//    PrintVec(vec);
//    PrintVec(Bubble_Sort(vec));
//    PrintVec(Merge_Sort(vec));
//    PrintVec(Insertion_Sort(vec));
//    PrintVec(Counting_Sort(vec));
//    PrintVec(Choise_Sort(vec));


//    Learn_Sorting_Time(Counting_Sort, vec, "Counting sort");
//    Learn_Sorting_Time(Merge_Sort, vec, "Merge sort");
//    Learn_Sorting_Time(Choise_Sort, vec, "Choise sort");
//    Learn_Sorting_Time(Insertion_Sort, vec, "Insertion sort");
//    Learn_Sorting_Time(Bubble_Sort, vec, "Bubble sort");
     */
}
