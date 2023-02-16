#define MAX_VALUE 100
#define SOC_RANGE 100
#define TEMP_RANGE 100

typedef struct
{
  float Temprature[MAX_VALUE];
  float Soc[MAX_VALUE];
}SensorData_st;

typedef enum
{
  DATA_SENDING_FAILED = 0,
  DATA_GENERATION_FAILED,
  DATA_GENERATION_OK,
  DATA_SENDING_OK
}DataStatus_en;

DataStatus_en SendBatteryParameters(SensorData_st *SensorData ,int);
DataStatus_en GenerateSensorData(SensorData_st *SensorData ,int);
void PrintBatteryData(float,float);
