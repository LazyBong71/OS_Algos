#include <iostream>
#include <list>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of frames: ";
    cin >> n;
    int m;
    cout << "Enter the number of pages: ";
    cin >> m;
    list<int> lruList;
    int pageFaults = 0;
    cout << "Enter the page reference string:\n";
    for (int i = 0; i < m; i++)
    {
        int page;
        cin >> page;
        bool pageFound = false;
        for (auto it = lruList.begin(); it != lruList.end(); ++it)
        {
            if (*it == page)
            {
                lruList.erase(it);
                lruList.push_front(page);
                pageFound = true;
                break;
            }
        }
        if (!pageFound)
        {
            pageFaults++;
            if (lruList.size() == n)
            {
                lruList.pop_back();
            }
            lruList.push_front(page);
        }
    }
    cout << "Total Page Faults: " << pageFaults << endl;
    return 0;
}