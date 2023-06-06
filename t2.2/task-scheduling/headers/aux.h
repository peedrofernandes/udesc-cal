#ifndef AUX_H
#define AUX_H

void throwError(char* errorMessage);

int stringIsNumber(char* str);

int* getTimeFromString(char* str);

int getMilliseconds(int hours, int minutes);

#endif