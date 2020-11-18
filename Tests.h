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

void ArrayTests(){
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

    Sequence<int>* ans1 = new ArraySequence<int>();
    Sequence<int>* ans2 = new ArraySequence<int>();
    Sequence<int>* ans3 = new ArraySequence<int>();
    Sequence<int>* ans4 = new ArraySequence<int>();
    Sequence<char>* ans5 = new ArraySequence<char>();
    Sequence<string>* ans6 = new ArraySequence<string>();

    ans1 = Bubble_Sort(ask1);
    ans2 = Bubble_Sort(ask2);
    ans3 = Bubble_Sort(ask3);
    ans4 = Bubble_Sort(ask4);
    ans5 = Bubble_Sort(ask5);
    ans6 = Bubble_Sort(ask6);

    assert(Is_Sorted(ans1));
    assert(Is_Sorted(ans2));
    assert(Is_Sorted(ans3));
    assert(Is_Sorted(ans4));
    assert(Is_Sorted(ans5));
    assert(Is_Sorted(ans6));

    cout << "Bubble sort works good" << endl;

    ans1 = Insertion_Sort(ask1);
    ans2 = Insertion_Sort(ask2);
    ans3 = Insertion_Sort(ask3);
    ans4 = Insertion_Sort(ask4);
    ans5 = Insertion_Sort(ask5);
    ans6 = Insertion_Sort(ask6);

    assert(Is_Sorted(ans1));
    assert(Is_Sorted(ans2));
    assert(Is_Sorted(ans3));
    assert(Is_Sorted(ans4));
    assert(Is_Sorted(ans5));
    assert(Is_Sorted(ans6));

    cout << "Insertion sort works good" << endl;

    ans1 = Counting_Sort(ask1);
    ans2 = Counting_Sort(ask2);
    ans3 = Counting_Sort(ask3);
    ans4 = Counting_Sort(ask4);
    ans5 = Counting_Sort(ask5);
    ans6 = Counting_Sort(ask6);

    assert(Is_Sorted(ans1));
    assert(Is_Sorted(ans2));
    assert(Is_Sorted(ans3));
    assert(Is_Sorted(ans4));
    assert(Is_Sorted(ans5));
    assert(Is_Sorted(ans6));

    cout << "Counting sort works good" << endl;

    ans1 = Choise_Sort(ask1);
    ans2 = Choise_Sort(ask2);
    ans3 = Choise_Sort(ask3);
    ans4 = Choise_Sort(ask4);
    ans5 = Choise_Sort(ask5);
    ans6 = Choise_Sort(ask6);

    assert(Is_Sorted(ans1));
    assert(Is_Sorted(ans2));
    assert(Is_Sorted(ans3));
    assert(Is_Sorted(ans4));
    assert(Is_Sorted(ans5));
    assert(Is_Sorted(ans6));

    cout << "Choise sort works good" << endl;

    ans1 = Merge_Sort(ask1);
    ans2 = Merge_Sort(ask2);
    ans3 = Merge_Sort(ask3);
    ans4 = Merge_Sort(ask4);
    ans5 = Merge_Sort(ask5);
    ans6 = Merge_Sort(ask6);

    assert(Is_Sorted(ans1));
    assert(Is_Sorted(ans2));
    assert(Is_Sorted(ans3));
    assert(Is_Sorted(ans4));
    assert(Is_Sorted(ans5));
    assert(Is_Sorted(ans6));

    cout << "Merge sort works good" << endl;
}

