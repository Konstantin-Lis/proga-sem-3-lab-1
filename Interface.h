#pragma once

//#include "Sorts_for_Arrays.h"
//#include "Sorts_for_Lists.h"
#include "Sorts1.h"

#include <iostream>

using namespace std;

void Interface(){
    while(true){
        int size = -1;
        int choose = 0;
        cout << "MAIN MENU" << endl;
        cout << "Enter 1 to add a sequence" << endl;
        cout << "Enter 0 to exit" << endl;
        cin >> choose;
        cout << endl;
        bool finish = false;
        switch (choose){
            case 0:
                finish = true;
                break;
            case 1:
                cout << "Enter size of sequence: ";
                cin >> size;
                cout << endl;
                while (size <= 0){
                    cout << "Size of sequence must be positive" << endl;
                    cout << "Enter size of sequence: ";
                    cin >> size;
                    cout << endl;
                }
                break;
            default:
                break;
        }
        if (finish) {
            break;
        }

        if (size != -1){
            Sequence<int>* seq;
            cout << "Enter 1 to use arrays" << endl;
            cout << "Enter 2 to use lists" << endl;
            cin >> choose;
            cout << endl;
            switch (choose) {
                case 0:
                    break;
                case 1:
                    seq = new ArraySequence<int>(size);
                    break;
                case 2:
                    seq = new ListSequence<int>(size);
                    break;
                default:
                    break;
            }
            cout << "Enter 0 to exit to Main menu" << endl;
            cout << "Enter 1 to fill in the sequence with random integer numbers" << endl;
            cout << "Enter 2 to fill in the sequence manually" << endl;
            cin >> choose;
            cout << endl;
            switch (choose){
                case 0:
                    finish = true;
                    break;
                case 1:
                    srand(time(0));
                    for (int i = 0; i < size; i++){
                        seq->Set(i, rand());
                    }
                    break;
                case 2:
                    int elem;
                    for (int i = 0; i < size; i++){
                        cout << "Enter element " << i+1 << ":";
                        cin >> elem;
                        cout << endl;
                        seq->Set(i, elem);
                    }
                    break;
                default:
                    break;
            }
            if (not finish){
                cout << "Your sequence:" << endl;
                PrintVec(seq);
                cout << "Enter 0 to exit to Main menu" << endl;
                cout << "Enter 1 to sort by Bubble sort" << endl;
                cout << "Enter 2 to sort by Insertion sort" << endl;
                cout << "Enter 3 to sort by Counting sort" << endl;
                cout << "Enter 4 to sort by Choise sort" << endl;
                cout << "Enter 5 to sort by Merge sort" << endl;
                cout << "Enter 6 to look at time of every sort" << endl;
                cout << "CAUTION: If size more than 20.000, computer will work more then 5 seconds for every sort, except Merge sort" << endl;
                switch (choose) {
                    case 0:
                        break;
                    case 1:
                        Learn_Sorting_Time_And_Sorted_Sequence(Bubble_Sort, seq, "Bubble sort");
                        break;
                    case 2:
                        Learn_Sorting_Time_And_Sorted_Sequence(Insertion_Sort, seq, "Insertion sort");
                        break;
                    case 3:
                        Learn_Sorting_Time_And_Sorted_Sequence(Counting_Sort, seq, "Counting sort");
                        break;
                    case 4:
                        Learn_Sorting_Time_And_Sorted_Sequence(Choise_Sort, seq, "Choise sort");
                        break;
                    case 5:
                        Learn_Sorting_Time_And_Sorted_Sequence(Merge_Sort, seq, "Merge sort");
                        break;
                    case 6:
                        Learn_Sorting_Time(Bubble_Sort, seq, "Bubble sort");
                        Learn_Sorting_Time(Insertion_Sort, seq, "Insertion sort");
                        Learn_Sorting_Time(Counting_Sort, seq, "Counting sort");
                        Learn_Sorting_Time(Choise_Sort, seq, "Choise sort");
                        Learn_Sorting_Time(Merge_Sort, seq, "Merge sort");
                        break;
                    default:
                        break;
                }
            }
        }
    }
}