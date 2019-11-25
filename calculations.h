/****************************************
 * calculations.h
 * Perform maths functions
 * This file is part of the DIY Flow Bench project. For more information including usage and licensing please refer to: https://github.com/DeeEmm/DIY-Flow-Bench
 ***/

// Define Constants


/****************************************
 * CALCULATE FLOW
 * Convert RAW MAF sensor data into flow rate
 ***/
void calculateMafFlow()
{
    // calculate values and update display data:
    // displayData[FLOW_CFM_VAL] = CALCULATED_VALUE;
}


/****************************************
 * CALCULATE Sensor #1 PRESSURE / VAC
 * Convert RAW sensor data into pressure or vacuum
 ***/
void calculateSensor1Pressure()
{

}


/****************************************
 * CALCULATE Sensor #2 PRESSURE / VAC
 * Convert RAW sensor data into pressure or vacuum
 ***/
void calculateSensor2Pressure()
{

}


/****************************************
 * CONVERT FLOW
 * Convert flow values between different reference pressures
 ***/
float convertMafFlow(int referencePressure = 28)
{
    float convertedFlowValue = 0;
    
    //do calculations here

    return convertedFlowValue;

}


