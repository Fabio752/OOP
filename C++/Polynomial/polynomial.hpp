
#include <iostream>

class Polynomial {
    private: 
    double *coefficients_;
    int degree_;

    public:
    Polynomial();
    Polynomial(const int& degree, const double* coefficients);    
    Polynomial(const Polynomial& polinomial);
    ~Polynomial();

    void DisplayPolynomial();

    double At(const int& index);
    void At(const int& index, const double& value);
    double evaluate(const double& x_value);
    double& operator[](int i);
    const double& operator[](int i) const;

    Polynomial& operator=(const Polynomial& first_polynomial);
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& polynomial);
    friend Polynomial operator+(const Polynomial& first_polynomial, const Polynomial& second_polynomial);
    friend Polynomial operator+(const Polynomial& first_polynomial, const double& constant);
    friend Polynomial operator-(const Polynomial& first_polynomial, const Polynomial& second_polynomial);
    friend Polynomial operator-(const Polynomial& first_polynomial, const double& constant);
    friend Polynomial operator*(const Polynomial& first_polynomial, const Polynomial& second_polynomial);
    friend Polynomial operator*(const Polynomial& first_polynomial, const double& constant);
};

