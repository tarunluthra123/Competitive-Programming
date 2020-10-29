#include <bits/stdc++.h>
using namespace std;

class item
{
public:
    int value;
    int weight;
};

bool cmp(item a, item b)
{
    double x = double((double)a.value / (double)a.weight);
    double y = double((double)b.value / (double)b.weight);
    return x > y;
}

int partition(item *a, int s, int e)
{
    item pivot = a[e];
    int i = s - 1;
    int j = s;
    for (; j < e; j++)
    {
        if (cmp(a[j], pivot))
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    //Bring pivot element to its correct position
    swap(a[i + 1], a[e]);
    return i + 1;
}

void quicksort(item *a, int s, int e)
{
    if (s >= e)
        return;

    int p = partition(a, s, e);
    quicksort(a, s, p - 1); //sort the left part i.e. part that is less than pivot element
    quicksort(a, p + 1, e); //sort the right part i.e. part that is greater than pivot element
}

int main()
{
    int n, W;
    cin >> n >> W;
    item arr[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].value;
        cin >> arr[i].weight;
    }
    
	// Sort on the basis of price/weight ratio
    quicksort(arr, 0, n - 1);

    int currWeight = 0;
    double finalValue = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight + currWeight <= W)
        {
            finalValue += arr[i].value;
            currWeight += arr[i].weight;
        }
        else
        {
            int remain = W - currWeight;
            finalValue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }

    cout << fixed;
    cout << setprecision(1) << finalValue << endl;

    return 0;
}

