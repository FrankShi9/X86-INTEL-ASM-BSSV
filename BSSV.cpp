// DailyExe1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

int main() {

	char msgSelectPositiveInt[] = "Select total number of positive integers (between 2-5): ";
	char msgEnterPositiveInt[] = "Enter positive integer %d: ";
	char msgProgEnds[] = "\nProgram terminates and has looped %d times.\n\n";
	char msgListInt[] = "Your integers from lowest to highest are ";
	char msgComma[] = " , ";
	char msgTotalAmt[] = "\n\n The total amount is %d \n\n";

	char fmt[] = "%d";

	int totalNumInt;
	int intList[5];

	int cntNumInt = 0;
	int positiveInt;
	int totalAmt = 0;
	int input;


	__asm {


	readTotalPositiveInt:
		    lea eax, msgSelectPositiveInt
			push eax
			call printf
			add esp, 4


			lea eax, positiveInt
			push eax
			lea eax, fmt
			push eax
			call scanf_s
			add esp, 8


			cmp positiveInt, 2
			js readTotalPositiveInt
			cmp positiveInt, length intList
			jg readTotalPositiveInt




			lea esi, intList


    enterPositiveInt:inc cntNumInt
			mov eax, cntNumInt
			push eax
			lea eax, msgEnterPositiveInt
			push eax
			call printf
			add esp, 8



			lea eax, input
			push eax
			lea eax, fmt
			push eax
			call scanf_s
			add esp, 8

            mov eax, input
			cmp input, 0
			jle printEnd

			mov edx, input
			mov [esi], edx

			add esi, 4


			mov eax, cntNumInt
			cmp eax, positiveInt
			jge printEnd
			jmp enterPositiveInt


	printEnd:
		    mov eax, cntNumInt
			push eax
			lea eax, msgProgEnds
			push eax
			call printf
			add esp, 8

	sort:

		    dec positiveInt
			mov eax, positiveInt

			

			L1:
				push eax
			    lea esi, intList
				L2:
					mov edx, [esi]
					cmp edx, [esi+4]
					jg greater

					jmp finish_inner

				greater:
					mov edx, [esi]
					xchg edx, [esi+4]
					mov [esi], edx


				finish_inner:

					add esi, 4
					dec eax
					cmp eax, 0
					jne L2

				pop eax
				dec eax
				cmp eax, 0
				jne L1


	printMsgListInt:

		    lea  eax, msgListInt
			push eax
			call printf
			add  esp, 4


			lea esi, intList
			inc positiveInt  //recover the original user designated cnt of int
			mov ebx, positiveInt


	printSortedList:

		    mov eax, [esi]
			push eax
			lea eax, fmt
			push eax
			call printf
			add esp, 8

			cmp ebx, 1
			jle no_comma

	printComma:
		    lea eax, msgComma
			push eax
			call printf
			add esp, 4


	no_comma:

			add esi, 4
			dec ebx
			cmp ebx, 0
			jne printSortedList


	outOfPrintSortedList:

		    lea esi, intList
			mov ebx, positiveInt

	add_sum:
		    mov eax, [esi]
			add totalAmt, eax
			add esi, 4
			dec ebx
			cmp ebx, 0

			jne add_sum


	printTotal:

		    mov eax, totalAmt
			push eax
			lea eax, msgTotalAmt
			push eax
			call printf
			add esp, 8
	}


	return 0;
}
