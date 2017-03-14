#include<iostream>
#include<stdlib.h>
using namespace std;
int n = 9;					// Map boundary
int  **map;					// Map address
int column = 0, row = 0;	// Temp Peak coordinate
int check_peak(){
	if(column == 0){
		if(row == 0){
			if(map[row][column] < map[row+1][column] || map[row][column] < map[row][column+1])
				return 0;
			else
				return 1;
		}
		else if(row == n - 1){
			
		}
		else{
			
		}
	}
	else if(column == n - 1){
		
	}
	else{
		
	}
}
int find(int *a, int *b){
	column = n/2;
	// Finding middle column peak
	int mid = 0;
	int i = n - 1, j = 0;
	while(i - j > 1){
		mid = (i + j)/2;
		if(map[mid][column] >= map[mid + 1][column])
			i = mid;
		else
			j = mid + 1;
	}
	row = map[i][column] > map[j][column] ? i : j;
	// Checking whether it's a peak
	check_peak();
	
	return 1;
}

int main(){
//	cin >> n;						//  Input the size n
	map = new int*[n];				// Create space
	for(int i = 0; i < n; i++){
		map[i] = new int [n];
	}
	for(int i = 0; i < n; i++){		// Input the 2D array
		for(int j = 0; j < n; j++){
//			cin >> map[i][j];
			map[i][j] = rand() % 9 + 1;
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	int *a = new int, *b = new int;	//  Recording x,y coordinate 
	// Processing
	find(a, b);
	cout << row + 1 << ", " << column + 1 << " = " << map[row][column] << endl;
	return 0;
}
