// C headers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// C++ headers
#include <vector>
#include <random>

// Training date, simple wave function
// input -> x
// output -> sin(x)
double TestData[] = {
	0.238656742,	0.236397655,
	0.161762712,	0.161058156,
	0.925049985,	0.798650845,
	0.852369319,	0.752842005,
	0.540492799,	0.514558607,
	0.135999441,	0.135580591,
	0.470343795,	0.453192775,
	0.44546609,		0.430878531,
	0.450596465,	0.435502542,
	0.657177067,	0.610884317,
	0.846612357,	0.749040311,
	0.40013923,		0.389546578,
	0.613382217,	0.575636406,
	0.768732549,	0.695224763,
	0.79960407,		0.717080188,
	0.206687639,	0.20521917,
	0.896416479,	0.781094332,
	0.975575318,	0.828024601,
	0.028595127,	0.02859123,
	0.717894794,	0.657800506,
	0.246993903,	0.244490201,
	0.444395404,	0.429912087,
	0.047398537,	0.047380792,
	0.043393592,	0.043379975,
	0.905720191,	0.786869802,
	0.162074907,	0.161366267,
	0.797946568,	0.71592394,
	0.568953168,	0.538750425,
	0.041420171,	0.041408329,
	0.109570933,	0.109351817,
	0.706671135,	0.649305679,
	0.376603432,	0.367764063,
	0.970888577,	0.8253877,
	0.577193473,	0.545674226,
	0.59586338,		0.561223553,
	0.580959339,	0.548826136,
	0.286184227,	0.282293711,
	0.410447442,	0.399019646,
	0.015967263,	0.015966585,
	0.195393534,	0.194152595,
	0.293973882,	0.289757905,
	0.389020069,	0.379281886,
	0.674166789,	0.624246607,
	0.154727504,	0.154110865,
	0.362573792,	0.354681868,
	0.371940905,	0.363424308,
	0.647477749,	0.60317656,
	0.637257064,	0.5949931,
	0.157442848,	0.156793198,
	0.557907239,	0.529411933,
	0.809147484,	0.723699103,
	0.422486678,	0.410029748,
	0.767160389,	0.694093848,
	0.660286928,	0.613343498,
	0.435894977,	0.42222186,
	0.187281792,	0.186188908,
	0.714463372,	0.655212118,
	0.447439951,	0.432658923,
	0.731984269,	0.668346948,
	0.347122754,	0.340193585,
	0.154967869,	0.154348354,
	0.575006631,	0.543840356,
	0.513870975,	0.491551953,
	0.736603499,	0.671775818,
	0.692083447,	0.63814265,
	0.595772568,	0.561148388,
	0.006150651,	0.006150612,
	0.686337954,	0.633708582,
	0.056053127,	0.056023779,
	0.062276401,	0.062236154,
	0.346891599,	0.339976209,
	0.005555753,	0.005555724,
	0.96927811,		0.824477414,
	0.21124453,		0.209676926,
	0.102616468,	0.102436469,
	0.026459826,	0.026456739,
	0.208821013,	0.20730667,
	0.130025147,	0.129659077,
	0.370109203,	0.361717243,
	0.102587509,	0.102407662,
	0.614953575,	0.576920603,
	0.708745334,	0.650881767,
	0.960951368,	0.819736826,
	0.382827437,	0.373544724,
	0.999231515,	0.841055522,
	0.606081486,	0.569651268,
	0.907960727,	0.788250504,
	0.73023025,		0.667041193,
	0.825655395,	0.734992347,
	0.316720306,	0.311451672,
	0.705485295,	0.64840336,
	0.913297324,	0.791523163,
	0.044643841,	0.044629013,
	0.294950648,	0.29069263,
	0.201012538,	0.199661583,
	0.683471649,	0.631488689,
	0.931968788,	0.802795395,
	0.13100861,		0.130634176,
	0.395381681,	0.385160451,
	0.932181382,	0.802922137,
	0.201708877,	0.200343853,
	0.548348257,	0.521278365,
	0.696277226,	0.641365895,
	0.468060998,	0.451156682,
	0.565554877,	0.535884376,
	0.599288224,	0.564054877,
	0.34144939,		0.33485316,
	0.036442426,	0.03643436,
	0.865478896,	0.761405808,
	0.733392794,	0.669394015,
	0.518555724,	0.49562625,
	0.398311782,	0.387862837,
	0.438875493,	0.424921796,
	0.105137622,	0.104944032,
	0.089008147,	0.088890667,
	0.319751946,	0.314331089,
	0.428222465,	0.415254426,
	0.142922001,	0.142435927,
	0.012380195,	0.012379879,
	0.637989364,	0.595581513,
	0.119756442,	0.119470397,
	0.961160822,	0.819856771,
	0.262598802,	0.259591137,
	0.206551752,	0.205086174,
	0.947981683,	0.812239828,
	0.789579957,	0.710057565,
	0.069828685,	0.069771951,
	0.600530978,	0.565080629,
	0.057946859,	0.057914435,
	0.027739193,	0.027735636,
	0.894371279,	0.77981565,
	0.458263874,	0.442391779,
	0.305292198,	0.300571875,
	0.048197803,	0.048179145,
	0.826252905,	0.735397373,
	0.869677316,	0.764120822,
	0.79326358,		0.712646541,
	0.470282043,	0.453137728,
	0.594172688,	0.559823426,
	0.616159457,	0.577905148,
	0.433658441,	0.420193403,
	0.968912835,	0.824270652,
	0.849406884,	0.750888827,
	0.813514732,	0.726706098,
	0.01395947,		0.013959017,
	0.500057107,	0.479475654,
	0.432478012,	0.419121948,
	0.98139617,		0.831274259,
	0.996288506,	0.839459865,
	0.771807608,	0.697431802,
	0.692684986,	0.63860567,
	0.983413844,	0.832394116,
	0.949181499,	0.812939124,
	0.394074836,	0.383954101,
	0.915776779,	0.79303602,
	0.239237436,	0.23696185,
	0.015540582,	0.015539956,
	0.199193779,	0.197879116,
	0.941091414,	0.808201322,
	0.785682777,	0.707308005,
	0.474912187,	0.457260354,
	0.228550552,	0.226566006,
	0.357705237,	0.350125647,
	0.042773606,	0.042760565,
	0.723586595,	0.662076848,
	0.048642104,	0.048622924,
	0.646862432,	0.602685664,
	0.997403291,	0.840065142,
	0.187680557,	0.186580687,
	0.438748694,	0.424807011,
	0.610872197,	0.573582137,
	0.897041203,	0.781484266,
	0.338083283,	0.331679487,
	0.612215842,	0.574682263,
	0.20131637,		0.199959289,
	0.205619908,	0.204174049,
	0.359045403,	0.351380668,
	0.81590332,		0.72834486,
	0.90546126,		0.786709985,
	0.893117438,	0.779030121,
	0.132584606,	0.132196503,
	0.588120275,	0.554798101,
	0.536893297,	0.511468869,
	0.654249823,	0.608564145,
	0.026068537,	0.026065585,
	0.670342459,	0.621254377,
	0.388701385,	0.378986994,
	0.909196648,	0.789010431,
	0.422869598,	0.410378968,
	0.853147965,	0.753354283,
	0.06582485,		0.065777325,
	0.580645748,	0.548563966,
	0.582464115,	0.550083411,
	0.690166206,	0.636665359,
	0.913713598,	0.791777495,
	0.163101511,	0.162379332,
	0.909318714,	0.78908542,
	0.603242836,	0.567315928,
	0.916751008,	0.79362912,
	0.667981963,	0.619402943,
};

