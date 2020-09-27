//
// Created by guyna25 on 18/12/2019.
//
#include <new>
#include "Matrix.h"
#include <iostream>

#define MEMORY_ALLOCATION_FAILURE "Matrix memory allocation failed"
#define ILLEGAL_MULTIPLICAITION_ERROR "Multiplicaition requires left cols match right cols number"
#define ILLEGAL_ADDITION_ERROR "Addition requires same size matrices"
#define INPUT_ERROR "Input has to match exact matrix dims"
#define ILLEGAL_MATRIX_INDEX "Matrix index has to be in range [0, number of elements - 1]"
#define ILLEGAL_MATRIX_DIMENSION "Matrix dimension have to be natrual numbers"

const int DEFAULT_COLS  = 1;
const int DEFAULT_ROWS  = 1;
const float DEFAULT_ELEMENT  = 0.0;
const char ERROR_PREFIX[] = "Error:";

/**
 * empty constructor for this class
 */

Matrix::Matrix()
{
    _matrixDims = MatrixDims{DEFAULT_ROWS, DEFAULT_COLS};
    _matrix = new (std::nothrow) float[DEFAULT_ROWS * DEFAULT_COLS];
    if (_matrix == nullptr)
    {
        errorExit(MEMORY_ALLOCATION_FAILURE);
    }
    _matrix[0] = DEFAULT_ELEMENT;
}

/**
 * @brief constructor for this class
 * @param rows number of rows in matrix
 * @param cols number of cols in matrix
 */

Matrix::Matrix(int rows, int cols)
{
    if (rows < 1 || cols < 1)
    {
        errorExit(ILLEGAL_MATRIX_DIMENSION);
    }
    _matrixDims = MatrixDims{rows, cols};
    _matrix = new (std::nothrow) float[rows * cols];
    if (_matrix == nullptr)
    {
        errorExit(MEMORY_ALLOCATION_FAILURE);
    }
    for (int i = 0; i<(rows*cols); i++)
    {
        _matrix[i] = 0.0;
    }
}

/**
 * @brief copy constructor for this class
 * @param m the matrix to be copied
 */

Matrix::Matrix(Matrix &m): Matrix::Matrix(m.getRows(), m.getCols())
{
    for (int i = 0; i<(m.getRows() * m.getCols()); i++)
    {
        _matrix[i] = m[i];
    }
};

/**
 * @brief copy constructor for this class
 * @param m the matrix to be copied
 */

Matrix::Matrix(const Matrix &m): Matrix::Matrix(m.getRows(), m.getCols())
{
    for (int i = 0; i<(m.getRows() * m.getCols()); i++)
    {
        _matrix[i] = m[i];
    }
};

/**
 * @brief destructor for this class
 */

Matrix::~Matrix()
{
    delete[] _matrix;
}

/**
 * @brief getter method for rows
 * @return number of rows in the matrix
 */

int Matrix::getRows()
{
    return this->_matrixDims.rows;
}

/**
 * @brief getter method for cols
 * @return number of cols in the matrix
 */

int Matrix::getCols()
{
    return this->_matrixDims.cols;
}

/**
 * @brief getter method for rows
 * @return number of rows in the matrix
 */

int Matrix::getRows() const
{
    return this->_matrixDims.rows;
}

/**
 * @brief getter method for cols
 * @return number of cols in the matrix
 */

int Matrix::getCols() const
{
    return this->_matrixDims.cols;
}

/**
 * @brief prints the matrix as is
 */

