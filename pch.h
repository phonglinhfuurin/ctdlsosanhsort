
#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <conio.h>
#include <string>
#include <sstream>

using namespace std;

long length;
const long max_length = 250000 + 2;
unsigned long sophepsosanh = 0;
unsigned long sophepgan = 0;
//long int arr[max_length]; 
double time_taken = 0;
double atime[4][6][10];


//danhsachham:
void phatsinhRandom(long len, long *arr);
void phatsinhCothutu(long len, long *arr);
void phatsinhNguoc(long len, long *arr);
void phatsinhGan(long len, long *arr);

void SelectionSort(int A[], int n);
void insertionSort(long arr[], long n);

long binarySearch(long a[], long item, long low, long high);
void binaryinsertionSort(long a[], long n);

void radixSort(long a[], long n);
void swap(long *xp, long *yp);
void bubbleSort(long arr[], long n);

void shakerSort(long a[], long n);
void shellSort(long a[], long n);

void heapify(long arr[], long n, long i);
void heapSort(long arr[], long n);

void quickSort(long arr[], long left, long right);

//Ham Dat ten file
string DattenFile(int sophantu, int flagsort, int atype, int inout);
//void ghifile(long arr[], int ind, int flagsort, int atype);
void ghicsv();
void phatsinh(long len, long *arr);


#endif