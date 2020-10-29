//Subsequences using recursion

#include <iostream>
using namespace std;

void subsequences(char *inp,char *out,int i,int j)
{
    //Base case
    if(inp[i]=='\0')
    {
        out[j] = '\0';
        cout<<out<<" , ";
        return;
    }

    //Rec case
    //1. Include the current char
    out[j] = inp[i];
    subsequences(inp,out,i+1,j+1);

    //2. Exclude the current char
    subsequences(inp,out,i+1,j);

}
int main() 
{
    char input[100];
    cin>>input;

    char output[100];
    subsequences(input,output,0,0);

    return 0;
}

