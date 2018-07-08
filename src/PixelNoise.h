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
        static void Set(int x, int y);
        static void Draw(HWND hwnd);
        static void Destroy();

    private:
        PixelNoise();
        static PixelNoise *Inst;

        int m_WindowX;
        int m_WindowY;

    public:
        PixelNoise(const PixelNoise &instance) = delete;
        PixelNoise(const PixelNoise &&instance) = delete;
        PixelNoise &operator=(const PixelNoise &instance) = delete;
        PixelNoise &operator=(const PixelNoise &&instance) = delete;
};

#endif
