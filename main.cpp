#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <bits/stdc++.h>


using namespace std;

string ReverseString(string str);
int LengthString(string str);
string Add_2_in_ASCII_each_charactor(string str);
string SortString(string str);
string Decrypt_with_Key(string str);


int main(int argc, char** argv)
{
    pid_t   pid_Reverse, pid_Length, pid_ASCII, pid_Sort, pid_Decrypt, pid;

    string UserInput, resultString, encryptedStr;
    cout << "Type any content (String but not use space): ";
    cin >> UserInput; // get user input from the keyboard
    cout <<endl<<endl;

    /*
     *   Required Tasks
     *      1.  Reverse
     *      2.  Find Length
     *      3.  Add 2 in the ASCII of each charactor
     *      4.  Sort
     *      5.  Decrypt with given key
     *
     */


    if ((pid_Reverse = fork()) < 0)
    {
        printf("Failed to fork process Reverse String\n");
        exit(1);
    }
    else if (pid_Reverse == 0)
    {
        resultString = ReverseString(UserInput);
        cout <<  "*** Parent detects Reverse process ID : "<<pid_Reverse<<" was done ***"<<endl<<endl ;
        cout <<  "***  Result is: "<<resultString<<endl <<endl <<endl ;
        //  ------  Find Length
        if ((pid_Length = fork()) < 0)
        {
            printf("Failed to fork process Length String\n");
            exit(1);
        }
        else if (pid_Length == 0)
        {
            int leng = LengthString(UserInput);
            resultString = to_string(leng);
            cout <<  "*** Parent detects Length process ID : "<<pid_Length<<" was done ***\n" ;
            cout <<  "***  Result is: "<<resultString<<endl <<endl <<endl ;

            //  ------  Add_2_in_ASCII_each_charactor
            if ((pid_ASCII = fork()) < 0)
            {
                printf("Failed to fork process Add_2_in_ASCII_each_charactor\n");
                exit(1);
            }
            else if (pid_ASCII == 0)
            {
                encryptedStr = Add_2_in_ASCII_each_charactor(UserInput);
                cout <<  "*** Parent detects Add_2_in_ASCII_each_charactor process ID : "<<pid_ASCII<<" was done ***\n" ;
                cout <<  "***  Result is: "<<encryptedStr<<endl <<endl <<endl ;

                //  ------  SortString
                if ((pid_Sort = fork()) < 0)
                {
                    printf("Failed to fork process SortString\n");
                    exit(1);
                }
                else if (pid_Sort == 0)
                {
                    resultString = SortString(UserInput);
                    cout <<  "*** Parent detects SortString process ID : "<<pid_Sort<<" was done ***\n" ;
                    cout <<  "***  Result is: "<<resultString<<endl <<endl <<endl ;

                    //  ------  Decrypt_with_Key
                    if ((pid_Decrypt = fork()) < 0)
                    {
                        printf("Failed to fork process SortString\n");
                        exit(1);
                    }
                    else if (pid_Decrypt == 0)
                    {
                        resultString = Decrypt_with_Key(encryptedStr);
                        cout <<  "*** Parent detects Decrypt_with_Key process ID : "<<pid_Decrypt<<" was done ***\n" ;
                        cout <<  "***  Input is: "<<encryptedStr<<endl;
                        cout <<  "***  Result is: "<<resultString<<endl <<endl <<endl ;
                    }

                }
            }
        }
    }






    waitpid(pid_Reverse, NULL, 0);
    waitpid(pid_Length, NULL, 0);
    waitpid(pid_ASCII, NULL, 0);
    waitpid(pid_Sort, NULL, 0);
    waitpid(pid_Decrypt, NULL, 0);


    cout<<endl<<endl<<endl;
    return 0;
}



string ReverseString(string str)
{
    string input = str;
    int n = input.length();
    for (int i = 0; i < n / 2; i++)
        swap(input[i], input[n - i - 1]);

    return input;
}
int LengthString(string str)
{
    return str.length();;
}
string Add_2_in_ASCII_each_charactor(string str)
{
    int len = str.length();
    char char_array[len + 1];
    strcpy(char_array, str.c_str());

    int asciiValue = 0;
    for(int i=0; i<len; ++i)
    {
        asciiValue = char_array[i];
        asciiValue += 2;
        //cout<<" origional Char : "<<char_array[i]<<" ASCII value : "<<(asciiValue-2)<<" new ASCII Value : " << asciiValue;
        char_array [i] = asciiValue;
        //cout<<" new Char is : "<<char_array[i]<<endl<<endl;
    }
    return string(char_array);
}
string SortString(string str)
{
    string input = str;
    sort(input.begin(), input.end());
    return input;
}
string Decrypt_with_Key(string str)
{
    int len = str.length();
    char char_array[len + 1];
    strcpy(char_array, str.c_str());

    int asciiValue = 0;
    for(int i=0; i<len; ++i)
    {
        asciiValue = char_array[i];
        asciiValue -= 2;
        char_array [i] = asciiValue;
    }
    return string(char_array);
}


