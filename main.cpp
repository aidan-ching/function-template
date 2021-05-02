#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index)
{
    unsigned min = index;
    for (unsigned i = index; i < vals.size(); ++i)
    {
        if (vals.at(i) < vals.at(min))
        {
            min = i;
        }
    }

    return min;
}

template<typename T>
void selection_sort(vector<T> &vals)
{
    unsigned minIndex;
    T temp;
    for (unsigned i = 0; i < vals.size(); ++i)
    {
        for (unsigned j = i; j < vals.size(); ++j)
        {
            minIndex = min_index(vals, j);
            temp = vals.at(j);
            vals.at(j) = vals.at(minIndex);
            vals.at(minIndex) = temp;
        }
    }
}

template<typename T>
T getElement(vector<T> vals, int index)
{
    return vals.at(index);
}

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}


int main()
{
    
    //test harness for part 1
    vector<int> userVector;
    for (unsigned i = 50; i > 0; --i)
    {
        userVector.push_back(i);
    }

    for (unsigned i = 0; i < userVector.size(); ++i)
    {
        cout << userVector.at(i) << " ";
    }

    cout << endl;

    selection_sort(userVector);

    cout << endl << endl;

    for (unsigned i = 0; i < userVector.size(); ++i)
    {
        cout << userVector.at(i) << " ";
    }


//Part B
     srand(time(0));
     vector<char> vals = createVector();
     char curChar;
     int index;
     int numOfRuns = 10;
     while(--numOfRuns >= 0){
         cout << "Enter a number: " << endl;
         cin >> index;

        try{
            curChar = getElement(vals,index);
            cout << "Element located at " << index << ": is " << curChar << endl;
        }

        catch(const std::out_of_range& excpt)
        {
            cout << "out of range exception occured" << endl;
        }
         
         
    }

    return 0;
}
