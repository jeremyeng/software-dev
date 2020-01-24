//lang::CwC
#ifndef OBJECT_H
#define OBJECT_H
#include <cstdlib>

/**
* @brief a class to represent generic objects, like the object
* class in java from which all classes inherit
*/
class Object
{
  public:

  /**
  * @brief check if the given object is equal to this object
  * @param other the object to check equality with
  */
  virtual bool equals(Object * other)
  {
    // just compare the pointers
    return other == this;
  }

  /**
   * @brief get the hash code for this object
   */ 
  virtual size_t hash()
  {
    // every object's pointer will be unique, so this is an excellent
    // thing to use for the default hash value
    return reinterpret_cast<size_t>(this);
  }

};

#endif
