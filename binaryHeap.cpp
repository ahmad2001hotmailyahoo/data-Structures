#include<iostream>
#include<math.h>
using namespace std ;
 
//int largest = 0 ;

int largest = 0;
void heapify(int arr[], int size, int i)
{
	int Left = 2 * i + 1;
	int Right = 2 *i + 2;

	
	if (Left < size && arr[Left] < arr[i]) largest = Left;
	else largest = i;
	if (Right < size && arr[Right] < arr[largest]) largest = Right;

	if (largest != i)
	{
		swap(arr[largest], arr[i]);
		heapify(arr, size, largest);
	}
}

void heapSort(int arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

int main()
{
    int arr[10]={2,0,1,4,3,7,6,8,5,9};
    //for(int i = 0 ; i < 10 ; i++)
    //{
      //  cout << "Enter the " << i+1 << " element " << endl ;
      // cin  >> arr[i] ;
    //}

    heapSort(arr,10) ;

    for(int i = 0 ; i < 10 ; i++)
    {
        cout << arr[i] << " , " ;
    }

    return 0 ;

}