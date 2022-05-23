#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>

int wide_search(std::vector<std::vector<bool>> M, int point) {
	std::queue<int> Q;
	std::vector<bool> labelled;
	std::vector<int> labelled_;
	labelled.resize(M.size());
	int n = M.size();

	int current = 0;
	Q.push(current);


	while (!labelled[point]){
		current = Q.front();
		Q.pop();
		labelled[current] = 1;
		labelled_.push_back(current);
		for (int i = 0; i < n; i++)
			if (M[current][i] && !labelled[i]) {
				Q.push(i);
			}
		

	}
	for (int i = 0; i < labelled_.size(); i++)
		std::cout << labelled_[i] << ", ";


	return n;
}

std::vector<std::vector<bool>> input(int n) {
	std::vector<std::vector<bool>> M;
	M.resize(n);
	for (int i = 0; i < n; i++)
		M[i].resize(n);
	std::srand(std::time(0));
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
			if (std::rand() > (RAND_MAX / 2)) {
				M[i][j] = 1; M[j][i] = 1;
			}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << M[i][j] << "  ";
		}
		std::cout << std::endl;
	}

	return M;
}

int main() {
	int n;
	int point;
	std::cin >> n >> point;
	wide_search(input(n), point);


	return 0;
}