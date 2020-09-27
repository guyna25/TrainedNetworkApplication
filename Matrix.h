// Matrix.h

#include <iostream>

#ifndef MATRIX_H
#define MATRIX_H


/**
 * @struct MatrixDims
 * @brief Matrix dimensions container
 */
typedef struct MatrixDims
{
    int rows, cols;
} MatrixDims;

/**
 * @brief this class represents a matrix in m x n space
 */

class Matrix
{
public:

    /**
     * @brief default constructor for this class
     */
    Matrix();

    /**
     * @brief constrcutor with matrix dims for this class
     * @param rows row size of the matrix
     * @param cols cols size for this class
     */
    Matrix(int rows, int cols);

    /**
     * @brief copy constructor for this class
     * @param m the matrix to be copied
     */
    Matrix(Matrix &m);

    /**
     * @brief copy constructor for this class
     * @param m the matrix to be copied
     */
    Matrix(const Matrix &m);

    /**
     * @brief destrcutor for this class
     */
    ~Matrix();

    /**
    * @brief getter method for rows
    * @return number of rows in the matrix
     */
    int getRows();

    /**
    * @brief getter method for cols
    * @return number of cols in the matrix
     */

    int getCols();

    /**
    * @brief getter method for rows
    * @return number of rows in the matrix
     */
    int getRows() const ;

    /**
    * @brief getter method for cols
    * @return number of cols in the matrix
     */

    int getCols() const ;

    /**
    * @brief turns matrix into vector where all cols are concatenated
    * @return the matrix in vector form
    */
    Matrix& vectorize();

    /**
    * @brief prints the matrix as is
     */
    void plainPrint() const;

    /**
    * @brief method for exit in case of error
    * @param errorMessage the error message to print
     */
    static void errorExit(const std::string& errorMessage);

    //operators overloads

/**
 * @brief equal operator for matrices
 */

    Matrix& operator = (const Matrix& other);

/**
 * @brief matrix multiplication operator
 * @param matrix the matrix to multiply with
 * @return the result of the multiplication
 */

    friend Matrix operator * (const float &factor, const Matrix &matrix);

    /**
    * @brief matrix multiplication operator
    * @param other the matrix to multiply with
    * @return the result of the multiplication
    */
    Matrix operator * (Matrix const &other) const;

    /**
    * @brief matrix multiplication operator
    * @param factor the factor to multiply with
    * @return the result of the multiplication
    */
    Matrix operator * (float factor) const;

    /**
    * @brief addition operator for matrices
    * @param other the matrix to add to
    * @return the result of the addition
     */
    Matrix operator + (Matrix const &other);

    /**
    * @brief addition operator for matrices
    * @param other the matrix to add to
    * @return the result of the addition
     */
    Matrix operator + (Matrix const &other) const ;

    /**
    * @brief matrix addition in place
    * @param other the matrix to add to current matrix
    * @return the result of the in place addition
    */
    Matrix& operator += (Matrix const &other);

    /**
    * @brief getter operator for matrix i,j value
    * @param i row index
    * @param j col index
    * @return the (i,j) value in the matrix
     */
    float& operator () (int i, int j);

    /**
    * @brief getter operator for matrix i,j value
    * @param i row index
    * @param j col index
    * @return the (i,j) value in the matrix
     */
    float& operator () (int i, int j) const ;

    /**
    * @brief getter operator for i'th value
    * @param i the wanted index
    * @return the i'th value in the matrix
     */
    float& operator [] (const int i);

    /**
    * @brief getter operator for i'th value
    * @param i the wanted index
    * @return the i'th value in the matrix
     */
    float& operator [] (const int i) const ;

    /**
    * @brief input operator for matrix
    * @param in the input stream object
    * @param m the input matrix
    * @return in stream
    */
    friend std::istream&operator >> (std::istream& in, Matrix& m);

    /**
    * @brief output operator for the matrix
    * @param out the out stream
    * @param m the output matrix
    * @return out stream
    */
    friend std::ostream& operator << (std::ostream& out, const Matrix& m);

private:
    MatrixDims _matrixDims;
    float *_matrix;

};

#endif