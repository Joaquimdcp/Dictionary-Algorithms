#include <vector>
using namespace std;

class dicothomic
{
  private:
    vector<unsigned int> dictionary;

  public:
    dicothomic();
    ~dicothomic();

    void insert(int key);
    bool  search(unsigned int key);
    int  get(int key);
    bool dichotomic_s(const unsigned int &query, const vector<unsigned int> &numbersVector, int left, int right);

};