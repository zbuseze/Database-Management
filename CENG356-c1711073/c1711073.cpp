#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;
struct person{
    char name[30];
    int id;
    int phone;
};

int main(void) {

    struct person info[10000];

    srand(static_cast<int>(time(0)));

    ofstream theFile("info.txt");
    int i,j;
    int idNum;
    int elements=10000;

    for(j=1;j<=elements;j++) {

        for (i = 0; i < 30; i++) {
            char ch = rand() % 26 + 'a';
            info[j].name[i] = ch;
        }
        info[j].id = rand() % 1000000 + 1;

        // burada ID'nin unique random olması için bir çok komut satırı denedim onlardan birisi aşağıda mevcut fakat compile ettiğimde .txt dosyasında herhangi bir veri görünmüyor.
        // bu nedenle bu kısmı yorum olarak bıraktım.

        /*bool same;
        do {
            same = false;
            info[j].id = rand() % 1000000 + 1;

            for (int check = 0; check < i; check++) {
                if (info[j].id == info[check].id) {
                    same = true;
                    break;
                }
            }
        } while (same); */

        info[j].phone = rand() % 1000000 + 1;

    }
    for(i=0; i<10000;i++){
        theFile << "NAME : " << info[i].name << "   ID: " << info[i].id << "   PHONE: " << info[i].phone << endl;
    }

    //theFile.close();
    ifstream isFile("info.txt");
    isFile.open("info.txt");
    float sum=0.0;
    for(i=0; i<10;i++){

        cout<< "Enter ID number : ";
        cin>> idNum;

        clock_t start, end;
        start = clock();
        int l;
        int flag=1;
        for( l=0; l<10000 && flag==1 ;l++){
            flag=0;
            isFile >> info[l].id ;
            if(info[l].id == idNum)
                break;
            flag=1;
        }
        if(flag==0)
            cout<< "NAME : "<< info[l].name << "   ID: " << info[l].id << "   PHONE: " << info[l].phone << endl;
        else if (flag==1)
            cout<< "The ID was not found in the file" << endl;

        end = clock();
        double extime = (double)(end - start) / CLOCKS_PER_SEC;
        cout<<"Execution time for the process: " << extime << "s"<<endl;
        cout<<endl;
        sum+=extime;
    }
    cout << "Average Time: " << sum/10 << "s"<< endl;
    cout<<endl;

    //     -------------SORTING----------------
    cout << "-------------SORTING----------------"<< endl;
    cout <<endl;
    ofstream sortFile("sort.txt");

    int id2;
    for(j=1;j<=elements;j++) {

        info[j].id = rand() % 1000000 + 1;

    }

   int temp;
    for (i = 0; i < elements; ++i)
    {
        for (j = i + 1; j < elements; ++j)
        {
            if (info[i].id > info[j].id)
            {
                temp =  info[i].id;
                info[i].id = info[j].id;
                info[j].id = temp;
            }
        }

        sortFile << "NAME : " << info[i].name << "   ID: " << info[i].id << "   PHONE: " << info[i].phone << endl;

    }
    //theFile.close();
    ifstream sFile("sort.txt");
    isFile.open("sort.txt");
    sum=0.0;
    for(i=0; i<10;i++){

        cout<< "Enter ID number : ";
        cin>> idNum;

        clock_t start, end;
        start = clock();

        int first = 0;
        int last = 9999;
        int middle = (first+last)/2;
        int flag=1;
        while(first <= last && flag==1)
        {
            flag=0;
            if(info[middle].id<idNum)
                first = middle+1;
            else if(info[middle].id==idNum)
            {
                break;
            }
            else
                last = middle-1;
            middle = (first+last)/2;
            flag=1;
        }
        if(flag==0)
            cout<< "NAME : "<< info[middle].name << "   ID: " << info[middle].id << "   PHONE: " << info[middle].phone << endl;
        else if (flag==1)
            cout<<"The ID was not found in the file" <<endl;


        end = clock();
        double extime = (double)(end - start) / CLOCKS_PER_SEC;
        cout<<"Execution time for the process: " << extime << "s"<<endl;
        cout<<endl;
        sum=sum+extime;
    }
    cout << "Average Time: " << sum/10 << "s"<< endl;



    return 0;
}