double g_RAND_TABLE[] = {
	0.310872197, 0.473582137,
	0.997041203, 0.781484266,
	0.338083283, 0.331679487,
	0.612215842, 0.574682263,
	0.20131637, 0.199959289,
	0.105619908, 0.904174049,
	0.359045403, 0.251380668,
	0.81590332, 0.72834486,
	0.90546126, 0.486709985,
	0.293117438, 0.779030121,
	0.532584606, 0.132196503,
	0.188120275, 0.554798101,
	0.736893297, 0.511468869,
};

int g_rand_tbl_counter = 0;

// Const globals
namespace Global{
	const int NumInputs = 1;
	const int NumHiddenNeurons = 3;
	const int NumOutputs = 1;
	const int NeuronBiasValue = 1;
	const double Eta = 0.15;
	const double Alpha = 0.5;
};

// Data structures
struct NeuronWeight{
	double weight;
	double deltaWeight;
};

struct Neuron{
	std::vector<NeuronWeight> weights;
	double currentValue;
	double gradientValue;
};

// Forward declarations
void RunNetwork(std::vector<Neuron> &inputNeuronLayer, std::vector<Neuron> &hiddenNeuronLayer, std::vector<Neuron> &outputNeuronLayer);
void TrainNetwork(std::vector<Neuron> &inputNeuronLayer, std::vector<Neuron> &hiddenNeuronLayer, std::vector<Neuron> &outputNeuronLayer, double *correctOutputValues);

