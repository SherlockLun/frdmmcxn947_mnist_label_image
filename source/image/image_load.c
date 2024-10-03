/*
 * Copyright 2021-2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "demo_config.h"
#include "fsl_debug_console.h"
#include "image.h"
#include "image_utils.h"
#include "image_data.h"

int s_staticCount = 0;
const char* s_imageName = STATIC_IMAGE_NAME;

status_t IMAGE_GetImage(uint8_t* dstData, int32_t dstWidth, int32_t dstHeight, int32_t dstChannels)
{
    s_staticCount++;

    // Array of static image data references
    static const void *image_data_array[] = {image_data_empty, image_data_1, image_data_31, image_data_4,
    		image_data_5, image_data_7, image_data_81, image_data_9};


    if (s_staticCount >= 1 && s_staticCount <= 8)
    {
        PRINTF(EOL "Static data processing:" EOL);
        return IMAGE_Decode(image_data_array[s_staticCount -1], dstData, dstWidth, dstHeight, dstChannels);
    }
    else
    {
        PRINTF(EOL "Camera data processing:" EOL);
        PRINTF("Camera input is currently not supported on this device" EOL);
        for (;;)
            ;
    }
    return kStatus_Success;
}

const char* IMAGE_GetImageName()
{
    return s_imageName;
}
