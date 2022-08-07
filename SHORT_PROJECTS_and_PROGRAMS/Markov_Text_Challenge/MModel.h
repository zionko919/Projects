#ifndef _MMODEL_H  // NOLINT
#define _MMODEL_H

#include <string>
#include <map>
#include <vector>

class MModel {
 public:
    MModel(std::string text, int k);
    ~MModel();
    int kOrder();
    int freq(std::string kgram);
    int freq(std::string kgram, char c);
    char kRand(std::string kgram);
    std::string generate(std::string kgram, int L);

    friend std::ostream& operator<< (std::ostream &out, MModel &mm);

 private:
    int _order;
    // std::map <std::string, int> _kgrams;  // must #include <map>
    std::map <std::string, std::map<char, int> > _kgrams;
    std::string _alphabet;
};

#endif  // _MMODEL_H  // NOLINT

