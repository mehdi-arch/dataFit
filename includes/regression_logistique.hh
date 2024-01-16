/**
 * @file regression_logistique.hh
 * @author Mehdi El Moussaoui
 * @version 0.1
 * @brief Header de la classe RegressionLogistique
*/

#ifndef _REGRESSION_LOGISTIQUE_
#include "regression.hh"
class RegressionLogistique: public Regression {
    private:
        /// @brief Vecteur contenant les poids de la régression
        Matrice poids;
    public:
        /**
         * @brief Contructeur implicite, crée une matrice 1x1 avec comme coefficient, peu recommandé.
         */
        RegressionLogistique();
        /**
         * @brief Constructeur explicite, initialise le vecteur poids
         * @param num_f Nombre de features
         * @exception invalid_argument si num_fit est inférieur ou égal à 0.
         */
        RegressionLogistique(int num_f);
        /**
         * @brief Fonction mathématique sigmoïde
         * @param x un double
         */
        double sigmoid(double x);
        /**
         * @brief Permets d'entraîner le modèle
         * @param X un vecteur de type Matrice
         */
        void entrainer(Matrice& X, Matrice& y, double alpha, int num_iterations);
        /**
         * @brief Permets de faire les prédictions et remplir l'attribut poids
         * @param features un vecteur de type const std::vector<double>
         * @return la prédiction en fonction des features
         */
        double predire(std::vector<double>& features);
        /**
         * @brief Permets de faire les prédictions et remplir l'attribut poids
         * @param features un vecteur de type Matrice
         * @return la prédiction en fonction des features
         */
        double predire(Matrice& features);
        /**
         * @brief Afficher l'attribut poids 
         */
        void afficherPoids();
};
#endif