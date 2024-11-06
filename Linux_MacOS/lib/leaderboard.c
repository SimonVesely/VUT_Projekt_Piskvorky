#include "../include/cJSON.h" // knihovna pro načítání/zapisování souborů typu JSON
#include "../include/mylib.h" // knihovna s custom scripty, které by se opakovali v částech kódu
#include <stdio.h>  // knihovna pro načítání vstupů a výstupů
#include <stdlib.h> // knihovna pro systémové příkazy
#include <unistd.h> // knihovna pro čas(sleep)
#include <string.h>

cJSON *load_json(const char *file_path) {
  FILE *data = fopen(file_path, "r");
  if (data == NULL) {
    printf("Error při otevírání souboru\n");
    return NULL;
  }

  fseek(data, 0, SEEK_END);
  long fileSize = ftell(data);
  fseek(data, 0, SEEK_SET);

  char *buffer = (char *)malloc(fileSize + 1);
  if (buffer == NULL) {
    printf("Memory allocation failed\n");
    fclose(data);
    return NULL;
  }

  fread(buffer, 1, fileSize, data);
  fclose(data);
  buffer[fileSize] = '\0';

  cJSON *json = cJSON_Parse(buffer);
  free(buffer);

  if (json == NULL) {
    const char *error_ptr = cJSON_GetErrorPtr();
    if (error_ptr != NULL) {
      printf("Error při parsování JSON at position: %ld\n", error_ptr - buffer);
    } else {
      printf("Unknown JSON parsing error occurred.\n");
    }
  }

  return json;
}

int compare_scores(const void *a, const void *b) {
  cJSON *itemA = *(cJSON **)a;
  cJSON *itemB = *(cJSON **)b;

  cJSON *scoreA = cJSON_GetObjectItem(itemA, "score");
  cJSON *scoreB = cJSON_GetObjectItem(itemB, "score");

  return cJSON_IsNumber(scoreB) && cJSON_IsNumber(scoreA)
             ? (scoreB->valueint - scoreA->valueint)
             : 0;
}

void reader_lb() {
    clearScreen();
    ascii();
    printf("SKÓRE:\n\n");

    cJSON *json = load_json("../Data/Leaderboard.json");
    if (json == NULL) {
        return;
    }

    int array_size = cJSON_GetArraySize(json);
    cJSON **items = malloc(array_size * sizeof(cJSON *));
    if (items == NULL) {
        printf("Memory allocation failed\n");
        cJSON_Delete(json);
        return;
    }

    for (int i = 0; i < array_size; i++) {
        items[i] = cJSON_GetArrayItem(json, i);
    }

    qsort(items, array_size, sizeof(cJSON *), compare_scores);

    for (int i = 0; i < array_size; i++) {
        cJSON *name = cJSON_GetObjectItem(items[i], "name");
        cJSON *score = cJSON_GetObjectItem(items[i], "score");

        if (cJSON_IsString(name) && cJSON_IsNumber(score)) {
            printf("%d. %s - %d\n", i + 1, name->valuestring, score->valueint);
        }
    }

    free(items);
    cJSON_Delete(json);
    sleep(5);
}
int checker_lb(char jmeno[256]) {
  cJSON *json = load_json("../Data/Leaderboard.json");
    if (json == NULL) {
        return 2;
    }

    int array_size = cJSON_GetArraySize(json);
    int found = 0;

    for (int i = 0; i < array_size; i++) {
        cJSON *item = cJSON_GetArrayItem(json, i);
        cJSON *name = cJSON_GetObjectItem(item, "name");
        if (cJSON_IsString(name) && strcmp(name->valuestring, jmeno) == 0) {
            found = 1;
            break;
        }
    }

    cJSON_Delete(json);
    return found;}
void writer_lb() { return; }
void overwriter_lb() { return; }
