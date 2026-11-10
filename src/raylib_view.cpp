#include "raylib_view.hpp"

namespace FrogToad {
	void RaylibView::draw(const BoardModel& model) {
		float margin {30.0f};
		float cellSize{ windowW() / model.BoardSize - margin * 2 / model.BoardSize };
		float circleMargin{ 15 };
		int cellThickness{ 5 };
		float arrowSize{20};
		float fontSize{ 60 };
		
		ClearBackground(DARKBLUE);
		DrawText("FROGS & TOADS",margin,margin, fontSize*2, BLACK);
		DrawText("1-7 = Move & R = Restart", margin , margin + fontSize*2, fontSize, BLACK);

		// TODO: Draw the board and game status.
		for (int i{ 0 };i < model.BoardSize; i++) {// Draw Board Start
			Rectangle rect{ i * cellSize + margin ,windowH() / 2,cellSize,cellSize };
			DrawRectangle(rect.x + cellThickness, rect.y + cellThickness, cellSize - cellThickness * 2, cellSize - cellThickness * 2, WHITE);
			DrawRectangleLinesEx(rect, cellThickness,BLACK);

			Vector2 Centre{ i * cellSize + margin + cellSize/2, windowH() / 2 + cellSize / 2 };
			switch (model.cellAt(i)) {
				case BoardModel::Cell::Empty:
					//Draw nothing as nothing is here. 
					break;
				case BoardModel::Cell::Frog:
					DrawCircle(Centre.x, Centre.y, cellSize / 2 - circleMargin, GREEN);
					DrawCircleLinesEx(Centre,cellSize/2 - circleMargin/2,10,BLACK);

					DrawLineEx(
						Vector2(Centre.x - arrowSize*2.5, Centre.y),
						Vector2(Centre.x, Centre.y), 5, DARKGREEN);
					DrawTriangle(
						Vector2(Centre.x - arrowSize, Centre.y- arrowSize),
						Vector2(Centre.x - arrowSize, Centre.y+ arrowSize),
						Vector2(Centre.x + arrowSize*2, Centre.y), DARKGREEN);

					break;
				case BoardModel::Cell::Toad:
					DrawCircle(Centre.x, Centre.y, cellSize / 2 - circleMargin, DARKGREEN);
					DrawCircleLinesEx(Centre, cellSize / 2 - circleMargin/2, 10, BLACK);

					DrawLineEx(
						Vector2(Centre.x + arrowSize * 2.5, Centre.y),
						Vector2(Centre.x, Centre.y), 5, GREEN);
					DrawTriangle(
						Vector2(Centre.x + arrowSize, Centre.y + arrowSize),
						Vector2(Centre.x + arrowSize, Centre.y - arrowSize),
						Vector2(Centre.x - arrowSize*2, Centre.y), GREEN);
					break;
			}
		}// Draw Board End
		DrawText("   1      2     3     4      5     6     7     ", margin, windowH() - margin - fontSize*1.8, fontSize, BLACK);
			
		if (model.state() == BoardModel::GameState::Solved) {
			DrawText("Solved! R to restart.", margin, windowH() - margin - fontSize +5, fontSize, YELLOW);
		}
		else if (model.state() == BoardModel::GameState::Lost) {
			DrawText("You Lost! R to restart.", margin, windowH() - margin - fontSize + 5, fontSize, RED);
		}
		else {
			DrawText("Choose a piece to move.",margin, windowH() - margin - fontSize + 5, fontSize, BLACK);
		}

	}

	int RaylibView::windowW() { return 1200; }
	int RaylibView::windowH() { return 600; }
}
