#include <stdio.h>

int count_words_in_file(const char *filename) {
    FILE *f;
    char ch;
    int count = 1;   // at least 1 word if file not empty

    f = fopen(filename, "r");
    if (f == NULL) {
        printf("Cannot open file for reading.\n");
        return -1;
    }

    // count spaces in the file
    while (fscanf(f, "%c", &ch) == 1) {
        if (ch == ' ') {
            count++;
        }
    }

    fclose(f);
    return count;
}

int main() {
    int choice;
    char sentence[200];
    FILE *f;
    const char *filename = "myfile.txt";

    while (1) {
        printf("Menu:\n");
        printf("1. Write sentence to file\n");
        printf("2. Read file\n");
        printf("3. Count number of words in file\n");
        printf("4. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        getchar();   // consume leftover newline from scanf

        switch (choice) {
        case 1:
            printf("Enter sentence: ");
            fgets(sentence, sizeof(sentence), stdin);

            f = fopen(filename, "w");
            if (f == NULL) {
                printf("Cannot open file for writing.\n");
                break;
            }
            fputs(sentence, f);
            fclose(f);
            printf("Written.\n");
            break;

        case 2:
            f = fopen(filename, "r");
            if (f == NULL) {
                printf("Cannot open file for reading.\n");
                break;
            }
            printf("File contents:\n");
            while (fgets(sentence, sizeof(sentence), f) != NULL) {
                printf("%s", sentence);
            }
            fclose(f);
            break;

        case 3: {
            int w = count_words_in_file(filename);
            if (w >= 0) {
                printf("Total number of words: %d\n", w);
            }
            break;
        }

        case 4:
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }
}
