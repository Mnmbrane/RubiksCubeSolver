#pragma once

#include <gtest/gtest.h>
#include "Cube.h"

// int is just a placeholder type
class CubeTest : public ::testing::TestWithParam<int>
{
protected:
   Cube cube;
};