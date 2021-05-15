# Milestone 2

## Description
For this milestone we refactored our code to work with unique pointers, and finished off the game by allowing it to
have an active state where the player can shoot at the opponent, and a game over state that ends the game.

## Challenges encountered
I think it was a bit tedious to refactor the code because any function that used an object now had to use unique pointers, which is
almost all of our functions.
I ran into some really confusing errors because I was not transferring ownership with std::move().

## Things I've learned
Ive learned to take things one at a time. At times I was trying to do to many things at once which made the assignment seem more
daunting than it actually was. Once I slowed down and broke down what I had to do, such as refactor, implement certain functions,
and add a game over screen, I was in a better workflow.
