#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <random>
#include <cmath>

using namespace std;

map<int, set<int>> findModeX(vector<int> X);
void mergeX(vector<int> &X, vector<int> &X1, vector<int> &X2, int n, int len1, int len2);
void mergeSortX(vector<int> &X, int n);
void printArrayX(vector<int> X);
vector<int> randomVector(int size, int min, int max);

int main()
{

    // vector<int> array = randomVector(n, 1, 20);
    //

    vector<int> array1 = {17, 5, 12, 9, 18, 10, 4, 18, 1, 1};
    vector<int> array2 = {13, 12, 4, 10, 9, 20, 11, 15, 10, 11, 8, 20, 4, 14, 4, 6, 13, 17, 6, 10};
    vector<int> array3 = {8, 4, 13, 18, 20, 8, 20, 6, 7, 18, 6, 2, 6, 19, 11, 6, 2, 2, 18, 17, 17,
                          20, 20, 3, 8, 5, 9, 14, 7, 6, 13, 19, 11, 17, 11, 10, 16, 11, 15, 15};

    vector<int> array4 = {9, 18, 8, 3, 7, 17, 10, 13, 14, 16, 18, 18, 4, 14, 16, 1, 2, 18, 8, 17,
                          16, 6, 20, 11, 5, 9, 10, 4, 18, 15, 7, 3, 7, 4, 16, 19, 19, 1, 2, 17,
                          11, 9, 20, 7, 17, 5, 4, 17, 1, 11, 15, 19, 5, 2, 5, 6, 11, 8, 13, 3, 12,
                          10, 13, 9, 13, 15, 17, 1, 19, 14, 20, 3, 17, 6, 4, 14, 15, 17, 6, 13, 3,
                          6, 1, 3, 10, 6, 3, 9, 19, 16, 1, 14, 1, 5, 13, 11, 8, 13, 2, 12};

    vector<int> array5 = {6, 3, 13, 5, 18, 16, 17, 16, 13, 13, 17, 18, 6, 15, 8, 12, 20, 4, 20, 12,
                          1, 20, 11, 16, 2, 17, 18, 17, 17, 8, 10, 11, 18, 16, 3, 4, 15, 14, 12,
                          8, 10, 11, 4, 11, 1, 11, 11, 17, 16, 18, 2, 18, 18, 7, 18, 8, 12, 4, 6,
                          6, 8, 4, 12, 6, 20, 11, 9, 7, 9, 11, 19, 3, 7, 8, 13, 11, 6, 20, 20, 11,
                          4, 5, 18, 14, 3, 6, 15, 7, 7, 13, 10, 15, 15, 9, 3, 14, 5, 7, 10, 16, 8,
                          17, 7, 7, 17, 18, 4, 13, 19, 5, 7, 11, 5, 17, 19, 10, 17, 20, 17, 7, 15,
                          20, 4, 8, 2, 8, 15, 17, 8, 10, 13, 20, 11, 16, 17, 5, 9, 8, 7, 11, 20, 19,
                          8, 5, 20, 15, 16, 13, 19, 13, 10, 8, 10, 7, 6, 19, 1, 18, 8, 8, 16, 9, 18,
                          20, 13, 5, 15, 13, 5, 16, 19, 6, 19, 6, 3, 4, 16, 9, 8, 14, 17, 16, 18, 11,
                          1, 18, 8, 18, 15, 17, 8, 5, 4, 10, 6, 14, 20, 7, 1, 4};

    printArrayX(array3);
    map<int, set<int>> modas = findModeX(array3);

    for (const auto &pair : modas)
    {
        int moda = pair.first;
        set<int> modeValues = pair.second;
        if (modeValues.size() == 1)
        {
            std::cout << "La moda de frecuencia " << moda << " es: " << *modeValues.begin() << endl;
        }
        else
        {
            std::cout << "Las modas de frecuencia " << moda << " son: " << endl;
            for (int value : modeValues)
            {
                std::cout << value << endl;
            }
        }
    }

    return 0;
}

map<int, set<int>> findModeX(vector<int> X)
{

    int n = X.size();
    int oe = n * log(n);

    map<int, set<int>> arrayModes;
    oe++;
    int maxFrequency = 0;
    oe++;

    map<int, int> frequencyMap;
    oe++;

    oe ++;
    for (int element : X)
    {
        oe += 2;
        frequencyMap[element]++;
        oe += 2;
        maxFrequency = max(maxFrequency, frequencyMap[element]);
        oe += 2;
    }

    oe ++;

    oe ++;
    for (const auto &pair : frequencyMap)
    {
        oe += 2;
        if (pair.second == maxFrequency)
        {
            oe++;
            arrayModes[maxFrequency].insert(pair.first);
            oe++;
        }
    }
    oe ++;

    oe++;
    std::cout << "\n" << oe << " operaciones elementales" << endl;

    return arrayModes;
}

void mergeX(vector<int> &X, vector<int> &X1, vector<int> &X2, int n, int len1, int len2)
{

    int i = 0;
    int j = 0;

    while (i + j < n)
    {
        if (j == len2 || (i < len1 && X1[i] < X2[j]))
        {
            X[i + j] = X1[i];
            i++;
            int a = X[i + j];
        }
        else
        {
            X[i + j] = X2[j];
            j++;
            int b = X[i + j];
        }
    }
}

void mergeSortX(vector<int> &X, int n)
{

    if (n < 2)
    {
        return;
    }
    int middle = n / 2;

    vector<int> X1(X.begin(), X.begin() + middle);
    vector<int> X2(X.begin() + middle, X.end());

    mergeSortX(X1, middle);
    mergeSortX(X2, n - middle);
    mergeX(X, X1, X2, n, middle, n - middle);
}

vector<int> randomVector(int size, int min, int max)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribucion(min, max);

    std::vector<int> vec(size);
    for (int i = 0; i < size; ++i)
    {
        vec[i] = distribucion(gen);
    }
    return vec;
}

void printArrayX(vector<int> X)
{
    for (const auto &element : X)
        cout << element << " ";
}
