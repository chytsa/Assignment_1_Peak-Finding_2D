#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int n = 20000;				// Map boundary
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
			if(map[row][column] < map[row-1][column] || map[row][column] < map[row][column+1])
				return 0;
			else
				return 1;
		}
		else{
			if(map[row][column] < map[row-1][column])
				return 0;
			else if(map[row][column] < map[row+1][column])
				return 0;
			else if(map[row][column] < map[row][column+1])
				return 0;
			else
				return 1;
		}
	}
	else if(column == n - 1){
		if(row == 0){
			if(map[row][column] < map[row+1][column] || map[row][column] < map[row][column-1])
				return 0;
			else
				return 1;
		}
		else if(row == n - 1){
			if(map[row][column] < map[row-1][column] || map[row][column] < map[row][column-1])
				return 0;
			else
				return 1;
		}
		else{
			if(map[row][column] < map[row-1][column])
				return 0;
			else if(map[row][column] < map[row+1][column])
				return 0;
			else if(map[row][column] < map[row][column-1])
				return 0;
			else
				return 1;
		}
	}
	else{
		if(row == 0){
			if(map[row][column] < map[row][column+1])
				return 0;
			else if(map[row][column] < map[row][column-1])
				return 0;
			else if(map[row][column] < map[row+1][column])
				return 0;
			else
				return 1;
		}
		else if(row == n - 1){
			if(map[row][column] < map[row][column+1])
				return 0;
			else if(map[row][column] < map[row][column-1])
				return 0;
			else if(map[row][column] < map[row-1][column])
				return 0;
			else
				return 1;
		}
		else{
			if(map[row][column] < map[row-1][column])
				return 0;
			else if(map[row][column] < map[row+1][column])
				return 0;
			else if(map[row][column] < map[row][column+1])
				return 0;
			else if(map[row][column] < map[row][column-1])
				return 0;
			else
				return 1;
		}
	}
	return 0;
}
void find_max(){
	for(int i = 0; i < n; i++){
		if(map[row][column] < map[row][i])
			column = i;
	}
}
void find(int *a, int *b){
	column = n/2;
	// Finding middle column peak
	int mid = 0;
	int i, j;
	do{
		i= n - 1, j = 0;
		while(i - j > 1){
			mid = (i + j)/2;
			if(map[mid][column] >= map[mid + 1][column])
				i = mid;
			else
				j = mid + 1;
		}
		row = map[i][column] > map[j][column] ? i : j;
		//cout << "A\n" << row + 1 << ", " << column + 1 << " = " << map[row][column] << endl;
		// Checking whether it's a peak
		if(check_peak())
			break;
		else{
			//cout << "B\n" << row + 1 << ", " << column + 1 << " = " << map[row][column] << endl;
			find_max();
			//cout << "C\n" << row + 1 << ", " << column + 1 << " = " << map[row][column] << endl;
			if(check_peak())
				break;
		}
	}while(1);
}

int main(){
//	cin >> n;						//  Input the size n
	map = new int*[n];				// Create space
	for(int i = 0; i < n; i++){
		map[i] = new int [n];
	}
	srand(time(NULL));
	//do{
	//cout << " |  1  2  3  4  5  6  7  8  9\n";
	//cout << "-+---------------------------\n";
	for(int i = 0; i < n; i++){		// Input the 2D array
		//cout << i + 1 << "| ";
		for(int j = 0; j < n; j++){
//			cin >> map[i][j];
			map[i][j] = rand() % 9999 + 1;
			//cout << map[i][j] << " ";
			//printf("%2d ", map[i][j]);
		}
		//cout << endl;
	}
	int *a = new int, *b = new int;	//  Recording x,y coordinate 
	// Processing
	find(a, b);
	cout << row + 1 << ", " << column + 1 << " = " << map[row][column] << endl;
	if((row > 0 && row < n - 1)&&(column > 0 && column < n - 1)){
		cout << map[row - 1][column] << ",";
		cout << map[row + 1][column] << ",";
		cout << map[row][column-1] << ",";
		cout << map[row][column+1] << "\n";
	}
	//system("pause");
	//}while(1);
	return 0;
}
