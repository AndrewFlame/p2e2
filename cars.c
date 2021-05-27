#include <stdio.h>
#include <string.h>
#include <stdbool.h>
void menu();
struct car{
	
	char model[50];
	float price;
	int construct_year;
	
	
}car[100];


int main(){
	
	int CarsCreated = 0;
	
	int check_year;
	int i;
	for(i=0; i<100; i++){
	
	printf("Car Number: %d#\n" , i+1);
	printf("Give Construct Year: "); scanf("%d" , &check_year);
	if(check_year == -1)
		break;
	
	else car[i].construct_year = check_year; 		
	getchar();	
	printf("Give Model: "); gets(car[i].model);
	printf("Give Price: ");	scanf("%f" , &car[i].price);
	
	CarsCreated++;
	
		printf("\n");	
	}
	menu();
	
	int ch;
	scanf("%d" , &ch);
	if(ch < 1 || ch > 3){
		printf("\n\nOut of Bounds.. Exiting.");
		return 0;
	}

	
	while(ch != 3){
		
		if(ch == 1){
			getchar();
			char CarModel[50];
			printf("Give Car Model for Search: ");
			gets(CarModel); 
			
			// Display All Cars
			if(strcmp(CarModel , "*") == 0){
				int i;
				for(i=0; i<CarsCreated; i++){
					printf("Car %d#\n" , i+1);
					printf("Car Model: %s\n" , car[i].model);
					printf("Car Price: %f\n" , car[i].price);
					printf("Car Construct Year: %d\n\n" , car[i].construct_year);
				}
			}
			
	
			bool found = false;
			// Car Model 
			int i;
			for(i=0; i<CarsCreated; i++){
				
				if(strcmp(CarModel , car[i].model) == 0)
				{
					found = true;
					printf("Car Model: %s\n" , car[i].model);
					printf("Car Price: %f\n" , car[i].price);
					printf("Car Construct Year: %d\n\n" , car[i].construct_year);
				}	
				else continue;
			}
			
			if(strcmp(CarModel , "*") != 0 && found == false)
			printf("Car Model: %s Doesn't Exist"  , CarModel); // Car Model Doesn't Exist
		}
		else{
			
			float Price;
			printf("Insert Price: "); scanf("%f" , &Price);
			int i;
			for(i=0; i<CarsCreated; i++){
				if(car[i].price > Price)
					{
					printf("Car Model: %s\n" , car[i].model);
					printf("Car Price: %f\n" , car[i].price);
					printf("Car Construct Year: %d\n\n" , car[i].construct_year);
					}
			}	
		}
		menu();
		scanf("%d" , &ch);
	}
	
	
	
	printf("\n\n Have a Nice Day");
	return 0;
}

void menu(){
	printf("\n\n\n");
	printf("(1) Display Model\n");
	printf("(2) Display Model Based on Price\n");
	printf("(3) Quit / Exit\n\n");
	
	printf("Insert Answer: ");
	
}
