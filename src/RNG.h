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

        virtual int red() const = 0;
        virtual int green() const = 0;
        virtual int blue() const = 0;
};

#endif
