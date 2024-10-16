#include <cjson/cJSON.h> // knihovna pro načítání/zapisování souborů typu JSON
#include <stdio.h> // knihovna pro načítání vstupů a výstupů
#include <stdlib.h> // knihovna pro systémové příkazy
#include <unistd.h> // knihovna pro čas(sleep)
#include "../include/mylib.h" // knihovna s custom scripty, které by se opakovali v částech kódu

void reader_lb() {

  clearScreen();
  ascii();

  printf("SKÓRE:\n\n");
  FILE *data = fopen("../Data/Leaderboard.json", "r");

  if (data == NULL) {
    printf("Error při otevírání souboru\n");
    return;
  }

  fseek(data, 0, SEEK_END);
  long fileSize = ftell(data);
  fseek(data, 0, SEEK_SET);
  char *buffer = (char *)malloc(fileSize + 1);
  fread(buffer, 1, fileSize, data);
  fclose(data);
  buffer[fileSize] = '\0';

  cJSON *json = cJSON_Parse(buffer);
  free(buffer);
  if (json == NULL) {
    printf("Error při parsování JSON\n");
    return;
  }

  int array_size = cJSON_GetArraySize(json);
  for (int i = 0; i < array_size; i++) {
    cJSON *item = cJSON_GetArrayItem(json, i);

    cJSON *name = cJSON_GetObjectItem(item, "name");
    cJSON *score = cJSON_GetObjectItem(item, "score");

    if (cJSON_IsString(name) && cJSON_IsNumber(score)) {
      printf("%d. %s - %d\n", i + 1, name->valuestring, score->valueint);
    }
  }

  sleep(5);

  cJSON_Delete(json);
  return;
}
