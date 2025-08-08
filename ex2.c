/******************
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
	int code;	
	do
	{
		printf("Choose an option:\n");
		printf("\t1. Happy Face\n");
		printf("\t2. Balanced Number\n");
		printf("\t3. Generous Number\n");
		printf("\t4. Circle Of Joy\n");
		printf("\t5. Happy Numbers\n");
		printf("\t6. Festival Of Laughter\n");
		printf("\t7. Exit\n");
		scanf("%d", &code);
		switch (code)
		{
		// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
		/* Example:
		* n = 3:
		* 0   0
		*   o
		* \___/
		*/
			case 1: {
				char c1, c2, c3;
				int faceSize;
				printf("Enter symbols for the eyes, nose, and mouth:\n");
				scanf(" %c %c %c", &c1, &c2, &c3);
				printf("Enter face size:\n");
				scanf("%d", &faceSize);
				while((faceSize <= 0) || (faceSize % 2 == 0)){
					printf("The face's size must be an odd and positive number, please try again:\n");
					scanf("%d", &faceSize);
				}
				printf("%c", c1);
				for(int i = 0; i < faceSize; i++){
					printf(" ");
				}
				printf("%c\n", c1);
				for(int i = 0; i < (faceSize + 1) / 2; i++){
					printf(" ");
				}
				printf("%c", c2);
				for(int i = 0; i < (faceSize + 1) / 2; i++){
					printf(" ");
				}
				printf("\n\\");
				for(int i = 0; i < faceSize; i++){
					printf("%c", c3);
				}
				printf("/\n");
				break;
			}
		// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
		// and the sum of all digits to the right of the middle digit(s) are equal
		/* Examples:
		Balanced: 1533, 450810, 99
		Not blanced: 1552, 34
		Please notice: the number has to be bigger than 0.
		*/
			case 2: {
				int num, num2, digits = 0, sumLeft = 0, sumRight = 0;
				printf("Enter a number:\n");
				scanf("%d", &num);
				while(num <= 0){
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}
				num2 = num;
				while(num2){
					digits++;
					num2 /= 10;
				}
				num2 = num;
				for(int i = 0; i < (digits + 1) / 2; i++)
					num2 /= 10;
				for(int i = 0; i < digits / 2; i++){
					sumLeft += num2 % 10;
					sumRight += num % 10;
					num /= 10;
					num2 /= 10;
				}
				if(sumLeft == sumRight)
					printf("This number is balanced and brings harmony!\n");
				else
					printf("This number isn't balanced and destroys harmony.\n");
				break;
			}
		// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
		/* Examples:
		Abudant: 12, 20, 24
		Not Abudant: 3, 7, 10
		Please notice: the number has to be bigger than 0.
		*/
			case 3: {
				int num, sum = 0;
				printf("Enter a number:\n");
				scanf("%d", &num);
				while(num <= 0){
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}
				for(int i = 2; i <= num / 2; i++){
					if(num % i == 0)
						sum += i;
				}
				if(sum > num)
					printf("This number is generous!\n");
				else
					printf("This number does not share.\n");
				break;
			}
		// Case 4: determine wether a number is a prime.
		/* Examples:
		This one brings joy: 3, 5, 11
		This one does not bring joy: 15, 8, 99
		Please notice: the number has to be bigger than 0.
		*/
			case 4: {
				// isPrimeReversed and isPrime are ment to boolean and are initialized to true
				int num, num2, isPrime = 1, isPrimeReversed = 1, reversedNum = 0;
				printf("Enter a number:\n");
				scanf("%d", &num);
				while(num <= 0){
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}
				if(num == 1){
					isPrime = 0;
				}
				else {
						num2 = num;
					while(num2){
						reversedNum = reversedNum * 10 + (num2 % 10);
						num2 /= 10;
					}
					for(int i = 2; i <= num / 2; i++){
						if(num % i == 0){
							isPrime = 0;
							break;
						}
					}
					for(int i = 2; i <= reversedNum / 2; i++){
						if(reversedNum % i == 0){
							isPrimeReversed = 0;
							break;
						}
					}
				}
				if(isPrimeReversed && isPrime)
					printf("This number completes the circle of joy!\n");
				else
					printf("The circle remains incomplete.\n");
				break;
			}
		// Happy numbers: Print all the happy numbers between 1 to the given number.
		// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
		/* Examples:
		Happy :) : 7, 10
		Not Happy :( : 5, 9
		Please notice: the number has to be bigger than 0.
		*/
			case 5: {
				int num, num2, sumSquared;
				printf("Enter a number:\n");
				scanf("%d", &num);
				while(num <= 0){
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}
				// at this point the input has to be atleast 1 and 1 is happy so there is no need to check for him
				printf("Between 1 and %d only these numbers bring happiness: 1", num);
				for(int i = 2; i <= num; i++){
					sumSquared = i;
					do{
						num2 = sumSquared;
						sumSquared = 0;
						while(num2){
							sumSquared += (num2 % 10) * (num2 % 10);
							num2 /= 10;
						}
						if(sumSquared == 1){
							printf(" %d", i);
							break;
						}
					// 4 is unhappy so if the number ever reaches 4, he is unhappy (you showed in the examples)
					} while(sumSquared != 4);
				}
				printf("\n");
				break;
			}
		// Festival of Laughter: Prints all the numbers between 1 the given number:
		// and replace with "Smile!" every number that divided by the given smile number
		// and replace with "Cheer!" every number that divided by the given cheer number
		// and replace with "Festival!" every number that divided by both of them
		/* Example:
		6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
		*/
			case 6: {
				int smileNumber, cheerNumber, maxNumber, correctInput;
				printf("Enter a smile and cheer number:\n");
				//assigns correctInput the number of assigned numbers, it needs to be 2 for a valid input
				correctInput = scanf(" smile: %d, cheer: %d", &smileNumber, &cheerNumber);
				while((correctInput != 2) || (smileNumber <= 0) || (cheerNumber <= 0) || (smileNumber == cheerNumber)) {
					scanf("%*[^\n]");
					printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
					correctInput = scanf(" smile: %d, cheer: %d", &smileNumber, &cheerNumber);
				}
				printf("Enter maximum number for the festival:\n");
				scanf("%d", &maxNumber);
				while(maxNumber <= 0){
					printf("Only positive maximum number is allowed, please try again:\n");
					scanf("%d", &maxNumber);
				}
				for(int i = 1; i <= maxNumber; i++){
					if(i % smileNumber == 0){
						if(i % cheerNumber == 0)
							printf("Festival!\n");
						else
							printf("Smile!\n");
					}
					else if(i % cheerNumber == 0)
						printf("Cheer!\n");
					else
						printf("%d\n", i);
				}
				break;
			}
			case 7:
				printf("Thank you for your journey through Numeria!");
				break;
			default:
				printf("This option is not available, please try again.\n");
		}
	} while (code != 7);
	return 0;
}