void Matrix::plainPrint() const
{
    for (int r = 0; r < getRows(); r++)
    {
        for (int c = 0; c < getCols(); c++)
        {
            std::cout << (*this)(r, c) << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * @brief getter operator for matrix i,j value
 * @param i row index
 * @param j col index
 * @return the (i,j) value in the matrix
 */

float& Matrix::operator() (int i, int j)
{
    if (i < 0 || i >= getRows() || j >= getCols() || j < 0)
    {
        errorExit("array indexes must be non-negative");
    }
    return _matrix[_matrixDims.cols * i + j];
}

/**
 * @brief multiplies the matrix by a scalar
 * @param factor the factor to multiply by
 * @return the matrix after multiplication
 */

Matrix Matrix::operator * (float factor) const
{
    Matrix newMatrix(*this);
    for (int i = 0; i<this->getRows() * this->getCols(); i++)
    {
        newMatrix[i] *= factor;
    }
    return newMatrix;
}

/**
 * @brief matrix multiplication operator
 * @param other the matrix to multiply with
 * @return the result of the multiplication
 */

Matrix Matrix::operator * (Matrix const &other) const
{
    if (getCols() != other.getRows())
    {
        errorExit(ILLEGAL_MULTIPLICAITION_ERROR);
    }
    Matrix newMatrix(getRows(), other.getCols());
    for (int r = 0; r < getRows(); r++)
    {
        for (int c = 0; c < other.getCols(); c++)
        {
            for (int i = 0; i < getCols(); i++)
            {
                newMatrix(r, c) += (*this)(r, i) * other(i, c);
            }
        }
    }
    return newMatrix;
}

/**
 * @brief getter operator for matrix i,j value
 * @param i row index
 * @param j col index
 * @return the (i,j) value in the matrix
 */


float& Matrix::operator()(int i, int j) const
{
    if (i < 0 || j < 0 || i >= getRows() || j >= getCols())
    {
        errorExit(ILLEGAL_MATRIX_INDEX);
    }
    return _matrix[_matrixDims.cols * i + j];
}

/**
 * @brief matrix multiplication operator
 * @param matrix the matrix to multiply with
 * @return the result of the multiplication
 */


Matrix operator * (const float &factor, const Matrix &matrix)
{
    Matrix newMatrix(matrix);
    for (int i = 0; i<matrix.getRows() * matrix.getCols(); i++)
    {
        newMatrix[i] *= factor;
    }
    return newMatrix;
}

/**
 * @brief turns matrix into vector where all cols are concatenated
 * @return the matrix in vector form
 */

Matrix& Matrix::vectorize()
{
    this->_matrixDims.rows = this->_matrixDims.rows * this->_matrixDims.cols;
    this->_matrixDims.cols = 1;
    return *this;
}

/**
 * @brief addition operator for matrices
 * @param other the matrix to add to
 * @return the result of the addition
 */

Matrix Matrix::operator + (Matrix const &other) const
{
    if ((getRows() != other.getRows()) || (getCols() != other.getCols()))
    {
        errorExit(ILLEGAL_ADDITION_ERROR);
    }
    Matrix newMatrix(getRows(), getCols());
    for (int i = 0; i<getRows() * getCols(); i++)
    {
        newMatrix[i] = _matrix[i] + other._matrix[i];
    }
    return newMatrix;
}

/**
 * @brief addition operator for matrices
 * @param other the matrix to add to
 * @return the result of the addition
 */

Matrix Matrix::operator + (Matrix const &other)
{
    if ((getRows() != other.getRows()) || (getCols() != other.getCols()))
    {
        errorExit(ILLEGAL_ADDITION_ERROR);
    }
    Matrix newMatrix(getRows(), getCols());
    for (int i = 0; i<getRows() * getCols(); i++)
    {
        newMatrix[i] = _matrix[i] + other._matrix[i];
    }
    return newMatrix;
}

/**
 * @brief equal operator for matrices
 */

Matrix& Matrix::operator = (const Matrix &other)
{
    if (this == &other) //matrix is the same as copied one so no need to copy
    {
        return *this;
    }
    delete[] _matrix;
    _matrixDims.rows = other.getRows();
    _matrixDims.cols = other.getCols();
    _matrix = new float[other.getRows() * other.getCols()];
    for(int i = 0; i < other.getRows() * other.getCols(); i++)
    {
       _matrix[i] = other[i];
    }
    return *this;
}

/**
 * @brief matrix addition in place
 * @param other the matrix to add to current matrix
 * @return the result of the in place addition
 */

Matrix &Matrix::operator += (Matrix const &other)
{
    for (int i = 0; i<getRows() * getCols(); i++)
    {
        this->_matrix[i] += other._matrix[i];
    }
    return *this;
}

/**
 * @brief getter operator for i'th value
 * @param i the wanted index
 * @return the i'th value in the matrix
 */

float& Matrix::operator[](const int i)
{
    if (i < 0 || i >= getRows() * getCols())
    {
        errorExit(ILLEGAL_MATRIX_INDEX);
    }
    return _matrix[i];
}

/**
 * @brief getter operator for i'th value
 * @param i the wanted index
 * @return the i'th value in the matrix
 */

float& Matrix::operator[](const int i) const
{
    if (i < 0 || i >= getRows() * getCols())
    {
        errorExit(ILLEGAL_MATRIX_INDEX);
    }
    return _matrix[i];
}

/**
 * @brief output operator for the matrix
 * @param out the out stream
 * @param m the output matrix
 * @return out stream
 */

std::ostream &operator << (std::ostream &out, const Matrix &m)
{
    int mRows = m.getRows();
    int mCols = m.getCols();
    for (int i = 0; i < mRows; i++)
    {
        for (int j = 0; j < mCols; j++)
        {

            if (m._matrix[mCols * i + j] <= 0.1f)
            {
               out << "  ";
            }
            else
            {
                out << "**";
            }
        }
        out << std::endl;
    }
    return out;
}

/**
 * @brief input operator for matrix
 * @param in the input stream object
 * @param m the input matrix
 * @return in stream
 */

std::istream& operator >> (std::istream &in, Matrix &m)
{
    int elemntIndex = 0;
    char buffer[4];

    while (in.good() && in.read(buffer, sizeof(float)) &&
           elemntIndex < m.getRows()*m.getCols())
    {
        auto *inValue = (float*)buffer;
        m[elemntIndex] = *inValue;
        elemntIndex++;
    }
    if (elemntIndex != (m.getRows() * m.getCols())) // number of elements is not exactly as
        // matrix
    {
        m.errorExit(INPUT_ERROR);
    }
    return in;
}

/**
 * @brief method for exit in case of error
 * @param errorMessage the error message to print
 */

void Matrix::errorExit(const std::string& errorMessage)
{
    std::cerr << ERROR_PREFIX << errorMessage << std::endl;
    exit(EXIT_FAILURE);
}
