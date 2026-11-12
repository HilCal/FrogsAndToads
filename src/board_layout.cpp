#include "board_layout.hpp"
#include "board_model.hpp"
#include <cassert> // assert() in cellRect()

namespace FrogToad {
    Rectangle BoardLayout::board(int BoardSize) {
        // TODO by You.

        Rectangle boardBack{ Left,Top,BoardSize * CellSize,CellSize };

        return {boardBack}; // Replace with the rectangle covering all cells.
    }

    Rectangle BoardLayout::cellRect(int index) {
        // Assert that the index is valid:
        assert(index >= 0 && index < BoardModel::BoardSize);

        // TODO by You.
        Rectangle rect{ Left + CellSize * index ,Top,CellSize,CellSize};
        return {}; // Replace with the calculated rectangle for cell at zero-based position index.
    }

    std::optional<int> BoardLayout::cellAt(Vector2 point) {
        // TODO by You. 
        //Checks if the point is wtihin the bounds of the rectangle by comparing it to the bounds of the rectangle.
        if (point.x > board(BoardModel::BoardSize).x &&
            point.x < board(BoardModel::BoardSize).x + board(BoardModel::BoardSize).width &&
            point.y > board(BoardModel::BoardSize).y &&
            point.y < board(BoardModel::BoardSize).y + board(BoardModel::BoardSize).height) {

            //Ignore the gaps between the cells using the cell thickness and a modulus equation
            //To ignore not count the gaps as inside of the board.
            if (((int)point.x - (int)Left - (int)cellThickness) % (int)CellSize < CellSize - cellThickness * 2) {
                //returns the truncated value of the mouse/cell size,
                //this value corresponds to the index of the current cell within its array
                return (int)(point.x - Left) / (CellSize);
            }
        }


        // Return nullopt only when the point is off the board. You can use board() to detect this.
        return std::nullopt;
    }
}