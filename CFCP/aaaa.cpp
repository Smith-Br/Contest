#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define fastIO cin.tie(nullptr)->sync_with_stdio(false);
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define file(name) if (fopen(name".in","r")) { freopen(name".in","r",stdin); freopen(name".out","w",stdout); }

const double EPS = 1E-9;
const int INF = 1000000000;
const ll INF64 = (ll) 1E18;
const double PI = 3.1415926535897932384626433832795;

// Function to construct a good array
vector<vector<int>> buildValidArrays(int tt, vector<pair<int, vector<int>>> &testCases) {
    vector<vector<int>> results;

    // Iterate over each test case
    for (const auto &testCase : testCases) {
        int arraySize = testCase.first;
        const vector<int> &inputArray = testCase.second;

        // Initialize the result array with zeros
        vector<int> resultArray(arraySize, 0);
        resultArray[0] = inputArray[0];
        bool isValid = true;

        // Iterate over the input array to construct the result array
        for (int i = 1; i < arraySize - 1; ++i) {
            resultArray[i] = inputArray[i - 1] | inputArray[i];
            if ((resultArray[i - 1] & resultArray[i]) != inputArray[i - 1]) {
                isValid = false;
                break;
            }
        }

        // Set the last element of the result array
        resultArray[arraySize - 1] = inputArray[arraySize - 2];
        if (isValid && (resultArray[arraySize - 2] & resultArray[arraySize - 1]) != inputArray[arraySize - 2]) {
            isValid = false;
        }

        // Add the result array to the results vector if it is valid
        if (isValid) {
            results.push_back(resultArray);
        } else {
            results.push_back({-1});
        }
    }

    return results;
}

int main() {
    fastIO;

    int tt;
    cin >> tt;
    vector<pair<int, vector<int>>> testCases(tt);

    // Read input for each test case
    for (int i = 0; i < tt; ++i) {
        int arraySize;
        cin >> arraySize;
        vector<int> inputArray(arraySize - 1);
        for (int j = 0; j < arraySize - 1; ++j) {
            cin >> inputArray[j];
        }
        testCases[i] = {arraySize, inputArray};
    }

    // Construct valid arrays for each test case
    vector<vector<int>> results = buildValidArrays(tt, testCases);

    // Print results for each test case
    for (const auto &result : results) {
        if (result.size() == 1 && result[0] == -1) {
            cout << -1 << '\n';
        } else {
            for (size_t i = 0; i < result.size(); ++i) {
                cout << result[i] << (i + 1 == result.size() ? '\n' : ' ');
            }
        }
    }

    return 0;
}
