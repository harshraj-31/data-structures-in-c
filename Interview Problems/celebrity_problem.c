#include <stdio.h>
#include <conio.h>

#define MAX 10

// Matrix representing who knows whom
// matrix[i][j] = 1 means 'i' knows 'j'
int matrix[MAX][MAX];

// Helper function to check if person A knows person B
int knows(int a, int b) {
    return matrix[a][b];
}

int main() {
    int n, i, j;
    int candidate = 0; // Assume person 0 is the celebrity initially
    int is_celeb = 1;

    clrscr();

    printf("Enter number of people (max 10): ");
    scanf("%d", &n);

    printf("Enter the relation matrix (0 or 1):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Step 1: Find a potential celebrity candidate
    for (i = 1; i < n; i++) {
        // If candidate knows 'i', the candidate is definitely NOT a celebrity.
        // But 'i' could be, so we update our candidate.
        if (knows(candidate, i)) {
            candidate = i;
        }
    }

    // Step 2: Verify the candidate
    for (i = 0; i < n; i++) {
        if (i != candidate) {
            // A celebrity should know NOBODY (candidate knows i == 0)
            // EVERYBODY should know the celebrity (i knows candidate == 1)
            if (knows(candidate, i) == 1 || knows(i, candidate) == 0) {
                is_celeb = 0;
                break;
            }
        }
    }

    // Display the final result
    if (is_celeb) {
        printf("\nPerson %d is the Celebrity!\n", candidate);
    } else {
        printf("\nThere is no Celebrity in the party.\n");
    }

    getch();
    return 0;
}
