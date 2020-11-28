#include "mylibs.h"
#include "mysockets.h"

void cels_to_fahr(TEMP_D *data) {
  data->temp = ((data->temp) * 9 / 5) + 32;
}

void fahr_to_cels(TEMP_D *data) {
  data->temp = ((data->temp) - 32) * 5 / 9;
}

