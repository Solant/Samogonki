#ifndef __ASPECT_RATIO_H__
#define __ASPECT_RATIO_H__

enum AspectRatio {
	AR_4x3 = 0,
	AR_16x9 = 1,
	AR_16x10 = 2,
	AR_21x9 = 3,
};

struct AspectRatioInfo {
    // virtual width for interface render
	int width;
    // offset for right-aligned elements
    int offset;
	// camera offset
	int cameraOffset;
};

extern AspectRatioInfo *AR_CURRENT;

void changeAspectRatio(int width, int height);

void applyScreenRatioOffset(mchArcaneScreenElement *el, const char *name);

#endif // __ASPECT_RATIO_H__