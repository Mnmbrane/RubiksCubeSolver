#pragma once

#include <gtest/gtest.h>
#include "Cube.h"

class CubeTest : public ::testing::TestWithParam<T>
{
protected:
   Cube cube;
};