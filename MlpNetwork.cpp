//
// Created by guyna25 on 19/12/2019.
//

#include "MlpNetwork.h"

#define WEIGHTS_DIMS_ERROR "Weights dims should match exercise description"
#define BIASES_DIMS_ERROR "Bias dims should match exercise description"
#define INPUT_DIMS_ERROR "Input vector dims should be 784 on 1"

/**
 * @brief Constructor for mlp class
 * @param weights input weights for it's weights, number should match number of biases
 * @param biases input biases for it's biases
 */

MlpNetwork::MlpNetwork(Matrix *weights, Matrix *biases): firstLayer(weights[0], biases[0],
        Relu), secondLayer(weights[1], biases[1], Relu), thirdLayer(weights[2],
                biases[2], Relu), fourthLayer(weights[3], biases[3], Softmax)
{
    for (int i = 0; i<MLP_SIZE; i++)
    {
        if ((weights[i].getRows() != weightsDims[i].rows) || (weights[i].getCols() !=
            weightsDims[i].cols))
        {
            Matrix::errorExit(WEIGHTS_DIMS_ERROR);
        }
        if ((biases[i].getRows() != biasDims[i].rows) || (biases[i].getCols() !=
            biasDims[i].cols))
        {
            Matrix::errorExit(BIASES_DIMS_ERROR);
        }
    }
}

/**
 * @brief Activates the network on the given matrix
 * @param input the matrix for the network
 * @return digit struct which contains the predicted digit and the probability for the match
 */

Digit MlpNetwork::operator()(Matrix input)
{
    if (input.getRows() != imgDims.rows*imgDims.cols || input.getCols() != 1)
    {
        Matrix::errorExit(INPUT_DIMS_ERROR);
    }
    input.vectorize();
    Matrix resultVector = firstLayer(input);
    resultVector = secondLayer(resultVector);
    resultVector = thirdLayer(resultVector);
    resultVector = fourthLayer(resultVector);
    unsigned int number = -1;
    float probability = -1;
    unsigned int rows = resultVector.getRows();
    for (unsigned int i = 0; i < rows; i++)
    {
        if (resultVector[i] > probability)
        {
            number = i;
            probability = resultVector[i];
        }
    }
    return Digit{number, probability};
}


