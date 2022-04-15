/* 
Christopher Hunt
CS 260

Building a Template
*/

template <class myType>
myType getMax(myType a, myType b){
    return (a>b?a:b); // if "myType" is not comparable this breaks.
}

// Something called "Comparable" helps with that
// Also, something called "interface"


template <class O>
struct node{
    O value;
    node *next;
};




