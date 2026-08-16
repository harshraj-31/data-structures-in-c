#include <stdio.h>
#include <conio.h>

// Function to find the index of the least recently used frame
int findLRU(int time[], int n) {
    int i, min = time[0], pos = 0;
    
    // Find the smallest time value
    for (i = 1; i < n; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int no_of_frames, no_of_pages, pages[50];
    int frames[10], time[10];
    int i, j, counter = 0, faults = 0;
    int is_hit, empty_slot, lru_index;

    clrscr();

    printf("Enter number of frames (cache size): ");
    scanf("%d", &no_of_frames);

    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter the page reference string:\n");
    for (i = 0; i < no_of_pages; i++) {
        scanf("%d", &pages[i]);
    }

    // Initialize all frames to -1 (empty)
    for (i = 0; i < no_of_frames; i++) {
        frames[i] = -1;
    }

    printf("\nIncoming \t Cache State\n");

    // Process each incoming page
    for (i = 0; i < no_of_pages; i++) {
        is_hit = 0;
        empty_slot = -1;

        // 1. Check if the page is already in the cache (Hit)
        for (j = 0; j < no_of_frames; j++) {
            if (frames[j] == pages[i]) {
                is_hit = 1;
                counter++;
                time[j] = counter; // Update time since it was just used
                break;
            }
        }

        // 2. If it's a miss, we need to bring it into the cache
        if (is_hit == 0) {
            faults++;
            counter++;

            // Look for an empty frame
            for (j = 0; j < no_of_frames; j++) {
                if (frames[j] == -1) {
                    empty_slot = j;
                    break;
                }
            }

            // If an empty frame exists, insert it there
            if (empty_slot != -1) {
                frames[empty_slot] = pages[i];
                time[empty_slot] = counter;
            } 
            // If cache is full, replace the Least Recently Used frame
            else {
                lru_index = findLRU(time, no_of_frames);
                frames[lru_index] = pages[i];
                time[lru_index] = counter;
            }
        }

        // Display the current state of the cache
        printf("%d \t\t ", pages[i]);
        for (j = 0; j < no_of_frames; j++) {
            if (frames[j] != -1) {
                printf("%d ", frames[j]);
            } else {
                printf("- ");
            }
        }
        
        if (is_hit) printf("\t (Hit)\n");
        else printf("\t (Miss)\n");
    }

    printf("\nTotal Page Faults (Misses): %d\n", faults);

    getch();
    return 0;
}
