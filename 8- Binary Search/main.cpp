#include <iostream>
using std::cin;
using std::cout;

void binarySearch(int arr[], int right, int left, int element)
{
  int temp = -1;
  int index;
  int iterations = 0;
  // when left is bigger thean right this means that the array has been searched entirely
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (arr[mid] == element)
    {
      index = mid;
      temp = 0;
      break;
    }
    else if (arr[mid] < element)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
    iterations++;
  }

  if (temp == -1)
  {
    cout << "Element Not Found\n";
    cout << "Number Of Iterations : " << iterations << "\n";
  }
  else
  {
    cout << "Element " << arr[index] << " Found At Index " << index << "\n";
    cout << "Number Of Iterations : " << iterations << "\n";
  }
}
int main()
{
  int element, right, left;
  int arr[6] = {3, 7, 10, 14, 20, 23};
  left = 0;
  right = 5;
  cout << "Enter The Element You Want To Look For\n";
  cin >> element;
  binarySearch(arr, right, left, element);
  return 0;
}