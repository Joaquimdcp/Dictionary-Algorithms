#include <iostream>
#include <random>
#include <fstream>
#define MAX 4294967295
using namespace std;



int main() {

    int n;
    double per, per_claus;

    cout << "Quants nombres vols generar?" << endl;
    cin >> n;

    cout << "Percentatge de repetits(en decimal):" << endl;
    cin >> per;

    cout << "Percentatge de claus al text(en decimal):" << endl;
    cin >> per_claus;

    long unsigned int r, r2;
    random_device rand;
    mt19937 generator(rand());
    uniform_int_distribution<unsigned int> randomInts(1,MAX);

    ofstream claus, text;
    claus.open("claus");
    text.open("text");

    r = randomInts(generator);
    int mod = 1/per_claus;
    for(int i = 0; i < n; ++i) {
        if (i >= n*per) r = randomInts(generator);
        claus << r << endl;
        if (i%mod == 0 and i != 0) text << r << endl;
        else {
            r2 = randomInts(generator);
            text << r2 << endl;
        }
        r2 = randomInts(generator);
        text << r2 << endl;
    }

    claus.close();
    text.close();
}
