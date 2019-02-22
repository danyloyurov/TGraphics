#ifndef TRAPHICS_HPP_
#define TRAPHICS_HPP_

#include "esc_defines.h"

struct tgraphics {
    int x_position;
    int y_position;
    int foreground_color;
    int background_color;
};

void draw_rectangle(const struct tgraphics* config, char symbol, int width, int height);
void draw_circle(const struct tgraphics* config, char symbol, int radius);

#endif // TRAPHICS_HPP_
