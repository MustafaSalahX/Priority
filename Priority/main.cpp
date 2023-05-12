#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    struct process
    {
        int id, at, bt, pr, wt;
    };// Struct Definition
    process* arr;
    int num;
    cout << "************************************************************ \n";
    cout << "***                                                     **** \n";
    cout << "***     This Program By Team AlfaX @Modern Academy      **** \n";
    cout << "***                                                     **** \n";
    cout << "************************************************************ \n";
    cout << " Enter number of Processes : ";
    cin >> num;
    arr = new process[num];//Dynamic Array of Struct 
    cout << " \tArrival time \t Burst time \t Priority"  << endl;
    for (int i = 0; i < num; i++)
    {
        arr[i].id = i + 1;
        cout << "\nP" << i + 1 << "\t ";
        cin >> arr[i].at >> arr[i].bt >>arr[i].pr;
    }
    //Sort Processes in ascending order according to its arrival time using 
    process temp;
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (arr[i].at > arr[j].at)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (arr[i].pr > arr[j].pr)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    // Calculating Waiting Time for each Process
    arr[0].wt = 0;
    int tot = 0;
    for (int i = 1; i < num; i++)
    {
        tot += arr[i - 1].bt;
        (arr[i].wt) = tot - arr[i].at;
    }
    cout << "--------------------------------------\n";
    cout << "The Sequence of Processes Will be & The Waiting Time for each process\n";
    cout << "\t Arrival time \t Burst time \t  Waiting time \t Priority \n";
    for (int i = 0; i < num; i++)
    {
        cout << "P" << arr[i].id << "\t \t" << arr[i].at << " \t \t" << arr[i].bt << "\t \t" << arr[i].wt << "\t \t" << arr[i].pr << endl;
    }
    cout << "---------------------------------------------------------------------\n";
    cout << "Gantt Chart \n ";// Drawing Gantt chart
    for (int i = 0; i < num; i++)
    {
        cout << setw(arr[i].bt) << "P" << arr[i].id << "\t";
    }
    cout << endl << "0";
    tot = 0;
    for (int i = 0; i < num; i++)
    {
        tot += arr[i].bt;
        cout << setfill('-') << setw(arr[i].bt * 2) << tot;
    }
    int sum = 0;
    for (int i = 0; i < num; i++)
    {
        sum += arr[i].wt;
    }
    cout << "\n \n Average Waiting time = "<<sum<<" / "<<num<<" = "<<(float)sum/num<<endl;
        delete[] arr;











}