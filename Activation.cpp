//
// Created by guyna25 on 19/12/2019.
//
#include "Activation.h"
#include <cmath>

#define ILLEGAL_ACTIVATION_TYPE "Activation type should be relu or softmax"

/**
 * @brief relu activation function
 * @param vector the vector to activate on
 * @return x if it's positive and 0 otherwise
 */

Matrix relu(Matrix vector)
{
    Matrix resultVector(vector);
    for (int i = 0; i<vector.getRows(); i++)
    {
        resultVector[i]  = resultVector[i] < 0.0 ? 0 : resultVector[i];
    }
    return resultVector;
}

/**
 * @brief softmax activation function
 * @param vector the vector to activate on
 * @return new vector with softmax on it
 */

Matrix softmax(Matrix vector)
{
    float coordinateExpSUm = 0;
    Matrix resultVector(vector);
    for (int i = 0; i<vector.getRows(); i++)
    {
        resultVector[i] = std::exp(vector[i]);
        coordinateExpSUm += resultVector[i];
    }
    for (int i = 0; i<vector.getRows(); i++)
    {
        resultVector[i]  /= coordinateExpSUm;
    }
    return resultVector;
}

/**
 * @brief constructor for activation class
 * @param actType the type of activation for this class
 */

Activation::Activation(ActivationType actType)
{
    if (actType != Relu && actType != Softmax)
    {
        Matrix::errorExit(ILLEGAL_ACTIVATION_TYPE);
    }
    activationType = actType;
}

/**
 * @brief getter method for activation type
 * @return the type of activation
 */

ActivationType Activation::getActivationType()
{
    return activationType;
}

/**
 * @brief getter method for activation type
 * @return the type of activation
 */

ActivationType Activation::getActivationType() const
{
    return activationType;
}

/**
 * @brief activates this activation func on a matrix
 * @param input matrix to operate on
 * @return the matrix after operation
 */

Matrix Activation::operator()(const Matrix input)
{
    if (getActivationType() == Relu)
    {
        return relu(input);
    }
    else
    {
        return softmax(input);
    }
}

/**
 * @brief activates this activation func on a matrix
 * @param input matrix to operate on
 * @return the matrix after operation
 */

Matrix Activation::operator()(const Matrix input) const
{
    if (getActivationType() == Relu)
    {
        return relu(input);
    }
    else
    {
        return softmax(input);
    }
}

/**
 * @brief empty constructor for this class
 */

Activation::Activation()
{}

