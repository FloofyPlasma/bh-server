#include <cmath>

class Vector {
public:
  float _vector[4];

  Vector(float x, float y, float z) : _vector{x, y, z, 1.0f} {}

  Vector(float x, float y, float z, float w) : _vector{x, y, z, w} {}

  Vector() : _vector{1.0f, 1.0f, 1.0f, 1.0f} {}

  float lengthSquared() {
    return this->_vector[0] * this->_vector[0] +
           this->_vector[1] * this->_vector[1] +
           this->_vector[2] * this->_vector[2];
  }

  float length() { return std::sqrtf(lengthSquared()); }

  Vector normal() {
    float len = length();

    if (len == 0.0f) {
      return {0.0f, 0.0f, 0.0f};
    } else {
      return {
          _vector[0] / len,
          _vector[1] / len,
          _vector[2] / len,
      };
    }
  }

  Vector operator*(Vector vec) {
    return {_vector[0] * vec._vector[0], _vector[1] * vec._vector[1],
            _vector[2] * vec._vector[2], _vector[3] * vec._vector[3]};
  }

  Vector operator*(float val) {
    return {_vector[0] * val, _vector[1] * val, _vector[2] * val,
            _vector[3] * val};
  }

  Vector operator+(Vector vec) {
    return {_vector[0] + vec._vector[0], _vector[1] + vec._vector[1],
            _vector[2] + vec._vector[2], _vector[3] + vec._vector[3]};
  }

  Vector operator-(Vector vec) {
    return {_vector[0] - vec._vector[0], _vector[1] - vec._vector[1],
            _vector[2] - vec._vector[2], _vector[3] - vec._vector[3]};
  }

  Vector operator/(float val) {
    return {_vector[0] / val, _vector[1] / val, _vector[2] / val,
            _vector[3] / val};
  }
};
