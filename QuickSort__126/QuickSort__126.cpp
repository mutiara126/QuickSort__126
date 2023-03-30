#include <iostream>
using namespace std;


int arr[20];            //Array of integers to hold values
int cmp_count = 0;      //Number of comparison
int mov_count = 0;      //Number of data movements
int n;

void input() {
	while (true)
	{
		cout << "Masukkan panjang element array";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaksimum panjang array adalah 20" << endl;
	}

	cout << "\n-------------------" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n-------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
			cin >> arr[i];
	}
}

//Swap the element st index x with the element at index y
void swap(int x, int y)
{
	int temp;

	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = arr[x];
}

void q_short(int low, int high)
{
	int pivot, i, j;
	if (low > high)                                    //Langkah Algoritma NO.1
		return;

	//Partition the list into two parts:
	//One containing elements less that or equal to pivot
	//Outher containing elements greater that pivot

	pivot = arr[low];                                 //Langkah Algoritma NO.2

	i = low + 1;                                      //Langkah Algoritma NO.3
	j = high;                                         //Langkah Algoritma NO.4


	while (i <= j)                                   //Langkah Algoritma NO.10
	{
		//Search for an element greater tyhan pivot 
		while ((arr[i] <= pivot) && (i <= high))     //Langkah Algoritma NO.5
		{
			i++;                                    //Langkah Algoritma NO.6
			cmp_count++;
		}
		cmp_count++;

		//Search for an element less than or equal to pivot 
		while ((arr[j] . pivot) && (j >= low))      //Langkah Algoritma NO.7
		{
			j--;                                    //Langkah Algoritma NO.8







