/***********************************************************
 * @name The DIY Flow Bench project
 * @details Measure and display volumetric air flow using an ESP32 & Automotive MAF sensor
 * @link https://diyflowbench.com
 * @author DeeEmm aka Mick Percy deeemm@deeemm.com
 * 
 * @file sensors.cpp
 * 
 * @brief Sensors class
 * 
 * @remarks For more information please visit the WIKI on our GitHub project page: https://github.com/DeeEmm/DIY-Flow-Bench/wiki
 * Or join our support forums: https://github.com/DeeEmm/DIY-Flow-Bench/discussions
 * You can also visit our Facebook community: https://www.facebook.com/groups/diyflowbench/
 * 
 * @license This project and all associated files are provided for use under the GNU GPL3 license:
 * https://github.com/DeeEmm/DIY-Flow-Bench/blob/master/LICENSE
 * 
 ***/

#include "Arduino.h"
#include <vector>

#include "constants.h"
#include "structs.h"
#include "calculations.h"

#include <Wire.h>
#include "hardware.h"
#include "sensors.h"
#include "messages.h"
#include "driver/pcnt.h"

#define TINY_BME280_I2C
#include "TinyBME280.h" 
tiny::BME280 _BME280Sensor;
// TwoWire I2CBME = TwoWire(0);

// #include "DeeEmm_BME680.h" // TODO #233



/***********************************************************
 * @brief Class constructor
 ***/
Sensors::Sensors() {

}

// REVIEW - Frequency style MAF Begin
// NOTE: Voodoo needed to get interrupt to work within class structure for frequency measurement. 
// We declare a new instance of the Sensor class so that we can use it for the MAF ISR
// https://forum.arduino.cc/t/pointer-to-member-function/365758
// Sensors __mafVoodoo;


/***********************************************************
 * @name begin
 * @brief Sensor initialisation and set up
 ***/
void Sensors::begin () {

	Messages _message;

	_message.serialPrintf("Initialising Sensors \n");

	extern struct DeviceStatus status;
    extern struct Language language;
	extern struct Configuration config;
	extern struct Pins pins;
	extern int mafOutputType;
	
	// Initialise  MAF data
	if (config.MAF_SRC_TYPE != SENSOR_DISABLED){	

			// get size of the MAF datatable 
			status.mafDataTableRows = status.mafJsonObject.size() -1;

			u_int rowNum = 0;
			u_int key;
			u_int value;

			// Get JSON Object iterator
			JsonObject::iterator it = status.mafJsonObject.begin();

			// Walk through JSON object to populate vectors
			for (u_int rowNum = 0; rowNum < status.mafDataTableRows; rowNum++) { 

				key = stoi(it->key().c_str());
				value = stoi(it->value().as<std::string>());

				// TEST
				// _message.serialPrintf(" rowNum: %i\n", rowNum);
				// _message.serialPrintf(" maf key: %i\n", key);
				// _message.serialPrintf(" maf value: %i\n", value);

				status.mafLookupTable.push_back( { key , value } );

				rowNum += 1;
				it += 1;

				status.mafDataKeyMax = key;
				status.mafDataValMax = value;
				
			}

			// get highest MAF input value from data table
			// status.mafDataValMax = status.mafLookupTable[status.mafDataTableRows][1];
			// status.mafDataKeyMax = status.mafLookupTable[status.mafDataTableRows][0];

			// TEST
			// _message.serialPrintf(" status.mafDataValMax: %lu\n", status.mafDataValMax);
			// _message.serialPrintf(" status.mafDataKeyMax: %lu\n", status.mafDataKeyMax);

	}














	//initialise BME280
	if (config.BME280_IS_ENABLED) {

		// uint8_t I2CAddress = (unsigned int)config.BME280_I2C_ADDR;

		_message.serialPrintf("Initialising BME280: %u\n", config.BME280_I2C_ADDR);	
		
		if (_BME280Sensor.beginI2C(config.BME280_I2C_ADDR) == false) {
			_message.serialPrintf("BME sensor did not respond. \n");
			_message.serialPrintf("Please check wiring and I2C address\n");
			_message.serialPrintf("BME I2C address %s set in configuration.h. \n", config.BME280_I2C_ADDR);
			while(1); //Freeze
		} else {
			_message.serialPrintf("BME280 Initialised\n");
		}

		_BME280Sensor.setTempOverSample(1);
		_BME280Sensor.setPressureOverSample(1);
		_BME280Sensor.setHumidityOverSample(1);
		_BME280Sensor.setStandbyTime(0);
		_BME280Sensor.setFilter(0);
		_BME280Sensor.setMode(tiny::Mode::NORMAL); // NORMAL / FORCED / SLEEP

	}


	//initialise BME680
	if (config.BME680_IS_ENABLED) {

		// TODO #233
		// BME680_Class _BME680Sensor;
	
		// _message.serialPrintf("Initialising BME680 \n");	

		// // while (!_BME680Sensor.begin(I2C_STANDARD_MODE, onfig.BME680_I2C_ADDR)) { 
		// while (!_BME680Sensor.begin(I2C_STANDARD_MODE, onfig.BME680_I2C_ADDR)) { 
		// 	_message.serialPrintf("-  Unable to find BME680. Trying again in 5 seconds.\n");
		// 	delay(5000);
		// }  

		// _BME680Sensor.setOversampling(TemperatureSensor, Oversample16);  
		// _BME680Sensor.setOversampling(HumiditySensor, Oversample16);     
		// _BME680Sensor.setOversampling(PressureSensor, Oversample16);     
		// _BME680Sensor.setOversampling(GasSensor, SensorOff);   
		// _BME680Sensor.setIIRFilter(IIR4);  							
		// _BME680Sensor.setGas(0, 0); // Turns off gas measurements
	
	}




	// REVIEW FREQUENCY BASED MAF - temporarily disabled - need to fix & reenable
	// Set up the MAF ISR if required
	// Note Frequency based MAFs are required to be attached direct to MAF pin for pulse counter to work
	// This means 5v > 3.3v signal conditioning is required on MAF pin (possible simple voltage divider + filter)
	// Need to check out use of ESP PCNT function - https://docs.espressif.com/projects/esp-idf/en/v4.4/esp32/api-reference/peripherals/pcnt.html
	// ESP32 has max PCNT frequency of 40MHz (half clock speed - 80MHz)
	// Typical MAF is 30Hz -  150Hz
	// Example - https://github.com/espressif/esp-idf/blob/v4.4/examples/peripherals/pcnt/pulse_count_event/main/pcnt_event_example_main.c
	// also this... https://blog.adafruit.com/2018/12/27/frequency-measurement-on-an-esp32-in-micropython-esp32-micropython-python/
	// and this... https://forum.micropython.org/viewtopic.php?f=18&t=5724&p=32921
	// (which has example without interrupts)

/* temp disabled - need to reenable	
	if (_maf.outputType == FREQUENCY) {	
		__mafVoodoo.mafSetupISR(MAF_PIN, []{__mafVoodoo.mafFreqCountISR();}, FALLING);
		timer = timerBegin(0, 2, true);                                  
		timerStart(timer);	
	}
*/	


	// Set status values for GUI
	status.mafSensor = config.MAF_SENSOR_TYPE;
	status.baroSensor = getSensorType(config.BARO_SENSOR_TYPE);
	status.tempSensor  = getSensorType(config.TEMP_SENSOR_TYPE);
	status.relhSensor = getSensorType(config.RELH_SENSOR_TYPE);
	status.prefSensor = getSensorType(config.PREF_SENSOR_TYPE);
	status.pdiffSensor = getSensorType(config.PDIFF_SENSOR_TYPE);
	status.pitotSensor = getSensorType(config.PREF_SENSOR_TYPE);

	// END System status definitions

	_message.serialPrintf("Sensors Initialised \n");



}
/***********************************************************
  * @brief Get Sensor Type
  * @note returns description for statis pane.
  ***/
