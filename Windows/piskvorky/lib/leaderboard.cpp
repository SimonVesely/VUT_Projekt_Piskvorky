#include "../include/cJSON.h" // knihovna pro naèítání/zapisování souborù typu JSON
#include "../include/mylib.h" // knihovna s custom scripty, které by se opakovali v èástech kódu
#include <stdio.h>  // knihovna pro naèítání vstupù a výstupù
#include <stdlib.h> // knihovna pro systémové pøíkazy
#include <string.h>
#include <windows.h> // knihovna pro èas(sleep)

cJSON* load_json() {
    FILE* data = fopen("../Data/Leaderboard.json", "r");
    if (data == NULL) {
        printf("Error pøi otevírání souboru\n");
        return NULL;
    }

    fseek(data, 0, SEEK_END);
    long fileSize = ftell(data);
    fseek(data, 0, SEEK_SET);

    char* buffer = (char*)malloc(fileSize + 1);
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        fclose(data);
        return NULL;
    }

    fread(buffer, 1, fileSize, data);
    fclose(data);
    buffer[fileSize] = '\0';

    cJSON* json = cJSON_Parse(buffer);
    free(buffer);

    if (json == NULL) {
        const char* error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            printf("Error pøi parsování JSON at position: %ld\n", error_ptr - buffer);
        }
        else {
            printf("Unknown JSON parsing error occurred.\n");
        }
    }

    return json;
}

int compare_scores(const void* a, const void* b) {
    cJSON* itemA = *(cJSON**)a;
    cJSON* itemB = *(cJSON**)b;

    cJSON* scoreA = cJSON_GetObjectItem(itemA, "score");
    cJSON* scoreB = cJSON_GetObjectItem(itemB, "score");

    return cJSON_IsNumber(scoreB) && cJSON_IsNumber(scoreA)
        ? (scoreB->valueint - scoreA->valueint)
        : 0;
}

void reader_lb() {
    clearScreen();
    ascii();
    printf("SKÓRE:\n\n");

    cJSON* json = load_json();
    if (json == NULL) {
        return;
    }

    int array_size = cJSON_GetArraySize(json);
    cJSON** items = (cJSON**)malloc(array_size * sizeof(cJSON*));
    if (items == NULL) {
        printf("Memory allocation failed\n");
        cJSON_Delete(json);
        return;
    }

    for (int i = 0; i < array_size; i++) {
        items[i] = cJSON_GetArrayItem(json, i);
    }

    qsort(items, array_size, sizeof(cJSON*), compare_scores);

    for (int i = 0; i < array_size; i++) {
        cJSON* name = cJSON_GetObjectItem(items[i], "name");
        cJSON* score = cJSON_GetObjectItem(items[i], "score");

        if (cJSON_IsString(name) && cJSON_IsNumber(score)) {
            printf("%d. %s - %d\n", i + 1, name->valuestring, score->valueint);
        }
    }

    free(items);
    cJSON_Delete(json);
    Sleep(5000);
}
int checker_lb(char jmeno[256]) {
    cJSON* json = load_json();
    if (json == NULL) {
        return 2;
    }

    int array_size = cJSON_GetArraySize(json);
    int found = 0;

    for (int i = 0; i < array_size; i++) {
        cJSON* item = cJSON_GetArrayItem(json, i);
        cJSON* name = cJSON_GetObjectItem(item, "name");
        if (cJSON_IsString(name) && strcmp(name->valuestring, jmeno) == 0) {
            found = 1;
            break;
        }
    }

    cJSON_Delete(json);
    return found;
}
// Function to write updated JSON to file
void save_json(cJSON* json) {
    char* json_string = cJSON_Print(json); // Convert JSON to string
    if (json_string == NULL) {
        printf("Error pøi konverzi JSON do stringu\n");
        return;
    }

    FILE* file = fopen("../Data/Leaderboard.json", "w");
    if (file == NULL) {
        printf("Error pøi otevírání souboru pro zápis\n");
        free(json_string);
        return;
    }

    fprintf(file, "%s", json_string);
    fclose(file);
    free(json_string);
}
void writer_lb(char* name) {
    // Load existing JSON data
    cJSON* json = load_json();
    if (json == NULL) {
        json = cJSON_CreateArray(); // Create an empty array if file doesn't exist
    }

    // Create new JSON object for the player
    cJSON* new_entry = cJSON_CreateObject();
    if (new_entry == NULL) {
        printf("Error pøi vytváøení nového objektu JSON\n");
        cJSON_Delete(json);
        return;
    }

    cJSON_AddStringToObject(new_entry, "name", name);
    cJSON_AddNumberToObject(new_entry, "score", 1);

    // Add new entry to the JSON array
    cJSON_AddItemToArray(json, new_entry);

    // Save updated JSON to file
    save_json(json);

    // Clean up
    cJSON_Delete(json);
    return;
}

void overwriter_lb(char* name) {
    // Load existing JSON data
    cJSON* json = load_json();
    if (json == NULL) {
        json = cJSON_CreateArray(); // Create an empty array if file doesn't exist
    }

    // Search for the name in the JSON array
    int array_size = cJSON_GetArraySize(json);

    for (int i = 0; i < array_size; i++) {
        cJSON* item = cJSON_GetArrayItem(json, i);
        cJSON* name_item = cJSON_GetObjectItem(item, "name");
        cJSON* score_item = cJSON_GetObjectItem(item, "score");

        if (cJSON_IsString(name_item) &&
            strcmp(name_item->valuestring, name) == 0) {
            // Name found, increment the score
            if (cJSON_IsNumber(score_item)) {
                cJSON_SetNumberValue(score_item, score_item->valueint + 1);
                break;
            }
        }
    }
    save_json(json);
    cJSON_Delete(json);
    return;
}
