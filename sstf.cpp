#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // Define initial position of the head and request queue
    int initial_pos = 50;
    vector<int> requests = { 82, 170, 43, 140, 24, 16 };

    // Find the request with shortest seek time to the initial position
    int total_head_movement = 0;
    while (!requests.empty()) {
        int closest_request_index = 0;
        int shortest_seek_time = abs(initial_pos - requests[0]);
        for (int i = 1; i < requests.size(); i++) {
            int current_seek_time = abs(initial_pos - requests[i]);
            if (current_seek_time < shortest_seek_time) {
                closest_request_index = i;
                shortest_seek_time = current_seek_time;
            }
        }

        // Move the head to the closest request and remove the request from the queue
        total_head_movement += shortest_seek_time;
        initial_pos = requests[closest_request_index];
        requests.erase(requests.begin() + closest_request_index);
    }

    // Output results
    cout << "Total head movement: " << total_head_movement << endl;

    return 0;
}
