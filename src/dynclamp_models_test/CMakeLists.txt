project(dynclamp_models_tests)

add_executable(runBasicDynclampModelsTest
        model_test.cpp
        )

target_link_libraries(runBasicDynclampModelsTest gtest gtest_main dynclamp_models)