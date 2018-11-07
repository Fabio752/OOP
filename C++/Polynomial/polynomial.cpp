
#include <iostream>
#include <cmath>

#include "polynomial.hpp"

Polynomial::Polynomial(){
    coefficients_ = new double[1];
    coefficients_[0] = 0;
    degree_ = 0;
}

Polynomial::Polynomial(const int& degree, const double* coefficients){
    coefficients_ = new double[degree + 1];
    
    degree_ = degree;
    for(int i = 0; i < degree + 1; i++){
        coefficients_[i] = coefficients[i];
    }
}

Polynomial::Polynomial(const Polynomial& polynomial){
    coefficients_ = new double [polynomial.degree_ + 1];
    degree_ = polynomial.degree_; 
    for(int i = 0; i < degree_ + 1; i++){
        coefficients_[i] = polynomial.coefficients_[i];
    }
}

Polynomial::~Polynomial(){
    std::cout << "polynomial is leaving : ";
    DisplayPolynomial();
    delete [] coefficients_;
}

void Polynomial::DisplayPolynomial(){
    std::cout << "polynomial = ";
    for(int i = 0; i < degree_ + 1; i++){
        if(i != degree_)
            std::cout << coefficients_[i] << "x^" << i <<" + ";
        else
            std::cout << coefficients_[i] << "x^" << i; 
    }
    std::cout << std::endl;
}

double Polynomial::At(const int& index){
    return coefficients_[index];
}

void Polynomial::At(const int& index, const double& value){
    coefficients_[index] = value;
}

double Polynomial::evaluate(const double& x_value){
    double result = 0;
    for(int i = 0; i < degree_ + 1; i++){
        result += coefficients_[i] * pow(x_value, i);
    }
    return result;
}

double& Polynomial::operator[](int i){
    return coefficients_[i];
}

const double& Polynomial::operator[](int i) const{
    return coefficients_[i];
}

Polynomial& Polynomial::operator=(const Polynomial& other_polynomial){
    for(int i = 0; i < other_polynomial.degree_ + 1; i++){
        coefficients_[i] = other_polynomial.coefficients_[i];
    }
    degree_ = other_polynomial.degree_;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& polynomial){
    for (int i = 0; i < polynomial.degree_ + 1; i++){
        if(i < polynomial.degree_)
            os << polynomial.coefficients_[i] <<"x^" <<i  << " ";
        else
            os << polynomial.coefficients_[i] <<"x^" <<i <<"\n";
    }

    return os;
}

Polynomial operator+(const Polynomial& first_polynomial, const Polynomial& second_polynomial){
    if(first_polynomial.degree_ < second_polynomial.degree_){
        Polynomial result_polynomial = second_polynomial;
        for(int i = 0; i < first_polynomial.degree_ + 1; i++){
            result_polynomial.coefficients_[i] += first_polynomial.coefficients_[i];
        }
    
        return result_polynomial;
    }
    else{
        Polynomial result_polynomial = first_polynomial;
        for(int i = 0; i < second_polynomial.degree_ + 1; i++){
            result_polynomial.coefficients_[i] += second_polynomial.coefficients_[i];
        }

        return result_polynomial;
    }
}

Polynomial operator+(const Polynomial& first_polynomial, const double& constant){  
    Polynomial result_polynomial = first_polynomial;
    result_polynomial.coefficients_[0] += constant;
    return result_polynomial;
}

Polynomial operator-(const Polynomial& first_polynomial, const Polynomial& second_polynomial){
   if(first_polynomial.degree_ < second_polynomial.degree_){
        Polynomial result_polynomial = second_polynomial;
        for(int i = 0; i < second_polynomial.degree_ + 1; i++){
            result_polynomial.coefficients_[i] = first_polynomial.coefficients_[i] - second_polynomial.coefficients_[i];
        }
    
        return result_polynomial;
    }
    else{
        Polynomial result_polynomial = first_polynomial;
        for(int i = 0; i < first_polynomial.degree_ + 1; i++){
            result_polynomial.coefficients_[i] = second_polynomial.coefficients_[i] - first_polynomial.coefficients_[i];
        }

        return result_polynomial;
    }
}

Polynomial operator-(const Polynomial& first_polynomial, const double& constant){  
    Polynomial result_polynomial = first_polynomial;
    result_polynomial.coefficients_[0] -= constant;
    return result_polynomial;
}


Polynomial operator*(const Polynomial& first_polynomial, const Polynomial& second_polynomial){
    double *new_coefficients = new double[first_polynomial.degree_ + second_polynomial.degree_ + 1];
    for(int i = 0; i < first_polynomial.degree_ + 1; i++){
        for(int j = 0; j < second_polynomial.degree_ + 1; j++){
           new_coefficients[i + j] += second_polynomial.coefficients_[j] * first_polynomial.coefficients_[i];
        }
    }

    Polynomial result_polynomial(first_polynomial.degree_ + second_polynomial.degree_, new_coefficients);
 
    return result_polynomial;
}

Polynomial operator*(const Polynomial& first_polynomial, const double& constant){
    Polynomial result_polynomial = first_polynomial;

    for(int i = 0; i < first_polynomial.degree_ + 1; i++){
        result_polynomial.coefficients_[i] = first_polynomial.coefficients_[i] * constant;
    }    
    return result_polynomial;
}

