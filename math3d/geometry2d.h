#ifndef MATH3D_GEOMETRY2D_H
#define MATH3D_GEOMETRY2D_H

#include "AABB2D.h"
#include "Line2D.h"
#include "Ray2D.h"
#include "Segment2D.h"
#include "Plane2D.h"
#include "Triangle2D.h"
#include "Box2D.h"
#include "Circle2D.h"
//#include "Ellipse2D.h"
#include "Polygon2D.h"
#include <utils/AnyValue.h>
#include <vector>

namespace Math3D {

class GeometricPrimitive2D
{
 public:
  enum Type { Point, Segment, AABB, Triangle, Circle, Box };

  GeometricPrimitive2D();
  GeometricPrimitive2D(const GeometricPrimitive2D& rhs);
  GeometricPrimitive2D(const Vector2& point);
  GeometricPrimitive2D(const Segment2D& segment);
  GeometricPrimitive2D(const AABB2D& aabb);
  GeometricPrimitive2D(const Box2D& box);
  GeometricPrimitive2D(const Circle2D& circle);
  GeometricPrimitive2D(const Triangle2D& triangle);
  static const char* TypeName(Type type);
  void Set(const Vector2& point);
  void Set(const Segment2D& segment);
  void Set(const AABB2D& aabb);
  void Set(const Box2D& box);
  void Set(const Circle2D& circle);
  void Set(const Triangle2D& triangle);
  bool Collides(const GeometricPrimitive2D& geom) const;
  bool Collides(const Vector2& point) const;
  bool Collides(const Segment2D& segment) const;
  bool Collides(const AABB2D& aabb) const;
  bool Collides(const Box2D& box) const;
  bool Collides(const Circle2D& circle) const;
  bool Collides(const Triangle2D& triangle) const;
  Real Distance(const GeometricPrimitive2D& geom) const;
  Real Distance(const Vector2& x) const;
  Real Distance(const Segment2D& segment) const;
  Real Distance(const AABB2D& aabb) const;
  Real Distance(const Box2D& box) const;
  Real Distance(const Circle2D& circle) const;
  Real Distance(const Triangle2D& triangle) const;
  void Transform(const RigidTransform2D& T);
  void ToPolygon(std::vector<Vector2>& outline,int divs=32) const;
  void ToBound(AABB2D& bb) const;

  Type type;
  AnyValue data;
};

} //Math3D

#endif

