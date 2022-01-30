#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include <algorithm>
using namespace std;
/*int counter1 = 0;
int counter2 = 0;
int counter3 = 0;
int counter4 = 0;
int counter5 = 0;
int counter6 = 0;
int counter7 = 0;
int counter8 = 0;
int counter9 = 0;
int counter10 = 0;
int counter11 = 0;
int counter12 = 0;
int counter13 = 0;
int counter14 = 0;
int counter15 = 0;
int counter16 = 0;
int counter17 = 0;
int counter18 = 0;
int counter19 = 0;
int counter20 = 0;
int counter21 = 0;
int counter22 = 0;
int counter23 = 0;
int counter24 = 0;
int counter25 = 0;
int counter26 = 0;
int counter27 = 0;
int counter28 = 0;*/

void solve(vector<vector<string>>colors, vector<int>heights, vector<bool>dones, vector<int>empties, vector<int>goesToempty, vector<pair<string, vector<int>>> heads, unordered_map<string, int>& heads_indices, vector<int>goesToHeads, vector<string>& moves, int& min, int& size, unordered_map <string, bool>pathMap, unordered_map <string, pair<int, vector<string>>>& pathesMap, bool& found, const int& bottles, const int& height)
{
	//counter1++;
	/*if (moves.size() >= min)
		return;*/
	if (size <= pathMap.size())//great optimization{
	{
		//counter6++;
		return;
	}
	for (int i = 0; i < dones.size(); i++)
	{
		//counter7++;
		if (dones[i] == 0)
		{
			//counter8++;
			break;
		}
		if (i == dones.size() - 1) {
			//counter25++;
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
	//counter9++;

	int minChoice = INT_MAX;
	//int min_temp = INT_MAX;//declared here to be modified and used 
	//vector<string>minMoves;
	for (int iterator1 = 0; iterator1 < goesToHeads.size(); iterator1++)
	{
		//counter28++;
		//if (heads[goesToHeads[iterator1]].second.size() > 1) {
		//counter2++;
		for (int iterator2 = 0; iterator2 < heads[goesToHeads[iterator1]].second.size(); iterator2++)
		{
			int i = heads[goesToHeads[iterator1]].second[iterator2];
			for (int iterator3 = 0; iterator3 < heads[goesToHeads[iterator1]].second.size(); iterator3++) {
				//counter3++;
				int j = heads[goesToHeads[iterator1]].second[iterator3];
				if (i != j) {
					//counter4++;
					if (heights[j] < height)//&& heights[i]>0 && heights[j] > 0 && colors[i][heights[i] - 1] == colors[j][heights[j] - 1])
					{
						//counter5++;
						/*string comparator = " " + std::to_string(j) + "_" + std::to_string(i);
						if (moves.size() && comparator == moves[moves.size() - 1])
							continue;
						*/
						vector<vector<string>>colors_temp = colors;
						colors_temp[j][heights[j]] = colors_temp[i][heights[i] - 1];
						string toReomeveHead = colors_temp[i][heights[i] - 1];
						colors_temp[i][heights[i] - 1] = "z";
						string mapper = "";
						for (int m1 = 0; m1 < bottles; m1++)
							for (int m2 = 0; m2 < height; m2++)
								mapper += colors_temp[m1][m2];
						if (pathMap.find(mapper) != pathMap.end())
						{
							//counter10++;
							continue;
						}
						vector<string>moves_temp;// = moves;
						string x = " " + std::to_string(i) + "_" + std::to_string(j);
						moves_temp.push_back(x);
						vector<string>movesTofind;
						if (pathesMap.find(mapper) != pathesMap.end()) {
							//counter11++;
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
							//counter12++;
							unordered_map<string, bool>pathMap_temp = pathMap;
							pathMap_temp.insert({ mapper,1 });
							vector<int>heights_temp = heights;
							vector<int>empties_temp = empties;
							vector<int>goesToempty_temp = goesToempty;
							vector<bool>dones_temp = dones;
							vector<pair<string, vector<int> >> heads_temp = heads;
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
							heights_temp[i]--;
							if (heights_temp[i] == 0)
								empties_temp.push_back(i);
							heights_temp[j]++;
							if (heights_temp[j] == 1)
								empties_temp.erase(std::remove(empties_temp.begin(), empties_temp.end(), j), empties_temp.end());
							/*calculating goes to empty*/
							if (heights_temp[j] == 2) {
								goesToempty_temp.push_back(j);
							}
							if (heights_temp[i] == 1) {
								goesToempty_temp.erase(std::remove(goesToempty_temp.begin(), goesToempty_temp.end(), i), goesToempty_temp.end());
							}
							if (dones_temp[j] == 1) {
								goesToempty_temp.erase(std::remove(goesToempty_temp.begin(), goesToempty_temp.end(), j), goesToempty_temp.end());
							}
							//***
							/*calcualting heads and heads indices*/
							vector<int>temp_vector = heads_temp[heads_indices[toReomeveHead]].second;
							temp_vector.erase(std::remove(temp_vector.begin(), temp_vector.end(), i), temp_vector.end());
							heads_temp[heads_indices[toReomeveHead]].second = temp_vector;
							if (heights_temp[i] != 0) {
								string head = colors_temp[i][heights_temp[i] - 1];
								vector<int>temp_vector = heads_temp[heads_indices[head]].second;
								temp_vector.push_back(i);
								heads_temp[heads_indices[head]].second = temp_vector;
							}
							//
							/*calculating goes To heads temp*/
							vector<int> goesToHeads_temp;
							for (int i = 0; i < heads_temp.size(); i++) {
								if (heads_temp[i].second.size() > 1) {
									goesToHeads_temp.push_back(i);
								}
							}
							//
							bool found_temp = 0;
							int min_temp = INT_MAX;
							solve(colors_temp, heights_temp, dones_temp, empties_temp, goesToempty_temp, heads_temp, heads_indices, goesToHeads_temp, movesTofind, min_temp, size, pathMap_temp, pathesMap, found_temp, bottles, height);
							if (found_temp) {
								//counter13++;
								pair<int, vector<string>>p;
								p.first = min_temp;
								p.second = movesTofind;
								pathesMap.insert({ mapper ,p });
							}
							if (min_temp < minChoice && found_temp) {
								//counter14++;
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
		//}
	}
	for (int iterator = 0; iterator < empties.size(); iterator++)
	{
		//counter15++;
		int i = empties[iterator];
		//if (heights[i] == 0) {
		//counter16++;
		for (int iterator2 = 0; iterator2 < goesToempty.size(); iterator2++) {
			//counter26++;
			int j = goesToempty[iterator2];
			//if (dones[j] == 0 && heights[j] != 0) {
				/*string comparator = " " + std::to_string(i) + "_" + std::to_string(j);
				if (moves.size()&&comparator == moves[moves.size() - 1])
					continue;*/
			/*counter27++;
			if (counter27 != counter26) {
				counter1 = counter1;
			}*/
			if (heights[j] == 1) {
				//counter17++;
				continue;
			}
			bool unuseful = true;
			for (int h = 1; h < heights[j]; h++) {
				if (colors[j][h] != colors[j][h - 1])
					unuseful = false;
			}
			if (unuseful) {
				//counter18++;
				continue;
			}
			vector<vector<string>>colors_temp = colors;
			colors_temp[i][heights[i]] = colors_temp[j][heights[j] - 1];
			string toReomeveHead = colors_temp[j][heights[j] - 1];
			colors_temp[j][heights[j] - 1] = "z";
			string mapper = "";
			for (int m1 = 0; m1 < bottles; m1++)
				for (int m2 = 0; m2 < height; m2++)
					mapper += colors_temp[m1][m2];
			if (pathMap.find(mapper) != pathMap.end()) {
				//counter19++;
				continue;
			}
			vector<string>moves_temp;// = moves;
			string x = " " + std::to_string(j) + "_" + std::to_string(i);
			moves_temp.push_back(x);
			vector<string>movesTofind;
			if (pathesMap.find(mapper) != pathesMap.end()) {
				//counter20++;
				found = true;
				int	minChoice_temp = pathesMap[mapper].first;
				if (minChoice_temp < minChoice) {
					//counter21++;
					minChoice = minChoice_temp;
					moves = moves_temp;
					movesTofind = pathesMap[mapper].second;
					moves.insert(moves.end(), movesTofind.begin(), movesTofind.end());
				}
			}
			else {
				//counter22++;
				unordered_map<string, bool>pathMap_temp = pathMap;
				pathMap_temp.insert({ mapper,1 });
				vector<int>heights_temp = heights;
				vector<int>empties_temp = empties;
				vector<int>goesToempty_temp = goesToempty;
				vector<bool>dones_temp = dones;
				vector<pair<string, vector<int> >> heads_temp = heads;
				bool done = true;
				for (int l = 0; l < height; l++) {
					if (l != 0 && colors_temp[j][l] != colors_temp[j][l - 1]) {
						done = false;
						break;
					}
				}
				dones_temp[j] = done;
				//#TODO more suitable implementation
				heights_temp[j]--;
				if (heights_temp[j] == 0)
					empties_temp.push_back(j);
				heights_temp[i]++;
				if (heights_temp[i] == 1)
					empties_temp.erase(std::remove(empties_temp.begin(), empties_temp.end(), i), empties_temp.end());
				/*calculating goes to empty*/
				if (heights_temp[i] == 2) {
					goesToempty_temp.push_back(i);
				}
				if (heights_temp[j] == 1) {
					goesToempty_temp.erase(std::remove(goesToempty_temp.begin(), goesToempty_temp.end(), j), goesToempty_temp.end());
				}
				if (dones_temp[i] == 1) {
					goesToempty_temp.erase(std::remove(goesToempty_temp.begin(), goesToempty_temp.end(), i), goesToempty_temp.end());
				}
				/*calcualting heads and heads indices*/
				vector<int>temp_vector = heads_temp[heads_indices[toReomeveHead]].second;
				temp_vector.erase(std::remove(temp_vector.begin(), temp_vector.end(), j), temp_vector.end());
				temp_vector.push_back(i); //adding the i to the heads
				heads_temp[heads_indices[toReomeveHead]].second = temp_vector;
				if (heights_temp[j] != 0) {
					string head = colors_temp[j][heights_temp[j] - 1];
					vector<int>temp_vector = heads_temp[heads_indices[head]].second;
					temp_vector.push_back(j);
					heads_temp[heads_indices[head]].second = temp_vector;
				}
				//
				/*calculating goes To heads temp*/
				vector<int> goesToHeads_temp;
				for (int i = 0; i < heads_temp.size(); i++) {
					if (heads_temp[i].second.size() > 1) {
						goesToHeads_temp.push_back(i);
					}
				}
				//
				int min_temp = INT_MAX;
				bool found_temp = 0;
				solve(colors_temp, heights_temp, dones_temp, empties_temp, goesToempty_temp, heads_temp, heads_indices, goesToHeads_temp, movesTofind, min_temp, size, pathMap_temp, pathesMap, found_temp, bottles, height);
				if (found_temp) {
					//counter23++;
					pair<int, vector<string>>p;
					p.first = min_temp;
					p.second = movesTofind;
					pathesMap.insert({ mapper ,p });
				}
				if (min_temp < minChoice && found_temp) {
					//counter24++;
					found = true;
					minChoice = min_temp;
					moves = moves_temp;
					moves.insert(moves.end(), movesTofind.begin(), movesTofind.end());
				}
			}
			//}
		}
		//}
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
	vector<int>empties;
	vector<int>goesToempty;
	vector<int>goesToHeads;
	vector<pair<string, vector<int>>> heads;
	unordered_map<string, int>heads_indices;
	string mapper = "";
	for (int i = 0; i < bottles; i++) {
		bool done = true;
		for (int j = 0; j < height; j++) {
			cin >> colors[i][j];
			if (colors[i][j] != "z" && heads_indices.find(colors[i][j]) == heads_indices.end()) {
				vector<int> x;
				heads.push_back({ colors[i][j],x });
				heads_indices.insert({ colors[i][j],heads.size() - 1 });
			}
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
		/*if (done && colors[i][0] == "z") {
			empties.push_back(i);
		}*/
		if (heights[i] == 0) {
			empties.push_back(i);
		}
		else if (!done) {
			goesToempty.push_back(i);
		}
		if (heights[i]) {
			string head = colors[i][heights[i] - 1];
			heads[heads_indices[head]].second.push_back(i);
		}
	}
	for (int i = 0; i < heads.size(); i++) {
		if (heads[i].second.size() > 1) {
			goesToHeads.push_back(i);
		}
	}
	vector<string>moves;// finalMoves;
	bool found = 0;
	unordered_map <string, bool>m;
	unordered_map <string, pair<int, vector<string>>>pathes_map;
	m.insert({ mapper, 1 });
	int min = INT_MAX;
	int size = INT_MAX;
	solve(colors, heights, dones, empties, goesToempty, heads, heads_indices, goesToHeads, moves, min, size, m, pathes_map, found, bottles, height);
	for (int i = 0; i < moves.size(); i++)
		cout << moves[i] << endl;
	return 0;
}