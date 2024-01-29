from PIL import Image
import os

def png_to_hex(file_path):
    image = Image.open(file_path)

    # Convert the image to RGB332 format (8 bits)
    image = image.convert("RGB")

    pixels = list(image.getdata())

    # Convert each RGB pixel value to RGB332 format
    rgb332_values = [(pixel[0] // 32) << 5 | (pixel[1] // 32) << 2 | pixel[2] // 64 for pixel in pixels]

    hex_values = [f"0x{value:02X}" for value in rgb332_values]

    return hex_values

def save_to_txt(file_path, data):
    txt_filename = os.path.splitext(file_path)[0] + "_output.txt"
    with open(txt_filename, "w") as txt_file:
        for i, hex_value in enumerate(data):
            txt_file.write(hex_value)
            if (i + 1) % 16 == 0:
                txt_file.write(",\n")
            else:
                txt_file.write(", ")

if __name__ == "__main__":
    import sys

    if len(sys.argv) != 2:
        print("Usage: python png2hex.py <path_to_png>")
        sys.exit(1)

    input_file = sys.argv[1]
    hex_data = png_to_hex(input_file)

    # Save the hex values to a CSV file
    save_to_txt(input_file, hex_data)

    print(f"Hex values saved to {os.path.splitext(input_file)[0]}_output.csv")
