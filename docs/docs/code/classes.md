# Classes

The code is mostly being structured in classes.

## `Game`

`Game` class is operating on game logic, display and usage.

### Global variables

#### Public

##### `editDiff()`

A function of type `int`. Responsible for providing interface letting user edit custom game parameters (fourth difficulty option). Uses methods from `Utils` class. Detailed specification of this function is `int editDiff()`.

##### `initDiff()`

A function of type `void`. This function sets game parameters (`boardWidth`, `boardHeight`, `mines`) to specified value depending on gived difficulty value `diff` (type `int`). The function requires a `diff` parameter of type `int`. Full specification of declaration of this function is `void initDiff(int diff)`.

First difficulty is *Easy* with `diff` value of 0, second difficulty is *Medium* with `diff` value of 1, third difficulty is *Hard* with `diff` value of 2, fourth difficulty is *Custom* with `diff` value of 3. On *Custom* difficulty given, `editDiff()` is being called.

Plot width, which means how much cells wide is the plot, is declared as `boardWidth`. The same with `boardHeight`. Amount of mines randomly placed in cells is declared as `mines`. These three variables are a type of `int` and are being properly set by `initDiff()` function. For *Easy* difficulty, all three variables are set to value `9`, which means that the plot is 9 cells wide and high, with 9 bombs randomly spread across the plot.