String Sensors::getSensorType(int sensorType) {

	extern struct Language language;

	String sensorDescription;

	switch (sensorType) {

		case SENSOR_DISABLED: {
			sensorDescription = language.LANG_NOT_ENABLED;
			break;
		}
		case MPXV7007: {
			sensorDescription = "MPXV7007";
			break;
		}
		case MPXV7025: {
			sensorDescription = "MPXV7025";
			break;
		}
		case LINEAR_ANALOG: {
			sensorDescription = "ANALOG PIN";
			break;
		}	
		case XGZP6899A007KPDPN: {
			sensorDescription = "XGZP6899A007KPDPN";
			break;
		}
		case XGZP6899A010KPDPN: {
			sensorDescription = "XGZP6899A010KPDPN";
			break;
		}
		case M5STACK_TubePressure: {
			sensorDescription = "TubePressure";
			break;
		}
		case BOSCH_BME280: {
			sensorDescription = "BME280";
			break;
		}
		case BOSCH_BME680: {
			sensorDescription = "BME680";
			break;
		}
		case SIMPLE_TEMP_DHT11: {
			sensorDescription = "DHT11";
			break;
		}
		case FIXED_VALUE: {
			sensorDescription = "Fixed Value";
			break;
		}		
		case MPX4115: {
			sensorDescription = "MPX4115";
			break;
		}		
		default: {
			sensorDescription = language.LANG_NOT_ENABLED;
			break;
		}

	}

	return sensorDescription;
}





// REVIEW - MAF Interrupt service routine setup
/***********************************************************
  * @brief Set up MAF ISR
  *
  * We cannot call a non-static member function directly so we need to encapsulate it
  * This is part of the Voodoo
  ***/
/* TODO: temp disabled - need to reenable	
void Sensors::mafSetupISR(uint8_t irq_pin, void (*ISR_callback)(void), int value) {
  attachInterrupt(digitalPinToInterrupt(irq_pin), ISR_callback, value);
}
*/


