#pragma once

#include "Sequence.h"
#include "Array_Sequence.h"
#include "List_Sequence.h"

#include <iostream>
#include <ctime>
using namespace std;

//Вывод вектора
template <typename T>
void PrintVec(Sequence<T>* vec){
    int a = vec->GetLength();
    for (int i = 0; i < a; i++){
        cout << vec->Get(i) << " ";
        if (i % 15 == 14){
            cout << endl;
        }
    }
    cout << endl;
}

//Узнаем и выводим время на сортировку
template <typename T>
void Learn_Sorting_Time(Sequence<T>* func(Sequence<T>*), Sequence<T>* vec, string sort_name){
    int start = clock();
    func(vec);
    int finish = clock();
    cout << sort_name << ": " << finish - start << "ms" << endl;
}

//Узнаем и выводим время на сортировку и отсортированную последовательность
template <typename T, typename Conteiner>
void Learn_Sorting_Time_And_Sorted_Sequence(Sequence<T>* func(Sequence<T>*), Sequence<T>* vec, string sort_name){
    int start = clock();
    Conteiner* seq = new ListSequence<T>(func(vec));
    int finish = clock();
    cout << sort_name << ": " << finish - start << "ms" << endl;
    PrintVec(seq);
}

//Сортировка пузырьком от меньшего к большему
template <typename T, typename Conteiner>
Conteiner* Bubble_Sort(Sequence<T>* vec){
    int s = vec->GetLength();
    for (int i = 1; i < s; i++){
        for (int j = 0; j < i; j++){
            if (vec->Get(i) < vec->Get(j)){
                T a = vec->Get(i);
                vec->Set(i, vec->Get(j));
                vec->Set(j, a);
            }
        }
    }
    return vec;
}


//сортировка вставками от меньшего к большему
template <typename T, typename Conteiner>
Conteiner* Insertion_Sort(Sequence<T>* vec){
    int s = vec->GetLength();
    for (int i = 1; i < s; i++){
        for (int j = 0; j < i; j++){
            if (vec->Get(i) < vec->Get(j)){
                int k = i;
                T a = vec->Get(i);
                for (k = i; k > j; k--){
                    vec->Set(k, vec->Get(k-1));
                }
                vec->Set(j, a);
            }
        }
    }
    return vec;
}

//сортировка выбором от меньшего к большему
template <typename T, typename Conteiner>
Conteiner* Choise_Sort(Sequence<T>* vec){
    int s = vec->GetLength();
    for (int i = 0; i < s; i++){
        int min_ind = i;
        for (int j = i; j < s; j++){
            if (vec->Get(j) < vec->Get(min_ind)){
                min_ind = j;
            }
        }
        T a = vec->Get(i);
        vec->Set(i, vec->Get(min_ind));
        vec->Set(min_ind, a);
    }
    return vec;
}

//Сортировка подсчетом от меньшего к большему
//Вспомогательная функция для проверки учтен ли элемент ранее
template <typename T>
bool Is_In(T elem, Sequence<T>* elements){
    int s = elements->GetLength();
    bool is_in = false;
    for (int i = 0; i < s; i++){
        if (elem == elements->Get(i)){
            is_in = true;
            break;
        }
    }
    return is_in;
}

//Сама сортировка
template <typename T, typename Conteiner>
Conteiner* Counting_Sort(Sequence<T>* vec) {
    int s = vec->GetLength();
    int k = 1;
    Sequence<T> *ans = new ArraySequence<T>(0);
    Sequence<T> *elements = new ArraySequence<T>(0);
    Sequence<int> *numbers = new ArraySequence<int>(0);
    elements->Set(0, vec->GetFirst());
    numbers->Set(0, 1);
    for (int i = 1; i < s; i++) {
        if (Is_In(vec->Get(i), elements)) {
            int j = 0;
            while (vec->Get(i) != elements->Get(j)) {
                j++;
            }
            int num = numbers->Get(j);
            numbers->Set(j, num + 1);
        } else {
            elements->Append(vec->Get(i));
            numbers->Append(1);
            k++;
        }
    }
    ans->Set(0, elements->GetFirst());
    T elem = elements->GetFirst();
    for (int m = 1; m < numbers->GetFirst(); m++) {
        ans->Append(elem);
    }
    for (int i = 1; i < k; i++) {
        T elem = elements->Get(i);
        int s = ans->GetLength();
        bool added = false;
        for (int j = 0; j < s; j++) {
            if (ans->Get(j) > elem) {
                added = true;
                for (int m = 0; m < numbers->Get(i); m++) {
                    ans->InsertAt(j, elem);
                }
                break;
            }
        }
        if (not added) {
            for (int m = 0; m < numbers->Get(i); m++) {
                ans->Append(elem);
            }
        }
    }
    return ans;
}

//Сортировка слиянием от меньшего к большему
//Разделяем данные на 2 части
template <typename T, typename Conteiner>
Conteiner* Divide1(Sequence<T>* vec){
    int s = vec->GetLength();
    Sequence<T>* vec1 = new ArraySequence<T>(s/2);
    for (int i = 0; i < s/2; i++){
        vec1->Set(i, vec->Get(i));
    }
    return vec1;
}

template <typename T, typename Conteiner>
Conteiner* Divide2(Sequence<T>* vec){
    int s = vec->GetLength();
    Sequence<T>* vec2 = new ArraySequence<T>(s-s/2);
    for (int i = s/2; i < s; i++){
        vec2->Set(i-s/2, vec->Get(i));
    }
    return vec2;
}

//Соединяем 2 части в одну
template <typename T, typename Conteiner>
Conteiner* Merging(Sequence<T>* vec1, Sequence<T>* vec2){
    int i1 = 0;
    int i2 = 0;
    int s1 = vec1->GetLength();
    int s2 = vec2->GetLength();
    Sequence<T>* vec = new ArraySequence<T>(s1+s2);
    while (i1 + i2 < s1 + s2){
        if (i1 < s1 and i2 < s2){
            if (vec1->Get(i1) < vec2->Get(i2)){
                vec->Set(i1+i2, vec1->Get(i1));
                i1++;
            }
            else {
                vec->Set(i1+i2, vec2->Get(i2));
                i2++;
            }
        }
        else if (i1 == s1){
            vec->Set(i1+i2, vec2->Get(i2));
            i2++;
        }
        else {
            vec->Set(i1+i2, vec1->Get(i1));
            i1++;
        }
    }
    return vec;
}

//Соединяем разделение и соединение
template <typename T, typename Conteiner>
Conteiner* Merge_Sort(Sequence<T>* vec){
    int s = vec->GetLength();
    if (s > 1){
        Sequence<T>* vec1 = Divide1(vec);
        Sequence<T>* vec2 = Divide2(vec);
        int s1 = vec1->GetLength();
        if (s1 > 1){
            vec1 = Merge_Sort(vec1);
        }
        int s2 = vec2->GetLength();
        if (s2 > 1){
            vec2 = Merge_Sort(vec2);
        }
        vec = Merging(vec1, vec2);
    }
    return vec;
}
