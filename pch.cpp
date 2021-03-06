
#include "pch.h"

void phatsinhRandom(long len, long *arr)
{

	srand(time(NULL));
	cout << "phat sinh " << len;
	for (long i = 0; i < len; i++)
	{
		arr[i] = rand() % 100000;
	}
}
void phatsinhCothutu(long len, long *arr)
{
	for (long i = 0; i < len; i++)
	{
		arr[i] = i + 1; 
	}
	cout << "phat sinh  co tu tu" << len;
}
void phatsinhNguoc(long len, long *arr)
{
	for (long i = 0; i < len; i++)
	{
		arr[i] = len + 1 - i; 
	}
	cout << "phat sinh nguoc " << len;
}
void phatsinhGan(long len, long *arr)
{
	int	temp = len * 80 / 100;
	for (int i = 0; i < temp; i++)
	{
		arr[i] = i + 1;

	} // gia su 80% phan tu dau tien da theo thu tu
	srand(time(NULL));
	for (int i = temp; i < len; i++)
	{
		arr[i] = rand() % 1000;
	}
	cout << "phat sinh gan" << len;
}


////////////////1.Selection Sort////////////
void SelectionSort(long A[], long n)
{
	long i, j, min_idx;

	for (i = 0; i < n - 1; i++)
	{
		// Tìm phần tử nhỏ nhất trong mảng
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (A[j] < A[min_idx])
				min_idx = j;

		// Đổi chỗ phần tử nhỏ nhất trong mảng
		//swap(&A[min_idx], &A[i]);
		long temp = A[min_idx];
		A[min_idx] = A[i];
		A[i] = temp;
	}
}


/////////////////// 2.INSERTION SORT/////////////
void insertionSort(long arr[], long n)
{
	long i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

/////////// 3.BINARY INSERTION SORRT/////////
long binarySearch(long a[], long item, long low, long high)
{
	if (high <= low)
		return (item > a[low]) ? (low + 1) : low;

	int mid = (low + high) / 2;

	if (item == a[mid])
		return mid + 1;

	if (item > a[mid])
		return binarySearch(a, item, mid + 1, high);
	return binarySearch(a, item, low, mid - 1);
}

void binaryinsertionSort(long a[], long n)
{
	long i, loc, j, selected;

	for (i = 1; i < n; ++i)
	{
		j = i - 1;
		selected = a[i];

		loc = binarySearch(a, selected, 0, j);
		while (j >= loc)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = selected;
	}
}

///////////////////4.RADIX SORT OPEN ////////////////////
void radixSort(long a[], long n)
{
	long i, m = a[0], exp = 1;
	long* b = (long*)malloc(n * sizeof(long));
	for (i = 0; i < n; i++)
	{
		if (a[i] > m)
		{
			m = a[i];
		}
	}
	while (m / exp > 0)
	{
		int bucket[10] = { 0 };
		for (i = 0; i < n; i++)
			bucket[a[i] / exp % 10]++;
		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (i = n - 1; i >= 0; i--)
		{
			b[--bucket[a[i] / exp % 10]] = a[i];
		}
		for (i = 0; i < n; i++)
		{
			a[i] = b[i];
		}
		exp *= 10;
	}
}


/////////////////// 5.BUBBLE SORT OPEN ///////////////////
void swap(long *xp, long *yp)
{
	long temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void bubbleSort(long arr[], long n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{

				long temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
}

/////////////////// 6.SHAKER SORT OPEN ///////////////////
void shakerSort(long a[], long n)
{
	long i, j, k;
	for (i = 0; i < n;)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[j - 1])
			{
				long temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
		n--;

		for (k = n - 1; k > i; k--)
		{
			if (a[k] < a[k - 1])
			{
				long temp = a[k];
				a[k] = a[k - 1];
				a[k - 1] = temp;
			}
		}
		i++;
	}
}


/////////////7.SHELLSORT////////////////////

void shellSort(long a[], long n)
{
	long i, j, k, temp;
	for (i = n / 2; i > 0; i = i / 2)
	{
		for (j = i; j < n; j++)
		{
			for (k = j - i; k >= 0; k = k - i)
			{
				if (a[k + i] >= a[k])
					break;
				else
				{

					temp = a[k];
					a[k] = a[k + i];
					a[k + i] = temp;
				}
			}
		}
	}
}


/////////////////// 8.HEAP SORT/////////////////////

void heapify(long arr[], long n, long i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		//swap(arr[i], arr[largest]);
		long temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		heapify(arr, n, largest);
	}
}

void heapSort(long arr[], long n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i >= 0; i--)
	{

		long temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr, i, 0);
	}
}