// REVIEW - MAF Interrupt service routine
/***********************************************************
 * @brief Interrupt Service Routine for MAF Frequency measurement
 *
 * Determine how long since last triggered (Resides in RAM memory as it is faster)
 ***/
// TODO: Add IRAM_ATTR to Nova-Arduino 
/* TODO: temp disabled - need to reenable	
void IRAM_ATTR Sensors::mafFreqCountISR() {
    uint64_t TempVal = timerRead(timer);            
    PeriodCount = TempVal - StartValue;             
    StartValue = TempVal;                           
}
*/




/***********************************************************
 * @brief Returns RAW MAF Sensor value (ADC Value)
 *
 ***/
long Sensors::getMafRaw() {
	
	Hardware _hardware;
	extern struct SensorData sensorVal;
	extern struct Configuration config;
	extern struct Pins pins;


	switch (config.MAF_SRC_TYPE) {

		case SENSOR_DISABLED: {
			return 0;
			break;
		}


		case ADS1115:{
			sensorVal.MafRAW = _hardware.getADCRawData(config.MAF_ADC_CHANNEL);
			break;
		}

		case LINEAR_ANALOG: {
			long mafFlowRaw = analogRead(pins.MAF_PIN);
			break;
		}

		default: {
			return 0;
			break;
		}

	}

	return sensorVal.MafRAW;


}




/***********************************************************
 * @brief getMafVolts: Returns MAF signal in Volts
 ***/
double Sensors::getMafVolts() {

	extern struct Configuration config;
	extern struct Pins pins;
	Hardware _hardware;
	double sensorVolts = 0.00F;

	switch (config.MAF_SRC_TYPE) {

		case ADS1115:{
			sensorVolts = _hardware.getADCVolts(config.MAF_ADC_CHANNEL);
			break;
		}

		case LINEAR_ANALOG: {
			long mafRaw = analogRead(pins.MAF_PIN);
			sensorVolts = mafRaw * (_hardware.get3v3SupplyVolts() / 4095.0);
			break;
		}

		default: {
			sensorVolts = 1.0;
			return sensorVolts;
			break;
		}
	}

	
	// Lets make sure we have a valid value to return
	if (sensorVolts > 0) {
		sensorVolts += config.MAF_MV_TRIMPOT;
		return sensorVolts;
	} else {
		return 0.0;
	}	
	
}





/***********************************************************
 * @brief Returns MAF mass flow value in KG/H 
 * @note Interpolates lookupvalue from datatable key>value pairs
 * @returns Mass flow in KG/H
 *
 ***/
double Sensors::getMafFlow(int units) {

	extern struct DeviceStatus status;
	extern struct SensorData sensorVal;
	extern struct BenchSettings settings;

	Hardware _hardware;
	Messages message;

	double flowRateCFM = 0.0;
	double flowRateMGS = 0.0;
	double flowRateKGH = 0.0;
	double lookupValue = 0.0;
	double transposedflowRateKGH = 0.0;
	double oldMafArea = 0.0;
	double newMafArea = 0.0;
	double velocity1 = 0.0;
	double velocity2 = 0.0;
	double mafVelocity = 0.0;


// message.serialPrintf("MAF TEST VAL: %li ", status.mafDataKeyMax);

	// scale sensor reading to data table size using map function (0-5v : 0-keymax)
	// NOTE Discrepency with MAP calculated value
	// long refValue =  map(this->getMafVolts(), 0, _hardware.get5vSupplyVolts(), 0, status.mafDataKeyMax ); 
	// long refValue =  map(this->getMafVolts(), 0, 5, 0, status.mafDataKeyMax); 
	u_int refValue = (status.mafDataKeyMax / 5) * this->getMafVolts();

// message.serialPrintf("MAF REF VAL: %l ", refValue);

	for (int rowNum = 0; rowNum < status.mafDataTableRows; rowNum++) { // iterate the data table comparing the Lookup Value to the refValue for each row

		u_int Key = status.mafLookupTable[rowNum][0]; // Key Value for this row (x2)
		u_int Val = status.mafLookupTable[rowNum][1]; // Flow Value for this row (y2)

		// Did we get a match??
		if (refValue == Key) { // Great!!! we've got the exact key value

			lookupValue = Val; // lets use the associated lookup value
			sensorVal.MafLookup = Val;
			break;

		} else if (Key > refValue && rowNum > 0) { // The value is somewhere between this and the previous key value so let's use linear interpolation to calculate the actual value: 

			u_int KeyPrev = status.mafLookupTable[rowNum - 1][0]; // Key value for the previous row (x1)
			u_int ValPrev = status.mafLookupTable[rowNum - 1][1]; // Flow value for the previous row (y1)

			// Linear interpolation y = y1 + (x-x1)((y2-y1)/(x2-x1)) where x1+y1 are coord1 and x2_y2 are coord2
			lookupValue = ValPrev + (refValue - KeyPrev)*((Val-ValPrev)/(Key-KeyPrev));
			sensorVal.MafLookup = lookupValue;
			break;   

		} else if (rowNum == status.mafDataTableRows && refValue > Key) { //we're at the largest value, this must be it
			lookupValue = Val; // lets use the associated lookup value
			sensorVal.MafLookup = Val;
			// TODO status message MAX FLOW
			break;
		}

	} 

	// Scale lookup value
	lookupValue *= status.mafScaling; 

	const auto unitMG_S = std::string("MG_S");
	const auto mafUnit = std::string(status.mafUnits);

	bool mafUnitIsMG_S = mafUnit.find(unitMG_S) != string::npos;

	if (mafUnitIsMG_S) {
	// if (status.mafUnits == MG_S) {
		flowRateKGH = lookupValue * 0.0036F;

	} else { // mafUnits is KG/H
		flowRateKGH = lookupValue;
	}

	// Now that we have a converted flow value we can translate it for different housing diameters
	if (settings.maf_housing_diameter > 0 && status.mafDiameter > 0 && settings.maf_housing_diameter != status.mafDiameter) { 
		// We are running a custom MAF Housing, lets translate the flow rates to the new diameter

		// NOTE this transfer function is actually for volumetric flow (m3/s) but we can assume that the mass to volumetric conversion is ratiometric at any given instant in time.
		// This is because any environmental influences apply equally to both parts of the equation and cancel each other out. 
		// So we can reduce the mass flow conversion to the same simple ratio that we use for volumetric flow. 
		// In short, the relationship between flow and pipe area applies equally to both mass flow and volumetric flow for a given instant in time.

		// Q = V*A
		// V = Q/A
		// A = PI*r^2
		// Q1 = Q2
		// V1*A1 = V2*A2
		// where Q = volumetric flow (m3/s) | A = area(m2) | V = velocity
		
		// Calculate original MAF area
		oldMafArea = (PI * pow((status.mafDiameter / 2), 2)) / 1000000;
		// Calculate new MAF area
		newMafArea = (PI * pow((settings.maf_housing_diameter / 2), 2)) / 1000000;

		// scale the result with the new pipe area and convert back to mass flow
		transposedflowRateKGH = (flowRateKGH / oldMafArea) * newMafArea;

		// Chat-GPT version		
		// transposedflowRateKGH = flowRateKGH * (newMafArea / oldMafArea);

		return transposedflowRateKGH;

	} else { 

		// lets send the standard MAF data
		return flowRateKGH;
	}


}




