#ifndef ED_H_  //NOLINT
#define ED_H_  //NOLINT

#include <string>
#include <algorithm>

class EditDistance {
 public:
    EditDistance(std::string strA, std::string strB);
    ~EditDistance();
    int penalty(char a, char b);
    int min(int a, int b, int c);
    int OptDistance();
    std::string Alignment();
 private:
    int ** matrix;
    int m;
    int n;
    std::string str_1;
    std::string str_2;
    std::string aligned_string;
};

#endif  // ED_H_ //NOLINT

