class Polynomial {
    private: 
    double *coefficients_;
    int length_array_;

    public:
    Polynomial();
    Polynomial(const int& size_array, const double* coefficients);    
    Polynomial(const Polynomial& polinomial);
    ~Polynomial();

    void DisplayPolynomial();

    double GetAndSetCoefficient(const int& index);
    double evaluate(const double& x_value);

    Polynomial& operator=(const Polynomial& first_polynomial);
    friend Polynomial operator+(const Polynomial& first_polynomial, const Polynomial& second_polynomial);
    friend Polynomial operator+(const Polynomial& first_polynomial, const double& constant);
    friend Polynomial operator-(const Polynomial& first_polynomial, const Polynomial& second_polynomial);
    friend Polynomial operator-(const Polynomial& first_polynomial, const double& constant);
    friend Polynomial operator*(const Polynomial& first_polynomial, const Polynomial& second_polynomial);
    friend Polynomial operator*(const Polynomial& first_polynomial, const double& constant);
};