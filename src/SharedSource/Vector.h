#import <cmath>

class Vector {
  public:
  float _vector[4];

  Vector(float x, float y, float z)
  {
    _vector[0] = x;
    _vector[1] = y;
    _vector[2] = z;
    _vector[3] = 1.0f;
  }

  Vector(float x, float y, float z, float w)
  {
    _vector[0] = x;
    _vector[1] = y;
    _vector[2] = z;
    _vector[3] = w;
  }

  Vector()
  {
    _vector[0] = 1.0f;
    _vector[1] = 1.0f;
    _vector[2] = 1.0f;
    _vector[3] = 1.0f;
  }

  float lengthSquared()
  {
    return this->_vector[0] * this->_vector[0] + this->_vector[1] * this->_vector[1] + this->_vector[2] * this->_vector[2];
  }

  float length() { return std::sqrtf(lengthSquared()); }

  Vector normal()
  {
    float len = length();

    if (len == 0.0f) {
      return Vector(0.0f, 0.0f, 0.0f);
    } else {
      return Vector(
          _vector[0] / len,
          _vector[1] / len,
          _vector[2] / len);
    }
  }

  Vector operator*(Vector vec)
  {
    return Vector(_vector[0] * vec._vector[0], _vector[1] * vec._vector[1],
        _vector[2] * vec._vector[2], _vector[3] * vec._vector[3]);
  }

  Vector operator*(float val)
  {
    return Vector(_vector[0] * val, _vector[1] * val, _vector[2] * val,
        _vector[3] * val);
  }

  Vector operator+(Vector vec)
  {
    return Vector(_vector[0] + vec._vector[0], _vector[1] + vec._vector[1],
        _vector[2] + vec._vector[2], _vector[3] + vec._vector[3]);
  }

  Vector operator-(Vector vec)
  {
    return Vector(_vector[0] - vec._vector[0], _vector[1] - vec._vector[1],
        _vector[2] - vec._vector[2], _vector[3] - vec._vector[3]);
  }

  Vector operator/(float val)
  {
    return Vector(_vector[0] / val, _vector[1] / val, _vector[2] / val,
        _vector[3] / val);
  }
};
