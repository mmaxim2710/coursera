#include <iostream>
#include <vector>
#include <cstdint>

int main() {
    uint32_t n = 0;
    uint16_t density = 0;

    std::cin >> n >> density;

    std::vector<uint64_t> v_mass;
    
    for (int i = 0; i < n; i++) {
        uint64_t W, H, D = 0;
        std::cin >> W >> H >> D;
        uint64_t mass = density * W * H * D;
        v_mass.push_back(mass);
    }

    uint64_t ans = 0;
    for(const auto& i : v_mass) {
        ans += i;
    }

    std::cout << ans << std::endl;
    return 0;
}