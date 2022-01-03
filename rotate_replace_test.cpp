#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int data[] = {2, 4, 3, 5, 7, 1, 8};

	replace (data, data+7, 1, 17);  // Find value and replace. If value not found, nothing will changed.

	rotate (data, data+3, data+7);

	replace (data, data+7, 4, 13);  // Find value and replace

	for (int i=0;i<7;i++){
		cout << data[i] << " ";
	}
	cout << endl;

	return 0;
}


// 5 7 17 8 2 13 3