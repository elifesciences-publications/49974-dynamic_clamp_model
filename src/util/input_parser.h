//
// Created by Paul Pfeiffer on 12.12.16.
//

#ifndef DYNAMIC_CLAMP_MODELS_INPUT_PARSER_H
#define DYNAMIC_CLAMP_MODELS_INPUT_PARSER_H

void
parseInput(int argc, char *const *args, float *voltage, float *frequency, float *conductance, float *reversalPotential,
           float *simulationTime, float *clusterInteraction, float *clusterSize, float *clusterNumber,
           float *timeConstant);

float readInput(int argc, char *const *string, int idx, float default_value);

#endif //DYNAMIC_CLAMP_MODELS_INPUT_PARSER_H
