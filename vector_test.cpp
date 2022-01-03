#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cout << "Enter the counts : ";
	int count, i, sum=0;
	cin >> count;

	vector<int> arr;  // Default size 
	arr.resize(count);  // Set resize

	for(i = 0; i < arr.size(); i++){
		arr[i] = i;
		sum += arr[i];
	}
	cout << "Final sum of vector array : " << sum << endl;
	return 0;
}