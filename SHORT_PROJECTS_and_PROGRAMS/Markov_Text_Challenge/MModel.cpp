#include "MModel.h"  // NOLINT
#include <map>  // NOLINT
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>

typedef std::map<std::string, std::map<char, int> > MarkovMap;
typedef std::map<std::string, std::map<char, int> >::iterator MarkovMapIterator;
typedef std::map<char, int> InnerMarkovMap;

MModel::MModel(std::string text, int k) : _order(k) {
    std::string temp = "";
    int endIndex;
    int jIndex;
    for (unsigned int i = 0; i < text.size(); i++) {
        auto sumLambda = [](int a, int b) {
            return a + b;
        };
        endIndex = sumLambda(i, k) % text.size();
        jIndex = sumLambda(i, k);
        for (int j = i; j < jIndex; j++) {
            temp += text[j%text.size()];
        }
        _kgrams[temp][text[endIndex]] += 1;
        _kgrams[temp][11] += 1;
        temp = "";
    }
}

MModel::~MModel() {
}

int MModel::kOrder() {
    return _order;
}

int MModel::freq(std::string kgram) {
    if (kgram.size() != static_cast<unsigned int>(_order)) {
        throw std::runtime_error("Error!: kgram is not of length k");
    }
    return _kgrams[kgram][11];
}

int MModel::freq(std::string kgram, char c) {
    if (kgram.size() != static_cast<unsigned int>(_order)) {
        throw std::runtime_error("Error!: kgram is not of length k");
    }
    InnerMarkovMap::iterator it2 = _kgrams[kgram].begin();
    if (it2 == _kgrams[kgram].end()) {
        throw std::runtime_error("Error!: kgram cannot be found");
    }
    return _kgrams[kgram][c];
}

char MModel::kRand(std::string kgram) {
    char c = '\0';
    if (kgram.size() != static_cast<unsigned int>(_order)) {
        throw std::runtime_error("Error!: kgram is not of length k");
    }
    InnerMarkovMap::iterator it2 = _kgrams[kgram].begin();
    if (it2 == _kgrams[kgram].end()) {
        throw std::runtime_error("Error!: kgram cannot be found");
    } else if (it2->second == _kgrams[kgram][11]) {
        it2++;
    }
    int total = freq(kgram);
    int random_num = rand() % total; //NOLINT
    for (; it2 != _kgrams[kgram].end(); ++it2) {
        random_num -= it2->second;
        if (random_num < 0) {
            c = it2->first;
            break;
        }
    }
    return c;
}

std::string MModel::generate(std::string kgram, int L) {
    if (kgram.size() != static_cast<unsigned int>(_order)) {
        throw std::runtime_error("Error!: kgram is not of length k");
    }
    std::string temp = kgram;
    for (int i = 0; i < L; i++) {
        temp = temp + kRand(temp.substr(i, kOrder()));
    }
    return temp;
}

std::ostream& operator<<(std::ostream &out, MModel &mm) {
    out << "k-order = " << mm._order << std::endl;
    for (MarkovMapIterator it=mm._kgrams.begin(); it !=mm._kgrams.end(); ++it) {
        out << "\nkgram: " << it->first;
        bool flag = true;
        for (InnerMarkovMap::iterator it2= it->second.begin();
             it2 != it->second.end(); ++it2) {
            if (flag) {
                out << "\nfreq =" << " " << it2->second << " " << std::endl;
                flag = false;
            } else {
                out << "freq of next char: '" << it2->first << "' = "
                    << it2->second << " " << std::endl;
            }
        }
    }
    return out;
}

