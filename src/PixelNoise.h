#ifdef PIXEL_NOISE_H
#error Already included
#else
#define PIXEL_NOISE_H

class RNG;

class PixelNoise
{
    public:
        ~PixelNoise();

    public:
        static void Create();
        static void Set(int x, int y);
        static void Draw(HWND hwnd);
        static void Destroy();

    private:
        PixelNoise();
        static PixelNoise *Inst;

        RNG *m_RNG;

    public:
        PixelNoise(const PixelNoise &instance) = delete;
        PixelNoise(const PixelNoise &&instance) = delete;
        PixelNoise &operator=(const PixelNoise &instance) = delete;
        PixelNoise &operator=(const PixelNoise &&instance) = delete;
};

#endif
