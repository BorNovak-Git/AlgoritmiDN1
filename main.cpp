#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

bool Branje_Stevil(vector<unsigned char> &vec, const char s[]) {
    ifstream input(s);
    int st;

    if (!input.is_open()) {
        return false;
    }

    while (input >> st) {
        if (st >= 0 && st <= 255) {
            vec.push_back(static_cast<unsigned char>(st));
        }
    }
    input.close();
    return true;
}

void Izpis_Stevil(unsigned char* polje, unsigned int velikost) {
    ofstream output("out.txt");

    for (unsigned int i = 0; i < velikost; i++)
        output << static_cast<int>(polje[i]) << ' ';
    output.close();
}

void countingSort(vector<unsigned char>& A, int bit) {
    int count[2] = {0};
    vector<unsigned char> output(A.size());

    for (unsigned char num : A) {
        int bitValue = (num >> bit) & 1;
        count[bitValue]++;
    }

    count[1] += count[0];

    for (int i = A.size() - 1; i >= 0; i--) {
        int bitValue = (A[i] >> bit) & 1;
        output[--count[bitValue]] = A[i];
    }

    for (size_t i = 0; i < A.size(); i++) {
        A[i] = output[i];
    }
}



int main(int argc, const char* argv[]) {
    vector<unsigned char> A;

    if (argc < 2) return 0;
    if (!Branje_Stevil(A, argv[1])) return 0;

    Izpis_Stevil(&A[0], A.size());

    return 0;
}
