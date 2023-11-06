// 04072213024-sehrish-siddique-assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <chrono>
#include <fstream>
//selection sort
int selectionSort(int arr[], int n) {
    int  temp = 0, min = 0; //min for comparing and temp for swapping
    for (int i = 0; i < n - 1; i++) {//loop to declare first elemnt of array as min
        min = arr[i];
        for (int j = (i + 1); j < n; j++) {//loop to compare min with value at next index
            if (arr[j] < min) {
                temp = arr[j];
                arr[j] = min;
                min = temp;     //swap if next element is smaller
                arr[i] = min;
            }
        }
        arr[i] = min;
    }
    return *arr;
}
int bubbleSort(int arr[], int n) {
    int count = 0, temp = 0;   //temp for swapping ad count to see whether array is sorted before completion of loops
    for (int i = 0; i < n - 1; i++) {
        count = 0;
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];    //this code will swap
                arr[j + 1] = temp;
                count++;
            }
        }
        if (count == 0) {
            break;
        }
    }
    return *arr;
}
int insertionSort(int arr[], int n) {
    int  temp = 0;    //temp as temporary storage for coparing purpose
    for (int i = 1; i < n; i++) {
        temp = arr[i];
        for (int j = (i - 1); j > -1; j--) {
            if (arr[j] > temp) {
                arr[j + 1] = arr[j];   //this code will shift the greater element one step further and smaller value will be placed at that index
                arr[j] = temp;
            }
        }
    }
    return *arr;
}
int main() {
    std::fstream f;
    f.open("ASSIGNMENT2.csv", std::ios::out);//file opening
    int arr=0;//for avg time
    int arr1=0;
    //implementing insertion sort
    for (int k = 0; k < 10; k++) {//for 10 executions
        //generating elements of array through rand 
        std::srand(std::time(nullptr));
        const int size = 1000000; //declarig size of array
        int* array = new int[size];//creating array

        for (int i = 0; i < size; i++) {
            array[i] = std::rand() % 10000000;//declaring range of elements
        }
        auto t1 = std::chrono::high_resolution_clock::now();//calculating time before insertion sorting func of random elements
        insertionSort(array, size);
        auto t2 = std::chrono::high_resolution_clock::now();//calculating time after insertion sorting func of random elemnts and before sorting sorted elements
        insertionSort(array, size);
        auto t3 = std::chrono::high_resolution_clock::now();//calculating time after insertion sorting func of sorted elements
       
       
        auto duration1 = std::chrono::duration_cast<std::chrono::seconds>(t3 - t2).count();//time in secs and for insertion sort function of random elements
        std::cout << "sorted:" << duration1 << std::endl;
        arr1 += duration1;
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count();//time in secs and for insertion sort function of sorted elements
       std::cout << "random:" << duration << std::endl;
        arr += duration;
        delete[]array;
    }
    arr /= 10;
    arr1 /= 10;
    //implementing bubble sort in same way as insertion
    int arr2=0;
    int arr3=0;
    for (int k = 0; k < 10; k++) {
        std::srand(std::time(nullptr));
        const int size1 = 1000000;
        int* array1 = new int[size1];

        for (int i = 0; i < size1; i++) {
            array1[i] = std::rand() % 10000000;
        }

        auto t4 = std::chrono::high_resolution_clock::now();
        insertionSort(array1, size1);
        auto t5 = std::chrono::high_resolution_clock::now();
        insertionSort(array1, size1);
        auto t6 = std::chrono::high_resolution_clock::now();
        auto duration2 = std::chrono::duration_cast<std::chrono::seconds>(t6 - t5).count();
        arr2 += duration2;
        std::cout << "sorted:" << duration2 << std::endl;
        auto duration3 = std::chrono::duration_cast<std::chrono::seconds>(t5 - t4).count();
        std::cout << "random" << duration3 << std::endl;
        arr3 += duration3;
        delete[]array1;
    }
    arr2 /= 10;
    arr3 /= 10;
    //implementing selection sort in same way as insertion
    int arr4=0;
    int arr5=0;
    for (int k = 0; k < 10; k++) {
        std::srand(std::time(nullptr));
        const int size2 = 1000000;
        int* array2 = new int[size2];

        for (int i = 0; i < size2; i++) {
            array2[i] = std::rand() % 10000000;
        }

        auto t7 = std::chrono::high_resolution_clock::now();
        insertionSort(array2, size2);
        auto t8 = std::chrono::high_resolution_clock::now();
        insertionSort(array2, size2);
        auto t9 = std::chrono::high_resolution_clock::now();
        auto duration4 = std::chrono::duration_cast<std::chrono::seconds>(t9 - t8).count();
        arr4 += duration4;
        std::cout << "sorted:" << duration4 << std::endl;
        auto duration5 = std::chrono::duration_cast<std::chrono::seconds>(t8 - t7).count();
        arr5 += duration5;
        std::cout << "random" << duration5 << std::endl;

        delete[]array2;
    }
    arr4 /= 10;
    arr5 /= 10;
    f << "ALGORITHM,SIZE,TYPE,RUN,AVERAGE" << std::endl;
    f << "insertion,1000000,random,10," << arr<<std::endl;
    f << "insertion,1000000,sorted,10," << arr1<<std::endl;
    f << "bubble,1000000,random,10," << arr3 << std::endl;
    f << "bubble,1000000,sorted,10," << arr2 << std::endl;
    f << "selection,1000000,random,10," << arr5 << std::endl;
    f << "selection,1000000,sorted,10," << arr4 << std::endl;
    f.close();
    return 0;
}