double ActivationFunc(double x);
double ActivationFuncDx(double x);

void Dbg_PrintNeuronSummary(const Neuron &neuron){
	int i = 0;
	
	printf("Current value: [%f]\nGradient value: [%f]\nWeights: ", neuron.currentValue, neuron.gradientValue);
	for(const NeuronWeight &weight : neuron.weights){
		printf("[%f] -> [%d], ", weight.weight, i++);
	}
	printf("\nDelta weights: ");

	i = 0;
	for(const NeuronWeight &weight : neuron.weights){
		printf("[%f] -> [%d], ", weight.deltaWeight, i++);
	}
	puts("\n------------------------------------------------------");
}

int main(){

	// Initialize std random number generator
	std::random_device r;
	std::uniform_real_distribution<double> unif(0, 1);
	std::default_random_engine re(r());

	// Declare layers and inputs (add 1 for the bias in the first and second layers)
	std::vector<Neuron> inputNeuronsLayer(static_cast<int>(Global::NumInputs) + 1);
	std::vector<Neuron> hiddenNeuronsLayer(static_cast<int>(Global::NumHiddenNeurons) + 1);
	std::vector<Neuron> outputNeuronsLayer(static_cast<int>(Global::NumOutputs));

	// Initialize random weights for the input and hidden layers
	for(Neuron &neuron : inputNeuronsLayer){

		// Each neuron has {i} number of of weights (equal to the number of neurons in the next layer, not including the bias)
		for(int i = 0; i < static_cast<int>(Global::NumHiddenNeurons); i++){
			struct NeuronWeight weight = {unif(re), 0}; // Push random weights in [0.0, 1.0]
			//struct NeuronWeight weight = {g_RAND_TABLE[g_rand_tbl_counter++], 0};
			neuron.weights.push_back(weight); 
			neuron.gradientValue = 0;
		}
	}

	for(Neuron &neuron : hiddenNeuronsLayer){
		for(int i = 0; i < static_cast<int>(Global::NumOutputs); i++){
			struct NeuronWeight weight = {unif(re), 0};
			//struct NeuronWeight weight = {g_RAND_TABLE[g_rand_tbl_counter++], 0};
			neuron.weights.push_back(weight);
		}
	}

	// Add bias constants
	inputNeuronsLayer.back().currentValue = 1;
	hiddenNeuronsLayer.back().currentValue = 1;
	
	// Test run of network [1-2-1]
	for(int i = 0; i < 398; i += 2){
		double *ptr = TestData + i + 1;
		inputNeuronsLayer[0].currentValue = TestData[i];

		RunNetwork(inputNeuronsLayer, hiddenNeuronsLayer, outputNeuronsLayer);
		TrainNetwork(inputNeuronsLayer, hiddenNeuronsLayer, outputNeuronsLayer, ptr);
		
		// Print out all the neurons
		//puts("[Input Neuron]");
		//Dbg_PrintNeuronSummary(inputNeuronsLayer[0]);

		//puts("[Input Bias]");
		//Dbg_PrintNeuronSummary(inputNeuronsLayer[1]);

		//puts("[Hidden Neuron #1]");
		//Dbg_PrintNeuronSummary(hiddenNeuronsLayer[0]);

		//puts("[Hidden Neuron #2]");
		//Dbg_PrintNeuronSummary(hiddenNeuronsLayer[1]);

		//puts("[Hidden Bias]");
		//Dbg_PrintNeuronSummary(hiddenNeuronsLayer[2]);

		//puts("[Output Neuron]");
		//Dbg_PrintNeuronSummary(outputNeuronsLayer[0]);
		//puts("\n");
		printf("in x:[%f] -> out sin(x):[%f]  TARGET:[%f]\n", inputNeuronsLayer[0].currentValue, outputNeuronsLayer[0].currentValue, *ptr);
	}

	// Calculate RMS from outputs
	//double sqDiff = 0;

	//for(int i = 0; i < static_cast<int>(Global::NumOutputs); i++){
	//	double diff = *ptr - outputNeuronsLayer[i].currentValue;
	//	sqDiff += diff * diff;
	//}

	//double RMS = sqrt(sqDiff / static_cast<int>(Global::NumOutputs));

	//printf("RMS Error: %f\n", RMS);

	getchar();

	return 0;
}

