//
// Created by Katya on 29.10.2026.
//
#include <stdio.h>
#include <string.h>
#define N 100

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    char surname[50];
    char name[50];
    char sex;
    Date birth;
    char position[100];
} Employee;

int input(Employee* x) {
    printf("Input surname and name: ");
    if (scanf("%49s%49s", x->surname, x->name) != 2) return -1;
    printf("Input sex (M/F): ");
    if (scanf(" %c", &x->sex) != 1) return -1;
    if (x->sex != 'M' && x->sex != 'F') return -1;
    printf("Input birth date (day month year): ");
    if (scanf("%d%d%d", &x->birth.day, &x->birth.month,
              &x->birth.year) != 3) return -1;
    printf("Input position: ");
    if (scanf(" %99[^\n]", x->position) != 1) return -1;
    return 0;
}

void vyvod(const Employee* x) {
    printf("%s %s, %c, %02d.%02d.%04d, %s\n",
           x->surname, x->name, x->sex, x->birth.day,
           x->birth.month, x->birth.year, x->position);
}

int most_common_position(const Employee p[], int n) {
    int index = 0, max_count = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (strcmp(p[i].position, p[j].position) == 0) count++;
        }
        if (count > max_count) {
            max_count = count;
            index = i;
        }
    }
    return index;
}

int oldest_man(const Employee p[], int n) {
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (p[i].sex != 'M') continue;
        if (index == -1) {
            index = i;
            continue;
        }
        Date a = p[i].birth;
        Date b = p[index].birth;
        if (a.year < b.year ||
            (a.year == b.year && a.month < b.month) ||
            (a.year == b.year && a.month == b.month && a.day < b.day)) {
            index = i;
        }
    }
    return index;
}

int main() {
    Employee p[N];
    int n;
    printf("Input number of employees: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > N) return 1;

    for (int i = 0; i < n; i++) {
        printf("\nEmployee %d\n", i + 1);
        if (input(&p[i]) != 0) return 1;
    }

    int k = most_common_position(p, n);
    printf("\nMost common position: %s\n", p[k].position);

    k = oldest_man(p, n);
    if (k == -1) printf("No men\n");
    else {
        printf("Oldest man: ");
        vyvod(&p[k]);
    }
    return 0;
}
