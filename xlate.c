#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX_CHRONIC 17
#define MAX_MONTH 7
#define MAX_ADMTYP 3

int main() {
	char previd[16], newid[16];

	int data[MAX_MONTH * MAX_CHRONIC * MAX_ADMTYP];
	int row[MAX_CHRONIC];
    int adm[MAX_ADMTYP];
	int month;
	int base, shift, i, j;

	strcpy(previd, "");

	while (scanf("%s", newid) != EOF) {
		for (i = 0; i < MAX_CHRONIC; i++) {
			scanf("%d", &row[i]);
		}

        for (i = 0; i < MAX_ADMTYP; i++) {
            scanf("%d", &adm[i]);
        }
        
		scanf("%d", &month);

		if (strcmp(newid, previd)) {
			if (strcmp(previd, "")) {
				printf("%s", previd);

				for (i = 0; i < MAX_MONTH * MAX_CHRONIC * MAX_ADMTYP; i++) {
					printf(",%d", data[i]);
				}

				printf("\n");
			}

			for (i = 0; i < MAX_MONTH * MAX_CHRONIC * MAX_ADMTYP; i++) {
				data[i] = 0;
			}
		}

		strcpy(previd, newid);

		base = month * MAX_CHRONIC * MAX_ADMTYP;
        
        for (shift = 0; shift < 3; shift++) {
            if (adm[shift]) {
                break;
            }
        }

        assert(shift < 3);
        
		for (i = 0; i < MAX_CHRONIC; i++) {
            j = i * MAX_ADMTYP;
			data[base + shift + j] = data[base + shift + j] || row[i];
		}
	}

	if (strcmp(previd, "")) {
		printf("%s", previd);

		for (i = 0; i < MAX_MONTH * MAX_CHRONIC * MAX_ADMTYP; i++) {
			printf(",%d", data[i]);
		}

		printf("\n");
	}

	return 0;
}
