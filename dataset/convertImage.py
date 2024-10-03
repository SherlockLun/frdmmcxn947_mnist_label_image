import cv2
import numpy as np

# Load the stopwatch image
img = cv2.imread('1.bmp')

# Resize the image to 128x128
img = cv2.resize(img, (32, 32))

# Convert the image from BGR to RGB
img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

# Save the final image as 'processed.bmp' in RGB format
cv2.imwrite('processed.bmp', img)

image_data_len = img.size

# Open the output file 'image_data.h' for writing
with open('image_data.h', 'w') as fout:
    # Write image data in a formatted way (with commas and spaces)
    img.tofile(fout, ', ', '0x%02X')
    #print('};\n', file=fout)

# Open the extra file 'rawData' for writing unformatted hex data
with open('rawData.txt', 'w') as raw_out:
    # Flatten the image array and format it as a continuous hex string
    hex_data = ''.join(format(byte, '02X') for byte in img.flatten())
    raw_out.write(hex_data)

print(f"Image size: {image_data_len}")

