/*
Assignment No:1
Assignment Title:Write a program to perform linear search and binary search for
                 finding a specific contact in a phone book and return the
                 contact's details.Analyse their Time complexity.

Name:Diya Ravindra Bhansali
PRN:125B1F271
Class & Div :SY Btech IT, Div-A, Batch-A4
*/
#include <bits/stdc++.h>
using namespace std;
/*
Linear Search:It is a simple algorithm that finds a target value within a collection
              by checking each element one by one from start to finish until a match is found or list ends.

Binary Search:It  is an efficient algorithm used to find the position of a target value within a sorted array or list.
              It operates on the principle of divide and conquer,
              meaning it repeatedly halves the search space until the element is located or the space is empty.
*/
struct phonebook
{
    char name[20];
    string p_num;
}record[20];
int ct=0;
void LinearSearch_name()
{
    char sname[20];
    int comparisons=0;
    cout<<"\nEnter the name to be searched:";
    cin>>sname;
    int flag=0;
    for(int i=0;i<ct;i++)
        {
        comparisons++;
        if(strcmp(record[i].name,sname)==0)
        {
            cout<<"\n----Record"<<i+1<<"----"<<"\n Name:"<<record[i].name<<"\n PhoneNumber:"<<record[i].p_num<<endl;
            flag=1;
        }
    }
    if(flag==0)
    {
        cout<<"Given name is not present in PhoneBook."<<endl;
    }
    cout<<"\n\n---Comparisons required for searching in linear Search: "<<comparisons<<endl;
}
void BinarySearch_name()
{
    char sname[20];
    cout<<"Enter name:";
    cin>>sname;
    int low=0, high=ct-1;
    int comparisons=0;
    while(low<=high)
    {
        comparisons++;
        int mid=(low+high)/2;
        int cmp = strcmp(record[mid].name, sname);
        if(cmp==0)
        {
            cout<<"\n----Record"<<mid+1<<"----"<<"\n Name:"<<record[mid].name<<"\n PhoneNumber:"<<record[mid].p_num<<endl;
            break;
        }
        else if(cmp>0)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    if(low>high)
        cout<<"Given name is not present in PhoneBook.";
    cout<<"\n\n---Comparisons required for searching in Binary Search: "<<comparisons<<endl;
}
int main()
{
    int ch=0;
    do{
        cout<<"****MENU****"<<endl<<"1)Enter phonebook record."<<endl;
        cout<<"2)Display Records."<<endl<<"3)Linear Search."<<endl;
        cout<<"4)Binary Search."<<endl<<"5)Exit"<<endl<<"Enter your Choice:"<<endl;
        cin>>ch;
        switch(ch){
        case 1:
            char ch1;
            do{
                cout<<"\n----Record no."<<ct+1<<"----";
                cout<<"\nEnter name to add:";
                cin>>record[ct].name;
                cout<<"\nEnter Phone number to add:";
                cin>>record[ct].p_num;
                ct++;
                cout<<"\nDo you want to add more\n Type 'Y' for Yes and 'N' for No:";
                cin>>ch1;
            }while(ch1!='N' && ch1!='n');
            break;
        case 2:
            cout<<"\n\n----PhoneBook----"<<endl;
            cout<<"Name\t\tPhoneNumber\n"<<endl;
            for(int i=0;i<ct;i++){
                cout<<record[i].name<<"\t\t"<<record[i].p_num<<"\n"<<endl;
            }
            break;
        case 3:
            LinearSearch_name();
            break;
        case 4:
            BinarySearch_name();
            break;
        case 5:
            exit(0);
        default:
            cout<<"Invalid choice."<<endl;
        }
    }while(ch!=5);
    return 0;
}
/*OUTPUT
****MENU****
1)Enter phonebook record.
2)Display Records.
3)Linear Search.
4)Binary Search.
5)Exit
Enter your Choice:
1

----Record no.1----
Enter name to add:Abhay

Enter Phone number to add:12345

Do you want to add more
 Type 'Y' for Yes and 'N' for No:y

----Record no.2----
Enter name to add:Bina

Enter Phone number to add:23456

Do you want to add more
 Type 'Y' for Yes and 'N' for No:n
****MENU****
1)Enter phonebook record.
2)Display Records.
3)Linear Search.
4)Binary Search.
5)Exit
Enter your Choice:
2


----PhoneBook----
Name            PhoneNumber

Abhay           12345

Bina            23456

****MENU****
1)Enter phonebook record.
2)Display Records.
3)Linear Search.
4)Binary Search.
5)Exit
Enter your Choice:
1

----Record no.3----
Enter name to add:Chetan

Enter Phone number to add:56789

Do you want to add more
 Type 'Y' for Yes and 'N' for No:y

----Record no.4----
Enter name to add:Diya

Enter Phone number to add:24680

Do you want to add more
 Type 'Y' for Yes and 'N' for No:y

----Record no.5----
Enter name to add:Hiten

Enter Phone number to add:31234

Do you want to add more
 Type 'Y' for Yes and 'N' for No:N
****MENU****
1)Enter phonebook record.
2)Display Records.
3)Linear Search.
4)Binary Search.
5)Exit
Enter your Choice:
3

Enter the name to be searched:Diya

----Record4----
 Name:Diya
 PhoneNumber:24680


---Comparisons required for searching in linear Search: 5
****MENU****
1)Enter phonebook record.
2)Display Records.
3)Linear Search.
4)Binary Search.
5)Exit
Enter your Choice:
4
Enter name:Hiten

----Record5----
 Name:Hiten
 PhoneNumber:31234


---Comparisons required for searching in Binary Search: 3
****MENU****
1)Enter phonebook record.
2)Display Records.
3)Linear Search.
4)Binary Search.
5)Exit
Enter your Choice:
4
Enter name:giya
Given name is not present in PhoneBook.

---Comparisons required for searching in Binary Search: 3
****MENU****
1)Enter phonebook record.
2)Display Records.
3)Linear Search.
4)Binary Search.
5)Exit
Enter your Choice:
5

Process returned 0
*/

/*
Program Analysis for Time Complexity and Space Complexity
Linear Search-
Time Complexity: O(n), where n is the size of the input array.
                 The worst-case scenario is when the target element is not present in the array,
                 and the function has to go through the entire array to figure that out.
Space Complexity:O(1), the function uses only a constant amount of extra space to store variables.
                 The amount of extra space used does not depend on the size of the input array.
Binary Search-
Time Complexity: O(log n),algorithm divides the input array in half at every step,
                 reducing the search space by half, and hence has a time complexity of logarithmic order.
Auxiliary Space: O(1),algorithm requires only constant space for storing the low, high, and mid indices,
                 and does not require any additional data structures,but recursivly space complexity is O(log n).

*/


