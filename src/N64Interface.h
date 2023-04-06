#ifndef N64Interface_h
#define N64Interface_h

#include <Arduino.h>

class N64Interface {
public:
    virtual void init();
    virtual void send(unsigned char * buffer, char length);
    virtual void get();

    char raw_dump[33];

protected:
    N64Interface(gpio_num_t pincode) : pincode(pincode) {};
    gpio_num_t pincode;
};

class N64Interface_PINB : public N64Interface {
public:
    N64Interface_PINB(gpio_num_t pincode) : N64Interface(pincode) {};
    virtual void init();
    virtual void send(unsigned char * buffer, char length);
    virtual void get();
};

class N64Interface_PIND : public N64Interface {
public:
    N64Interface_PIND(gpio_num_t pincode) : N64Interface(pincode) {};
    virtual void init();
    virtual void send(unsigned char * buffer, char length);
    virtual void get();
};

#endif
