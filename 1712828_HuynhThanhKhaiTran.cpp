// 1712828_HuynhThanhKhaiTran.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

//double atime[4][6][10];
//int arrsl[6];

int main()
{
	/*arrsl[0] = 1000;
	arrsl[1] = 5000;
	arrsl[2] = 10000;
	arrsl[3] = 50000;
	arrsl[4] = 100000;
	arrsl[5] = 250000;*/

//	ofstream fout("Result.csv");
//	fout << "Input_state,(1)SelectionSort,(2)InsertionSort,(3)BinaryInsertionSort,(4)RadixSort,(5)BubbleSort";
//	fout << "(6)ShakerSort,(7)ShellShort,(8)HeapSort,(9)MergeSort,(10)QuickSort\n";
	/*for (long ind = 1000; ind < max_length; )
	{

		long *mang_phu = (long*)malloc(ind * sizeof(long));
		long *arrRan = (long*)malloc(ind * sizeof(long));
		long *arrCo = (long*)malloc(ind * sizeof(long));
		long *arrNguoc = (long*)malloc(ind * sizeof(long));
		long *arrGan = (long*)malloc(ind * sizeof(long));
		fout << "\n ********* N = " << ind << "\n";
		phatsinhRandom(ind, arrRan); //atype= 101;
		phatsinhCothutu(ind, arrCo); //atype=102;
		phatsinhNguoc(ind, arrNguoc); // atype=103;
		phatsinhGan(ind, arrGan); //atype=104;

		// random: atype =1 //
		fout << "Random";
		for (int dem = 0; dem < 10; dem++)
		{
			ghifile(arrRan, ind, dem + 1, 101);
			ghifile(arrCo, ind, dem + 1, 102);
			ghifile(arrNguoc, ind, dem + 1, 103);
			ghifile(arrGan, ind, dem + 1, 104);
		}
		   		 	  	  	 
		if ((ind == 1000) || (ind == 10000)) { ind = ind * 5; }
		else if ((ind == 5000) || (ind == 50000)) { ind = ind * 2; }
		else if (ind == 100000) { ind = 250000; }
		else if (ind == 250000) {
			break;
		}
		cout << " da ghi xong file " << ind; 
	}*/
	
	//fout.close();
	ghicsv();


}

