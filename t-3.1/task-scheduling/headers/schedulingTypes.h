#ifndef SCHEDULING_TYPES_H
#define SCHEDULING_TYPES_H

typedef struct train {
  int id;
  int arriveTimeMilliseconds;
  int departTimeMilliseconds;
  int nPlatform;
} Train;

#endif