#pragma once

#include "Sorts1.h"

#include <cassert>

using namespace std;

template <typename T>
bool Is_Sorted(Sequence<T>* seq){
    int s = seq->GetLength();
    bool sorted = true;
    for (int i = 0; i < s-1; i++){
        if (seq->Get(i) > seq->Get(i+1)){
            sorted = false;
            break;
        }
    }
    return sorted;
}

void Test(){
    int arr1[8] = {3,2,6,5,7,5,3,3};
    int arr2[8] = {1,2,3,4,5,6,7,8};
    int arr3[8] = {5,5,5,5,5,5,5,5};
    int arr4[15] = {12,3,12,4,15,16,17,3,12,12,3,42,3,12,4};
    char arr5[10] = {'q','r','a','t','b','t','a','y','f','t'};
    string arr6[6] = {"aaab", "aaba", "abaa", "bbaa", "aabb", "baab"};

    Sequence<int>* ask1 = new ArraySequence<int>(arr1, 8);
    Sequence<int>* ask2 = new ArraySequence<int>(arr2, 8);
    Sequence<int>* ask3 = new ArraySequence<int>(arr3, 8);
    Sequence<int>* ask4 = new ArraySequence<int>(arr4, 15);
    Sequence<char>* ask5 = new ArraySequence<char>(arr5, 10);
    Sequence<string>* ask6 = new ArraySequence<string>(arr6, 6);

    Sequence<int>* ans1 = new ArraySequence<int>(Bubble_Sort(ask1));
    Sequence<int>* ans2 = new ArraySequence<int>(Bubble_Sort(ask2));
    Sequence<int>* ans3 = new ArraySequence<int>(Bubble_Sort(ask3));
    Sequence<int>* ans4 = new ArraySequence<int>(Bubble_Sort(ask4));
    Sequence<char>* ans5 = new ArraySequence<char>(Bubble_Sort(ask5));
    Sequence<string>* ans6 = new ArraySequence<string>(Bubble_Sort(ask6));

    assert(Is_Sorted(ans1));
    assert(Is_Sorted(ans2));
    assert(Is_Sorted(ans3));
    assert(Is_Sorted(ans4));
    assert(Is_Sorted(ans5));
    assert(Is_Sorted(ans6));

    cout << "Bubble sort works good" << endl;

    ans1 = new ArraySequence<int>(Insertion_Sort(ask1));
    ans2 = new ArraySequence<int>(Insertion_Sort(ask2));
    ans3 = new ArraySequence<int>(Insertion_Sort(ask3));
    ans4 = new ArraySequence<int>(Insertion_Sort(ask4));
    ans5 = new ArraySequence<char>(Insertion_Sort(ask5));
    ans6 = new ArraySequence<string>(Insertion_Sort(ask6));

    assert(Is_Sorted(ans1));
    assert(Is_Sorted(ans2));
    assert(Is_Sorted(ans3));
    assert(Is_Sorted(ans4));
    assert(Is_Sorted(ans5));
    assert(Is_Sorted(ans6));

    cout << "Insertion sort works good" << endl;

    ans1 = new ArraySequence<int>(Counting_Sort(ask1));
    ans2 = new ArraySequence<int>(Counting_Sort(ask2));
    ans3 = new ArraySequence<int>(Counting_Sort(ask3));
    ans4 = new ArraySequence<int>(Counting_Sort(ask4));
    ans5 = new ArraySequence<char>(Counting_Sort(ask5));
    ans6 = new ArraySequence<string>(Counting_Sort(ask6));

    assert(Is_Sorted(ans1));
    assert(Is_Sorted(ans2));
    assert(Is_Sorted(ans3));
    assert(Is_Sorted(ans4));
    assert(Is_Sorted(ans5));
    assert(Is_Sorted(ans6));

    cout << "Counting sort works good" << endl;

    ans1 = new ArraySequence<int>(Choise_Sort(ask1));
    ans2 = new ArraySequence<int>(Choise_Sort(ask2));
    ans3 = new ArraySequence<int>(Choise_Sort(ask3));
    ans4 = new ArraySequence<int>(Choise_Sort(ask4));
    ans5 = new ArraySequence<char>(Choise_Sort(ask5));
    ans6 = new ArraySequence<string>(Choise_Sort(ask6));

    assert(Is_Sorted(ans1));
    assert(Is_Sorted(ans2));
    assert(Is_Sorted(ans3));
    assert(Is_Sorted(ans4));
    assert(Is_Sorted(ans5));
    assert(Is_Sorted(ans6));

    cout << "Choise sort works good" << endl;

    ans1 = new ArraySequence<int>(Merge_Sort(ask1));
    ans2 = new ArraySequence<int>(Merge_Sort(ask2));
    ans3 = new ArraySequence<int>(Merge_Sort(ask3));
    ans4 = new ArraySequence<int>(Merge_Sort(ask4));
    ans5 = new ArraySequence<char>(Merge_Sort(ask5));
    ans6 = new ArraySequence<string>(Merge_Sort(ask6));

    assert(Is_Sorted(ans1));
    assert(Is_Sorted(ans2));
    assert(Is_Sorted(ans3));
    assert(Is_Sorted(ans4));
    assert(Is_Sorted(ans5));
    assert(Is_Sorted(ans6));

    cout << "Merge sort works good" << endl;
}