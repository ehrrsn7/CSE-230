Austin Hilderbrand
Elijah Harrison
Lab 3 Class Diagrams

LM

---
- alive:boolean
- x:double
- y:double
- dx:double
- dy:double
- angle:double
- fuel:double
- weight:const double
- thrust:const double
- gravity:const double
- fuelConsumptionRate:const double
---
+ initialize(altitude:double,position:double,verticalVelocity:double,
           horizontalVelocity:double,degrees:double)
+ update
+ updateAngle(degrees:integer)
+ draw
+ applyInertia
+ applyThrust
- burnFuel
+ applyGravity
+ isAlive:boolean
+ setAlive(alive:boolean)
+ totalVelocity:double
+ friend ostream & operator << (ostream & out, const LM & rhs)
- degreesFromRadians(radians:double)
- radiansFromDegrees(degrees:double)

---

Ground

---
- ground:double[]
- landingZonePositionx:int
- screenDimensions:Point
---
+ draw
+ distanceFromGround(LMPosition:Point):double
+ hitGround(LMPosition:Point, LMWidth:int):boolean
+ onPlatform(LMPosition:Point, LMWidth:int):boolean
+ reset
---

Simulator

---
- lunarModule:LM
- ground:Ground
---
+ initializer
+ update
+ draw(gout:ogstream&)
+ handleInput(ui:const Interface*)
- handleEvents
---
