/**
 * @file regression.cpp
 * @author Mehdi El Moussaoui
 * @version 0.1
 * @brief Implémentation de la classe Regression
*/
#include  "../includes/regression.hh"

Regression::Regression(): x(Matrice()), y(Matrice()) {}

Regression::Regression(std::vector<double> x, std::vector<double> y) {
    if(y.size() == x.size()) {
        std::vector<std::vector<double> > v1;
        std::vector<std::vector<double> > v2;
        for(int i = 0; i < x.size(); i++) {
            v1.push_back({x[i]});
            v2.push_back({y[i]});
        }
        this->x = Matrice(v1);
        this->y = Matrice(v2); 
    } else {
        throw std::invalid_argument("Les matrices X et Y doivent être des vecteurs de même dimension (1 colonne, n lignes).");
    }
}

Regression:: Regression(Matrice & x, Matrice & y) {
    if(x.getCol() == 1 && y.getCol() == 1 && y.getLigne() == x.getLigne()) {
        this->x = x;
        this->y = y;
    } else {
        throw std::invalid_argument("Les matrices X et Y doivent être des vecteurs de même dimension (1 colonne, n lignes).");
    }
}

Matrice Regression::getX() const {
    return this->x;
}

Matrice Regression::getY() const {
    return this->y;
}

void Regression::setX(const Matrice & x) {
    if(x.getElements().size() != getY().getElements().size()) {
        throw std::invalid_argument("Les vecteurs doivent être de même taille.");
    } else {
        this->x = x;
    }
}

void Regression::setY(const Matrice & y) {
    if(y.getElements().size() != getX().getElements().size()) {
        throw std::invalid_argument("Les vecteurs doivent être de même taille.");
    } else {
        this->y = y;
    }
}

void Regression::afficher(bool printData, bool printCurve) {
    std::cout << "l'affichage arrive" << std::endl;
    if(printData == true) {
        std::cout << "On affiche le nuage de points" << std::endl;
    }
    if(printCurve == true) {
        std::cout << "On affiche la courbe" << std::endl;
    }
}
