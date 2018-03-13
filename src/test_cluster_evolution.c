
#include <stdio.h>

#include "util/input_parser.h"
#include "dynclamp_models/model.h"

float loopInterval = 0;

float *lookupx[0];

void mock_generating_lookup_table();

void write_cluster_state_to_file(FILE *fp);

void write_time_to_file(FILE *pFILE, float time);

void mock_generating_lookup_table() {
    int table_enumerator[1];
    float **dummy_y = NULL;
    generateLookupTable(0, lookupx, dummy_y, table_enumerator);

}

void write_cluster_state_to_file(FILE *fp) {
    int clusterSize = getClusterSize();
    for (int i = 0; i <= clusterSize; i++) {
        fprintf(fp, "%d ", getClusterState(i));
    }
    fprintf(fp, "\n");
}


void write_time_to_file(FILE *fp, float time) {
    fprintf(fp, "%9.6f ", time);

}

int main(int argc, char **args) {

    float voltage;
    float frequency;
    float conductance;
    float reversalPotential;
    float clusterInteraction;
    float simulationTime;
    float clusterSize;
    float clusterNumber;
    float timeConstant;

    float vhalf;
    int VHALF_IDX = 10;
    float VHALF_DEFAULT = (float) -1.0;
    vhalf = readInput(argc, args, VHALF_IDX, VHALF_DEFAULT);

    int state_to_populate;
    int STATE_IDX = 11;
    float STATE_DEFAULT = 0;
    state_to_populate = (int) readInput(argc, args, STATE_IDX, STATE_DEFAULT);

    parseInput(argc, args, &voltage, &frequency, &conductance, &reversalPotential, &simulationTime, &clusterInteraction,
               &clusterSize, &clusterNumber, &timeConstant);

    int number_of_trials = (int) (simulationTime * frequency);

    float loopInterval = 1 / frequency;
    setLoopInterval(loopInterval);
    mock_generating_lookup_table();

    FILE *fp;


    initModel();
    setConductance(conductance);
    setReversalPotential(reversalPotential);
    setClusterInteraction(clusterInteraction);
    setTimeConstant(timeConstant);
    setClusterSize(clusterSize);
    setClusterNumber(clusterNumber);
    setVhalf(vhalf);
    setClusterInit(state_to_populate);

    setVoltage(voltage);

    char *filename = "./cluster_states.txt";
    fp = fopen(filename, "w");

    for (int i = 0; i < number_of_trials; i++) {
        write_time_to_file(fp, i * loopInterval);
        write_cluster_state_to_file(fp);
        computeModel();
    }
    fclose(fp);
    return 0;
}



