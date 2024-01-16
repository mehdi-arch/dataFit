/**
 * @file regression_polynomial.hh
 * @author Mehdi El Moussaoui
 * @version 0.1
 * @brief Header de la classe RegressionPolynomiale
 *
*/

#ifndef __REGRESSION_POLYNOMIAL__
    #define __REGRESSION_POLYNOMIAL__
    #ifndef MATRICES_MATHS
        #include "matrices.hh"
    #endif
    #ifndef __REGRESSION__
        #include "regression.hh"
    #endif
    #include <iostream>
    #include <cmath>
    class RegressionPolynomiale: public Regression {
        private:
            /// @brief Degrée de la regression polynomiale
            int degree;
            /// @brief Coefficients de la régression polynomiale
            Matrice coefficients;
        public:
            /**
             * @brief Constructeur implicite, met le degré à 0 (fonction constante) et le vecteur coefficient est vide
            */
            RegressionPolynomiale(void);
            /**
             * @brief Constructeur explicite, met le degrée et remplis le vecteur coefficient
             * @param x Vecteur de double (Abscisse)
             * @param y Vecteur de double (Ordonnée)
             * @param degree Degrée de la régression
             */
            RegressionPolynomiale(std::vector<double> x, std::vector<double> y, int degree);
            /**
             * @brief Getter de l'attribut degree
             * @return degree du polynome
            */
            int getDegree(void) const;
            /**
             * @brief Setter de l'attribut degree
             * @param degree nouveau degree
             */
            void setDegree(int & degree);
            /**
             * @brief Getter de l'attribut coefficients
             * @return coefficients du polynome
             */
            Matrice getCoefficient() const;
            /**
             * @brief Setter de l'attribut coefficients
             * @param coefficients nouveau degree de type vecteur de double
             */
            void setCoefficient(std::vector<double> & coefficients);
            /**
             * @brief Setter de l'attribut coefficients
             * @param coefficients nouveau degree de type Matrice
             */
            void setCoefficient(Matrice & coefficients);
            /**
             * @brief Calcul de la régression et remplis l'attribut coefficients
             */
            void calculerCoefficient(void);
            /**
             * @brief Affiche sur la sortie standard le polynôme résultat de la régression
             * @exception logic_failure si le calcul de coefficient à été fait.
             */
            void afficherResultats(void);
    };
#endif