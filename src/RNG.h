#ifdef RNG_H
#error Already included
#else
#define RNG_H

class RNG
{
    public:
        RNG() { }
        virtual ~RNG() { }

        virtual int x() const = 0;
        virtual int y() const = 0;

        virtual uint8_t red() const = 0;
        virtual uint8_t green() const = 0;
        virtual uint8_t blue() const = 0;
};

#endif