/***********************************************************
 * @brief Returns flow value in CFM from differential pressure using ratiometric principle
 * @note uses calibrated orifice flow rate and assumes reference pressure is matched to orifice calibration
 * @note pRef tapped below orifice plate | pDiff tapped above orifice plate
 *
 ***/
double Sensors::getDifferentialFlow() {

	extern struct DeviceStatus status;
	extern struct SensorData sensorVal;
	extern struct BenchSettings settings;
	extern struct Language language;

	Hardware _hardware;
    Messages _message;  

	double flowRateCFM = 0.0;
    double orificeOneFlow = 0.0;
    double orificeOneDepression = 0.0;
	double orificeFlowRate = 0.0;
	double orificeDepression = 0.0;
	double flowRatio = 0.0;

	// convert orifice querystring to char 
	char activeOrifice[status.activeOrifice.length() + 1];
	strcpy(activeOrifice, status.activeOrifice.c_str()); 

	//  switchval = strtol(liftPoint.c_str(), &end, 10); // convert std::str to int

	char orifice = activeOrifice[0];

	// get orifice flow data from active orifice
	switch (orifice)   {

		case '1': 
			orificeFlowRate = settings.orificeOneFlow;
			orificeDepression = settings.orificeOneDepression;
		break;

		case '2': 
			orificeFlowRate = settings.orificeTwoFlow;
			orificeDepression = settings.orificeTwoDepression;
		break;

		case '3': 
			orificeFlowRate = settings.orificeThreeFlow;
			orificeDepression = settings.orificeThreeDepression;
		break;

		case '4': 
			orificeFlowRate = settings.orificeFourFlow;
			orificeDepression = settings.orificeFourDepression;
		break;

		case '5': 
			orificeFlowRate = settings.orificeFiveFlow;
			orificeDepression = settings.orificeFiveDepression;
		break;

		case '6': 
			orificeFlowRate = settings.orificeSixFlow;
			orificeDepression = settings.orificeSixDepression;
		break;

		// We've got here without a valid active orifice so lets set something and send an error message
        default:
			orificeFlowRate = settings.orificeOneFlow;
			orificeDepression = settings.orificeOneDepression;
			_message.serialPrintf("%s\n", "Invalid Orifice Data");
			String statusMessage = language.LANG_INVALID_ORIFICE_SELECTED;
        break;

	}

	status.activeOrificeFlowRate = orificeFlowRate;
	status.activeOrificeTestPressure = orificeDepression;

	// Calculate flow rate based on calibrated orifice data, ref pressure and current pressure drop
	flowRatio = sensorVal.PDiffKPA / sensorVal.PRefKPA;
	flowRateCFM = flowRatio * orificeFlowRate;

	return flowRateCFM;

}








