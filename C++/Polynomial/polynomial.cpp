#include <iostream>
#include <cmath>

#include "polynomial.hpp"

Polynomial::Polynomial(){
    coefficients_ = new double[1];
    coefficients_[0] = 0;
    length_array_ = 1;
}

Polynomial::Polynomial(const int& size_array, const double* coefficients){
    coefficients_ = new double[size_array];
    
    length_array_ = size_array;
    for(int i = 0; i < size_array; i++){
        coefficients_[i] = coefficients[i];
    }
}

Polynomial::Polynomial(const Polynomial& polynomial){
    coefficients_ = new double [polynomial.length_array_];
    length_array_ = polynomial.length_array_; 
    for(int i = 0; i < length_array_; i++){
        coefficients_[i] = polynomial.coefficients_[i];
    }
}

Polynomial::~Polynomial(){
    //std::cout << "polynomial is leaving : ";
    //DisplayPolynomial();
    delete [] coefficients_;
}

void Polynomial::DisplayPolynomial(){
    std::cout << "polynomial = ";
    for(int i = 0; i < length_array_; i++){
        if(i != length_array_ - 1)
            std::cout << coefficients_[i] << "x^" << i <<" + ";
        else
            std::cout << coefficients_[i] << "x^" << i; 
    }
    std::cout << std::endl;
}

double Polynomial::GetAndSetCoefficient(const int& index){
    char answer;
    double value = coefficients_[index];
    std::cout << " Do you want to overwrite the value at index " << index <<"? (Y, N)" << std::endl;
    std::cin >> answer;
    if(answer == 'Y' || answer == 'y'){
        double new_value;
        std::cout << "With which value?" <<std::endl;
        std::cin >> new_value;
        coefficients_[index] = new_value;
    }

    return value;
}

double Polynomial::evaluate(const double& x_value){
    double result = 0;
    for(int i = 0; i < length_array_; i++){
        result += coefficients_[i] * pow(x_value, i);
    }
    return result;
}

Polynomial& Polynomial::operator=(const Polynomial& other_polynomial){
    for(int i = 0; i < other_polynomial.length_array_; i++){
        coefficients_[i] = other_polynomial.coefficients_[i];
    }
    length_array_ = other_polynomial.length_array_;
    return *this;
}

Polynomial operator+(const Polynomial& first_polynomial, const Polynomial& second_polynomial){
    if(first_polynomial.length_array_ < second_polynomial.length_array_){
        Polynomial result_polynomial = second_polynomial;
        for(int i = 0; i < first_polynomial.length_array_; i++){
            result_polynomial.coefficients_[i] += first_polynomial.coefficients_[i];
        }
    
        return result_polynomial;
    }
    else{
        Polynomial result_polynomial = first_polynomial;
        for(int i = 0; i < second_polynomial.length_array_; i++){
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
   if(first_polynomial.length_array_ < second_polynomial.length_array_){
        Polynomial result_polynomial = second_polynomial;
        for(int i = 0; i < second_polynomial.length_array_; i++){
            result_polynomial.coefficients_[i] = first_polynomial.coefficients_[i] - second_polynomial.coefficients_[i];
        }
    
        return result_polynomial;
    }
    else{
        Polynomial result_polynomial = first_polynomial;
        for(int i = 0; i < first_polynomial.length_array_; i++){
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
    double *new_coefficients = new double[first_polynomial.length_array_ + second_polynomial.length_array_];
    for(int i = 0; i < first_polynomial.length_array_; i++){
        for(int j = 0; j < second_polynomial.length_array_; j++){
           new_coefficients[i + j] += second_polynomial.coefficients_[j] * first_polynomial.coefficients_[i];
        }
    }

    Polynomial result_polynomial(first_polynomial.length_array_ + second_polynomial.length_array_ - 1, new_coefficients);
 
    return result_polynomial;
}

Polynomial operator*(const Polynomial& first_polynomial, const double& constant){
    Polynomial result_polynomial = first_polynomial;
    std::cout <<"anubi";

    for(int i = 0; i < first_polynomial.length_array_; i++){
        result_polynomial.coefficients_[i] = first_polynomial.coefficients_[i] * constant;
    }    
    return result_polynomial;
}