void ListTests(){
    int arr1[8] = {3,2,6,5,7,5,3,3};
    int arr2[8] = {1,2,3,4,5,6,7,8};
    int arr3[8] = {5,5,5,5,5,5,5,5};
    int arr4[15] = {12,3,12,4,15,16,17,3,12,12,3,42,3,12,4};
    char arr5[10] = {'q','r','a','t','b','t','a','y','f','t'};
    string arr6[6] = {"aaab", "aaba", "abaa", "bbaa", "aabb", "baab"};

    Sequence<int>* ask1 = new ListSequence<int>(arr1, 8);
    Sequence<int>* ask2 = new ListSequence<int>(arr2, 8);
    Sequence<int>* ask3 = new ListSequence<int>(arr3, 8);
    Sequence<int>* ask4 = new ListSequence<int>(arr4, 15);
    Sequence<char>* ask5 = new ListSequence<char>(arr5, 10);
    Sequence<string>* ask6 = new ListSequence<string>(arr6, 6);

    Sequence<int>* ans1 = new ListSequence<int>();
    Sequence<int>* ans2 = new ListSequence<int>();
    Sequence<int>* ans3 = new ListSequence<int>();
    Sequence<int>* ans4 = new ListSequence<int>();
    Sequence<char>* ans5 = new ListSequence<char>();
    Sequence<string>* ans6 = new ListSequence<string>();

    ans1 = Bubble_Sort(ask1);
    ans2 = Bubble_Sort(ask2);
    ans3 = Bubble_Sort(ask3);
    ans4 = Bubble_Sort(ask4);
    ans5 = Bubble_Sort(ask5);
    ans6 = Bubble_Sort(ask6);

    assert(Is_Sorted(ans1));
    assert(Is_Sorted(ans2));
    assert(Is_Sorted(ans3));
    assert(Is_Sorted(ans4));
    assert(Is_Sorted(ans5));
    assert(Is_Sorted(ans6));

    cout << "Bubble sort works good" << endl;

    ans1 = Insertion_Sort(ask1);
    ans2 = Insertion_Sort(ask2);
    ans3 = Insertion_Sort(ask3);
    ans4 = Insertion_Sort(ask4);
    ans5 = Insertion_Sort(ask5);
    ans6 = Insertion_Sort(ask6);

    assert(Is_Sorted(ans1));
    assert(Is_Sorted(ans2));
    assert(Is_Sorted(ans3));
    assert(Is_Sorted(ans4));
    assert(Is_Sorted(ans5));
    assert(Is_Sorted(ans6));

    cout << "Insertion sort works good" << endl;

    ans1 = Counting_Sort(ask1);
    ans2 = Counting_Sort(ask2);
    ans3 = Counting_Sort(ask3);
    ans4 = Counting_Sort(ask4);
    ans5 = Counting_Sort(ask5);
    ans6 = Counting_Sort(ask6);

    assert(Is_Sorted(ans1));
    assert(Is_Sorted(ans2));
    assert(Is_Sorted(ans3));
    assert(Is_Sorted(ans4));
    assert(Is_Sorted(ans5));
    assert(Is_Sorted(ans6));

    cout << "Counting sort works good" << endl;

    ans1 = Choise_Sort(ask1);
    ans2 = Choise_Sort(ask2);
    ans3 = Choise_Sort(ask3);
    ans4 = Choise_Sort(ask4);
    ans5 = Choise_Sort(ask5);
    ans6 = Choise_Sort(ask6);

    assert(Is_Sorted(ans1));
    assert(Is_Sorted(ans2));
    assert(Is_Sorted(ans3));
    assert(Is_Sorted(ans4));
    assert(Is_Sorted(ans5));
    assert(Is_Sorted(ans6));

    cout << "Choise sort works good" << endl;

    ans1 = Merge_Sort(ask1);
    ans2 = Merge_Sort(ask2);
    ans3 = Merge_Sort(ask3);
    ans4 = Merge_Sort(ask4);
    ans5 = Merge_Sort(ask5);
    ans6 = Merge_Sort(ask6);

    assert(Is_Sorted(ans1));
    assert(Is_Sorted(ans2));
    assert(Is_Sorted(ans3));
    assert(Is_Sorted(ans4));
    assert(Is_Sorted(ans5));
    assert(Is_Sorted(ans6));

    cout << "Merge sort works good" << endl;
}
