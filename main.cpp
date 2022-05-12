#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int find_max(vector<vector<int>> vec) {
	int max = -1;
	for (size_t i = 0; i < vec.size(); i++) {
		if (vec[i][0] > max) {
			max = vec[i][0];
		}
		if (vec[i][1] > max) {
			max = vec[i][1];
		}
	}
	return max;
}

void recolor(vector<int>& colors, int color1, int color2) {
	for (size_t i = 0; i < colors.size(); i++) {
		if (colors[i] == color2) {
			colors[i] = color1;
		}
	}
}

int main() {

	vector<vector<int>> edges;
	vector<vector<int>> res;

	edges = { { 3, 1, 4 }, { 2, 1, 3 }, { 2, 4, 10 }, { 5, 3, 4 }, { 4, 3, 7 }, { 4, 5, 2 }, { 5, 5, 5 } };
	// вершина, вершина, вес

	int n = find_max(edges);

	vector<int> colors;

	for (int i = 0; i < n; i++) {
		colors.push_back(i);
	}

	sort(edges.begin(), edges.end(), [](vector<int> first, vector<int> second) {
		return first[2] < second[2];
	});

	for (size_t i = 0; i < edges.size(); i++) {
		if (colors[edges[i][0] - 1] != colors[edges[i][1] - 1]) {
			recolor(colors, colors[edges[i][0] - 1], colors[edges[i][1] - 1]);
			res.push_back(edges[i]);
		}
	}

	for (size_t i = 0; i < res.size(); i++) {
		cout << "Edge #" << i + 1 << ": from " << res[i][0] << " to " << res[i][1] << ", weight = " << res[i][2];
		cout << endl;
	}

	return 0;
}