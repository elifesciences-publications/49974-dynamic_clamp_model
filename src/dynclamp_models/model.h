#ifndef DYNAMIC_CLAMP_MODELS_MODEL_H

#ifdef __cplusplus
extern "C" {
#endif

#define DYNAMIC_CLAMP_MODELS_MODEL_H

#include <math.h>

#define DYNCLAMPMODEL
#define ENABLE_LOOKUPTABLES


/*
 Methods called externally during running dynamic clamp
 */

void initModel(void);

void computeModel(void);

int generateLookupTable(int k, float **x, float **y, int *n);



/*
 * Setters for the param output variables, i.e. the model parameters
 */

void setVoltage(float);

void setConductance(float);

void setReversalPotential(float);

void setClusterInteraction(float);

void setClusterSize(float);

void setClusterNumber(float);

void setTimeConstant(float);

void setVhalf(float);

void setClusterInit(float);


/*
 * Getters for the param input traces
 */

float getCurrentOutput(void);

int get_number_of_open_channels(void);


/*
 * Getter for the internal states of the model
 */

int getClusterSize(void);

int getClusterState(int);

/*
 * Internally used functions
 */

void process_cluster_property_changes(void);

/*
 * Setters for externally set variables used by the model
 */

void setLoopInterval(float interval);

/*
 * Externally defined variables
 */

float *lookupx[0];

#ifdef __cplusplus
}
#endif

#endif //DYNAMIC_CLAMP_MODELS_MODEL_H

