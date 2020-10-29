/* Program for performing various operations on strings using pointer representation
   Made by Tarun Luthra
   Roll No. = 2018 CSC 1023   																	*/
   #include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
 {   char *s,ch; 
	 int i=0,j,choice=1,l,l2,c,count,n,check=0,pos,pos1,pos2;
	 s=new(char);
	 cout<<"Enter a string=";
	 gets(s);
	 fflush(stdin); //used to clear the buffer otherwise the following gets() does not work
	 int x; 
	do
	{   cout<<"\n\nChoose one of the following options to run";
		cout<<"\n1. Enter string again";
		cout<<"\n2. View entered string";
		cout<<"\n3. Check whether the string is palindrome";
		cout<<"\n4. Search the occurence of a character in the string";
		cout<<"\n5. Replace a character in string by another";
		cout<<"\n6. Delete all occurences of a char in string";
		cout<<"\n7. Search a string in the main string";
		cout<<"\n8. Concatinate two strings";
		cout<<"\n9. Extract a substring from the main string"; 
		cout<<"\n10. Exit Program";
		cout<<"\nEnter choice (1-10)=";		 	
		cin>>choice;		cout<<endl;
		switch(choice)
		{
			case 1: 	    cout<<"\n\nEnter a string = ";  
							gets(s);
							fflush(stdin);
							break;
			case 2:			cout<<"\n\nString = " ; 
							puts(s);
							break;
			case 3:		   l=strlen(s);
						   c=0;   
						   for(i=0;i<l/2;i++)
						   { if(*(s+i)!=*(s+l-i-1))
							   {c++;}   }
						   if(c==0)
						   cout<<"\n\nYes, The string is a palindrome";
						   else
						   cout<<"\n\nNot a palindrome";
						   break;
			case 4:		   cout<<"\nEnter char= "; 
						   cin>>ch;
						   count=0;
						   l=strlen(s);
						   for(i=0;i<l;i++)
						   { 
						     if(ch==*(s+i))
							 { cout<<"\nCharacter found at pos "<<i+1;
								count++; }
							}
							cout<<"\nTotal count = "<<count;
							break;	 
			case 5: 		cout<<"Enter a character=";
							cin>>ch;
							cout<<"Enter position to replace (1 to "<<strlen(s)<<" )=";
							cin>>n;
							if(n>=1&&n<=strlen(s))
							{  //s[n-1]=ch;	
							   *(s+n-1)=ch;
							   cout<<"\n\nNew string ="; 
							   puts(s); }
							else 
							{ cout<<"\n\nIncorrect input ...try again"; }
							break;
			case 6:			cout<<"Enter a character to be deleted from the string=";
							cin>>ch;
							count=0;
							l=strlen(s);
							for(i=0;i<l;i++)
							{ if(ch==*(s+i))
							  {  for(j=i;j<=l;j++)
								  { *(s+j)=*(s+j+1); }
								  l--;	//string length reduces for every char deleted
								  i--;	//otherwise the next char of the deleted char goes unchecked
							  }
							}
							cout<<"\nNew string="; puts(s);
							break;   
			case 7:			cout<<"Enter string to be searched = ";
							char *p;		p=new(char);
							scanf("%s",p);
							l2=strlen(p);		l=strlen(s);
							check=0;
							if(l2>l)
							{ cout<<"\nEntered string is longer than the original string \nSearch operation cannot be performed";  break;}
							for(i=0;i<l;i++)
							{ check=0;
							  if(*(s+i)==*p&&check==0)
							  { pos=i;
							    check=1;
								for(j=0;j<l2;j++)
								{  if(*(s+j+i)!=*(p+j))
								   { check=0; }
								}
							  }
							  if(check==1)
							  break;
							}
							if(check==0)
							{ cout<<"\nEntered string could not be found in the main string"; }
							else if(check==1)
							{ cout<<"\nString exists from pos "<<pos+1<<" to "<<pos+l2;  }
							delete(p);
							break;
			case 8:			cout<<"Enter string = ";
							//char *p;
							p=new char;
							fflush(stdin);
							gets(p);
							strcat(s,p);
							cout<<"\nNew string after concatination is - ";
							puts(s);
							delete(p);
							break;
			case 9:			cout<<"Enter initial position of the substring (1 - "<<strlen(s)<<" ) = ";
							cin>>pos1 ; 
							if(pos1<1||pos1>strlen(s))
							{ cout<<"Invalid input" ; break; } 
							cout<<"Enter final position of the substring ("<<pos1<<" - "<<strlen(s)<<" ) = ";
							cin>>pos2 ; 
							if(pos2<pos1||pos2>strlen(s))
							{ cout<<"Invalid input" ; break; } 
							p=new char;
							cout<<"New substring obtained = ";
							if(pos1==pos2)
							{ *p=*(s+pos1-1); cout<<*p; }
							else
							{	for(i=pos1-1,j=0;i<pos2;j++,i++)
								{	 *(p+j)=*(s+i); }
								puts(p);
						    }
						   	break;
			case 10:		cout<<"BYE";
		}	 //end of switch
		cout<<endl;//<<endl;
	}while(choice!=10);	//end of do-while
   return 0;
}
