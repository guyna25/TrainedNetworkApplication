//
// Created by guyna25 on 19/12/2019.
//
#include "Dense.h"

/**
 * @brief constrcutor for the dense class
 * @param w the dense' weights
 * @param bias the dense biases
 * @param actType the activation type
 */

Dense::Dense(Matrix w, Matrix bias, ActivationType actType)
{
    this->weights = w;
    this->bias = bias;
    this->activationFunc = Activation(actType);
}

/**
 * @brief getter method for weights
 * @return the weights of dense
 */

Matrix Dense::getWeights() const
{
    return this->weights;
}

/**
 * @brief getter method for biases
 * @return the biases of dense
 */

Matrix Dense::getBias() const
{
    return this->bias;
}

/**
 * @brief getter method for activation
 * @return the activation of dense
 */

Activation Dense::getActivation() const
{
    return activationFunc;
}

/**
 * @brief activates the layer on input
 * @param input the matrix to operate om
 * @return result of operation on matrix
 */

Matrix Dense::operator()(Matrix input) const
{
    return activationFunc(((this->weights * input) + bias));
}
