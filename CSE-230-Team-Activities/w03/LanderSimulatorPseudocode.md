
```
FUNCTION main

parameters/return vals vary depending on programming language. For c++:
PARAMETERS: argc:int, argv:char[][]
RETURN: 0:int (exit code for program run success)
---

    // initialize interface/gl (display)
    dimensions <- set up dimensions
    ui <- new Interface

    // initialize game class
    game <- new Simulator

    // set up game loop: call Interface::run(function, Simulator&)
    ui.run(callback, game)
```

```
FUNCTION callback

PARAMETER ui:Interface* (Pointer)
PARAMETER game:Simulator* (Pointer)

---

    game.update()
    game.display(ui)
    game.handleInput(ui)
```

```
Simulator CONSTRUCTOR

PARAMETER: screen dimensions:Point
PARAMETER: lunar module point init:Point

---
    
    lunarModule = new LM // (LM = lunar module class)
    ground      = new Ground
```

```
FUNCTION Simulator.update()

---

    lander.update()

    handleEvents()
```

```
FUNCTION Simulator.handleEvents()

---

    IF  lander.position.y < ground level:
        
        lander.alive <- FALSE

    IF lander.position is not on screen:
        run program exit sequence where
        landing sequence is unknown

    IF lander.alive IS FALSE:
        run program exit sequence where 
        landing sequence was not successful

    IF ground.onPlatform(lander.position, lander.width) IS TRUE:
        run program exit sequence where 
        landing sequence was successful
```

