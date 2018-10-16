 #include<stdio.h>
 #include<string.h>
 
 #define FLAG '#'
 #define ESC '*'
 
void main()
{
	int j=1,i;
	char Data[50],Frame[50];
	
	printf("Enter the data :");
	scanf("%s",Data);
	
	Frame[0]=FLAG;
	
	for(i=0;i<strlen(Data);i++)  // stuffing of byte
	{
		if(Data[i]==FLAG || Data[i]==ESC)   //check whether there is flag or escape character
		{
			Frame[j++]=ESC;   // appending escape character
		}
		Frame[j++]=Data[i];   //adding data with frame
	}
	Frame[j++]=FLAG;  // setting tailer with flag CHARACTER
	Frame[j]='\0';   //setting end of string
	printf("Frame to be send : %s \n",Frame);	
}

