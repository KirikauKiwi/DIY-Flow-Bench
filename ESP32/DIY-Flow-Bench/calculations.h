/***********************************************************
 * @name The DIY Flow Bench project
 * @details Measure and display volumetric air flow using an ESP32 & Automotive MAF sensor
 * @link https://diyflowbench.com
 * @author DeeEmm aka Mick Percy deeemm@deeemm.com
 * 
 * @file calculations.h
 * 
 * @brief Calculations class header file
 * 
 * @remarks For more information please visit the WIKI on our GitHub project page: https://github.com/DeeEmm/DIY-Flow-Bench/wiki
 * Or join our support forums: https://github.com/DeeEmm/DIY-Flow-Bench/discussions
 * You can also visit our Facebook community: https://www.facebook.com/groups/diyflowbench/
 * 
 * @license This project and all associated files are provided for use under the GNU GPL3 license:
 * https://github.com/DeeEmm/DIY-Flow-Bench/blob/master/LICENSE
 * 
 ***/
#pragma once
#include "constants.h"

class Calculations {

	friend class Sensors;
	friend class Hardware;
	
	private:
		double MOLECULAR_WEIGHT_DRY_AIR;
		bool streamMafData = false;
		
	public:
		Calculations();
		double convertFlowDepression(double oldPressure, double newPressure, double inputFlow);
		double convertPressure(double baroPressureKpa, int units);
		double convertTemperature(double refTempDegC, int units);
		double convertRelativeHumidity(double relativeHumidity, int units = DECI);

		double calculateVaporPressure(int units = PSIA);
		double calculateSpecificGravity();
		double convertMassFlowToVolumetric(double massFlowKgh);
		double calculateFlowCFM(int mafValue, int maxValue = 32767);
		double calculateAirDensity();

		double startupBaroPressure;

};
