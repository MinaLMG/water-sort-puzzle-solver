#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

void solve(vector<vector<string>>colors, vector<int>heights, vector<bool>dones, vector<string>& moves, int& min, int& size, unordered_map <string, bool>pathMap, unordered_map <string, pair<int, vector<string>>>& pathesMap, bool& found, const int& bottles, const int& height)
{
	/*if (moves.size() >= min)
		return;*/
	if (size < pathMap.size())//great optimization
		return;
	for (int i = 0; i < dones.size(); i++)
	{
		if (dones[i] == 0)
			break;
		if (i == dones.size() - 1) {
			/*if (moves.size() < min) {*/
				//finalMoves = moves;	
			found = 1;
			min = 0;/*moves.size();*/
			size = pathMap.size();
			return;
			//}

		}
	}
	/*if (found)
		return;*/
	int minChoice = INT_MAX;
	int min_temp = INT_MAX;//declared here to be modified and used 
	//vector<string>minMoves;
	for (int i = 0; i < colors.size(); i++)
		for (int j = 0; j < colors.size(); j++)
			if (i != j)
				if (heights[j] < height && heights[i]>0 && heights[j] > 0 && colors[i][heights[i] - 1] == colors[j][heights[j] - 1])
				{
					/*string comparator = " " + std::to_string(j) + "_" + std::to_string(i);
					if (moves.size() && comparator == moves[moves.size() - 1])
						continue;
					*/
					string x = " " + std::to_string(i) + "_" + std::to_string(j);
					if (x == " 2_3")
						x = " 2_3";
					if (x == " 0_2")
						x = " 0_2";
					if (x == " 1_0")
						x = " 1_0";
					if (x == " 1_2")
						x = " 1_2";
					if (x == " 0_1")
						x = " 0_1";

					vector<string>moves_temp;// = moves;
					moves_temp.push_back(x);
					vector<vector<string>>colors_temp = colors;
					colors_temp[j][heights[j]] = colors_temp[i][heights[i] - 1];
					colors_temp[i][heights[i] - 1] = "z";
					string mapper = "";
					for (int m1 = 0; m1 < bottles; m1++)
						for (int m2 = 0; m2 < height; m2++)
							mapper += colors_temp[m1][m2];
					if (pathMap.find(mapper) != pathMap.end())
						continue;
					unordered_map<string, bool>pathMap_temp = pathMap;
					pathMap_temp.insert({ mapper,1 });
					vector<int>heights_temp = heights;
					heights_temp[i]--;
					heights_temp[j]++;
					vector<bool>dones_temp = dones;
					bool done = true;
					for (int l = 0; l < height; l++) {
						if (l != 0 && colors_temp[i][l] != colors_temp[i][l - 1])
						{
							done = false;
							break;
						}
					}
					dones_temp[i] = done;

					done = true;
					for (int l = 0; l < height; l++) {
						if (l != 0 && colors_temp[j][l] != colors_temp[j][l - 1])
						{
							done = false;
							break;
						}
					}
					dones_temp[j] = done;
					vector<string>movesTofind;
					bool found_temp = 0;
					if (pathesMap.find(mapper) != pathesMap.end()) {
						found = true;
						int	minChoice_temp = pathesMap[mapper].first;
						if (minChoice_temp < minChoice) {
							minChoice = minChoice_temp;
							moves = moves_temp;
							movesTofind = pathesMap[mapper].second;
							moves.insert(moves.end(), movesTofind.begin(), movesTofind.end());
						}
					}
					else {
						solve(colors_temp, heights_temp, dones_temp, movesTofind, min_temp, size, pathMap_temp, pathesMap, found_temp, bottles, height);
						if (found_temp) {
							pair<int, vector<string>>p;
							p.first = min_temp;
							p.second = movesTofind;
							pathesMap.insert({ mapper ,p });
						}
						if (min_temp < minChoice && found_temp) {
							found = true;
							minChoice = min_temp;
							moves = moves_temp;
							moves.insert(moves.end(), movesTofind.begin(), movesTofind.end());
						}
					}
				}
	for (int i = 0; i < bottles; i++)
	{
		if (heights[i] == 0) {
			for (int j = 0; j < bottles; j++) {
				if (dones[j] == 0 && heights[j] != 0) {
					/*string comparator = " " + std::to_string(i) + "_" + std::to_string(j);
					if (moves.size()&&comparator == moves[moves.size() - 1])
						continue;*/
					if (heights[j] == 1) {
						continue;
					}
					bool unuseful = true;
					for (int h = 1; h < heights[j]; h++) {
						if (colors[j][h] != colors[j][h - 1])
							unuseful = false;
					}
					if (unuseful) {
						continue;
					}
					string x = " " + std::to_string(j) + "_" + std::to_string(i);
					if (x == " 2_3" && pathMap.size() == 1)
						x = " 2_3";
					if (x == " 0_2")
						x = " 0_2";
					if (x == " 1_0")
						x = " 1_0";
					if (x == " 1_2")
						x = " 1_2";
					if (x == " 0_1")
						x = " 0_1";

					vector<string>moves_temp;// = moves;
					moves_temp.push_back(x);
					vector<vector<string>>colors_temp = colors;
					colors_temp[i][heights[i]] = colors_temp[j][heights[j] - 1];
					colors_temp[j][heights[j] - 1] = "z";
					string mapper = "";
					for (int m1 = 0; m1 < bottles; m1++)
						for (int m2 = 0; m2 < height; m2++)
							mapper += colors_temp[m1][m2];
					if (pathMap.find(mapper) != pathMap.end())
						continue;
					unordered_map<string, bool>pathMap_temp = pathMap;
					pathMap_temp.insert({ mapper,1 });
					vector<int>heights_temp = heights;
					heights_temp[j]--;
					heights_temp[i]++;
					vector<bool>dones_temp = dones;
					bool done = true;
					for (int l = 0; l < height; l++) {
						if (l != 0 && colors_temp[j][l] != colors_temp[j][l - 1]) {
							done = false;
							break;
						}
					}
					dones_temp[j] = done;
					int min_temp = INT_MAX;
					vector<string>movesTofind;
					bool found_temp = 0;
					if (pathesMap.find(mapper) != pathesMap.end()) {
						found = true;
						int	minChoice_temp = pathesMap[mapper].first;
						if (minChoice_temp < minChoice) {
							minChoice = minChoice_temp;
							moves = moves_temp;
							movesTofind = pathesMap[mapper].second;
							moves.insert(moves.end(), movesTofind.begin(), movesTofind.end());
						}
					}
					else {
						solve(colors_temp, heights_temp, dones_temp, movesTofind, min_temp, size, pathMap_temp, pathesMap, found_temp, bottles, height);
						if (found_temp) {
							pair<int, vector<string>>p;
							p.first = min_temp;
							p.second = movesTofind;
							pathesMap.insert({ mapper ,p });
						}
						if (min_temp < minChoice && found_temp) {
							found = true;
							minChoice = min_temp;
							moves = moves_temp;
							moves.insert(moves.end(), movesTofind.begin(), movesTofind.end());
						}
					}
				}
			}
		}
	}
	min = minChoice + 1;
}
int main() {
	int bottles, height;
	cin >> bottles;
	cin >> height;
	vector<vector<string>>colors(bottles, vector<string>(height, "z"));
	vector<int>heights(bottles, 0);
	vector<bool>dones(bottles, 0);
	string mapper = "";
	for (int i = 0; i < bottles; i++) {
		bool done = true;
		for (int j = 0; j < height; j++) {
			cin >> colors[i][j];
			mapper += colors[i][j];
			if (colors[i][j] != "z")
				heights[i]++;
			/*if (j == 0)
				if (colors[i][j] == -1)
					done = false;*/
			if (j != 0 && colors[i][j] != colors[i][j - 1])
				done = false;
		}
		dones[i] = done;
	}
	vector<string>moves;// finalMoves;
	bool found = 0;
	unordered_map <string, bool>m;
	unordered_map <string, pair<int, vector<string>>>pathes_map;
	m.insert({ mapper, 1 });
	int min = INT_MAX;
	int size = INT_MAX;
	solve(colors, heights, dones, moves, min, size, m, pathes_map, found, bottles, height);
	for (int i = 0; i < moves.size(); i++)
		cout << moves[i] << endl;
	return 0;
}