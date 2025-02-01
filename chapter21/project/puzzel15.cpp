#include <array>
#include <string>
#include <string_view>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <utility>
#include <limits>
#include <functional>
#include <numeric>
#include "Random.h"
#include "Timer.h"

constexpr int g_consoleLines{ 25 };

template <typename T, std::size_t Row, std::size_t Col>
using Arr2d = std::array <std::array<T, Col>, Row>;

/*Step 2

Goal: Be able to display individual tiles on the screen.

Our game board is a 4×4 grid of tiles that can slide around. 
Therefore, it will be useful to have a Tile class that represents one of the numbered tiles on our 4×4 grid or the missing tile. 

Each tile should be able to:
Be given a number or be set as the missing tile
Determine whether it is the missing tile.
Draw to the console with the appropriate spacing (so the tiles will line up when the board is displayed).*/

class Tile 
{
    int m_value {0};

public:
    Tile (int value){
        if (value > 0 && value < 16)
        {
            m_value = value;
        }
    };

    bool setNum(int value)
    {
        if (value > -1 && value < 16)
        {
            m_value = value;
            return true;
        }
        else
        {
            return false;
        }
    }

    int getNum() const
    {
        return m_value;
    }

    bool isEmpty() const
    {
        return !static_cast<bool>(m_value);
    }

    void setEmpty()
    {
        m_value = 0;
    }

    void printTile() const
    {
        if (isEmpty())
        {
            std::cout<<"    ";
        }
        else if (m_value < 10)
        {
            std::cout<<"   "<<m_value;
        }
        else
        {
            std::cout<<"  "<<m_value;
        }
    }

    friend std::ostream& operator<< (std::ostream& out, const Tile& tile)
    {
        tile.printTile();
        return out;
    }
};

/*Step 4

Goal: In this step, we’ll allow the user to repeatedly input game commands, handle invalid input, and implement the quit game command.

These are the 5 commands our game will support (each of which will be input as a single character):

‘w’ - slide tile up
‘a’ - slide tile left
‘s’ - slide tile down
‘d’ - slide tile right
‘q’ - quit game
When the user runs the game, the following should occur:

The (solved) board should be printed to the console.
The program should repeatedly get valid game commands from the user. If the user enters an invalid command or extraneous input, ignore it.
For each valid game command:

Print "Valid command: " and the character the user input.
If the command is the quit command, also print "\n\nBye!\n\n" and then quit the app.
Because our user input routines do not need to maintain any state, implement them inside a namespace named UserInput.*/

namespace UserInput
{
    enum Command
    {
        up,
        down,
        left,
        right,
        quit,
        max_command,
    };

    bool clear_input()
    {
        bool correct_input {true};

        if(std::cin.fail())
        {
            correct_input = false;
            std::cin.clear();
        }
        if(std::cin.fail())
        {
            std::exit(0);
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return correct_input;
    }

    Command get_input()
    {
        char input {};
        while(1)
        {
            std::cout<<"Enter valid input (w, a, s, d, q): ";
            std::cin>>input;
            if (!clear_input())
            {
                continue;
            }

            switch (input)
            {
            case 'w': return up;
            case 'a': return left;
            case 's': return down;
            case 'd': return right;
            case 'q': return quit;
            
            default: continue;
            }
        }
    }

    std::ostream& operator<< (std::ostream& out, const Command& comand)
    {
        char command{};

        switch (comand)
        {
        case up:
            command = 'w'; 
            break;
        case left:
            command = 'a'; 
            break;
        case down:
            command = 's'; 
            break;
        case right:
            command = 'd'; 
            break;
        case quit:
            command = 'q'; 
            break;
        
        default:
            break;
        }

        std::cout<<command;

        return out;
    }
}

/*Step 5

Goal: Implement a helper class that will make it easier for us to handle directional commands.

After implementing the prior step, we can accept commands from the user (as characters ‘w’, ‘a’, ‘s’, ‘d’, and ‘q’). 
These characters are essentially magic numbers in our code. 
While it’s fine to handle these commands in our UserInput namespace and function main(), 
we don’t want to propagate them throughout our whole program. For example, the Board class should have no knowledge of what ‘s’ means.

Implement a helper class named Direction, which will allow us to create objects that represent the cardinal directions (up, left, down, or right). 
operator- should return the opposite direction, and operator<< should print the direction to the console. 
We will also need a member function that will return a Direction object containing a random direction. 
Lastly, add a function to namespace UserInput that converts a directional game command (‘w’, ‘a’, ‘s’, or ‘d’) to a Direction object.

The more we can use Direction instead of directional game commands, the easier our code will be to read and understand.*/

class Direction
{
public:
    enum Type
    {
        up,
        down,
        left,
        right,
        max_type,
    };

    Direction(Type type) : m_type {type} {};
    Direction(UserInput::Command command) 
    {
        if (command == UserInput::up ||
            command == UserInput::down ||
            command == UserInput::left ||
            command == UserInput::right)
        {
            m_type = static_cast<Type>(command);
        }
    };

    Type getType() const
    {
        return m_type;
    }

    Direction operator-() const
    {
        switch (m_type)
        {
        case up: return down;
        case down: return up;
        case left: return right;
        case right: return left;

        default:
            return max_type;
        }
    }

    friend std::ostream& operator<<(std::ostream& out,const Direction& direction)
    {
        switch (direction.m_type)
        {
        case up:
            std::cout<<"up";
            break;
        case down:
            std::cout<<"down";
            break;
        case left:
            std::cout<<"left";
            break;
        case right:
            std::cout<<"right";
            break;
        
        default:
            break;
        }
        return out;
    }

