#include "work_with_files.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
void ShowAllFromFile(List* list, FILE* fPtr) {
	//system("cls");
	errno_t err;
	Flight temp;
	if ((err = fopen_s(&fPtr, "flights.dat", "r")) != 0) {
		printf("\n%s", "Global Fail...");
	}
	else {
		fseek(fPtr, 0, 0);
		fread(&temp, sizeof(Flight), 1, fPtr);
		while (!feof(fPtr)) {
			PrintFlight(temp);
			fread(&temp, sizeof(Flight), 1, fPtr);
		}
		fclose(fPtr);
	}
}
void LoadFromFileToList(List* list) {
		errno_t err;	
		FILE* fPtr;
		if ((err = fopen_s(&fPtr, "flights.dat", "r")) != 0) {
			printf("\n%s", "Global Fail...");
		}
		else {
			fseek(fPtr, 0, 0);
			Flight temp;
			fread(&temp, sizeof(Flight), 1, fPtr);
			while (!feof(fPtr)) {
				if(temp.isdeleted==0)AddFlight(list, &temp);
				fread(&temp, sizeof(Flight), 1, fPtr);
			}
			fclose(fPtr);
		}
}
void LoadToFile(Flight* flight) {
	if (&flight == NULL)return;
	errno_t err;
	FILE* fPtr;
	if ((err = fopen_s(&fPtr, "flights.dat", "r+")) != 0) {
		printf("\n%s", "Global Fail...");
	}
	else {
		Flight* temp = (Flight*)malloc(sizeof(Flight));
		memcpy(temp, flight, sizeof(Flight));
		fseek(fPtr, 0, SEEK_END);
		fwrite(temp, sizeof(Flight), 1, fPtr);
		fclose(fPtr);
		//free(temp);
	}
}
void DeleteFromFile(int numinlist) {
	errno_t err;
	FILE* fPtr;
	if ((err = fopen_s(&fPtr, "flights.dat", "rb+")) != 0) {
		printf("\n%s", "Global Fail...");
	}
	else {
		Flight* temp=(Flight*)malloc(sizeof(Flight));
		fseek(fPtr, (numinlist-1) * sizeof(Flight),SEEK_SET);
		fread(temp, sizeof(Flight), 1, fPtr);
		Flight* temp2 = (Flight*)malloc(sizeof(Flight));
		memcpy(temp2, temp, sizeof(Flight));
		temp2->isdeleted = 1;
		fseek(fPtr, (numinlist-1) * sizeof(Flight), SEEK_SET);
		fwrite(temp2, sizeof(Flight), 1, fPtr);
		fclose(fPtr);
		free(temp);
		free(temp2);	
	}
}
/*!!! NOT FOR USE !!!*/
void CreateFileWithFlights() {
	errno_t err;
	FILE *fPtr;
	Flight temp0 = {0, 1,"LN32","London","B737",12,30,5,70,August,30 };
	Flight temp1 = {0, 2,"BR322","Berlin","B737",5,30,4,110,July,1 };
	Flight temp2 = {0, 3,"LN32","London","B737",18,00,5,30,July,15 };
	Flight temp3 = {0, 4,"MS137","Moscow","B747",4,30,2,200,August,13 };
	Flight temp4 = {0, 5,"PL1","Warsaw","B747",5,30,2,110,July,1 };
	Flight temp5 = {0, 6,"LN800","London","B747",17,00,4,30,October,4 };
	Flight temp6 = {0, 7,"PA300","Paris","B777",2,20,7,78,October,30 };
	Flight temp7 = {0, 8,"MA999","Madrid","B777",23,00,9,45,November,1 };
	if ((err = fopen_s(&fPtr, "flights.dat", "w")) != 0) {
		return;	
	}
	else {
		fwrite(&temp0, sizeof(Flight), 1, fPtr);
		fwrite(&temp1, sizeof(Flight), 1, fPtr);
		fwrite(&temp2, sizeof(Flight), 1, fPtr);
		fwrite(&temp3, sizeof(Flight), 1, fPtr);
		fwrite(&temp4, sizeof(Flight), 1, fPtr);
		fwrite(&temp5, sizeof(Flight), 1, fPtr);
		fwrite(&temp6, sizeof(Flight), 1, fPtr);
		fwrite(&temp7, sizeof(Flight), 1, fPtr);
		fclose(fPtr);
	}
}
int FItemsGetCount() {
	errno_t err;
	FILE* fPtr;
	int count = 0;
	Flight* temp = (Flight*)malloc(sizeof(Flight));
	if ((err = fopen_s(&fPtr, "flights.dat", "r")) != 0) {
		printf("Geting count of items failed");
		return 0;
	}
	else {
		while (!feof(fPtr)) {
			fread(temp, sizeof(Flight), 1, fPtr);
			count++;
		}
		fclose(fPtr);
		free(temp);
		return count;
	}
}
