#include "string.h"

/**
 * @brief a variable size list of Strings
 */ 
class StringArray
{
public:

    /**
     * @brief the default constructor, constructs an empty array
     */     
    StringArray()
    {

    }

    /**
     * @brief delete this array
     */ 
    ~StringArray()
    {
        
    }

    /**
     * @brief add the given String to this array
     * @param s the String to add
     * @return 1 if successful and 0 if unsuccessful
     */
    virtual int pushBack(String *s);

    /**
     * @brief remove the last String from this array=
     * @return 1 if successful and 0 if unsuccessful
     */
    virtual int popBack();

    /**
     * @brief insert the given String at the given index, moving all other Strings back
     * @param s String to add
     * @param i the index to add the String at
     * @return 1 if successful and 0 is unsuccessful
     */
    virtual int insert(String *s, size_t i);

    /**
     * @brief set the array's value at the given index to be the given String
     * replacing any String already at that index
     * @param s the String to add
     * @param i the index to add the String at
     * @return 1 if successfull and 0 if unsuccesssful
     */
    virtual int emplace(String *s, size_t i);

    /**
     * @brief remove the String at the given index
     * @param i the index of the String to remove
     * @return 1 if successfull and 0 if unsuccesssful
     */
    virtual int remove(size_t i);

    /**
     * @brief get the index of the given String
     * @param s the String to look for
     * @return the index of the String if it is in the array
     * or 0 if it is not in the array
     */
    virtual int indexOf(String *s);

    /**
     * @brief get the String at the given index
     * @param i the index of the String to find
     * @return the String if it is found, or nullptr if it is not
     */
    virtual String *valueAt(size_t i);

    /**
     * @brief get the size of this array
     * @return the number of elements in this array
     */
    virtual size_t size();

    /**
     * @brief erase the contents of this array
     * @return 1 if successful and 0 if unsuccessful
     */
    virtual int erase();
};