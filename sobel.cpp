#include <img_lib.h>
#include <ppm_image.h>

#include <cmath>
#include <string_view>
#include <algorithm>
#include <iostream>


using namespace std;

int Sum(img_lib::Color c) {
    return to_integer<int>(c.r) + to_integer<int>(c.g) + to_integer<int>(c.b);
}

img_lib::Image Sobel(const img_lib::Image& image) {
    img_lib::Image result(image.GetWidth(), image.GetHeight(), img_lib::Color::Black());


    for (int y = 1; y + 1 < image.GetHeight(); ++y) {

        const img_lib::Color* source_line = image.GetLine(y);
        img_lib::Color* destination_line = result.GetLine(y);

        for (int x = 1; x + 1 < image.GetWidth(); ++x) {

        const auto top_line = image.GetLine(y - 1);
        const auto bottom_line = image.GetLine(y + 1);
                // gx = −tl − 2tc − tr + bl + 2bc + br
                int gx = -Sum(top_line[x - 1]) - 2 * Sum(top_line[x]) - Sum(top_line[x + 1]) + Sum(bottom_line[x - 1]) + 2 * Sum(bottom_line[x]) + Sum(bottom_line[x + 1]);
                
                // gy = −tl − 2cl − bl + tr + 2cr + br
                int gy = -Sum(top_line[x - 1]) - 2 * Sum(source_line[x - 1]) - Sum(bottom_line[x - 1]) + Sum(top_line[x + 1]) + 2 * Sum(source_line[x + 1]) + Sum(bottom_line[x + 1]);
                double color = sqrt(gx * gx + gy * gy);

                std::byte component = static_cast<std::byte>(std::clamp<double>(color, 0, 255));

                destination_line[x].r = component;
                destination_line[x].g = component;
                destination_line[x].b = component;
        }
    }
    return result;
}

int main(int argc, const char **argv)
{
    if (argc != 3)
    {
        cerr << "Usage: "sv << argv[0] << " <input image> <output image>"sv << endl;
        return 1;
    }

    auto image = img_lib::LoadPPM(argv[1]);
    if (!image)
    {
        cerr << "Error loading image"sv << endl;
        return 2;
    }

    img_lib::Image result_img = Sobel(image);

    if (!img_lib::SavePPM(argv[2], result_img))
    {
        cerr << "Error saving image"sv << endl;
        return 3;
    }

    cout << "Image saved successfully!"sv << endl;
}