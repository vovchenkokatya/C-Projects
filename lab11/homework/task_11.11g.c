//
// Created by Katya on 07.11.2026.
//
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct Passenger {
    char surname[50];
} Passenger;

typedef struct Baggage {
    int passenger_id;
    int count;
    double weight;
} Baggage;

bool write_passenger_files(const char* passengers_filename, const char* baggage_filename) {
    int n;
    printf("Enter the number of passengers: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return false;
    }

    FILE* passengers = fopen(passengers_filename, "wb");
    if (passengers == NULL) {
        return false;
    }

    FILE* baggage = fopen(baggage_filename, "wb");
    if (baggage == NULL) {
        fclose(passengers);
        return false;
    }

    for (int i = 0; i < n; i++) {
        Passenger passenger = {0};
        Baggage bag = {0};
        bag.passenger_id = i + 1;

        printf("Enter surname of passenger %d: ", i + 1);
        if (scanf("%49s", passenger.surname) != 1) {
            fclose(passengers);
            fclose(baggage);
            return false;
        }

        printf("Enter the number of items and total weight: ");
        if (scanf("%d %lf", &bag.count, &bag.weight) != 2 ||
            bag.count < 0 || bag.weight < 0 || !isfinite(bag.weight)) {
            fclose(passengers);
            fclose(baggage);
            return false;
        }

        if (fwrite(&passenger, sizeof(Passenger), 1, passengers) != 1 ||
            fwrite(&bag, sizeof(Baggage), 1, baggage) != 1) {
            fclose(passengers);
            fclose(baggage);
            return false;
        }
    }

    int passengers_status = fclose(passengers);
    int baggage_status = fclose(baggage);
    return passengers_status == 0 && baggage_status == 0;
}

bool read_passenger(FILE* file, int id, Passenger* passenger) {
    if (id <= 0 || fseek(file, (id - 1L) * sizeof(Passenger), SEEK_SET) != 0) {
        return false;
    }
    return fread(passenger, sizeof(Passenger), 1, file) == 1;
}

int find_similar_baggage(const char* passengers_filename, const char* baggage_filename, double a) {
    FILE* passengers = fopen(passengers_filename, "rb");
    if (passengers == NULL) {
        return -1;
    }

    FILE* baggage = fopen(baggage_filename, "rb");
    if (baggage == NULL) {
        fclose(passengers);
        return -1;
    }

    Baggage first, second;
    bool found = false;

    while (fread(&first, sizeof(Baggage), 1, baggage) == 1) {
        long position = ftell(baggage);
        if (position == -1L) {
            fclose(passengers);
            fclose(baggage);
            return -1;
        }

        while (fread(&second, sizeof(Baggage), 1, baggage) == 1) {
            if (first.passenger_id != second.passenger_id &&
                first.count == second.count &&
                fabs(first.weight - second.weight) <= a) {

                Passenger passenger1, passenger2;

                if (!read_passenger(passengers, first.passenger_id, &passenger1) ||
                    !read_passenger(passengers, second.passenger_id, &passenger2)) {
                    fclose(passengers);
                    fclose(baggage);
                    return -1;
                    }

                printf("%s and %s\n", passenger1.surname, passenger2.surname);
                found = true;
                }
        }

        if (ferror(baggage) || fseek(baggage, position, SEEK_SET) != 0) {
            fclose(passengers);
            fclose(baggage);
            return -1;
        }
    }

    int result = ferror(baggage) ? -1 : (int)found;
    fclose(passengers);
    fclose(baggage);
    return result;
}

int main(void) {
    const char* passengers_filename = "passengers.bin";
    const char* baggage_filename = "baggage.bin";

    if (!write_passenger_files(passengers_filename, baggage_filename)) {
        printf("Failed to write passenger files.\n");
        return 1;
    }

    double a;
    printf("Enter the maximum weight difference: ");
    if (scanf("%lf", &a) != 1 || a < 0 || !isfinite(a)) {
        printf("Invalid weight difference.\n");
        return 1;
    }

    int result = find_similar_baggage(passengers_filename, baggage_filename, a);

    if (result == -1) {
        printf("Failed to read passenger files.\n");
        return 1;
    }

    if (result == 0) {
        printf("No matching passengers found.\n");
    }

    return 0;
}