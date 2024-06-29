#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

void printVector(const vector<int> &vec)
{

    vector<int>::iterator it;

    auto print = [](const int &num) { cout << num << ' '; };

    for_each(vec.begin(), vec.end(), print);

    cout << endl;
}

int main()
{

    vector<int> prviVektor;

    prviVektor.insert(prviVektor.begin(), {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100});

    auto kvadrat = [](int &num) {
        num *= num;
    };

    printVector(prviVektor);

    for_each(prviVektor.begin(), prviVektor.end(), kvadrat);

    printVector(prviVektor);

    vector<int> drugiVektor;

    copy_if(prviVektor.begin(), prviVektor.end(), back_inserter(drugiVektor), [](int num) { return (num % 7) != 0; });

    printVector(drugiVektor);

    auto reciprocnaVrednost = [](double a, int b) { return (move(a) + pow(b, -1)); };

    double reciprocnaSuma = accumulate(drugiVektor.begin(), drugiVektor.end(), 0.0, reciprocnaVrednost);

    cout << reciprocnaSuma << endl; 

    drugiVektor.erase(remove_if(drugiVektor.begin(), drugiVektor.end(), [](int num) { return (num % 9) == 0; }), drugiVektor.end());

    printVector(drugiVektor);

    int i = 0;

    vector<int>::iterator it = find_if(drugiVektor.begin(), drugiVektor.end(), [](int num) { return (num % 13) == 0; });

    if (distance(drugiVektor.begin(), it) == drugiVektor.size())
        cout << -1 << endl;
    else
        cout << distance(drugiVektor.begin(), it) << endl;

    return 0;
}