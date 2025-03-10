#import "Vector.h"
#import "Vector2.h"
#include <cstdint>

struct intpair {
  int x;
  int y;
};

struct MJColor {
  float r;
  float g;
  float b;
  float a;
};

struct MJColor8 {
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t a;
};

Vector2 cardinalSplineInterpolate(Vector2 aa, Vector2 a, Vector2 b, Vector2 bb,
    float fraction, float factor)
{
  //! TODO: Ghidra REALLY does not like this one.

  return Vector2();
}

float clamp(float value, float min, float max)
{
  float returnValue = value;

  if (value > max) {
    returnValue = max;
  }

  if (min > value) {
    return min;
  }

  return returnValue;
}

int clampi(int value, int min, int max)
{
  int returnValue = value;

  if (value > max) {
    returnValue = max;
  }

  if (min > value) {
    return min;
  }

  return returnValue;
}

float linearInterpolate(float a, float b, float fraction)
{
  return a + (b - a) * fraction;
}

//? This seems to disregard the fraction entirely, is this correctly decompiled?
Vector linearInterpolatev(Vector a, Vector b, float fraction)
{
  Vector returnValue = Vector();

  returnValue = returnValue - b;
  returnValue = returnValue * a;
  returnValue = returnValue + b;

  return returnValue;
}

intpair makeIntpair(int x, int y) { return intpair { x, y }; }

MJColor8 MJColor8Make(float r, float g, float b, float a = 1.0f)
{
  return MJColor8 { (uint8_t)(clamp(r * 255.0f, 0.0f, 255.0f)),
    (uint8_t)(clamp(g * 255.0f, 0.0f, 255.0f)),
    (uint8_t)(clamp(b * 255.0f, 0.0f, 255.0f)),
    (uint8_t)(clamp(a * 255.0f, 0.0f, 255.0f)) };
}

Vector MJColor8ToVec(MJColor8 color)
{
  return Vector(color.r, color.g, color.b, color.a);
}

Vector polarToRectangular(double lat, double lon)
{
  float x = std::sin(lon) * std::cos(lat);
  float y = std::sin(lat);
  float z = std::cos(lon) * std::cos(lat);

  return Vector(x, y, z);
}

void quickSort(float* numbers, unsigned int array_size,
    unsigned int* orderedIndices)
{
  //! TODO: Ghidra REALLY does not like this one.
}

float simpleSmoothStep(float x) { return x * x * (3.0f - x * 2.0f); }

//? This is pure speculation and I'm honestly not sure how accurate it is.
//* I believe this is an implementation of
// https://en.wikipedia.org/wiki/Smoothstep.
float smoothStep(float a, float b, float x)
{
  if (a <= x) {
    if (x < b) {
      x = (x - a) / (b - a);
      return x * x * (3.0f - x * 2.0f);
    } else {
      return 1.0f;
    }
  } else {
    return 0.0f;
  }
}
