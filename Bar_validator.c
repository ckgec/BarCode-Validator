/*
Author -Chanchal Kumar
Email- ckgec98@gmail.com
*/

#include <stdio.h>
int main() 
{
    int code[13],i,odd,even,add,check_digit,choice;
	printf("---Barcode Validator---\nSelect the type of barcode:-\n1.UPC-12(Mostly used in USA)\n2.EAN-13(Used Worldwide)");
    scanf("%d",&choice);
	if(choice==1)
	{
	printf("Enter the 12 digit UPC barcode\n");
	for(i=0;i<12;i++)
		{
		scanf("%d",&code[i]);
		}

    odd = 3 * (code[0] + code[2] + code[4] + code[6] + code[8] + code[10]); //Adding the digits in odd number positions together and multiply 3.

	even = code[1] + code[3] + code[5] + code[7] + code[9]; // Adding the digits (up to but not including the check digit) in the even-numbered positions.

	add= odd + even;//Adding two results together.

    add = add % 10; // Taking the remainder of number.

    if(add != 0)
		{
	check_digit = 10 - add;
		}

    printf("Check digit value is %d \n", check_digit);

    if (check_digit == code[11])
		{
	printf("\nBarcode is Valid\n");
		}

    else
		{
	printf("Barcode is invalid");
		}
	}
	else if(choice == 2)
	{
		printf("Enter the 13 digit EAN barcode\n");
		for(i=0;i<13;i++)
			{
			scanf("%d",&code[i]);
			}
		odd = (code[0] + code[2] + code[4] + code[6] + code[8] + code[10]); //Adding the digits in odd number positions

		even=3*(code[1] + code[3] + code[5] + code[7] + code[9] +code[11]);//Adding the digits in even number positions(excluding last digit) multiplied by 3

		add= odd + even;//Adding two results together.

		check_digit = (add/10)*10;     //the nearest multiple of 10 i.e., equal or higher than added digits
		if(check_digit != add)
			check_digit=check_digit+10;

		check_digit=check_digit-add;

		if (check_digit == code[12]) //comparing with last digit of barcode
		{
	printf("\nBarcode is Valid\n");
		}

    else
		{
	printf("Barcode is invalid\n");
		}
	}
	getch();
    return 0;
}
