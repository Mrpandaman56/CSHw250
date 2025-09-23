/*
 *  Rayden Powell HistoGram Program Homework 1
 *
 */
#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdint>
#include <cstdlib>
#include <ctime>

using namespace std;

uint32_t generate_random_color() {
    uint32_t r = rand() % 256;
    uint32_t g = rand() % 256;
    uint32_t b = rand() % 256;
    return (r << 16) | (g << 8) | b;
}

inline uint8_t get_red(uint32_t color)   { return (color >> 16) & 0xFF; }
inline uint8_t get_green(uint32_t color) { return (color >> 8) & 0xFF; }
inline uint8_t get_blue(uint32_t color)  { return color & 0xFF; }

vector<int> build_histogram(const vector<vector<uint32_t>> &image_data,
                            char channel) {
    vector<int> histogram(256, 0);
    for (const auto &row : image_data) {
        for (uint32_t color : row) {
            uint8_t value = 0;
            if (channel == 'R') value = get_red(color);
            else if (channel == 'G') value = get_green(color);
            else if (channel == 'B') value = get_blue(color);
            histogram[value]++;
        }
    }
    return histogram;
}

void display_histogram(const vector<int> &hist, const string &title) {
    cout << "--- " << title << " Histogram ---\n";
    for (int i = 0; i < 256; i++) {
        if (hist[i] > 0) {
            cout << setw(3) << i << ": ";
            for (int j = 0; j < hist[i]; j++) cout << "##########";
            cout << " (" << hist[i] << ")\n";
        } else {
            cout << setw(3) << i << ": (0)\n";
        }
    }
    cout << "\n";
}

int main() {
    const int ROWS = 10;
    const int COLS = 10;

    vector<vector<uint32_t>> image_data(ROWS, vector<uint32_t>(COLS));

    srand(time(0));

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            image_data[r][c] = generate_random_color();
        }
    }

    vector<int> red_hist   = build_histogram(image_data, 'R');
    vector<int> green_hist = build_histogram(image_data, 'G');
    vector<int> blue_hist  = build_histogram(image_data, 'B');

    display_histogram(red_hist, "Red Channel");
    display_histogram(green_hist, "Green Channel");
    display_histogram(blue_hist, "Blue Channel");

    return 0;
}