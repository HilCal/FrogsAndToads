#include "raylib_view.hpp"

namespace FrogToad {
	void RaylibView::draw(const BoardModel& model) {
		float margin {30.0f};
		float cellSize{ windowW() / model.BoardSize - margin * 2 / model.BoardSize };
		float circleMargin{ 15 };
		int CellThickness{ 4 };
		
		ClearBackground(DARKBLUE);
		// TODO: Draw the board and game status.
		for (int i{ 0 };i < model.BoardSize; i++) {// Draw Board Start
			Rectangle rect{ i * cellSize + margin,windowH() / 2,cellSize,cellSize };
			DrawRectangleLinesEx(rect, CellThickness,BLACK);

			Vector2 Centre{ i * cellSize + margin + cellSize/2, windowH() / 2 + cellSize / 2 };
			switch (model.cellAt(i)) {
				case BoardModel::Cell::Empty:
					//Draw nothing as nothing is here. 
					break;
				case BoardModel::Cell::Frog:
					DrawCircle(Centre.x, Centre.y, cellSize / 2 - circleMargin, GREEN);
					DrawCircleLinesEx(Centre,cellSize/2 - circleMargin/2,10,BLACK);
					break;
				case BoardModel::Cell::Toad:
					DrawCircle(Centre.x, Centre.y, cellSize / 2 - circleMargin, RED);
					DrawCircleLinesEx(Centre, cellSize / 2 - circleMargin/2, 10, BLACK);
					break;
			}
		}// Draw Board End

		
	}

	int RaylibView::windowW() { return 1200; }
	int RaylibView::windowH() { return 600; }
}