/***********************************************************
 * @brief get Reference Pressure sensor voltage
 * @returns current PRef sensor value in Volts
 ***/
double Sensors::getPRefVolts() {

	Hardware _hardware;

	extern struct Configuration config;
	extern struct Pins pins;

	double sensorVolts = 0.0;

	switch (config.PREF_SENSOR_TYPE) 	{

		case ADS1115 : {
			sensorVolts = _hardware.getADCVolts(config.PREF_ADC_CHANNEL);
			break;
		}

		case LINEAR_ANALOG : {
			long refPressRaw = analogRead(pins.REF_PRESSURE_PIN);
			sensorVolts = refPressRaw * (_hardware.get3v3SupplyVolts() / 4095.0);
			break;
		}

		default: {
			// return a fixed value
			sensorVolts = 1.0;
			return sensorVolts;
			break;
		}
	} 

	// Lets make sure we have a valid value to return
	if (sensorVolts > 0.0) { 
		sensorVolts += config.PREF_MV_TRIMPOT;
		return sensorVolts;
	} else { 
		return 0.0;
	}

}





/***********************************************************
 * @brief Process Reference Pressure sensor value depending on sensor type
 * @returns Reference pressure in kPa
 * @note Default sensor MPXV7007DP - https://www.nxp.com/docs/en/data-sheet/MPXV7007.pdf
 ***/
double Sensors::getPRefValue() {

	Hardware _hardware;
	Messages message;
	extern struct BenchSettings settings;
	extern struct Configuration config;

	double sensorVal = 0.0;
	double sensorVolts = this->getPRefVolts();

	switch (config.PREF_SENSOR_TYPE)  {

		case LINEAR_ANALOG: 	
				sensorVal = this->getPRefVolts() * config.PREF_ANALOG_SCALE;
		break;

		case MPXV7007:
			// Vout = Vcc x (0.057 x sensorVal + 0.5) --- Transfer function formula from MPXV7007DP Datasheet
			sensorVal = ((sensorVolts / _hardware.get5vSupplyVolts()) -0.5) / 0.057;
		break;

		case MPXV7025:
			// Vout = Vcc x (0.018 x P + 0.5)
			// P = ((Vout / Vcc) - 0.5 ) / 0.018 )
			sensorVal = ((sensorVolts / _hardware.get5vSupplyVolts()) -0.5) / 0.018;
		break;

		case XGZP6899A007KPDPN :
			// Linear response. Range = 0.5 ~ 4.5 = -7 ~ 7kPa
			sensorVal = sensorVolts * 3.5 - 8.75;

		case XGZP6899A010KPDPN:
			// Linear response. Range = 0.5 ~ 4.5 = -10 ~ 10kPa
			sensorVal = sensorVolts * 5 - 12.5;
		break;

		case M5STACK_TubePressure:
			//P: Actual test pressure value, unit (Kpa)
			//Vout: sensor voltage output value
			//P = (Vout-0.1)/3.0*300.0-100.0
			sensorVal = (sensorVolts-0.1)/3.0*300.0-100.0;	
		break;

		default:
			sensorVal = config.FIXED_REF_PRESS_VALUE;
		break;
	}

	// Lets make sure we have a valid value to return
	double pRefComp = fabs(sensorVal);
	if (pRefComp > settings.min_bench_pressure) { 
		return sensorVal;
	} else { 
		return 0.0001; // return small non zero value to prevent divide by zero errors (will be truncated to zero in display)
	}

}





/***********************************************************
 * @brief Get PDiff Volts
 * @returns Differential Pressure in Volts
 ***/
double Sensors::getPDiffVolts() {
	
	Hardware _hardware;
	extern struct Configuration config;
	extern struct Pins pins;

	double sensorVolts = 0.0;

	switch (config.PDIFF_SENSOR_TYPE) 	{

		case ADS1115 : {
			sensorVolts = _hardware.getADCVolts(config.PDIFF_ADC_CHANNEL);
			break;
		}

		case LINEAR_ANALOG : {
			long pDiffRaw = analogRead(pins.DIFF_PRESSURE_PIN);
			sensorVolts = pDiffRaw * (_hardware.get3v3SupplyVolts() / 4095.0);
			break;
		}

		default: {
			// return a fixed value
			sensorVolts = 1.0;
			return sensorVolts;
			break;
		}
	} 


	// Lets make sure we have a valid value to return
	if (sensorVolts > 0) {
		sensorVolts += config.PDIFF_MV_TRIMPOT;
		return sensorVolts;
	} else {
		return 0;
	}
	
}




/***********************************************************
 * @brief Get differential pressure in kPa
 * @returns Differential pressure in kPa
 * @note Default sensor is MPXV7007DP - Datasheet - https://www.nxp.com/docs/en/data-sheet/MPXV7007.pdf
 ***/