void RunNetwork(std::vector<Neuron> &inputNeuronLayer, std::vector<Neuron> &hiddenNeuronLayer, std::vector<Neuron> &outputNeuronLayer){

	// Clear old values (except for biases
	for(Neuron &neuron : outputNeuronLayer) neuron.currentValue = 0;
	for(int i = 0; i < static_cast<int>(Global::NumHiddenNeurons); i++){
		hiddenNeuronLayer[i].currentValue = 0;
	}

	// Apply weights to value and add to the next layer's neurons (input layer -> hidden layer)
	for(Neuron &neuron : inputNeuronLayer){
		for(int i = 0; i < neuron.weights.size(); i++){
			hiddenNeuronLayer[i].currentValue += neuron.currentValue * neuron.weights[i].weight;
		}
	}

	// Apply activation function to all values contained in the hidden neuron layer (except bias neuron)
	for(int i = 0; i < static_cast<int>(Global::NumHiddenNeurons); i++){
		hiddenNeuronLayer[i].currentValue = ActivationFunc(hiddenNeuronLayer[i].currentValue);
	}

	// Same stuff, but for hidden layer -> output layer
	for(Neuron &neuron : hiddenNeuronLayer){
		for(int i = 0; i < neuron.weights.size(); i++){
			outputNeuronLayer[i].currentValue += neuron.currentValue * neuron.weights[i].weight;
		}
	}

	// Apply activation function to all values contained in the hidden neuron layer (except bias neuron)
	for(int i = 0; i < static_cast<int>(Global::NumOutputs); i++){
		outputNeuronLayer[i].currentValue = ActivationFunc(outputNeuronLayer[i].currentValue);
	}
}

void TrainNetwork(std::vector<Neuron> &inputNeuronLayer, std::vector<Neuron> &hiddenNeuronLayer, std::vector<Neuron> &outputNeuronLayer, double *correctOutputValues){
	int i = 0;

	// Calculate output layer gradients
	for(Neuron &neuron : outputNeuronLayer){
		neuron.gradientValue = (correctOutputValues[i++] - neuron.currentValue) * ActivationFuncDx(neuron.currentValue);
	}

	// Calculate hidden layer gradients
	for(Neuron &neuron : hiddenNeuronLayer){
		double summation = 0;

		// It's a summation of all weights times their respective output neuron's gradient
		for(int j = 0; j < static_cast<int>(Global::NumOutputs); j++){
			summation += neuron.weights[j].weight * outputNeuronLayer[j].gradientValue;
		}

		neuron.gradientValue = summation * ActivationFuncDx(neuron.currentValue);
	}

	// Now update weights for input layer and hidden layer

	// Start with the hidden layer
	for(int i = 0; i < static_cast<int>(Global::NumOutputs); i++){

		// Loop over preceding layer's neurons (input layer)
		for(int j = 0; j < static_cast<int>(Global::NumHiddenNeurons) + 1; j++){

			// Get the delta weight from the preceding neuron that goes into the current hidden neuron
			double oldDeltaWeight = hiddenNeuronLayer[j].weights[i].deltaWeight;
			double newDeltaWeight = Global::Eta	* hiddenNeuronLayer[j].currentValue * outputNeuronLayer[i].gradientValue + Global::Alpha * oldDeltaWeight;

			hiddenNeuronLayer[j].weights[i].deltaWeight = newDeltaWeight;
			hiddenNeuronLayer[j].weights[i].weight += newDeltaWeight;
		}
	}

	// Now do input layer
	for(int i = 0; i < static_cast<int>(Global::NumHiddenNeurons); i++){
		for(int j = 0; j < static_cast<int>(Global::NumInputs) + 1; j++){
			double oldDeltaWeight = inputNeuronLayer[j].weights[i].deltaWeight;
			double newDeltaWeight = Global::Eta * inputNeuronLayer[j].currentValue * hiddenNeuronLayer[i].gradientValue + Global::Alpha * oldDeltaWeight;

			inputNeuronLayer[j].weights[i].deltaWeight = newDeltaWeight;
			inputNeuronLayer[j].weights[i].weight += newDeltaWeight;
		}
	}
}

double ActivationFunc(double x){
	return tanh(x);
}

double ActivationFuncDx(double x){
	return 1.0 - x * x;
}
