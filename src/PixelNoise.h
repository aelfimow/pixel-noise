#ifdef PIXEL_NOISE_H
#error Already included
#else
#define PIXEL_NOISE_H

class PixelNoise
{
    public:
        ~PixelNoise();

    public:
        static void Create();
        static void Draw(HWND hwnd);
        static void Destroy();

    public:
        PixelNoise() = delete;
        PixelNoise(const PixelNoise &instance) = delete;
        PixelNoise(const PixelNoise &&instance) = delete;
        PixelNoise &operator=(const PixelNoise &instance) = delete;
        PixelNoise &operator=(const PixelNoise &&instance) = delete;
};

#endif
