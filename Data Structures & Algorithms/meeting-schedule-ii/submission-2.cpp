/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int max_rooms = 0;
        int curr = 0;
        map<int, int> rooms;

        for (auto & [start,end] : intervals) {
            rooms[start] += 1;
            rooms[end] -= 1;
        }

        for (auto & rooms : rooms) {
            curr += rooms.second;
            max_rooms = max(curr, max_rooms);
        }

        return max_rooms;
    }
};