double Sensors::getPDiffValue() {

	extern struct BenchSettings settings; 
	extern struct Configuration config;

	Hardware _hardware;

	double sensorVal = 0.0;
	double sensorVolts = this->getPDiffVolts();

	switch (config.PDIFF_SENSOR_TYPE)  {

			case LINEAR_ANALOG: 	
					sensorVal = this->getPRefVolts() * config.PDIFF_ANALOG_SCALE;
			break;

			case MPXV7007:
				// Vout = Vcc x (0.057 x sensorVal + 0.5) --- Transfer function formula from MPXV7007DP Datasheet
				sensorVal = ((sensorVolts / _hardware.get5vSupplyVolts()) -0.5) / 0.057;
			break;

			case MPXV7025:
				// Vout = Vcc x (0.018 x P + 0.5)
				// P = ((Vout / Vcc) - 0.5 ) / 0.018 )
				sensorVal = ((sensorVolts / _hardware.get5vSupplyVolts()) -0.5) / 0.018;
			break;

			case XGZP6899A007KPDPN:
				// Linear response. Range = 0.5 ~ 4.5 = -7 ~ 7kPa
				sensorVal = sensorVolts * 3.5 - 8.75;

			case XGZP6899A010KPDPN:
				// Linear response. Range = 0.5 ~ 4.5 = -10 ~ 10kPa
				sensorVal = sensorVolts * 5 - 12.5;
			break;

			case M5STACK_TubePressure:
				//P: Actual test pressure value, unit (Kpa)
				//Vout: sensor voltage output value
				//P = (Vout-0.1)/3.0*300.0-100.0
				sensorVal = (sensorVolts-0.1)/3.0*300.0-100.0;	
			break;

			default:
				sensorVal = config.FIXED_DIFF_PRESS_VALUE;
			break;
		}

	// Lets make sure we have a valid value to return - check it is above minimum threshold
	double pDiffComp = fabs(sensorVal);
	if (pDiffComp > settings.min_bench_pressure) { 
		return sensorVal;
	} else { 
		return 0.0001; // return small non zero value to prevent divide by zero errors (will be truncated to zero in display)
	}	

}




/***********************************************************
 * @brief Get pitot Volts
 * @returns Pitot Pressure in Volts
 ***/
double Sensors::getPitotVolts() {

	extern struct Configuration config;
	extern struct Pins pins;

	Hardware _hardware;

	double sensorVolts = 0.0;

		switch (config.PITOT_SENSOR_TYPE) 	{

		case ADS1115 : {
			sensorVolts = _hardware.getADCVolts(config.PDIFF_ADC_CHANNEL);
			break;
		}

		case LINEAR_ANALOG : {
			long pDiffRaw = analogRead(pins.DIFF_PRESSURE_PIN);
			sensorVolts = pDiffRaw * (_hardware.get3v3SupplyVolts() / 4095.0);
			break;
		}

		default: {
			// return a fixed value
			sensorVolts = 1.0;
			return sensorVolts;
			break;
		}
	} 

	
	// Lets make sure we have a valid value to return
	if (sensorVolts > 0) {
		sensorVolts += config.PITOT_MV_TRIMPOT;
		return sensorVolts;
	} else {
		return 0.0;
	}
	
	
}





/***********************************************************
 * @brief get Pitot value in kPa
 * @returns Pitot pressure differential in kPa
 * @note Default sensor MPXV7007DP - Datasheet - https://www.nxp.com/docs/en/data-sheet/MPXV7007.pdf
 ***/
double Sensors::getPitotValue() {
	
	extern struct BenchSettings settings;
	extern struct CalibrationData calVal;
	extern struct Configuration config;

	Calculations _calculations;
	Hardware _hardware;

	double pitotPressure = 0.0;
	double sensorVolts = this->getPitotVolts();
	double airDensity = 0.0;
	double airVelocity = 0.0;
	double totalPressure = 0.0;
	double staticPressure = 0.0;	

	double sensorVal = 0.0;

	switch (config.PITOT_SENSOR_TYPE)  {

		case LINEAR_ANALOG: 	
				sensorVal = this->getPitotVolts() * config.PITOT_ANALOG_SCALE;
		break;

		case MPXV7007:
			// Vout = Vcc x (0.057 x sensorVal + 0.5) --- Transfer function formula from MPXV7007DP Datasheet
			sensorVal = ((sensorVolts / _hardware.get5vSupplyVolts()) -0.5) / 0.057;
		break;

		case MPXV7025:
			// Vout = Vcc x (0.018 x P + 0.5)
			// P = ((Vout / Vcc) - 0.5 ) / 0.018 )
			sensorVal = ((sensorVolts / _hardware.get5vSupplyVolts()) -0.5) / 0.018;
		break;

		case XGZP6899A007KPDPN:
			// Linear response. Range = 0.5 ~ 4.5 = -7 ~ 7kPa
			sensorVal = sensorVolts * 3.5 - 8.75;

		case XGZP6899A010KPDPN:
			// Linear response. Range = 0.5 ~ 4.5 = -10 ~ 10kPa
			sensorVal = sensorVolts * 5 - 12.5;
		break;

		case M5STACK_TubePressure:
			//P: Actual test pressure value, unit (Kpa)
			//Vout: sensor voltage output value
			//P = (Vout-0.1)/3.0*300.0-100.0
			sensorVal = (sensorVolts-0.1)/3.0*300.0-100.0;	
		break;

		default:
			sensorVal = config.FIXED_DIFF_PRESS_VALUE;
		break;
	}


	// Lets make sure we have a valid value to return - check it is above minimum threshold
	double pitotComp = fabs(sensorVal);
	if (pitotComp > settings.min_bench_pressure) { 
		return pitotComp;
	} else { 
		return 0.0001; // return small non zero value to prevent divide by zero errors (will be truncated to zero in display)
	}	

}






