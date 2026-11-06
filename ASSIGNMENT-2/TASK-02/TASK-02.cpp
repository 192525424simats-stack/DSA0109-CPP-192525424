
#include <iostream>
#include <vector>
using namespace std;

// Return reference to highest mark
int& highestMark(int marks[], int size) {
    int maxIndex = 0;

    for (int i = 1; i < size; i++) {
        if (marks[i] > marks[maxIndex]) {
            maxIndex = i;
        }
    }

    return marks[maxIndex];
}

// Return index instead of reference
int highestIndex(const vector<int>& marks) {
    int maxIndex = 0;

    for (int i = 1; i < (int)marks.size(); i++) {
        if (marks[i] > marks[maxIndex]) {
            maxIndex = i;
        }
    }

    return maxIndex;
}

int main() {
    int marks[5] = {75, 88, 92, 81, 85};

    cout << "Original marks: ";

    for (int mark : marks) {
        cout << mark << " ";
    }

    cout << '\n';

    // Modify highest mark using returned reference
    highestMark(marks, 5) += 2;

    cout << "After moderation: ";

    for (int mark : marks) {
        cout << mark << " ";
    }

    cout << '\n';

    vector<int> scores = {70, 85, 95, 80};

    int index = highestIndex(scores);

    scores[index] += 2;

    cout << "Highest score after update: "
         << scores[index] << '\n';

    return 0;
}

