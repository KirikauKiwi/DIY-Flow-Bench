// exampleSensor.h

// This is an example MAF Data file
// You can either use volts versus kg/hr as below, or 1024 analog data points versus kg/hr
// Just change the values below to suit. Array length and voltage intervals are not an issue, add extra items as necessary.

// NOTE: all data values used for MAF lookup are integers. This is to reduce overheads and simplify code. 
// It also allows us to use both millivolts and RAW analog references in the same code without having to worry about changing datatypes
// So to populate the table you will probably have to translate your values as follows:
// millivolts (volts/100), kgh/1000 

// example - the first two entries below are 0.1 volts and 6.226 kg/hr
// we multiply volts by 1000 to get millivolts - 0.1 x 1000 = 100
// we multiply kg/hr by 1000 to provide 3 decimal places in integer format - 6.226 x 1000 = 6226

long mafMapData[][2] = {
{100,6226},
{200,6745},
{300,7307},
{400,7917},
{500,8577},
{600,9292},
{700,10067},
{800,10907},
{900,11816},
{1000,12802},
{1100,13869},
{1200,15026},
{1300,16279},
{1400,17637},
{1500,19108},
{1600,20701},
{1700,22428},
{1800,24298},
{1900,26324},
{2000,28520},
{2100,30898},
{2200,33475},
{2300,36266},
{2400,39291},
{2500,42567},
{2600,46117},
{2700,49963},
{2800,54130},
{2900,58644},
{3000,63535},
{3100,68833},
{3200,74574},
{3300,80793},
{3400,87531},
{3500,94830},
{3600,102739},
{3700,111307},
{3800,120589},
{3900,130646},
{4000,141541},
{4100,153345},
{4200,166133},
{4300,179988},
{4400,194998},
{4500,211260},
{4600,228878},
{4700,247965},
{4800,268644},
{4900,291048},
{5000,315320}
};