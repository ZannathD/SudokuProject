//Developers:         Dustin Lockhart, Simon Mekhail
//Class:              COP 2006 - CRN 14488
//Date:               March 25, 2025
//Description:        A program in C++ that
//Log:


#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>



/*
void sudokuBoard(sf::RenderWindow &window)
{
    int counter;
    sf::RectangleShape line;
    line.setFillColor(sf::Color::Black);
    line.setSize(sf::Vector2f(1, 450));
    for (int counter = 0; counter < 9; counter++)
    {
        line.setPosition(counter * 50, 0);
        window.draw(line);
    }
    line.setSize(sf::Vector2f(450, 1));
    for (counter = 0; counter < 9; counter++)
    {
        line.setPosition(0, 50 * counter);
        window.draw(line);
    }
}
*/







int main()
{
    int column, row;
    int board [9][9] =
    {
        {2, 0, 0, 0, 6, 0, 0, 0, 0},
        {3, 0, 0, 0, 0, 2, 0, 8, 5},
        {6, 0, 0, 0, 0, 3, 1, 0, 0},
        {0, 2, 5, 9, 0, 0, 0, 7, 3},
        {9, 0, 7, 5, 8, 4, 2, 0, 6},
        {1, 4, 0, 0, 0, 7, 9, 5, 0},
        {0, 0, 9, 2, 0, 0, 0, 0, 1},
        {7, 8, 0, 4, 0, 0, 0, 0, 9},
        {0, 0, 0, 0, 9, 0, 0, 0, 4}
    };

    sf::Font font("arial.ttf");
    sf::Text text(font);

    for (column = 0; column < 9; column++)
    {
        for (row = 0; row < 9; row++)
        {
            std::cout << board[row][column] << " ";
            if (row == 8)
            {
                std::cout << std::endl;
            }
        }
    }

    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();

        //window.draw();

        for (column = 0; column < 9; column++)
        {
            for (row = 0; row < 9; row++)
            {
                text.setString(std::to_string(board[row][column]));
                text.setPosition(sf::Vector2f(column * 50 + 15, row * 50+10));
                window.draw(text);
                if (row == 8)
                {
                    std::cout << std::endl;
                }
            }
        }

        window.display();
    }
}
