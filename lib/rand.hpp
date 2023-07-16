#ifndef RAND_HPP
#define RAND_HPP

#include <random>
#include <chrono>

class Random {
private:
  static inline std::mt19937 generate() noexcept {
    std::random_device rd{};
    std::seed_seq seq{
      static_cast<std::seed_seq::result_type>
        (std::chrono::steady_clock::now().time_since_epoch().count()),
      rd(), rd(), rd(), rd(), rd(), rd(), rd()
    };
    return std::mt19937{ seq };
  }

public:
  static inline std::mt19937 mt{ generate() };
public:
  Random() {};

public:
  /// @brief Get a random number between min 
  ///and max inclusive using mt as the random engine
  /// @param min 
  /// @param max 
  /// @return  T 
  template<typename T, typename Y>
  static inline auto get_random(const T min, const Y max) {
    /// @brief std::uniform_int_distribution<T> is a uniform distribution of 
      /// integers with a range of [min, max]
    /// @return T
    /// (mt) is the random engine to use to generate the random number
    /// {min, max} is the range of numbers to generate
    return std::uniform_int_distribution
    { static_cast<Y>(min), static_cast<Y>(max) }(mt);
  }
};

#endif