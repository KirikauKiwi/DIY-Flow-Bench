/***********************************************************
 * ACDELCO-92281162.h
 *
 * Manufacturer: AC Delco
 * Part#: 92281162
 * MAF file for type: GM / Holden VZ & VE / Corvette / LS2 engines
 * File units = 10 * mg/sec
 * Comments: Original data from Megasquirt website - www.microsquirt.info/maffactor_lsx.inc
 * Status: Validated
 * Support: https://github.com/DeeEmm/DIY-Flow-Bench/wiki/MAF-Data-Files
 * Discussion: https://github.com/DeeEmm/DIY-Flow-Bench/discussions/51
 ***/
#ifndef MAFDATACLASS
#define MAFDATACLASS

#include <Arduino.h>
#include "../constants.h"
#include "mafData/maf.h"



/***********************************************************
 * @brief MAF Class Constructor
 * @note: See exampleMafData.h for explaination and example
 * 
 ***/
Maf::Maf() {
}



/***********************************************************
 * @brief MAF Type
 * 
 * @note Description of MAF type
 *
 ***/
String Maf::getMafSensorType() {
    return "ACDELCO_92281162";
}



/***********************************************************
 * @brief MAF Output Type
 *
 * @note Valid options:
 * VOLTAGE
 * FREQUENCY
 ***/
int Maf::getMafOutputType() {
    return VOLTAGE;
}



/***********************************************************
 * @brief MAF Units
 * 
 * @note: Valid options:
 * KG_H
 * MG_S
 ***/
int Maf::getMafUnits() {
    return MG_S;
}



/***********************************************************
 * @brief mafLookupTable
 * @note Global vector of vectors containing MAF>Flow key>value pairs
 ***/
