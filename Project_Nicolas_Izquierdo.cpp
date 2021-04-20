#include <iostream> //Needed for input and output operations
#include <iomanip> //Needed for formatting the output
#include <string> //Needed for using string class
using namespace std;

int gpuSpeed = 0; //To hold the GPU clock speed value
int cpuSpeed = 0; //To hold the CPU clock speed value
int cpuNum = 0; //To hold the number of cores of the processor
int select = 0; //To hold the user's choice from the resolution question
int compNum = 0; //To hold  the number of PCs being processed
int num = 0; //To be used in the for loop
double perfScore = 0.0; //To hold the perfomrance score
double highScore = 0.0, lowScore = 0.0; //To hold the highest and lowset scores for the running totals at the end
string recQual = ""; //To hold the monitor resolution as well as the recomended graphics quality

//Constants to hold the monitor's resolution
const string RES1 = "1280 x 720";
const string RES2 = "1920 x 1080";
const string RES3 = "2560 x 1440";
const string RES4 = "3840 x 2160";

//Constants to hold the multiplier value accordingly to its multiplier
const double MULTIPLIER_RES1 = 1;
const double MULTIPLIER_RES2 = 0.75;
const double MULTIPLIER_RES3 = 0.55;
const double MULTIPLIER_RES4 = 0.35;

//Constants to hold the performance threshold
const string PERF_ULTRA = "Ultra";
const string PERF_HIGH = "High";
const string PERF_MED = "Medium";
const string PERF_LOW = "Low";
const string PERF_UNABLE = "Unable to Play";

//Prototypes
void displayTitle();
string getResolutionString(int);
double getMultiplierValue(int);

int main()
{
	cout << "How many computers are being processed? ";
    cin >> compNum; //Read in the user's input for the number of computers being processed
    
    //Validate the user's input
    while(compNum <= 0)
    {
    	cout << "You've got to process at least 1 computer!" << endl;
    	cout << "How many computers are being processed? ";
    	cin >> compNum;
	}
	
	displayTitle();
	
	//Run the loop for as many times as the user requested
	for(num = 1; num <= compNum; num++)
	{
    	cout << "\nPlease enter the clock speed (in Megahertz) of your graphics card: ";
    	cin >> gpuSpeed; //Read in the user's input for clock speed of GPU
    	//Input validation to confirm the user entered a value between 800 and 2000
    	while(gpuSpeed < 800 || gpuSpeed > 2000)
    	{
    		cout << "Please enter a number between 800 and 2000!" << endl;
    		cout << "Please enter the clock speed (in Megahertz) of your graphics card: ";
    		cin >> gpuSpeed;
		}
    	
    	cout << "Please enter the clock speed (in Megahertz) of your processor: ";
    	cin >> cpuSpeed; //Read in the user's input for clock speed of CPU
    	//Input validation to confirm the user entered a value between 1000 and 5500
    	while(cpuSpeed < 1000 || cpuSpeed > 5500)
    	{
    		cout << "Please enter a number between 1000 and 5500!" << endl;
    		cout << "Please enter the clock speed (in Megahertz) of your processor: ";
    		cin >> cpuSpeed;
		}
    	
    	cout << "Please enter the number of cores in your processor: ";
    	cin >> cpuNum; //Read in the user's input for number of cores of CPU
    	while(cpuNum < 1 || cpuNum > 16) //Input validation to confirm the user entered a value
    	{
    		cout << "Please enter a number between 1 and 16!" << endl;
    		cout << "Please enter the number of cores in your processor: ";
    		cin >> cpuNum;
		}
    	
    	cout << "What is the resolution of your monitor?" << endl;
    	cout << "\t1. " << RES1 << endl;
    	cout << "\t2. " << RES2 << endl;
    	cout << "\t3. " << RES3 << endl;
    	cout << "\t4. " << RES4 << endl;
    	cout << "Please select from the options above: "; //Ask the user to make a choice
    	cin >> select; //Read in the user's input for monitor's resolution
    	
    	//Input validation to see if the user choose 1, 2, 3, or 4
    	while(select < 1 || select > 4)
    	{
    		cout << "Please enter 1, 2, 3, or 4!" << endl;
    		cout << "Please select from the options above: ";
    		cin >> select;
		}
    	
    	perfScore = ((5 * gpuSpeed) + (cpuNum * cpuSpeed)) * getMultiplierValue(select); //Use formula to get the performance score
    	
    	//Use if-else-if statement to assign recomended graphics quality to its respective performance score
    	if (perfScore > 17000) recQual = PERF_ULTRA;
    	else if ((perfScore > 15000) && (perfScore <= 17000)) recQual = PERF_HIGH;
    	else if ((perfScore > 13000) && (perfScore <= 15000)) recQual = PERF_MED;
    	else if ((perfScore > 11000) && (perfScore <= 13000)) recQual = PERF_LOW;
    	else recQual = PERF_UNABLE;
    	
    	//Display the user's specs as well as performance results
    	cout << "\nGPU Clock Speed: " << gpuSpeed << "MHz" << endl;
    	cout << "CPU Clock Speed: " << cpuSpeed << "MHz" << endl;
    	cout << "Number of Cores: " << cpuNum << endl;
    	cout << "Monitor Resolution: " << getResolutionString(select) << endl;
    	cout << "Performance score: " << setprecision(3) << fixed << perfScore << endl;
    	cout << "Recommended Graphics Quality: " << recQual << endl;
    	
    	//Check the largest and smallest value and apply them to their respective score
        if (num == 1) //This action will only be performed once in the first loop only 
		{       
            lowScore = perfScore;
            highScore = perfScore;
        }
        else if (perfScore > highScore) highScore = perfScore;
        else if (perfScore < lowScore) lowScore = perfScore;
	}
	
	cout << "\nThe highest performance score was: " << setprecision(2) << fixed << highScore << endl;
	cout << "The lowest performance score was: " << setprecision(2) << fixed << lowScore << endl;
}//End Main

void displayTitle()
{
	cout << "\n" << "Computer Hardware Graphics Quality Recommendation Tool" << endl;
}

string getResolutionString(int select)
{
	//Use awitch statement to handle the user's selection
	switch(select)
	{
		case 1:
			return RES1;
			break;
		case 2:
			return RES2;
			break;
		case 3:
			return RES3;
			break;
		case 4:
			return RES4;
			break;
	}
}

double getMultiplierValue(int select)
{
	//Use awitch statement to handle the user's selection
	switch(select)
	{
		case 1:
			return MULTIPLIER_RES1; //Use different numbers accordingly to multiplier 
			break;
		case 2:
			return MULTIPLIER_RES2;
			break;
		case 3:
			return MULTIPLIER_RES3; 
			break;
		case 4:
			return MULTIPLIER_RES4;
			break;
	}
}
