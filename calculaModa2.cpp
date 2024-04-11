#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <utility>
#include <unordered_map>
#include <map>

using namespace std;

pair<pair<int, set<int>>, unordered_map<int, int>> findModeX(vector<int> X);
pair<pair<int, set<int>>, unordered_map<int, int>> mergeModes(pair<pair<int, set<int>>, unordered_map<int, int>> pair1,
                                                              pair<pair<int, set<int>>, unordered_map<int, int>> pair2);
void printNewMode(pair<pair<int, set<int>>, unordered_map<int, int>> par);

int main()
{

    vector<int> X = {6, 3, 13, 5, 18, 16, 17, 16, 13, 13, 17, 18, 6, 15, 8, 12, 20, 4, 20, 12,
                     1, 20, 11, 16, 2, 17, 18, 17, 17, 8, 10, 11, 18, 16, 3, 4, 15, 14, 12,
                     8, 10, 11, 4, 11, 1, 11, 11, 17, 16, 18, 2, 18, 18, 7, 18, 8, 12, 4, 6,
                     6, 8, 4, 12, 6, 20, 11, 9, 7, 9, 11, 19, 3, 7, 8, 13, 11, 6, 20, 20, 11,
                     4, 5, 18, 14, 3, 6, 15, 7, 7, 13, 10, 15, 15, 9, 3, 14, 5, 7, 10, 16, 8,
                     17, 7, 7, 17, 18, 4, 13, 19, 5, 7, 11, 5, 17, 19, 10, 17, 20, 17, 7, 15,
                     20, 4, 8, 2, 8, 15, 17, 8, 10, 13, 20, 11, 16, 17, 5, 9, 8, 7, 11, 20, 19,
                     8, 5, 20, 15, 16, 13, 19, 13, 10, 8, 10, 7, 6, 19, 1, 18, 8, 8, 16, 9, 18,
                     20, 13, 5, 15, 13, 5, 16, 19, 6, 19, 6, 3, 4, 16, 9, 8, 14, 17, 16, 18, 11,
                     1, 18, 8, 18, 15, 17, 8, 5, 4, 10, 6, 14, 20, 7, 1, 4};
    pair<pair<int, set<int>>, unordered_map<int, int>> mode = findModeX(X);
    printNewMode(mode);

    return 0;
}

pair<pair<int, set<int>>, unordered_map<int, int>> findModeX(vector<int> X)
{

    if (X.size() == 1) // 1 OE
    { 

        pair<pair<int, set<int>>, unordered_map<int, int>> mode; // 1 OE

        pair<int, set<int>> par;  // 1OE
        par.first = 1;  // 1 OE
        par.second = {X[0]};  // 1 OE

        unordered_map<int, int> freq = {{X[0], 1}};  // 1 OE
        mode.first = par; // 1 OE
        mode.second = freq; // 1 OE

        return mode; // 1 OE
    }  // 9 OE

    int middle = X.size() / 2; // 2 OE

    vector<int> X1(X.begin(), X.begin() + middle); // N/2 OE
    vector<int> X2(X.begin() + middle, X.end());   // N/2 OE

    pair<pair<int, set<int>>, unordered_map<int, int>> par1 = findModeX(X1);           // T(N/2)
    pair<pair<int, set<int>>, unordered_map<int, int>> par2 = findModeX(X2);           // T(N/2)
    pair<pair<int, set<int>>, unordered_map<int, int>> modeX = mergeModes(par1, par2); // 11N + 10

    return modeX;
}

pair<pair<int, set<int>>, unordered_map<int, int>> mergeModes(pair<pair<int, set<int>>, unordered_map<int, int>> pair1,
                                                              pair<pair<int, set<int>>, unordered_map<int, int>> pair2)
{

    // MAP1 TIENE N1 ELEMENTOS
    // MAP2 TIENE N2 ELEMENTOS
    // MAP1 Y  MAP2 TIENE K CLAVES IGUALES

    unordered_map<int, int> map1 = pair1.second; // 1 OE
    unordered_map<int, int> map2 = pair2.second; // 1 OE


    for (const auto &pair : map2) // N2 OE
    {
        if (map1.find(pair.first) != map1.end()) // 1 OE
        {
            map1[pair.first] = map1[pair.first] + pair.second; // 2 OE
        }
        else
        {
            map1[pair.first] = pair.second; // 1OE
        }
    }

    // SI K = 0, 1 + N2(3 + 2) + 1 OE = 5N2 + 2 OE  (PEOR CASO)
    // SI K = N2, 1 + N2(3) + 1 OE = 3N2 + 2 OE     (MEJOR CASO)
    


    // AHORA MAP1 TIENE N1 + N2 - K ELEMENTOS
    // SI K = 0, SERIA N1 + N2  (PEOR CASO)
    // SI K = N2, SERIA N1      (MEJOR CASO)

    pair<int, set<int>> mode;
    int maxFrequency = 0;

    for (const auto &pair : map1) // N1 + N2 - K OE
    {
        if (pair.second > maxFrequency) // 1 OE
        {
            mode.second.clear(); // 1 OE
            maxFrequency = pair.second; // 1 OE
            mode.first = maxFrequency; // 1 OE
            mode.second.insert(pair.first); // 1 OE
        } // 5 OE

        else if (pair.second == maxFrequency)  //  1 OE
        {
            mode.second.insert(pair.first); // 1 OE
        }
    }

    pair<pair<int, set<int>>, unordered_map<int, int>> modeX; // 1 OE
    modeX.first = mode; // 1 OE
    modeX.second = map1; // 1 OE

    return modeX; // 1 OE


    // PEOR CASO SERIA 2 + 5N2 + 2 + 1 + (N1 + N2)(3OE + 5OE) + 1 + 4 OE
    //  8N1 + 13N2 + 10 OE
    // SI N1 = N2 = N/2
    // 11N + 10
     
}

void printNewMode(pair<pair<int, set<int>>, unordered_map<int, int>> par)
{

    pair<int, set<int>> modeX = par.first;

    if (modeX.first <= 1)
    {
        cout << "No existe moda" << endl;
        return;
    }

    if (modeX.first > 1)
    {

        if (modeX.second.size() == 1)
        {
            cout << "La moda de frecuencia " << modeX.first << " es ";
        }

        else
        {
            cout << "Las modas de frecuencia " << modeX.first << " son ";
        }

        for (const auto &element : modeX.second)
        {
            cout << element << " ";
        }
    }
}