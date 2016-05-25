/*
 * This file is part of clr-boot-manager.
 *
 * Copyright (C) 2016 Intel Corporation
 *
 * clr-boot-manager is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2.1
 * of the License, or (at your option) any later version.
 */

#pragma once

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <search.h>
#include <stdbool.h>
#include <stdint.h>

/**
 * A dynamic array
 * Represents daemon's reply to client
 */
typedef struct CBMArray {
        void **data;  /**<Dynamic array contents */
        uint16_t len; /**<Length of the array */
} CBMArray;

/**
 * Valid function prototype for 'free' method
 * @param p Pointer to free
 */
typedef void (*array_free_func)(void *p);

/**
 * Create a new CBMArray
 * @returns CBMArray a newly allocated CBMArray
 */
CBMArray *cbm_array_new(void) __attribute__((warn_unused_result));

/**
 * Append data to CBMArray
 * @param array Valid CBMArray
 * @param data Pointer to add to this array
 * @returns bool true if the data was added to the array
 */
bool cbm_array_add(CBMArray *array, void *data) __attribute__((warn_unused_result));

/**
 * Free an array, and optionally its members
 * @param array valid CBMArray reference
 * @param free_func Function to call to free all members, or NULL to leave allocated
 */
void cbm_array_free(CBMArray **array, array_free_func free_method);

/**
 * Retrieve an element from the array by index
 * @param array valid CBMArray reference
 * @param index index of the element in the array
 * @return a data pointer refered to by index, or NULL
 */
void *cbm_array_get(CBMArray *array, uint16_t index) __attribute__((warn_unused_result));

/**
 * Sort the internal array using the qsort() function
 *
 * @param array valid CBMArray reference
 * @param cmp a comparison_fn_t pointer
 */
void cbm_array_qsort(CBMArray *array, __compar_fn_t cmp);

/*
 * Editor modelines  -  https://www.wireshark.org/tools/modelines.html
 *
 * Local variables:
 * c-basic-offset: 8
 * tab-width: 8
 * indent-tabs-mode: nil
 * End:
 *
 * vi: set shiftwidth=8 tabstop=8 expandtab:
 * :indentSize=8:tabSize=8:noTabs=true:
 */
