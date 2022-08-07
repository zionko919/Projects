#include "ED.h"  //NOLINT
#include <iostream> //NOLINT
#include <string>
#include <algorithm>

EditDistance::EditDistance(std::string strA, std::string strB) {
    str_1 = strA;
    str_2 = strB;
    n = str_1.length();
    m = str_2.length();
    matrix = new int* [n+1];

    for (int i = 0; i < n+ 1; i++) {
        // simple lambda expression to calculate sum of two ints
        auto sum = [](int a, int b) {
            return a + b;
        };
        matrix[i] = new int[sum(m, 1)];
    }
    for (int j = 0; j < n + 1; j++) {
        // simple lambda expression to calculate subtraction between two ints
        auto subtract = [](int a, int b) {
            return a - b;
        };
        matrix[j][m] = (subtract(n, j)) * 2;
    }
    for (int k = 0; k < m + 1; k++) {
        // simple lambda expression to calculate subtraction between two ints
        auto subtract = [](int a, int b) {
            return a - b;
        };
        matrix[n][k] = (subtract(m, k)) * 2;
    }
    aligned_string = "";
}

EditDistance::~EditDistance() {
    for (int i = 0; i < n + 1; i++) {
        delete[] matrix[i];
    }
    delete matrix;
}

int EditDistance::min(int x, int y, int z) {
    return x < y ? (x < z ? x : z) : (y < z ? y : z);
}

int EditDistance::penalty(char a, char b) {
    if (a == b) {
        return 0;
    } else {
        return 1;
    }
}

int EditDistance::OptDistance() {
    for (int i = m - 1; i > -1; i--) {
        for (int j = n - 1; j > -1; j--) {
            if (!(penalty(str_1[j], str_2[i]))) {
                matrix[j][i] = matrix[j + 1][i + 1];
            } else {
                matrix[j][i] = min(matrix[j][i + 1] + 2,
                        matrix[j + 1][i] + 2, matrix[j + 1][i + 1] + 1);
            }
        }
    }
    return matrix[0][0];
}

std::string EditDistance::Alignment() {
    int i = 0;
    int j = 0;
    bool a = true;
    bool b = true;
    while (i < n || j < m) {
        if (!(a && b)) {
            break;
        }
        if (matrix[i][j] == matrix[i][j + 1] + 2) {
            aligned_string = aligned_string + "- " + str_2[j] + " 2\n";
            if (j < m && a) {
                j++;
            } else {
                a = false;
            }
        } else if (matrix[i][j] == matrix[i + 1][j] + 2) {
            aligned_string = aligned_string + str_1[i] + " - 2\n";
            if (i < n && b) {
                i++;
            } else {
                b = false;
            }
        } else if (penalty(str_1[i], str_2[j])) {
            aligned_string = aligned_string + str_1[i]
                    + " " + str_2[j] + " 1\n";
            if (i < n && b) {
                i++;
            } else {
                b = false;
            }
            if (j < m && a) {
                j++;
            } else {
                a = false;
            }
        } else {
            aligned_string = aligned_string + str_1[i]
                    + " " + str_2[j] + " 0\n";
            if (i < n && b) {
                i++;
            } else {
                b = false;
            }
            if (j < m && a) {
                j++;
            } else {
                a = false;
            }
        }
    }
    return aligned_string;
}

