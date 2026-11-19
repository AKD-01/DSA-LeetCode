class Solution
{
public:
    [[gnu::always_inline]] static constexpr void
    swp(int& x, int& y, bool c) noexcept
    {
        int m = (x ^ y) & -int{c};
        x ^= m, y ^= m;
    }

    int minimizeSum(const std::vector<int>& a) const noexcept
    {
        int l[] = {INT_MAX, INT_MAX, INT_MAX}, h[]{0, 0, 0};

        for (int x : a)
        {
            int y = x;
            for (auto& v : l) swp(v, x, v > x);
            for (auto& v : h) swp(v, y, v < y);
        }

        return std::min(std::min(h[0] - l[2], h[1] - l[1]), h[2] - l[0]);
    }
};