//////// 9.Merge /////////////
void merge(long arr[], long l, long m, long r)
{
	long i, j, k;
	long n1 = m - l + 1;
	long n2 = r - m;

	long *L = (long*)malloc(n1 * sizeof(long));
	long *R = (long*)malloc(n2 * sizeof(long));
	// long L[n1], R[n2];

	for (i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = arr[m + 1 + j];
	}
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(long arr[], long l, long r)
{
	if (l < r)
	{
		long m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}


//////// 10.quick sort /////////
void quickSort(long arr[], long left, long right)
{
	//time_t t = clock();
	long i = left;  long j = right;
	long tmp;
	long pivot = arr[(left + right) / 2];
	/* partition */
	while (i <= j) {

		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};
	/* recursion */

	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
	//t = clock() - t;
	//time_taken = ((double)t) / CLOCKS_PER_SEC;
}


////// interchange sort ////
void InterchangeSort(long a[], long n)
{
	for (long i = 0; i < n - 1; i++)
		for (long j = i + 1; j < n; j++)
			if (a[i] > a[j])
			{
				long temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
}


string DattenFile(int sophantu, int flagsort, int atype, int inout)
{
	ostringstream ss;
	switch (flagsort)
	{
	case 1:
		ss << "SelectionSort_";
		break;
	case 2:
		ss << "InsertionSort_";
		break;
	case 3:
		ss << "BinaryinsertionSort_";
		break;
	case 4:
		ss << "RadixSort_";
			break;
	case 5:
		ss << "BubbleSort_";
		break;
	case 6:
		ss << "ShakerSort_";
		break;
	case 7:
		ss << "ShellSort_";
		break;
	case 8:
		ss << "HeapSort_";
		break;
	case 9:
		ss << "MergeSort_";
		break;
	case 10:
		ss << "QuickSort_";
		break;
	}
	switch (atype)
	{
	case 101:
		ss << "RanDom_";
		break;
	case 102:
		ss << "Sorted_";
		break;
	case 103:
		ss << "NearlySort_";
		break;
	case 104:
		ss << "Reversed_";
		break;
	}
	ss << sophantu;
	if (inout == 1) {
		ss << ".in";
	}
	if (inout == 2)
	{
		ss << ".out";
	}
	return ss.str();
}
void ghifile(long arr[], int ind, int flagsort, int atype)
{
	ofstream taofilein, taofileout;
	string tenfilein, tenfileout;
	tenfilein = DattenFile(ind, flagsort, atype, 1);
	//flagin = 50; // tao ten file in
	taofilein.open(tenfilein);
	long *mang_phu = (long*)malloc(ind * sizeof(long));
	for (long j = 0; j < ind; j++)
	{
		mang_phu[j] = arr[j];
		taofilein << mang_phu[j] << "  ";
	}
	taofilein.close();
	//	flagin = 51;// tao ten file out;
	tenfileout = DattenFile(ind, flagsort, atype, 2);
	taofileout.open(tenfileout);
	clock_t  start = clock();
	switch (flagsort)
	{
	case 1:
		SelectionSort(mang_phu, ind);
		break;
	case 2:
		insertionSort(mang_phu, ind);
		break;
	case 3:
		binaryinsertionSort(mang_phu, ind);
		break;
	case 4:
		radixSort(mang_phu, ind);
		break;
	case 5:
		bubbleSort(mang_phu, ind);
		break;
	case 6:
		shakerSort(mang_phu, ind);
		break;
	case 7:
		shellSort(mang_phu, ind);
		break;
	case 8:
		heapSort(mang_phu, ind);
		break;
	case 9:
		mergeSort(mang_phu, 0, ind);
		break;
	case 10:
		quickSort(mang_phu, 0, ind);
		break;
	}


	clock_t  finish = clock();
	time_taken = (double)(finish-start) / CLOCKS_PER_SEC;
//	double time = time_taken;

	for (long j = 0; j < ind; j++)
	{
		taofileout << mang_phu[j] << "  ";
	}
	taofileout << "\n Thoi gian thuc hien: " << time_taken;
	//taofilein.close();
	//taofileout.close();
	int row = 0;
	int loai = 0;
	switch (atype)
	{
	case (101):
		loai = 0;
		break;
	case (102):
		loai = 1;
		break;
	case (103):
		loai = 2;
		break;
	case (104):
		loai = 3;
		break;

	}

	switch (ind)
	{
	case 1000:
		row = 0;
		break;
	case 5000:
		row = 1;
		break;
	case 10000:
		row = 2;
		break;
	case 50000:
		row = 3;
		break;
	case 100000:
		row = 4;
		break;
	case 250000:
		row = 5;
		break;
	}
	atime[loai][row][flagsort - 1] = time_taken;
	
	//fout << " thoi gian chay:  " << time_taken << "\n";
}

void ghicsv()
{
	int arrsl[6];
	arrsl[0] = 1000;
	arrsl[1] = 5000;
	arrsl[2] = 10000;
	arrsl[3] = 50000;
	arrsl[4] = 100000;
	arrsl[5] = 250000;
	ofstream fout("Result.csv");
	fout << "Input_state,(1)SelectionSort,(2)InsertionSort,(3)BinaryInsertionSort,(4)RadixSort,(5)BubbleSort";
	fout << "(6)ShakerSort,(7)ShellShort,(8)HeapSort,(9)MergeSort,(10)QuickSort\n";
	for (int dem1 = 0; dem1 < 4; dem1++)
	{
		for (int dem2 = 0; dem2 < 6; dem2++)
		{
			for (int dem3 = 0; dem3 < 10; dem3++)
			{
				if (dem1 == 0)
				{
					fout << "Random," << arrsl[dem2];
					fout << "," << atime[dem1][dem2][dem3];
				}

				else if (dem1 == 1)
				{
					fout << "Sorted," << arrsl[dem2];
					fout << "," << atime[dem1][dem2][dem3];
				}

				else if (dem1 == 2)
				{
					fout << "Reversed," << arrsl[dem2];
					fout << "," << atime[dem1][dem2][dem3];
				}

				else if (dem1 == 3)
				{
					fout << "Nearly Sorted," << arrsl[dem2];
					fout << "," << atime[dem1][dem2][dem3];
				}


			}

		}

	}
}