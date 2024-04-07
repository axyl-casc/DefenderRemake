#include "bitmap.h"

const unsigned int spaceship_bitmap[8] = {
    0x0,
    0x1000,
    0x1E00,
    0x3FFF,
    0x3FFF,
    0x1FF0,
    0x0,
    0x0,
};

const unsigned int spaceship_bitmap_alive[8] = {
    0x0,
    0x1000,
    0x1E00,
    0x3FFF,
    0x3FFF,
    0x1FF0,
    0x0,
    0x0,
};

const unsigned int spaceship_bitmap_dead[8] = {
    0x0,
    0x1000,
    0x1C00,
    0x393B,
    0x3377,
    0x660,
    0x0,
    0x0,
};


const unsigned int alien_bitmap[8] = {
    0x7C0,
    0xFE0,
    0x1BB0,
    0x1FF0,
    0xFE0,
    0xFE0,
    0x820,
    0x820,
};

/* Function to reverse bits of a 16-bit unsigned integer */
unsigned int reverseBits(unsigned int num) {
    unsigned int NO_OF_BITS = sizeof(num) * 8;
    unsigned int reverse_num = 0, i, temp;

    for (i = 0; i < NO_OF_BITS; i++) {
        temp = (num & (1 << i));
        if (temp)
            reverse_num |= (1 << ((NO_OF_BITS - 1) - i));
    }

    return reverse_num;
}

/* Function to mirror alien bitmap along the y-axis */
void mirrorBitmap(const unsigned int *bitmap, unsigned int *mirroredBitmap, unsigned int size) {
    int i;
    for (i = 0; i < size; i++) {
        mirroredBitmap[i] = reverseBits(bitmap[i]);
    }
}
