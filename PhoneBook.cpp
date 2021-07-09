#include<bits/stdc++.h>
#include<conio.h>
using namespace std;


void menu();        	//	display menu 
void AddNumber();    	//	add new record
void DisplayRecords();  //	read data file & display on screen
void SearchBySrNo();    //	search and display record by sr no.
void deleteRecord();    //	delete a specific record from file.
void modifyRecord();    //	modify a specific record in file.


class PhoneBook
{
    int srno;
    char name[25];
    char mobile[15];
    public:
    int getSrNo() {return srno;}
    void storeData()
    {
        cout<<"\n...............CREATE NEW PHONE RECORD...............\n\n";
        cout<<"Enter Serial Number : "; 
		cin>>srno; 
		cin.ignore();
        cout<<"Enter Record Name   : "; 
		cin.getline(name,25);
        cout<<"Enter Mobile Number : "; 
		cin.getline(mobile,15);
        cout<<endl;
    }
    void showData()
    {
        cout<<"\n...............PHONE BOOK RECORD...............\n\n";
        cout<<"Sr. No.    : "<<srno<<endl;
        cout<<"Name       : "<<name<<endl;
        cout<<"Mobile No. : "<<mobile<<endl;
    }
}b;

void AddNumber()
{
    ofstream fout;
    fout.open("PhonBook.dat",ios::out|ios::binary|ios::app);
    b.storeData();
    fout.write((char*)&b,sizeof(b));
    fout.close();
    cout<<"\nRecord Saved to File...\n";
}



void DisplayRecords()
{
    ifstream fin;
    fin.open("PhonBook.dat",ios::out|ios::binary|ios::app);
    while(fin.read((char*)&b,sizeof(b)))
    {
        b.showData();
    }
    fin.close();
    cout<<"\nReading of Data File Completed...\n";
}

void SearchBySrNo()
{
    ifstream fin;
    int n, flag=0;
    fin.open("PhonBook.dat",ios::out|ios::binary|ios::app);
    cout<<"Enter Serial Number of Record To Display: ";
    cin>>n;

    while(fin.read((char*)&b,sizeof(b)))
    {
        if(n==b.getSrNo())
        {
            b.showData();
            flag++;
            cout<<"\n\nRecord Found and Displayed...\n";
        }
    }
    fin.close();
    if(flag==0)
        cout<<"\nThe Record of Serial Number "<<n<<" is not in file....\n";
    cout<<"\nReading of Data File Completed...\n";
}

void deleteRecord()
{
    ifstream fin;
    ofstream fout;
    int n, flag=0;
    fin.open("PhonBook.dat",ios::out|ios::binary|ios::app);
    fout.open("temp.dat",ios::out|ios::binary);
    cout<<"Enter Serial Number of Record To Delete : ";
    cin>>n;

    while(fin.read((char*)&b,sizeof(b)))
    {
        if(n==b.getSrNo())
        {
            cout<<"\nThe Following record is deleted...\n";
            b.showData();
            flag++;
        }
        else
        {
            fout.write((char*)&b,sizeof(b));
        }
    }
    fin.close();
    fout.close();
    if(flag==0)
        cout<<"\nThe Record of Serial Number "<<n<<" is not in file...\n";
    cout<<"\nReading of Data File Completed...\n";
    remove("PhonBook.dat");
    rename("temp.dat","PhonBook.dat");
}


void modifyRecord()
{
    fstream fio;
    int n, flag=0,pos;
    fio.open("PhonBook.dat",ios::out|ios::binary|ios::in);

    cout<<"Enter Serial Number of Record To Modify : ";
    cin>>n;

    while(fio.read((char*)&b,sizeof(b)))
    {
        pos=fio.tellg();
        if(n==b.getSrNo())
        {
            cout<<"\nThe Following record will be modified...\n";
            b.showData();
            flag++;
            cout<<"\nRe-Enter the New Details...\n";
            b.storeData();
            fio.seekg(pos-sizeof(b));
            fio.write((char*)&b,sizeof(b));
            cout<<"\nData Modified Successfully...\n";
        }
    }
    fio.close();
    if(flag==0)
        cout<<"\nThe Record of Serial Number "<<n<<" is not in the file...\n";
    cout<<"\nReading of Data File Completed...\n";
}


void menu()
{
    int ch;
    do
    {
        system("cls");
        cout<<"..................................\n";
        cout<<"           PHONE BOOK\n";
        cout<<"..................................\n\n";
        cout<<"************** MENU **************\n\n";
        cout<<"0. Exit\n";
        cout<<"1. Add New Phone Record\n";
        cout<<"2. Display All Saved Records\n";
        cout<<"3. Search Specific Record\n";
        cout<<"4. Delete Specific Record\n";
        cout<<"5. Modify Existing Record\n\n";
        cout<<"Enter Your Choice : ";
        cin>>ch;
        system("cls");
        switch(ch)
        {
            case 1: AddNumber();
					cout<<"Press any key..."<<endl;
					break;
            case 2: DisplayRecords(); 
            		cout<<"Press any key..."<<endl;
					break;
            case 3: SearchBySrNo(); 
            		cout<<"Press any key..."<<endl;
					break;
            case 4: deleteRecord();
					cout<<"Press any key..."<<endl; 
					break;
            case 5: modifyRecord(); 
            		cout<<"Press any key..."<<endl;
					break;
        }
        getch();
    }while(ch);
}

int main()
{
    menu();
    return 0;
}
