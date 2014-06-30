/* Copyright 2011, 2012 SRI International
 * See LICENSE for other credits and copying information
 */


#ifndef _IMAGES_H
#define _IMAGES_H

#include <stddef.h>

typedef struct image *image_p;

typedef struct image {
  size_t size;             /* size of the cover image           */
  char* path;              /* from whence it came               */
  unsigned char* bytes;    /* the actual image                  */
  int capacity;            /* how much jel reckons it can carry */
} image_t;


typedef struct image_pool *image_pool_p;

typedef struct image_pool {
  image_p *the_images;               /* an array of image_p objects                       */
  int      the_images_length;        /* the capacity (length of) the array                */
  int      the_images_offset;        /* the current empty offset into the array           */
  int      the_images_max_payload;   /* the maximal jel capacity of all the images stored */
} image_pool_t;

void free_image(image_p im);

int extract_message(unsigned char** messagep, unsigned char* jpeg_data, unsigned int jpeg_data_length);

image_pool_p load_images(const char* path);

int free_image_pool(image_pool_p pool);

image_p embed_message(image_pool_p pool, unsigned char* message, int message_length);


#endif
