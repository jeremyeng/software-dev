#include "array.h"
#include "string-array.h"
#include <assert.h>

void testArray()
{
    Object o1;
    Object o2;
    Object o3;

    Array array;

    if (array.pushBack(&o1) == 1)
    {
        assert(array.size() == 1);
        assert(array.valueAt(0) == &o1);
    }

    array.pushBack(&o1);
    array.pushBack(&o2);
    array.pushBack(&o3);

    assert(array.size() == 3);
    assert(array.valueAt(0) == &o1);
    assert(array.valueAt(1) == &o2);
    assert(array.valueAt(2) == &o3);

    array.popBack();

    assert(array.size() == 2);
    assert(array.valueAt(0) == &o1);
    assert(array.valueAt(1) == &o2);

    array.pushBack(&o3);

    array.insert(&o1, 1);

    assert(array.size() == 4);
    assert(array.valueAt(0) == &o1);
    assert(array.valueAt(1) == &o1);
    assert(array.valueAt(2) == &o2);
    assert(array.valueAt(3) == &o3);

    array.emplace(&o2, 1);

    assert(array.size() == 4);
    assert(array.valueAt(0) == &o1);
    assert(array.valueAt(1) == &o2);
    assert(array.valueAt(2) == &o2);
    assert(array.valueAt(3) == &o3);

    array.popBack();

    assert(array.size() == 3);
    assert(array.valueAt(0) == &o1);
    assert(array.valueAt(1) == &o2);
    assert(array.valueAt(2) == &o2);

    assert(array.indexOf(&o2) == 1);

    array.emplace(&o3, 1);

    assert(array.size() == 3);
    assert(array.valueAt(0) == &o1);
    assert(array.valueAt(1) == &o3);
    assert(array.valueAt(2) == &o2);

    assert(array.indexOf(&o2) == 2);

    array.erase();

    assert(array.size() == 0);
}

void testStringArray()
{
    String s1;
    String s2;
    String s3;

    StringArray stringArray;

    if (stringArray.pushBack(&s1) == 1)
    {
        assert(stringArray.size() == 1);
        assert(stringArray.valueAt(0) == &s1);
    }

    stringArray.pushBack(&s1);
    stringArray.pushBack(&s2);
    stringArray.pushBack(&s3);

    assert(stringArray.size() == 3);
    assert(stringArray.valueAt(0) == &s1);
    assert(stringArray.valueAt(1) == &s2);
    assert(stringArray.valueAt(2) == &s3);

    stringArray.popBack();

    assert(stringArray.size() == 2);
    assert(stringArray.valueAt(0) == &s1);
    assert(stringArray.valueAt(1) == &s2);

    stringArray.pushBack(&s3);

    stringArray.insert(&s1, 1);

    assert(stringArray.size() == 4);
    assert(stringArray.valueAt(0) == &s1);
    assert(stringArray.valueAt(1) == &s1);
    assert(stringArray.valueAt(2) == &s2);
    assert(stringArray.valueAt(3) == &s3);

    stringArray.emplace(&s2, 1);

    assert(stringArray.size() == 4);
    assert(stringArray.valueAt(0) == &s1);
    assert(stringArray.valueAt(1) == &s2);
    assert(stringArray.valueAt(2) == &s2);
    assert(stringArray.valueAt(3) == &s3);

    stringArray.popBack();

    assert(stringArray.size() == 3);
    assert(stringArray.valueAt(0) == &s1);
    assert(stringArray.valueAt(1) == &s2);
    assert(stringArray.valueAt(2) == &s2);

    assert(stringArray.indexOf(&s2) == 1);

    stringArray.emplace(&s3, 1);

    assert(stringArray.size() == 3);
    assert(stringArray.valueAt(0) == &s1);
    assert(stringArray.valueAt(1) == &s3);
    assert(stringArray.valueAt(2) == &s2);

    assert(stringArray.indexOf(&s2) == 2);

    stringArray.erase();

    assert(stringArray.size() == 0);
}

int main(int argc, char **argv)
{
    testArray();
    testStringArray();
}