#include <iostream>
#include <fstream>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem; // 1
    tmp->info = value; // 2
    tmp->link = NULL; // 3
    if (last != NULL)
        last->link = tmp; // 4
    last = tmp; // 5
    if (first == NULL)
        first = tmp; // 6
}

void print(Elem* first)
{
    while (first != NULL)
    {
        cout << first->info << ' ';
        first = first->link;
    }
    cout << endl;
}

Info min(Elem* first)
{
    Info minvalue = first->info;
    while (first->link != NULL)
    {
        first = first->link;
        if (first->info < minvalue)
            minvalue = first->info;
    }
    return minvalue;
}

Info max(Elem* first)
{
    Info maxvalue = NULL;
    while (first != NULL)
    {
        if (first->info > maxvalue)
            maxvalue = first->info;
        first = first->link;
    }
    return maxvalue;
}

void find(Elem* first, Info value)
{
    bool found = false; int i = 0;
    while (first != NULL)
    {
        if (first->info == value)
        {
            cout << "Value found at position " << i << endl;
            found = true;
        }
        first = first->link;
        i++;
    }
    if (!found) cout << "There are no positions with the value of " << value << endl;
}

double avg(Elem* first)
{
    Info sum = 0; int i = 0;
    while (first != NULL)
    {
        i++;
        sum += first->info;
        first = first->link;
    }
    return sum * 1.0 / i;
}

double avg2(Elem* first)
{
    return (min(first) + max(first)) * 1.0 / 2;
}


int main()
{
    Elem *first = NULL, *last = NULL;
    ifstream fin("file.txt");
    Info n, value;
    while (fin >> n)
        enqueue(first, last, n);
    print(first); cout << endl;
    cout << "Minimal value : " << min(first) << endl << endl;
    cout << "Maximal value : " << max(first) << endl << endl;
    cout << "Average value : " << avg(first) << endl << endl;
    cout << "Average value (min-max) : " << avg2(first) << endl << endl;
    cout << "Enter the value to search : "; cin >> value;
    find(first, value); cout << endl;
}