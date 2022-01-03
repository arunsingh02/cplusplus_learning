#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int i, int j){
	return (i < j);
}

int main(){
	int data[] = {7, 4, 6, 3, 8, 1};
	sort(data, data+6, compare);

	for (int i=0; i < 6; i++){
		cout << data[i] << " ";
	}
	cout << endl;
	return 0;
}

// 1, 3, 4, 6, 7, 8