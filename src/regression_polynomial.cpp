/**
 * @file regression_polynomial.cpp
 * @author Mehdi El Moussaoui
 * @version 0.1
 * @brief Implémentation de la classe RegressionPolynomiale
*/
#include "../includes/regression_polynomial.hh"

RegressionPolynomiale::RegressionPolynomiale(): degree(0), coefficients(std::vector<double>()) {}

RegressionPolynomiale::RegressionPolynomiale(std::vector<double> x, std::vector<double> y, int degree): Regression::Regression(x, y), degree(degree){}

int RegressionPolynomiale::getDegree() const {
    return this->degree;
}

void RegressionPolynomiale::setDegree(int & degree) {
    this->degree = degree;
}

Matrice RegressionPolynomiale::getCoefficient() const {
    return this->coefficients;
}

void RegressionPolynomiale::setCoefficient(std::vector<double> & coefficients) {
    Matrice m(coefficients);
    this->coefficients = m;
}

void RegressionPolynomiale::setCoefficient(Matrice & coefficients) {
    this->coefficients = coefficients;
}

void RegressionPolynomiale::calculerCoefficient(void){

    std::vector<std::vector<double> > A_tab;
    Matrice Y = getY();

    for(int i = 0; i < getX().getElements().size(); i++) {
        std::vector<double> ligne;
        for(int j = 0; j <= degree; j++) {
            Matrice v = getX();
            std::vector<std::vector<double> > va = v.getElements();
            ligne.push_back(std::pow(va[i][0], j));
        }
        A_tab.push_back(ligne);
    }
    Matrice A(A_tab);
    Matrice A_transposee = A.transpose();
    Matrice A_transposee_A = A_transposee * A;
    Matrice A_transposee_A_inverse = A_transposee_A.inverserMatrice();
    Matrice A_transposee_Y = A_transposee * Y;
    Matrice coefs = A_transposee_A_inverse * A_transposee_Y;
    this->coefficients = coefs;
}

void RegressionPolynomiale::afficherResultats(void) {
    Matrice coefs = coefficients;
    for(int i = this->getDegree(); i >= 0 ; i--) {
        if(coefs(i, 0) != 0) {
            if(i == this->getDegree()) {
                std::cout << coefs(i, 0) << "*x^" << i << " ";
            } else if (coefs(i, 0) < 0){
                if(i == 0) {
                    std::cout << coefs(i, 0) << std::endl;
                } else {
                    std::cout << coefs(i, 0) << "*x^" << i << " ";
                }
            } else {
                if(i == 0) {
                    std::cout << "+ " << coefs(i, 0) << std::endl;
                } else {
                    std::cout << "+ " << coefs(i, 0) << "*x^" << i;
                }
            }

        }
    }
}
