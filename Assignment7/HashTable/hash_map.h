/* Christopher Hunt
 * CS260
 * hash_map.h
 */

#include <vector>

class HashMap{
    private:
        std::vector<int> map;
        int capacity;
        int size;

        int hash(int key);


    public:
        HashMap();
        ~HashMap();
        int get_capacity();
        float get_load();
        void add(int new_value);
        void remove(int old_value);
        int search(int candidate_value);
};
