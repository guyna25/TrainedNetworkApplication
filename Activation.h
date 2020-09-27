//Activation.h

#include "Matrix.h"

#ifndef ACTIVATION_H
#define ACTIVATION_H

/**
 * @enum ActivationType
 * @brief Indicator of activation function.
 */
enum ActivationType
{
    Relu,
    Softmax
};

/**
 * @brief THis class represents the activation function on a given matrix
 */
class Activation
{
public:

    /**
 * @brief empty constructor for this class
 */

    Activation();

    /**
 * @brief constructor for activation class
 * @param actType the type of activation for this class
 */
    Activation(ActivationType actType);

    /**
 * @brief getter method for activation type
 * @return the type of activation
 */

    ActivationType getActivationType();

    /**
 * @brief getter method for activation type
 * @return the type of activation
 */

    ActivationType getActivationType() const ;

    //operators overloads

    /**
 * @brief activates this activation func on a matrix
 * @param input matrix to operate on
 * @return the matrix after operation
 */
    Matrix operator () (const Matrix input);

    /**
 * @brief activates this activation func on a matrix
 * @param input matrix to operate on
 * @return the matrix after operation
 */
    Matrix operator () (const Matrix input) const ;

private:
    ActivationType activationType;
};

#endif