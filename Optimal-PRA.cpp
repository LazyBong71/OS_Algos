#include <iostream>
using namespace std;

#define FRAMES_NUMBER 4

int Optimal(int pages[], int size)
{
    int frames[FRAMES_NUMBER];
    for (int i = 0; i < FRAMES_NUMBER; i++)
        frames[i] = -1;

    int paeFaults = 0;

    for (int pageIndex = 0; pageIndex < size; pageIndex++)
    {
        bool isFound = false;
        for (int i = 0; i < FRAMES_NUMBER; i++)
            if (frames[i] == pages[pageIndex])
            {
                isFound = true;
                cout << pages[pageIndex] << endl;
                break;
            }

        if (!isFound)
        {
            bool hasFreeFrame = false;
            for (int i = 0; i < FRAMES_NUMBER; i++)
                if (frames[i] == -1)
                {
                    hasFreeFrame = true;
                    frames[i] = pages[pageIndex];
                    paeFaults++;

                    cout << pages[pageIndex] << "\t\t";
                    for (int f = 0; f < FRAMES_NUMBER; f++)
                        cout << frames[f] << "\t";
                    cout << endl;

                    break;
                }

            if (!hasFreeFrame)
            {
                int nextUse[FRAMES_NUMBER];
                for (int i = 0; i < FRAMES_NUMBER; i++)
                    nextUse[i] = size + 1;

                for (int i = 0; i < FRAMES_NUMBER; i++)
                    for (int p = pageIndex; p < size; p++)
                        if (pages[p] == frames[i])
                        {
                            nextUse[i] = p;
                            break;
                        }

                int victim = 0;
                for (int i = 0; i < FRAMES_NUMBER; i++)
                    if (nextUse[i] > nextUse[victim])
                        victim = i;

                frames[victim] = pages[pageIndex];
                paeFaults++;

                cout << pages[pageIndex] << "\t\t";
                for (int f = 0; f < FRAMES_NUMBER; f++)
                    cout << frames[f] << "\t";
                cout << endl;
            }
        }
    }
    return paeFaults;
}

int main(int argc, char const *argv[])
{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};

    int pageFaults = Optimal(pages, 13);
    cout << "Number Of Page Faults = " << pageFaults;

    getchar();
    return 0;
}

// 4 13
// 7 0 1 2 0 3 0 4 2 3 0 3 2