/***********************************************************
 * @brief get Pitot velocity in m/sec
 * @returns Pitot velocity in metres per second
 * @note Default sensor MPXV7007DP - Datasheet - https://www.nxp.com/docs/en/data-sheet/MPXV7007.pdf
 ***/
double Sensors::getPitotVelocity() {
	
	extern struct BenchSettings settings;
	extern struct SensorData sensorVal;
	extern struct CalibrationData calVal;

	Calculations _calculations;

	double pitotPressure = 0.0;
	double sensorVolts = this->getPitotVolts();
	double airDensity = 0.0;
	double airVelocity = 0.0;
	double totalPressure = 0.0;
	double staticPressure = 0.0;	
	
	pitotPressure = sensorVal.PitotKPA;

	// get air density
	airDensity = _calculations.calculateAirDensity(sensorVal.TempDegC, sensorVal.BaroKPA, sensorVal.RelH);

	// Convert Pitot pressure to velocity (m3/min)
	// airVelocity = sqrt(2 * (pitotPressure - sensorVal.PRefKPA) / airDensity );
	airVelocity = sqrt(2 * (pitotPressure) / airDensity );

	// Lets make sure we have a valid value to return - check it is above minimum threshold 
	// TODO - 'borrowing' min_bench_pressure
	double pitotComp = fabs(airVelocity);
	if (pitotComp > settings.min_bench_pressure) { 
		return pitotComp;
	} else { 
		return 0.0001; // return small non zero value to prevent divide by zero errors (will be truncated to zero in display)
	}	

}




/***********************************************************
 * @name getTempValue
 * @brief Returns temperature in Deg C
 * @return refTempDegC
 ***/
double Sensors::getTempValue() {
	
	Hardware _hardware;
	Messages _message;

	extern struct SensorData sensorVal;
	extern struct Configuration config;
	extern struct Pins pins;

	double  refTempDegC;
	int32_t  refTempDegC_INT;
	int32_t  unusedRH, unusedBaro, unusedGas;
	

	switch (config.TEMP_SENSOR_TYPE) {

		case LINEAR_ANALOG: {
			long rawTempValue = analogRead(pins.TEMPERATURE_PIN);	
			double tempVolts = rawTempValue * (_hardware.get3v3SupplyVolts() / 4095.0);	
			tempVolts += config.TEMP_MV_TRIMPOT;		
			refTempDegC = tempVolts * config.TEMP_ANALOG_SCALE;
			refTempDegC +=  config.TEMP_FINE_ADJUST;
			break;
		}

		case BOSCH_BME280 : {
			refTempDegC = _BME280Sensor.readFixedTempC() / 100.00F;
			break;
		}

		case BOSCH_BME680 : {
			// _BME680Sensor.getSensorData(refTempDegC_INT, unusedRH, unusedBaro, unusedGas, false);
			// refTempDegC = double(refTempDegC_INT / 100.00F);
			// sensorVal.test = refTempDegC_INT;
			break;
		}

		case SIMPLE_TEMP_DHT11: {
			// NOTE DHT11 sampling rate is max 1HZ. We may need to slow down read rate to every few secs
			// int err = SimpleDHTErrSuccess;
			// if ((err = dht11.read(&refTemp, &refRelh, NULL)) != SimpleDHTErrSuccess) {
			// _message.Handler(language.LANG_DHT11_READ_FAIL); // Set error to display on screen
			// refTempDegC = 0;        
			// } else {
			// refTempDegC = refTemp;
			// }	
			// refTempDegC +=  TEMP_FINE_ADJUST;
			break;
		}

		default: {
			refTempDegC = config.FIXED_TEMP_VALUE;
			break;
		}

	}


	_message.debugPrintf("config.TEMP_SENSOR_TYPE %d\n",config.TEMP_SENSOR_TYPE);

	// if (config.TEMP_FINE_ADJUST != 0) refTempDegC += config.TEMP_FINE_ADJUST;
	refTempDegC += config.TEMP_FINE_ADJUST;
	return refTempDegC;
}



/***********************************************************
 * @name getBaroValue
 * @brief Barometric pressure in hPa
 * @returns baroPressureHpa
 * @note 1 kPa = 10 hPa | 1 hPa = 1 millibar
 ***/