    static Direction getRandomDirection()
    {
        Type random {static_cast<Type>(Random::get(0, max_type-1))};
        return Direction{random};
    }

private:
    Type m_type {};
};

namespace UserInput
{
    Direction commandToDirrection (Command command)
    {
        return Direction{command};
    };
}

/*Step 6

Goal: Implement a helper class that will make it easier for us to index the tiles in our game board.

Our game board is a 4×4 grid of Tile, which we store in two-dimensional array member m_tiles of the Board class. 
We will access a given tile using its {x, y} coordinates. For example, the top left tile has coordinate {0, 0}. 
The tile to the right of that has coordinate {1, 0} (x becomes 1, y stays 0). The tile one down from that has coordinate {1, 1}.

Since we’ll be working with coordinates a lot, create a helper class named Point that stores an {x, y} pair of coordinates. 
We should be able to compare two Point objects for equality and inequality. 
Also implement a member function named getAdjacentPoint that takes a Direction object as a parameter and returns the Point in that direction. 
For example, Point{1, 1}.getAdjacentPoint(Direction::right) == Point{2, 1}.*/

class Point
{
public:
    int m_x {};
    int m_y {};

    Point(int x, int y) : m_x {x} , m_y {y} {};

    Point up(){ return Point{m_x, m_y - 1};}

    Point down(){ return Point{m_x, m_y + 1};}

    Point left(){ return Point{m_x - 1, m_y};}

    Point right(){ return Point{m_x + 1, m_y};}

    Point getAdjacentPoint (const Direction& direction)
    {
        switch (direction.getType())
        {
        case Direction::up: return up();
        case Direction::down: return down();
        case Direction::left: return left();
        case Direction::right: return right();
        
        default: return Point {0, 0};
        }
    }

    bool isValidPoint() {
        return (m_x > -1) && (m_x < 4) && (m_y > -1) && (m_y < 4);
    }

    friend bool operator==(const Point& a, const Point& b)
    {
        return (a.m_x == b.m_x && a.m_y == b.m_y);
    }
    
};

/*Step 3

Goal: Create a solved board (4×4 grid of tiles) and display it on the screen.

Define a Board class that will represent 4×4 grid of tiles. 
A newly created Board object should be in the solved state. 
To display the board, first print g_consoleLines (defined in code snippet below) empty lines and then print the board itself. 
Doing so will ensure that any prior output is pushed out of view so that only the current board is visible on the console.*/

class Board
{
private:
    static constexpr int s_size { 4 };

    Tile m_tiles [s_size][s_size] = {
        Tile{1}, {2}, {3}, {4},
        Tile{5}, {6}, {7}, {8},
        Tile{9}, {10}, {11}, {12},
        Tile{13}, {14}, {15}, {0}
    };

public:
    void printBoard() const
    {
        for (int i {0}; i < g_consoleLines ; ++i)
        {
            std::cout<<"\n";
        }

        for (auto& row : m_tiles)
        {
            for (auto& tile: row)
            {
                tile.printTile();
            }
            
            std::cout<<'\n';
        }
    }

    friend std::ostream& operator<< (std::ostream& out, const Board& board)
    {
        board.printBoard();
        return out;
    }

/*Step 7

Goal: Add the ability for players to slide the tiles on the board.

Let’s generalize this procedure. When the user enters a directional command, we need to:

Locate the empty tile.
From the empty tile, find the adjacent tile that is in the direction opposite of the direction the user entered.
If the adjacent tile is valid (it’s not off the grid), swap the empty tile and adjacent tile.
If the adjacent tile is not valid, do nothing.
Implement this by adding a member function moveTile(Direction) to the class Board. Add this to your game loop from step 5. 
If the user successfully slides a tile, the game should redraw the updated board.
*/
private:
    Point findEmpty()
    {
        for (std::size_t row {0}; row < s_size; ++row)
        {
            for (std::size_t col {0}; col < s_size; ++col)
            {
                if (m_tiles[row][col].isEmpty())
                    return Point{static_cast<int>(col), static_cast<int>(row)};
            }
        }

        return Point{-1, -1};
    }

    void setTile (const Point& point, const int value)
    {
        m_tiles[point.m_y][point.m_x].setNum(value);
    }

    int getTile (const Point& point) const
    {
        return m_tiles[point.m_y][point.m_x].getNum();
    }

public:
    bool moveTile(Direction direction)
    {
        Point empty_point {findEmpty()};
        Point adjacent_point {empty_point.getAdjacentPoint(direction)};
        if (adjacent_point.isValidPoint())
        {
            setTile(empty_point, getTile(adjacent_point));
            setTile(adjacent_point, 0);
            return true;
        }
        else
        {
            return false;
        }
    }

/*Step 8

Goal: In this step, we’ll finish our game. Randomize the initial state of the game board. 
Also, detect when user wins, so after that we can print a win message and quit the game.*/

    void randomize()
    {
        Direction direction{Direction::getRandomDirection()};
        for(int i {0}; i < 50; )
        {
            if (moveTile(direction))
            {
                ++i;
            }
            
            direction = Direction::getRandomDirection();
        }
    }

    bool isWon()
    {
        int num{1};

        for (auto& row : m_tiles)
        {
            for (auto& tile: row)
            {
                if (tile.getNum() != num++)
                {
                    return false;
                }

                if (num == 16)
                    num = 0;
            }
        }
        return true;
    }
};

int main()
{
    UserInput::Command command {};

    Board board{};

    board.randomize();

    board.printBoard();

    while (1)
    {
        command = UserInput::get_input();

        if(command == UserInput::quit)
        {
            std::cout<<"\n\nBye! Bye!\n\n";
            break;
        }
            

        if(board.moveTile(command))
        {
            board.printBoard();
        }

        if(board.isWon())
        {
            std::cout<<"\n\nYou won!\n\n";
            break;
        }
    }

    return 0;
}