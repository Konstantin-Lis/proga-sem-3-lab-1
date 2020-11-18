#pragma once

#include "Sorts1.h"
#include "Tests.h"

#include <iostream>

using namespace std;

void Interface(){
    while(true){
        int size = -1;
        int choose = 0;
        cout << "MAIN MENU" << endl;
        cout << "Enter 1 to add a sequence" << endl;
        cout << "Enter 2 to look tests results" << endl;
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
            case 2:
                cout << "Sorting arrays: " << endl;
                ArrayTests();
                cout << "Sorting lists: " << endl;
                ListTests();
                cout << endl;
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
                        seq->Set(i, rand()%size + 1);
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
                cin >> choose;
                cout << endl;
                switch (choose) {
                    case 0:
                        break;
                    case 1:
                        PrintVec(Bubble_Sort(seq));
                        break;
                    case 2:
                        PrintVec(Insertion_Sort(seq));
                        break;
                    case 3:
                        PrintVec(Counting_Sort(seq));
                        break;
                    case 4:
                        PrintVec(Choise_Sort(seq));
                        break;
                    case 5:
                        PrintVec(Merge_Sort(seq));
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
