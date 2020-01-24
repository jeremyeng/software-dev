#include "object.h"

/**
 * @brief a variable size list of objects
 */ 
class Array
{
public:

    /**
     * @brief the default constructor, constructs an empty array
     */     
    Array()
    {

    }

    /**
     * @brief delete this array
     */ 
    ~Array()
    {

    }

    /**
     * @brief add the given object to this array
     * @param o the object to add
     * @return 1 if successful and 0 if unsuccessful
     */
    virtual int pushBack(Object *o);

    /**
     * @brief remove the last object from this array=
     * @return 1 if successful and 0 if unsuccessful
     */
    virtual int popBack();

    /**
     * @brief insert the given object at the given index, moving all other objects back
     * @note insert must happen at an index that already exists
     * @param o the object to add
     * @param i the index to add the object at
     * @return 1 if successful and 0 is unsuccessful
     */
    virtual int insert(Object *o, size_t i);

    /**
     * @brief set the array's value at the given index to be the given object
     * replacing any object already at that index
     * @param o the object to add
     * @param i the index to add the object at
     * @return 1 if successfull and 0 if unsuccesssful
     */
    virtual int emplace(Object *o, size_t i);

    /**
     * @brief remove the object at the given index
     * @param i the index of the object to remove
     * @return 1 if successfull and 0 if unsuccesssful
     */
    virtual int remove(size_t i);

    /**
     * @brief get the index of the given object
     * @param o the object to look for
     * @return the index of the object if it is in the array
     * or 0 if it is not in the array
     */
    virtual int indexOf(Object *o);

    /**
     * @brief get the object at the given index
     * @param i the index of the object to find
     * @return the object if it is found, or nullptr if it is not
     * @note if the same object is on the list multiple times, its first index
     * will be returned
     */
    virtual Object *valueAt(size_t i);

    /**
     * @brief get the size of this array
     * @return the size of this array
     */
    virtual size_t size();

    /**
     * @brief erase the contents of this array
     * @return 1 if successful and 0 if unsuccessful
     */
    virtual int erase();
};