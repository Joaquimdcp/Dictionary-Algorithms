#include <vector>
using namespace std;

class dichotomic
{
  private:
    vector<unsigned int> dictionary;
    int comparacions;

  public:
    dichotomic();
    ~dichotomic();

    void insert(int key);
    void sortDic();
    bool  search(unsigned int key);
    int  get(int key);
    int get_comparacions();
    bool dichotomic_s(const unsigned int &query, const vector<unsigned int> &numbersVector, int left, int right);

};
