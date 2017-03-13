#include<iostream>
using namespace std;
int main(){
	int n;							//  Input the size n
	cin >> n;
	int **map;						// Creat space
	map = new int*[n];
	for(int i = 0; i < n; i++){
		map[i] = new int [n];
	}
	for(int i = 0; i < n; i++){		// Input the 2D array
		for(int j = 0; j < n; j++){
			cin >> map[i][j];
		}
	}
	
	return 0;
}
