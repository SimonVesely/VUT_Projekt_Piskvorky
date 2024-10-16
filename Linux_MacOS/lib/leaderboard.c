#include <cjson/cJSON.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/mylib.h"

void reader_lb() {
  clearScreen();
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
      printf("Jméno: %s, skóre: %d\n", name->valuestring, score->valueint);
    }
  }

  sleep(5);

  cJSON_Delete(json);
  return;
}
