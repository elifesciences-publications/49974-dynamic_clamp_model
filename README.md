### This code is associated with the paper from Pfeiffer et al., "Clusters of cooperative ion channels enable a membrane potential-based mechanism for short-term memory". eLife, 2020. http://dx.doi.org/10.7554/eLife.49974

# Model of clusters of cooperative channels for a dynamic clamp experiment

Dynamic clamp model for a current generated by multiple clusters of cooperative ion channels:
$$
I_{coop} = -g*N_{open}*(V-E)
$$
where the number of open channels N_{open} changes due to the stochastic opening and closing events guided by rates
which depend on the external voltage and the number of open channels among the surrounding channels in a cluster i.e.
alpha(V, o) and beta(V,o)

The model is written to work with [RELACS](http://relacs.sourceforge.net/). 
 
## Usage

After installation of RELACS, please follow the instructions to configure dynamic clamp to run the provided model in 
`src/dynclamp_model/model.c`.

## Building

The project also involves some tests and executables that can be build via
```bash
mkdir build
cd build 
cmake ..
make
```

## Testing 
After building, the simple unit tests using the C++ testing framework gtest (included for simplicity) can be run via
```bash
./build/src/dynclamp_models_test/runBasicDynclampModelsTest
```

A couple of other basic tests are available

### Cluster configuration
The model allows online resetting of cluster size and number, which is tested via

```bash
./build/src/test_cluster_configuration
```

### Cluster evolution
The evolution of cluster states in a voltage clamp setting can be simulated via 
```bash
./build/src/test_cluster_configuration <for setting parameters see the source file>
```

### Rough timing test

For a typical set of parameters, the calculation time per step is measured
```bash
./build/src/test_calculation_time
```




