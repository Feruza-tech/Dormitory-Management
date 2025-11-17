#include <iostream>
#include <string>
#include <cctype>
#include <conio.h>
using namespace std;
void accept(int&, string**, int**, char**);
int search(int*, int, int);
int search(char, char, int);
int search(string*, string, int);
void display(string*, int*, char*, int);
char test;
int main()
{
    int size;
    string* names = NULL;
    int* ages = NULL;
    char* sexes = NULL;
    accept(size, &names, &ages, &sexes);
    display(names, ages, sexes, size);
    return 0;
}
void accept(int& num, string** string_p, int** int_p, char** char_p)
{
    cout<<" Enter number of students: ";
    cin >> num;
    delete string_p[0];
    delete int_p[0];
    delete char_p[0];
    string_p[0] = new string[num];
    int_p[0] = new int[num];
    char_p[0] = new char[num];
    cout<<" Enter "<<num<<" students details:\n";
    for(int i = 0; i < num; i++)
    {
        cout<<" Enter "<<(i + 1)<<(i == 0 ? "st" : (i == 1 ? "nd" : (i == 2 ? "rd" : "th")))<<" student's name: ";
        cin >> string_p[0][i];
        Input_age:
        cout<<" Enter "<<(i + 1)<<(i == 0 ? "st" : (i == 1 ? "nd" : (i == 2 ? "rd" : "th")))<<" student's age: ";
        cin >> int_p[0][i];
        if(!cin) // validates for wrong data type input.
        {
            cin.clear(); // clears the input stream.
            cin >> test; // refreshes the input stream.
            cout<<" WRONG INPUT, can't enter non-digit characters\n\a";
            goto Input_age;
        }
        else if(int_p[0][i] <= 0)
        {
            cout<<" WRONG INPUT, can't enter negative numbers or zero as \"age\"\n\a";
            goto Input_age;
        }
        Input_sex:
        cout<<" Enter "<<(i + 1)<<(i == 1 ? "st" : (i == 2 ? "nd" : (i == 3 ? "rd" : "th")))<<" student's sex (M/F): ";
        cin >> char_p[0][i];
        if(isdigit(char_p[0][i]))
        {
            cout<<" WRONG INPUT, can't enter digit characters\n\a";
            goto Input_sex;
        }
        if(toupper(char_p[0][i]) != 'M' && toupper(char_p[0][i]) != 'F')
        {
            cout<<" WRONG INPUT, can't enter other than \'f\' or \'m\' (case insensitive)\n\a";
            goto Input_sex;
        }
    }
}
int search(int* int_p, int age, int num)
{
    if(age <= 0  !int_p)return -1;
    int count = 0;
    for(int i = 0; i < num; i++)
    {
        if(int_p[i] == age) count++;
    }
    return count;
}
int search(char* char_p, char sex, int num)
{
    if(!char_p)return -1;
    if(toupper(sex) != 'M' && toupper(sex) != 'F')return -1;
    int count = 0;
    for(int i = 0; i < num; i++)
    {
        if(toupper(char_p[i]) == toupper(sex)) count++;
    }
    return count;
}
int search(string* string_p, string char_p, int num)
{
    if(!string_p)return -1;
    int count = -1;
    for(int i = 0; i < num; i++)
    {
        if(string_p[i] == char_p)count = i;
    }
    return count;
}
void display(string* string_p, int* int_p, char* char_p, int num)
{
  display_head:
  system("cls");
  cout << " Student's list: \n";
    if(!string_p  !int_p  !char_p  num <= 0)
    {
        cout<<" Pointer memory allocation error (\a";
        if(!string_p)cout<<'s';
        if(!int_p)cout<<'i';
        if(!char_p)cout<<'c';
        if(num <= 0)cout<<'n';
        cout<<")\n";
        return;
    }
    int maxsize = string_p[0].length();
    for(int i = 1; i < num; i++)
    {
        int size1 = string_p[i].length();
        if(size1 > maxsize)maxsize = size1;
    }
    int push = (maxsize > 6 ? maxsize - 6 : 0);
    int fullstream 
    = 
    1 + // for the very first space 
    3 + // for this "#: "
    3 + // for three spaces.
    6 + // for this "name: "
    push  + // for the lengthiest string in the array.
    3 + // for three spaces.
    5 + // for this "age: "
    3 + // for three spaces.
    5 + // for this "sex: " 
    3 ; // for the last three spaces.
    cout << ' ' ;
    for(int i = 0; i < fullstream; i++)cout << '=' ;
    cout << endl ;
    cout << " #:    name: ";
    for(int i = 0; i < (push + 3); i++)cout << ' ' ;
    cout << "age:    sex:    ";
    cout << endl << ' ' ;

Feruza, [11/17/2025 12:45 PM]
for(int i = 0; i < fullstream; i++)cout << '=' ;
    cout << endl ;
    for(int i = 0; i < num; i++)
    {
        cout<<' '<<(i + 1)<<((i + 1) / 10 ? "    " : "     ");
        cout<<string_p[i];
        int counter = (push > 0 ? (maxsize - string_p[i].length()) : (6 - string_p[i].length()));
        counter += 3;
        //cout<<" counter = "<<counter<<endl;
        for(int j = 0; j < counter; j++)cout << ' ' ;
        cout << int_p[i] ;
        cout << (int_p[i] / 10 ? "      " : "       ") ;
        cout << (char)toupper(char_p[i]) << "      " ;
        cout << endl ;
    }
    cout << ' ' ;
    for(int i = 0; i < fullstream; i++)cout << '=' ;
    int search_type;
    Input_searchtype:
    cout<<"\n Enter search type: \n";
    cout<<" 1. Search by name\n";
    cout<<" 2. Search by age\n";
    cout<<" 3. Search by sex\n";
    cout<<" 4. Exit\n ";
    cin >> search_type;
    if(!cin)
    {
      cin.clear();
      cin >> test;
      cout<<" WRONG INPUT, can't enter non-digit characters\n\a";
        goto Input_searchtype;
    }
    else if(search_type > 4 || search_type < 1)
    {
      cout<<" WRONG INPUT, enter between {1, 2, 3, 4}\n\a";
        goto Input_searchtype;
    }
    switch(search_type)
    {
      case 1:
      {
        string search_string;
      cout<<" Enter name to be searched: ";
      cin >> search_string; 
      int position = search(string_p, search_string, num);
      cout<<" The name "<<search_string<<" is";
        if(position > -1)cout<<" found at index "<<position<<endl;
        else cout<<" not found\n";
        cout << " Press any key to continue...";
        getch();
        goto display_head;
        break;
    }
      case 2:
    {
      int search_age;
        Input_searchage:
        cout<<" Enter age to be searched: ";
        cin >> search_age;
        if(!cin)
        {
          cin.clear();
          cin >> test;
          cout << " WRONG INPUT, can't enter non-digit characters\n\a";
          goto Input_searchage;
        }
        else if(search_age <= 0)
        {
          cout << " WRONG INPUT, can't enter zero or negative numbers as age\a\n";
          goto Input_searchage;
        }
        int numbers = search(int_p, search_age, num);
        cout<<" Found "<<numbers<<" student"<<(numbers > 1 ? "s " : " ")<<"aged "<<search_age<<endl;
        cout << " Press any key to continue...";
        getch();
        goto display_head;
        break;
    }
      case 3:
      {
      char search_sex;
        Input_searchsex:
        cout << " Enter sex to be searched: ";
        cin >> search_sex;
        if(toupper(search_sex) != 'M' && toupper(search_sex) != 'F')
        {
          cout<<" WRONG INPUT, only allowed to input 'm' or 'f' (case insensitive)\n\a";
          goto Input_searchsex;
        }
        int numbers = search(char_p, search_sex, num);
        cout<<" Found "<<numbers<<" student"<<(numbers > 1 ? "s " : " ")<<"of sex "<<(char)toupper(search_sex)<<endl;
        cout << " Press any key to continue...";
        getch();
        goto display_head;
        break;  
      }
      case 4:
      {
        cout << " quitting\n";
        break;
      }
    }
}
