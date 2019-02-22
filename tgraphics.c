#include "tgraphics.h"

static void _draw_vertical_line(char symbol, int length, int begin_y, int x_position);
static void _draw_horizontal_line(char symbol, int length, int begin_x, int y_position);
static void _tset_color(int foreground_color, int background_color);

void draw_rectangle(const struct tgraphics* config, char symbol, int width, int height) {
    _tset_color(config->foreground_color, config->background_color);

    _draw_horizontal_line(symbol, width, config->x_position, config->y_position);
    _draw_horizontal_line(symbol, width, config->x_position, config->y_position + height - 1);
    _draw_vertical_line(symbol, height, config->y_position, config->x_position);
    _draw_vertical_line(symbol, height, config->y_position, config->x_position + width - 1);

    _tset_color(FGCL_RESET, BGCL_RESET);
}

void draw_circle(const struct tgraphics* config, char symbol, int radius){

}

static void _tset_color(int foreground_color, int background_color) {
    set_color(foreground_color);
    set_color(background_color);
}

static void _draw_vertical_line(char symbol, int length, int begin_y, int x_position) {
    for(int y_offset = begin_y; y_offset < begin_y + length; y_offset++) {
        set_cursor(x_position, y_offset);
        printf("%c", symbol);
    }
}

static void _draw_horizontal_line(char symbol, int length, int begin_x, int y_position) {
    for(int x_offset = begin_x; x_offset < begin_x + length; x_offset++) {
        set_cursor(x_offset, y_position);
        printf("%c", symbol);
    }
}
