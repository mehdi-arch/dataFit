/**
 * @file matrices.hh
 * @author Mehdi El Moussaoui
 * @version 0.1
 * @brief Header de la classe Matrice
 *
*/

#ifndef MATRICES_MATHS
    #define MATRICES_MATHS
    #include <iostream>
    #include <vector>
    #include <cstddef>

    class Matrice {
    protected:
        /// @brief Tableau contenant les coefficients de la matrice
        std::vector<std::vector<double> > elements;
        /// @brief Nombre de colonnes
        size_t num_col;
        /// @brief Nombre de lignes
        size_t num_lig;
    public:
        /**
         * @brief Constructeur implicite
         */
        Matrice();
        /**
         * @brief Constructeur explicite qui initialise une matrice en fonction des dimensions souhaitée, non recommandé. 
         * @param lig Nombre de lignes de la matrice
         * @param col Nombre de colonnes de la matrice
         */
        Matrice(size_t lig, size_t col);
        /**
         * @brief Constructeur explicite qui initialise une matrice en fonction des dimensions souhaitée et un tableau de deux dimensions (coefficient de la matrice), non recommandé. 
         * @param array Tableau de double de double dimensions 
         * @param lig Nombre de lignes de la matrice
         * @param col Nombre de colonnes de la matrice
         */
        Matrice(const std::vector<std::vector<double> > array, size_t num_lig, size_t num_cols);
        /**
         * @brief Constructeur explicite qui initialise une matrice en fonction d'un tableau de deux dimensions (coefficient de la matrice), recommandé. 
         * @param array Tableau (Vector) de double de double dimensions 
         */
        Matrice(const std::vector<std::vector<double> > array);
        /**
         * @brief Constructeur explicite qui initialise une matrice en fonction d'un tableau a une dimension (c'est un vecteur), recommandé. 
         * @param array Tableau (Vector) de double de une dimension
         */
        Matrice(const std::vector<double> array);
        /**
         * @brief Getter de l'attribut  num_lig (le nombre de lignes de la matrice)
         * @return L'attribut num_lig, le nombre de lignes
        */
        size_t getLigne() const;
        /**
         * @brief Getter de l'attribut  num_col (le nombre de colonnes de la matrice)
         * @return L'attribut num_col, le nombre de colonnes
        */
        size_t getCol() const;
        /**
         * @brief Getter de l'attribut  elements (coefficients de la matrice)
         * @return L'attribut elements, les coefficients de la matrice
        */
        std::vector<std::vector<double> > getElements() const;
        /**
         * @brief Opérateur: ()
         * @param i i-ème ligne de la matrice
         * @param j j-ème colonne de la matrice
         * @return Coefficient de la i-ème ligne et j-ème colonne de type double
         * @exception out_of_range les indices sont trops grands ou petits
         */
        double& operator()(size_t i, size_t j);
        /**
         * @brief Opérateur: +, Addition entre deux matrices
         * @param autre une matrice de bonne dimensions
         * @return Retourne la matrice résultante de la somme
         * @exception invalid_argument les dimensions des deux matrices sont différentes
         */
        Matrice operator+(Matrice& autre) const;
        /**
         * @brief Opérateur: *, Multiplication de la matrice avec un scalaire
         * @param scalaire un scalaire (double)
         * @return matrice multipliée par le scalaire
         */
        Matrice operator*(const double& scalaire) const;
        /**
         * @brief Opérateur: *, Multiplication de la matrice avec une autre matrice
         * @param autre une matrice
         * @return Matrice résultat de la multiplication des deux matrices
         * @exception invalid_argument les dimensions sont incompatibles
         */
        Matrice operator*(Matrice& autre);
        /**
         * @brief Afficher la matrice sur la sortie standard
         */
        void afficher() const;
        /**
         * @brief Calcul du déterminant de la matrice
         * @return Le détermiant de type double
         * @exception invalid_argument la matrice n'est pas carrée
         */
        double determinant() const;
        /**
         * @brief Calcul de la matrice adjointe
         * @return La matrice adjointe de type Matrice
         * @exception invalid_argument la matrice n'est pas carrée
         */
        Matrice matriceAdjointe() const;
        /**
         * @brief Calcul de la transposée
         * @return Transposée de la matrice de type Matrice
         */
        Matrice transpose() const;
        /**
         * @brief Calcul de la matrice inverse (si elle existe)
         * @return Matrice inverse de type matrice
         * @exception invalid_argument le déterminant est nul
        */
        Matrice inverserMatrice() const;
    };
#endif