double Sensors::getBaroValue() {
	
	Hardware _hardware;
	Messages _message;

	extern struct Configuration config;
	extern struct Pins pins;

	double baroPressureHpa;
	int32_t  baroPressureHpa_INT;
	int32_t  unusedTemp;   
	int32_t  unusedRH;   
	int32_t  unusedGas;   


	switch (config.BARO_SENSOR_TYPE) {

		case LINEAR_ANALOG: {
			long rawBaroValue = analogRead(pins.REF_BARO_PIN);
			double baroVolts = rawBaroValue * (_hardware.get3v3SupplyVolts() / 4095.0);
			baroVolts += config.BARO_MV_TRIMPOT;		
			baroPressureHpa = baroVolts * config.BARO_ANALOG_SCALE;
			baroPressureHpa += config.BARO_FINE_ADJUST;
			break;
		}

		case MPX4115: {
			// Datasheet - https://html.alldatasheet.es/html-pdf/5178/MOTOROLA/MPX4115/258/1/MPX4115.html
			// Vout = VS (P x 0.009 – 0.095) --- Where VS = Supply Voltage (Formula from Datasheet)
			baroPressureHpa = map(_hardware.getADCRawData(config.BARO_ADC_CHANNEL), 0, 4095, 15000, 115000);
			baroPressureHpa += config.BARO_FINE_ADJUST;
			break;
		}

		case BOSCH_BME280: {
			baroPressureHpa = _BME280Sensor.readFixedPressure() / 100.00F; 
			break;
		}

		case BOSCH_BME680: {
			// _BME680Sensor.getSensorData(unusedTemp, unusedRH, baroPressureHpa_INT, unusedGas);
			// baroPressureHpa = baroPressureHpa_INT / 100.00F; 
			// break;
		}

		case REF_PRESS_AS_BARO: {
			// No baro sensor defined so use value grabbed at startup from reference pressure sensor
			// NOTE will only work for absolute style pressure sensor like the MPX4250
			baroPressureKpa = startupBaroPressure; 
			baroPressureKpa += config.BARO_FINE_ADJUST;
			break;
		}

		default: {
			baroPressureKpa = config.FIXED_BARO_VALUE;
			break;
		}
	}


	_message.debugPrintf("config.BARO_SENSOR_TYPE %d\n",config.BARO_SENSOR_TYPE);

	// Truncate to 2 decimal places
	// int value = baroPressureKpa * 100 + .5;
    // return (double)value / 100;

	// if (config.BARO_FINE_ADJUST != 0) baroPressureKpa += config.BARO_FINE_ADJUST;
	baroPressureHpa += config.BARO_FINE_ADJUST;
	return baroPressureHpa;

}



/***********************************************************
 * @name getRelHValue
 * @brief Returns Relative Humidity in %
 * @returns relativeHumidity
 ***/
double Sensors::getRelHValue() {
	
	Hardware _hardware;
	Messages _message;

	extern struct Configuration config;
	extern struct Pins pins;

	double relativeHumidity;
	int32_t  relativeHumidity_INT;
	int32_t  unusedTemp;   
	int32_t  unusedBaro;   
	int32_t  unusedGas;   		

	switch (config.RELH_SENSOR_TYPE){

		case LINEAR_ANALOG: {
			long rawRelhValue = analogRead(pins.HUMIDITY_PIN);
			double relhVolts = rawRelhValue * (_hardware.get3v3SupplyVolts() / 4095.0);
			relhVolts += config.RELH_MV_TRIMPOT;		
			relativeHumidity = relhVolts * config.RELH_ANALOG_SCALE;
			relativeHumidity += config.RELH_FINE_ADJUST;
			break;
		}

		case SIMPLE_TEMP_DHT11: {
			// NOTE DHT11 sampling rate is max 1HZ. We may need to slow down read rate to every few secs
			// int err = SimpleDHTErrSuccess;
			// if ((err = dht11.read(&refTemp, &refRelh, NULL)) != SimpleDHTErrSuccess) {
			// _message.Handler(language.LANG_DHT11_READ_FAIL); // Set error to display on screen
			// relativeHumidity = 0;        
			// } else {
			// relativeHumidity = refRelh;
			// }
			// relativeHumidity + config.RELH_FINE_ADJUST;
			break;
		}

		case BOSCH_BME280: {
			relativeHumidity = _BME280Sensor.readFixedHumidity() / 1000.00F;
			break;
		}

		case BOSCH_BME680: {
			// _BME680Sensor.getSensorData(unusedTemp, relativeHumidity_INT, unusedBaro, unusedGas);
			// relativeHumidity = relativeHumidity_INT / 1000.00F;
			break;
		}

		default: {
			relativeHumidity = config.FIXED_RELH_VALUE; // (36%)
			break;
		}


	}


	// if (config.RELH_FINE_ADJUST != 0) relativeHumidity += config.RELH_FINE_ADJUST;
	relativeHumidity += config.RELH_FINE_ADJUST;
	return relativeHumidity;
	
}