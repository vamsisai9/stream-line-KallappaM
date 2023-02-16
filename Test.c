#include <stdio.h>
#include "BMS_DataSender.h"
#include <assert.h>
#include <stdlib.h>

void TEST_CASE_01()
{
  
  assert(SendBatteryParameters(NULL,50) == DATA_SENDING_FAILED);
  
}

void TEST_CASE_02()
{
  SensorData_st test_01;
  assert(SendBatteryParameters(&test_01,20) == DATA_SENDING_OK);
}
int main()
{
  TEST_CASE_01();
  TEST_CASE_02();
}
