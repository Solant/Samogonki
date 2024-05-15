#include "aspect_ratio.h"

AspectRatioInfo createAspectRatio(int sc_width, int sc_height) {
    int width = 480 / sc_height * sc_width;

    return AspectRatioInfo {
        .width = width,
        .offset = width - 640,
    };
}

AspectRatioInfo aspectRatios[] = {
    createAspectRatio(4, 3),
    createAspectRatio(16, 9),
    createAspectRatio(16, 10),
    createAspectRatio(21, 9),
};

AspectRatioInfo *AR_CURRENT = &aspectRatios[0];

void changeAspectRatio(int width, int height) {
    if (((float)4 / 3) == ((float) width / height)) {
        AR_CURRENT = &aspectRatios[AR_4x3];
    }

    if (((float)16 / 9) == ((float) width / height)) {
        AR_CURRENT = &aspectRatios[AR_16x9];
    }

    if (((float)16 / 10) == ((float) width / height)) {
        AR_CURRENT = &aspectRatios[AR_16x10];
    }

    if (((float)21 / 9) == ((float) width / height)) {
        AR_CURRENT = &aspectRatios[AR_21x9];
    }
}