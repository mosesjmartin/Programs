/* atoi function */

#include<stdio.h>
#include<string.h>
#define MAX_INT 2147483647
#define MIN_INT -2147483648

//Function to return MIN_INT or MAX_INT
int maxOrMinIntValue(int sign) {
	if(sign > 0) {
		return MAX_INT;
	} else {
		return MIN_INT;
	}
}

// Implementation of the atoi function
int atoi (char *str) {
	int value; // final int value
	int counter; // constant value to move the digits one place to the left
	int temp; // index value to iterate through the string
	int length; // length of the string
	int sign; // sign of the integer
	value = 0;
	counter = 10;
	sign = 1;
	// Check for NULL input
	if(str == NULL) {
		return 0;
	}
	length = strlen(str);
	// Check for Empty string
	if(!length) {
		return 0;
	}
	temp = 0;
	// Remove leading spaces
	while(str[temp] == ' ' || str[temp] == '\t') {
		temp++;
		continue;
	}
	// Check to find the sign of the value (positive/negative)
	if(temp < length && str[temp] == '-') {
		sign = -1;
		temp++;
	} else {
		if(temp < length && str[temp] == '+') {
			temp++;
		}
	}
	// While loop to convert the string to integer
	while(temp < length) {
		// Check if the character given in the string is numeric because only numberic values can be converted to integer
		if(str[temp] < '0' || str[temp] > '9') {
			break;
		}
		// Check if the given value exceeds the max int value
		if(value > MAX_INT/10) {
			return maxOrMinIntValue(sign);
		} else {
			if(value == MAX_INT/10 && (str[temp] - 48 >= 8)) {
				return maxOrMinIntValue(sign);
			}
		}
		// Calculate the value
		value = (value * counter) + (str[temp] - 48);
		temp++;
	}
	return sign * value;
}


int main() {
	int value;
	value = atoi(NULL);
	printf("The value is %d\n",value);
	value = atoi("");
	printf("The value is %d\n",value);
	value = atoi("47");
	printf("The value is %d\n",value);
	value = atoi("hello world");
	printf("The value is %d\n",value);
	value = atoi("0");
	printf("The value is %d\n",value);
	value = atoi("-24");
	printf("The value is %d\n",value);
	value = atoi("2-4");
	printf("The value is %d\n",value);
	value = atoi("abcd123");
	printf("The value is %d\n",value);
	value = atoi("1234abc");
	printf("The value is %d\n",value);
	value = atoi("1234567890986754536375");
	printf("The value is %d\n",value);
	value = atoi("+2147483646");
	printf("The value is %d\n",value);
	value = atoi("2147483648");
	printf("The value is %d\n",value);
	value = atoi("-2147483647abc");
	printf("The value is %d\n",value);
	value = atoi("-2147483648");
	printf("The value is %d\n",value);
	return 0;
}