#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct ContactStatus {
    int32_t age;
    bool isConfirmed;
    struct ContactStatus *prev;
    struct ContactStatus *next;
} s_ContactStatus;

s_ContactStatus* removeFromRing(int32_t target, s_ContactStatus* Header);
