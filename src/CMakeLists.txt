project(DYNAMIC_CLAMP)

include_directories(util)
include_directories(dynclamp_models)


add_subdirectory(util)
add_subdirectory(dynclamp_models)

add_subdirectory(dynclamp_models_test)

find_library(MATH_LIB m)

set(MODEL_TIME_SRC test_calculation_time.c)
add_executable(test_calculation_time ${MODEL_TIME_SRC})
target_link_libraries(test_calculation_time util dynclamp_models gtest)


set(MODEL_CLUSTER_DYNAMICS_SRC test_cluster_evolution.c)
add_executable(test_cluster_evolution ${MODEL_CLUSTER_DYNAMICS_SRC})
target_link_libraries(test_cluster_evolution util dynclamp_models gtest)

set(MODEL_CLUSTER_CONFIG_SRC test_cluster_configuration.c)
add_executable(test_cluster_configuration ${MODEL_CLUSTER_CONFIG_SRC})
target_link_libraries(test_cluster_configuration util dynclamp_models gtest)

