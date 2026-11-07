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

bool find_best_baggage(const char* filename, Baggage* best) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return false;
    }

    if (fread(best, sizeof(Baggage), 1, file) != 1) {
        fclose(file);
        return false;
    }

    Baggage bag;
    while (fread(&bag, sizeof(Baggage), 1, file) == 1) {
        if (bag.count > best->count ||
            (bag.count == best->count && bag.weight < best->weight)) {
            *best = bag;
        }
    }

    bool success = !ferror(file);
    fclose(file);
    return success;
}

int main(void) {
    const char* passengers_filename = "passengers.bin";
    const char* baggage_filename = "baggage.bin";

    if (!write_passenger_files(passengers_filename, baggage_filename)) {
        printf("Failed to write passenger files.\n");
        return 1;
    }

    Baggage best;
    if (!find_best_baggage(baggage_filename, &best)) {
        printf("Failed to find passenger.\n");
        return 1;
    }

    FILE* file = fopen(passengers_filename, "rb");
    if (file == NULL) {
        printf("Failed to open passenger file.\n");
        return 1;
    }

    Passenger passenger;
    if (!read_passenger(file, best.passenger_id, &passenger)) {
        printf("Failed to read passenger.\n");
        fclose(file);
        return 1;
    }
    fclose(file);

    printf("Passenger ID: %d\n", best.passenger_id);
    printf("Surname: %s\n", passenger.surname);
    printf("Number of items: %d\n", best.count);
    printf("Total weight: %g kg\n", best.weight);

    return 0;
}