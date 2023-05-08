#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // Define initial position of the head and request queue
    int initial_pos = 50;
    vector<int> requests = { 82, 170, 43, 140, 24, 16 };

    // Sort requests based on cylinder number
    sort(requests.begin(), requests.end());

    // Find the index of the request closest to the initial position
    int closest_request_index = 0;
    for (int i = 0; i < requests.size(); i++) {
        if (requests[i] >= initial_pos) {
            closest_request_index = i;
            break;
        }
    }

    // Go up from initial position
    int total_head_movement = 0;
    for (int i = closest_request_index; i < requests.size(); i++) {
        total_head_movement += abs(initial_pos - requests[i]);
        initial_pos = requests[i];
    }

    // Go down from maximum cylinder to last request
    total_head_movement += abs(initial_pos - CYLINDER_MAX);
    initial_pos = CYLINDER_MAX;

    // Go down from initial position
    for (int i = closest_request_index - 1; i >= 0; i--) {
        total_head_movement += abs(initial_pos - requests[i]);
        initial_pos = requests[i];
    }

    // Output results
    cout << "Total head movement: " << total_head_movement << endl;

    return 0;
}
