#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <utility>
#include <unordered_map>
#include <map>


using namespace std;

vector<pair<int, int>> vector_fromTwoSets(set<pair<int, int>> set1, set<pair<int, int>> set2);
unordered_map<int,int> mergeFrequency(unordered_map<int, int> map1, unordered_map<int,int> map2);
void printFrequency(unordered_map<int, int> frequencies);
unordered_map<int,int> calcFrequencies(vector<int> X);
pair<int, set<int>> findModeX(vector<int> X);
void printModeX(pair<int, set<int>> modeX);

int main() {

    vector<int> X = {1, 2, 3, 4, 5, 2, 3, 4, 1, 5,
                            6, 7, 8, 9, 7, 8, 9, 6, 10, 10,
                            11, 12, 13, 11, 12, 13, 14, 15, 14, 15,
                            16, 17, 18, 19, 17, 18, 19, 16, 20, 20,
                            21, 22, 23, 3, 22, 23, 24, 21, 25, 25,
                            26, 27, 5, 29, 4, 28, 29, 26, 30, 30,
                            31, 32, 2, 34, 32, 33, 34, 31, 35, 35,
                            36, 37, 4, 39, 37, 38, 39, 36, 40, 40,
                            41, 3, 43, 44, 42, 43, 44, 41, 45, 45,
                            5, 47, 48, 49, 47, 48, 49, 46, 50, 50};
    pair<int, set<int>> mode = findModeX(X);
    printModeX(mode);

    return 0;
}


pair<int, set<int>> findModeX(vector<int> X) {

    unordered_map<int,int> frequencies = calcFrequencies(X);

    pair<int, set<int>> mode;
    int maxFrequency = 0;

    for(const auto& pair : frequencies) {
        if (pair.second > maxFrequency) {
            mode.second.clear();
            maxFrequency = pair.second;
            mode.first = maxFrequency;
            mode.second.insert(pair.first);
        }

        else if (pair.second == maxFrequency) {
            mode.second.insert(pair.first);
        }
    }

    return mode;
}

unordered_map<int,int> calcFrequencies(vector<int> X) {

    if (X.size() == 1) {  // 1 OE
        unordered_map<int,int> par; // 1 OE
        par[X[0]] = 1; // 1 OE
        return par; // 1 OE
    }

    int middle = X.size() / 2; // 2 OE

    vector<int> X1(X.begin(), X.begin() + middle); // N/2 OE
    vector<int> X2(X.begin() + middle, X.end()); // N/2 OE

    unordered_map<int,int> map1 = calcFrequencies(X1); // T(N/2)
    unordered_map<int,int> map2 = calcFrequencies(X2); // T(N/2)
    unordered_map<int,int> map = mergeFrequency(map1, map2); // N OE

    return map;
}


unordered_map<int,int> mergeFrequency(unordered_map<int, int> map1, unordered_map<int,int> map2) {

    for(const auto& pair : map2){
        if (map1.find(pair.first) != map1.end()) {
            map1[pair.first] = map1[pair.first] + pair.second;
        }
        else {
            map1[pair.first] = pair.second;
        }
    }
    return map1;
}

vector<pair<int, int>> vector_fromTwoSets(set<pair<int, int>> set1, set<pair<int, int>> set2) {

    vector<pair<int, int>> vec;

    for (const auto& pair: set1)
        vec.push_back(pair);

    for (const auto& pair: set2)
        vec.push_back(pair);

    return vec;
}

void printFrequency(unordered_map<int, int> frequencies) {

    for(const auto& pair : frequencies) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

void printModeX(pair<int, set<int>> modeX) {

    if (modeX.first <= 1) {
        cout << "No existe moda" << endl;
        return ;
    } 

    if (modeX.first > 1) {
        
        if (modeX.second.size() == 1) {
            cout << "La moda de frecuencia " << modeX.first << " es ";
        }

        else {
           cout << "Las modas de frecuencia " << modeX.first << " son "; 
        }

        for(const auto& element : modeX.second) {
            cout << element << " ";
        }
    }
}





