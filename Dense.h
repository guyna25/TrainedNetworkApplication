//
// Created by guyna25 on 18/12/2019.
//

#include "Activation.h"

#ifndef DENSE_H
#define DENSE_H

/**
 * @brief this class represents a layer in a ml network
 */
class Dense
{
public:

    /**
 * @brief constrcutor for the dense class
 * @param w the dense' weights
 * @param bias the dense biases
 * @param actType the activation type
 */

    Dense(Matrix w, Matrix bias, ActivationType actType);

    /**
 * @brief getter method for weights
 * @return the weights of dense
 */

    Matrix getWeights() const;

    /**
 * @brief getter method for biases
 * @return the biases of dense
 */
    Matrix getBias() const;

    /**
 * @brief getter method for activation
 * @return the activation of dense
 */
    Activation getActivation() const;

    //operators overloads

    /**
 * @brief activates the layer on input
 * @param input the matrix to operate om
 * @return result of operation on matrix
 */

    Matrix operator () (Matrix input) const ;

private:
    Matrix weights;
    Matrix bias;
    Activation activationFunc;
};

#endif