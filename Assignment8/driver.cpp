/* Christopher Hunt
 * CS260
 * driver.py
 */

#include "edge.h"

int main(){
    Edge edge1(nullptr, nullptr, 1);

    std::cout << "edge1.m_src: " << edge1.m_src << std::endl;
    std::cout << "edge1.m_dst: " << edge1.m_dst << std::endl;
    std::cout << "edge1.m_weight: " << edge1.m_weight << std::endl;

    return 0;
}
