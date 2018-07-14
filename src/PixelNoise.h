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
        static void Start();
        static void Stop();
        static void SetLimit(int max_x, int max_y);
        static void Draw(HWND hwnd);
        static void Destroy();

        static void RNG_rand();
        static void RNG_xorshift();

    private:
        PixelNoise();
        static PixelNoise *Inst;

        RNG *m_RNG;

        bool m_is_started;

        int m_max_x;
        int m_max_y;

    public:
        PixelNoise(const PixelNoise &instance) = delete;
        PixelNoise(const PixelNoise &&instance) = delete;
        PixelNoise &operator=(const PixelNoise &instance) = delete;
        PixelNoise &operator=(const PixelNoise &&instance) = delete;
};

#endif
