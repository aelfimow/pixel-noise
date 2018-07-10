#ifdef RNG_RAND_H
#error Already included
#else
#define RNG_RAND_H

class RNG_rand : public RNG
{
    public:
        RNG_rand();
        ~RNG_rand();

        int x() const override;
        int y() const override;

        uint8_t red() const override;
        uint8_t green() const override;
        uint8_t blue() const override;

    private:
        int m_min_x;
        int m_max_x;
        int m_min_y;
        int m_max_y;
};

#endif
