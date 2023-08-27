#include<stdio.h>     //This project is meant for laboratory people who takes blood report it stores the details entered of patient or patients into a text file it takes details of 1000 people in one run.   
#include<stdlib.h>    // The Details should be printed out after every run because the text file gets updated after every run. 
#include<math.h>     
#include<conio.h>
int report (int,int,int); // This function returns a value which is used to determine blood group. 
void display(); // This function takes care what is to be printed inside file.
int i,n,a,b,o,ab,k; //global variables.
struct patient // This structure consists of variables which are needed to be entered by the laboratory member who tested the blood and details of patient is available. 
{
	char name[100]; 
	int age; 
	char gender[10]; 
	float height; 
	float weight; 
	float BMI;  
	float leucocyte_count; 
	float t_rbc;
	double platelet_count; 	
} patient[1000];  // Maximum limit of patients in one run is 1000.
int main() 
{    
    struct patient name,age,gender,height,weight,BMI;
	printf("Enter Number of Patients Report to be entered : "); 
	scanf("%d",&n);   
	printf("\n");  // next line consists of instructions.
	printf("You are about to give the details of patient this one thing is to be remembered : \n \n 1) Spacing doesn't work in name if you wish to give space in name use underscore('_').\n Example : Madhu_Kiran \n\n 2) Please Don't use spacebar while entering gender.\n Example : MA LE \n\n");
	for(i=0;i<n;i++)     //Entering details of patient or patients into structure array.
	{
		printf("Enter Patient's Name : ");     
		scanf("%s",patient[i].name);          // Stores patient's Name and using underscore is must instead of spacing.
		printf("\n"); 
		printf("Enter Patient's Age : ");               
		scanf("%d",&patient[i].age);         // Stores patient's Age.
		printf("\n");  
		printf("Enter Patient's Gender :");   
		scanf("%s",patient[i].gender);       // Stores patient's Gender and No Spacing is Allowed here. 
 		printf("\n"); 
		printf("Enter Patient's Height(In Meters) : ");
		scanf("%f",&patient[i].height);                  // Stores patient's Height and height should be entered in meters.
		printf("\n"); 
		printf("Enter Patient's Weight(In Kilograms) : ");
		scanf("%f",&patient[i].weight);                    // Stores patient's Weight and weight should be  entered in kilograms.
		printf("\n");  
		printf("Enter Patient's Platelet Count (per cmm) : "); 
		scanf("%lf",&patient[i].platelet_count);              // Stores patient's Platelet Count, Range(150000 to 4500000) for a healthy person.
		printf("\n"); 
		printf("Enter Patient's T-RBC (mil/cumm): "); 
		scanf("%f",&patient[i].t_rbc);                      //Stores patient's total red blood cell amount, Range(4.6 to 6.2) for a healthy person.
		printf("\n");  
		printf("Enter Patient's White Blood Cell count (per cmm) : "); 
		scanf("%f",&patient[i].leucocyte_count);            // Stores patient's white blood cell count,Range(4000 to 11000) for a healthy person.
		printf("\n");
	}  
	for(i=0;i<n;i++)  
	{
		display();       //function gets called n times.
	 } 
}
void display() 
{  
printf("\n"); 
FILE *FilePointer; 
FilePointer = fopen("BloodReport.txt","w"); // file in which output is displayed.
for(i=0;i<n;i++) 
{
fprintf(FilePointer,"____________________________________________________________________________________________________________________________________________________\n");
fprintf(FilePointer,"****************************************************  THIS IS PATIENT'S REPORT *********************************************************************\n\n"); 
fprintf(FilePointer,"NAME                              : %s \n \n",patient[i].name); 
fprintf(FilePointer,"AGE                               : %d \n \n",patient[i].age); 
fprintf(FilePointer,"GENDER                            : %s \n \n",patient[i].gender); 
fprintf(FilePointer,"HEIGHT                            : %f \n \n",patient[i].height);  
fprintf(FilePointer,"WEIGHT                            : %f \n \n",patient[i].weight); 
fprintf(FilePointer,"Body Mass Index                   : %f \n\n",patient[i].weight/pow(patient[i].height,2));  
fprintf(FilePointer,"Platelet Count                    : %lf \n\n",patient[i].platelet_count); 
fprintf(FilePointer,"Total Red Blood Cells             : %f \n\n",patient[i].t_rbc); 
fprintf(FilePointer,"Total White Blood Cells           : %f \n\n",patient[i].leucocyte_count);
k = report(a,b,ab); // The value returned by report() function is stored into the variable 'k'.
switch(k) 
{
	case 1: 
	fprintf(FilePointer,"The Blood Group of Patient is O-Positive \n"); 
	break;  
	case 2: 
	fprintf(FilePointer,"The Blood Group of Patient is O-Negative \n"); 
	break; 
	case 3: 
	fprintf(FilePointer,"The Blood Group of Patient is A-Positive \n"); 
	break; 
	case 4: 
	fprintf(FilePointer,"The Blood Group of Patient is A-Negative \n"); 
	break; 
	case 5: 
	fprintf(FilePointer,"The Blood Group of Patient is B-Positive \n"); 
	break; 
	case 6: 
	fprintf(FilePointer,"The Blood Group of Patient is B-Negative \n"); 
	break;  
	case 7: 
	fprintf(FilePointer,"The Blood Group of Patient is AB-Positive \n"); 
	break; 
	case 8: 
	fprintf(FilePointer,"The Blood Group of Patient is AB-Negative \n"); 
	break; 
	default: 
	fprintf(FilePointer,"Error! Wrong Input Please Try Again \n"); 	
}
fprintf(FilePointer,"\n**************************************************** ENDS OF PATIENT'S REPORT  *********************************************************************\n"); 
fprintf(FilePointer,"\n____________________________________________________________________________________________________________________________________________________\n"); 
if(i==n) 
{
	fclose(FilePointer); //The file will be closed after the details of all patients are entered.
}
} 	 // The file updates after every run.  
} 
int report(int a,int b,int ab) 
{    
    printf("Enter The Antigen Results '1' for Positive '0' for Negative : ");
	scanf("%d %d %d",&a,&b,&ab); 
	printf("\n");  
	if(a==1 && b==1 && ab==0) // The value which is returned here is used by display() function.
	{
		return 1; //Patient's Blood Group is O+ 
	} 
	else if(a==1 && b==1 && ab==1) 
	{
		return 2; //Patient's Blood Group is O-
	} 
	else if(a==0 && b==1 && ab==0) 
	{
		return 3; //Patient's Blood Group is A+
	} 
	else if(a==0 && b==1 && ab==1) 
	{
		return 4; //Patient's Blood Group is A-
	}  
	else if(a==1 && b==0 && ab==0) 
	{
		return 5; //Patient's Blood Group is B+
	}  
	else if(a==1 && b==0 && ab==1) 
	{
		return 6; //Patient's Blood Group is B-
    } 
    else if(a==0 && b==0 && ab==0) 
	{
		return 7; //Patient's Blood Group is AB+
	}  
	else if(a==0 && b==0 && ab==1) 
	{
		return 8; //Patient's Blood Group is AB-
	} 	 
}
