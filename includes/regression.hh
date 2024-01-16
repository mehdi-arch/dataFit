/**
 * @file regression.hh
 * @author Mehdi El Moussaoui
 * @version 0.1
 * @brief Header de la classe Regression
 *
*/
#ifndef __REGRESSION__
    #define __REGRESSION__
    #ifndef MATRICES_MATHS
        #include "matrices.hh"
    #endif
    #include <iostream>
    #include <vector>

    class Regression {
        protected:
            /// @brief Vecteur contenant toutes les abscisses
            Matrice x;
            /// @brief Vecteur contenant toutes les ordonnées
            Matrice y;
        public:
            /**
             * @brief Constructeur implicite, remplis les champs par des vecteurs vides
             */
            Regression();
            /**
             * @brief Constructeur explicite, remplis les champs par les vecteurs en argument.
             * @param x remplis le champs x de la classe
             * @param y remplis le champs y de la classe
             * @exception invalid_argument, si les dimensions des vecteurs X et Y ne coïncident pas
             */
            Regression(std::vector<double> x, std::vector<double> y);
            /**
             * @brief Constructeur explicite, remplis les champs par les vecteurs en argument.
             * @param x remplis le champs x de la classe
             * @param y remplis le champs y de la classe
             * @exception invalid_argument, si les dimensions des vecteurs X et Y ne coïncident pas
             */
            Regression(Matrice & x, Matrice & y);
            /**
             * @brief Getter du vecteur X
             * @return Le vecteur X
             */
            Matrice getX() const;
            /**
             * @brief Getter du vecteur Y
             * @return Le vecteur Y
             */
            Matrice getY() const;
            /**
             * @brief Setter du vecteur X
             * @param x Nouveau vecteur X
             */
            void setX(const Matrice & x);
            /**
             * @brief Setter du vecteur Y
             * @param y Nouveau vecteur Y
             */
            void setY(const Matrice & y);
            /**
             * @brief Fonction qui affiche la regression et/ou le nuage de points
             * @param printData par défault à **true**, affiche le nuage de points
             * @param printCurve par défault à **true**, affiche la courbe de régression
            */
            void afficher(bool printData = true, bool printCurve = true);
    };
#endif