// std::vector<std::vector<int>> Maf::mafLookupTable = new std::vector<std::vector<int>> {{ // declare on heap using pointer
 std::vector<std::vector<int>> mafLookupTable = {{ 
    {0,0},
    {1,177},
    {2,181},
    {3,184},
    {4,188},
    {5,191},
    {6,195},
    {7,199},
    {8,203},
    {9,207},
    {10,211},
    {11,214},
    {12,218},
    {13,223},
    {14,227},
    {15,231},
    {16,235},
    {17,239},
    {18,244},
    {19,248},
    {20,253},
    {21,257},
    {22,262},
    {23,266},
    {24,271},
    {25,276},
    {26,281},
    {27,286},
    {28,291},
    {29,296},
    {30,301},
    {31,306},
    {32,311},
    {33,316},
    {34,322},
    {35,327},
    {36,332},
    {37,338},
    {38,343},
    {39,349},
    {40,355},
    {41,361},
    {42,366},
    {43,372},
    {44,378},
    {45,384},
    {46,391},
    {47,397},
    {48,403},
    {49,409},
    {50,416},
    {51,422},
    {52,429},
    {53,435},
    {54,442},
    {55,449},
    {56,456},
    {57,463},
    {58,470},
    {59,477},
    {60,484},
    {61,491},
    {62,499},
    {63,506},
    {64,513},
    {65,521},
    {66,529},
    {67,536},
    {68,544},
    {69,552},
    {70,560},
    {71,568},
    {72,576},
    {73,584},
    {74,593},
    {75,601},
    {76,610},
    {77,618},
    {78,627},
    {79,635},
    {80,644},
    {81,653},
    {82,662},
    {83,671},
    {84,680},
    {85,690},
    {86,699},
    {87,709},
    {88,718},
    {89,728},
    {90,737},
    {91,747},
    {92,757},
    {93,767},
    {94,777},
    {95,787},
    {96,798},
    {97,808},
    {98,819},
    {99,829},
    {100,840},
    {101,851},
    {102,862},
    {103,873},
    {104,884},
    {105,895},
    {106,906},
    {107,918},
    {108,929},
    {109,941},
    {110,952},
    {111,964},
    {112,976},
    {113,988},
    {114,1000},
    {115,1012},
    {116,1025},
    {117,1037},
    {118,1050},
    {119,1062},
    {120,1075},
    {121,1088},
    {122,1101},
    {123,1114},
    {124,1128},
    {125,1141},
    {126,1154},
    {127,1168},
    {128,1182},
    {129,1195},
    {130,1209},
    {131,1223},
    {132,1238},
    {133,1252},
    {134,1266},
    {135,1281},
    {136,1295},
    {137,1310},
    {138,1325},
    {139,1340},
    {140,1355},
    {141,1370},
    {142,1386},
    {143,1401},
    {144,1417},
    {145,1433},
    {146,1448},
    {147,1464},
    {148,1481},
    {149,1497},
    {150,1513},
    {151,1530},
    {152,1546},
    {153,1563},
    {154,1580},
    {155,1597},
    {156,1614},
    {157,1632},
    {158,1649},
    {159,1667},
    {160,1684},
    {161,1702},
    {162,1720},
    {163,1738},
    {164,1756},
    {165,1775},
    {166,1793},
    {167,1812},
    {168,1831},
    {169,1850},
    {170,1869},
    {171,1888},
    {172,1907},
    {173,1927},
    {174,1947},
    {175,1966},
    {176,1986},
    {177,2007},
    {178,2027},
    {179,2047},
    {180,2068},
    {181,2088},
    {182,2109},
    {183,2130},
    {184,2151},
    {185,2173},
    {186,2194},
    {187,2216},
    {188,2238},
    {189,2259},
    {190,2282},
    {191,2304},
    {192,2326},
    {193,2349},
    {194,2371},
    {195,2394},
    {196,2417},
    {197,2440},
    {198,2464},
    {199,2487},
    {200,2511},
    {201,2535},
    {202,2559},
    {203,2583},
    {204,2607},
    {205,2632},
    {206,2656},
    {207,2681},
    {208,2706},
    {209,2731},
    {210,2756},
    {211,2782},
    {212,2808},
    {213,2833},
    {214,2859},
    {215,2886},
    {216,2912},
    {217,2938},
    {218,2965},
    {219,2992},
    {220,3019},
    {221,3046},
    {222,3074},
    {223,3101},
    {224,3129},
    {225,3157},
    {226,3185},
    {227,3213},
    {228,3242},
    {229,3270},
    {230,3299},
    {231,3328},
    {232,3357},
    {233,3387},
    {234,3416},
    {235,3446},
    {236,3476},
    {237,3506},
    {238,3536},
    {239,3567},
    {240,3598},
    {241,3629},
    {242,3660},
    {243,3691},
    {244,3722},
    {245,3754},
    {246,3786},
    {247,3818},
    {248,3850},
    {249,3883},
    {250,3915},
    {251,3948},
    {252,3981},
    {253,4014},
    {254,4048},
    {255,4082},
    {256,4115},
    {257,4149},
    {258,4184},
    {259,4218},
    {260,4253},
    {261,4288},
    {262,4323},
    {263,4358},
    {264,4394},
    {265,4429},
    {266,4465},
    {267,4501},
    {268,4538},
    {269,4574},
    {270,4611},
    {271,4648},
    {272,4685},
    {273,4722},
    {274,4760},
    {275,4798},
    {276,4836},
    {277,4874},
    {278,4913},
    {279,4951},
    {280,4990},
    {281,5030},
    {282,5069},
    {283,5108},
    {284,5148},
    {285,5188},
    {286,5229},
    {287,5269},
    {288,5310},
    {289,5351},
    {290,5392},
    {291,5433},
    {292,5475},
    {293,5517},
    {294,5559},
    {295,5601},
    {296,5644},
    {297,5687},
    {298,5730},
    {299,5773},
    {300,5816},
    {301,5860},
    {302,5904},
    {303,5948},
    {304,5993},
    {305,6037},
    {306,6082},
    {307,6128},
    {308,6173},
    {309,6219},
    {310,6265},
    {311,6311},
    {312,6357},
    {313,6404},
    {314,6451},
    {315,6498},
    {316,6545},
    {317,6593},
    {318,6641},
    {319,6689},
    {320,6737},
    {321,6786},
    {322,6835},
    {323,6884},
    {324,6933},
    {325,6983},
    {326,7033},
    {327,7083},
    {328,7134},
    {329,7184},
    {330,7235},
    {331,7286},
    {332,7338},
    {333,7390},
    {334,7442},
    {335,7494},
    {336,7546},
    {337,7599},
    {338,7652},
    {339,7706},
    {340,7759},
    {341,7813},
    {342,7867},
    {343,7922},
    {344,7976},
    {345,8031},
    {346,8087},
    {347,8142},
    {348,8198},
    {349,8254},
    {350,8310},
    {351,8367},
    {352,8424},
    {353,8481},
    {354,8538},
    {355,8596},
    {356,8654},
    {357,8713},
    {358,8771},
    {359,8830},
    {360,8889},
    {361,8949},
    {362,9008},
    {363,9068},
    {364,9129},
    {365,9189},
    {366,9250},
    {367,9311},
    {368,9373},
    {369,9435},
    {370,9497},
    {371,9559},
    {372,9622},
    {373,9685},
    {374,9748},
    {375,9812},
    {376,9875},
    {377,9940},
    {378,10004},
    {379,10069},
    {380,10134},
    {381,10199},
    {382,10265},
    {383,10331},
    {384,10397},
    {385,10464},
    {386,10531},
    {387,10598},
    {388,10665},
    {389,10733},
    {390,10801},
    {391,10870},
    {392,10938},
    {393,11008},
    {394,11077},
    {395,11147},
    {396,11217},
    {397,11287},
    {398,11358},
    {399,11429},
    {400,11500},
    {401,11572},
    {402,11644},
    {403,11716},
    {404,11788},
    {405,11861},
    {406,11935},
    {407,12008},
    {408,12082},
    {409,12156},
    {410,12231},
    {411,12306},
    {412,12381},
    {413,12457},
    {414,12532},
    {415,12609},
    {416,12685},
    {417,12762},
    {418,12839},
    {419,12917},
    {420,12995},
    {421,13073},
    {422,13152},
    {423,13231},
    {424,13310},
    {425,13390},
    {426,13470},
    {427,13550},
    {428,13631},
    {429,13712},
    {430,13793},
    {431,13875},
    {432,13957},
    {433,14039},
    {434,14122},
    {435,14205},
    {436,14288},
    {437,14372},
    {438,14456},
    {439,14541},
    {440,14626},
    {441,14711},
    {442,14797},
    {443,14883},
    {444,14969},
    {445,15056},
    {446,15143},
    {447,15230},
    {448,15318},
    {449,15406},
    {450,15495},
    {451,15583},
    {452,15673},
    {453,15762},
    {454,15852},
    {455,15943},
    {456,16033},
    {457,16124},
    {458,16216},
    {459,16308},
    {460,16400},
    {461,16493},
    {462,16586},
    {463,16679},
    {464,16773},
    {465,16867},
    {466,16961},
    {467,17056},
    {468,17152},
    {469,17247},
    {470,17343},
    {471,17440},
    {472,17537},
    {473,17634},
    {474,17731},
    {475,17829},
    {476,17928},
    {477,18026},
    {478,18126},
    {479,18225},
    {480,18325},
    {481,18426},
    {482,18526},
    {483,18627},
    {484,18729},
    {485,18831},
    {486,18933},
    {487,19036},
    {488,19139},
    {489,19243},
    {490,19347},
    {491,19451},
    {492,19556},
    {493,19661},
    {494,19767},
    {495,19873},
    {496,19979},
    {497,20086},
    {498,20193},
    {499,20301},
    {500,20409},
    {501,20517},
    {502,20626},
    {503,20736},
    {504,20845},
    {505,20956},
    {506,21066},
    {507,21177},
    {508,21289},
    {509,21401},
    {510,21513},
    {511,21626},
    {512,21739},
    {513,21852},
    {514,21966},
    {515,22081},
    {516,22196},
    {517,22311},
    {518,22427},
    {519,22543},
    {520,22659},
    {521,22776},
    {522,22894},
    {523,23012},
    {524,23130},
    {525,23249},
    {526,23368},
    {527,23488},
    {528,23608},
    {529,23728},
    {530,23849},
    {531,23971},
    {532,24093},
    {533,24215},
    {534,24338},
    {535,24461},
    {536,24585},
    {537,24709},
    {538,24834},
    {539,24959},
    {540,25084},
    {541,25210},
    {542,25336},
    {543,25463},
    {544,25591},
    {545,25718},
    {546,25847},
    {547,25975},
    {548,26105},
    {549,26234},
    {550,26364},
    {551,26495},
    {552,26626},
    {553,26758},
    {554,26890},
    {555,27022},
    {556,27155},
    {557,27288},
    {558,27422},
    {559,27557},
    {560,27692},
    {561,27827},
    {562,27963},
    {563,28099},
    {564,28236},
    {565,28373},
    {566,28511},
    {567,28649},
    {568,28787},
    {569,28927},
    {570,29066},
    {571,29206},
    {572,29347},
    {573,29488},
    {574,29630},
    {575,29772},
    {576,29915},
    {577,30058},
    {578,30201},
    {579,30345},
    {580,30490},
    {581,30635},
    {582,30781},
    {583,30927},
    {584,31073},
    {585,31220},
    {586,31368},
    {587,31516},
    {588,31665},
    {589,31814},
    {590,31963},
    {591,32113},
    {592,32264},
    {593,32415},
    {594,32567},
    {595,32719},
    {596,32872},
    {597,33025},
    {598,33179},
    {599,33333},
    {600,33488},
    {601,33643},
    {602,33799},
    {603,33955},
    {604,34112},
    {605,34269},
    {606,34427},
    {607,34585},
    {608,34744},
    {609,34904},
    {610,35064},
    {611,35224},
    {612,35385},
    {613,35547},
    {614,35709},
    {615,35872},
    {616,36035},
    {617,36199},
    {618,36363},
    {619,36528},
    {620,36693},
    {621,36859},
    {622,37026},
    {623,37193},
    {624,37360},
    {625,37528},
    {626,37697},
    {627,37866},
    {628,38036},
    {629,38206},
    {630,38377},
    {631,38548},
    {632,38720},
    {633,38892},
    {634,39066},
    {635,39239},
    {636,39413},
    {637,39588},
    {638,39763},
    {639,39939},
    {640,40115},
    {641,40292},
    {642,40470},
    {643,40648},
    {644,40827},
    {645,41006},
    {646,41186},
    {647,41366},
    {648,41547},
    {649,41729},
    {650,41911},
    {651,42093},
    {652,42276},
    {653,42460},
    {654,42645},
    {655,42830},
    {656,43015},
    {657,43201},
    {658,43388},
    {659,43575},
    {660,43763},
    {661,43952},
    {662,44141},
    {663,44330},
    {664,44521},
    {665,44711},
    {666,44903},
    {667,45095},
    {668,45287},
    {669,45481},
    {670,45674},
    {671,45869},
    {672,46064},
    {673,46259},
    {674,46456},
    {675,46652},
    {676,46850},
    {677,47048},
    {678,47246},
    {679,47446},
    {680,47645},
    {681,47846},
    {682,48047},
    {683,48249},
    {684,48451},
    {685,48654},
    {686,48857},
    {687,49061},
    {688,49266},
    {689,49471},
    {690,49677},
    {691,49884},
    {692,50091},
    {693,50299},
    {694,50507},
    {695,50716},
    {696,50926},
    {697,51136},
    {698,51347},
    {699,51559},
    {700,51771},
    {701,51984},
    {702,52197},
    {703,52412},
    {704,52626},
    {705,52842},
    {706,53058},
    {707,53274},
    {708,53492},
    {709,53710},
    {710,53928},
    {711,54147},
    {712,54367},
    {713,54588},
    {714,54809},
    {715,55031},
    {716,55253},
    {717,55476},
    {718,55700},
    {719,55925},
    {720,56150},
    {721,56375},
    {722,56602},
    {723,56829},
    {724,57057},
    {725,57285},
    {726,57514},
    {727,57744},
    {728,57974},
    {729,58205},
    {730,58437},
    {731,58669},
    {732,58902},
    {733,59136},
    {734,59370},
    {735,59605},
    {736,59841},
    {737,60077},
    {738,60314},
    {739,60552},
    {740,60791},
    {741,61030},
    {742,61269},
    {743,61510},
    {744,61751},
    {745,61993},
    {746,62235},
    {747,62478},
    {748,62722},
    {749,62967},
    {750,63212},
    {751,63458},
    {752,63705},
    {753,63952},
    {754,64200},
    {755,64449},
    {756,64698},
    {757,64948},
    {758,65199},
    {759,65451},
    {760,65703},
    {761,65956},
    {762,66210},
    {763,66464},
    {764,66719},
    {765,66975},
    {766,67231},
    {767,67488},
    {768,67746},
    {769,68005},
    {770,68264},
    {771,68524},
    {772,68785},
    {773,69046},
    {774,69309},
    {775,69571},
    {776,69835},
    {777,70099},
    {778,70365},
    {779,70630},
    {780,70897},
    {781,71164},
    {782,71432},
    {783,71701},
    {784,71970},
    {785,72240},
    {786,72511},
    {787,72783},
    {788,73055},
    {789,73328},
    {790,73602},
    {791,73877},
    {792,74152},
    {793,74428},
    {794,74705},
    {795,74983},
    {796,75261},
    {797,75540},
    {798,75820},
    {799,76100},
    {800,76382},
    {801,76664},
    {802,76947},
    {803,77230},
    {804,77515},
    {805,77800},
    {806,78086},
    {807,78372},
    {808,78660},
    {809,78948},
    {810,79237},
    {811,79526},
    {812,79817},
    {813,80108},
    {814,80400},
    {815,80693},
    {816,80986},
    {817,81280},
    {818,81575},
    {819,81871},
    {820,82168},
    {821,82465},
    {822,82763},
    {823,83062},
    {824,83362},
    {825,83662},
    {826,83964},
    {827,84266},
    {828,84569},
    {829,84872},
    {830,85177},
    {831,85482},
    {832,85788},
    {833,86095},
    {834,86402},
    {835,86711},
    {836,87020},
    {837,87330},
    {838,87641},
    {839,87952},
    {840,88265},
    {841,88578},
    {842,88892},
    {843,89207},
    {844,89522},
    {845,89839},
    {846,90156},
    {847,90474},
    {848,90793},
    {849,91113},
    {850,91433},
    {851,91754},
    {852,92077},
    {853,92400},
    {854,92723},
    {855,93048},
    {856,93373},
    {857,93699},
    {858,94027},
    {859,94354},
    {860,94683},
    {861,95013},
    {862,95343},
    {863,95674},
    {864,96006},
    {865,96339},
    {866,96673},
    {867,97007},
    {868,97343},
    {869,97679},
    {870,98016},
    {871,98354},
    {872,98692},
    {873,99032},
    {874,99372},
    {875,99714},
    {876,100056},
    {877,100399},
    {878,100743},
    {879,101087},
    {880,101433},
    {881,101779},
    {882,102126},
    {883,102475},
    {884,102823},
    {885,103173},
    {886,103524},
    {887,103875},
    {888,104228},
    {889,104581},
    {890,104935},
    {891,105290},
    {892,105646},
    {893,106003},
    {894,106360},
    {895,106719},
    {896,107078},
    {897,107438},
    {898,107800},
    {899,108162},
    {900,108524},
    {901,108888},
    {902,109253},
    {903,109618},
    {904,109985},
    {905,110352},
    {906,110720},
    {907,111089},
    {908,111459},
    {909,111830},
    {910,112202},
    {911,112574},
    {912,112948},
    {913,113322},
    {914,113698},
    {915,114074},
    {916,114451},
    {917,114829},
    {918,115208},
    {919,115588},
    {920,115968},
    {921,116350},
    {922,116733},
    {923,117116},
    {924,117501},
    {925,117886},
    {926,118272},
    {927,118659},
    {928,119047},
    {929,119436},
    {930,119826},
    {931,120217},
    {932,120609},
    {933,121001},
    {934,121395},
    {935,121789},
    {936,122185},
    {937,122581},
    {938,122978},
    {939,123376},
    {940,123776},
    {941,124176},
    {942,124577},
    {943,124979},
    {944,125382},
    {945,125785},
    {946,126190},
    {947,126596},
    {948,127003},
    {949,127410},
    {950,127819},
    {951,128228},
    {952,128639},
    {953,129050},
    {954,129462},
    {955,129876},
    {956,130290},
    {957,130705},
    {958,131121},
    {959,131538},
    {960,131957},
    {961,132376},
    {962,132796},
    {963,133217},
    {964,133639},
    {965,134061},
    {966,134485},
    {967,134910},
    {968,135336},
    {969,135763},
    {970,136191},
    {971,136619},
    {972,137049},
    {973,137480},
    {974,137911},
    {975,138344},
    {976,138778},
    {977,139212},
    {978,139648},
    {979,140085},
    {980,140522},
    {981,140961},
    {982,141400},
    {983,141841},
    {984,142283},
    {985,142725},
    {986,143169},
    {987,143613},
    {988,144059},
    {989,144505},
    {990,144953},
    {991,145401},
    {992,145851},
    {993,146301},
    {994,146753},
    {995,147206},
    {996,147659},
    {997,148114},
    {998,148569},
    {999,149026},
    {1000,149484},
    {1001,149942},
    {1002,150402},
    {1003,150863},
    {1004,151324},
    {1005,151787},
    {1006,152251},
    {1007,152716},
    {1008,153182},
    {1009,153648},
    {1010,154116},
    {1011,154585},
    {1012,155055},
    {1013,155526},
    {1014,155998},
    {1015,156471},
    {1016,156945},
    {1017,157420},
    {1018,157897},
    {1019,158374},
    {1020,158852},
    {1021,159331},
    {1022,159812},
    {1023,160293},
    {1024,160775}
    }};




#endif