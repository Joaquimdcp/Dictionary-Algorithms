#include <vector>
using namespace std;

class dicothomic
{
  private:
    vector<unsigned int> dictionary;
    int comparacions;

  public:
    dicothomic();
    ~dicothomic();

    void insert(int key);
    bool  search(unsigned int key);
    int  get(int key);
    int get_comparacions();
    bool dichotomic_s(const unsigned int &query, const vector<unsigned int> &numbersVector, int left, int right);

};
