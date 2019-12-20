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
#include <LiquidCrystalIO.h>
#include <IoAbstraction.h>
#include <DfRobotInputAbstraction.h>
#include <RuntimeMenuItem.h>
#include "tcMenuLiquidCrystal.h"

// all define statements needed
#define TCMENU_USING_PROGMEM true

// all variables that need exporting
extern LiquidCrystal lcd;
extern LiquidCrystalRenderer renderer;

// all menu item forward references.
extern ActionMenuItem menuSettingsCalFlow;
extern ActionMenuItem menuSettingsCalRefPress;
extern TextMenuItem menuSettingsLeakTestChk;
extern ActionMenuItem menuSettingsLeakTestCal;
extern TextMenuItem menuSettingsBld;
extern TextMenuItem menuSettingsVer;
extern BackMenuItem menuBackSettings;
extern SubMenuItem menuSettings;
extern AnalogMenuItem menuAFlow;
extern AnalogMenuItem menuARef;
extern AnalogMenuItem menuPitot;
extern AnalogMenuItem menuTemp;
extern AnalogMenuItem menuPRef;
extern AnalogMenuItem menuFlow;
extern const ConnectorLocalInfo applicationInfo;

// Callback functions must always include CALLBACK_FUNCTION after the return type
#define CALLBACK_FUNCTION

void CALLBACK_FUNCTION checkLeakCalibrationValue(int id);
void CALLBACK_FUNCTION setCalibrationOffset(int id);
void CALLBACK_FUNCTION setLeakCalibrationValue(int id);
void CALLBACK_FUNCTION setRefPressCalibrationValue(int id);

void setupMenu();

#endif // MENU_GENERATED_CODE_H
