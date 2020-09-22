#include <math.h>
#include <cstdio>
#include <float.h>
#include <cassert>

enum {
    INFINITY_SOLUTION = -1,
    TWO_SOLUTIONS = 2,
    ONE_SOLUTION = 1,
    ZERO_SOLUTION = 0,
};

//------------------------------------------------------
//!Solves a square equation ax2 + bx + c = 0
//!
//! @param [in]    a      a-coefficient
//! @param [in]    b      b-coefficient
//! @param [in]    c      c-coefficient
//! @param [out]   first  first-coefficient
//! @param [out]   second  second-coefficient
//!
//! @return Number of roots
//!
//! @note In case of infinite number of roots, returns
//!                     INFINITY_SOLUTION.
//------------------------------------------------------\

int SquareEquation (double a, double b, double c, double* first, double* second)
{
    assert(first != nullptr);
    assert(second != nullptr);
    assert(&first != &second);
    assert(b * b < DBL_MAX);

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                return INFINITY_SOLUTION;
            } else {
                return ZERO_SOLUTION;
            }
        }
        else {
            *first = -c / b;
            return ONE_SOLUTION;
        }
    }
    else {
        double Discriminant = b * b - 4 * a * c;
        if (Discriminant == 0) {
            *first = -b / 2 * a;
            return ONE_SOLUTION;
        } else if (Discriminant > 0) {
            *first = (-b + sqrt(Discriminant)) / (2 * a);
            *second = (-b - sqrt(Discriminant)) / (2 * a);
            return TWO_SOLUTIONS;
        }
        else if (Discriminant < 0) {
            return ZERO_SOLUTION;
        }
    }
}


void TestOne() {
    double first = -10;
    double second = -10;
    int nRoots = 0;
    nRoots = SquareEquation(0, 3, 4, &first, &second);
    if (first == -4. / 3 && nRoots == 1) {
        printf("%-10s \033[32mpassed\033[0m {3x + 4 = 0}\n", "Test №1");
    }
    else {
        printf("%-10s \033[31mfalied\033[0m {3x + 4 = 0}\n", "Test №1");
    }
}

void TestTwo() {
    double first = -10;
    double second = -10;
    int nRoots = 0;
    nRoots = SquareEquation(0, 0, 4, &first, &second);
    if (first == -10 && nRoots == 0) {
        printf("%-10s \033[32mpassed\033[0m {4 = 0}\n", "Test №2");
    }
    else {
        printf("%-10s \033[31mfalied\033[0m {4 = 0}\n", "Test №2");
    }
}

void TestThree() {
    double first = -10;
    double second = -10;
    int nRoots = 0;
    nRoots = SquareEquation(0, 0, 0, &first, &second);
    if (first == -10 && nRoots == -1) {
        printf("%-10s \033[32mpassed\033[0m {0 = 0}\n", "Test №3");
    }
    else {
        printf("%-10s \033[31mfalied\033[0m {0 = 0}\n", "Test №3");
    }
}

void TestFour() {
    double first = -10;
    double second = -10;
    int nRoots = 0;
    nRoots = SquareEquation(1, -2, 1, &first, &second);
    if (first == 1 && nRoots == 1) {
        printf("%-10s \033[32mpassed\033[0m {x^2 - 2x + 1 = 0}\n", "Test №4");
    }
    else {
        printf("%-10s \033[31mfalied\033[0m {x^2 - 2x + 1 = 0}\n", "Test №4");
    }
}

void TestFive() {
    double first = -10;
    double second = -10;
    int nRoots = 0;
    nRoots = SquareEquation(1, 5, 6, &first, &second);
    if (first == -2 && nRoots == 2 && second == -3) {
        printf("%-10s \033[32mpassed\033[0m {x^2 + 5x + 6 = 0}\n", "Test №5");
    }
    else {
        printf("%-10s \033[32mfalied\033[0m {x^2 + 5x + 6 = 0}\n", "Test №5");
    }
}

void TestSix() {
    double first = -10;
    double second = -10;
    int nRoots = 0;
    nRoots = SquareEquation(1, 5, 0, &first, &second);
    if (first == 0 && nRoots == 2 && second == -5) {
        printf("%-10s \033[32mpassed\033[0m {x^2 + 5x = 0}\n", "Test №6");
    }
    else {
        printf("%-10s \033[31mfalied\033[0m {x^2 + 5x = 0}\n", "Test №6");
    }
}

void TestSeven() {
    double first = -10;
    double second = -10;
    int nRoots = 0;
    nRoots = SquareEquation(1, 0, 6, &first, &second);
    if (first == -10 && nRoots == 0 && second == -10) {
        printf("%-10s \033[32mpassed\033[0m {x^2 + 6 = 0}\n", "Test №7");
    }
    else {
        printf("%-10s \033[31mfalied\033[0m {x^2 + 6 = 0}\n", "Test №7");
    }
}

void TestEight() {
    double first = -10;
    double second = -10;
    int nRoots = 0;
    nRoots = SquareEquation(4, 0, -6, &first, &second);
    if (first == sqrt(6. / 4) && nRoots == 2 && second == -sqrt(6. / 4 )) {
        printf("%-10s \033[32mpassed\033[0m {2x^2 - 6 = 0}\n", "Test №8");
    }
    else {
        printf("%-10s \033[31mfalied\033[0m {2x^2 - 6 = 0}\n", "Test №8");
    }
}

int main() {
    double a = 0;
    double b = 0;
    double c = 0;
    double first = 0;
    double second = 0;
    TestOne();
    TestTwo();
    TestThree();
    TestFour();
    TestFive();
    TestSix();
    TestSeven();
    TestEight();
    printf("Inter coefficients:");
    scanf("%lg%lg%lg", &a, &b, &c);
    int nRoots = SquareEquation(a, b, c, &first, &second);
    switch (nRoots) {
        case 1:
            printf("Equation: %lgx^2%+lgx%+lg = 0\n", a, b, c);
            printf("Solution: %f", first);
            break;
        case 2:
            printf("Equation: %lgx^2%+lgx%+lg = 0\n", a, b, c);
            printf("Solutions: %f and %f", first, second);
            break;
        case 0:
            printf("Equation: %lgx^2%+lgx%+lg = 0\n", a, b, c);
            printf("No solution");
            break;
    }
}