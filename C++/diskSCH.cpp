//Andrew Broek 
#include<iostream>
#include<fstream>
#include<string>
#include<bits/stdc++.h>
using namespace std;


//FCFS help found at https://www.geeksforgeeks.org/fcfs-disk-scheduling-algorithms/
void FCFS(int arr[], int head)
{
    int size = 1000;
    int seek_count = 0;
    int distance, cur_track;

    for (int i = 0; i < size; i++) {
        cur_track = arr[i];

        // calculate absolute distance
        distance = abs(cur_track - head);

        // increase the total count
        seek_count += distance;

        // accessed track is now new head
        head = cur_track;
    }

    cout << "Total number of seek operations = "
        << seek_count << endl;

    // Seek sequence would be the same
    // as request array sequence
    cout << "Seek Sequence is" << endl;

    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}

//scan algorithm help at https://www.geeksforgeeks.org/scan-elevator-disk-scheduling-algorithms/
void SCAN(int arr[], int head, string direction)
{
    int seek_count = 0;
    int distance, cur_track;
    int disk_size = 1000;
    vector<int> left, right;
    vector<int> seek_sequence;

    // appending end values
    // which has to be visited
    // before reversing the direction
    if (direction == "left")
        left.push_back(0);
    else if (direction == "right")
        right.push_back(disk_size - 1);

    for (int i = 0; i < 1000; i++) {
        if (arr[i] < head)
            left.push_back(arr[i]);
        if (arr[i] > head)
            right.push_back(arr[i]);
    }

    // sorting left and right vectors
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    // run the while loop two times.
    // one by one scanning right
    // and left of the head
    int run = 2;
    while (run--) {
        if (direction == "left") {
            for (int i = left.size() - 1; i >= 0; i--) {
                cur_track = left[i];

                // appending current track to seek sequence
                seek_sequence.push_back(cur_track);

                // calculate absolute distance
                distance = abs(cur_track - head);

                // increase the total count
                seek_count += distance;

                // accessed track is now the new head
                head = cur_track;
            }
            direction = "right";
        }
        else if (direction == "right") {
            for (int i = 0; i < right.size(); i++) {
                cur_track = right[i];
                // appending current track to seek sequence
                seek_sequence.push_back(cur_track);

                // calculate absolute distance
                distance = abs(cur_track - head);

                // increase the total count
                seek_count += distance;

                // accessed track is now new head
                head = cur_track;
            }
            direction = "left";
        }
    }

    cout << "Total number of seek operations = "
        << seek_count << endl;

    cout << "Seek Sequence is" << endl;

    for (int i = 0; i < seek_sequence.size(); i++) {
        cout << seek_sequence[i] << endl;
    }
}


// Calculates difference of each 
// track number with the head position
void calculatedifference(int request[], int head,
    int diff[][2], int n)
{
    for (int i = 0; i < n; i++)
    {
        diff[i][0] = abs(head - request[i]);
    }
}

// Find unaccessed track which is
// at minimum distance from head
int findMIN(int diff[][2], int n)
{
    int index = -1;
    int minimum = 1e9;

    for (int i = 0; i < n; i++)
    {
        if (!diff[i][1] && minimum > diff[i][0])
        {
            minimum = diff[i][0];
            index = i;
        }
    }
    return index;
}

void SSTF(int request[],
    int head, int n)
{
    if (n == 0)
    {
        return;
    }

    // Create array of objects of class node   
    int diff[n][2] = { { 0, 0 } };

    // Count total number of seek operation  
    int seekcount = 0;

    // Stores sequence in which disk access is done
    int seeksequence[n + 1] = { 0 };

    for (int i = 0; i < n; i++)
    {
        seeksequence[i] = head;
        calculatedifference(request, head, diff, n);
        int index = findMIN(diff, n);
        diff[index][1] = 1;

        // Increase the total count
        seekcount += diff[index][0];

        // Accessed track is now new head
        head = request[index];
    }
    seeksequence[n] = head;

    cout << "Total number of seek operations = "
        << seekcount << endl;
    cout << "Seek sequence is : " << "\n";

    // Print the sequence
    for (int i = 0; i <= n; i++)
    {
        cout << seeksequence[i] << "\n";
    }
}
// Driver code
int main(int argc, char*argv[])
{
    fstream cyl;
    int i = 0;
    cyl.open(argv[1]);
    int cylinders[1000];
    string d = "right";
    while(!cyl.eof())
    {
        cyl >> cylinders[i];
        i++;
    }
    
    //FCFS(cylinders, cylinders[i]);
    //SCAN(cylinders, cylinders[i], d);
    SSTF(cylinders, cylinders[i], 1000);

    cyl.close();
    
    
  
    return 0;
}
