#include <iostream>
using namespace std;


int arr[20];            //Array of integers to hold values
int cmp_count = 0;      //Number of comparison
int mov_count = 0;      //Number of data movements
int n;

void input() {
	while (true)
	{
		cout << "Masukkan panjang element array: ";
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
	arr[y] = temp;
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
		while ((arr[j] > pivot) && (j >= low))      //Langkah Algoritma NO.7
		{
			j--;                                    //Langkah Algoritma NO.8
			cmp_count++;
		}
		cmp_count++;

		//If the greater element is on the left of the element 
		if (i < j)                                //Langkah Algoritma NO.9
		{
			//Swap the element is on the left of the element at index j
			swap(i, j);
			mov_count++;
		}
	}
	//J now containt the index of the last element in the sorted list 
	if (low < j);                               //Langkah Algoritma NO.11
	{
		//Move the pivot to its correct position in the list 
		swap(low, j);
		mov_count++;
	}
	//Sort the list on the left of pivot using quick sort
	q_short(low, j - 1);                   //Langkah Algoritma NO.12

	//Sort the list on the right of pivot using quick sort
	q_short(j + 1, high);                  //Langkah Algoritma NO.13

} 

void display() {
	cout << "\n---------------" << endl;
	cout << "Sorted Array" << endl;
	cout << "-----------------" << endl;
	
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
    }

	cout << "\n\nNumber of comparisions: " << cmp_count << endl;
	cout << "Number of data movements: " << mov_count << endl;
}

int main()
{
	input();
	q_short(0, n - 1);                       //Sort the array using quick sort
	display();
	system("pause");

	return 0;
}