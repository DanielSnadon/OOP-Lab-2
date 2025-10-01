#ifndef THREE_H
#define THREE_H

#include <initializer_list>
#include <string>

class Three {
    
    public:
        Three();
        Three(const size_t &n, unsigned char t = 0);
        Three(const std::initializer_list<unsigned char> &t);
        Three(const std::string &t);
        Three(const Three& other);
        Three(Three&& other) noexcept;

        Three add(const Three& other);
        Three subtract(const Three& other);

        bool greaterThan(const Three& other) const;
        bool lessThan(const Three& other) const;
        bool equals(const Three& other);

        std::ostream& print(std::ostream& os) const;

        virtual ~Three() noexcept;

    private:
        size_t _size;
        unsigned char *_array;
};

#endif