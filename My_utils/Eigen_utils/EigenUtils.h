// Works on Eigen/Dense

namespace Eigen{
    template< typename T, std::size_t _size>
    using Vector = Eigen::Matrix< T, _size, 1>;

    template< std::size_t _size>
    using Vectord = Vector< double, _size>;
}