// C headers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// C++ headers
#include <vector>
#include <random>

// Const globals
enum class Global{
	NumInputs = 3,
	NumHiddenNeurons = 3,
	NumOutputs = 1,
	NeuronBiasValue = 1
};

// Data structures
struct Neuron{
	std::vector<double> weights;
	double currentValue;
};

// Forward declarations
void RunNetwork(Neuron *inputNeurons, Neuron *hiddenNeurons, Neuron *outputNeurons);
double ActivationFunc(double x);

int main(){

	// Init std random number generator
	std::random_device r;
	std::uniform_real_distribution<double> unif(0, 1);
	std::default_random_engine re(r());

	// Declare layers and inputs (add 1 for the bias)
	Neuron *inputNeurons = new Neuron[static_cast<int>(Global::NumInputs) + 1];
	Neuron *hiddenNeurons = new Neuron[static_cast<int>(Global::NumHiddenNeurons) + 1];
	Neuron *outputNeurons = new Neuron[static_cast<int>(Global::NumOutputs) + 1]; // Added an extra +1 so that the array would be > 1

	// Randomize weights on all neurons and add biases

	// Initialize first layer
	for(int i = 0; i < static_cast<int>(Global::NumInputs) + 1; i++){ 
		
		// Randomize each neuronal weight
		for(int j = 0; j < static_cast<int>(Global::NumHiddenNeurons); j++){
			inputNeurons[i].weights.push_back(unif(re));
		}

		inputNeurons[i].currentValue = 0;
	}

	// Initialize second layer
	for(int i = 0; i < static_cast<int>(Global::NumHiddenNeurons) + 1; i++){
		for(int j = 0; j < static_cast<int>(Global::NumOutputs); j++){
			hiddenNeurons[i].weights.push_back(unif(re));
		}

		hiddenNeurons[i].currentValue = 0;
	}

	// Zero out output layer values
	for(int i = 0; i < static_cast<int>(Global::NumOutputs) + 1; i++){
		outputNeurons[i].currentValue = 0;
	}

	inputNeurons[static_cast<int>(Global::NumInputs)].currentValue = static_cast<int>(Global::NeuronBiasValue); // Add bias to input layer
	hiddenNeurons[static_cast<int>(Global::NumHiddenNeurons)].currentValue = static_cast<int>(Global::NeuronBiasValue); // Add bias to hidden layer

	////// Test run of network

	// Load test inputs
	inputNeurons[0].currentValue = -.5;
	inputNeurons[1].currentValue = -.9;
	inputNeurons[2].currentValue = .1;
			
	// Run test
	RunNetwork(inputNeurons, hiddenNeurons, outputNeurons);

	// Print results
	printf("%f\n", outputNeurons[0].currentValue);
	getchar();

	////// Test run of network

	// Clean up
	delete[] inputNeurons;
	delete[] hiddenNeurons;
	delete[] outputNeurons;

	return 0;
}

void RunNetwork(Neuron *inputNeurons, Neuron *hiddenNeurons, Neuron *outputNeurons){

	// Iterate over first layer
	for(int i = 0; i < static_cast<int>(Global::NumInputs) + 1; i++){

		// Apply weights to value and add to next layer
		for(int j = 0; j < static_cast<int>(Global::NumHiddenNeurons); j++){
			hiddenNeurons[j].currentValue += inputNeurons[i].currentValue * inputNeurons[i].weights[j];
		}
	}

	// Apply activation function to all values contained in the hidden neuron layer (except bias neuron)
	for(int i = 0; i < static_cast<int>(Global::NumHiddenNeurons); i++){
		hiddenNeurons[i].currentValue = ActivationFunc(hiddenNeurons[i].currentValue);
	} 

	// Iterate over second layer
	for(int i = 0; i < static_cast<int>(Global::NumHiddenNeurons) + 1; i++){

		// Apply weights to value and add to next layer
		for(int j = 0; j < static_cast<int>(Global::NumOutputs); j++){
			outputNeurons[j].currentValue += hiddenNeurons[i].currentValue * hiddenNeurons[i].weights[j];
		}
	}

	// Apply activation function to all values contained in the output neuron layer (except bias neuron)
	for(int i = 0; i < static_cast<int>(Global::NumOutputs); i++){
		outputNeurons[i].currentValue = ActivationFunc(outputNeurons[i].currentValue);
	}
}

double ActivationFunc(double x){
	return tanh(x);
}

