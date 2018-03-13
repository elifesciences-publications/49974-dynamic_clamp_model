#include <stdlib.h>
#include "input_parser.h"

void
parseInput(int argc, char *const *args, float *voltage, float *frequency, float *conductance, float *reversalPotential,
           float *simulationTime, float *clusterInteraction, float *clusterSize, float *clusterNumber,
           float *timeConstant) {
    int VOLTAGE_IDX = 1;
    int CLUSTER_SIZE_IDX = 2;
    int CLUSTER_NUMBER_IDX = 3;
    int CLUSTER_INTERACTION_IDX = 4;
    int TIME_CONSTANT_IDX = 5;
    int CONDUCTANCE_IDX = 6;
    int POTENTIAL_IDX = 7;
    int FREQUENCY_IDX = 8;
    int SIMULATION_TIME_IDX = 9;

    float VOLTAGE_DEFAULT = 0;
    float FREQUENCY_DEFAULT = 20000;
    float CONDUCTANCE_DEFAULT = 0;
    float POTENTIAL_DEFAULT = 0;
    float CLUSTER_INTERACTION_DEFAULT = 0;
    float CLUSTER_SIZE_DEFAULT = 8;
    float CLUSTER_NUMBER_DEFAULT = 100;
    float TIME_CONSTANT_DEFAULT = 15;
    float SIMULATION_TIME_DEFAULT = 1;

    (*voltage) = readInput(argc, args, VOLTAGE_IDX, VOLTAGE_DEFAULT);
    (*clusterSize) = readInput(argc, args, CLUSTER_SIZE_IDX, CLUSTER_SIZE_DEFAULT);
    (*clusterNumber) = readInput(argc, args, CLUSTER_NUMBER_IDX, CLUSTER_NUMBER_DEFAULT);
    (*clusterInteraction) = readInput(argc, args, CLUSTER_INTERACTION_IDX, CLUSTER_INTERACTION_DEFAULT);
    (*timeConstant) = readInput(argc, args, TIME_CONSTANT_IDX, TIME_CONSTANT_DEFAULT);
    (*conductance) = readInput(argc, args, CONDUCTANCE_IDX, CONDUCTANCE_DEFAULT);
    (*reversalPotential) = readInput(argc, args, POTENTIAL_IDX, POTENTIAL_DEFAULT);
    (*frequency) = readInput(argc, args, FREQUENCY_IDX, FREQUENCY_DEFAULT);
    (*simulationTime) = readInput(argc, args, SIMULATION_TIME_IDX, SIMULATION_TIME_DEFAULT);
}

float readInput(int argc, char *const *string, int idx, float default_value) {
    return (float) (argc >= (idx + 1) ? atof(string[idx]) : default_value);
}