#include <fstream>
#include <iostream>

#include "../../Atividade01/at01_myClass_Image.cc"
#include "../../Atividade02/src/at02_vec3.hpp"
#include "at04_color.h"
#include "at04_ray.h"

bool hit_sphere(const point3& center, double radius, const ray& r) {
    vec3 oc = r.origin() - center;
    auto a = dot(r.direction(), r.direction());
    auto b = 2.0 * dot(oc, r.direction());
    auto c = dot(oc, oc) - radius * radius;
    auto discriminant = b * b - 4 * a * c;
    return (discriminant >= 0);
}

color ray_color(const ray& r) {
    if (hit_sphere(point3(0, 0, -1), 0.5, r))
        return color(1, 0, 0);

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

bool hit_triangle(const point3& vertex0, const point3& vertex1, const point3& vertex2, const ray& r) {
    vec3 e1 = vertex1 - vertex0;
    vec3 e2 = vertex2 - vertex0;
    vec3 h = cross(r.direction(), e2);
    double a = dot(e1, h);

    if (a > -1e-6 && a < 1e-6)
        return false;

    double f = 1.0 / a;
    vec3 s = r.origin() - vertex0;
    double u = f * dot(s, h);

    if (u < 0.0 || u > 1.0)
        return false;

    vec3 q = cross(s, e1);
    double v = f * dot(r.direction(), q);

    if (v < 0.0 || u + v > 1.0)
        return false;

    double t = f * dot(e2, q);

    return (t > 0.0001);
}

color ray_color_triangle(const ray& r) {
    point3 v0(-0.5, -0.5, -1.0);
    point3 v1(0.5, -0.5, -1.0);
    point3 v2(0, 0.5, -1.0);

    if (hit_triangle(v0, v1, v2, r)) {
        return color(1, 0, 0);
    }

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

int main() {
    // Image
    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    // Calculate the image height, and ensure that it's at least 1.
    int image_height = static_cast<int>(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    myClass_Image myImage = myClass_Image(image_height, image_width);

    // Camera
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (static_cast<double>(image_width) / image_height);
    auto camera_center = point3(0, 0, 0);

    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    // Calculate the location of the upper left pixel.
    auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    // Generates sphere image:
    std::ofstream arquivo("sphere.ppm");

    arquivo << "P3\n"
            << image_width << " " << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r);
            write_color(arquivo, pixel_color);
        }
    }

    arquivo.close();
    myImage.Ppm2Png("sphere.ppm");

    // Generate triangle image:
    std::ofstream arquivo2("triangle.ppm");
    arquivo2 << "P3\n"
             << image_width << " " << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color_triangle(r);
            write_color(arquivo2, pixel_color);
        }
    }

    arquivo2.close();
    myImage.Ppm2Png("triangle.ppm");
}
