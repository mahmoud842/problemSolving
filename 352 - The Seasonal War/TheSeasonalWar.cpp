//============================================================================
// Name        : TheSeasonalWar.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n = 0;

vector<pair<int, int>> neighbour(int i, int j, vector<vector<char>> & image, vector<vector<bool>> & visited){
	vector<pair<int, int>> result;
	if (i > 0){
		if (j > 0 && image[i-1][j-1] == '1' && !visited[i-1][j-1]){
			pair<int, int> tmp(i-1, j-1);
			result.push_back(tmp);
		}
		if (image[i-1][j] == '1' && !visited[i-1][j]){
			pair<int, int> tmp(i-1, j);
			result.push_back(tmp);
		}
		if (j < n - 1 && image[i-1][j+1] == '1' && !visited[i-1][j+1]){
			pair<int, int> tmp(i-1, j+1);
			result.push_back(tmp);
		}
	}
	if (i < n - 1){
		if (j > 0 && image[i+1][j-1] == '1' && !visited[i+1][j-1]){
			pair<int, int> tmp(i+1, j-1);
			result.push_back(tmp);
		}
		if (image[i+1][j] == '1' && !visited[i+1][j]){
			pair<int, int> tmp(i+1, j);
			result.push_back(tmp);
		}
		if (j < n - 1 && image[i+1][j+1] == '1' && !visited[i+1][j+1]){
			pair<int, int> tmp(i+1, j+1);
			result.push_back(tmp);
		}
	}
	if (j > 0 && image[i][j-1] == '1' && !visited[i][j-1]){
		pair<int, int> tmp(i, j-1);
		result.push_back(tmp);
	}
	if (j < n - 1 && image[i][j+1] == '1' && !visited[i][j+1]){
		pair<int, int> tmp(i, j+1);
		result.push_back(tmp);
	}
	return result;
}

void DFS(int i, int j, vector<vector<char>> & image, vector<vector<bool>> & visited){
	visited[i][j] = 1;
	vector<pair<int, int>> neighbours = neighbour(i, j, image, visited);
	for (pair<int, int> & x : neighbours){
		if (!visited[x.first][x.second])
			DFS(x.first, x.second, image, visited);
	}
}

int main() {

	int num = 0;
	while (cin >> n){
		num++;
		vector<vector<char>> image(n, vector<char> (n));
		vector<vector<bool>> visited(n, vector<bool> (n, 0));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				char tmp;
				cin >> tmp;
				image[i][j] = tmp;
			}
		}

		int count = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (image[i][j] == '1' && !visited[i][j]){
					count++;
					DFS(i, j, image, visited);
				}
			}
		}

		// Image number 1 contains 3 war eagles.
		cout << "Image number " << num << " contains " << count << " war eagles." << endl;

	}

	return 0;
}
