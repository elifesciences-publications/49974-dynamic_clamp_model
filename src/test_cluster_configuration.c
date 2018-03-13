#include <stdio.h>
#include "dynclamp_models/model.h"

float loopInterval = 0;

float *lookupx[0];

void mock_generating_lookup_table();

void write_cluster_state_to_file(FILE *pFILE);

void set_cluster_config_and_evolve(float clusterSize, float clusterNumber);

void print_expected_and_actual_states_after_cluster_config_setting(float clusterSize, float clusterNumber,
                                                                   const char *expected_states);

void mock_generating_lookup_table() {
    int table_enumerator[1];
    float **dummy_y = NULL;
    generateLookupTable(0, lookupx, dummy_y, table_enumerator);

}

void write_cluster_state_to_terminal() {
    int clusterSize = getClusterSize();
    for (int i = 0; i <= clusterSize; i++) {
        printf("%d ", getClusterState(i));
    }
    printf("\n");
}


int main() {

    int number_of_trials = 6;

    float voltage = -100;
    float conductance = 20;
    float reversalPotential = 40;
    float clusterInteraction = 10;
    float clusterSize = 8;
    float clusterNumber = 100;
    float timeConstant = 15;

    float frequency = 20000;
    setLoopInterval(1 / frequency);
    mock_generating_lookup_table();

    initModel();
    setConductance(conductance);
    setReversalPotential(reversalPotential);
    setClusterInteraction(clusterInteraction);
    setTimeConstant(timeConstant);
//    setClusterSize(size);
//    setClusterNumber(number);


    setVoltage(voltage);

    print_expected_and_actual_states_after_cluster_config_setting(clusterSize, clusterNumber, "100 0 0 0 0 0 0 0 0\n");

    clusterSize = 5;
    print_expected_and_actual_states_after_cluster_config_setting(clusterSize, clusterNumber, "100 0 0 0 0 0 \n");

    clusterNumber = 1;
    print_expected_and_actual_states_after_cluster_config_setting(clusterSize, clusterNumber, "1 0 0 0 0 0\n");

    clusterSize = 2;
    clusterNumber = 5;
    print_expected_and_actual_states_after_cluster_config_setting(clusterSize, clusterNumber, "5 0 0\n");

    clusterSize = 0;
    print_expected_and_actual_states_after_cluster_config_setting(clusterSize, clusterNumber, "5 0\n");

    clusterSize = 100;
    print_expected_and_actual_states_after_cluster_config_setting(clusterSize, clusterNumber, "5 0 0 0 0 0 0 0 0\n");

    clusterNumber = -1;
    print_expected_and_actual_states_after_cluster_config_setting(clusterSize, clusterNumber, "0 0 0 0 0 0 0 0\n");


    return 0;
}

void print_expected_and_actual_states_after_cluster_config_setting(float clusterSize, float clusterNumber, const char
        *expected_states) {
    printf("set cluster size %d and cluster number %d\n", (int) clusterSize, (int) clusterNumber);
    printf("expected cluster population\n");
    printf("%s", expected_states);
    printf("actual cluster population\n");
    set_cluster_config_and_evolve(clusterSize, clusterNumber);
    printf("\n");
}

void set_cluster_config_and_evolve(float clusterSize, float clusterNumber) {
    setClusterSize(clusterSize);
    setClusterNumber(clusterNumber);

    for (int i = 0; i < 1; i++) {
        computeModel();
        write_cluster_state_to_terminal();
    }
}



