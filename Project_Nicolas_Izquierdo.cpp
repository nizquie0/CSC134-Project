#include <iostream> //Needed for input and output operations
#include <iomanip> //Needed for formatting the output
#include <string> //Needed for using string class
using namespace std;

int main()
{
	int gpuSpeed = 0; //To hold the GPU clock speed value
    int cpuSpeed = 0; //To hold the CPU clock speed value
    int cpuNum = 0; //To hold the number of cores of the processor
    int select = 0; //To hold the user's choice from the resolution question
    int compNum = 0; //To hold  the number of PCs being processed
    double perfScore = 0.0; //To hold the perfomrance score
    string res = "", recQual = ""; //To hold the monitor resolution as well as the recomended graphics quality
    
	cout << "How many computers are being processed? ";
    cin >> compNum; //Read in the user's input for the number of computers being processed
    
    //Validate the user's input
    while(compNum <= 0)
    {
    	cout << "You've got to process at least 1 computer!" << endl;
    	cout << "How many computers are being processed? ";
    	cin >> compNum;
	}
	
	cout << "\nComputer Hardware Graphics Quality Recommendation Tool" << endl;
	
	//Run the loop for as many times as the user requested
	for(int num = 1; num <= compNum; num++)
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
    	cout << "\t 1. 1280 x 720" << endl;
    	cout << "\t 2. 1920 x 1080" << endl;
    	cout << "\t 3. 2560 x 1440" << endl;
    	cout << "\t 4. 3840 x 2160" << endl;
    	cout << "Please select from the options above: "; //Ask the user to make a choice
    	cin >> select; //Read in the user's input for monitor's resolution
    	
    	//Input validation to see if the user choose 1, 2, 3, or 4
    	while(select < 1 || select > 4)
    	{
    		cout << "Please enter 1, 2, 3, or 4!" << endl;
    		cout << "Please select from the options above: ";
    		cin >> select;
		}
    	
    	//Use if-else-if statement to handle the user's selection
    	if (select == 1)
		{   
    		perfScore = ((5 * gpuSpeed) + (cpuNum * cpuSpeed)) * 1; //Use formula to get the performance score
        	res = "1280 x 720";       
    	}
    	else if (select == 2)
		{            
        	perfScore = ((5 * gpuSpeed) + (cpuNum * cpuSpeed)) * 0.75; //Use different numbers at the end according to multiplier
        	res = "1920 x 1080";    
    	}
    	else if (select == 3)
		{           
        	perfScore = ((5 * gpuSpeed) + (cpuNum * cpuSpeed)) * 0.55;
        	res = "2560 x 1440";           
    	}
    	else if (select == 4)
		{           
        	perfScore = ((5 * gpuSpeed) + (cpuNum * cpuSpeed)) * 0.35;
        	res = "3840 x 2160";       
    	}
    	
    	//Use if-else-if statement to assign recomended graphics quality to its respective performance score
    	if (perfScore > 17000) recQual = "Ultra";
    	else if ((perfScore > 15000) && (perfScore < 17000)) recQual = "High";
    	else if ((perfScore > 13000) && (perfScore < 15000)) recQual = "Medium";
    	else if ((perfScore > 11000) && (perfScore < 13000)) recQual = "Low";
    	else recQual = "Unable to Play";
    	
    	//Display the user's specs as well as performance results
    	cout << "\nComputer Hardware Graphics Quality Recommendation Tool\n" << endl;
    	cout << "GPU Clock Speed: " << gpuSpeed << "MHz" << endl;
    	cout << "CPU Clock Speed: " << cpuSpeed << "MHz" << endl;
    	cout << "Number of Cores: " << cpuNum << endl;
    	cout << "Monitor Resolution: " << res << endl;
    	cout << "Performance score: " << setprecision(2) << fixed << perfScore << endl;
    	cout << "Recommended Graphics Quality: " << recQual << endl;
	}
}//End Main
