// Write a program to implement to find out solution for 0/1 knapsack problem using
// LCBB (Least Cost Branch and Bound).

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight, value;
    double ratio;
};

bool compare(const Item& a, const Item& b) {
    return a.ratio > b.ratio;
}

int upperBound(const vector<Item>& items, int capacity, int index, int currWeight, int currValue) {
    int remain = capacity - currWeight;
    double bound = currValue;
    while (index < items.size() && items[index].weight <= remain) {
        remain -= items[index].weight;
        bound += items[index].value;
        index++;
    }
    if (index < items.size())
        bound += remain * items[index].ratio;
    return (int)bound;
}

void knapsackBnB(const vector<Item>& items, int capacity, int index,
                 int currWeight, int currValue,
                 int& maxValue, vector<int>& currSelected, vector<int>& bestSelected) {

    if (index == items.size() || currWeight == capacity) {
        if (currValue > maxValue) {
            maxValue = currValue;
            bestSelected = currSelected;
        }
        return;
    }

    int bound = upperBound(items, capacity, index, currWeight, currValue);
    if (bound <= maxValue) return;

    // Include
    if (currWeight + items[index].weight <= capacity) {
        currSelected.push_back(index);
        knapsackBnB(items, capacity, index + 1,
                    currWeight + items[index].weight,
                    currValue + items[index].value,
                    maxValue, currSelected, bestSelected);
        currSelected.pop_back();
    }

    // Exclude
    knapsackBnB(items, capacity, index + 1,
                currWeight, currValue,
                maxValue, currSelected, bestSelected);
}

int main() {
    vector<Item> items = {{2, 1}, {5, 2}, {1, 7}, {3, 15}};
    int capacity = 8, maxValue = 0;
    vector<int> currSelected, bestSelected;

    for (auto& item : items)
        item.ratio = (double)item.value / item.weight;

    sort(items.begin(), items.end(), compare);
    knapsackBnB(items, capacity, 0, 0, 0, maxValue, currSelected, bestSelected);

    cout << "Optimal value: " << maxValue << "\nSelected items (indices): ";
    for (int i : bestSelected) cout << i << " ";
    cout << endl;
    return 0;
}


// Optimal value: 22
// Selected items (indices): 2 3 
