#ifdef RNG_XORSHIFT_H
#error Already included
#else
#define RNG_XORSHIFT_H

class RNG_xorshift : public RNG
{
    public:
        RNG_xorshift();
        ~RNG_xorshift();

        void calc() override;

        void limit_x(int min, int max) override;
        void limit_y(int min, int max) override;

        int x() const override;
        int y() const override;

        int red() const override;
        int green() const override;
        int blue() const override;

    private:
        size_t m_state;
        int m_min_x;
        int m_max_x;
        int m_min_y;
        int m_max_y;
        int m_x;
        int m_y;
        int m_red;
        int m_green;
        int m_blue;

    private:
        bool is_range_valid(int min, int max) const;
        size_t xorshift(size_t value) const;
};

#endif
