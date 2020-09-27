//MlpNetwork.h

#include "Dense.h"

#define MLP_SIZE 4

#include "Digit.h"

const MatrixDims imgDims = {28, 28};
const MatrixDims weightsDims[] = {{128, 784}, {64, 128}, {20, 64}, {10, 20}};
const MatrixDims biasDims[]    = {{128, 1}, {64, 1}, {20, 1},  {10, 1}};

/**
 * @brief This class represents a machine learning network
 */

class MlpNetwork
{
public:

    /**
 * @brief Constructor for mlp class
 * @param weights input weights for it's weights, number should match number of biases
 * @param biases input biases for it's biases
 */

    MlpNetwork(Matrix weights[], Matrix biases[]);

    //operators overloads
    /**
 * @brief Activates the network on the given matrix
 * @param input the matrix for the network
 * @return digit struct which contains the predicted digit and the probability for the match
 */
    Digit operator () (Matrix input);

private:
    Dense firstLayer;
    Dense secondLayer;
    Dense thirdLayer;
    Dense fourthLayer;
};