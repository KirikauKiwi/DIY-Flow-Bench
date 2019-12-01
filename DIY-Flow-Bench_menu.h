/*
    The code in this file uses open source libraries provided by thecoderscorner

    DO NOT EDIT THIS FILE, IT WILL BE GENERATED EVERY TIME YOU USE THE UI DESIGNER
    INSTEAD EITHER PUT CODE IN YOUR SKETCH OR CREATE ANOTHER SOURCE FILE.

    All the variables you may need access to are marked extern in this file for easy
    use elsewhere.
 */

#ifndef MENU_GENERATED_CODE_H
#define MENU_GENERATED_CODE_H

#include <tcMenu.h>
#include <IoAbstractionWire.h>
#include <LiquidCrystalIO.h>
#include <Wire.h>
#include <RuntimeMenuItem.h>
#include "tcMenuLiquidCrystal.h"

// all define statements needed
#define TCMENU_USING_PROGMEM true
#define LCD_WIDTH 20
#define LCD_HEIGHT 4
#define ENCODER_PIN_A 2
#define ENCODER_PIN_B 3
#define ENCODER_PIN_OK 4

// all variables that need exporting
extern LiquidCrystal lcd;
extern LiquidCrystalRenderer renderer;

// all menu item forward references.
extern TextMenuItem menuSettingsLeakTestCheck;
extern ActionMenuItem menuSettingsLeakTestCal;
extern ActionMenuItem menuSettingsHighFlowCal;
extern ActionMenuItem menuSettingsLowFlowCal;
extern TextMenuItem menuSettingsDevBuild;
extern TextMenuItem menuSettingsCodeVersion;
extern BackMenuItem menuBackSettings;
extern SubMenuItem menuSettings;
extern AnalogMenuItem menuAdjustedFlow;
extern AnalogMenuItem menuDesiredRef;
extern AnalogMenuItem menuPitot;
extern AnalogMenuItem menuTemperature;
extern AnalogMenuItem menuRefPressure;
extern AnalogMenuItem menuFlowRate;
extern const ConnectorLocalInfo applicationInfo;

// Callback functions must always include CALLBACK_FUNCTION after the return type
#define CALLBACK_FUNCTION

void CALLBACK_FUNCTION setHighFlowCalibrationValue(int id);
void CALLBACK_FUNCTION setLeakCalibrationValue(int id);
void CALLBACK_FUNCTION setLowFlowCalibrationValue(int id);

void setupMenu();

#endif // MENU_GENERATED_CODE_H
