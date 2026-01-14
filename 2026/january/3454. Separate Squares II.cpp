#include <ranges>

class Solution {
public:
    double separateSquares(const vector<vector<int>>& in_squares) {
        using SegTree = SegTreeSimple; 

        vector<int> comp2x;
        for (const auto& v : in_squares) {
            comp2x.push_back(v[0]);
            comp2x.push_back(v[0] + v[2]);
        }
        sort(comp2x.begin(), comp2x.end());
        comp2x.erase(unique(comp2x.begin(), comp2x.end()), comp2x.end());

        auto squares = in_squares
            | views::transform(
                [&comp2x](const auto& v) {
                    return Square{
                        v[0], v[1], v[2],
                        static_cast<int>(::distance(
                            comp2x.begin(), ::lower_bound(comp2x.begin(), comp2x.end(), v[0]))),
                        static_cast<int>(::distance(
                            comp2x.begin(), ::lower_bound(comp2x.begin(), comp2x.end(), v[0] + v[2])))};
                })
            | ::ranges::to<vector>();

        vector<SquareTopBottom> sq_tb;
        sq_tb.reserve(squares.size() * 2);
        for (const auto& sq : squares) {
            sq_tb.emplace_back(&sq, true);
            sq_tb.emplace_back(&sq, false);
        }
        ::sort(sq_tb.begin(), sq_tb.end());

        const auto acc_stages = sq_tb
            | ::views::chunk_by([](const auto& a, const auto& b) { return a.y == b.y; })
            | ::views::transform([&sq_tb, segt = SegTree(comp2x)](const auto& chunk) mutable {
                long long cur_y = chunk.back().y;
                long long nxt_y = &chunk.back() == &(sq_tb.back()) ? cur_y : (&chunk.back() + 1)->y;
                for (const auto& sq : chunk) 
                    segt.inc(sq.sq->x_comp_beg, sq.sq->x_comp_end - 1, sq.is_beg ? 1 : -1);
        
                return SquareAccumulateStage{cur_y, nxt_y, segt.get_length_x()};
            })
            | ::ranges::to<vector>();

        double remain_sq = 0.5 * accumulate(
            acc_stages.begin(), acc_stages.end(), 0.0,
            [](double acc, const auto& stage) { return acc + (stage.nxt_y - stage.cur_y) * stage.len_x; });

        for (const auto& stage : acc_stages) {
            double stage_sq = (stage.nxt_y - stage.cur_y) * stage.len_x;
            if (stage_sq > remain_sq - kEps)
                return stage.cur_y + remain_sq / stage.len_x;
            remain_sq -= stage_sq;
            if (abs(remain_sq) < kEps) return stage.nxt_y;
        }
        return acc_stages.back().cur_y;
    }

private:
    static constexpr double kEps = 1e-5;

    struct Square {
        long long x, y, side;
        int x_comp_beg = -1, x_comp_end = -1;
    };

    struct SquareTopBottom {
        const Square* sq;
        bool is_beg = true;
        long long y;
        SquareTopBottom(const Square* sq, bool is_beg)
            : sq(sq), is_beg(is_beg), y(is_beg ? sq->y : sq->y + sq->side) {}
        bool operator<(const SquareTopBottom& other) {
            if (y != other.y) return y < other.y;
            return sq->x < other.sq->x;
        }
    };

    struct SegTreeLazy { 
        const vector<int>& comp2x;
        vector<int> covr, lazy_covr; 
        vector<long long> xacc; 
        int half_size;
        SegTreeLazy(const vector<int>& comp2x) : comp2x(comp2x) {
            int pow = 0;
            while ((1 << pow) < comp2x.size())
                ++pow;
            half_size = 1 << pow;
            covr.resize(half_size * 2);
            lazy_covr.resize(half_size * 2);
            xacc.resize(half_size * 2);
        }

        long long get_length_x() const { return xacc[1]; }

        void inc(int beg, int end, int delta) { inc_impl(1, 0, half_size - 1, beg, end, delta); }

        void inc_impl(int node, int left, int rght, int beg, int end, int delta) {
            if (beg <= left && rght <= end) {
                lazy_covr[node] += delta;
                delta = 0;
            }

            if (lazy_covr[node]) {
                if (left < rght) {
                    lazy_covr[node * 2] += lazy_covr[node];
                    lazy_covr[node * 2 + 1] += lazy_covr[node];
                }
                covr[node] += lazy_covr[node];
                lazy_covr[node] = 0;
                xacc[node] =
                    covr[node] ? comp2x[rght + 1] - comp2x[left] :
                    left < rght ? xacc[node * 2] + xacc[node * 2 + 1] :
                    0;
            }

            if (rght < beg || left > end || left == rght) return;

            if (beg <= left && rght <= end && covr[node] > 0) {
                xacc[node] = comp2x[rght + 1] - comp2x[left];
                return;
            }

            int mid = (left + rght) / 2;
            inc_impl(node * 2, left, mid, beg, end, delta);
            inc_impl(node * 2 + 1, mid + 1, rght, beg, end, delta);
            xacc[node] = xacc[node * 2] + xacc[node * 2 + 1];
        }
    };

    struct SegTreeSimple { 
        const vector<int>& comp2x;
        vector<int> covr; 
        vector<long long> xacc; 
        int half_size;
        SegTreeSimple(const vector<int>& comp2x) : comp2x(comp2x) {
            int pow = 0;
            while ((1 << pow) < comp2x.size())
                ++pow;
            half_size = 1 << pow;
            covr.resize(half_size * 2);
            xacc.resize(half_size * 2);
        }

        long long get_length_x() const { return xacc[1]; }

        void inc(int beg, int end, int delta) { inc_impl(1, 0, half_size - 1, beg, end, delta); }

        void inc_impl(int node, int left, int rght, int beg, int end, int delta) {
            if (rght < beg || left > end) return;

            if (beg <= left && rght <= end) {
                covr[node] += delta;
            } else {
                int mid = (left + rght) / 2;
                inc_impl(node * 2, left, mid, beg, end, delta);
                inc_impl(node * 2 + 1, mid + 1, rght, beg, end, delta);
            }

            xacc[node] =
                covr[node] ? comp2x[rght + 1] - comp2x[left] :
                left < rght ? xacc[node * 2] + xacc[node * 2 + 1] :
                0;
        }
    };

    struct SquareAccumulateStage {
        long long cur_y, nxt_y, len_x;
    };
};
