#include <stdio.h>
#include <time.h>

#include "util/input_parser.h"
#include "dynclamp_models/model.h"


float loopInterval = 0;

float *lookupx[0];

void mock_generating_lookup_table();


int main(int argc, char *args[]) {
    float voltage;
    float frequency;
    float conductance;
    float reversalPotential;
    float clusterInteraction;
    float simulationTime;
    float clusterSize;
    float clusterNumber;
    float timeConstant;
    parseInput(argc, args, &voltage, &frequency, &conductance, &reversalPotential, &simulationTime, &clusterInteraction,
               &clusterSize, &clusterNumber, &timeConstant);

    float vhalf;
    int VHALF_IDX = 10;
    float VHALF_DEFAULT = (float) -1.0;
    vhalf = readInput(argc, args, VHALF_IDX, VHALF_DEFAULT);

    int number_of_trials = (int) (simulationTime * frequency);

    clock_t start, end;
    double cpu_time_used;
    double mean_time, maximum_time, minimum_time;
    double mean_number_of_open_channels;


    setLoopInterval(1 / frequency);
    mock_generating_lookup_table();

    initModel();

    setConductance(conductance);
    setReversalPotential(reversalPotential);
    setClusterInteraction(clusterInteraction);
    setTimeConstant(timeConstant);
    setClusterSize(clusterSize);
    setClusterNumber(clusterNumber);
    setVhalf(vhalf);

    setVoltage(voltage);

    minimum_time = 1e9;
    maximum_time = 0;
    mean_time = 0;

    mean_number_of_open_channels = 0;
    for (int i = 0; i < number_of_trials; i++) {
        start = clock();
        computeModel();
        end = clock();

        //timing
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC * 1e9;
        mean_time += cpu_time_used / number_of_trials;
        maximum_time = (maximum_time > cpu_time_used) ? maximum_time : cpu_time_used;
        minimum_time = (minimum_time < cpu_time_used) ? minimum_time : cpu_time_used;

        //analyze cluster states
        mean_number_of_open_channels += ((double) get_number_of_open_channels()) / number_of_trials;

    }
    printf("# Time\n");
    printf("computeModel() performance (ns) \nmean\t\t\t\tmax \t\t\t\tmin \n%10.2f  %10.2f  %10.2f\n\n", mean_time,
           maximum_time,
           minimum_time);
    printf("# Results\n");
    printf("InputVoltage: %2.2f \n", voltage);
    printf("\tMean number of open channels: %3.8f", mean_number_of_open_channels);

    return 0;
}


void mock_generating_lookup_table() {
    int table_enumerator[1];
    float **dummy_y = NULL;
    generateLookupTable(0, lookupx, dummy_y, table_enumerator);

}



