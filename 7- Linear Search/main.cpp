#include <iostream>
using std::cin;
using std::cout;

void linearSearch(int arr[], int length, int element)
{
  int temp = -1;
  for (int i = 0; i < length; i++)
  {
    if (arr[i] == element)
    {
      cout << "Element " << element << " Found At Index : " << i << "\n";
      temp = 0;
    }
  }
  if (temp == -1)
  {
    cout << "No Element Found\n";
  }
}
int main()
{
  int element;
  int arr[5];
  cout << "Linear Search Implementation Using Arrays\n";
  cout << "-----------------------------------------\n";
  cout << "Please 5 Elements Of The Arrays :\n";
  for (int i = 0; i < 5; i++)
  {
    cout << "Enter Element At Index " << i << ": ";
    cin >> element;
    arr[i] = element;
  }
  cout << "-----------------------------------------\n";
  cout << "Please Enter An Element To Search For\n";
  cin >> element;
  linearSearch(arr, sizeof(arr) / sizeof(int), element);
  return 0;
}