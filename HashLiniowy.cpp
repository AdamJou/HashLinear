#include <fstream>
#include <iostream>

using namespace std;


class Data
{
public:
    int key;
    string txt;

};


class Hash
{
private:
    Data** tab;
    int size;
public:
    Hash(int n);
    int hashFunction(int key);
    void insert(int key, string txt);
    void remove(int key);
    void printTable();
    int scan_for(int k);
    int find(int k);
};

int Hash::find(int k)
{
    int i= scan_for(k);

    if(i==-1 || tab[i]==nullptr || tab[i]->key == -1)
    {
        cout<<"Nie znaleziono" << endl;
        return 0;
    }
    cout<<"Indeks "  << i <<  " Value: " << tab[i]->txt << endl;
    return 0;
}


int Hash::scan_for(int k)
{
    int f = hashFunction(k);
    int d = -1;
    int i = f;

    while(tab[i]!=nullptr)
    {
        if(tab[i]->key==-1)
        {
            if(d==-1)

                d=i;
        }
        else if (tab[i]->key == k)
        {
            return i;
        }
        i=(i+1) % size;
        if(i==f)
            return d;
    }

    if(d!=-1)
        return d;

    return i;

}



Hash::Hash(int n)
{
    size = n;
    tab = new Data*[n];
    for (int i = 0; i < n; i++)
    {
        tab[i] = nullptr;
    }
}

int Hash::hashFunction(int key)
{
    return key % size;
}

void Hash::insert(int key, string txt)
{
    int i = scan_for(key);
    if(i==-1)
    {
        cout<<"Brak miejsca";
    }
    else
    {
        tab[i] = new Data();
        tab[i]->key = key;
        tab[i]->txt = txt;

    }


}

void Hash::remove(int key)
{
    int i = scan_for(key);
     if (tab[i]->key == -1)
    {
        cout<<"Nie ma takiego elementu" << endl;
    }
    if(i!=-1 && tab[i]!=nullptr)
    {
        tab[i]->key = -1;
        tab[i]->txt = "deleted";

    }



}

void Hash::printTable()
{

        cout<<"INDEKS \tKLUCZ \tWARTOSC " << endl;
        for (int i = 0; i < size; i++)
        {
            if (tab[i] != nullptr)
                cout << endl << "["  << i <<"]" << "\t" << tab[i]->key << "\t" << tab[i]->txt << endl;
        }



}






int main()
{
    Hash tab(10);

    tab.insert(1,"ABC");
    tab.insert(2,"ALG");
    tab.insert(3,"CDE");
    tab.insert(38,"PDW");
    tab.insert(0,"WOW");

    tab.printTable();



    return 0;
}
