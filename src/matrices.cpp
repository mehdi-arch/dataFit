/**
 * @file matrices.cpp
 * @author Mehdi El Moussaoui
 * @version 0.1
 * @brief Implémentation des méthodes de la classe Matrice
*/
#include "../includes/matrices.hh"

Matrice::Matrice(): elements(std::vector<std::vector<double> >()), num_col(0), num_lig(0) {}

Matrice::Matrice(size_t lig, size_t col): num_col(col), num_lig(lig) {
    elements.resize(lig, std::vector<double>(col, 0.0));
}

Matrice::Matrice(const std::vector<std::vector<double> > array, size_t num_lig, size_t num_cols): elements(array), num_col(array[0].size()), num_lig(array.size()) {}

Matrice::Matrice(const std::vector<std::vector<double> > array): elements(array), num_col(array[0].size()), num_lig(array.size()){}

Matrice::Matrice(const std::vector<double> array): num_col(1), num_lig(array.size()) {
    std::vector<std::vector<double> > v;
    int l = 0;
    for(ssize_t i = 0; i < array.size(); i++) {
        v.push_back({array[i]});
        l++;
    }
    this->elements = v;
    this->num_lig = l;
}

size_t Matrice::getLigne(void) const {
    return this->num_lig;
}

size_t Matrice::getCol(void) const {
    return this->num_col;
}

std::vector<std::vector<double> > Matrice::getElements(void) const {
    return this->elements;
}

double& Matrice::operator()(size_t i, size_t j) {
    if (i < num_lig && j < num_col && i >= 0 && j >= 0) {
        return this->elements[i][j];
    } else {
        throw std::out_of_range("Indices hors limites");
    }
}

Matrice Matrice::operator+(Matrice& autre) const {
    if (num_lig == autre.getLigne() && num_col == autre.getCol()) {
        Matrice resultat(getLigne(), getCol());
        for (size_t i = 0; i < getLigne(); ++i) {
            for (size_t j = 0; j < getCol(); ++j) {
                resultat(i, j) = elements[i][j] + autre(i, j);
            }
        }
        return resultat;
    } else {
        throw std::invalid_argument("Les dimensions des matrices ne correspondent pas pour l'addition.");
    }
}

Matrice Matrice::operator*(const double& scalaire) const {
    Matrice resultat(this->getLigne(), this->getCol());
    for (size_t i = 0; i < this->getLigne(); ++i) {
        for (size_t j = 0; j < this->getCol(); ++j) {
            resultat(i, j) = elements[i][j] * scalaire;
        }
    }
    return resultat;
}

Matrice Matrice::operator*(Matrice& autre) {
    if (num_col != autre.getLigne()) {
        throw std::invalid_argument("Incompatible matrix dimensions for multiplication");
    }
    Matrice result(num_lig, autre.getCol());
    for (size_t i = 0; i < num_lig; ++i) {
        for (size_t j = 0; j < autre.getCol(); ++j) {
            double sum = 0.0;
            for (size_t k = 0; k < num_col; ++k) {
                sum += this->elements[i][k] * autre(k, j);
            }
            result.elements[i][j] = sum;
        }
    }
    return result;
}

void Matrice::afficher() const {
    for (size_t i = 0; i < this->getLigne(); ++i) {
        for (size_t j = 0; j < this->getCol(); ++j) {
            std::cout << elements[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

double Matrice::determinant() const {
    if (this->getLigne() != this->getCol()) {
        throw std::invalid_argument("Le calcul du déterminant n'est possible que pour les matrices carrées.");
    }
    if (this->getCol() == 1) {
        return this->elements[0][0];
    }
    double det = 0;
    for (size_t j = 0; j < this->getCol(); ++j) {
        Matrice sousMatrice(this->getLigne() - 1, this->getCol() - 1);
        for (size_t i = 1; i < this->getLigne(); ++i) {
            for (size_t k = 0, l = 0; k < this->getCol(); ++k) {
                if (k == j) continue;
                sousMatrice(i - 1, l++) = elements[i][k];
            }
        }
        double signe = (j % 2 == 0) ? 1 : -1;
        det += signe * elements[0][j] * sousMatrice.determinant();
    }
    return det;
}

Matrice Matrice::matriceAdjointe() const {
    if (this->getLigne() != this->getCol()) {
        throw std::invalid_argument("Le calcul de la matrice adjointe n'est possible que pour les matrices carrées.");
    }
    Matrice adjointe(this->getLigne(), this->getCol());
    for (size_t i = 0; i < this->getLigne(); ++i) {
        for (size_t j = 0; j < this->getCol(); ++j) {
            Matrice sousMatrice(this->getLigne() - 1, this->getCol() - 1);
            for (size_t m = 0, p = 0; m < this->getLigne(); ++m) {
                if (m == i) continue;
                    for (size_t q = 0, nq = 0; q < this->getCol(); ++q) {
                        if (q == j) continue;
                            sousMatrice(p, nq++) = elements[m][q];
                    }
                    ++p;
            }
            double signe = ((i + j) % 2 == 0) ? 1 : -1;
            adjointe(j, i) = signe * sousMatrice.determinant();
        }
    }
    return adjointe;
}

Matrice Matrice::transpose() const {
    Matrice result(num_col, num_lig);
    for (size_t i = 0; i < num_lig; ++i) {
        for (size_t j = 0; j < num_col; ++j) {
            result(j, i) = elements[i][j];
        }
    }
    return result;
}

Matrice Matrice::inverserMatrice() const {
    double det = determinant();
    if (det == 0) {
        throw std::invalid_argument("La matrice est singulière, l'inversion n'est pas possible.");
    }
    Matrice adjointeMat = matriceAdjointe();
    Matrice inverseMat(this->getLigne(), this->getCol());
    for (size_t i = 0; i < this->getLigne(); ++i) {
        for (size_t j = 0; j < this->getCol(); ++j) {
            inverseMat(i, j) = adjointeMat(i, j) / det;
        }
    }
    return inverseMat;
}