#include <iostream>
using std::cin;
using std::cout;

void selectionSort(int arr[], int length)
{
  for (int i = 0; i < length - 1; i++)
  {
    // setting the current index of the first element in the list
    int min = i;

    // comparing the element with all the elements on the list and chanching the min value
    // if we find an element the is less that the element with the index of min
    for (int j = i + 1; j < length; j++)
    {
      // if we want descending order we change > to <
      if (arr[min] > arr[j])
        min = j;
    }

    // if min change meaning that that we found the less element that's why need to swap
    // positions
    if (min != i)
    {
      int temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
    }
  }
}
int main()
{
  int arr[5];
  cout << "Enter 5 Element To Populate The Array\n";
  for (int i = 0; i < 5; i++)
  {
    cout << "Enter The Element With The Index Of " << i << "\n";
    cin >> arr[i];
  }
  selectionSort(arr, 5);
  cout << "The Sorted List\n";
  for (int i = 0; i < 5; i++)
  {
    cout << "Index : " << i << " ===> "
         << "Element : " << arr[i] << "\n";
  }
  return 0;
}