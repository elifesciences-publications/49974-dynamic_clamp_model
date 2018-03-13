#include <model.h>
#include "gtest/gtest.h"


TEST(ModelTest, ShiftsTheClusterPopulationToTheDesiredState) {
    int target_state_idx = 3;
    setClusterInit(target_state_idx);
    initModel();
    for (int state_idx = 0; state_idx < 9 ; ++state_idx) {
        if(state_idx != target_state_idx) {
            EXPECT_EQ(getClusterState(state_idx),0);
        }
        else {
            EXPECT_GT(getClusterState(state_idx), 0);
        }
    }
}

TEST(ModelTest, DoesShiftTheClusterPopulationToTheTopStateIfDesiredStateIsTooLarge) {
    int target_state_idx = 10;
    int maximum_state_idx = 8;
    setClusterInit(target_state_idx);
    initModel();
    for (int state_idx = 0; state_idx < 9 ; ++state_idx) {
        if(state_idx != maximum_state_idx) {
            EXPECT_EQ(getClusterState(state_idx),0);
        }
        else {
            EXPECT_GT(getClusterState(state_idx), 0);
        }
    }
}

TEST(ModelTest, DoesShiftTheClusterPopulationToTheTopStateIfDesiredStateIsNegative) {
    int target_state_idx = -1;
    int minimum_state_idx = 0;
    setClusterInit(target_state_idx);
    initModel();
    for (int state_idx = 0; state_idx < 9 ; ++state_idx) {
        if(state_idx != minimum_state_idx) {
            EXPECT_EQ(getClusterState(state_idx),0);
        }
        else {
            EXPECT_GT(getClusterState(state_idx), 0);
        }
    }
}