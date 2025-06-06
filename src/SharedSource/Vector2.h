#import <cmath>

class Vector2 {
  public:
  float _vector[2];

  Vector2(float x, float y)
  {
    _vector[0] = x;
    _vector[1] = y;
  }

  Vector2()
  {
    _vector[0] = 1.0f;
    _vector[1] = 1.0f;
  }

  float lengthSquared()
  {
    return this->_vector[0] * this->_vector[0] + this->_vector[1] * this->_vector[1];
  }

  float length()
  {
    if (0.0f < lengthSquared()) {
      return std::sqrtf(lengthSquared());
    } else {
      return 0.0f;
    }
  }

  Vector2 operator*(Vector2 vec)
  {
    return Vector2(_vector[0] * vec._vector[0], _vector[1] * vec._vector[1]);
  }

  Vector2 operator*(float val) { return Vector2(_vector[0] * val, _vector[1] * val); }

  Vector2 operator+(Vector2 vec)
  {
    return Vector2(_vector[0] + vec._vector[0], _vector[1] + vec._vector[1]);
  }

  Vector2 operator-(Vector2 vec)
  {
    return Vector2(_vector[0] - vec._vector[0], _vector[1] - vec._vector[1]);
  }

  Vector2 operator/(float val) { return Vector2(_vector[0] / val, _vector[1] / val); }
};
