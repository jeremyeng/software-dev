#ifndef STRING_H
#define STRING_H

#include "object.h"
#include <cstring>

class String : public Object
{
public:
    char *my_value;
    size_t my_size;

    /**
     * @brief construct a string with the given value
     * @param value the value to give the new string
     */
    String(const char *value)
    {
        my_size = strlen(value);
        my_value = new char[my_size];
        for (int i = 0; i < my_size; i++)
        {
            my_value[i] = value[i];
        }
    }

    /**
     * @brief the default constructor
     * @note a string that is not given a value is empty with size 0
     */
    String()
    {
        my_value = new char[1];
        my_value[0] = 0;
        my_size = 0;
    }

    /**
     * @brief the default destructor
     */
    ~String()
    {
        delete my_value;
    }

    /**
     * @brief create the concatination of this string and the given string
     * @param n the new string 
     * @return a new string that is the concatination of this string and the given string
     */
    String *concat(String *n)
    {
        // join up the two strings and add a null terminator
        char newValue[this->my_size + n->my_size + 1];
        for (int i = 0; i < this->my_size; i++)
        {
            newValue[i] = this->my_value[i];
        }
        for (int i = 0; i < n->my_size; i++)
        {
            newValue[i + this->my_size] = n->my_value[i];
        }
        newValue[this->my_size + n->my_size] = 0;

        return new String(newValue);
    }

    /**
     * @brief is the given object equal to this string
     * @param other the object to compare to this string
     * @return true if the objects are equal, false otherwise
     */
    virtual bool equals(Object *other) override
    {
        if (other == this)
        {
            return true;
        }
        String *sOther = dynamic_cast<String *>(other);
        if (other == nullptr)
        {
            return false;
        }
        return(strcmp(sOther->my_value, this->my_value) == 0);
    }

    /**
     * @brief get the hash code for this string
     * @note this is an implementation of the polynomial rolling hash function
     */
    virtual size_t hash()
    {
        const int a = 69;
        const int n = 0xffffffff;
        size_t hash_value = 0;
        size_t exponent = 1;
        for (int i = 0; i < this->my_size; i++)
        {
            hash_value = (hash_value + (this->my_value[i] - 'a' + 1) * exponent) % n;
            exponent = (exponent * a) % n;
        }
        return hash_value;
    }
};

#endif //CS4500_STRING_H
