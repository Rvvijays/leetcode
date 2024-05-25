class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        sort(meetings.begin(), meetings.end());

        vector<long long> roomsAvailableAt(n,0);
        vector<int> roomFreq(n,0);

        for (int i = 0; i < meetings.size(); i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];
            int duration = end - start;

            int earlyRoom = 0;
            long long earlyRoomAvailableAt = LLONG_MAX;

            int found = false;

            for (int room = 0; room < n; room++) {
                if (roomsAvailableAt[room] <= start) {
                    roomsAvailableAt[room] = end;
                    roomFreq[room]++;
                    found = true;
                    break;
                }

                if (earlyRoomAvailableAt > roomsAvailableAt[room]) {
                    earlyRoomAvailableAt = roomsAvailableAt[room];
                    earlyRoom = room;
                }
            }


            if(!found) {
                roomsAvailableAt[earlyRoom] += duration;
                roomFreq[earlyRoom]++;
            }
        }


        int maxRoomUsed = 0;
        int roomNo = -1;

        for (int room = 0; room < n; room++) {
            if(maxRoomUsed < roomFreq[room]) {
                maxRoomUsed = roomFreq[room];
                roomNo = room;
            }
        }

        return roomNo;


    }
};