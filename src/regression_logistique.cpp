/**
 * @file regression_logistique.cpp
 * @author Mehdi El Moussaoui
 * @version 0.1
 * @brief Implémentation de la classe RegressionLogistique
*/

#include "../includes/regression_logistique.hh"
#include <cmath>

RegressionLogistique::RegressionLogistique() {
    const std::vector<std::vector<double> > v = {{0.0}};
    this->poids = Matrice(v);
}

RegressionLogistique::RegressionLogistique(int num_f) {
    if(num_f > 0) {
        std::vector<double> vec;
        vec.resize(num_f + 1, 0.0);
        this->poids = Matrice(vec);
    } else {
        std::invalid_argument("Le nombre de features doit être supérieur strict à 0.");
    }
}

double RegressionLogistique::sigmoid(double x) {
    return 1.0 / (1.0 + std::exp(-x));
}

double RegressionLogistique::predire(std::vector<double>& features) {
    double z = this->poids(0, 0);
    for (size_t i = 0; i < features.size(); ++i) {
        z += this->poids(i + 1, 0) * features[i];
    }
    return sigmoid(z);
}

double RegressionLogistique::predire(Matrice& features) {
    double z = this->poids(0, 0);
    for (size_t i = 0; i < features.getLigne(); ++i) {
        z += this->poids(i + 1, 0) * features(i, 0);
    }
    return sigmoid(z);
}

void RegressionLogistique::entrainer(Matrice& X, Matrice& y, double alpha, int num_iterations) {
    size_t m = X.getLigne();
    size_t n = this->poids.getLigne() - 1;
    for (int iter = 0; iter < num_iterations; ++iter) {
        std::vector<double> gradient(n + 1, 0.0);
        for (size_t i = 0; i < m; ++i) {
            double prediction = predire(X.getElements()[i]);
            double erreur = prediction - y(i, 0);
            gradient[0] += erreur;
            for (size_t j = 0; j < n; ++j) {
                gradient[j + 1] += erreur * X(i, j);
            }
        }
        for (size_t j = 0; j <= n; ++j) {
            this->poids(j, 0) -= alpha * gradient[j] / m;
        }
    }
}

void RegressionLogistique::afficherPoids(void) {
    std::vector<std::vector<double>> elems = this->poids.getElements();
    std::cout << "Poids : ";
    for (int i = 0; i < elems.size(); i++) {
        std::cout << elems[i][0] << " ";
    }
    std::cout << std::endl;
}