# adaship
## Challenge Outline
### Summary and Review of the Problem
AdaShip is a battleship-style game implemented in C++. The game involves two players: a human player and a computer player. Players strategically deploy a fleet of ships on a game board and take turns attacking each other's fleets. The primary goal is to sink all the opponent's ships. I have take a simple OOP approach utilising methods for manipulating class instances and creating a smooth game loop. Also utilising nested loops for handling the game board were vital in providing the solution to this problem.

### Initial working plan
Due to unforseen circumstances I had to take a very 'singular' extreme programming approach. This allowed me to pick up new things in c++ very quickly. However, this approach came at a cost of a lack of documentation and design which led to me being stuck on certain bugs time-consuming.

T

### Decomposition and Analysis

The overall problem is decomposed into key epic tasks:
    
    1. Parsing the game configuration
    2. Implementing Fleet class for managing ships.
    3. Creating Board class for handling game boards.
    4. Designing Player class for player-specific functionalities.
    5. Developing Gameplay class to manage the flow of the game.

From these Epics it was clear what each Class need to accomplish to ensure that the project would run as intended:
    Fleet class: Manages ship placement and removal.
    Board class: Handles game board operations.
    Player class: Represents a player with specific actions.
    Gameplay class: Orchestrates the game flow.
    