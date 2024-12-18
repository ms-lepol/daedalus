/**
 * @file array_2D.hpp
 * @brief A 2D array implementation using a single vector for storage.
 */

#include <vector>

namespace daedalus {

    /**
     * @class Array_2D
     * @brief A template class for a 2D array.
     * 
     * This class provides a 2D array interface using a single vector for storage.
     * 
     * @tparam T The type of elements stored in the array.
     */
    template <typename T>
    class Array_2D {
    public:
        /**
         * @brief Constructs a 2D array with the given number of rows and columns.
         * 
         * @param rows The number of rows in the array.
         * @param cols The number of columns in the array.
         */
        Array_2D(std::size_t rows, std::size_t cols);

        /**
         * @brief Accesses the element at the given row and column.
         * 
         * @param i The row index.
         * @param j The column index.
         * @return A reference to the element at the specified position.
         */
        T& operator()(std::size_t i, std::size_t j);

        /**
         * @brief Accesses the element at the given row and column (const version).
         * 
         * @param i The row index.
         * @param j The column index.
         * @return A const reference to the element at the specified position.
         */
        const T& operator()(std::size_t i, std::size_t j) const;

        /**
         * @brief Gets the number of rows in the array.
         * 
         * @return The number of rows.
         */
        std::size_t rows() const;

        /**
         * @brief Gets the number of columns in the array.
         * 
         * @return The number of columns.
         */
        std::size_t cols() const;

        /**
         * @brief Exports the data of the array to a vector.
         * 
         * @param v The vector to which the data will be exported.
         */
        void export_data(std::vector<T>& v) const;

    private:
        std::size_t rows_; ///< The number of rows in the array.
        std::size_t cols_; ///< The number of columns in the array.
        std::vector<T> data_; ///< The data storage for the array.
    };
}