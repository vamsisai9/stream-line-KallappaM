#include <stdio.h>
#include <stdlib.h>
#include "BMS_DataSender.h"

void PrintBatteryData(float BatteryTemp,float BatterySoc)
{
  printf("Temprature: = %f - Soc: = %f\n",BatteryTemp,BatterySoc);
}

DataStatus_en GenerateSensorData(SensorData_st *SensorData,int DataSize)
{
  DataStatus_en FinalStatus = DATA_GENERATION_FAILED;
  
  if((SensorData != NULL) && (DataSize))
  {
    FinalStatus = DATA_GENERATION_OK;
    
    for(int Count=0;Count<DataSize;Count++)
    {
          SensorData->Temprature[Count] = rand()%TEMP_RANGE;
          SensorData->Soc[Count] = rand()%SOC_RANGE;
          PrintBatteryData(SensorData->Temprature[Count],SensorData->Soc[Count]);
    }
  
  }
  
  return(FinalStatus);
}
    

DataStatus_en SendBatteryParameters(SensorData_st *SensorData,int DataSize)
{
  DataStatus_en FinalStatus = DATA_SENDING_FAILED ;
  
  if(SensorData != NULL)
  {
    FinalStatus = GenerateSensorData(SensorData,DataSize);
    if(FinalStatus)
    {  
      FinalStatus = DATA_SENDING_OK;
    }
  }
  return(FinalStatus);
}
