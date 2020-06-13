#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<double> k;
    ifstream fin("a.txt");
    if (fin.is_open() == false)
	 {
        cerr << "a cannot be open!" << endl;
        return -1;
    }
    ofstream fout("b.txt");
    if (fout.is_open() == false) 
	{
        cerr << "b cannot be open!" << endl;
        return -1;
    }
    double temp;
    while (fin >> temp) 
	{
        k.push_back(temp);
    }
    sort(k.begin(), k.end());
    for (std::size_t  i = 0; i < k.size(); i++) {
        fout << k[i] << " ";
    }
    fin.close();
    fout.close();
    return 0;

}
